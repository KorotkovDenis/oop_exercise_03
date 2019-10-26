#ifndef __POLYGON__
#define __POLYGON__

#include <iostream>
#include <array>

struct Point {
    double x;
    double y;
    Point() {x = 0; y = 0;}
    Point(double a, double b) {x = a; y = b;}
};


struct Polygon {
public:
    virtual ~Polygon() {}
    virtual void print (std::ostream& os) const = 0;
    virtual void scan (std::istream& is) = 0;
    virtual Point center() const = 0;
    virtual double area() const = 0;
};


struct Triangle : public Polygon {
public:
    Triangle ();
    Triangle (std::istream& is);
    void print (std::ostream& os) const override;
    void scan (std::istream& is) override;
    Point center() const override;
    double area() const override;
    ~Triangle() {}
private:
    std::array<Point, 3> vertexes;
};


struct Square : public Polygon {
public:
    Square ();
    Square (std::istream& is);
    void print (std::ostream& os) const override;
    void scan (std::istream& is) override;
    Point center() const override;
    double area() const override;
    ~Square() {}
private:
    std::array<Point, 4> vertexes;
};


struct Rectangle : public Polygon {
public:
    Rectangle ();
    Rectangle (std::istream& is);
    void print (std::ostream& os) const override;
    void scan (std::istream& is) override;
    Point center() const override;
    double area() const override;
    ~Rectangle() {}
private:
    std::array<Point, 4> vertexes;
};


std::istream& operator>> (std::istream& is, Polygon& m);
std::ostream& operator<< (std::ostream& os, const Polygon& m);


#endif