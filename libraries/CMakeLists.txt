# Copyright: Universidad Carlos III de Madrid (C) 2016
# Authors: jgvictores

find_package(YARP REQUIRED)
include_directories(${YARP_INCLUDE_DIRS})
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
include(YarpPlugin)

yarp_begin_plugin_library(GtestYarp)
    add_subdirectory(ExampleLibrary)
yarp_end_plugin_library(GtestYarp)

install(TARGETS GtestYarp DESTINATION lib)

yarp_add_plugin_yarpdev_executable(launchGtestYarp GtestYarp)
install(TARGETS launchGtestYarp DESTINATION bin)

