cmake_minimum_required(VERSION 3.5.1)
	
project(utils LANGUAGES CXX)		#this is the library folder

set(_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)	
set(_INC_DIR ${_BASE_DIR}/utils)						#we made the same folder name in order to be readable
set(_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)	

add_library(
	${PROJECT_NAME} STATIC
		
	${_INC_DIR}/drawings/Point.h
	${_INC_DIR}/drawings/Color.h
	${_INC_DIR}/drawings/Rectangle.h
	${_INC_DIR}/drawings/DrawParams.h
	${_INC_DIR}/thread/ThreadUtils.h
	${_INC_DIR}/Time/Time.h
	
	${_SRC_DIR}/drawings/Point.cpp
	${_SRC_DIR}/drawings/Color.cpp
	${_SRC_DIR}/drawings/Rectangle.cpp
	${_SRC_DIR}/thread/ThreadUtils.cpp
	${_SRC_DIR}/Time/Time.cpp
  
	)

set_target_cpp_standard(${PROJECT_NAME} 17)
enable_target_warnings(${PROJECT_NAME})

target_include_directories(
${PROJECT_NAME} 
	PUBLIC 
		${_BASE_DIR}	#we need to include the directory
)
