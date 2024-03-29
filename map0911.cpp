#include <iostream>
#include <map>
using namespace std;

// Функция для перевода римской цифры в арабскую
int romanToArabic(string roman)
{
    map<char, int> romanMap;
    romanMap['I'] = 1;
    romanMap['V'] = 5;
    romanMap['X'] = 10;
    romanMap['L'] = 50;
    romanMap['C'] = 100;
    romanMap['D'] = 500;
    romanMap['M'] = 1000;
    
    int result = 0;
    int prevValue = 0;
    
    for (int i = roman.length() - 1; i >= 0; i--) {
        int currentValue = romanMap[roman[i]];
        
        if (currentValue < prevValue) {
            result -= currentValue;
        } else {
            result += currentValue;
        }

        prevValue = currentValue;
    }
    
    return result;
}

// Функция для перевода арабской цифры в римскую
string arabicToRoman(int arabic)
{
    map<int, string> romanMap;
    romanMap[1] = "I";
    romanMap[4] = "IV";
    romanMap[5] = "V";
    romanMap[9] = "IX";
    romanMap[10] = "X";
    romanMap[40] = "XL";
    romanMap[50] = "L";
    romanMap[90] = "XC";
    romanMap[100] = "C";
    romanMap[400] = "CD";
    romanMap[500] = "D";
    romanMap[900] = "CM";
    romanMap[1000] = "M";
    
    string result;
    
    for (auto it = romanMap.rbegin(); it != romanMap.rend(); ++it) {
        int currentValue = it->first;
        string numeral = it->second;
        
        while (arabic >= currentValue) {
            result += numeral;
            arabic -= currentValue;
        }
    }
    
    return result;
}

int main()
{
    string input;
    int number;
    
    cout << "Введите римскую цифру или арабское число: ";
    cin >> input;
    
    // Проверка, является ли ввод римской цифрой или арабским числом
    if (isdigit(input[0])) {
        number = stoi(input);
        cout << "Арабская цифра " << number << " в римской системе: " << arabicToRoman(number) << endl;
    } else {
        cout << "Римская цифра " << input << " в арабской системе: " << romanToArabic(input) << endl;
    }
    
    return 0;
}
