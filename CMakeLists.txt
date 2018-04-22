cmake_minimum_required(VERSION 3.8)
project(IBFNotfall)

include_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/include/tiefblau
	${CMAKE_CURRENT_SOURCE_DIR}/dependencies/include/SDL2
)

if(WIN32)
	set(TARGET_PLATFORM win)
elseif(UNIX)
	set(TARGET_PLATFORM linux)
endif()

link_directories(
	${CMAKE_CURRENT_SOURCE_DIR}/dependencies/lib/x32/${TARGET_PLATFORM}
)

add_subdirectory(src)
add_subdirectory(player)