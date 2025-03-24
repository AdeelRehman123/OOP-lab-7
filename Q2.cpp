#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string color;
    int positionX, positionY;
    double borderThickness;

public:
    Shape(int x, int y, string col, double border = 1.0)
        : positionX(x), positionY(y), color(col), borderThickness(border) {}

    virtual ~Shape() {}

    virtual void draw() const {
        cout << "Drawing a shape at (" << positionX << ", " << positionY << ") with color " << color << endl;
    }

    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(int x, int y, string col, double rad)
        : Shape(x, y, col), radius(rad) {}

    void draw() const override {
        cout << "Drawing a Circle at (" << positionX << ", " << positionY << ") with radius " << radius << " and color " << color << endl;
    }

    double calculateArea() const override {
        return M_PI * radius * radius;
    }

    double calculatePerimeter() const override {
        return 2 * M_PI * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(int x, int y, string col, double w, double h)
        : Shape(x, y, col), width(w), height(h) {}

    void draw() const override {
        cout << "Drawing a Rectangle at (" << positionX << ", " << positionY << ") with width " << width
             << ", height " << height << " and color " << color << endl;
    }

    double calculateArea() const override {
        return width * height;
    }

    double calculatePerimeter() const override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
private:
    double sideA, sideB, sideC;

public:
    Triangle(int x, int y, string col, double a, double b, double c)
        : Shape(x, y, col), sideA(a), sideB(b), sideC(c) {}

    void draw() const override {
        cout << "Drawing a Triangle at (" << positionX << ", " << positionY << ") with sides "
             << sideA << ", " << sideB << ", " << sideC << " and color " << color << endl;
    }

    double calculateArea() const override {
        double s = (sideA + sideB + sideC) / 2;
        return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
    }

    double calculatePerimeter() const override {
        return sideA + sideB + sideC;
    }
};

class Polygon : public Shape {
private:
    int sides;
    double sideLength;

public:
    Polygon(int x, int y, string col, int s, double length)
        : Shape(x, y, col), sides(s), sideLength(length) {}

    void draw() const override {
        cout << "Drawing a Polygon with " << sides << " sides at (" << positionX << ", " << positionY
             << ") with side length " << sideLength << " and color " << color << endl;
    }

    double calculateArea() const override {
        if (sides < 3) return 0;
        return (sides * sideLength * sideLength) / (4 * tan(M_PI / sides));
    }

    double calculatePerimeter() const override {
        return sides * sideLength;
    }
};

int main() {
    Circle c(10, 10, "Red", 5);
    Rectangle r(0, 0, "Blue", 10, 20);
    Triangle t(5, 5, "Green", 3, 4, 5);
    Polygon p(2, 2, "Yellow", 6, 4);

    cout << "\n--- Shape Operations ---\n";
    c.draw();
    cout << "Area: " << c.calculateArea() << ", Perimeter: " << c.calculatePerimeter() << "\n\n";

    r.draw();
    cout << "Area: " << r.calculateArea() << ", Perimeter: " << r.calculatePerimeter() << "\n\n";

    t.draw();
    cout << "Area: " << t.calculateArea() << ", Perimeter: " << t.calculatePerimeter() << "\n\n";

    p.draw();
    cout << "Area: " << p.calculateArea() << ", Perimeter: " << p.calculatePerimeter() << "\n";

    return 0;
}
