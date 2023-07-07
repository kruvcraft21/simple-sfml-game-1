cmake_minimum_required(VERSION 3.8)
project(Cat_following_beam VERSION 0.1.0 LANGUAGES CXX)

file(GLOB src "src/*")
add_executable(Cat_following_beam main.cpp ${src})

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ${CMAKE_SOURCE_DIR}/libs/SFML/lib/cmake/SFML)

include_directories(${CMAKE_SOURCE_DIR}/libs/SFML/include)

target_link_libraries(${PROJECT_NAME} sfml-graphics)
find_package(SFML 2.6 REQUIRED graphics system audio network window)

add_custom_target(copy_assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/Debug/assets
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/Release/assets
)
add_dependencies(${PROJECT_NAME} copy_assets)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)