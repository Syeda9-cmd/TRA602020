#include <iostream>
using namespace std;
int countVowels(char* str) {
    char* ptr = str;
    int count = 0;
    int index = 0;
    cout << "\nVowels found:\n";
    while (*ptr != '\0') {
        char ch = *ptr;
        if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ||
            ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U') {
            cout << "  Vowel: '" << ch << "'  at index " << index << "\n";
            count++;
        }
        ptr++;
        index++;
    }
    return count;
}
int main() {
    char str[]="Programming";
    int total = countVowels(str);
    cout << "\nTotal vowels = " << total << "\n";
    return 0;
}
