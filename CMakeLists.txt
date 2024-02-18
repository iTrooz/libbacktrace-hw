cmake_minimum_required(VERSION 3.10)

project(cpp_hw)

add_executable(cpp_hw main.cpp)

find_library(Backtrace_LIBRARY backtrace)
find_path(Backtrace_INCLUDE_DIR "backtrace.h")

target_link_libraries(cpp_hw ${Backtrace_LIBRARY} LLVMDemangle)
target_include_directories(cpp_hw PUBLIC ${Backtrace_INCLUDE_DIR})

