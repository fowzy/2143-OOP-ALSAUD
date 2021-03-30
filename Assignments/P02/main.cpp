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
// #include "Edge.h"

using namespace std;

// Main Function
int main()
{
    // Creating an object for Node class
    Node N;
    // Storing nodes into a vectors
    vector<string> node;
    // ifstream to open our data file
    ifstream openFile("input.txt");
    // ofstream outputFile("output.txt");
    string state, team;
    // While loop to read our data file
    while (openFile >> state >> team)
    {
        // Then push data into vectors
        N.setNode(state, team);
        node.push_back(state);
        node.push_back(team);
    }
    // for loop to set Node ID and Node Data
    for (int i = 0; i <= node.size(); i++)
    {
        N.setNode(to_string(i), node[i]);
        // Print out our vector
        N.getNode();
    }
    // Close ifstream and ofstream
    openFile.close();
    //outputFile.close();

    return 0;
}