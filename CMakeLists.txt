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
        Sources/Useful/Memory.hpp
                Sources/World/Map.cpp
                Sources/World/Map.hpp
                Sources/Game.cpp
                Sources/Game.hpp
        Sources/Useful/Geometry/Vec2f.cpp
        Sources/Useful/Geometry/Vec2f.hpp
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
        Sources/Useful/Geometry/Geometry.cpp
        Sources/Useful/Geometry/Shape/Shape.hpp
        Sources/Useful/Geometry/Shape/Circle.cpp
        Sources/Useful/Geometry/Shape/Circle.hpp
        Sources/Useful/Geometry/Shape/Rectangle.cpp
        Sources/Useful/Geometry/Shape/Rectangle.hpp
        Sources/Useful/Geometry/Geometry.hpp
        Sources/Useful/Math.cpp Sources/Useful/Math.hpp Sources/Useful/Geometry/Shape/Shape.cpp Sources/World/Objects/Enemy.cpp Sources/World/Objects/Enemy.hpp Sources/World/Objects/Turret.cpp Sources/World/Objects/Turret.hpp)

set(EXECUTABLE_NAME "Hold_On")
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

include_directories(${CMAKE_SOURCE_DIR}/Sources)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake-modules")
find_package(SFML 2 REQUIRED system window graphics) #network audio
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()