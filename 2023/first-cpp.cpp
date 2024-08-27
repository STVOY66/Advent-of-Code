#include <iostream>
#include <fstream>
#include <cstdint>
#define pINT(i) (i - '0')

int part1(std::ifstream*);
int part2(std::ifstream*);

int main(int argc, char *argv[]) {
    std::ifstream input("./input-1.txt");
    int ans;

    if(pINT(*argv[1]) - 1)
        ans = part1(&input);
    else
        ans = part2(&input);
    
    std::cout << "Answer to part " << argv[1] << "is: " << ans << "\n";

    return 0;
}

int part1(std::ifstream *input) {
    std::string ins;
    uint8_t a, b, inlength;
    int sum = 0;
    
    while(*input >> ins) {
        inlength = ins.length(); 

        for(a = 0; !isdigit(ins[a]) && a < inlength; a++);
        for(b = inlength - 1; !isdigit(ins[b]) && b >= 0; b--);

        sum += pINT(ins[a])*10 + pINT(ins[b]);
    }

    return sum;

}