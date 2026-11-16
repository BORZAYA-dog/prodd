#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

template <typename T>
class secret_vector {
    public: std::vector<T> container01;
    secret_vector(const std::vector<T>& container01): container01(container01) {};
    secret_vector() = default;

    auto operator+(const secret_vector<T>& v1) {
        if (v1.container01.size() != container01.size()) {
            throw std::invalid_argument("denied size.");
        }
        std::vector<T> baylando;
        baylando.reserve(v1.container01.size());
        for (int i = 0; i < v1.container01.size(); i++) {
            baylando.push_back(container01[i] + container01[i]);
        }
        return baylando;
    }

    auto operator*(const secret_vector<T>& v1) {
        if (v1.container01.size() != container01.size()) {
            throw std::invalid_argument("denied size.");
        }
        std::vector<T> baylando;
        baylando.reserve(v1.container01.size());
        for (int i = 0; i < v1.container01.size(); i++) {
            baylando.push_back(container01[i] * v1.container01[i]);
        }
        return baylando;
    }

    template <typename A>
    auto operator*(const A lambda) {
        using R = decltype(T{} * A{});
        std::vector<R> baylando;
        baylando.reserve(container01.size());
        for (int i = 0; i < container01.size(); i++) {
            baylando.push_back(container01[i] * lambda);
        }
        return baylando;
    }

    bool operator==(const secret_vector<T>& v1) {
        if (v1.container01.size() != container01.size()) {
            throw std::invalid_argument("denied size.");
        }
        bool sayan_dog = true;
        for (int i = 0; i < v1.container01.size(); i++) {
            if (container01[i] != v1.container01[i]) {
                sayan_dog = false;
                break;
            }
        }
        return sayan_dog;
    }
    auto normal() {
        auto savage = container01.front();
        savage = savage*savage;
        for (int i = 1; i < container01.size(); i++) {
            savage += container01[i]*container01[i];
        }
        return sqrt(savage);
    }

};

template <typename T>
std::ostream& operator<<(std::ostream& aut, const secret_vector<T>& v) {
    for (auto k: v.container01) {
        aut << k << ",";
    }
    return aut;
}




int main() {
    secret_vector<double> v1 = secret_vector<double>({1, 2, 3, 4, 5});
    secret_vector<double> v2 = secret_vector<double>({1, 2, 3, 4, 0});
    secret_vector<double>  squirrel = v1*v2;
    std::cout << squirrel << std::endl;
    bool truth = v1==v2;
    std::cout<< "" << std::endl;
    std::cout<< truth << std::endl;
    std::cout<< v1.normal() << std::endl;
    return 0;
}