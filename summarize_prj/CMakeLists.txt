project(summarize_prj)

add_executable(summarize_prj summarize_prj.cpp)
include_directories(../src)
target_link_libraries(summarize_prj prjmodel)
