#include <iostream>
#include <string>
#include "math.h"

using namespace std;

// Find first non-repeated character
char findNonRepeatedChar(string);

// Remove all chars in string2 from string1
string removeCharFromString(string, string);

// Reverse all words from string 
string reverseWords(string);

// Reverses all words without creating copy of string
string reverseWordsNoBuffer(string);

// Converts a string to a signed int
int stringToInt(string);

// Converts single char digit to int
int getDigitFromChar(char);

// Converts a signed int to string
string intToString(int);

int main() {

   
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

string reverseWords(string orig_str) {

    // If orig_str is empty, return empty string
    if(orig_str == "")
        return orig_str;

    string reverse_str = "";

    int orig_len = orig_str.length();
    int orig_num_words = 1;

    // Find total number of words;
    for(int i = 0; i < orig_len; i++) {
        if(orig_str[i] == ' ')
            orig_num_words++;
    }

    // Array to hold all words in original string
    string orig_words_arr[orig_num_words];
    
    // Write words to new arr
    string temp_word;
    int orig_indx = 0;

    for(int i = 0; i < orig_len; i++) {

        char temp_c = orig_str[i];

        if(temp_c == ' ') {
            orig_words_arr[orig_indx] = temp_word;
            temp_word = "";
            orig_indx++;
        }
        else {
            temp_word += temp_c;
        }

    }

    // Write last word to array
    orig_words_arr[orig_indx] = temp_word;

    // Place reversed array in string
    for(int i = orig_indx; i >= 0; i--) {
        reverse_str += orig_words_arr[i]+" "; 

    }

    return reverse_str;

}

string reverseWordsNoBuffer(string orig_str) {

    string reverse_str = "";

    if(orig_str == "")
        return reverse_str;

    int orig_str_len = orig_str.length();

    int orig_str_begin = 0;

    // Reverse entire original string
    for(int i = (orig_str_len-1); i > orig_str_begin; i--) {

        char temp = orig_str[i];
        orig_str[i] = orig_str[orig_str_begin];
        orig_str[orig_str_begin] = temp;

        orig_str_begin++;
    }

    // Reverse each individual word
    int word_begin = 0;

    for(int i = 0; i < orig_str_len; i++) {

        if(orig_str[i] == ' ') {
            
            for(int k = i-1; k > word_begin; k--) {

                char temp = orig_str[k];
                orig_str[k] = orig_str[word_begin];
                orig_str[word_begin] = temp;

                word_begin++;
            }
            
            word_begin = (i+1);

        }

        // Reverse last word
        if(i == orig_str_len-1) {

            for(int k = i; k > word_begin; k--) {

                char temp = orig_str[k];
                orig_str[k] = orig_str[word_begin];
                orig_str[word_begin] = temp;

                word_begin++;
            }

        }

    }

    cout << orig_str << endl;
    cout << endl;
    return orig_str;

}

int stringToInt(string str_int) {

    int str_int_len = str_int.length();

    int result = 0;
    bool is_neg = false;

    for(int i = 0; i < str_int_len; i++) {
        
        
        if(str_int[i] == '-') {

            // If minus is found, need to make negative eventually
            is_neg = true;

        }
        else {

            // Find each individual digit
            int num = getDigitFromChar(str_int[i]);

            // Multiply digit by power of 10 that corresponds to its place
            result += num*pow(10,(str_int_len-1)-i);

        }

    }

    if(is_neg) {
        result *= -1;
    }

    return result;

}

int getDigitFromChar(char digit) {

    int digit_int;

    switch(digit) {
        case '0':
            digit_int = 0;
            break;
        case '1':
            digit_int = 1;
            break;
        case '2':
            digit_int = 2;
            break;
        case '3':
            digit_int = 3;
            break;
        case '4':
            digit_int = 4;
            break;
        case '5':
            digit_int = 5;
            break;
        case '6':
            digit_int = 6;
            break;
        case '7':
            digit_int = 7;
            break;
        case '8':
            digit_int = 8;
            break;
        case '9':
            digit_int = 9;
            break;
    }

    return digit_int;
}