# Testing things #########################################################################################
add_subdirectory(gtest-1.7.0)
enable_testing()

find_package(YARP REQUIRED)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ${YARP_INCLUDE})

link_directories(${YARP_LINK_DIRS})

add_executable(testExampleLibrary testExampleLibrary.cpp)
target_link_libraries(testExampleLibrary ${YARP_LIBRARIES} gtest gtest_main)

