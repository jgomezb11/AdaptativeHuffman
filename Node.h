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

  Nodo* getFather();

  Nodo* getRight();

  void setCurrent(Parameter current);

  void setLeft(Nodo* left);

  void setFather(Nodo* right);

  void setRight(Nodo* right);
};
