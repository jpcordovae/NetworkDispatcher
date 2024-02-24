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
    std::hash_map<uint64_t,node_ptr> m_nodes_map;
    bool m_allow_echo; /// @brief allow echo of messages
public:

    typedef std::shared_ptr<Network> network_ptr;
    
    bool AllowEcho() const
    {
        return m_allow_echo;
    }

    void AllowEcho(bool _allow)
    {
        m_allow_echo = _allow;
    }

    /**
     * This method is used to get a shared pointer to the current instance of the Network class.
     * 
     * @return A shared pointer to the current instance of the Network class.
     * 
     * This method uses the `shared_from_this()` method, which is a special method provided by the 
     * `std::enable_shared_from_this` class in C++. This method allows an object that is currently 
     * owned by a `std::shared_ptr` to safely generate another `std::shared_ptr` that shares ownership 
     * of the object.
     */
    std::shared_ptr<Network> getptr()
    {
        return this->shared_from_this();
    }
    
    bool ExistsNodeByID(const uint64_t _id)
    {
        return m_nodes_map.find(_id) != m_nodes_map.end();
    }

    bool ExistsNode(const node_ptr _node)
    {
        return m_nodes_map.find(_node->GetID()) != m_nodes_map.end();
    }

    /**
     * This method is used to add a new node to the network.
     * 
     * @param _new_node A shared pointer to the new node that is being added to the network.
     * 
     * This method is used to add a new node to the network. It is called by the `Node` class when a new 
     * node is created. The method adds the new node to the network's list of nodes, and then calls the 
     * `OnNodeConnect` method to allow the network to perform any necessary setup or initialization for 
     * the new node.
     */
    void ConnectNode(const node_ptr _new_node)
    {
        if(m_nodes_map.find(_new_node->GetID()) == m_nodes_map.end())
        {
            m_nodes_map[_new_node->GetID()] = _new_node;
            OnNodeConnect(_new_node);
        }
    }

    void DisconnectNode(const node_ptr _node)
    {
        if(m_nodes_map.find(_node->GetID()) != m_nodes_map.end())
        {
            m_nodes_map.erase(_node->GetID());
            OnNodeDisconnect();
        }
    }

    /**
     * This is a virtual method that is called when a new node connects to the network.
     * Subclasses should override this method to implement the specific behavior when a new node connects.
     * 
     * @param new_node A shared pointer to the node that has just connected to the network.
     * 
     * Typical uses of this method could include:
     * - Establishing a handshake or other connection protocol with the new node.
     * - Adding the new node to a list or other data structure that tracks connected nodes.
     */
    virtual void OnNodeConnect(node_ptr new_node)
    {
        // add the node to the list of connected nodes
    }

    /**
     * This is a virtual method that is called when a node disconnects from the network.
     * Subclasses should override this method to implement the specific behavior when a node disconnects.
     * 
     * Typical uses of this method could include:
     * - Cleaning up resources associated with the disconnected node.
     * - Removing the node from a list or other data structure that tracks connected nodes.
     */
    virtual void OnNodeDisconnect(){
        // remove the node from the list of connected nodes

    }

    /**
     * This is a virtual method that is called when a message is received from a node.
     * Subclasses should override this method to implement the specific behavior when a message is received.
     * 
     * @param node A shared pointer to the node that sent the message.
     * @param data The data that was received from the node.
     * 
     * Typical uses of this method could include:
     * - Processing the received data.
     * - Responding to the message.
     * - Updating the state of the network or the nodes based on the received data.
     */
    virtual void OnReceiveFromNode(const node_ptr node, data_buffer data)
    {
        // queue the message
    }

    virtual void Dispatch(node_ptr _node, data_buffer_ptr message)
    {
        if(message == nullptr)
        {
            return;
        }

        for(auto& node : m_nodes_map)
        {
            if( (node.second->GetID() == _node->GetID()) && !m_allow_echo)
            {
                continue;
            }
            node.second->Receive(message);
        }
    }

private:
    // behavioral lists
    std::list<uint64_t> m_muted_nodes;
    std::list<uint64_t> m_deaf_nodes;
    

};

typedef Network::network_ptr network_ptr;

network_ptr CreateNetwork()
{
    return std::make_shared<Network>();
}

} // END: networkdispatcher namespace

