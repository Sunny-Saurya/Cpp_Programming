#include <iostream>
#include <string>
using namespace std;

// Function to check if a character is a vowel
bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// Function to reverse the vowels in the string
string reverseVowel(string str) {
    int i = 0;
    int j = str.length() - 1;

    while (i < j) {
        while (i < j && !isVowel(str[i])) {
            i++;
        }

        while (i < j && !isVowel(str[j])) {
            j--;
        }

        if (i < j) {
            swap(str[i], str[j]);
            i++;
            j--;
        }
    }

    return str; // Return the modified string after the loop
}

int main() {
    string str;
    cout << "Enter string: ";
    getline(cin, str);

    // Call the reverseVowel function
    string str1 = reverseVowel(str);

    // Print the modified string
    cout << "String after reversing vowels: " << str1 << endl;

    return 0;
}
