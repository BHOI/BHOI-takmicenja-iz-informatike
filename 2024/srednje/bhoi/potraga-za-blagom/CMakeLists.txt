cmake_minimum_required(VERSION 3.13)  # CMake version check
project(task)
set(CMAKE_CXX_STANDARD 17)            # Enable c++17 standard
add_executable(main sol/main.cpp)
add_executable(generator sol/generator.cpp sol/generator_specific.cpp)

if(WIN32)
  string(REPLACE "\\" "/" SOL_DIR ${CMAKE_SOURCE_DIR}/sol)
else()
  set(SOL_DIR ${CMAKE_SOURCE_DIR}/sol)
endif()
target_compile_definitions(generator PRIVATE SOURCE_PATH=${SOL_DIR})

if(MSVC)
  target_compile_definitions(generator PRIVATE APPEND_ONE_MORE_BACKDIR)
  set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
  target_compile_options(main [PUBLIC|PRIVATE] /MT)
  target_link_options(main [PUBLIC|PRIVATE] /INCREMENTAL:NO /NODEFAULTLIB:MSVCRT)
  target_compile_options(generator [PUBLIC|PRIVATE] /MT)
  target_link_options(generator [PUBLIC|PRIVATE] /INCREMENTAL:NO /NODEFAULTLIB:MSVCRT)
else()
  target_link_libraries(main -static)
  target_link_libraries(generator -static)
endif()

# Manager should only be compiled on linux
if (UNIX)
  add_executable(manager check/manager.cpp)
  target_link_libraries(manager -static)
  add_custom_command(
      TARGET manager POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:manager> ${CMAKE_SOURCE_DIR}/check
      COMMENT "Copying manager to source directory check folder"
  )
endif()
