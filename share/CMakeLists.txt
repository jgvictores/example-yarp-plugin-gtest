# Copyright: UC3M 2016
# Author: jgvictores
# CopyPolicy: Released under the terms of the GNU GPL v2.0.
# 

find_package(YARP REQUIRED)
list(APPEND CMAKE_MODULE_PATH ${YARP_MODULE_PATH})
include(YarpInstallationHelpers)
yarp_configure_external_installation(gtest-yarp-plugins)

### Go through single applications

#add_subdirectory(prog)

