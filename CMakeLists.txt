cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAG_RELEASE "${CMAKE_C_FLAG_RELEASE} -NDEBUG")

project(SDLconway VERSION 1.0)

add_subdirectory(external/SDL)

add_executable(${PROJECT_NAME}
	src/main.c
)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
