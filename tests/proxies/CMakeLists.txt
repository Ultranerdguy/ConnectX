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
  proxies.cpp
  ${testTargets}
)

add_executable(Proxies ${Tests} ${testSources})
target_link_libraries(Proxies connectX_lib)

foreach (test ${testTargets})
  get_filename_component (TName ${test} NAME_WE)
  add_test (NAME ${TName} COMMAND Proxies ${TName})
endforeach ()