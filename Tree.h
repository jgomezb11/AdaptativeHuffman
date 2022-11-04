#include "Node.h"
#include <map>
#include <iostream>

typedef Nodo* Node;

class Tree{
private:
    Node head;

public:
    Tree(Node head);

    ~Tree();

    Node getHead();

    Node searchNode(Node leaf, std::map<char,bool>& visited, Node &currNode, int weight);

    bool searchSymbol(char symbol, Node head, char newSymbol, int id);

    void printTree(Node head);

    void sumWeights(Node head);

    void addNode(char symbol, int &id);
};
