cmake_minimum_required(VERSION 3.21)
project(WineShop)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt6/lib/cmake/")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.ui
)

add_executable(WineShop main.cpp  ${SOURCE_FILES} mainwindow.cpp mainwindow.h cartwindow.cpp cartwindow.h WineTable.cpp WineTable.h CartFilterModel.cpp CartFilterModel.h MainFilterModel.cpp MainFilterModel.h LogoWidget.cpp LogoWidget.h)
target_link_libraries(WineShop
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

