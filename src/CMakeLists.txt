#include_directories(${PROJECT_BINARY_DIR})
#include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(target_name prjmodel)

project(${target_name})

set(${target_name}_src
  prjmodel_api.hpp
  #contam/ForwardTranslator.hpp
  #contam/ForwardTranslator.cpp
  logging.hpp
  reader.hpp
  reader.cpp
  #SimFile.hpp
  #SimFile.cpp
  defines.hpp
  model.hpp
  model.cpp
  objects.hpp
  objects.cpp
  subobjects.hpp
  subobjects.cpp
  airflowelements.hpp
  airflowelements.cpp
  #SurfaceNetworkBuilder.hpp
  #SurfaceNetworkBuilder.cpp
  utility_functions.hpp
  windpressure.hpp
  windpressure.cpp
)

# resource files
#include("${PROJECT_SOURCE_DIR}/embedded/EmbedFiles.cmake")
# EMBEDDED_OUTPUT stores the list of cxx files that we need to link later
#file(GLOB_RECURSE IDD_FILES  FOLLOW_SYMLINKS "${CMAKE_CURRENT_SOURCE_DIR}/templates/*.prj")
#foreach( _FILE ${IDD_FILES} )
#  file(RELATIVE_PATH LOCATION "${CMAKE_CURRENT_SOURCE_DIR}" ${_FILE})
#  list(APPEND E_FILES ${_FILE})
#  list(APPEND E_PATHS ${LOCATION})
#endforeach()

#include("${PROJECT_SOURCE_DIR}/embedded/EmbedFiles.cmake")
#embed_files("${E_FILES}" "${E_PATHS}" EMBEDDED_OUTPUT openstudiocontam)
# message("EMBEDDED_OUTPUT: ${EMBEDDED_OUTPUT}")

# set up groups of source files for Visual Studio
#source_group(embedded FILES ${EMBEDDED_OUTPUT})


#set(${target_name}_test_src
#  Test/AirflowFixture.hpp
#  Test/AirflowFixture.cpp
#  Test/ContamModel_GTest.cpp
#  Test/ForwardTranslator_GTest.cpp
#  Test/SurfaceNetworkBuilder_GTest.cpp
#  Test/DemoModel.hpp
#  Test/DemoModel.cpp
#)

#set(${target_name}_swig_src
#  Airflow.i
#)

#set(${target_name}_depends
#  ${Boost_LIBRARIES}
#  ${CMAKE_THREAD_LIBS}
#  openstudio_utilities
#  openstudio_model
#  openstudio_osversion
#)

add_library(${target_name} SHARED
  ${${target_name}_src}
  #  ${EMBEDDED_OUTPUT}
)
#target_link_libraries(${target_name} ${${target_name}_depends})

#if(BUILD_TESTING)
#  CREATE_TEST_TARGETS(${target_name} "${${target_name}_test_src}" "${${target_name}_depends}")
#  add_dependencies(${target_name}_tests openstudio_airflow_resources)
#endif()

#MAKE_SWIG_TARGET(OpenStudioAirflow Airflow "${CMAKE_CURRENT_SOURCE_DIR}/Airflow.i" "${${target_name}_swig_src}" ${target_name} OpenStudioEnergyPlus)
