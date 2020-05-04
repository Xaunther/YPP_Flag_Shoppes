cmake_minimum_required(VERSION 3.0.0)
project(YPP_Flag_Shoppes VERSION 0.1.0)

#Silence MS compiler on fopen warning
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif()

#Include dirs
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/libcurl/include)

#1 for all
file(GLOB cpp_files "src/*.cpp")
add_library(ypp_flag_shoppe_lib ${cpp_files})

#Main exec
add_executable(YPP_Flag_Shoppes src/main.cpp)

#Link against single library and curl
target_link_libraries(YPP_Flag_Shoppes ypp_flag_shoppe_lib)
target_link_libraries(YPP_Flag_Shoppes ${CMAKE_SOURCE_DIR}/libcurl/lib/libcurl.lib)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

#Post-build setup
#Move necessary stuff for the exe to run
add_custom_command(TARGET YPP_Flag_Shoppes POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/libcurl/lib/libcurl.dll ${CMAKE_SOURCE_DIR}/build/Release
    COMMENT "Copying DLLs"
)
add_custom_command(TARGET YPP_Flag_Shoppes POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/build/Release/downloads
    COMMENT "Creating downloads folder"
)

