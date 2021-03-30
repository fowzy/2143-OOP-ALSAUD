/*
    Author      :       Fowzy Alsaud & Paxton Proctor
    Assignment  :       P02 - Graphviz Class
    Professor   :       Dr. Griffen
    Date        :       March, 24th, 2021
    Class       :       OOP 2143 - MSUTexas
    Description :       Program to make Graphviz code for you :D
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include "Node.h"
#include "Edge.h"

using namespace std;

// Functions Prototype
// void runApp();
// void readFile();
void showEdges(vector<Edge> &);
void showVec(vector<Node> &); // Show vectors functions
void createVec(ifstream &);   // Create vectors functions

// Main Function
int main()
{
    // string inputFile;
    // creating vector for Nodes and Edges
    // ifstream to open our data file
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    // cout << "Enter the input file: ";
    // cin >> inputFile;
    createVec(inputFile);

    // Close ifstream and ofstream
    inputFile.close();
    outputFile.close();

    return 0;
}

// function will show you all vectors and print it out for you
void showVec(vector<Node> &vecNodes)
{
    // for loop to read Node ID and Node Data
    for (int i = 0; i <= vecNodes.size(); i++)
    {
        vecNodes[i].getNode();
        //cout << vecNodes[i].getNode() << endl;
    }
}

void showEdges(vector<Edge> &vecEdges)
{
    // for loop to read Edge class
    for (int i = 0; i <= vecEdges.size(); i++)
    {
        vecEdges[i].getEdges();
    }
}

// function will create vectors for our Node and Edges
void createVec(ifstream &openFile)
{
    vector<Node> vecNodes;
    vector<Edge> vecEdges;

    string element;
    // While loop to read our data file
    while (openFile >> element)
    {
        if (element == "74")
        {
            string nid, node;
            while (openFile >> nid >> node)
            {
                if (nid != "50")
                {
                    Node newNode(nid, node);
                    // Then push data into vectors
                    vecNodes.push_back(newNode);
                }
                else
                    break;
            }
            showVec(vecNodes);
        }
    }
}