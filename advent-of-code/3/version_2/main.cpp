#include <iostream>
#include <string>
#include <regex>
#include "data_read.hpp"

std::string enabled (std::string& input){
    std::string chunk;
    size_t sPos = 0;
    size_t dont1Pos = input.find("don't()", sPos);
    chunk += input.substr(sPos, dont1Pos + 6);


    while (sPos != std::string::npos) {
        
        size_t doPos = input.find("do()", sPos);
        if (doPos == std::string::npos) {
            break; // Nie ma więcej "do()"
        }
        size_t dontPos = input.find("don't()", doPos);
        if (dontPos == std::string::npos) {
            break; // Nie ma zamykającego "don't()"
        }

        chunk += input.substr(doPos, dontPos - doPos + 7);
        sPos = 7 + dontPos;

    }


    std::cout << chunk << std::endl;

    return chunk;
}


int sumOfMul(const std::string& chunk){
    int sum = 0;
    std::regex mulRegex(R"(mul\(\s*(\d+)\s*,\s*(\d+)\s*\))");
    std::smatch matches;

    auto begin = chunk.cbegin();
    auto end = chunk.cend();

    while (std::regex_search(begin, end, matches, mulRegex)) {
        for(size_t i = 1; i < matches.size(); i++){
            std::cout << "Group " << i <<": "<< matches[i].str() << std::endl;
        }
        
        int num1 = std::stoi(matches[1].str());
        int num2 = std::stoi(matches[2].str());

        sum += num1 * num2;

        begin = matches.suffix().first;
    }
    return sum;


}


int main(){

    std::string path = "/home/bimberiev/Desktop/advent-of-code/3/input3.txt" ;
    std::string input = dataRead(path);
    std::string chunk = enabled(input);
    long long result = sumOfMul(chunk);

    std::cout << "Suma wszystkiech wyników mnożenia: " << result << std::endl;

    return 0;
}
