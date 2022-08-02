cmake_minimum_required(VERSION 3.5.1)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers.cmake)

set(CMAKE_MODULE_PATH 
	${CMAKE_MODULE_PATH} ${CMAKE_MODULE_PATH}/cmake_helpers/find_modules)

project(Texts LANGUAGES CXX)	#first instance the project and the language

if(UNIX)
	set(SDL2_image_name SDL2_image)
	set(SDL2_ttf_name SDL2_ttf)
	set(SDL2_mixer_name SDL2_mixer)
elseif(WIN32 OR APPLE)
	set(SDL2_image_name SDL2_IMAGE)
	set(SDL2_ttf_name SDL2_TTF)
	set(SDL2_mixer_name SDL2_MIXER)
endif()

	find_package(SDL2 REQUIRED)					#first one doesnt need to change
	find_package(${SDL2_image_name} REQUIRED)	#using the three variables we just used and set
	find_package(${SDL2_ttf_name} REQUIRED)
	find_package(${SDL2_mixer_name} REQUIRED)

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})	#set a variable name

add_executable(
	${PROJECT_NAME} 	
	${_BASE_DIR}/common/commonDefines.h

	${_BASE_DIR}/Engine/config/EngineConfig.h
	${_BASE_DIR}/Engine/Engine.h
	${_BASE_DIR}/Engine/Engine.cpp
	${_BASE_DIR}/Engine/EngineConfigLoader.h
	${_BASE_DIR}/Engine/EngineConfigLoader.cpp 
	
	${_BASE_DIR}/Game/Game.h
	${_BASE_DIR}/Game/Game.cpp
	${_BASE_DIR}/Game/config/GameCfg.h
	

	${_BASE_DIR}/main.cpp
	)

set_target_cpp_standard( ${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(
${PROJECT_NAME} 
	PRIVATE 
		${_BASE_DIR}
		PRIVATE
		${SDL2_INCLUDE_DIR}
		${SDL2_image_INCLUDE_DIR}
		${SDL2_MIXER_INCLUDE_DIR}
		${SDL2_TTF_INCLUDE_DIR}

)
target_link_libraries(
${PROJECT_NAME} 
	PRIVATE 
		utils		#we include our library we just made
		sdl_utils
		${SDL2_LIBRARY}
		${SDL2_IMAGE_LIBRARY}
		${SDL2_TTF_LIBRARY}
		${SDL2_MIXER_LIBRARY}
)

if(CMAKE_BUILD_TYPE MATCHES Release)
	target_compile_definitions(
		${PROJECT_NAME}
		PRIVATE_HEADER-DRELEASE_BUILD=1
	)

#this is a bash script for copying the resource folder
add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy_directory
		${CMAKE_CURRENT_SOURCE_DIR}/resources/
		$<TARGET_FILE_DIR:${PROJECT_NAME}>/resources/
)
endif()

add_subdirectory(utils)	#we will import the directory and we will inherit there our variables made here
add_subdirectory(sdl_utils)


