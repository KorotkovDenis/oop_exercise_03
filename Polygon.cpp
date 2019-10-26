#include <iostream>
#include <vector>
#include <array>
#include <math.h>
#include <exception>
#include "Polygon.hpp"


void Triangle::print (std::ostream& os) const {
    os << "Triangle" << ':';
    for (int i = 0; i < vertexes.size(); ++i) {
        os << vertexes[i].x << ' ' << vertexes[i].y << ' ';
    }
    os << '\n';
}


Point Triangle::center() const {
    Point ans = {0, 0};
    for (int i = 0; i < 3; ++i) {
        ans.x += vertexes[i].x;
        ans.y += vertexes[i].y;
    }
    ans = {ans.x / 3, ans.y / 3};
    return ans;
}


double Triangle::area() const {
    Point vec1 = {vertexes[1].x - vertexes[0].x, vertexes[1].y - vertexes[0].y};
    Point vec2 = {vertexes[2].x - vertexes[0].x, vertexes[2].y - vertexes[0].y};
    double ans = fabs(vec1.x * vec2.y - vec2.x * vec1.y);
    return ans / 2;
}


Triangle::Triangle (std::istream& is) {
    for (int i = 0; i < vertexes.size(); ++i) {
        is >> vertexes[i].x >> vertexes[i].y;
    }
    if (area() == 0) {
        throw std::logic_error("non pravilni");
    }
}


void Triangle::scan (std::istream& is) {
    for (int i = 0; i < vertexes.size(); ++i) {
        is >> vertexes[i].x >> vertexes[i].y;
    }
    if (area() == 0) {
        throw std::logic_error("non pravilni");
    }
}


void Square::print (std::ostream& os) const {
    os << "Square" << ':';
    for (int i = 0; i < vertexes.size(); ++i) {
        os << vertexes[i].x << ' ' << vertexes[i].y << ' ';
    }
    os << '\n';
}


Point Square::center() const {
    Point ans = {0, 0};
    for (int i = 0; i < vertexes.size(); ++i) {
        ans.x += vertexes[i].x;
        ans.y += vertexes[i].y;
    }
    ans = {ans.x / 4, ans.y / 4};
    return ans;
}


double Square::area() const {
    Point vec1 = {vertexes[1].x - vertexes[0].x, vertexes[1].y - vertexes[0].y};
    Point vec2 = {vertexes[2].x - vertexes[0].x, vertexes[2].y - vertexes[0].y};
    double ans = fabs(vec1.x * vec2.y - vec2.x * vec1.y);
    std::cout << ans << '\n';
    return ans;
}


Square::Square (std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        is >> vertexes[i].x >> vertexes[i].y;
    }
    //for (int i = 0; i < 4; ++i) {
        //std::cout << vertexes[i].x << ' ' <<  vertexes[i].y << '\n';
    //}
    Point vec1 {vertexes[1].x - vertexes[0].x, vertexes[1].y - vertexes[0].y};
    Point vec2 {vertexes[2].x - vertexes[1].x, vertexes[2].y - vertexes[1].y};
    Point vec3 {vertexes[3].x - vertexes[2].x, vertexes[3].y - vertexes[2].y};
    Point vec4 {vertexes[0].x - vertexes[3].x, vertexes[0].y - vertexes[3].y};
    double l1 = vec1.x * vec1.x + vec1.y * vec1.y;
    double l2 = vec2.x * vec2.x + vec2.y * vec2.y;
    double l3 = vec3.x * vec3.x + vec3.y * vec3.y;
    double l4 = vec4.x * vec4.x + vec4.y * vec4.y;
    //std::cout << vec1.x << ' ' << vec1.y << '\n';
    //std::cout << l1 << ' ' << l2 << ' ' << l3 << ' ' << l4;
    if (!(l1 == l2 && l2 == l3 && l3 == l4) || !(vec1.x * vec2.x + vec1.y * vec2.y == 0)) {
        throw std::logic_error("non pravilni");
    }
}


void Square::scan (std::istream& is) {
    for (int i = 0; i < 4; ++i) {
        is >> vertexes[i].x >> vertexes[i].y;
    }
    Point vec1 {vertexes[1].x - vertexes[0].x, vertexes[1].y - vertexes[0].y};
    Point vec2 {vertexes[2].x - vertexes[1].x, vertexes[2].y - vertexes[1].y};
    Point vec3 {vertexes[3].x - vertexes[2].x, vertexes[3].y - vertexes[2].y};
    Point vec4 {vertexes[0].x - vertexes[3].x, vertexes[0].y - vertexes[3].y};
    double l1 = vec1.x * vec1.x + vec1.y * vec1.y;
    double l2 = vec2.x * vec2.x + vec2.y * vec2.y;
    double l3 = vec3.x * vec3.x + vec3.y * vec3.y;
    double l4 = vec4.x * vec4.x + vec4.y * vec4.y;
    if (!(l1 == l2 && l2 == l3 && l3 == l4) || !(vec1.x * vec2.x + vec1.y * vec2.y == 0)) {
        throw std::logic_error("non pravilni");
    }
}


void Rectangle::print (std::ostream& os) const {
    os << "Rectangle" << ':';
    for (int i = 0; i < vertexes.size(); ++i) {
        os << vertexes[i].x << ' ' << vertexes[i].y << ' ';
    }
    os << '\n';
}


Point Rectangle::center() const {
    Point ans = {0, 0};
    for (int i = 0; i < vertexes.size(); ++i) {
        ans.x += vertexes[i].x;
        ans.y += vertexes[i].y;
    }
    ans = {ans.x / 4, ans.y / 4};
    return ans;
}


double Rectangle::area() const {
    Point vec1 = {vertexes[1].x - vertexes[0].x, vertexes[1].y - vertexes[0].y};
    Point vec2 = {vertexes[2].x - vertexes[0].x, vertexes[2].y - vertexes[0].y};
    double ans = fabs(vec1.x * vec2.y - vec2.x * vec1.y);
    return ans;
}


Rectangle::Rectangle (std::istream& is) {

    for (int i = 0; i < vertexes.size(); ++i) {
        is >> vertexes[i].x >> vertexes[i].y;
    }
    Point vec1 = {vertexes[1].x - vertexes[0].x, vertexes[1].y - vertexes[0].y};
    Point vec2 = {vertexes[2].x - vertexes[1].x, vertexes[2].y - vertexes[1].y};
    Point vec3 = {vertexes[3].x - vertexes[2].x, vertexes[3].y - vertexes[2].y};
    Point vec4 = {vertexes[0].x - vertexes[3].x, vertexes[0].y - vertexes[3].y};
    double l1 = vec1.x * vec1.x + vec1.y * vec1.y;
    double l2 = vec2.x * vec2.x + vec2.y * vec2.y;
    double l3 = vec3.x * vec3.x + vec3.y * vec3.y;
    double l4 = vec4.x * vec4.x + vec4.y * vec4.y;
    if (!(l1 == l3 && l2 == l4) || !(vec1.x * vec2.x + vec1.y * vec2.y == 0)) {
        throw std::logic_error("non pravilni");
    }
}


void Rectangle::scan (std::istream& is) {
    for (int i = 0; i < vertexes.size(); ++i) {
        is >> vertexes[i].x >> vertexes[i].y;
    }
    Point vec1 = {vertexes[1].x - vertexes[0].x, vertexes[1].y - vertexes[0].y};
    Point vec2 = {vertexes[2].x - vertexes[1].x, vertexes[2].y - vertexes[1].y};
    Point vec3 = {vertexes[3].x - vertexes[2].x, vertexes[3].y - vertexes[2].y};
    Point vec4 = {vertexes[0].x - vertexes[3].x, vertexes[0].y - vertexes[3].y};
    double l1 = vec1.x * vec1.x + vec1.y * vec1.y;
    double l2 = vec2.x * vec2.x + vec2.y * vec2.y;
    double l3 = vec3.x * vec3.x + vec3.y * vec3.y;
    double l4 = vec4.x * vec4.x + vec4.y * vec4.y;
    if (!(l1 == l3 && l2 == l4) || !(vec1.x * vec2.x + vec1.y * vec2.y == 0)) {
        throw std::logic_error("non pravilni");
    }
}


Triangle::Triangle () {
    Point a = {0, 0};
    for (int i = 0; i < 3; ++i) {
        vertexes[i] = a;
    }
}


Square::Square () {
    Point a = {0, 0};
    for (int i = 0; i < 4; ++i) {
        vertexes[i] = a;
    }
}


Rectangle::Rectangle () {
    Point a = {0, 0};
    for (int i = 0; i < 4; ++i) {
        vertexes[i] = a;
    }
}


std::istream& operator>> (std::istream& is, Polygon& m) {
    m.scan(is);
    return is;
}


std::ostream& operator<< (std::ostream& os, const Polygon& m) {
    m.print(os);
    return os;
}