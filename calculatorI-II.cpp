#include <iostream>

using namespace std;

int roman_to_integer(string rstr) {
    int n = int(rstr.length());
    if (0 == n) {
        return 0;
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        switch (rstr[i]) {
            case 'I':
                result += 1;
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                result += 10;
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                result += 100;
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
            // default:
            //     cout << "Invalid Number" << endl;
            //     return 0;
                
            }
        }

        for (int i = 1; i < n; i++) {
            if ((rstr[i] == 'V' || rstr[i] == 'X') && rstr[i - 1] == 'I') {
                result -= 1 + 1;
            }

            if ((rstr[i] == 'L' || rstr[i] == 'C') && rstr[i - 1] == 'X') {
                result -= 10 + 10;
            }

            if ((rstr[i] == 'D' || rstr[i] == 'M') && rstr[i - 1] == 'C') {
                result -= 100 + 100;
            }
        }

        return result;
    }
    
    
string integer_to_Roman(int n) {

    string str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string result = "";

    for ( int i = 0; i < 13; ++i){

        while(n - values[i] >= 0){
            result += str_romans[i];
            n -= values[i];
        }
    }

    return result;
}


int main(){

    string op;
    string romanNumber;

    cout<<"Enter Roman Number: ";
    cin>>romanNumber;

    int result = roman_to_integer(romanNumber);
    
    while(true) {
        string num;
        cout<<"enter operator: ";
        cin>>op;


        if (op == "exit"){
            break;
        }
        
        else{
            cout << "Enter Roman Number: ";
            cin >> num;
            
            if (op=="+") {

                result=result+roman_to_integer(num);
            } 
            
            else if (op=="-"){

                result=result-roman_to_integer(num);
            }
            
            else if (op=="*") {

                result=result*roman_to_integer(num);
            }
            
            else if(op=="/") {

                result=result/roman_to_integer(num);
            }
            
            else {
                cout << "error";
            }
        }
    }

    cout << integer_to_Roman(result) << endl;
    

    return 0;
}