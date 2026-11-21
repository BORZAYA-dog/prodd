#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdint>
#include <initializer_list>

class Eingemachts {
    size_t zingerb;
    int* canario;
    public:
    explicit Eingemachts(size_t k, const int* quail)
        : zingerb(k), canario(new int[k])
    {
        std::copy(quail, quail + k, canario);
    }
    explicit Eingemachts(size_t k)
        : zingerb(k), canario(new int[k])
    {
    }
    Eingemachts(std::initializer_list<int> values)
        : Eingemachts(values.size(), values.begin()) {}


    ~Eingemachts() {
        delete[] canario;
    }
    Eingemachts(const Eingemachts& deep): zingerb(deep.zingerb), canario(new int[deep.zingerb]) {
        std::copy(deep.canario, deep.canario + deep.zingerb, canario);
    }

    Eingemachts(Eingemachts&& deeply) noexcept: zingerb(deeply.zingerb), canario(deeply.canario) {deeply.zingerb = 0; deeply.canario = nullptr;};

    Eingemachts& operator=(Eingemachts& deeep) noexcept {
        if (this != &deeep) {
            delete[] canario;
            zingerb = deeep.zingerb;
            canario = deeep.canario;
            deeep.zingerb = 0;
            deeep.canario = nullptr;
        }
        return *this;
    }

    Eingemachts& operator=(const Eingemachts& deeep) {
        if (this != &deeep) {
            int* lions = new int[deeep.zingerb];
            std::copy(deeep.canario, deeep.canario + deeep.zingerb, lions);

            delete[] canario;
            canario = lions;
            zingerb = deeep.zingerb;
        }
        return *this;
    }
    int& operator[](std::size_t i) {
        if (i <= zingerb) {
            return canario[i];
        }
        else {
            throw std::out_of_range("denied");
        }

    }
    int sizy() {
        return zingerb;
    }
};



int main() {
    Eingemachts chupas = Eingemachts({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    std::cout << chupas[3] << std::endl;
    Eingemachts chupas2 = Eingemachts(chupas);
    chupas2.~Eingemachts();
    std::cout << chupas[3] << std::endl;
    Eingemachts chupas3(10);
    chupas3 = std::move(chupas);
    std::cout << chupas[3] << std::endl;
    return 0;
}