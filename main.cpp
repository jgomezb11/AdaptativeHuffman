#include "Tree.h"
#include <iostream>
#include <vector>
#include <conio.h>

using namespace std;

vector<char> alphabet;
vector<char> specialChars = {-96, -126, -95, -94, -93, -92, -75, -112, -42, -32, -23, -91};
int id = 107;
Tree *tree;

bool validateRestOfChars(char actual) {
    for (char possible : specialChars) {
        if (actual == possible)
            return true;
    }
    return false;
}

void getInput() {
    string actualChar;
    getline(cin,actualChar);
    for (char c : actualChar) {
        if ((c >= 32 && c <= 127) || validateRestOfChars(c)){
            alphabet.push_back(c);
        }else{
            cout << "Error con caracter " << c << endl;
            getch();
            exit(1);
        }
    }
}

int main() {
    tree = new Tree(new Nodo(new Parameters(0, '\0', id)));
    getInput();
    for(char c:alphabet){
        tree->addNode(c, id);
    }
    tree->printTree(tree->getHead());
    getch();
    return 0;
}
