cmake_minimum_required(VERSION 3.15)

project(as-camera-input-sdl LANGUAGES CXX)

find_package(SDL2 REQUIRED CONFIG)

include(FetchContent)
FetchContent_Declare(
  as-camera-input
  GIT_REPOSITORY https://github.com/pr0g/as-camera-input.git
  GIT_TAG 5490cf0ccf7fe60545c4e36cb182a1e074314ed2)
FetchContent_Declare(
  cmake-helpers
  GIT_REPOSITORY https://github.com/pr0g/cmake-helpers.git
  GIT_TAG 7e1ded2f027dd2bd3265ab7cb4972d06083fbcc5)
FetchContent_MakeAvailable(as-camera-input cmake-helpers)

list(APPEND CMAKE_MODULE_PATH ${cmake-helpers_SOURCE_DIR})

add_library(${PROJECT_NAME})
target_sources(${PROJECT_NAME} PRIVATE src/as-camera-input-sdl.cpp)
target_include_directories(
  ${PROJECT_NAME} PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)
target_link_libraries(${PROJECT_NAME} PUBLIC SDL2::SDL2 as-camera-input)
set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "d")

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

target_compile_definitions(
  ${PROJECT_NAME}
  PRIVATE $<$<BOOL:${AS_PRECISION_FLOAT}>:AS_PRECISION_FLOAT>
          $<$<BOOL:${AS_PRECISION_DOUBLE}>:AS_PRECISION_DOUBLE>
          $<$<BOOL:${AS_COL_MAJOR}>:AS_COL_MAJOR>
          $<$<BOOL:${AS_ROW_MAJOR}>:AS_ROW_MAJOR>)

include(thh-install)
thh_install_static_with_dependencies(${PROJECT_NAME} as-camera-input-sdl)
