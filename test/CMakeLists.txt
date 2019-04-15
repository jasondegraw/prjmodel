project(tests)

add_executable(prjmodel_tests catch.hpp utility_function_tests.cpp reader_tests.cpp)
include_directories(../src)
target_link_libraries(prjmodel_tests prjmodel)
