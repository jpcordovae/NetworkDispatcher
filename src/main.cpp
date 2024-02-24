#include <iostream>
#include "Network.hpp"

using namespace networkdispatcher;

network_ptr network = CreateNetwork();

int main() {
    

    // Load nodes
    node_ptr node1 = std::make_shared<Node>(network);
    node1->SetName("Node1");

    node_ptr node2 = std::make_shared<Node>(network);
    node2->SetName("Node2");

    node_ptr node3 = std::make_shared<Node>(network);
    node3->SetName("Node3");

    node1->Send("Hello from Node1 to Node2");

    // Rest of your code...

    return 0;
}
