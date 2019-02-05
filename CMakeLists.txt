cmake_minimum_required(VERSION 3.5.0)

#Project name
project(Light_Qt)

#setup qt
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

#fine QtWidgets library
find_package(Qt5Widgets REQUIRED)

#setup include and linking directories
include_directories(inc
                    )

#setup source files
set(src src/Light.cpp
        )
        
#setup header files
set(include inc/Light.h
            )
            
#create the library
add_library(${PROJECT_NAME} ${src} ${include})

#linking
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

set(BUILD_TEST false)
if(BUILD_TEST)
  add_subdirectory(Test)
endif(BUILD_TEST)
