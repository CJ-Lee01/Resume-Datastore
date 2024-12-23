cmake_minimum_required(VERSION 3.31.2)

project(ResumeDatastore)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(ResumeStorage main.cpp)

# Include nlohmann/json header-only library
find_package(nlohmann_json 3.2.0 REQUIRED)

# Link nlohmann_json to the target
target_link_libraries(ResumeStorage PRIVATE nlohmann_json::nlohmann_json)

# Include directories (if necessary)
# target_include_directories(ResumeStorage PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Add compile options (optional)
target_compile_options(ResumeStorage PRIVATE -Wall -Wextra -Wpedantic)

# Specify where to output compiled binary
set_target_properties(ResumeStorage PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# Installation (optional)
install(TARGETS ResumeStorage DESTINATION bin)
