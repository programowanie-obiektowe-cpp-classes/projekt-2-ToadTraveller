#include <iostream>
#include <string>
#include <vector>
#include <ranges>
#include <sstream>
#include <deque>
#include <thread>
#include <mutex>
#include <future>

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

void removeLeadingZeros(std::string& kamyk) {
    size_t first_non_zero = kamyk.find_first_not_of('0');
    if (first_non_zero == std::string::npos) {
        kamyk = "0";
    } else {
        kamyk = kamyk.substr(first_non_zero);
    }
}

void processChunk(const std::deque<std::string>& kamyki_blink, std::deque<std::string>& nowe_kamyki, size_t start, size_t end) {
    for (size_t i = start; i < end; ++i) {
        const std::string& kamyk = kamyki_blink[i];

        if (kamyk == "0") {
            nowe_kamyki.push_back("1");
        } else if (kamyk.size() % 2 == 0) {
            size_t split_pos = kamyk.size() / 2;

            std::string kamyk1 = kamyk.substr(0, split_pos);
            std::string kamyk2 = kamyk.substr(split_pos);

            removeLeadingZeros(kamyk1);
            removeLeadingZeros(kamyk2);

            nowe_kamyki.push_back(kamyk1);
            nowe_kamyki.push_back(kamyk2);
        } else {
            long long kamyk2 = std::stoll(kamyk);
            long long result = kamyk2 * 2024;
            nowe_kamyki.push_back(std::to_string(result));
        }
    }
}

void physicsDefyingStones(std::vector<std::deque<std::string>>& kamyki, const int& blink, int thread_count = 8) {
    const std::deque<std::string>& kamyki_blink = kamyki.at(blink);
    size_t total_size = kamyki_blink.size();
    size_t chunk_size = (total_size + thread_count - 1) / thread_count;

    std::vector<std::future<std::deque<std::string>>> futures;

    for (int t = 0; t < thread_count; ++t) {
        size_t start = t * chunk_size;
        size_t end = std::min(start + chunk_size, total_size);

        futures.push_back(std::async(std::launch::async, [&, start, end]() {
            std::deque<std::string> chunk_results;
            processChunk(kamyki_blink, chunk_results, start, end);
            return chunk_results;
        }));
    }

    std::deque<std::string> nowe_kamyki;
    for (auto& future : futures) {
        std::deque<std::string> chunk_results = future.get();
        nowe_kamyki.insert(nowe_kamyki.end(), chunk_results.begin(), chunk_results.end());
    }

    kamyki.push_back(nowe_kamyki);
}

int main() {
    std::vector<std::deque<std::string>> kamyki = parsed();

    for (int blink = 0; blink < 50; blink++) {
        physicsDefyingStones(kamyki, blink, 8); // Liczba wątków ustawiona na 4
    }

    std::cout << "Liczba kamieni na końcu: " << kamyki.back().size() << std::endl; 
}
