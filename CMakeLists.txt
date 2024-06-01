cmake_minimum_required(VERSION 3.10)
project(MarkowitzModel)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)

add_library(Matrix SHARED src/Matrix.cpp)
add_library(CsvReader SHARED src/CsvReader.cpp)
add_library(Algorithm SHARED src/Algorithm.cpp)
add_library(PortfolioSolver SHARED src/PortfolioSolver.cpp)
add_library(AssetCharacteristics SHARED src/AssetCharacteristics.cpp)
add_library(Backtest SHARED src/Backtest.cpp)

target_link_libraries(PortfolioSolver Algorithm AssetCharacteristics)
target_link_libraries(Backtest CsvReader PortfolioSolver)

add_executable(Markowitz Main.cpp)
target_link_libraries(Markowitz Backtest PortfolioSolver)
