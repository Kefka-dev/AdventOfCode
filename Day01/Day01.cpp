#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int numberFromFirstAndLastDigit(vector<int>& inputVector){
    int TheNumber;
    if(inputVector.size() == 0){
        TheNumber = 0;
    } else {
        TheNumber = inputVector.front() *10 + inputVector.back();
    }

    return TheNumber;
}
//converts character to digit
int intFromChar(char c){
    int number;
    number = c - '0';
    return number;
}

int main(){

    ifstream file("input.txt");
    stringstream ss;
    string fileLine;
    vector<int> numbersFromLine;
    
    char c;
    int number, sum{0};
    while (getline(file, fileLine))
    {
        cout << fileLine << "\n";

        //searches through the line and if there is a number it stores it in a vector
        for (char znak : fileLine)
        {
            if (isdigit(znak) != 0)
            {
                number = intFromChar(znak);
                numbersFromLine.push_back(number);
            }
        }

        sum = sum + numberFromFirstAndLastDigit(numbersFromLine);
        cout << sum<<"\n";
        numbersFromLine.clear();
    }
    
    
    file.close();
    return 0;
}