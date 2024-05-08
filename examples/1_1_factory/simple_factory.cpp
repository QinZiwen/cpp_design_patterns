#include "common/common.h"

class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    virtual void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

class Rectangle : public Shape {
public:
    virtual void draw() override {
        std::cout << "Drawing a rectangle" << std::endl;
    }
};

class ShapeFactory {
public:
    static Shape* createShape(const std::string type) {
        if (type == "circle") {
            return new Circle();
        } else if (type == "rectangle") {
            return new Rectangle();
        }
        return nullptr;
    }
};

int main() {
    Shape* circle = ShapeFactory::createShape("circle");
    circle->draw();  // Êä³ö£ºDrawing a circle

    Shape* rectangle = ShapeFactory::createShape("rectangle");
    rectangle->draw();  // Êä³ö£ºDrawing a rectangle

    delete circle;
    delete rectangle;

    return 0;
}