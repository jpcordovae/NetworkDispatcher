#pragma once

#include <map>
#include <list>
#include <hash_map>
#include <hash_set>

#include "network_common.hpp"
#include "Node.hpp"

namespace 
networkdispatcher{
// BEGIN: networkdispatcher namespace

class Network : public std::enable_shared_from_this<Network>
{
public:

    typedef std::shared_ptr<Network> network_ptr;

    std::shared_ptr<Network> getptr()
    {
        return this->shared_from_this();
    }

    virtual bool Connect(const Network new_network){}

    virtual void OnNodeConnect(node_ptr new_node)
    {
        // stablish handshake or whatever
        // get into 
    }

    virtual void OnNodeDisconnect(){}

    virtual void OnReceiveFromNode(const node_ptr node, byte_buffer data){
        // queue the message
    }

private:
    
    std::hash_map<uint64_t,node_ptr> m_nodes_map;
    // behavioral lists
    std::list<uint64_t> m_muted_nodes;
    
    virtual size_t send(const NodePtr node){}


};

} // END: networkdispatcher namespace

