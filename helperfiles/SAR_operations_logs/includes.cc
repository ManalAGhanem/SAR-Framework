
#include <unordered_set>

#include <iomanip>
#include <filesystem>
#include <algorithm> 
#include <numeric>   
#include <random>    
#include <sstream> 
#include <fstream>
#include <string>
#include <iostream>
#include <cmath>  
#include <cstddef>  
#include <vector>
#include <cstdint>  
#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/mobility-module.h"
#include "ns3/wifi-module.h"
#include "ns3/internet-module.h"
#include "ns3/applications-module.h"
#include "ns3/netanim-module.h"
#include "ns3/udp-socket-factory.h"
#include "ns3/udp-client-server-helper.h"
#include "ns3/socket.h"
#include "ns3/aodv-module.h"
#include "ns3/dsdv-module.h"
#include "ns3/ipv4-static-routing.h"
#include "ns3/ipv4-list-routing.h"
#include "ns3/dsr-module.h"
#include "ns3/olsr-module.h"
#include "ns3/flow-monitor-helper.h"
#include "ns3/ipv4-flow-classifier.h"  
#include <map> 
#include <unordered_map> 
#include <cstring>
#include "ns3/node.h"
#include "ns3/ipv4.h"
#include "ns3/ipv4-address.h"
#include "ns3/energy-module.h"
#include "ns3/basic-energy-source.h"
#include "ns3/li-ion-energy-source.h"
#include "ns3/wifi-radio-energy-model.h"
#include <utility>
#include "ns3/propagation-module.h"
#include "ns3/buildings-module.h"
#include "ns3/buildings-helper.h"
#include "ns3/building.h"
#include "ns3/hybrid-buildings-propagation-loss-model.h"
#include "ns3/buildings-module.h"
#include "ns3/mobility-helper.h"
#include "ns3/traffic-control-helper.h"
#include "ns3/wifi-mac-queue.h"
#include "ns3/ipv4-header.h"
#include "ns3/traffic-control-layer.h"
#include "ns3/energy-source.h"
#include <fstream>
#include <iomanip>
#include "ns3/wifi-mac-header.h"
#include "ns3/packet.h"
#include "ns3/simulator.h"
#include "ns3/node.h"
#include "ns3/tag.h"



class NodeIdTag : public ns3::Tag
{
public:
    NodeIdTag () : m_nodeId(0) {}
    NodeIdTag (uint32_t nodeId) : m_nodeId(nodeId) {}

    static ns3::TypeId GetTypeId (void) {
        static ns3::TypeId tid = ns3::TypeId ("NodeIdTag")
            .SetParent<ns3::Tag> ()
            .AddConstructor<NodeIdTag> ();
        return tid;
    }
    virtual ns3::TypeId GetInstanceTypeId (void) const { return GetTypeId (); }
    virtual void Serialize (ns3::TagBuffer i) const { i.WriteU32 (m_nodeId); }
    virtual uint32_t GetSerializedSize (void) const { return 4; }
    virtual void Deserialize (ns3::TagBuffer i) { m_nodeId = i.ReadU32 (); }
    virtual void Print (std::ostream &os) const { os << "NodeId=" << m_nodeId; }

    void SetNodeId(uint32_t nodeId) { m_nodeId = nodeId; }
    uint32_t GetNodeId() const { return m_nodeId; }
private:
    uint32_t m_nodeId;
};

