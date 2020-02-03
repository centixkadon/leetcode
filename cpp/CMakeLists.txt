
cmake_minimum_required(VERSION 2.8)

project(leetcode)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CONFIGURATION_TYPES ${CMAKE_BUILD_TYPE})
add_compile_options("-Wall")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

include_directories(include)

file(GLOB SOURCE_DIRS cpp_*)
foreach(SOURCE_DIR ${SOURCE_DIRS})

  file(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}/p*.cpp)
  get_filename_component(TARGET_PREFIX ${SOURCE_DIR} NAME)
  string(SUBSTRING ${TARGET_PREFIX} 4 -1 TARGET_PREFIX)
  foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(TARGET_POSTFIX ${SOURCE_FILE} NAME_WE)
    string(SUBSTRING ${TARGET_POSTFIX} 1 4 TARGET_POSTFIX)
    add_executable(${TARGET_PREFIX}_${TARGET_POSTFIX} ${SOURCE_FILE})
    target_link_libraries(${TARGET_PREFIX}_${TARGET_POSTFIX} pthread)
  endforeach()

endforeach()

add_executable(${PROJECT_NAME}_run_all run_all.cpp)
