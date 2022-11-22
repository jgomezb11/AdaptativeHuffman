#include "Tree.h"
#include <vector>
#include <fstream>
#include <thread>
#include <string>
#include <sstream>
#include <bitset>

using namespace std;

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

bool checkCharacter(char c) {
    if (!((c >= 32 && c <= 127) || validateRestOfChars(c))){
        return false;
    }
    return true;
}

vector<string> getParameters(string line) {
    string name = "";
    string threads = "";
    for(int i = 0; i < line.size(); i++) {
        if (line[i] == ' '){
            name = line.substr(0, i);
            threads = line.substr(i + 1);
        }
    }
    return {name, threads};
}

void openFile(string filename, int position, int idThread, int limit) {
    char lines[limit + 1];
    lines[limit] = '\0';
    ifstream file;
    file.open(filename, ios::in | ios::binary);
    if(file.fail()) {
        cout << "No se encontro archivo en esta carpeta";
        exit(1);
    }
    file.seekg(position, ios::beg);
    file.read(lines, limit);
    for(int i = filename.size() - 1; i > 0; i--){
        if(filename[i] == '.'){
            filename = filename.substr(0, i) + to_string(idThread) + ".txt";
            break;
        }
    }
    file.close();
    ofstream outputFile(filename);
    string listOfSymbols = "";
    tree = new Tree(new Nodo(new Parameters(0, '\0', id)));
    for(int i = 0; i < limit; i++) {
        if(checkCharacter(lines[i])){
            listOfSymbols += tree->addNode(lines[i], id);
        }else{
            cout << "Error con caracter " << lines[i] << endl;
            exit(1);
        }
    }
    if(listOfSymbols.size() % 8 != 0){
        string restOfBytes ((8 - (listOfSymbols.size() % 8)), '0');
        listOfSymbols += restOfBytes;
    }
    stringstream sstream(listOfSymbols);
    string output;
    while(sstream.good())
    {
        bitset<8> bits;
        sstream >> bits;
        char c = char(bits.to_ulong());
        output += c;
    }
    outputFile << output;
    outputFile.close();
}

int getFileSize(string nameFile){
    ifstream file(nameFile, ios::in | ios::binary);
    if(file.fail()) {
        cout << "No se encontro archivo en esta carpeta";
        exit(1);
    }
    file.seekg(0, ios::end);
    int bytes = file.tellg();
    file.close();
    return bytes;
}

int main() {
    string line;
    getline(cin, line);
    vector<string> values = getParameters(line);
    int threads = stoi(values[1]);
    int fileSize = getFileSize(values[0]);
    int position = 0;
    int id = 1;
    int limit = (fileSize/threads);
    vector<thread> ThreadVector;
    for(int i = 0; i < threads; i++) {
        if (i == threads - 1 && (position + limit) < fileSize) {
            limit = fileSize - position;
        }
        ThreadVector.push_back(thread(openFile, values[0], position, id, limit));
        position += limit;
        id += 1;
    }
    for(auto& t: ThreadVector) {
        t.join();
    }
    return 0;
}
