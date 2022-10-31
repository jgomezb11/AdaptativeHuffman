#include "node.h"

typedef Nodo* Node;

class Tree{
private:
  Node left;
  Node right;
  
public:
  Tree(Node left, Node right);
  ~Tree();
  void addNode(Node nodo);
  
}
