#pragma once

#include <memory>

#include <network_common.hpp>

class Node : public std::enable_shared_from_this<Node>
{
public:
    typedef std::shared_ptr<Node> node_ptr;

    Node() = delete;

    node_ptr getptr()
    {
        return shared_from_this();
    }
private:
    uint64_t m_id;

    friend class Network;
};

/// @brief exposing the NodePtr definition to global
typedef Node::node_ptr node_ptr;
