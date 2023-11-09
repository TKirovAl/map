#include <iostream>
#include <map>
using namespace std;

/*string arabicToRoman(int num) {
    //string result = ""

   map<int, string> romanNumerals{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    for (auto it = romanNumerals.begin(); it != romanNumerals.end(); ++it) {
        while (num >= it->first) {
            result += it->second;
            num -= it->first;
        }
    }

    return result;
} */

int romanToArabic(string roman) {
    int result = 0;

    map<char, int> romanNumerals{
        {'M', 1000}, {'D', 500}, {'CD', 400}, {'C', 100}, {"XC", 90}, {'L', 50}, {'XL', 40}, {'X', 10}, {"IX", 9}, {'V', 5}, {'IV',4}, {'I', 1}
    };

    for (int i = 0; i < roman.length(); i++) {
        if (i < roman.length() - 1 && romanNumerals[roman[i]] < romanNumerals[roman[i + 1]]) {
            result -= romanNumerals[roman[i]];
        }
        else {
            result += romanNumerals[roman[i]];
        }
    }

    return result;
}

int main() {
    int arabicNumber;
    string romanNumber;

    cin >> arabicNumber;
    cin >> romanNumber;

    string romanResult = arabicToRoman(arabicNumber);
    cout << arabicNumber << " = " << romanResult << endl;

    int arabicResult = romanToArabic(romanNumber);
    cout << romanNumber << " = " << arabicResult << endl;

    return 0;
}
