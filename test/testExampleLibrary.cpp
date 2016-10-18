#include "gtest/gtest.h"

#include <yarp/os/all.h>
#include <yarp/dev/Drivers.h>
#include <yarp/dev/PolyDriver.h>

namespace teo
{

/**
 * @brief Test
 */
class ExampleLibraryTest : public testing::Test
{

    public:
        virtual void SetUp() {

            //setenv("YARP_VERBOSE","1",1);
            //yarp::os::ResourceFinder::setVerbose();

            yarp::os::Property options("(device ExampleLibrary)");

            device.open(options);
            if( ! device.isValid() ) {
                printf("device not valid: %s.\n",options.find("device").asString().c_str());
                return;
            }
        }

        virtual void TearDown()
        {
            device.close();
        }

    protected:
        yarp::dev::PolyDriver device;
};

TEST_F( ExampleLibraryTest, ExampleTest1)
{
    ASSERT_EQ(1, 1 );
}

}  // namespace teo

