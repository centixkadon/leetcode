
cmake_minimum_required(VERSION 2.8)

project(leetcode)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CONFIGURATION_TYPES Debug Release)
if(MSVC)
  add_compile_options(/W4)
elseif()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/)

find_package(Threads REQUIRED)

include_directories(include)

file(GLOB_RECURSE LIBRARY_SOURCE_FILES source/*.c source/*.cpp)

file(GLOB SOURCE_DIRS cpp_*)
foreach(SOURCE_DIR ${SOURCE_DIRS})

  file(GLOB_RECURSE SOURCE_FILES ${SOURCE_DIR}/p*.cpp)
  get_filename_component(TARGET_PREFIX ${SOURCE_DIR} NAME)
  string(SUBSTRING ${TARGET_PREFIX} 4 -1 TARGET_PREFIX)
  foreach(SOURCE_FILE ${SOURCE_FILES})
    get_filename_component(TARGET_POSTFIX ${SOURCE_FILE} NAME_WE)
    string(SUBSTRING ${TARGET_POSTFIX} 1 4 TARGET_POSTFIX)

    if(${SOURCE_DIR} MATCHES cpp_algorithm$)
      set(SOURCE_FILE ${SOURCE_FILE} ${LIBRARY_SOURCE_FILES})
    endif()
    add_executable(${TARGET_PREFIX}_${TARGET_POSTFIX} ${SOURCE_FILE})
    target_link_libraries(${TARGET_PREFIX}_${TARGET_POSTFIX} ${CMAKE_THREAD_LIBS_INIT})
  endforeach()

endforeach()

add_executable(${PROJECT_NAME}_run_all run_all.cpp)
