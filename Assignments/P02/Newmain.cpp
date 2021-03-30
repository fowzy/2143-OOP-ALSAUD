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
#include <string>
#include "Node.h"
//#include "Edge.h"

using namespace std;

// Main Function
int main()
{
    // Creating an object for Node class
    Node N;
    // Storing nodes into a vectors
    vector<string> vecNodes;
    // ifstream to open our data file
    ifstream openFile("newInput.txt");
    // ofstream outputFile("output.txt");
    string nid, node;
    // While loop to read our data file
    while (openFile >> nid >> node)
    {
        for (int i = 0; i <= vecNodes.size(); i++)
        {
            N.setNode(nid, vecNodes[i]);
        }
        // Then push data into vectors
        vecNodes.push_back(nid);
        vecNodes.push_back(node);
    }
    // for loop to set Node ID and Node Data
    for (int i = 0; i <= vecNodes.size(); i++)
    {
        // Print out our vector
        N.getNode();
    }
    // Close ifstream and ofstream
    openFile.close();
    //outputFile.close();

    return 0;
}