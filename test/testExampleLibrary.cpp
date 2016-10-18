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

            printf("YARP_VERBOSE before forcing is: %s\n", std::getenv("YARP_VERBOSE") );
            setenv("YARP_VERBOSE","1",1);  //-- Does not seem to have any additional effect in travis.
            printf("YARP_VERBOSE after forcing is:  %s\n", std::getenv("YARP_VERBOSE") );

            //yarp::os::ResourceFinder::setVerbose();  //-- Way out of scope: not static, and we do not use ResourceFinder here.

            yarp::os::Property options;
            options.put("device","ExampleLibrary");

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

