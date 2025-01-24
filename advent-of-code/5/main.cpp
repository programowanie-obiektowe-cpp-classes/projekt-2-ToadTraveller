#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <ranges>
#include <string_view>
#include <fstream>
#include <algorithm>

#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <stdexcept>


struct InputData {
    std::vector<std::vector<int>> zasady;
    std::vector<std::vector<int>> updates;
};

void dataRead(const std::string& path, InputData& data){
    std::ifstream file(path);

    if (!file){
        throw std::runtime_error("Nie można otworzyć pliku! "  + path);
    }

    //wczytanie file do stringa
    std::string input((std::istreambuf_iterator<char>(file)),(std::istreambuf_iterator<char>()));
    //znalezienie pierwszej sekcji
    const size_t section1_first = input.find("\n\n");
    if(section1_first == std::string::npos) {
        throw std::runtime_error("Nie znaleziono separatora w pliku");
    }

    const auto section1 = input.substr(0, section1_first);
    std::cout << section1 << std::endl;
//podzielenie ciągu znaków na przedziały (views)
    auto s = section1 | std::views::split('\n');

    std::vector<std::vector<int>> parsed1;

    for (auto&& line : s){
        std::vector<int> para;
        for(auto&& liczba : line | std::views::split('|')){
            std::string ls(liczba.begin(), liczba.end());
            para.push_back(std::stoi(ls));
        }
        parsed1.push_back(std::move(para));


    }

    data.zasady = std::move(parsed1);

    const auto section2 = input.substr(section1_first + 2);
    std::cout << section2 << std::endl;

    auto s2 = section2 | std::views::split('\n');

    std::vector<std::vector<int>> parsed2;

    for(auto&& line : s2){
        std::vector<int> linia;
        for(auto&& liczba : line | std::views::split(',')){
            std::string ls(liczba.begin(), liczba.end());
            linia.push_back(std::stoi(ls));
        }
        parsed2.push_back(linia);
    }

    data.updates = std::move(parsed2);

}

void print(InputData& data){
    std::cout << "Zasady: \n";
    for (const auto& row : data.zasady) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Aktualizacje: \n";
    for (const auto& row : data.updates) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void print(std::unordered_map<int, std::vector<int>>& graph){
    std::cout << "Graph: \n";

    for (const auto& row : graph) {
        std::cout << "Page " << row.first << " depends on: ";
        for (const auto& val : row.second) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void print (std::vector<int>& result){
    std::cout << "Topologiczne sortowanie: ";
    for (int v : result) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void print(std::queue<int>& q) {
    std::cout << "Kolejka: ";
    std::queue<int> tempQueue = q;  // Kopiujemy kolejkę, aby nie zmieniać oryginalnej
    while (!tempQueue.empty()) {
        std::cout << tempQueue.front() << " ";  // Wypisujemy pierwszy element
        tempQueue.pop();  // Usuwamy pierwszy element
    }
    std::cout << std::endl;
}
void createGraph(const std::vector<std::vector<int>>& dependencies, 
std::unordered_map<int, std::vector<int>>& graph,
std::unordered_map<int, int>& indegree,
int& maxPage){

    for(const auto& dep : dependencies) {

        int X = dep[0];
        int Y = dep[1];

        graph[X].push_back(Y);
        indegree[Y]++;

        maxPage = std::max(maxPage, std::max(X,Y));
    }

}

std::vector<int> topologicalSort(std::unordered_map<int, std::vector<int>>& graph,
std::unordered_map<int, int>& indegree,
int& maxPage) {
    std::queue<int> q;
    std::vector<int> result;

    for (auto it = indegree.begin(); it != indegree.end(); ++it){
        
        q.push(it->first);
        
    }
    print(q);

    while(!q.empty()) {
        int u  = q.front();
        q.pop();
        result.push_back(u);

        for (int v : graph.at(u)) {
            if (--indegree.at(v) == 0){
                q.push(v);
            }
        }


    }

    

    

    return result;

}




int main() {
    std::string path = "input.txt";
    InputData data;
    dataRead(path, data);
    print(data);

    std::unordered_map<int, std::vector<int>> graph;
   
    std::unordered_map<int, int> indegree;
    int maxPage = 0;

    createGraph(data.zasady, graph, indegree, maxPage);
    

    std::vector<int> result = topologicalSort(graph, indegree, maxPage);
    print(result);






    return 0;
}


