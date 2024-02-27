# Minimum required CMake version
cmake_minimum_required(VERSION 3.12)

# Project name
project(NetworkDispatcher)

set(dir ${CMAKE_CURRENT_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin CACHE PATH "Build directory" FORCE)
set(LIBRARY_OUTPUT_PATH ${dir} CACHE PATH "Build directory" FORCE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${dir})
set(CMAKE_BUILD_FILES_DIRECTORY ${dir})
set(CMAKE_BUILD_DIRECTORY ${dir})
set(CMAKE_BINARY_DIR  ${dir})
SET(EXECUTABLE_OUTPUT_PATH ${dir})
SET(LIBRARY_OUTPUT_PATH ${dir}lib)
SET(CMAKE_CACHEFILE_DIR ${dir})

set(CXX_STANDARD_REQUIRED ON)

# Add source files
set(SOURCES
    src/main.cpp
)

# Add header files
set(HEADERS
    src/network.hpp
    src/node.hpp
    src/network_common.hpp
)

# Add executable target
add_executable(NetworkDispatcher ${SOURCES} ${HEADERS})

target_compile_features(NetworkDispatcher PUBLIC cxx_std_23)

# Include directories
target_include_directories(NetworkDispatcher PUBLIC include)

# Link libraries if needed
target_link_libraries(NetworkDispatcher PUBLIC some_library)
