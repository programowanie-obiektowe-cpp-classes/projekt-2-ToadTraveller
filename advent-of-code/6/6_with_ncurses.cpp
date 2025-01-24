#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <vector>
#include <ncurses.h>
#include <chrono>
#include <thread>

int counter = 0;
int direction = 0;
std::string path = "/home/bimberiev/Desktop/advent-of-code/6/input.txt";


std::array<std::array<char, 130>, 130> dataRead(const std::string& path) {
    std::ifstream file(path);
    if(!file) {
        throw std::runtime_error("Nie można otowrzyc pliku");
    }
    std::array<std::array<char, 130>, 130> data;
    
    for(int i = 0; i<130; i++){
        std::string line;
        std::getline(file, line);
        if (line.size() < 130) {
            throw std::runtime_error("Nieprawidłowa długość wiersza w wierszu " + std::to_string(i));
        }
        for(int j = 0; j<130; j++){
            data[i][j] = line [j];
        }
        std::cout<<std::endl;
    }
    file.close();

    return data;

}

std::array<std::array<char, 130>, 130> data = dataRead(path);



std::pair<int,int> findGuard(std::array<std::array<char, 130>, 130>& data){
     for (int i = 0; i < 130; ++i) {
        for (int j = 0; j < 130; ++j) {
            if (data[i][j] == '^') {
                std::cout << "Strażnik jest tutaj: (" << i << ", " << j << ")" << std::endl;
                return {i, j};

            }
        }
    }
    std::cout << "Strażnik nie został znaleziony." << std::endl;
    return{-1,-1};
}

std::vector<std::pair<int, int>> directions = {{
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
}};

std::pair<int, int> operator+(const std::pair<int, int>& a, const std::pair<int, int>& b){
    return  {a.first + b.first, a.second + b.second};
}
bool ifLeftMap(std::pair<int,int>& position){
    int x = position.first;
    int y = position.second;

    if(x < 0 || x >= 130 || y < 0 || y >= 130) {
        std::cout << "Strażnik wyszedł poza mapę!"<<std::endl;
        return false;
    }else{
        return true;
    }

}

void move(std::array<std::array<char, 130>, 130>& data, std::pair<int,int>& position, int& direction){
    data[position.first][position.second] = 'X';

    std::pair<int, int> next_step = position + directions[direction];
    if(data[next_step.first][next_step.second] == '#'){
        direction = (direction+1)%4;
        counter++;
        std::cout << "Odwiedzonych przeszkód: " << counter << std::endl;
    }else{
        position = next_step;
    }
    

        
}


void printMap(const std::array<std::array<char, 130>, 130>& map) {
    for (const auto& row : map) {       // Iteracja przez wiersze
        for (const auto& cell : row) { // Iteracja przez komórki w wierszu
            std::cout << cell;
        }
        std::cout << '\n'; // Nowa linia po każdym wierszu
    }
}

void printMapNcurses(const std::array<std::array<char, 130>, 130>& data, const std::pair<int, int>& position){
    for (int i = 0; i < 130; ++i) {
        for (int j = 0; j < 130; ++j) {
            if (i == position.first && j == position.second) {
                mvaddch(i, j, 'O'); // Wyświetlenie strażnika
            } else {
                mvaddch(i, j, data[i][j]); // Wyświetlenie komórki mapy
            }
        }
    }
    refresh();
}

int main(){
    std::array<std::array<char, 130>, 130> data = dataRead(path);
    std::pair<int,int> position = findGuard(data);
    initscr();
    noecho();
    curs_set(0);


    while(ifLeftMap(position)){
        clear();
        move(data, position, direction);
        printMapNcurses(data, position);
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    printMapNcurses(data, position);
    getch();
    endwin();
    std::cout << "Odwiedzonych przeszkód: " << counter << std::endl;

    return 0;



}
