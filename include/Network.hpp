#pragma once

#include <memory>
#include <array>
#include <cstddef>
#include <vector>
#include <map>
#include <list>
#include <hash_map>
#include <hash_set>

namespace 
networkdispatcher{
// BEGIN: networkdispatcher namespace

typedef std::vector<std::byte> byte_buffer;


class Node : public std::enable_shared_from_this<Node>
{
public:
    typedef std::shared_ptr<Node> node_ptr;

    Node()
    {
        //m_id = new_id
    }

    node_ptr getptr()
    {
        return shared_from_this();
    }
private:
    uint64_t m_id;
};

/// @brief exposing the NodePtr definition to global
typedef Node::node_ptr node_ptr;

class Network : public std::enable_shared_from_this<Network>
{
public:

    typedef std::shared_ptr<Network> network_ptr;

    std::shared_ptr<Network> getptr()
    {
        return this->shared_from_this();
    }

    virtual bool Connect(const Network new_network){}

    virtual bool OnNetworkConnect(const network_ptr new_network ){}

    virtual void OnNodeConnect(node_ptr new_node)
    {
        // stablish handshake or whatever
        // get into 
    }

    virtual void OnNodeDisconnect(){}

    virtual void OnReceiveFromNode(const node_ptr node, byte_buffer data){
        // queue the message
    }

    virtual void OnReceiveFromNetwork(){
        // queue the message
    }


private:
    
    std::hash_map<uint64_t,NodePtr> m_nodes_map;
    // behavioral lists
    std::list<uint64_t> m_muted_nodes;
    
    virtual size_t send(const NodePtr node){}


};

} // END: networkdispatcher namespace

