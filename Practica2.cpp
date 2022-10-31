#include <iostream>
#include <vector>
//#include <locale.h>

using namespace std;

vector<char> alphabet;
string specialChars = "áéíóúÁÉÍÓÚñÑ";

bool validateRestOfChars(char actual){
    for(char possible : specialChars){
        if(possible == actual) return true;
    }
    return false;
}

void llenarArr(){
    string actualChar;
    cin >> actualChar;
    for(char c: actualChar){
        if((c >= 32 && c <= 127) || (validateRestOfChars(c)))
            alphabet.push_back(c);
    }
}

int main()
{
    //setlocale(LC_CTYPE, "spanish");
    // cout << specialChars;
    llenarArr();
    for(char a : alphabet){
        cout << s << endl;
    }
    return 0;
}
