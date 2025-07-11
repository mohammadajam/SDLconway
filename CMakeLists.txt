cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAG_DEBUG "${CMAKE_C_FLAG_DEBUG} -Wall")
set(CMAKE_C_FLAG_RELEASE "${CMAKE_C_FLAG_RELEASE} -NDEBUG")

project(SDLconway VERSION 1.0)

add_subdirectory(external/SDL)
add_subdirectory(external/SDL_ttf)

add_executable(${PROJECT_NAME}
	src/main.c
	src/grid.c
	src/rule.c
)

target_include_directories(${PROJECT_NAME} PRIVATE include)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3 SDL3_ttf::SDL3_ttf m)
