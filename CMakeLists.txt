cmake_minimum_required (VERSION 3.8)
project ("Game")

FILE(GLOB_RECURSE PIXEL_FILES   
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
                    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
                    )

if( ${CMAKE_VERSION} VERSION_GREATER_EQUAL 3.16 )
    set ( CMAKE_UNITY_BUILD_BATCH_SIZE 16 )
endif()

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/opengl/libs)

add_executable (Game ${PIXEL_FILES})

if( ${CMAKE_VERSION} VERSION_GREATER_EQUAL 3.16 )
    target_precompile_headers( Game PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/_pch_/pch.h )
    set_target_properties( Game PROPERTIES UNITY_BUILD ON)
endif()

MACRO( collect_head_dirs return_list )
    FILE(GLOB_RECURSE new_list 
                      ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
                      ${CMAKE_CURRENT_SOURCE_DIR}/src/*.hpp
                      )
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

collect_head_dirs( src_header_dirs )

target_include_directories ( Game PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/deps/opengl/include
    ${src_header_dirs}
    )

target_link_libraries(Game OpenGL32 glfw3)

