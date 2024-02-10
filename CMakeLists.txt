cmake_minimum_required(VERSION 3.10)
project(PacmanClone)

# Add the executable
add_executable(pacman src/main.c src/pacman_logic/pacman.c)

# Set include directories
target_include_directories(pacman PUBLIC src/pacman_logic)

# Find SDL2 library
find_package(SDL2 REQUIRED)
target_include_directories(pacman PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(pacman PRIVATE ${SDL2_LIBRARIES})
