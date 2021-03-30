
#include <string>
#include <iostream>
using namespace std;

class Node
{
private:
    string nid; // ID for every Node we create
    string label;
    string color;

public:
    //Default Constructor
    Node()
    {
        nid = "0000";
        label = "empty";
    }
    //Overloaded Constructor
    Node(string _nid, string _label)
    {
       nid = _nid;
       label = _label;
    }
    void getNode();
    void setNode(string, string);

};

// Member functions definitions
void Node::getNode()
{
    cout << nid << " [label=" << label << "]\n";
}
void Node::setNode(string id, string lab)
{
    nid = id;
    label = lab;
}