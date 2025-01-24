#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>
#include <array>
#include <ranges>
#include <algorithm>
#define ARR_SIZE 54

std::array<std::array<int, ARR_SIZE>, ARR_SIZE> dataRead(){
    std::string path = "/home/bimberiev/Desktop/advent-of-code/10/input.txt";
    std::ifstream file(path);

    if(!file.is_open()){
        throw std::runtime_error("Could not open file:" + path);
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    

    auto lines = content | std::views::split('\n');


    std::array<std::array<int, ARR_SIZE>, ARR_SIZE> parsed;
    size_t row = 0;
    for(auto&& line : lines) {
        size_t col = 0;
        for(auto&& liczba : line){
            parsed[row][col]=liczba - '0';
            col++;
        }
        row++;
    }
    return parsed;

}

sf::Color intensityToColor(int intensity) {
    float normalized = intensity / 9.0f; 
    sf::Uint8 red = static_cast<sf::Uint8>(normalized * 255);
    sf::Uint8 green = static_cast<sf::Uint8>((1 - normalized) * 255);
    return sf::Color(red, green, 0);
}

sf::Color visitedColor(int intensity) {
    float normalized = intensity / 9.0f; 
    sf::Uint8 red = static_cast<sf::Uint8>(normalized * 255);
    sf::Uint8 green = static_cast<sf::Uint8>((1 - normalized) * 255);
    return sf::Color(red, green, 100);
}

void drawMap(auto& data, auto& visited){
     const int width = ARR_SIZE;
    const int height = ARR_SIZE;
    const int cellSize = 10; 

    sf::RenderWindow window(sf::VideoMode(width * cellSize, height * cellSize), "Mapa");
    



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x) {
                sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
                cell.setPosition(x * cellSize, y * cellSize);
                if (visited[x][y]) {
                    cell.setFillColor(intensityToColor(data[y][x]));
                } else {
                    cell.setFillColor(intensityToColor(data[y][x]));
                }
                window.draw(cell);
               
            }
        }

        window.display();
    }
}


std::vector<std::pair<int,int>> directions = {{
    {0, 1}, {0, -1}, {1, 0}, {-1, 0}
}};

bool isValid(int x, int y) {
    return x >= 0 && x < ARR_SIZE && y >= 0 && y < ARR_SIZE;
}

int trail(const std::array<std::array<int, ARR_SIZE>, ARR_SIZE>& data, int x, int y){
    
    

    if(!isValid(x, y)){
        return 0;
    }
    if(data[x][y] == 9 && isValid(x, y)){
        return 1;
        }
  
    int score = 0;
    for(auto pair : directions){
        int dx = pair.first;
        int dy = pair.second;

        if(isValid(x+dx, y+dy) && data[x+dx][y+dy] == data[x][y]+1){

            score += trail(data, x+dx, y+dy);
        }


    }

    
    return score;
}

int trailHead(const std::array<std::array<int, ARR_SIZE>, ARR_SIZE>& data) {
    static int totalScore = 0;
    
    for(int x = 0; x < ARR_SIZE; x++ ){
        for(int y = 0; y < ARR_SIZE; y++ ){
            if(data[x][y] == 0){
                int score =trail(data, x, y);
                std::cout << score << std::endl;
                totalScore +=score;
            }
            
        }
    }
    
    return totalScore;
}


int main() {

    std::array<std::array<int, ARR_SIZE>, ARR_SIZE> data = dataRead();
    


    int score = trailHead(data);

    //int score = trail(data, 6, 0, visited);
    std::cout << score << std::endl;



    //drawMap(data, visited);

    return 0;
   
}
