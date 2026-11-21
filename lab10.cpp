#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdint>
#include <initializer_list>

class Grupper {
    protected:
    std::vector<int> secret;
    public:
    Grupper(std::vector<int> values) : secret(std::move(values)) {
        std::sort(secret.begin(), secret.end());
    }
    virtual std::vector<std::vector<int>> sart(const int n) = 0;
    virtual ~Grupper() = default;

};

class SerpentGroupper : public Grupper {

    public:
    using Grupper::Grupper;
    std::vector<std::vector<int>> sart(const int n) override {
        std::vector<std::vector<int>> quack;
        for (int j = 0; j < n; j++) {
            quack.push_back(std::vector<int>());
        }
        int ciciq = 0;
        while (ciciq < (int)secret.size()) {
            for (int z = 0; z < n && ciciq < (int)secret.size(); z++) {
                quack[z].push_back(secret[ciciq]);
                ciciq++;
            }
        }
        return quack;

    }
    ~SerpentGroupper() = default;
};

class DefaultGrupper : public Grupper {
    public:
    using Grupper::Grupper;
    std::vector<std::vector<int>> sart(const int n) override {
        std::vector<std::vector<int>> quack(n);

        int ciciq = 0;
        int jyj = std::max(1, static_cast<int>(secret.size()) / n);
        int ganimed = 0;
        while (ciciq < static_cast<int>(secret.size()) && ganimed < n) {
            if (ciciq != 0 && ciciq % jyj == 0 && ganimed < n - 1) {
                ganimed++;
            }

            quack[ganimed].push_back(secret[ciciq]);
            ciciq++;
        }
        return quack;
    };
    ~DefaultGrupper() = default;
};

class BalancedGrupper : public Grupper {
public:
    using Grupper::Grupper;
    std::vector<std::vector<int>> sart(const int n) override {

        std::vector<std::vector<int>> quack(n);
        std::vector<int> sums(n, 0);

        for (int x : secret) {
            int siam = std::min_element(sums.begin(), sums.end()) - sums.begin();
            quack[siam].push_back(x);
            sums[siam] += x;
        }
        return quack;
    };
    ~BalancedGrupper() = default;
};



int main() {
    BalancedGrupper fly(std::vector<int>{13, 40, 12, 19, 30, 50, 90});
    std::vector<std::vector<int>> mixture = fly.sart(2);
    for (int i = 0; i < (int)mixture.size(); i++) {
        std::cout << "Group " << i << " (" << mixture[i].size() << "): ";
        for (int v : mixture[i]) std::cout << v << " ";
        std::cout << "\n";
    }
    return 0;
};