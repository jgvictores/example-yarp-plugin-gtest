// -*- mode:C++; tab-width:4; c-basic-offset:4; indent-tabs-mode:nil -*-

#include "ExampleLibrary.hpp"

namespace teo
{

/************************************************************************/

ExampleLibrary::ExampleLibrary()
{
}

/************************************************************************/

bool ExampleLibrary::open(yarp::os::Searchable& config)
{
	return true;
}

/************************************************************************/

bool ExampleLibrary::close()
{
	return true;
}

/************************************************************************/

}  // namespace teo

