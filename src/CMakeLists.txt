# CMake tools
include (collect_sources)


collect_sources (src_HEADERS src_SOURCES ${CMAKE_SOURCE_DIR})


# Headers
set (${PROJECT_NAME}_HEADERS ${${PROJECT_NAME}_HEADERS} ${src_HEADERS} PARENT_SCOPE)


# Sources
set (${PROJECT_NAME}_SOURCES ${${PROJECT_NAME}_SOURCES} ${src_SOURCES} PARENT_SCOPE)


# UIs
collect_files (src_UIS "*.ui" ${CMAKE_SOURCE_DIR})
set (${PROJECT_NAME}_UIS ${${PROJECT_NAME}_UIS} ${src_UIS} PARENT_SCOPE)


# Resources
collect_files (src_RESOURCES "*.qrc" ${CMAKE_SOURCE_DIR})
set (${PROJECT_NAME}_RESOURCES ${${PROJECT_NAME}_RESOURCES} ${src_RESOURCES} PARENT_SCOPE)
