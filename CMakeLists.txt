cmake_minimum_required(VERSION 3.16...3.21)
project(SimpleDetector)

# Find Geant4 package
find_package(Geant4 REQUIRED ui_all vis_all)

# Include Geant4 headers
include(${Geant4_USE_FILE})

# Add source files
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)

# Add the executable and link libraries
add_executable(SimpleDetector main.cc ${sources} ${headers})
target_link_libraries(SimpleDetector ${Geant4_LIBRARIES})

# Add the source directories to include path
target_include_directories(SimpleDetector PUBLIC 
    ${PROJECT_SOURCE_DIR}/include
    ${Geant4_INCLUDE_DIR})

# Copy macro files to build directory
file(GLOB macros ${PROJECT_SOURCE_DIR}/macros/*.mac)
foreach(_macro ${macros})
    file(COPY ${_macro} DESTINATION ${PROJECT_BINARY_DIR})
endforeach()