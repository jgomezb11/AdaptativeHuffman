class Parameters {
private:
    int weight;
    char symbol;
    int id;

public:
    Parameters(int weight,  char symbol, int id);

    Parameters(int weight);

    ~Parameters();

    int getWeight();

    char getSymbol();

    int getId();

    void setWeight(int weight);
};
