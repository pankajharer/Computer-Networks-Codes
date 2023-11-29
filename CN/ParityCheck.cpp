#include <iostream>
#include <string>
using namespace std;

bool isOddParity(const std::string& binaryString) {
    int countOnes = 0;

    for (size_t i = 0; i < binaryString.length(); ++i) {
        if (binaryString[i] == '1') {
            countOnes++;
        }
    }
    return (countOnes % 2 != 0);
    
}

int main() {
    string binaryNumber;
    cout << "Enter a binary number: ";
    cin >> binaryNumber;

    for (size_t i = 0; i < binaryNumber.length(); ++i)
	 {
        if (binaryNumber[i] != '0' && binaryNumber[i] != '1') {
            cout << "Invalid binary number entered." << endl;
            return 1; 
        }
    }

    if (isOddParity(binaryNumber)) {
        cout << "The binary number has odd parity." << endl;
    } else {
        cout << "The binary number has even parity." << endl;
    }

    return 0;
}
