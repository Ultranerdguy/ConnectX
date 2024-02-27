set(testTargets 
  FactoryTester.cpp
  FactoryAddArgumentTester.cpp
  FactoryCreateArgumentTester.cpp
)
set(testSources
)

create_test_sourcelist(Tests 
  factory.cpp
  ${testTargets}
)

add_executable(Factory ${Tests} ${testSources})
target_link_libraries(Factory connectX_lib)

foreach (test ${testTargets})
  get_filename_component (TName ${test} NAME_WE)
  add_test (NAME ${TName} COMMAND Factory ${TName})
endforeach ()