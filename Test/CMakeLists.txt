cmake_minimum_required(VERSION 3.5.0)

#Project name
project(Light_Qt_Test)

#setup include and linking directories
include_directories(inc
                    )

#setup source files
set(src main.cpp
        )
        
#setup header files
set(include 
            )
            
#create the library
add_executable(${PROJECT_NAME} ${src} ${include})

#linking
target_link_libraries(${PROJECT_NAME} Qt5::Widgets
                                      Light_Qt)
