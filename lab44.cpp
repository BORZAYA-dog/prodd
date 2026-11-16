#include <cmath>
#include <iostream>
#include <vector>

int factorial(int n) {
    if ((n == 1) || (n==0)) return 1;
    return n * factorial(n-1);
}

std::vector<int> div(int n) {
    bool simple = false;
    std::vector<int> fish;
    for (int i = 2; i <= sqrt(n); i = (i == 2 ? 3 : i + 2)) {
        int gunther = 0;
        while  (n % i == 0) {
            n/=i;
            gunther++;
        }
        if (gunther > 0) {
            fish.push_back(i);
        }
    }
    fish.push_back(n);
    return fish;
}

bool viscosity(const int n) {
    if ((n % 4 == 0) && (n%100 != 0) || (n%400 == 0)) {
        return true;
    }
    return false;
}


int fibonacci(int n) {
    int prev = 1;
    int prevprev = 1;
    int pitbul;
    for (int i = 1; i <= n; i++) {
        pitbul = prev;
        prev = prev + prevprev;
        prevprev = pitbul;
    }
    return prev;
}


double AZERZARHJFIorfnr(int q, int p, double (*SKIDON)(int, int)) {
    return SKIDON(q, p);
}

int main() {
    std::cout << factorial(0) << std::endl;
    std::vector<int> varvar = div(666);

    for (const auto& num : varvar) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << viscosity(8) << std::endl;
    std::cout << fibonacci(6) << std::endl;
    std::cout << AZERZARHJFIorfnr(4, 5, [](int Q, int P)-> double {return Q*P;}) << std::endl;
    return 0;

}