#include <iostream>
#include <array>
#include <fstream>
#include <string>
#include <vector>
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

void move(auto& data, std::pair<int,int>& position, int& direction, int& counter2, std::vector<int>& loops){
    data[position.first][position.second] = 'X';

    std::pair<int, int> next_step = position + directions[direction];
    if(data[next_step.first][next_step.second] == '#'){
        direction = (direction+1)%4;
        counter++;
        loops.push_back(counter2);
        counter2 = 0;
    }else{
        position = next_step;
        counter2++;
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

void findPairs(const std::vector<int>& loops) {
    int count = 0;
    for (size_t i = 0; i < loops.size() - 2; ++i){
        if(loops[i] > loops[i+2]){
            std::cout << "Para: (" << loops[i] << ", " << loops[i + 2] << ")\n"; 
            count++;
        }
    }

    std::cout<<count<<std::endl;

}

int main(){
    std::array<std::array<char, 130>, 130> data = dataRead(path);
    std::pair<int,int> position = findGuard(data);
    std::vector<int> loops;
    int counter2 = 0;
    while(ifLeftMap(position)){
        move(data, position, direction, counter2, loops);
    }
    std::cout << "Odwiedzonych przeszkód: " << counter << std::endl;


    findPairs(loops);

    return 0;



}