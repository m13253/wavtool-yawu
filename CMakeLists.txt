cmake_minimum_required(VERSION 3.0)
project(wavtool-yawu)

if(NOT MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Og")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
else()
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Ox /GL")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
endif()
add_definitions(-D_FILE_OFFSET_BITS=64)

if("${YAWU_OUTPUT_SAMPLE_FORMAT}" STREQUAL "")
    set(YAWU_OUTPUT_SAMPLE_FORMAT SF_FORMAT_PCM_32)  # See pcm_merger.cpp for more information
endif()
add_definitions("-DYAWU_OUTPUT_SAMPLE_FORMAT=${YAWU_OUTPUT_SAMPLE_FORMAT}")

file(GLOB_RECURSE YAWU_SRC_SOURCES RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "src/*.cpp")
add_executable(wavtool-yawu ${YAWU_SRC_SOURCES})

set_target_properties(wavtool-yawu PROPERTIES
    CXX_STANDARD 11
    POSITION_INDEPENDENT_CODE ON
)

target_link_libraries(wavtool-yawu PUBLIC m)  # libm math library
add_subdirectory(lib/libWinTF8)
target_link_libraries(wavtool-yawu PUBLIC wintf8)
if(NOT USE_SYSTEM_SNDFILE)
    add_subdirectory(lib/libsndfile-1.0.25)
endif()
target_link_libraries(wavtool-yawu PUBLIC sndfile)

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")  # Test subproject
    install(TARGETS wavtool-yawu
        RUNTIME DESTINATION "bin"
        LIBRARY DESTINATION "lib"
        ARCHIVE DESTINATION "lib"
    )
endif()
