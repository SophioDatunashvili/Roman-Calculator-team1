#include <iostream>
#include <vector>
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

        for ( int i = 0; i < 13; ++i)
        {
            while(n - values[i] >= 0)
            {
                result += str_romans[i];
                n -= values[i];
            }
        }

        return result;
    }

        
int main()
{
    string num;
    string op;
    
    vector <string> romNum;
    vector <string> operations;

    while(op !="Exit") {
        
        cout<<"enter roman number: ";
        cin>>num;
        romNum.push_back(num);
        
        cout<<"enter operator: ";
        cin>>op;
        operations.push_back(op);
        
    }
    
    vector <int> arabNum;
    
    for (int i=0; i< romNum.size(); i++) {
        int number=roman_to_integer(romNum[i]);
        arabNum.push_back(number);
    }
    
    
    
    int result=arabNum[0];
    
    for (int i=0; i < operations.size()-1; i++) {
        
        if (operations[i]=="+") {
            result=result + arabNum[i+1];
            cout<<"mimatebaze "<<result<< " "<<endl;
        }else if (operations[i]=="-") {
            result=result - arabNum[i+1];
            cout<<"gamoklebaze "<<result<<endl;
        }else if (operations[i]=="*") {
            result=result * arabNum[i+1];
            cout<<"gamravlebaze "<<result<<endl;
        }else if (operations[i]=="/") {
            result = result/arabNum[i+1];
            cout<<"gakofaze "<<result<<endl;       
        } else{
            cout<<"Invalid Operation";
        }
    }
    cout<<"result is "<<integer_to_Roman(result);
   

    return 0;
}