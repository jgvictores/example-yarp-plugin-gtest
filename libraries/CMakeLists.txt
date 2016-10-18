# Copyright: Universidad Carlos III de Madrid (C) 2016
# Authors: jgvictores

find_package(YARP REQUIRED)
include_directories(${YARP_INCLUDE_DIRS})
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
include(YarpPlugin)

yarp_begin_plugin_library(TeoYarp)
    add_subdirectory(ExampleLibrary)
yarp_end_plugin_library(TeoYarp)

