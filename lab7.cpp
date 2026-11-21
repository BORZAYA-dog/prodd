#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstdint>

enum class Haters: std::uint8_t  {Made, Paid, Send, Delivered, Cancelled };

struct Optical {
    Haters typo;
    int aidi;
    int cost;

    inline static std::vector<int> uniqas {};

    Optical(Haters status, int id, int cost)
        : typo(status), aidi(id), cost(cost)
    {
        if (std::find(uniqas.begin(), uniqas.end(), id)
            != uniqas.end()) {
            throw std::invalid_argument("denied.");
            }

        uniqas.push_back(id);
    }

};

void change(Optical& order, Haters squid) {
    if (!((order.typo == Haters::Cancelled) || (order.typo == Haters::Delivered))) {
        switch (squid) {
            case Haters::Paid:
                order.typo = (order.typo == Haters::Made) ? Haters::Paid : order.typo;
                break;
            case Haters::Send:
                order.typo = (order.typo == Haters::Paid) ? Haters::Send : order.typo;
                break;
            case Haters::Delivered:
                order.typo = (order.typo == Haters::Send) ? Haters::Delivered : order.typo;
                break;
            case Haters::Cancelled:
                order.typo = (order.typo != Haters::Send) ? Haters::Cancelled : order.typo;
                break;
            default:
                break;
        }
    }
}

void printajo( Haters& xenia) {
    switch (xenia) {
        case Haters::Made:
            std::cout << "Maid" << std::endl;
            break;
        case Haters::Paid:
            std::cout << "Paid" << std::endl;
            break;
        case Haters::Send:
            std::cout << "Send" << std::endl;
            break;
        case Haters::Delivered:
            std::cout << "Delivered" << std::endl;
            break;
        case Haters::Cancelled:
            std::cout << "Cancelled" << std::endl;
            break;
        default:
            break;
    }
}



int main() {
    Optical the_harper = {Haters::Made, 13, 19};
    change(the_harper, Haters::Delivered);
    change(the_harper, Haters::Cancelled);
    change(the_harper, Haters::Delivered);
    printajo(the_harper.typo);
    Optical jinlar = {Haters::Made, 15, 19};
    change(jinlar, Haters::Paid);
    change(jinlar, Haters::Send);
    change(jinlar, Haters::Delivered);
    change(jinlar, Haters::Cancelled);
    printajo(jinlar.typo);
    return 0;
}