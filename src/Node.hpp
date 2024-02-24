#pragma once

#include <memory>
#include <network_common.hpp>
#include <string>
#include <deque>

#include "Network.hpp"


namespace networkdispatcher
{

class Network;

class Node : public std::enable_shared_from_this<Node>
{
    uint64_t m_id;
    network_ptr& m_network;
    std::string m_name;
    bool m_connect_node_on_creation;
    std::deque<data_buffer_ptr> m_recent_messages;
public:
    typedef std::shared_ptr<Node> node_ptr;

    Node() = delete;

    node_ptr getptr()
    {
        return shared_from_this();
    }

    uint64_t GetID() const
    {
        return m_id;
    }

    Node(network_ptr _network) : m_network{_network}, m_id{rand_uint64()}
    {
        while(m_network->ExistsNodeByID(m_id))
        {
            m_id = rand_uint64();
        }

        _network->ConnectNode(getptr());
    }

    void SetName(const std::string& _name)
    {
        m_name = _name;
    }

    std::string GetName() const
    {
        return m_name;
    }

    /// @brief receive message from the network
    /// @param _buffer 
    /// @return 
    virtual size_t Deliver(const data_buffer_ptr _buffer)
    {
        #warning "Not implemented"
        return 0;
    }

    virtual size_t Deliver(node_ptr _node, const data_buffer_ptr _buffer)
    {
        #warning "Not implemented"
        return 0;
    }

    /// @brief send message to the network
    /// @param _buffer 
    /// @return 
    virtual size_t Send(const data_buffer_ptr _buffer)
    {
        m_network->Dispatch(getptr(), _buffer);
    }

    virtual ~Node()
    {
        LeaveNetwork();
    }

    void LeaveNetwork()
    {
        OnLeave();
    }

private:
    void OnLeave()
    {
        m_network->DisconnectNode(getptr());
    }

    

};

/// @brief exposing the Node::node_ptr definition to global
typedef Node::node_ptr node_ptr;

} // END: networkdispatcher namespace



