SET(LIB_NAME editor)

SET(HEADER_PATH ${COTOON_HEADER_PATH}/${LIB_NAME})
SET(SOURCE_PATH ${COTOON_SOURCE_PATH}/${LIB_NAME})

SET(EDITOR_LIST
${HEADER_PATH}/qtmain.h
${SOURCE_PATH}/qtmain.cpp
${HEADER_PATH}/mainwindow.h
${SOURCE_PATH}/mainwindow.cpp
${HEADER_PATH}/widgets/OViewWidget.h
${SOURCE_PATH}/widgets/OViewWidget.cpp
)
SOURCE_GROUP(${LIB_NAME} FILES ${EDITOR_LIST})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set_property(SOURCE qrc_qml.cpp qrc_qss.cpp PROPERTY SKIP_AUTOMOC ON)
set(CMAKE_AUTOMOC ON)


# add resources
set(Qt5_DIR ${QT_INCLUDE_PATH}/Qt5)
find_package(Qt5 COMPONENTS Quick Core Network Widgets QuickWidgets)
qt5_add_resources(RESOURCES qml.qrc qss.qrc)

ADD_DEFINITIONS(-D_BUILD_DLL_EXPORT)
ADD_LIBRARY(${LIB_NAME} SHARED ${EDITOR_LIST} ${RESOURCES})

TARGET_LINK_LIBRARIES(${LIB_NAME} Qt5::Core Qt5::Widgets Qt5::QuickWidgets)

# qt5_use_modules(${LIB_NAME} Quick Core Network Widgets QuickWidgets)


SET_TARGET_ATTRIBUTE(${LIB_NAME} "core")

# copy resources
file(COPY ${PROJECT_SOURCE_DIR}/resource DESTINATION ${LIBRARY_OUTPUT_PATH})
file(COPY ${COTOON_SOURCE_PATH}/${LIB_NAME}/qml DESTINATION ${LIBRARY_OUTPUT_PATH})
file(COPY ${COTOON_SOURCE_PATH}/${LIB_NAME}/qss DESTINATION ${LIBRARY_OUTPUT_PATH})
# file(COPY ${COTOON_SOURCE_PATH}/${LIB_NAME}/${RESOURCESss} DESTINATION ${LIBRARY_OUTPUT_PATH})
