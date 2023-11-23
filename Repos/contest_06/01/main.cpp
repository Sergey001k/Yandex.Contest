#include <iostream>
#include <vector>
#include <cmath>

const double PI = acos(-1.0);


class Shape
{
public:
    virtual double getPerimeter() const {
        return 0.0;
    }
     
};


class Rectangle : public Shape 
{
private:
    int a, b;
public:
    
    Rectangle(int a, int b) {
        this->a = a;
        this->b = b;

    }

    double getPerimeter() const override{
        return (a + b)*2;
    }

};

class Circle : public Shape
{
private:
    int r;
public:

    Circle(int r) {
        this->r = r;
    }

    double getPerimeter() const override {
        return 2 * PI * r;
    }
};

class Triangle : public Shape 
{
private:
    int a, b, c;

public:

    Triangle(int a, int b, int c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    double getPerimeter() const override{
        if ((a + b) <= c || (b + c) <= a || (a + c) <= b || (a == (b + c))){
            return 0;
        }
        
        
        return a+b+c;
    }

};


int main() {
    int momentum;
    std::cin >> momentum;
    srand(momentum);
    std::vector <Shape*> shapes(rand() % 100 + 1);
    for (int i = 0; i < shapes.size(); i++) {
        int a = rand() % 10 + 1, b = rand() % 10 + 1, c = rand() % 10 + 1;
        if (rand() % 3 == 0) shapes[i] = new Rectangle(a, b);
        else if (rand() % 3 == 1) shapes[i] = new Circle(c);
        else shapes[i] = new Triangle(a, b, c);
    }

    double sum = 0;
    for (auto shape : shapes) { sum += shape->getPerimeter(); }
    std::cout << (int)sum;
}