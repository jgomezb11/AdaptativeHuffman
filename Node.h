#include "Parameters.h"

typedef Parameters* Parameter;

class Nodo {
private:
  Parameter current;
  Nodo* left;
  Nodo* father;
  Nodo* right;

public:
  Nodo(Parameter current);

  ~Nodo();

  Parameter getCurrent();

  Nodo* getLeft();

  Nodo* getRight();

  Nodo* getFather();

  void setCurrent(Parameter current);

  void setLeft(Nodo* left);

  void setRight(Nodo* right);

  void setFather(Nodo* right);
};
