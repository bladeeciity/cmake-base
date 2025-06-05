# Set the minimum required version of CMake.
cmake_minimum_required(VERSION 3.21)

# Set the project name and supported languages.
project(cmake-base LANGUAGES CXX)

# Set the C++ standard to C++23.
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable compiler warnings for GCC/Clang or MSVC.
if (MSVC)
    add_compile_options(/MP /permissive-) # /MP for multi-processor compilation, /permissive- for strict ISO C++ compliance
else()
    add_compile_options(-Wall -Wextra -pedantic) # -Wall for all warnings, -Wextra for additional warnings, -pedantic for strict ISO C++ compliance
endif()

# Enable folder structure in IDEs.
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Gather all header files in include/
file(GLOB_RECURSE PROJ_HEADERS CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp"
)

# Gather all source files in source/
file(GLOB_RECURSE PROJ_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cc"
    "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cxx"
)

# Add executable target (Change to add_library if building DLL).
add_executable(${PROJECT_NAME} ${PROJ_SOURCES} ${PROJ_HEADERS})

# Add the include directories for the project.
target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Set output directories for binaries and libraries.
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/exe"    
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/lib"    
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin/lib"    
)