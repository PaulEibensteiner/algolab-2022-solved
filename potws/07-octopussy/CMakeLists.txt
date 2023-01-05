cmake_minimum_required(VERSION 3.2)
project(algo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")
set(CGAL_DO_NOT_WARN_ABOUT_CMAKE_BUILD_TYPE TRUE)

find_package(CGAL REQUIRED COMPONENTS Core)
find_package(Boost REQUIRED)
include_directories(${CGAL_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})
include( ${CGAL_USE_FILE} )

add_executable(${PROJECT_NAME} "src/algorithm.cpp")
target_link_libraries(${PROJECT_NAME} ${CGAL_LIBRARIES} ${Boost_LIBRARIES} ${MPFR_LIBRARIES} ${GMP_LIBRARIES} ${THREAD_LIBRARIES})
