#include "Parameters.h"

Parameters::Parameters(int weight, char symbol, int id) {
    this->weight = weight;
    this->symbol = symbol;
    this->id = id;
}

Parameters::Parameters(int weight) {
    this->weight = weight;
    this->symbol = -1;
    this->id = -1;
}

Parameters::~Parameters() { }

int Parameters::getWeight() { return this->weight; }

char Parameters::getChar() { return this->symbol; }

int Parameters::getId() { return this->id; }

void Parameters::setWeight(int weight) { this->weight = weight; }
