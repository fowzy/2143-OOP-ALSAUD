class Node
{
private:
    int nid; // ID for every Node we create
    string label;
    string color;

public:
    //Default Constructor
    Node()
    {
        nid = 0;
        label = "empty";
        color = "while";
    }
    //Overloaded Constructor
    Node(int _nid, string _label)
    {
       nid = _nid;
       label = _label;
    }
    void getNode();
    void setNode();

};
// Member functions definitions
void Node::getNode()
{
}
void Node::setNode()
{
}