cmake_minimum_required(VERSION 3.25)

#-------------------------------------------------------------------
# Project
#-------------------------------------------------------------------

# package.json is the primary source for version data
file(READ "${CMAKE_SOURCE_DIR}/package.json" PACKAGE_JSON_STRING)
string(JSON PROJECT_NAME         GET ${PACKAGE_JSON_STRING} "name")
string(JSON PROJECT_VERSION      GET ${PACKAGE_JSON_STRING} "version")
string(JSON PROJECT_DESCRIPTION  GET ${PACKAGE_JSON_STRING} "description")
string(JSON PROJECT_LICENSE      GET ${PACKAGE_JSON_STRING} "license")
string(JSON PROJECT_AUTHOR       GET ${PACKAGE_JSON_STRING} "author")
string(JSON PROJECT_HOMEPAGE     GET ${PACKAGE_JSON_STRING} "homepage")
string(JSON PROJECT_DISPLAY_NAME GET ${PACKAGE_JSON_STRING} "displayName")

project(${PROJECT_NAME} DESCRIPTION ${PROJECT_DESCRIPTION} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

#-------------------------------------------------------------------
# Setup Build Targets
#-------------------------------------------------------------------

set(PROJECT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
add_executable(${PROJECT_NAME} "${PROJECT_SOURCE_DIR}/main.cpp")

target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_20)

target_include_directories(${PROJECT_NAME} INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>"
)
