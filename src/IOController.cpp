#include "ConnectX/IOController.hpp"
#include <string>
#include <sstream>
#include "ConnectX/IBoard.hpp"
#include "ConnectX/IReferee.hpp"

// Implementation only
namespace {
  namespace Helper {
    ConnectX::Token GetAt(ConnectX::TokenBuffer const& buffer, ConnectX::Vector const& offsets, ConnectX::Vector const& indexes) {
      std::size_t const size = offsets.size();
      std::size_t offsetTotal = 0;
      for (std::size_t i = 0; i < size; ++i) {
        offsetTotal += offsets[i] * indexes[i];
      }
      return buffer[offsetTotal];
    }

    void PrintRange(std::ostream& output, ConnectX::TokenBuffer const& buffer, ConnectX::Vector const& sizes) {
      // Handle lower dimensions simply
      std::size_t const sizeLength = sizes.size();
      if (sizeLength == 0) return;
      if (sizeLength == 1) {
        for (auto& token : buffer) {
          output << token << '\n';
        }
        return;
      }

      // Do work for higher dimensions
      ConnectX::Vector offsets(sizeLength, 1);
      for (std::size_t i = 1; i < sizeLength; ++i) {
        offsets[sizeLength-i-1] = offsets[sizeLength-i] * sizes[sizeLength-i];
      }

      bool printing = true;
      ConnectX::Vector indexes(sizeLength, 0);
      while (printing) {
        // Only need to count iteratively for sizeLength-2 dimensions, then print last two dimensions
        for (ConnectX::VectorComponent y = 0; y < sizes[sizeLength-1]; ++y) {
          indexes[sizeLength-1] = sizes[sizeLength-1] - y - 1; // Print top to bottom, indexed bottom to top
          for (ConnectX::VectorComponent x = 0; x < sizes[sizeLength-2]; ++x) {
            indexes[sizeLength-2] = x;
            output << GetAt(buffer, offsets, indexes);
            if (x+1 < sizes[sizeLength-2]) {
              output << " | ";
            }
            else {
              output << '\n';
            }
          }
        }
        output << '\n';

        if (sizeLength > 2) {
          // Increment indexes to next slice. Work backwards through the array
          for (std::size_t i = 2; i < sizeLength; ++i) {
            auto const query = sizeLength - i - 1;
            ++indexes[query];
            if (indexes[query] == sizes[query]) {
              indexes[query] = 0;
              if (query == 0) {
                printing = false; // done
                break;
              }
            }
            else {
              break;
            }
          }
        }
        else {
          printing = false; // done
        }
      }
    }
  }

  std::string helpString = "IOController help\nUsage:\n\
  \t<command> [<options>]\n\
  \t<target move>\n\
  \n\
  Commands:\n\
  \thelp              - Prints this help message\n\
  \tget <query>       - Query information about the game\n\
  \t  Queries\n\
  \t  token               - Return the token for the current controller\n\
  \t  dimensions          - Return the number of dimensions of the board\n\
  \t  start               - Returns the smallest index in the board\n\
  \t  end                 - Returns the largest index in the board\n\
  \t  range <start> <end> - Returns a chunk of the board ranging from <start> to <end>\n\
  \t  history             - Returns the game history since this controller's last move\n\
  \t  at <position>       - Returns the token at specified position\n\
  \t  <position>          - Returns the token at specified position\n\
  \tprint             - Prints the entire board. Equivalent to `get start`;`get end`;`get range <start> <end>`\n\
                        Warning: Large boards may be too large to print to screen. Be sure the board is small enough\n\
  \treturn <position> - Returns the move of <position>\n\
  \t<position>        - Returns the move of <position>\n";

  enum class Command {
    Return,
    Help,
    Get,
    Print,
  };

  enum class GetSubcommand {
    At,
    Token,
    Dimensions,
    Start,
    End,
    Range,
    History,
  };

  Command GetCommand(std::istream& stream) {
    auto start = stream.tellg();
    std::string word;
    if (!(stream >> word) || word.empty()) {
      throw std::ios_base::failure("IOController.cpp - GetCommand - Failed to read word");
    }

    switch (tolower(word[0])) {
      case 'h': return Command::Help;
      case 'g': return Command::Get;
      case 'p': return Command::Print;
      default: stream.seekg(start); [[fallthrough]];
      case 'r': return Command::Return;
    }
  }

  GetSubcommand GetGetSubcommand(std::istream& stream) {
    auto start = stream.tellg();
    std::string word;
    if (!(stream >> word) || word.empty()) {
      throw std::ios_base::failure("IOController.cpp - GetGetSubCommand - Failed to read word");
    }

    switch (tolower(word[0])) {
      case 't': return GetSubcommand::Token;
      case 'd': return GetSubcommand::Dimensions;
      case 's': return GetSubcommand::Start;
      case 'e': return GetSubcommand::End;
      case 'r': return GetSubcommand::Range;
      case 'h': return GetSubcommand::History;
      default: stream.seekg(start); [[fallthrough]];
      case 'a': return GetSubcommand::At;
    }
  }
}

ConnectX::IOController::IOController(std::istream& input, std::ostream& output)
  : m_input{input}
  , m_output{output}
{
}

void ConnectX::IOController::AssignToken(Token const token) {
  m_token = token;
}

ConnectX::Vector ConnectX::IOController::GetMove(IReferee const& referee, IBoard const& board) {
  bool querying = true;
  while (querying) {
    switch (GetCommand(m_input)) {
      case Command::Help:  RunHelp(); break;
      case Command::Print: RunPrint(board); break;
      case Command::Get:   RunGet(referee, board); break;
      default: [[fallthrough]];
      case Command::Return: querying = false; break;
    }
  }
  ConnectX::Vector controllerMove;
  if (!(m_input >> controllerMove)) {
    throw std::ios_base::failure("IOController.cpp - ConnectX::IOController::GetMove - Failed to read ConnectX::Vector");
  }
  return controllerMove;
}

void ConnectX::IOController::OnWin() {
  m_output << m_token << " draws\n";
}

void ConnectX::IOController::OnLose() {
  m_output << m_token << " loses!\n";
}

void ConnectX::IOController::OnDraw() {
  m_output << m_token << " wins!\n";
}

ConnectX::IController& ConnectX::IOController::GetController() {
  return *this;
}

// Command handlers

void ConnectX::IOController::RunHelp() const {
  m_output << helpString;
}

void ConnectX::IOController::RunPrint(IBoard const& board) const {
  auto const start = board.GetStart();
  auto end = board.GetEnd();
  auto const range = board.GetRange(start, end);

  // Calculate sizes across the dimensions of the board
  // Start and End are both in the board, so account for off-by-one
  auto sizes = std::move(end);
  std::size_t size = start.size();
  for (std::size_t i = 0; i < size; ++i) {
    sizes[i] -= start[i];
    ++sizes[i];
  }
  Helper::PrintRange(m_output, range, sizes);
}

void ConnectX::IOController::RunGet(ConnectX::IReferee const& referee, ConnectX::IBoard const& board) const {
  switch (GetGetSubcommand(m_input)) {
    case GetSubcommand::Token: RunGetToken(board); break;
    case GetSubcommand::Dimensions: RunGetDimensions(board); break;
    case GetSubcommand::Start: RunGetStart(board); break;
    case GetSubcommand::End: RunGetEnd(board); break;
    case GetSubcommand::Range: RunGetRange(board); break;
    case GetSubcommand::History: RunGetHistory(referee); break;
    default: [[fallthrough]];
    case GetSubcommand::At: RunGetAt(board); break;
  }
}

void ConnectX::IOController::RunGetAt(IBoard const& board) const {
  ConnectX::Vector position;
  if (!(m_input >> position) || position.empty()) {
    throw std::ios_base::failure("IOController.cpp - ConnectX::IOController::RunGetAt - Failed to read ConnectX::Vector");
  }
  m_output << board.GetAt(position) << '\n';
}

void ConnectX::IOController::RunGetToken(IBoard const& board) const {
  m_output << m_token << '\n';
}

void ConnectX::IOController::RunGetDimensions(ConnectX::IBoard const& board) const {
  m_output << board.GetStart().size() << '\n';
}

void ConnectX::IOController::RunGetStart(ConnectX::IBoard const& board) const {
  m_output << board.GetStart() << '\n';
}

void ConnectX::IOController::RunGetEnd(ConnectX::IBoard const& board) const {
  m_output << board.GetEnd() << '\n';
}

void ConnectX::IOController::RunGetRange(ConnectX::IBoard const& board) const {
  ConnectX::Vector start;
  ConnectX::Vector end;
  if (!(m_input >> start >> end) || start.empty() || end.empty() || start.size() != end.size()) {
    throw std::ios_base::failure("IOController.cpp - ConnectX::IOController::RunGetRange - Failed to read ConnectX::Vector");
  }
  // Clip start and end
  auto const boardStart = board.GetStart();
  auto const boardEnd = board.GetEnd();
  if (boardStart.size() != start.size() || boardEnd.size() != end.size()) {
    throw std::range_error("IOController.cpp - ConnectX::IOController::RunGetRange - Wrong input dimensions");
  }

  std::size_t const size = start.size();
  for (std::size_t i = 0; i < size; ++i) {
    start[i] = std::max(start[i], boardStart[i]);
  }
  for (std::size_t i = 0; i < size; ++i) {
    end[i] = std::min(end[i], boardEnd[i]);
  }

  auto const range = board.GetRange(start, end);

  // Calculate sizes across the dimensions of the board
  // Start and End are both in the board, so account for off-by-one
  auto sizes = std::move(end);
  for (std::size_t i = 0; i < size; ++i) {
    sizes[i] -= start[i];
    ++sizes[i];
  }
  Helper::PrintRange(m_output, range, sizes);
}

void ConnectX::IOController::RunGetHistory(ConnectX::IReferee const& referee) const {
  std::size_t const size = referee.GetHistorySize();
  auto fullHistory = referee.GetHistoryRange(0,size);

  for (std::size_t i = 0; i < size; ++i) {
    if (fullHistory[i].pController && &fullHistory[i].pController->GetController() == this) {
      fullHistory.resize(i+1);
      break;
    }
  }

  std::size_t reducedSize = fullHistory.size();
  for (std::size_t i = 0; i < reducedSize; ++i) {
    auto& move = fullHistory[reducedSize-i-1];
    m_output << move.token << "\t-\t" << move.position << '\n';
  }
}