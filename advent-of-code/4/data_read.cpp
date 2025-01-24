#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "data_read.hpp"


std::vector<std::vector<char>> dataRead(const std::string& path){
    std::ifstream file(path);
    if (!file){ 
        throw std::runtime_error("Nie można otowrzyc pliku! " + path);
    }

    std::vector<std::vector<char>> data ;
    std::string line;

    while (std::getline(file, line)) {
        //zamiana stringa na rządek charów
        std::vector<char> row(line.begin(),line.end());
        data.push_back(row);
    }

    file.close();
    int rows = data.size();
    int cols = data[0].size();

    //std::cout << "Liczba wierszy: " << data.size() << std::endl;
    //std::cout << "Liczba kolumn: " << (data.empty() ? 0 : data[0].size()) << std::endl;

    //wyświetlenie macierzy
    /*
    std::cout << "Wczytane dane:"<<std::endl;
    for (const auto& row : data) {
        for(char ch : row){
            std::cout << ch << ' ';
        }
        std::cout << std::endl;
    }
    */
    return data;
}