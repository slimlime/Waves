#pragma once

#include <vector>
#include "SimWire.h"
#include "SimNode.h"

namespace hwsim {

//class SimWire;
//class SimNode;

struct SimWireEdge;
struct SimNodeVertex;

// Interfaces for SimWire and SimNode to use, in order to access the graph model
// the data fields of a DirectedGraph<> Edge/Vertex specialization should implement these

struct SimWireEdge
{
	friend class SimWire;
	friend class SimNode;

	SimWireEdge() {};
	virtual ~SimWireEdge() {};

	virtual SimNodeVertex& getStartNode() = 0;
	virtual SimNodeVertex& getEndNode() = 0;
	virtual SimWire* getWire() = 0;
	virtual void setWire(SimWire* _wire) = 0;
	virtual SimWire::Config* getWireConfig() = 0;
	virtual SimWire::InitState* getInitState() = 0;
};

struct SimNodeVertex
{
	friend class SimWire;
	friend class SimNode;

	using Edges = std::vector<SimWireEdge*>;

	SimNodeVertex() {};
	virtual ~SimNodeVertex() {};

	virtual Edges& getEdges() = 0;
	virtual SimNode* getSimNode() = 0;
	virtual void setSimNode(hwsim::SimNode* node) = 0;
};

};