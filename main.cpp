#include <iostream>
#include <string>

using namespace std;

// Find first non-repeated character
char findNonRepeatedChar(string);

string removeCharFromString(string, string);

int main() {
    string test1 = "total";
    string test2 = "Battle of the Vowels: Hawaii vs. Grozny";
    string rmv_test2 = "aeiou";

    char first_char = findNonRepeatedChar(test1);

    string new_test = removeCharFromString(test2, rmv_test2);

    cout << new_test << endl;
    
}

char findNonRepeatedChar(string test) {
    int test_len = test.length();
    int total_ascii = 128;

    int letter_cnt_arr[total_ascii];

    // Initialize array to 0's
    for(int i = 0; i < total_ascii; i++) {
        letter_cnt_arr[i] = 0;
    }

    // Store the count of each letter in an array
    for(int i = 0; i < test_len; i++) {
        letter_cnt_arr[int(test[i])]++;
    }

    // Find first letter in original string
    // that has a count of 1 and return it
    for(int i = 0; i < test_len; i++) {
        if(letter_cnt_arr[int(test[i])] == 1)
            return test[i];
    }

    // Return if no non-repeated characters are found
    return '\0';
}

string removeCharFromString(string orig_str, string rmv_str) {
    int orig_len = orig_str.length();
    int rmv_len = rmv_str.length();

    // New string to build new string
    string new_str;

    // Array to hold which characters to remove
    int rmv_ascii_arr[128];

    // Fill array with 0's so they can be incremented
    for(int i = 0; i < 128; i++) {
        rmv_ascii_arr[i] = 0;
    }

    // Flag characters that need to be removed
    for(int i = 0; i < orig_len; i++) {
        rmv_ascii_arr[int(rmv_str[i])]++;
    }

    // Go through original string and keep chars that aren't flagged
    for(int i = 0; i < orig_len; i++) {
        if(rmv_ascii_arr[int(orig_str[i])] == 0)
            new_str += orig_str[i];
    }

    return new_str;


}