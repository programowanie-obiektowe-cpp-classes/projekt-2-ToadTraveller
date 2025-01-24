#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <numeric>
#include <unordered_map>
using namespace std;




struct Coordinates {
	vector<int> column1;
	vector<int> column2;
};

Coordinates readCsvArrays() {

	Coordinates result;
	

	ifstream file("/home/bimberiev/Desktop/advent-of-code/1/input_day1.txt");
	if (!file.is_open()){
		throw runtime_error("Nie można otworzyć pliku!");
	}


	string line;

	while (getline(file, line)) {
		stringstream ss(line);
		int cell1, cell2;

		//odczytanie pierwszej kolumny
		if (ss >> cell1) {
			result.column1.push_back(cell1);
		}

		//odczytanie drugiej kolumny, pomija przecinek i idzie dalej
		if (ss.ignore(1) && ss >> cell2) {
			result.column2.push_back(cell2);
		}

	}

	//std::cout << "Liczba elementów w kolumnie 1: " << result.column1.size() << endl;
	//std::cout << "Liczba elementów w kolumnie 2: " << result.column2.size() << endl;

/*
	cout << "Kolumna 1:" << endl;
	for(int num : result.column1){
		cout << num << endl;
	}
	cout << "Kolumna 2:" << endl;
	for(int num : result.column2){
		cout << num << endl;
	}

*/
	file.close();
	return result;
};



int Distance(const Coordinates& input_data ){
	vector<int> dist(input_data.column1.size()) ;
	int total;
	for (size_t i = 0; i < input_data.column1.size(); ++i){

		dist[i] = abs(input_data.column1[i] - input_data.column2[i]);
	}
/*
	std::cout << "Dystans:" << endl;

	for(int num : dist){
		std::cout << num << endl;
	}
*/
	total = std::accumulate(dist.begin(), dist.end(), 0);
	return total;
}


int similarityScore(const vector<int>& left, const vector<int>& right){
	std::unordered_map<int, int> right_count;
	int score = 0;

	for(const auto& id : right){
		//tworzone są komórki mapy z kluczem id
		// wartość każdej komórki to to ile razy się dane id powtarza w rght
		right_count[id] ++;
	}

	for (const auto& id : left){
		if (right_count.find(id) !=right_count.end()){
			score += id * right_count[id];
		}
	}


	return score;
}







int main() {
	
	Coordinates input_data = readCsvArrays();
	sort(input_data.column1.begin(), input_data.column1.end());
	vector<int>& left = input_data.column1;
	sort(input_data.column2.begin(), input_data.column2.end());
	vector<int>& right = input_data.column2;
	
	/*
	std::cout << "Kolumna 1:" << endl;
	for(int num : input_data.column1){
		std::cout << num << endl;
	}
	std::cout << "Kolumna 2:" << endl;
	for(int num : input_data.column2){
		std::cout << num << endl;
	}
	*/

	int sum = Distance(input_data);

    std::cout << "Suma elementów: " << sum << endl;

	int score = similarityScore(left, right);
    std::cout << "Similarity Score: " << score << endl;



}
