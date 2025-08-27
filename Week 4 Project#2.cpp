#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

// Build substitution alphabet from keyword
string buildCipherAlphabet(const string& keyword) {
    string key = "";
    for (char c : keyword) {
        c = toupper(c);
        if (key.find(c) == string::npos) key += c; // remove duplicates
    }

    string alphabet = key;
    for (char c = 'Z'; c >= 'A'; c--) {
        if (alphabet.find(c) == string::npos) alphabet += c;
    }
    return alphabet;
}

// Encrypt text using cipher
string encrypt(const string& text, const string& cipher) {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            bool isLower = islower(c);
            char mapped = cipher[alphabet.find(toupper(c))];
            result += isLower ? tolower(mapped) : mapped;
        } else {
            result += c; // keep spaces, punctuation
        }
    }
    return result;
}

// Decrypt text using cipher
string decrypt(const string& text, const string& cipher) {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string result = "";
    for (char c : text) {
        if (isalpha(c)) {
            bool isLower = islower(c);
            char mapped = alphabet[cipher.find(toupper(c))];
            result += isLower ? tolower(mapped) : mapped;
        } else {
            result += c;
        }
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "Usage: crypt <-e|-d> -kKEYWORD input.txt output.txt\n";
        return 1;
    }

    string mode = argv[1]; // -e or -d
    string keyword = argv[2];
    if (keyword.rfind("-k", 0) != 0) {
        cerr << "Error: Must supply keyword with -k\n";
        return 1;
    }
    keyword = keyword.substr(2);

    ifstream inFile(argv[3]);
    ofstream outFile(argv[4]);

    if (!inFile || !outFile) {
        cerr << "Error: Cannot open input or output file.\n";
        return 1;
    }

    string cipher = buildCipherAlphabet(keyword);
    string line;
    while (getline(inFile, line)) {
        if (mode == "-e")
            outFile << encrypt(line, cipher) << endl;
        else if (mode == "-d")
            outFile << decrypt(line, cipher) << endl;
        else {
            cerr << "Invalid mode. Use -e for encrypt or -d for decrypt.\n";
            return 1;
        }
    }

    return 0;
}
