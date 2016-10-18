// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#ifndef __EXAMPLE_LIBRARY_HPP__
#define __EXAMPLE_LIBRARY_HPP__

#include <yarp/os/all.h>
#include <yarp/dev/all.h>

namespace teo
{

/**
 * @ingroup exampleLibrary
 *
 * @brief exampleLibrary
 *
 */
class ExampleLibrary : public yarp::dev::DeviceDriver {

public:

	ExampleLibrary();

	virtual bool open(yarp::os::Searchable& config);

	virtual bool close();

protected:

};

}  // namespace teo

#endif  // __EXAMPLE_LIBRARY_HPP__
