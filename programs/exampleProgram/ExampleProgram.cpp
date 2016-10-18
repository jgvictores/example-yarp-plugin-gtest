// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "ExampleProgram.hpp"

namespace teo
{

/************************************************************************/

bool ExampleProgram::configure(yarp::os::ResourceFinder &rf) {

    printf("--------------------------------------------------------------\n");
    if (rf.check("help")) {
        printf("ExampleProgram options:\n");
        printf("\t--help (this help)\t--from [file.ini]\t--context [path]\n");
        //printf("\t--file (default: \"%s\")\n",fileName.c_str());
    }

    printf("--------------------------------------------------------------\n");

    printf("YARP_VERBOSE before forcing is: %s\n", std::getenv("YARP_VERBOSE") );
    setenv("YARP_VERBOSE","1",1);  //-- Does not seem to have any additional effect in travis.
    printf("YARP_VERBOSE after forcing is:  %s\n", std::getenv("YARP_VERBOSE") );

    //yarp::os::ResourceFinder::setVerbose();  //-- Way out of scope: not static, and we do not use ResourceFinder here.

    yarp::os::Property options;
    options.put("device","ExampleLibrary");

    device.open(options);
    if( ! device.isValid() ) {
        printf("device not valid: %s.\n",options.find("device").asString().c_str());
        return false;
    }

    counter = 3;

    return true;
}

/************************************************************************/
double ExampleProgram::getPeriod() {
    return 0.5;  // Fixed, in seconds, the slow thread that calls updateModule below
}

/************************************************************************/
bool ExampleProgram::updateModule() {
    printf("Count: %d\n",counter);
    if ( counter == 0 )
        this->stopModule();

    counter--;

    return true;
}

/************************************************************************/

bool ExampleProgram::interruptModule() {
    return true;
}

/************************************************************************/

}  // namespace teo

