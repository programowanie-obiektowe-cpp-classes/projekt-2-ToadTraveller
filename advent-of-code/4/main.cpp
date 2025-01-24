#include "data_read.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


std::vector<std::pair<int,int>> directions = {{
    {0, 1}, {0, -1}, {1, 0}, {-1, 0},
    {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
}};

long long xmasCounter(const std::vector<std::vector<char>>& data, const std::vector<std::pair<int,int>>& directions){
    int rows = data.size();
    int cols = data[0].size();

    //std::cout << "Liczba wierszy: " << data.size() << std::endl;
    //std::cout << "Liczba kolumn: " << (data.empty() ? 0 : data[0].size()) << std::endl;

    long long counter = 0;


    for (int y = 0; y< rows ; ++y){
        for(int x = 0; x< cols; ++x){
            if (data[y][x] == 'X'){
                for(auto [dy,dx] : directions){
                    if ((dy > 0 && y + 3 >= rows) || (dy < 0 && y - 3 < 0) ||
                        (dx > 0 && x + 3 >= cols) || (dx < 0 && x - 3 < 0)) {
                        continue; // Optymalizacja granic
                    }



                    int ny = y, nx = x;
                    bool found = true;

                    for(char c : {'M', 'A', 'S'}){
                        ny += dy;
                        nx += dx;

                        if (ny < 0 || ny >= rows || nx < 0 || nx >= cols || data[ny][nx] != c){
                            found = false;
                            break;
                        }
                    }
                    if(found){
                        counter ++;
                    }
                }
            }
        }
    }

    return counter;
}


std::vector<std::pair<int,int>> directions2 = {{
    {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
}};

bool isValid(const std::vector<char>& v){
    if(v.size() != 4) return false;

    int count_s = std::count(v.begin(), v.end(), 'S');
    std::cout << "znaleziono "<< count_s << "s ";
    int count_m = std::count(v.begin(), v.end(), 'M');
    std::cout << "znaleziono "<< count_m << "m ";

    if ((count_s == 2) && (count_m == 2)  && (v[0] != v[1])) {
        return true;
    }
    
    return false;
}
int masShape(const std::vector<std::vector<char>>& data, const std::vector<std::pair<int,int>>& directions2){
    int rows = data.size();
    int cols = data[0].size(); 
    int counter = 0;
    for (int y = 0; y< rows ; ++y){
        for(int x = 0; x< cols; ++x){
            if(data[y][x] == 'A'){
                std::vector<char> mmss;
                std::cout << "Pozycja: "<<data[y][x]<< x << y << ' ';

                for (auto [dy, dx] : directions2){
                    

                    int ny = y+dy, nx = x+dx;
                    //std::cout << "Wokół: "<<data[ny][nx]<< nx << ny << std::endl;
                    if (ny < 0 || ny >= rows || nx < 0 || nx >= cols) {
                        break; 
                    }
                    mmss.push_back(data[ny][nx]);


                }

                for(auto x : mmss){
                    std::cout << x;
                }
                if(isValid(mmss)){
                    counter++;
                    std::cout << " Sukces "<< counter << ' '<< std::endl;

                }else{
                    std::cout << std::endl;
                }
                mmss.clear();

            }
        }
    }

    return counter;
    
}







int main(){
    std::string path = "/home/bimberiev/Desktop/advent-of-code/4/input4.txt";
    std::vector<std::vector<char>> data = dataRead(path);
    //long long counter = xmasCounter(data, directions);

    //std::cout << "XMAS: " << counter << std::endl;


    int count = masShape(data, directions2);

    std::cout << "X-MAS: " << count << std::endl;




    return 0;
}