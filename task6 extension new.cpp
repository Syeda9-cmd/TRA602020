#include <iostream>
using namespace std;
int myStrLen(char* s) {
    char* p = s;
    while (*p != '\0') p++;
    return (int)(p - s);
}
bool isPalindrome(char* s) {
    int len   = myStrLen(s);
    char* left  = s;
    char* right = s + len - 1;
    while (left < right) {
        if (*left != *right) return false;
        left++;
        right--;
    }
    return true;
}
char toLow(char c) {
    if (c >= 'A' && c <= 'Z') return c + 32;
    return c;
}
bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
bool isPalindromeExtended(char* s) {
    int len   = myStrLen(s);
    char* left  = s;
    char* right = s + len - 1;
    while (left < right) {
        while (left < right && !isLetter(*left))  left++;
        while (left < right && !isLetter(*right)) right--;
        if (toLow(*left) != toLow(*right)) return false;
        left++;
        right--;
    }
    return true;
}
int main() {
    char words[][50] = {
    	"madam"
    	"racecar"
    	"hello"
    	"level"
        "A man a plan a canal Panama"
    };
    int count = 5;
    cout << "Basic Palindrome Check:\n";
    for (int i = 0; i < count - 1; i++) {
        cout << "  \"" << words[i] << "\" => "
             << (isPalindrome(words[i]) ? "Palindrome" : "Not Palindrome") << "\n";
    }
    cout << "\nExtended Check (ignore spaces & case):\n";
    for (int i = 0; i < count; i++) {
        cout << "  \"" << words[i] << "\" => "
             << (isPalindromeExtended(words[i]) ? "Palindrome" : "Not Palindrome") << "\n";
    }
    char input[100];
   cout << "\nEnter your own string to check: ";
    cin.getline(input, 100);
    cout << "Result (extended): "
         << (isPalindromeExtended(input) ? "Palindrome" : "Not Palindrome") << "\n";
    return 0;
}
