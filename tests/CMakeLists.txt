find_package(GTest REQUIRED)

add_executable(teletactica_tests test_teletactica.cpp)
target_link_libraries(teletactica_tests GTest::GTest GTest::Main teletactica)
add_test(NAME TeletacticaTest COMMAND teletactica_tests)
