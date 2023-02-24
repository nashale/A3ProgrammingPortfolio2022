#include <bits/stdc++.h>
using namespace std;
 
bool isVowel(char c)
{
    return (c == 'A' || c == 'E' || c == 'I' ||
            c == 'O' || c == 'U' || c == 'a' ||
            c == 'e' || c == 'i' || c == 'o' ||
            c == 'u');
}

string pigLatin(string s)
{
    // the index of the first vowel is stored.
    int len = s.length();
    int index = -1;
    for (int i = 0; i < len; i++) {
        if (isVowel(s[i])) {
            index = i;
            break;
        }
    }
 
    // Pig Latin is possible only if vowels
    // is present
    if (index == -1)
        return "-1";
 
    return s.substr(index) + s.substr(0, index) + "ay";
}
 
// Driver code
int main()
{
    string firstName, lastName; 
    cout << "Welcome to the Pig Latin Name Converter! Please enter your first name: " << endl;
    getline(cin, firstName);
    cout << "Great! Now enter your last name: " << endl;
    getline(cin, lastName);
    string str = pigLatin(firstName);
    if (str == "-1")
        cout << "No vowels found. Pig Latin not possible";
    else
        cout << "Your first name converted is: " << str << "\n";
    string str2 = pigLatin(lastName);
    if (str2 == "-1")
        cout << "No vowels found. Pig Latin not possible";
    else
        cout << "Your last name converted is: " << str2;
}

