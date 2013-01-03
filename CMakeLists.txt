cmake_minimum_required (VERSION 2.8)
project (qiron)


# Custom modules
set (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")


# Project header
include (project_cxx_header)


# Main settings
set (USE_GPROF    NO)
set (UNIT_TESTING NO CACHE BOOL "Compile binary executable for unit testing?")


# Fix path delimeters
if (WIN32)
    file (TO_CMAKE_PATH ${CMAKE_INSTALL_PREFIX} CMAKE_INSTALL_PREFIX)
endif ()


# 3rdparty
find_package (Qt4 4.7.1 COMPONENTS QtCore QtGui QtXml REQUIRED)
include (${QT_USE_FILE})
set (${PROJECT_NAME}_LIBS ${${PROJECT_NAME}_LIBS} ${QT_LIBRARIES})
add_definitions (${QT_DEFINITIONS})


# Includes
include_directories (include)

# Link directories

# Libs
if (USE_GPROF)
	set (${PROJECT_NAME}_LIBS ${${PROJECT_NAME}_LIBS} gmon)
endif (USE_GPROF)
 
# Definitions
add_definitions (
    -DQIRON_LIBRARY_EXPORT
    -DQIR_NO_NAMESPACE_SUPPORT
    -DUNICODE
    -DQT_NO_CAST_FROM_ASCII
)

# We're require at least Windows 2000 (http://msdn.microsoft.com/en-us/library/Aa383745)
if (WIN32)
    add_definitions (-D_WIN32_WINNT=0x0500 -DWINVER=0x0500)
endif ()


# Sources
add_subdirectory(src)
QT4_WRAP_UI (${PROJECT_NAME}_UIS_HEADERS ${${PROJECT_NAME}_UIS})
QT4_WRAP_CPP (${PROJECT_NAME}_MOC_SOURCES ${${PROJECT_NAME}_HEADERS} OPTIONS "-nw")
set (${PROJECT_NAME}_SOURCES ${${PROJECT_NAME}_SOURCES} ${${PROJECT_NAME}_MOC_SOURCES} ${${PROJECT_NAME}_UIS_HEADERS})


# Resources
QT4_ADD_RESOURCES (${PROJECT_NAME}_RESOURCES_BIN ${${PROJECT_NAME}_RESOURCES})
set (${PROJECT_NAME}_SOURCES ${${PROJECT_NAME}_SOURCES} ${${PROJECT_NAME}_RESOURCES_BIN})


# Target - qiron
add_library(qiron ${${PROJECT_NAME}_SOURCES})
target_link_libraries (qiron ${${PROJECT_NAME}_LIBS})

# It is because of Qt (qglobal.h)
set_target_properties (qiron PROPERTIES COMPILE_FLAGS "-Wno-long-long")

# Compiler flags
if (USE_GPROF)
    set (CMAKE_CXX_FLAGS        ${CMAKE_CXX_FLAGS}        -pg)
    set (CMAKE_EXE_LINKER_FLAGS ${CMAKE_EXE_LINKER_FLAGS} -pg)
endif (USE_GPROF)
