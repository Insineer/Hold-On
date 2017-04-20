cmake_minimum_required(VERSION 3.6)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

project(Hold_On)

set(Hold_On_VERSION_MAJOR 1)
set(Hold_On_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
Sources/main.cpp
Sources/Graphics/Window.cpp
Sources/Graphics/Window.hpp
Sources/Useful.hpp
Sources/World/Map.cpp
Sources/World/Map.hpp
Sources/Game.cpp
Sources/Game.hpp
Sources/Useful/Vec2f.cpp
Sources/Useful/Vec2f.hpp
Sources/World/Objects/Hero.cpp
Sources/World/Objects/Hero.hpp
Sources/World/Objects/Object.cpp
Sources/World/Objects/Object.hpp
Sources/Player.cpp
Sources/Player.hpp
Sources/States/State.cpp
Sources/States/State.hpp
Sources/States/GameProcessState.cpp
Sources/States/GameProcessState.hpp
Sources/World/Objects/Mob.cpp
Sources/World/Objects/Mob.hpp
Sources/Geometry.cpp
Sources/Useful/Shape/Shape.hpp
Sources/Useful/Shape/Circle.cpp
Sources/Useful/Shape/Circle.hpp
Sources/Useful/Shape/Rectangle.cpp
Sources/Useful/Shape/Rectangle.hpp
Sources/Geometry.hpp
Sources/Useful.cpp)

set(EXECUTABLE_NAME "Hold_On")
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

include_directories(${CMAKE_SOURCE_DIR}/Sources)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake-modules")
find_package(SFML 2 REQUIRED system window graphics) #network audio
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()