cmake_minimum_required(VERSION 3.24)
project(ping_pong)

# settings
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)

# libs
include(FetchContent)

FetchContent_Declare(
	sdl2
	GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
	GIT_TAG release-2.32.8
)

FetchContent_MakeAvailable(sdl2)

# files
set(SRCS
    src/main.cpp
    src/game.cpp
	src/vector.cpp
	src/entity.cpp
)

add_executable(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE ${SRCS})

include_directories(${PROJECT_NAME} PRIVATE ${SDL2_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2)

