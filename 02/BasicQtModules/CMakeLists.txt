cmake_minimum_required(VERSION 3.5)

project(BasicQtModules LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network Sql)

add_executable(BasicQtModules
  main.cpp
)
target_link_libraries(BasicQtModules Qt${QT_VERSION_MAJOR}::Core
                                     Qt${QT_VERSION_MAJOR}::Network
                                     Qt${QT_VERSION_MAJOR}::Sql)
install(TARGETS BasicQtModules
LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
