add_library(teletactica teletactica.cpp)
target_include_directories(teletactica PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(teletactica_exec main.cpp)
target_link_libraries(teletactica_exec teletactica)
set_target_properties(teletactica_exec PROPERTIES OUTPUT_NAME teletactica)
