set(testTargets 
  BoardProxyPassthroughInTester.cpp
  BoardProxyPassthroughOutTester.cpp
  ControllerProxyPassthroughInTester.cpp
  ControllerProxyPassthroughOutTester.cpp
  RefereeProxyPassthroughInTester.cpp
  RefereeProxyPassthroughOutTester.cpp
)
set(testSources
  BoardPassthroughImpl.cpp
  ControllerPassthroughImpl.cpp
  RefereePassthroughImpl.cpp
)

create_test_sourcelist(Tests 
  common.cpp
  ${testTargets}
)

add_executable(Common ${Tests} ${testSources})
target_link_libraries(Common connectX_lib)

foreach (test ${testTargets})
  get_filename_component (TName ${test} NAME_WE)
  add_test (NAME ${TName} COMMAND Common ${TName})
endforeach ()