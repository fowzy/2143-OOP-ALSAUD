class Edge{
    private:
        string firstEdge;
        string secondEdge;
        string label;
    public:
    //Default Constructor
    Edge()
    {
        firstEdge = "NULL";
        secondEdge = "NULL";
        label = "NULL";
    }
    //Overloaded Constructor
    Edge(string _firstEdge, string _secondEdge, string _label)
    {
       firstEdge = _firstEdge;
       secondEdge = _secondEdge;       
       label = _label;

    }
    void getEdges();
    void setEdges(string, string, string);    
};

// Member functions definitions
void Edge::getEdges()
{
    cout << firstEdge << " -> " << label << " [ label=" << "]" << endl;
}
void Edge::setEdges(string frst, string scnd, string lbl)
{
    firstEdge = frst;
    secondEdge = scnd;
    label = lbl;
}