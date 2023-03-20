cmake_minimum_required(VERSION 3.1)
project(helloWorld)

add_library(myLibrary
	${CMAKE_CURRENT_SOURCE_DIR}/src/myImplementation.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Geometry.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Mesh.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/MeshReader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Quadrature.cpp
	)

target_include_directories(myLibrary PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(integrate ${CMAKE_CURRENT_SOURCE_DIR}/exe/integrate.cpp)
target_link_libraries(integrate PRIVATE myLibrary)

add_executable(pointersNonsense ${CMAKE_CURRENT_SOURCE_DIR}/exe/pointersNonsense.cpp)
target_link_libraries(pointersNonsense PRIVATE myLibrary)
