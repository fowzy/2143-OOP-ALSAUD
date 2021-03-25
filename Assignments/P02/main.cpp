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
#include "Node.h"
#include "Edge.h"

using namespace std;

// Main Function
int main()
{
    int nid;
    string state;
    string team;
    fstream openfile("input.txt");
    while (!openfile.eof())
    {

        nid >> state >> team;
    }
    Node N;

    return 0;
}
