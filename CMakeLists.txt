cmake_minimum_required(VERSION 3.8)
project(NewProjectQT)

set(OpenCV_STATIC OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

FIND_PACKAGE(Qt5Widgets REQUIRED)

FIND_PACKAGE(OpenCV REQUIRED)
if( NOT OpenCV_FOUND )
    message( FATAL_ERROR "Cannot build without OpenCV! Please provide location of OpenCV cmake files!" )
endif()
 
if(CMAKE_CL_64)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/bin/X86)
else(CMAKE_CL_64)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/build/bin/X64)
endif(CMAKE_CL_64)

add_subdirectory("include")
add_subdirectory("src")

source_group( "Header Files" FILES ${headers})
source_group( "Source Files" FILES ${sources})

include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/include"
					${CMAKE_BINARY_DIR}
					${OpenCV_INCLUDE_DIRS})

message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

link_directories(${OpenCV_LIB_DIR})
 
qt5_wrap_ui(UIS_HDRS ${CMAKE_CURRENT_SOURCE_DIR}/src/interface.ui)

ADD_EXECUTABLE(NewProjectQT ${sources} ${headers} ${UIS_HDRS})

TARGET_LINK_LIBRARIES(NewProjectQT Qt5::Widgets ${OpenCV_LIBS})

if(WIN32)
    if($<CONFIG:Debug>)
        get_target_property(WIDGETDLL Qt5::Widgets IMPORTED_LOCATION_DEBUG)
    else($<CONFIG:Debug>)
        get_target_property(WIDGETDLL Qt5::Widgets IMPORTED_LOCATION_RELEASE)
    endif($<CONFIG:Debug>)
    
   add_custom_command( TARGET NewProjectQT POST_BUILD
                        COMMAND ${CMAKE_COMMAND} -E copy
                                 $<TARGET_FILE:Qt5::Widgets>
                                 $<TARGET_FILE:Qt5::Core>
                                 $<TARGET_FILE:Qt5::Gui>
                                 $<TARGET_FILE_DIR:NewProjectQT>) 
endif(WIN32)