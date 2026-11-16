#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>


int main() {
    std::string carlos;
    std::cin >> carlos;
    std::vector<int> century;
    std::getline(std::cin >> std::ws, carlos);
    std::stringstream ss(carlos);
    int verlidog;
    while (ss >> verlidog) {
        century.emplace_back(verlidog);
    }
    century.erase(std::remove_if(century.begin(), century.end(),[](int x) {return x < 0;}), century.end());
    std::sort(century.begin(), century.end());
    for (int j: century) {
        std::cout << j << " ";
    }
}