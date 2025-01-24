#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iterator>
#include "data_read.hpp"

std::string dataRead(const std::string& path){
    std::ifstream file(path, std::ios::binary | std::ios::in);
    //std::ios::in -> flaga, plik do odczytu
    //std::ios::binary - flaga, plik otwarty w trybie binarnym

    if(!file.is_open()){
        throw std::runtime_error("Could not open file:" + path);
    }

    //wczytanie całego pliku do ciągu znaków 
    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    //std::string:;streambuf_iterator

}
