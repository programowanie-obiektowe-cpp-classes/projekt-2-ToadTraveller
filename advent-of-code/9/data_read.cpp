#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "data_read.hpp"


std::vector<int> dataRead(const std::string& path){
    std::vector<int> data;
    std::ifstream file(path, std::ios::binary | std::ios::in);

    if(!file){
        throw std::runtime_error("Nie można otworzyć pliku. " + path);
    }
    std::string content;
    char digit;
    while((file).get(digit)){
        if(isdigit(digit)){
            content +=digit;
        }
    }

    

    for(const char& ch : content){
        data.push_back(ch - '0');
    }
    /*
    for(size_t i = 0; i < data.size(); ++i){
        std::cout << data[i];
      
    }
*/
    file.close();
    return data;
}
