#include <iostream>
#include <string>

using namespace std;

int main() {
    string input, divisor;

    cout << "Enter Data (in binary): ";
    cin >> input;

    cout << "Enter Divisor (in binary): ";
    cin >> divisor;

    int inputLength = input.length();
    int divisorLength = divisor.length();

    // Append zeros to the input data (equal to divisor length minus 1)
    input += string(divisorLength - 1, '0');

    // Perform CRC division
    for (int i = 0; i < inputLength; ++i) {
        if (input[i] == '1') {
                     
            for (int j = 0; j < divisorLength; ++j) {
                input[i + j] = (input[i + j] == divisor[j]) ? '0' : '1';
            }
        }
    }

    // Extract the CRC code (remainder)
    string crcCode = input.substr(inputLength, divisorLength - 1);
    cout << "Generated CRC Code: " << crcCode << endl;

    return 0;
}
