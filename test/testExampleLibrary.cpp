#include "gtest/gtest.h"

#include <yarp/os/all.h>
#include <yarp/dev/Drivers.h>
#include <yarp/dev/PolyDriver.h>

namespace teo
{

/**
 * @brief Test
 */
class ExampleTest : public testing::Test
{

    public:
        virtual void SetUp() {

            setenv("YARP_VERBOSE","1",1);
            //yarp::os::ResourceFinder::setVerbose();

            yarp::os::Property options("(device Example)");

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

TEST_F( ExampleTest, ExampleTest1)
{
    ASSERT_EQ(1, 1 );
}

}  // namespace teo

