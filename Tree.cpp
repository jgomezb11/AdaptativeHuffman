#include "Tree.h"
#include <map>

Tree::Tree(Node head){
    this->head = head;
}

Tree::~Tree() { }

Node Tree::getHead(){
    return this->head;
}

Node Tree::searchNode(Node leaf, std::map<char,bool>& visited, Node &currNode, int weight){
    if(visited.find(leaf->getCurrent()->getChar()) != visited.end()) return currNode;
    if(!leaf->getLeft() && !leaf->getRight()){
        visited[leaf->getCurrent()->getChar()] = true;
        if(leaf->getCurrent()->getWeight() < weight){
            currNode = leaf;
        }
        if(leaf->getFather()->getFather()){
            searchNode(leaf->getFather()->getFather()->getRight(), visited, currNode, weight);
        }else{
            return currNode;
        }
    }
    if(leaf->getLeft() && leaf->getRight()) searchNode(leaf->getRight(), visited, currNode, weight);
}

bool Tree::searchSymbol(char symbol, Node head,char newSymbol, int id){
    if(head == nullptr) {
        return false;
    }
    if(head->getCurrent()->getChar() == symbol){
        if(symbol == '\0'){
            Node character = new Nodo(new Parameters(1, newSymbol, id));
            Parameter counter = new Parameters(1);
            head->setCurrent(counter);
            head->setRight(character);
            head->setLeft(new Nodo(new Parameters(0, '\0', 107)));
            head->getLeft()->setFather(head);
            head->getRight()->setFather(head);
            return true;
        }else{
            int weight = head->getCurrent()->getWeight() + 1;
            head->getCurrent()->setWeight(weight);
            if(head->getFather()->getFather()){
                if(head->getFather()->getFather()->getRight()->getCurrent()->getWeight() < head->getCurrent()->getWeight()){
                    std::map<char,bool> visited;
                    Node swapNode;
                    searchNode(head->getFather()->getFather()->getRight(), visited, swapNode, head->getCurrent()->getWeight());
                    Node newHead = head->getFather();
                    Node newSwapNode = swapNode;
                    swapNode->getFather()->setRight(newHead);
                    head->getFather()->getFather()->setLeft(newSwapNode);
                }
            }
            return true;
        }
    }
    bool left = searchSymbol(symbol, head->getLeft(), newSymbol, id);
    if(left) return true;
    bool right = searchSymbol(symbol, head->getRight(), newSymbol, id);
    return right;
}

void Tree::printTree(Node head){
    if(!head) return;
    printTree(head->getLeft());
    if(head->getCurrent()->getChar() == -1){
        std::cout << "[,";
        std::cout << head->getCurrent()->getWeight() << ",]";
    }else if(head->getCurrent()->getChar() == '\0') {
        std::cout << "[NYT,," << head->getCurrent()->getId() << "]";
    }else{
        std::cout << "[" << head->getCurrent()->getChar() << "," << head->getCurrent()->getWeight() << "," << head->getCurrent()->getId() << "]";
    }
    std::cout << std::endl;
    printTree(head->getRight());
}

void Tree::sumWeights(Node head){
    if(head == nullptr) {
        return;
    }
    int weight = 0;
    if(!head->getLeft() && !head->getRight())
        weight = head->getCurrent()->getWeight();
    sumWeights(head->getLeft());
    if(head->getLeft()){
        weight += head->getLeft()->getCurrent()->getWeight();
    }
    sumWeights(head->getRight());
    if(head->getRight()){
        weight += head->getRight()->getCurrent()->getWeight();
    }
    head->getCurrent()->setWeight(weight);
}

void Tree::addNode(char symbol, int &id){
    if(!searchSymbol(symbol, this->head, symbol, id)){
        id -= 1;
        searchSymbol('\0',this->head, symbol, id);
    }
    sumWeights(this->head);
}
