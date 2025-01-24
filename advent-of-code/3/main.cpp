#include "data_read.hpp"
#include <iostream>
#include <string>
#include <algorithm>


bool isDigit(const std::string& str){
    return !str.empty() && std::all_of(str.begin(), str.end(), ::isdigit);
}

//funkcja do wydobywnia liczb z instrukcji 'mul(X,Y)'
int parseNumber(const std::string& str){
    int num = 0;
    for(char c : str){
        if(isdigit(c)) {
            //wydłubuje po jednej cyfrze, co jeżeli x/y to ciąg cyfr np. 12
            num = num*10 + (c - '0'); 
        }
    }
    
    return num;
}




long long sumOfMul(const std::string& input){
    //przechowuje sume wyników mnożenia
    long long sum = 0;
    //indeks ciągu input, który oznacza aktualną pozycję podczas wyszukiwania
    size_t pos = 0;
   
    
    //find szuka wystąpienia mul(, jeśli zadziała to funkcja zwraca pozucję pierwszego znaku 'm' tego ciągu
    //petla działa dopóty, dopóki find nie zwróci wartości std::string::npos - koniec ciągu
    while ((pos = input.find("mul(", pos)) != std::string::npos) {
   
        //po znalezieniu 'mul(' funkcja szuka znaku ')', który oznacza koniec instrukcji
        size_t closePos = input.find(')', pos);
        if (closePos == std::string::npos) {
            break;
        }
        //jeśli closePos nie jest równy std::string:;npos to git
        
        std::string params = input.substr(pos + 4, closePos - (pos + 4));
        size_t posm = params.find("mul(");
        if (posm != std::string::npos){
            std::cout << "Wykryto nieprawidłą instrukcję w params. Resetowanie." << std::endl;
            pos = pos + 4 + posm;
            continue;

        }
        size_t commaPos = params.find(',');
        if (commaPos != std::string::npos ){
            std::string num1 = params.substr(0, commaPos);
            std::string num2 = params.substr(commaPos + 1);
            std::cout << "Przed konwersją: X: " << num1 << " Y: "<< num2 <<std::endl;

            if(isDigit(num1) && isDigit(num2)){
                int X = parseNumber(num1);
                int Y = parseNumber(num2);
                std::cout << "X: " << num1 << " Y: "<< num2 <<std::endl;
                sum += X*Y;
                std::cout << sum << std::endl; 
                
            }
                
        }
        pos = closePos + 1;
    }
    
    return sum;
}
int main(){

    std::string path = "/home/bimberiev/Desktop/advent-of-code/3/input3.txt" ;
    std::string input = dataRead(path);
    long long result = sumOfMul(input);

    std::cout << "Suma wszystkiech wyników mnożenia: " << result << std::endl;

    return 0;
}
