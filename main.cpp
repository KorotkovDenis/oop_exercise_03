#include <iostream>
#include <vector>
#include <array>
#include <math.h>
#include "Polygon.hpp"



int main() {
    std::vector <Polygon*> data;
    char st;
    char figure;
    int ind;
    Polygon* f;
    std::cout.precision(3);
    while (1) {
        std::cin >> st;
        if (st == 'q') {
            break;
        } else if (st == 'a') {
            std::cin >> figure;
            if (figure == 't') {
                f = new Triangle(std::cin);
                data.push_back(f);
            } else if (figure == 's') {
                f = new Square(std::cin);
                data.push_back(f);
            } else if (figure == 'r') {
                f = new Rectangle(std::cin);
                data.push_back(f);
            } else {
                std::cout << "invalid command" << '\n';
            }
        } else if (st == 'd') {
            std::cin >> ind;
            delete(data[ind]);
            data.erase(data.begin() + ind);
        } else if (st == 'p') {
            for (int i = 0; i < data.size(); ++i) {
                data[i]->print(std::cout);
            }
        } else if (st == 's') {
            for (int i = 0; i < data.size(); ++i) {
                std::cout << data[i]->area() << '\n';
            }
        } else if (st == 'c') {
            for (int i = 0; i < data.size(); ++i) {
                Point cntr = data[i]->center();
                std::cout << cntr.x << ' ' << cntr.y << '\n';
            }
        } else {
            std::cout << "invalid command" << '\n';
        }
    }
    for (int i = 0; i < data.size(); ++i) {
        delete data[i];
    }
}