
using namespace std;
class Node
{
private:
    string nid; // ID for every Node we create
    string label; // var. to store label

public:
    //Default Constructor
    Node()
    {
        nid = "NULL";
        label = "NULL";
    }
    //Overloaded Constructor
    Node(string _nid, string _label)
    {
       nid = _nid;
       label = _label;
    }
    void getNode(); // this function to get a  
    void setNode(string, string);

};

// Member functions definitions
void Node::getNode()
{
    cout << nid << " [label=" << label << "]\n";
}

void Node::setNode(string id, string nlab)
{
    nid = id;
    label = nlab;
}