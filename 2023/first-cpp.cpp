#include <iostream>
#include <fstream>

int part1(std::ifstream*);

int main() {
    std::ifstream input("./input-1.txt");
    
    std::cout << part1(&input) << "\n";

    return 0;
}

int part1(std::ifstream *input) {
    std::string ins;
    std::string outs = "";
    int outi;
    int sum = 0;
    
    while(*input >> ins) {
        for(char& c : ins) {
            if(isdigit(c)) outs += c;
        }
        outi = atoi((std::string(1, outs[0]) + outs[outs.length() - 1]).c_str());
        sum += outi;
        outs = "";
    }

    return sum;

}