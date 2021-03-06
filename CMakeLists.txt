cmake_minimum_required(VERSION 3.12)
project("elo_rating_system"
    LANGUAGES CXX
    VERSION 0.0.1
    DESCRIPTION "Elo rating system implementation"
)
option(ENABLE_TIME "Measure compilation time" OFF)
option(ENABLE_TESTS "Build unit tests" ${BUILD_TESTING})
option(ENABLE_APPS "Build applications" ON)
option(ENABLE_CONCEPT "Concept feature" ${BUILD_CONCEPT})
option(ENABLE_MODULE "Module feature" ${BUILD_MODULE})
option(COVERAGE_POLICY "Enable coverage reporting" OFF)
option(CXX_STD "C++ standard" 20)
option(ARM "Enable arm" OFF)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

if (NOT APPLE AND NOT ARM)
  include(src/cmake/cpu_detect.cmake)
  DetectHostArch()
  message("-- Architecture ${HOST_ARCH}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=${HOST_ARCH}")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")
endif()
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
if (ENABLE_CONCEPT)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fconcepts")
endif()
if (ENABLE_MODULE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fmodules-ts")
endif()
if (ENABLE_TESTS)
    enable_testing()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
endif()


install(DIRECTORY include/ DESTINATION include)
include_directories("${PROJECT_SOURCE_DIR}/include")
if (APPLE)
  include_directories("/usr/local/include")
endif()
add_subdirectory("${PROJECT_SOURCE_DIR}/src/cmake")
if (ENABLE_TESTS)
  add_subdirectory("${PROJECT_SOURCE_DIR}/test/cmake")
endif()
