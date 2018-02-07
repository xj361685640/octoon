SET(LIB_NAME editor)

SET(HEADER_PATH ${COTOON_HEADER_PATH}/${LIB_NAME})
SET(SOURCE_PATH ${COTOON_SOURCE_PATH}/${LIB_NAME})

SET(EDITOR_LIST
${HEADER_PATH}/mainwindow.h
${SOURCE_PATH}/mainwindow.cpp
${HEADER_PATH}/qtmain.h
${SOURCE_PATH}/qtmain.cpp
${HEADER_PATH}/OMainWindow.h
${HEADER_PATH}/OTitleBar.h
)
SOURCE_GROUP(${LIB_NAME} FILES ${EDITOR_LIST})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)
set(Qt5Widgets_DIR ${QT_INCLUDE_PATH})
# Find the QtWidgets library
find_package(Qt5Widgets)

ADD_DEFINITIONS(-D_BUILD_DLL_EXPORT)
ADD_LIBRARY(${LIB_NAME} SHARED ${EDITOR_LIST})
# Use the Widgets module from Qt 5.x
TARGET_LINK_LIBRARIES(${LIB_NAME} Qt5::Widgets)

SET_TARGET_ATTRIBUTE(${LIB_NAME} "core")

# copy resources
file(COPY ${PROJECT_SOURCE_DIR}/resource DESTINATION ${LIBRARY_OUTPUT_PATH})
