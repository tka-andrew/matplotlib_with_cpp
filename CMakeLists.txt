# Reference: https://github.com/lava/matplotlib-cpp/issues/236

cmake_minimum_required(VERSION 3.10)

# set the project name
project(MatplotlibWithCppExample VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find python libraries
find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)
find_package(PythonLibs 3.0 REQUIRED)
include_directories(${PYTHON3_INCLUDE_DIRS} ${NumPy_INCLUDE_DIRS})

# REFERENCE: https://www.youtube.com/watch?v=ED-WUk440qc&list=PLalVdRk2RC6o5GHu618ARWh0VO0bFlif4&index=3
# DOWNLOAD ALL THE SUBMODULES
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed ${GIT_SUBMOD_RESULT}, please check")
        endif()
    endif()
endif()

# CHECK ALL THE SUBMODULES
if(NOT EXISTS "${PROJECT_SOURCE_DIR}/thirdparty/matplotlib-cpp/CMakeLists.txt")
    message(FATAL_ERROR "The matplotlib-cpp submodule was not downloaded! GIT_SUBMODULE was turned off or failed!")
endif()

add_subdirectory(thirdparty/matplotlib-cpp)

# add the executable
add_executable(${PROJECT_NAME} src/main.cpp)

# include
target_include_directories(${PROJECT_NAME}
    PUBLIC
        thirdparty/matplotlib-cpp
)

# link python and numpy
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ${PYTHON_LIBRARIES}
        Python3::NumPy
)