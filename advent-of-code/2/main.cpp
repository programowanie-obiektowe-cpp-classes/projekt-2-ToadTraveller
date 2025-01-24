#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>  //istringstream
#include <string>   //getline

std::vector<std::vector<int>> dataRead(std::string path){
    std::vector<std::vector<int>> results;
    std::string line;

    std::ifstream file(path);
    if (!file.is_open()){
        throw std::runtime_error("Nie można otowrzyć pliku!");
    }

    while(std::getline(file, line) && !line.empty()){
        

        std::stringstream ss(line);
        std::vector<int> result;
        int lvl;

        while(ss >> lvl){
            result.push_back(lvl);
        }

        results.push_back(result);
    } 

    //wyświetlenie wczytanych raportów
    /*
    std::cout << "\nWczytane raporty:\n";
    for (const auto& result : results){
        for(const auto& lvl : result){
            std::cout << lvl << " ";
        }
        std::cout << "\n";
    }
    */

    file.close();
    return results;
}

bool isMonotonic(const std::vector<int>& raport){
    bool increasing = true;
    bool decreasing = true;
    
    for (size_t i = 1; i < raport.size(); ++i){
        if(raport[i-1] < raport[i]){
            decreasing = false;
            

        }
        if(raport[i-1] > raport[i]){
            increasing = false;
        }
    }

    return increasing || decreasing; 
}


bool isValid(const std::vector<int>& raport){
    
    for (size_t i = 0; i < raport.size()-1; ++i){
        int diff = abs(raport[i+1] - raport[i]);
        if(diff < 1 || diff > 3){
            return false;
        }
        
    }
   return true;
}

bool Damper(const std::vector<int>& raport) {
    if(isMonotonic(raport) && isValid(raport)) return true;

    for(size_t i = 0; i < raport.size(); ++i){
        std::vector<int> modified = raport;
        modified.erase(modified.begin()+i);

        if(isMonotonic(modified) && isValid(modified)){
            return true;
        }
    }
    return false;
}


int safetyCheck(std::vector<std::vector<int>>& raports){
    int counter = 0;
    for (const auto& raport : raports){
        if(isValid(raport) && isMonotonic(raport)){
            counter++;

        }else if(Damper(raport)){
            counter++;
        }
    }

    return counter;
}


int main(){
    std::string path = "/home/bimberiev/Desktop/advent-of-code/2/input_2.csv";
    std::vector<std::vector<int>> raports;


    raports = dataRead(path);
    int safe = safetyCheck(raports);
    std::cout << "Liczba bezpiecznych raportów: " << safe << std::endl;

    return 0;

}