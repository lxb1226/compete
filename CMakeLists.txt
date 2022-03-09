cmake_minimum_required(VERSION 3.10)
project(compete)
SET(CMAKE_BUILD_TYPE "Debug")
# <---------- set c++ standard ------------->
# NOTE: you must build redis-plus-plus and your application code with the same standard.
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(third_party)
add_subdirectory(tests)

# <------------ add hiredis dependency --------------->
# <------------ add redis-plus-plus dependency -------------->
# NOTE: this should be *sw* NOT *redis++*

# find_path(HIREDIS_HEADER hiredis)
# find_path(REDIS_PLUS_PLUS_HEADER sw)
# find_library(HIREDIS_LIB hiredis)
# find_library(REDIS_PLUS_PLUS_LIB redis++)
# set(headers ${HIREDIS_HEADER} ${REDIS_PLUS_PLUS_HEADER})
# set(libs ${HIREDIS_LIB} ${REDIS_PLUS_PLUS_LIB})
# target_include_directories(target PUBLIC ${headers})
# target_link_libraries(target ${libs})
# target_include_directories(target PUBLIC ${HIREDIS_HEADER})
# target_include_directories(target PUBLIC ${REDIS_PLUS_PLUS_HEADER})
# target_link_libraries(target ${HIREDIS_LIB})
# target_link_libraries(target ${REDIS_PLUS_PLUS_LIB})

find_package(Boost REQUIRED serialization)


find_path(HIREDIS_HEADER hiredis)
find_library(HIREDIS_LIB hiredis)
set(headers ${HIREDIS_HEADER} ${PROJECT_BINARY_DIR}/src)
set(libs ${HIREDIS_LIB} pthread)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})

    MESSAGE( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
    MESSAGE( STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
    MESSAGE( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")
    add_executable(main main.cpp ./src/thread.cpp ./src/RedisTools.cpp ./src/serialtest.cpp)
    target_include_directories(main PUBLIC ${headers})
    target_link_libraries(main ${libs} ${Boost_LIBRARIES})
    # target_link_libraries (main ${Boost_LIBRARIES})
endif()

