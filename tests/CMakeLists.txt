set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_redisplusplus test_redisplusplus)

find_path(HIREDIS_HEADER hiredis)
find_path(REDIS_PLUS_PLUS_HEADER sw)
find_library(HIREDIS_LIB hiredis)
find_library(REDIS_PLUS_PLUS_LIB redis++)
set(headers ${HIREDIS_HEADER} ${REDIS_PLUS_PLUS_HEADER})
set(libs ${HIREDIS_LIB} ${REDIS_PLUS_PLUS_LIB})
target_include_directories(test_redisplusplus PUBLIC ${headers})
target_link_libraries(test_redisplusplus ${libs})