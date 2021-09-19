cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(NAOCMAKE VERSION 0.1 LANGUAGES CXX)

set(CMAKE_MODULE_PATH C:/naoqi-sdk/share/cmake C:/naoqi-sdk/share/cmake/qibuild/modules)
set(CMAKE_PREFIX_PATH C:/Qt/5.15.1/msvc2015_64/lib/cmake C:/naoqi-sdk/lib/cmake)

set(QT_DIR  C:/Qt/5.15.1/msvc2015_64/lib/cmake/Qt5)
set(Qt5_DIR C:/Qt/5.15.1/msvc2015_64/lib/cmake/Qt5)


INCLUDE_DIRECTORIES("C:/naoqi-sdk/include")
LINK_DIRECTORIES("C:/naoqi-sdk/lib" )
#INCLUDE_DIRECTORIES(NAOCMAKE C:/Qt/5.15.1/msvc2015_64/include/QtWidgets C:/Qt/5.15.1/msvc2015_64/include)

find_package(qibuild )
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)



set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)



qi_create_bin(NAOCMAKE ${PROJECT_SOURCES})
add_library(NAO)
qi_use_lib(NAO ALCOMMON ALVALUE ALERROR ALPROXIES)

target_link_libraries(NAOCMAKE PRIVATE Qt5::Widgets NAO)





