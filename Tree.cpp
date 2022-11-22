#include "Tree.h"

std::map<int,std::string> encryptCode = {
        {32,"0000000"},{33,"0000001"},{34,"0000010"},{35,"0000011"},
        {36,"0000100"},{37,"0000101"},{38,"0000110"},{39,"0000111"},
        {40,"0001000"},{41,"0001001"},{42,"0001010"},{43,"0001011"},
        {44,"0001100"},{45,"0001101"},{46,"0001110"},{47,"0001111"},
        {48,"0010000"},{49,"0010001"},{50,"0010010"},{51,"0010011"},
        {52,"0010100"},{53,"0010101"},{54,"0010110"},{55,"0010111"},
        {56,"0011000"},{57,"0011001"},{58,"0011010"},{59,"0011011"},
        {60,"0011100"},{61,"0011101"},{62,"0011110"},{63,"0011111"},
        {64,"0100000"},{65,"0100001"},{66,"0100010"},{67,"0100011"},
        {68,"0100100"},{69,"0100101"},{70,"0100110"},{71,"0100111"},
        {72,"0101000"},{73,"0101001"},{74,"0101010"},{75,"0101011"},
        {76,"0101100"},{77,"0101101"},{78,"0101110"},{79,"0101111"},
        {80,"0110000"},{81,"0110001"},{82,"0110010"},{83,"0110011"},
        {84,"0110100"},{85,"0110101"},{86,"0110110"},{87,"0110111"},
        {88,"0111000"},{89,"0111001"},{90,"0111010"},{91,"0111011"},
        {92,"0111100"},{93,"0111101"},{94,"0111110"},{95,"0111111"},
        {96,"1000000"},{97,"1000001"},{98,"1000010"},{99,"1000011"},
        {100,"1000100"},{101,"1000101"},{102,"1000110"},{103,"1000111"},
        {104,"1001000"},{105,"1001001"},{106,"1001010"},{107,"1001011"},
        {108,"1001100"},{109,"1001101"},{110,"1001110"},{111,"1001111"},
        {112,"1010000"},{113,"1010001"},{114,"1010010"},{115,"1010011"},
        {116,"1010100"},{117,"101010"},{118,"101011"},{119,"101100"},
        {120,"101101"},{121,"101110"},{122,"101111"},{123,"110000"},
        {124,"110001"},{125,"110010"},{126,"110011"},{-75,"110100"},
        {-112,"110101"},{-42,"110110"},{-32,"110111"},{-23,"111000"},
        {-91,"111001"},{-96,"111010"},{-126,"111011"},{-95,"111100"},
        {-94,"111101"},{-93,"111110"},{-92,"111111"}
};

Tree::Tree(Node root){
    this->root = root;
}

Tree::~Tree() { }

Node Tree::getRoot(){
    return this->root;
}

Node Tree::searchNode(Node leaf, std::map<char,bool>& visited, Node &currNode, int weight){
    if(visited.find(leaf->getCurrent()->getSymbol()) != visited.end()) return currNode;
    if(!leaf->getLeft() && !leaf->getRight()){
        visited[leaf->getCurrent()->getSymbol()] = true;
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

std::pair<bool ,std::string> Tree::searchSymbol(char symbol, Node root,char newSymbol, int id, std::string path){
    if(root == nullptr) {
        return std::pair<bool ,std::string>(false, path);
    }
    if(root->getCurrent()->getSymbol() == symbol){
        if(symbol == '\0'){
            Node character = new Nodo(new Parameters(1, newSymbol, id));
            Parameter counter = new Parameters(1);
            root->setCurrent(counter);
            root->setRight(character);
            root->setLeft(new Nodo(new Parameters(0, '\0', 107)));
            root->getLeft()->setFather(root);
            root->getRight()->setFather(root);
            return std::pair<bool ,std::string>(true, path);
        }else{
            int weight = root->getCurrent()->getWeight() + 1;
            root->getCurrent()->setWeight(weight);
            if(root->getFather()->getFather()){
                if(root->getFather()->getFather()->getRight()->getCurrent()->getWeight() < root->getCurrent()->getWeight()){
                    std::map<char,bool> visited;
                    Node swapNode;
                    searchNode(root->getFather()->getFather()->getRight(), visited, swapNode, root->getCurrent()->getWeight());
                    Node newRoot = root->getFather();
                    Node newSwapNode = swapNode;
                    swapNode->getFather()->setRight(newRoot);
                    root->getFather()->getFather()->setLeft(newSwapNode);
                }
            }
            return std::pair<bool ,std::string>(true, path);
        }
    }
    std::pair<bool ,std::string> left = searchSymbol(symbol, root->getLeft(), newSymbol, id, path+"0");
    if(left.first) return left;
    std::pair<bool ,std::string> right = searchSymbol(symbol, root->getRight(), newSymbol, id, path+"1");
    return right;
}

void Tree::printTree(Node root){
    if(!root) return;
    printTree(root->getLeft());
    if(root->getCurrent()->getSymbol() == -1){
        std::cout << "[,";
        std::cout << root->getCurrent()->getWeight() << ",]";
    }else if(root->getCurrent()->getSymbol() == '\0') {
        std::cout << "[NYT,," << root->getCurrent()->getId() << "]";
    }else{
        std::cout << "[" << root->getCurrent()->getSymbol() << "," << root->getCurrent()->getWeight() << "," << root->getCurrent()->getId() << "]";
    }
    std::cout << std::endl;
    printTree(root->getRight());
}

void Tree::sumWeights(Node root){
    if(root == nullptr) {
        return;
    }
    int weight = 0;
    if(!root->getLeft() && !root->getRight())
        weight = root->getCurrent()->getWeight();
    sumWeights(root->getLeft());
    if(root->getLeft()){
        weight += root->getLeft()->getCurrent()->getWeight();
    }
    sumWeights(root->getRight());
    if(root->getRight()){
        weight += root->getRight()->getCurrent()->getWeight();
    }
    root->getCurrent()->setWeight(weight);
}

std::string Tree::addNode(char symbol, int &id){
    std::string code = encryptCode[symbol];
    std::string position = "";
    std::pair<bool ,std::string> found = searchSymbol(symbol, getRoot(), symbol, id, "");
    if(!found.first) {
        id -= 1;
        position = searchSymbol('\0',getRoot(), symbol, id, "").second;
    }else{
        position = found.second;
    }
    sumWeights(getRoot());
    return found.first ? position: position + code;
}
