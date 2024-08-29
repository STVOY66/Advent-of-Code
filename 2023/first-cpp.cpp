#include <iostream>
#include <fstream>
#include <cstdint>
#include <cstring>
#define pINT(i) (i - '0')

int part1(std::ifstream*);
int part2(std::ifstream*);
void findFLInt(std::string, int*);
void findFLStr(std::string, int*);
int parseInt(const char*);

int main(int argc, char *argv[]) {
    std::ifstream input("./input-1.txt");

    // std::cout << "Answer to part 1 is: " << part1(&input) << "\n";
    // std::cout << "Answer to part 2 is: " << part2(&input) << "\n";
    std::cout << parseInt("fivetynine") << "\n";
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
    return -1;
}

int parseInt(const char* input) {
    std::string nums[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for(int i = 0; i <= 9; i++) {
        if(strncmp(input, nums[i].c_str(), nums[i].length()) == 0) return i;
    }

    return -1;
}

void findFLInt(std::string input, int* out) {
    int a, b, slen;
    slen = input.length();

    for(a = 0; !isdigit(input[a]) && a < slen; a++);
    for(b = slen - 1; !isdigit(input[b]) && b >= 0; b--);

    out[0] = a;
    out[1] = b;
}

void findFLStr(std::string input, int* out) {
    
}