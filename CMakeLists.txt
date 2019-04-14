<<<<<<< HEAD
include_directories(${CMAKE_BINARY_DIR})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

set(target_name openstudio_airflow)

set(${target_name}_src
  AirflowAPI.hpp
  contam/ForwardTranslator.hpp
  contam/ForwardTranslator.cpp
  contam/PrjReader.hpp
  contam/PrjReader.cpp
  contam/SimFile.hpp
  contam/SimFile.cpp
  WindPressure.hpp
  WindPressure.cpp
  contam/PrjDefines.hpp
  contam/PrjModel.hpp
  contam/PrjModel.cpp
  contam/PrjModelImpl.hpp
  contam/PrjModelImpl.cpp
  contam/PrjObjects.hpp
  contam/PrjObjects.cpp
  contam/PrjObjectsImpl.hpp
  contam/PrjObjectsImpl.cpp
  contam/PrjSubobjects.hpp
  contam/PrjSubobjects.cpp
  contam/PrjSubobjectsImpl.hpp
  contam/PrjSubobjectsImpl.cpp
  contam/PrjAirflowElements.hpp
  contam/PrjAirflowElements.cpp
  contam/PrjAirflowElementsImpl.hpp
  contam/PrjAirflowElementsImpl.cpp
  SurfaceNetworkBuilder.hpp
  SurfaceNetworkBuilder.cpp
)

# resource files
include("${CMAKE_SOURCE_DIR}/embedded/EmbedFiles.cmake")
# EMBEDDED_OUTPUT stores the list of cxx files that we need to link later
file(GLOB_RECURSE IDD_FILES  FOLLOW_SYMLINKS "${CMAKE_CURRENT_SOURCE_DIR}/templates/*.prj")
foreach( _FILE ${IDD_FILES} )
  file(RELATIVE_PATH LOCATION "${CMAKE_CURRENT_SOURCE_DIR}" ${_FILE})
  list(APPEND E_FILES ${_FILE})
  list(APPEND E_PATHS ${LOCATION})
endforeach()

include("${CMAKE_SOURCE_DIR}/embedded/EmbedFiles.cmake")
embed_files("${E_FILES}" "${E_PATHS}" EMBEDDED_OUTPUT openstudiocontam)
# message("EMBEDDED_OUTPUT: ${EMBEDDED_OUTPUT}")

# set up groups of source files for Visual Studio
source_group(embedded FILES ${EMBEDDED_OUTPUT})


set(${target_name}_test_src
  Test/AirflowFixture.hpp
  Test/AirflowFixture.cpp
  Test/ContamModel_GTest.cpp
  Test/ForwardTranslator_GTest.cpp
  Test/SurfaceNetworkBuilder_GTest.cpp
  Test/DemoModel.hpp
  Test/DemoModel.cpp
)

set(${target_name}_swig_src
  Airflow.i
)

set(${target_name}_depends
  ${Boost_LIBRARIES}
  ${CMAKE_THREAD_LIBS}
  openstudio_utilities
  openstudio_model
  openstudio_osversion
)
=======

project(prjmodel)

if(CMAKE_COMPILER_IS_GNUCXX)
  # Nothing to see here yet
elseif(MSVC)
  if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
    if (_cpp_latest_flag_supported)
        add_compile_options("/std:c++latest")
    endif()
  else()
    message(FATAL_ERROR "Visual Studio versions earlier than VS2017 are not supported")
  endif()
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  # Nothing to see here yet
endif()
>>>>>>> 10d2bab... Get a couple things compiling

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(contam)
add_subdirectory(test)

