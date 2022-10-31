#include "node.cpp"
#include <iostream>
#include <vector>

using namespace std;

vector<char> alphabet;
string specialChars = "áéíóúÁÉÍÓÚñÑ";

bool validateRestOfChars(char actual) {
  for (char possible : specialChars) {
    if (possible == actual)
      return true;
  }
  return false;
}

void llenarArr() {
  string actualChar;
  cin >> actualChar;
  for (char c : actualChar) {
    if ((c >= 32 && c <= 127) || (validateRestOfChars(c)))
      alphabet.push_back(c);
  }
}

int main() {
  Nodo *arbol = new Nodo(2, 'b', 107);
  cout << arbol->getChar() << endl;
  llenarArr();
  for (char a : alphabet) {
    cout << a << endl;
  }
  return 0;
}
