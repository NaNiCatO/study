#include <iostream>
#include <sstream>
#include <memory>
#include <vector>
#include <algorithm>
#include <cmath>

class Shape {
public:
    virtual double area() const = 0;
    virtual void read(std::istream&) = 0;
    virtual void print(std::ostream&) const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    Circle() : x(50), y(50), r(10) {}
    Circle(double x, double y, double r) : x(x), y(y), r(r) {}
    double area() const override { return 3.14 * r * r; }
    void read(std::istream& is) override {
        is >> x >> y >> r;
    }
    void print(std::ostream& os) const override {
        os << "[Circle: (" << x << ", " << y << ", " << r << ")]";
    }
private:
    double x, y, r;
};

class Rectangle : public Shape {
public:
    Rectangle() : x(45), y(45), w(10), h(10) {}
    Rectangle(double x, double y, double w, double h) : x(x), y(y), w(w), h(h) {}
    double area() const override { return w * h; }
    void read(std::istream& is) override {
        is >> x >> y >> w >> h;
    }
    void print(std::ostream& os) const override {
        os << "[Rectangle: (" << x << ", " << y << ", " << w << ", " << h << ")]";
    }
private:
    double x, y, w, h;
};

int main() {
    std::istringstream iss("C 50 50 15 R 40 40 20 20");
    std::vector<std::unique_ptr<Shape>> shapes;

    while (iss) {
        char shape_type;
        iss >> shape_type;
        if (shape_type == 'C') {
            shapes.emplace_back(std::make_unique<Circle>());
            shapes.back()->read(iss);
        } else if (shape_type == 'R') {
            shapes.emplace_back(std::make_unique<Rectangle>());
            shapes.back()->read(iss);
        }
    }

    std::sort(shapes.begin(), shapes.end(), [](const std::unique_ptr<Shape>& a, const std::unique_ptr<Shape>& b) {
        return a->area() < b->area();
    });

    for (const auto& shape : shapes) {
        shape->print(std::cout);
        std::cout << std::endl;
    }

}