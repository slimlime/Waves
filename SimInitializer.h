#pragma once

#include "SimWire.h"
#include "SimNode.h"
#include "SimGraphInterface.h"

namespace hwsim {

// utility class for constructing and initializing SimWire objects
// based on provided default configurations and states
class SimInitializer
{

public:

	SimInitializer();
	~SimInitializer();

	void constructWire(SimWireEdge* edge);
	void initializeWire(SimWireEdge* edge);

	SimWire::Config defaultWireConfig;
	SimWire::InitState defaultWireInitState;

	// the timestep to use when applying the velocity in initialization
	// this seems to be something of an odd one out, not sure where else to put it
	float dt;
};

};