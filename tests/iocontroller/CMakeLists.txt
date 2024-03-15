set(testTargets 
  BadCommandTester.cpp
  BadGetCommandTester.cpp
  ReturnPlainTester.cpp
  ReturnTester.cpp
  HelpTester.cpp
  PrintTester.cpp
  GetAtPlainTester.cpp
  GetAtTester.cpp
  GetStartTester.cpp
  GetEndTester.cpp
  GetRangeTester.cpp
  GetTokenTester.cpp
  GetDimensionsTester.cpp
  GetHistoryTester.cpp
)
set(testSources
  QueryBoard.cpp
  QueryReferee.cpp
)

create_test_sourcelist(Tests 
  iocontroller.cpp
  ${testTargets}
)

add_executable(IOControllerTest ${Tests} ${testSources})
target_link_libraries(IOControllerTest connectX_lib)

foreach (test ${testTargets})
  get_filename_component (TName ${test} NAME_WE)
  add_test (NAME ${TName} COMMAND IOControllerTest ${TName})
endforeach ()

# Tests
# 