cmake_minimum_required(VERSION 3.10)
project(meerkat_graphics)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)
add_subdirectory(src)

include(FetchContent)
FetchContent_Declare(
    GoogleTest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(GoogleTest)

enable_testing()
add_subdirectory(tests/)