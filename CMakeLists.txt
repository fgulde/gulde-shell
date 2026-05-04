# ==============================================================================
# 1. GLOBAL SETUP & PROJECT DEFINITION
# ==============================================================================
cmake_minimum_required(VERSION 3.20)

project(Gulde-Shell C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# Sanitizers configuration
option(ENABLE_SANITIZERS "Enable Address/UB sanitizers in Debug builds" ON)
set(SANITIZERS "address,undefined" CACHE STRING "Sanitizers to enable")

# ==============================================================================
# 2. DEPENDENCIES / EXTERNAL PACKAGES
# ==============================================================================
find_package(PkgConfig REQUIRED)
pkg_check_modules(readline REQUIRED IMPORTED_TARGET readline)

enable_testing() # Enable CTest support

find_package(cmocka CONFIG REQUIRED)

# ==============================================================================
# 3. HELPER VARIABLES
# ==============================================================================
file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS src/*.c src/*.h)
file(GLOB_RECURSE TEST_FILES CONFIGURE_DEPENDS tests/*.c)

# ==============================================================================
# 4. CORE LIBRARY (shell_lib)
# Contains all business logic, reusable by both the main app and tests.
# Compiled once to avoid duplication.
# ==============================================================================
add_library(shell_lib STATIC ${SOURCE_FILES})

set_target_properties(shell_lib PROPERTIES
        C_STANDARD 23
        C_STANDARD_REQUIRED ON
        C_EXTENSIONS OFF
)

if(ENABLE_SANITIZERS AND CMAKE_C_COMPILER_ID MATCHES "Clang|GNU")
    target_compile_options(shell_lib PRIVATE
            $<$<CONFIG:Debug>:-fsanitize=${SANITIZERS}>
            $<$<CONFIG:Debug>:-fno-omit-frame-pointer>
            $<$<CONFIG:Debug>:-g>
    )
    target_link_options(shell_lib PRIVATE
            $<$<CONFIG:Debug>:-fsanitize=${SANITIZERS}>
    )
endif()

target_compile_options(shell_lib PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Werror
        -Wshadow
        -Wconversion
        -Wformat=2
)

target_include_directories(shell_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(shell_lib PUBLIC PkgConfig::readline)

# ==============================================================================
# 5. MAIN EXECUTABLE
# The actual shell binary that runs in production.
# ==============================================================================
add_executable(shell src/main.c)

set_target_properties(shell PROPERTIES
        C_STANDARD 23
        C_STANDARD_REQUIRED ON
        C_EXTENSIONS OFF
)

target_link_libraries(shell PRIVATE shell_lib)

# ==============================================================================
# 6. TESTING EXECUTABLE
# Contains all unit and integration tests.
# ==============================================================================
if(TEST_FILES)
    add_executable(shell_tests ${TEST_FILES})

    set_target_properties(shell_tests PROPERTIES
            C_STANDARD 23
            C_STANDARD_REQUIRED ON
            C_EXTENSIONS OFF
    )

    target_compile_options(shell_tests PRIVATE
            -Wall
            -Wextra
            -Wpedantic
            -Wshadow
            -Wconversion
            -Wformat=2
    )

    target_link_libraries(shell_tests PRIVATE shell_lib cmocka::cmocka)

    # Register the testing binary with CTest
    add_test(NAME shell_tests COMMAND shell_tests)
endif()