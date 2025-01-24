#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "data_read.hpp"



void print(const std::vector<std::pair<int, std::vector<int>>>& data){
    for(const auto& [first, rest] : data){
        std::cout << "Wynik: "<< first <<"Sklad: ";
        for(const auto& val : rest) {
            std::cout << val << ' ';
        }
        std::cout << std::endl;
    }
};

std::vector<std::pair<int, std::vector<int>>> dataRead(const std::string& path){

    std::ifstream file(path);
    if (!file) {
        throw std::runtime_error("Nie mozna otowrzyć pliku " + path);
    }

    std::vector<std::pair<int, std::vector<int>>> data;
    std::string line;

    while(std::getline(file, line)){
        //ss to obiekt typu stringstream
        //jest to rodzaj strumienia, który działa na stringach i umożliwia łątwe przetważanie/manipulację tekstu w pamięci
        //pojedynczy wiersz wczytany z pliku csv
        std::stringstream ss(line);
        std::string cell;
        std::vector<int> row;

        int first_val = 0;

        if(std::getline(ss, cell, ',')){
            first_val = std::stoi(cell);
        }

        while(std::getline(ss, cell, ',')){
            row.push_back(std::stoi(cell));
        }

        data.emplace_back(first_val, row);

    }

    file.close();

    print(data);

    return data;


};

//wypisanie zawartosci
