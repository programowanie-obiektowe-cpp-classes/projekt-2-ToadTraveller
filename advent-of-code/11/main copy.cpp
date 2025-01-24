#include <iostream>
#include <string>
#include <vector>
#include <ranges>
#include <sstream>
#include <deque>



std::vector<std::deque<std::string>> parsed() {

    std::string input = "6571 0 5851763 526746 23 69822 9 989";

    auto numbers = input 
        | std::views::split(' ') 
        | std::views::transform([](auto&& part){ 
            std::string s(part.begin(), part.end());
            return s;
        });

    
    std::deque<std::string> kamyk(numbers.begin(), numbers.end());
    std::vector<std::deque<std::string>> kamyki;
    kamyki.push_back(kamyk);

    return kamyki;
}

void printKamienie(const std::vector<std::deque<std::string>>& kamienie) {
    
    for(size_t blink = 0; blink < kamienie.size()-10; blink++) {
        std::cout << "Mrugnięcie nr: "<< blink+1<< std::endl;
        for(const auto& i : kamienie[blink]){
            std::cout << i <<' ';
        }
        
    }

}

void removeLeadingZeros(std::string& kamyk){
    size_t first_non_zero = kamyk.find_first_not_of('0');

    if(first_non_zero == std::string::npos){
        kamyk = "0";
    }else {
        kamyk = kamyk.substr(first_non_zero);
    }


}

void physicsDefyingStones(std::vector<std::deque<std::string>>& kamyki, const int& blink){

    std::deque<std::string> nowe_kamyki;
    std::deque<std::string>& kamyki_blink = kamyki.at(blink);
//iterujemy się przez cały rządek 
    for(auto& kamyk : kamyki_blink) {

        if(kamyk =="0") {
            nowe_kamyki.push_back("1");


        }else if(kamyk.size()%2 == 0) {

            size_t split_pos = kamyk.size()/2;

            std::string kamyk1 = kamyk.substr(0, split_pos);
            std::string kamyk2 = kamyk.substr(split_pos);

            removeLeadingZeros(kamyk1);
            removeLeadingZeros(kamyk2);

            nowe_kamyki.push_back(kamyk1);
            nowe_kamyki.push_back(kamyk2);

        }else{


            long long kamyk2 = std::stoll(kamyk);

            long long result = kamyk2*2024;

            std::string kamyk_str = std::to_string(result);

            nowe_kamyki.push_back(kamyk_str);


        }

    }

    kamyki.push_back(nowe_kamyki);
}




int main() {
    std::vector<std::deque<std::string>> kamyki = parsed();

    


    for(int blink = 0; blink < 25; blink++){
        physicsDefyingStones(kamyki, blink);

    }

    //printKamienie(kamyki);

    std::cout <<  "Liczba kamieni na końcu: " << kamyki.back().size() << std::endl; 
}
