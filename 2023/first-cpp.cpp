#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstring>

// macro to convert single-digit integer chars to ints (for readability)
#define pINT(i) (i - '0')

// function headers
int part1(std::ifstream*);
int part2(std::ifstream*);
int findFLInt(std::string, int*);
int findFLStr(std::string, int*);
int parseInt(const char*);

int main(int argc, char *argv[]) {
    // grabs input file
    std::ifstream inputFile("./input-1.txt");

    // for debugging: grabs nth line from input for use in functions
    // std::string ins;
    // for(int n = atoi(argv[1]); n > 0; n--) inputFile >> ins;

    // Output with function calls for part 1 and part 2 of challenge day 1
    std::cout << "Answer to part 1 is: " << part1(&inputFile) << "\n";
    std::cout << "Answer to part 2 is: " << part2(&inputFile) << "\n";

    return 0;
}

// Gets answer to part 1
int part1(std::ifstream *input) {
    std::string ins;
    int out[2];
    int sum = 0;
    
    while(*input >> ins) { // runs until EOF
        findFLInt(ins, out);

        sum += pINT(ins[out[0]])*10 + pINT(ins[out[1]]); // converts first and last values to first and last digits and adds to total sum
    }

    //returning to start of filestream
    input->clear();
    input->seekg(0);

    return sum;

}

int part2(std::ifstream *input) {
    std::string ins;

    // results of functions are stored in arrays for easy comparison and retrieval
    // FL = "First Last", initialized to -1 to catch errors
    int outs[4] = {}, outi[2] = {}, FL[2] = {-1}, sum = 0;

    while(*input >> ins) { // runs until EOF
        findFLInt(ins, outi);
        findFLStr(ins, outs);

        if(outi[0] < outs[0] && outi[0] != -1) FL[0] = pINT(ins[outi[0]]); // first value is number if it comes before word and it exists in the string
        else if(outs[1] != -1) FL[0] = outs[1]; // first value is word if it comes before number and exists in string
        else FL[0] = -1; // sets first value to -1 to indicate an error

        if(outi[1] > outs[2]) FL[1] = pINT(ins[outi[1]]); // last value is number if it comes after word
        else if(outs[2] > outi[1] && outs[3] != -1) FL[1] = outs[3]; // last value is word if comes after number and exists in string
        else FL[1] = -1; // sets first value to -1 to indicate an error

        sum += (FL[0]*10) + FL[1]; // converts first and last values to first and last digits and adds to total sum
    }

    //returning to start of filestream
    input->clear();
    input->seekg(0);

    return sum;
}

int parseInt(const char* input) { // from a char* in a string, returns number if it is the beginning of a number as a word
    std::string nums[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; // lookup array, index = value
    for(int i = 0; i <= 9; i++) {
        if(strncmp(input, nums[i].c_str(), nums[i].length()) == 0) return i; // returns integer value of word.
    }

    return -1;
}

int findFLInt(std::string input, int* out) { // finds first and last number of string
    int a, b, slen;
    slen = input.length();

    for(a = 0; !isdigit(input[a]) && a < slen; a++); // finds index of first number
    for(b = slen - 1; !isdigit(input[b]) && b >= 0; b--); // finds the index of the last number

    out[0] = a; out[1] = b; // stores indices in output array

    return 0;
}

int findFLStr(std::string input, int* out) { //finds first and last number word in string
    int a, b, slen;
    slen = input.length();

    for(a = 0; parseInt(&input.c_str()[a]) == -1 && a < slen; a++); // finds the index of the first number
    for(b = slen; parseInt(&input.c_str()[b]) == -1 && b >= 0; b--); // finds the index of the last number

    // stores both the index and value of the numbers for easier comparison and usage
    out[0] = a; out[1] = parseInt(&input.c_str()[a]);
    out[2] = b; out[3] = parseInt(&input.c_str()[b]);

    return 0;
}