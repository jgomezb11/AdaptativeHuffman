#include "Node.h"
#include <map>
#include <iostream>

typedef Nodo* Node;

class Tree{
private:
    Node root;

public:
    Tree(Node root);

    ~Tree();

    Node getRoot();

    Node searchNode(Node leaf, std::map<char,bool>& visited, Node &currNode, int weight);

    std::pair<bool ,std::string> searchSymbol(char symbol, Node root, char newSymbol, int id, std::string path);

    void printTree(Node root);

    void sumWeights(Node root);

    std::string addNode(char symbol, int &id);
};
