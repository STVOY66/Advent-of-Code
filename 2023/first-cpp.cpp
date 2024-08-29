#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstring>
#define pINT(i) (i - '0')

int part1(std::ifstream*);
int part2(std::ifstream*);
int findFLInt(std::string, int*);
int findFLStr(std::string, int*);
int parseInt(const char*);

int main(int argc, char *argv[]) {
    std::ifstream input("./input-1.txt");

    // for debugging: grabs nth line from input for use in functions
    // std::string ins;
    // for(int n = atoi(argv[1]); n > 0; n--) input >> ins;

    // std::cout << "Part1 answer: " << part1(&input) << "\n";
    // std::cout << "Part2 answer: " << part2(&input) << "\n";

    return 0;
}

int part1(std::ifstream *input) {
    std::string ins;
    int out[2];
    int sum = 0;
    
    while(*input >> ins) {
        findFLInt(ins, out);

        sum += pINT(ins[out[0]])*10 + pINT(ins[out[1]]);
    }

    return sum;

}

int part2(std::ifstream *input) {
    std::string ins;
    int outs[4] = {}, outi[2] = {}, FL[2] = {-1}, sum = 0;

    while(*input >> ins) {
        findFLInt(ins, outi);
        findFLStr(ins, outs);

        if(outi[0] < outs[0] && ins[outi[0]] != -1) FL[0] = ins[outi[0]] - '0';
        else if(outs[1] != -1) FL[0] = outs[1];
        else FL[0] = -1;

        if(outi[1] > outs[2]) FL[1] = ins[outi[1]] - '0';
        else if(outs[2] > outi[1] && outs[3] != -1) FL[1] = outs[3];
        else FL[1] = -1;
    }

    return 0;
}

int parseInt(const char* input) {
    std::string nums[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i = 0; i <= 9; i++) {
        if(strncmp(input, nums[i].c_str(), nums[i].length()) == 0) return i;
    }

    return -1;
}

int findFLInt(std::string input, int* out) {
    int a, b, slen;
    slen = input.length();

    for(a = 0; !isdigit(input[a]) && a < slen; a++);
    for(b = slen - 1; !isdigit(input[b]) && b >= 0; b--);

    if((out[0] + out[1]) != 0) return -1;

    out[0] = a;
    out[1] = b;

    return 0;
}

int findFLStr(std::string input, int* out) {
    int a, b, slen;
    slen = input.length();

    for(a = 0; parseInt(&input.c_str()[a]) == -1 && a < slen; a++);
    for(b = slen; parseInt(&input.c_str()[b]) == -1 && b >= 0; b--);

    int arrCheck = 0;
    for(int i = 0; i < 4; i++)
        arrCheck += out[i];

    if(arrCheck != 0) return -1;

    out[0] = a; out[1] = parseInt(&input.c_str()[a]);
    out[2] = b; out[3] = parseInt(&input.c_str()[b]);

    return 0;
}