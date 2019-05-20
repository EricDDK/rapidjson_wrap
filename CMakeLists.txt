cmake_minimum_required (VERSION 2.6)
add_compile_options(-std=c++11)
project (rapidjson_wrap)

include_directories(
    ${PROJECT_SOURCE_DIR}/3rd
)

add_library(
    rapidjson_wrap 
    json-wrap.cpp
    json-wrap.h
)

add_executable(
    main 
    test.cpp
)

target_link_libraries(main rapidjson_wrap)
