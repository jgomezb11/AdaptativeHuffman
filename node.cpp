#include "node.h"

Nodo::Nodo(int weight, char symbol, int id) {
  this->weight = weight;
  this->symbol = symbol;
  this->id = id;
}

Nodo::~Nodo(){ }

int Nodo::getWeight() { return this->weight; }

char Nodo::getChar() { return this->symbol; }

int Nodo::getId() { return this->id; }

void Nodo::setWeight(int weight) { this->weight = weight; }

void Nodo::setSymbol(char symbol) { this->symbol = symbol; }

void Nodo::setId(int id) { this->id = id; }
