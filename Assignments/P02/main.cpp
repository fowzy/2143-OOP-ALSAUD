/*
    Author      :       Fowzy Alsaud
    Assignment  :       P02 - Graphviz Class
    Professor   :       Dr. Griffen
    Date        :       March, 24th, 2021
    Class       :       OOP 2143 - MSUTexas
    Description :       
    How to Run  :       Simply we provide a simple example 
*/
#include <iostream>
#include <fstream>
#include <vector>
//#include "Node.h"
//#include "Edge.h"

using namespace std;

// Main Function
int main()
{
    vector<string> node;
    ifstream openFile("input.txt");
    //int nid;
    string state;
    string team;
    while (openFile >> state >> team)
    {
        node.push_back(state);
        node.push_back(team);
        //cout << state << " = > " << team << endl;
    }
    for (int i = 0; i <= node.size(); i++)
    {
        cout << i << ", "<< node[i] << endl;
    }

    return 0;
}