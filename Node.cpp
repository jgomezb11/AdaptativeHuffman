#include "Node.h"

Nodo::Nodo(Parameter current){
    this->current = current;
    this->left = nullptr;
    this->right = nullptr;
    this->father = nullptr;
}

Nodo::~Nodo() { }

Parameter Nodo::getCurrent() {
    return this->current;
}

Nodo* Nodo::getLeft(){
    return this->left;
}

Nodo* Nodo::getRight(){
    return this->right;
}

Nodo* Nodo::getFather(){
    return this->father;
}

void Nodo::setCurrent(Parameter current){
    this->current = current;
}

void Nodo::setLeft(Nodo* left){
    this->left = left;
}

void Nodo::setRight(Nodo* right){
    this->right = right;
}

void Nodo::setFather(Nodo *father){
    this->father = father;
}
