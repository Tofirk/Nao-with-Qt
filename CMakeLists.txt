cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(NAOCMAKE VERSION 0.1 LANGUAGES CXX)

set(CMAKE_PREFIX_PATH C:/naoqi-sdk/lib/cmake)

set(QT_DIR  C:/Qt/5.15.2/msvc2015_64/lib/cmake/Qt5)
set(Qt5_DIR C:/Qt/5.15.2/msvc2015_64/lib/cmake/Qt5)


LINK_DIRECTORIES(C:/naoqi-sdk/lib)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(qibuild)


add_library(NAO)
qi_use_lib(NAO ALPROXIES ALCOMMON ALVALUE ALERROR)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

qi_create_bin(NAOCMAKE ${PROJECT_SOURCES})
target_link_libraries(NAOCMAKE PRIVATE Qt5::Widgets NAO)





