#include <iostream>
#include <vector>
#include <string>
#include "data_read.hpp"



std::vector<int> diskMap(const std::vector<int>& data){
    std::vector<int> disk;
    int fileID = 0;

    for(size_t i = 0; i < data.size(); ++i){
        if(i % 2 == 0){
            //fill with ids

            for(int j = 0; j < data[i]; ++j){
                disk.push_back(fileID);
            }
            fileID++;
        }else{
            //fill with dots
            for(int j = 0; j < data[i]; ++j){
                disk.push_back(0);
            }
        }
    }


    std::cout << "Disk map: "<< std::endl;
    
    for(size_t i = 0; i < disk.size(); ++i){
        std::cout << disk[i];
      
    }
    std::cout << std::endl;
    

    return disk;

}

std::vector<int> diskSwap(std::vector<int> data){
    for(size_t i = 5; i < data.size(); ++i){
        if(data[i] == 0){
            for(size_t j = data.size() - 1; j > i; --j){
                if(data[j] != 0){
                    data[i] = data[j];
                    data[j] = 0;
                    break;
                }
            }

        }
  


    }
    /*
    std::cout << "Swapped disk map: "<< std::endl;
    
    for(size_t i = 0; i < data.size(); ++i){
        std::cout << data[i];
      
    }
    std::cout << std::endl;*/
    return data;
}
/*
std::vector<int> diskSwapImproved(std::vector<int> data){
    for(size_t i = 5; i < data.size(); ++i)



    return data;
}*/

size_t checksum(const std::vector<int>& data){
    size_t sum = 0;
    for(size_t i = 0; i < data.size(); ++i){
        sum += data[i]*i;

    }
    return sum;
}


int main(){

    std::string path = "/home/bimberiev/Desktop/advent-of-code/9/input.txt" ;
    std::vector<int> input = dataRead(path);
    std::vector<int> input2 = diskMap(input);
    std::vector<int> input3 = diskSwap(input2);
    size_t sum = checksum(input3);

    std::cout << sum << std::endl;

    return 0;
}