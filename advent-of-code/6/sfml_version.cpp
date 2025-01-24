#include <SFML/Graphics.hpp>
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
    if (!file) {
        throw std::runtime_error("Nie można otworzyć pliku");
    }
    std::array<std::array<char, 130>, 130> data;

    for (int i = 0; i < 130; i++) {
        std::string line;
        std::getline(file, line);
        if (line.size() < 130) {
            throw std::runtime_error("Nieprawidłowa długość wiersza w wierszu " + std::to_string(i));
        }
        for (int j = 0; j < 130; j++) {
            data[i][j] = line[j];
        }
    }
    file.close();

    return data;
}

std::pair<int, int> findGuard(std::array<std::array<char, 130>, 130>& data) {
    for (int i = 0; i < 130; ++i) {
        for (int j = 0; j < 130; ++j) {
            if (data[i][j] == '^') {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

std::vector<std::pair<int, int>> directions = {{
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
}};

std::pair<int, int> operator+(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    return {a.first + b.first, a.second + b.second};
}

bool ifLeftMap(std::pair<int, int>& position) {
    int x = position.first;
    int y = position.second;

    return !(x < 0 || x >= 130 || y < 0 || y >= 130);
}

void move(auto& data, std::pair<int, int>& position, int& direction) {
    data[position.first][position.second] = 'X';

    std::pair<int, int> next_step = position + directions[direction];
    if (data[next_step.first][next_step.second] == '#') {
        direction = (direction + 1) % 4;
        position.first += directions[direction].first;
        position.second += directions[direction].second;
        counter++;
    } else {
        position = next_step;
    }
}

void drawMap(sf::RenderWindow& window, const std::array<std::array<char, 130>, 130>& map, const sf::Font& font) {
    for (int i = 0; i < 130; i++) {
        for (int j = 0; j < 130; j++) {
            sf::RectangleShape cell(sf::Vector2f(5.f, 5.f));  // 5x5 pixels per cell
            cell.setPosition(j * 5.f, i * 5.f);
            
            // Set color based on the content of the cell
            if (map[i][j] == '#') {
                cell.setFillColor(sf::Color::Green);  // Obstacle
            } else if (map[i][j] == 'X') {
                cell.setFillColor(sf::Color::Red);  // Visited
            } else if (map[i][j] == '^') {
                cell.setFillColor(sf::Color::Blue);  // Guard (up)
            } else {
                cell.setFillColor(sf::Color::White);  // Empty space
            }

            window.draw(cell);
        }
    }
}

int main() {
    std::array<std::array<char, 130>, 130> data = dataRead(path);
    std::pair<int, int> position = findGuard(data);

    // Initialize SFML window
    sf::RenderWindow window(sf::VideoMode(650, 650), "Guard Patrol");
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        std::cerr << "Nie można załadować czcionki!" << std::endl;
        return -1;
    }

    // Main game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (ifLeftMap(position)) {
            move(data, position, direction);
        }

        // Clear screen
        window.clear();

        // Draw the map
        drawMap(window, data, font);

        // Display the contents of the window
        window.display();
    }

    return 0;
}
