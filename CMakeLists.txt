cmake_minimum_required(VERSION 3.29)
project(kerkers_en_draken)

set(CMAKE_CXX_STANDARD 26)

set(SRC_DIR src)
set(DOMAIN_DIR ${SRC_DIR}/domain)
set(APPLICATION_DIR ${SRC_DIR}/application)
set(INFRA_DIR ${SRC_DIR}/infrastructure)
set(PRESENTATION_DIR ${SRC_DIR}/presentation)

file(GLOB_RECURSE DOMAIN_FILES
        ${DOMAIN_DIR}/**/*.h
        ${DOMAIN_DIR}/**/*.hpp
        ${DOMAIN_DIR}/**/*.cpp
)

file(GLOB_RECURSE APPLICATION_FILES
        ${APPLICATION_DIR}/*.h
        ${APPLICATION_DIR}/*.hpp
        ${APPLICATION_DIR}/*.cpp
)

file(GLOB_RECURSE INFRA_FILES
        ${INFRA_DIR}/**/*.h
        ${INFRA_DIR}/**/*.hpp
        ${INFRA_DIR}/**/*.cpp
)

file(GLOB_RECURSE PRESENTATION_FILES
        ${PRESENTATION_DIR}/**/*.h
        ${PRESENTATION_DIR}/**/*.hpp
        ${PRESENTATION_DIR}/**/*.cpp
)

#set(SOURCES
#        ${DOMAIN_FILES}
#        ${APPLICATION_FILES}
#        ${INFRA_FILES}
#        ${PRESENTATION_FILES}
#        src/main.cpp
#)

find_package(SQLite3 REQUIRED)

add_library(domain ${DOMAIN_FILES})
add_library(application ${APPLICATION_FILES})
add_library(infrastructure ${INFRA_FILES})
add_executable(kerkers_en_draken src/main.cpp ${PRESENTATION_FILES})

target_link_libraries(kerkers_en_draken PRIVATE application domain infrastructure SQLite3)

target_include_directories(kerkers_en_draken PRIVATE
        ${DOMAIN_DIR}
        ${APPLICATION_DIR}
        ${INFRA_DIR}
        ${PRESENTATION_DIR}
)

add_custom_command(
        TARGET kerkers_en_draken POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:kerkers_en_draken>/resources
)