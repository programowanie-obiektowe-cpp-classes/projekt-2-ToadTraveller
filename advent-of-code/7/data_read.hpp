#ifndef DATAREAD_HPP
#define DATAREAD_HPP

#include <iostream>
#include <string>
#include <vector>

void print(const std::vector<std::pair<int, std::vector<int>>>& data);

std::vector<std::pair<int, std::vector<int>>> dataRead(const std::string& path);

#endif //DATAREAD_HPP