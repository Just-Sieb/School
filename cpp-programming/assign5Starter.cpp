#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<char> normalV(26);
    vector<char> cipherV(26);
    string toDec = "";
    string beenDec = "";
    
    normalV.at(0) = 'n'; cipherV.at(0) = '{';
    
    // Get secret message
    do {
        cout << "Enter a secret message: ";
        getline(cin, toDec);
    } while (toDec.length() == 0);

    beenDec = toDec;

    // Decrypt secret message
    if (toDec.at(0) == cipherV.at(0)) {
        beenDec.at(0) = normalV.at(0);
    }
    
    cout << "Decrypted message: " << beenDec << endl;
    
    return 0;
}
