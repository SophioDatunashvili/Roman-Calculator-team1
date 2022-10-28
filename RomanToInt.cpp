#include <iostream>

using namespace std;

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



int romanToInt(string romanNumber)
{
    int arabic=0;
    int previousNum=0;
    int n=romanNumber.length()-1;
    
    for (int i=n; i>=0; i--)
    {
        if(arabicValue(romanNumber[i])>= previousNum)
        {
            arabic=arabic + arabicValue(romanNumber[i]);
        } else {
            arabic=arabic - arabicValue(romanNumber[i]);
        }
        
        previousNum = arabicValue(romanNumber[i]);   
        
    }
    return arabic;
}
