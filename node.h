class Nodo {
private:
  int weight;
  char symbol;
  int id;

public:
  Nodo(int weight, char symbol, int id);

  ~Nodo();

  int getWeight();

  char getChar();

  int getId();

  void setWeight(int weight);

  void setSymbol(char symbol);

  void setId(int id);
};
