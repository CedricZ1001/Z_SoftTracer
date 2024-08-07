set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE source CONFIGURE_DEPENDS src/*.cpp)

add_executable(Z_SoftTracer ${source})

target_include_directories(Z_SoftTracer PUBLIC include)

target_link_libraries(Z_SoftTracer glm)