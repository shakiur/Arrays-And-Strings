#include <iostream>
#include <string>

using namespace std;

// Find first non-repeated character
char findNonRepeatedChar(string);

int main() {
    string test = "total";

    char first_char = findNonRepeatedChar(test);

    cout << "First Single Char in: '" << test << "' is '";

    if (first_char != '\0')
        cout << first_char << "'\n";
    else
        cout << "NONE_FOUND" << "'\n";
    
}

char findNonRepeatedChar(string test) {
    int test_len = test.length();
    int total_ascii = 128;

    int letter_cnt_arr[total_ascii];

    // Initialize array to 0's
    for(int i = 0; i < total_ascii; i++) {
        letter_cnt_arr[i] = 0;
    }

    // Store the count of each letter in a map
    for(int i = 0; i < test_len; i++) {
        letter_cnt_arr[int(test[i])]++;
    }

    // Find first letter in original string
    // that has a count of 1 and return it
    for(int i = 0; i < test_len; i++) {
        if(letter_cnt_arr[int(test[i])] == 1)
            return test[i];
    }

    return '\0';
}