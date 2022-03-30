add_executable(app main.cpp)
add_subdirectory(geometry/)
target_link_libraries(app -lGL -lGLU -lglut -lGLEW)
target_link_libraries(app geometry)