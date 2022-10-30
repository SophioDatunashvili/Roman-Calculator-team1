#include <iostream>

using namespace std;
//ფუნქცია ანიჭებს რომაულ რიცხვებს არაბულ მნიშვნელობას
int arabicValue(char roman) 
{
    switch(roman) 
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}

// ფუნქციას გადაჰყავს რომაული რიცხვები არაბულში
int romanToInt(string romanNumber)
{
    int arabic = 0;
    int previousNum = 0;
    int n = romanNumber.length()-1;

    for (int i = n; i >= 0; i--)
    {
        if (arabicValue(romanNumber[i]) >= previousNum) {
             arabic = arabic + arabicValue(romanNumber[i]);
        } else {
            arabic = arabic - arabicValue(romanNumber[i]);
        }

        previousNum = arabicValue(romanNumber[i]);   

    }
    return arabic;
}

 //ამ ფუნქციით მომხმარებელს შემოაქვს რომაული რიცხვები და საბოლოოდ ითვლის მათემატიკური ოპერაციების შედეგს   
int calculator(string num, int result, string operators) {

    cout << "Enter Roman Number: ";
    cin >> num;
            
    if (operators=="+") {
        result=result+romanToInt(num);
    } else if (operators=="-"){
        result=result-romanToInt(num);
    } else if (operators=="*") {
        result=result*romanToInt(num);
    } else if(operators=="/") {
        result=result/romanToInt(num);
    } else {
        cout << "invalid operator"<<endl;
    }
    return result;
}

 // ფუნქციას გადაჰყავს არაბული რიცხვები რომაულში   
string intToRoman(int arabic) {
    if (arabic < 0) {
        arabic = -arabic;
        cout << "-";
    }

    string romanChars[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int arabicValues[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string roman = "";

    for ( int i = 0; i < 13; i++){

        while (arabic - arabicValues[i] >= 0){
            roman = roman + romanChars[i];
            arabic = arabic- arabicValues[i];
        }
    }

    return roman;
}


int main(){

    string operators;
    string romanNumber;

    cout<<"Enter Roman Number: ";
    cin>>romanNumber;

    int result = romanToInt(romanNumber);
    
    while(true) {
        string num;
        cout<<"enter operator: ";
        cin>>operators;
    
        if (operators == "exit"){
            break;
        } else{
             result = calculator(num, result, operators);
        }
    }
    cout << intToRoman(result) << endl;

    return 0;
}           