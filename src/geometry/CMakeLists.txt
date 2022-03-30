file(GLOB Geometry *.cpp)
add_library(geometry ${Geometry})
link_directories(iterators/ shapes/)