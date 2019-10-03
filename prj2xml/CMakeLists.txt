project(prj2xml)

add_executable(prj2xml prj2xml.cpp)
include_directories(../src)
target_link_libraries(prj2xml prjmodel)
