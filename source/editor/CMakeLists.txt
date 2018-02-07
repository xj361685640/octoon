SET(LIB_NAME editor)

SET(HEADER_PATH ${COTOON_HEADER_PATH}/${LIB_NAME})
SET(SOURCE_PATH ${COTOON_SOURCE_PATH}/${LIB_NAME})

SET(EDITOR_LIST
${HEADER_PATH}/mainwindow.h
${SOURCE_PATH}/mainwindow.cpp
${HEADER_PATH}/qtmain.h
${SOURCE_PATH}/qtmain.cpp
)
SOURCE_GROUP(${LIB_NAME} FILES ${EDITOR_LIST})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(Qt5Widgets_DIR C:/Qt/5.10.0/msvc2017_64/lib/cmake/Qt5Widgets)
# Find the QtWidgets library
find_package(Qt5Widgets)

ADD_DEFINITIONS(-D_BUILD_DLL_EXPORT)
ADD_LIBRARY(${LIB_NAME} SHARED ${EDITOR_LIST})
# Use the Widgets module from Qt 5.x
TARGET_LINK_LIBRARIES(${LIB_NAME} Qt5::Widgets)



SET_TARGET_ATTRIBUTE(${LIB_NAME} "core")
