#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>
using namespace std;


class Shape{
    public:
        // Declaration of an abstract method (aka pure virtual member function)
        virtual double getArea() const = 0;
        // Destructor, also needs to be virtual
        virtual ~Shape() {}
};

class Rectangle: public Shape{
    private:
        double width;
        double height;
    public:
        // Constructor with parameters
        Rectangle(double w, double h): width(w), height(h) {}
        // A concrete implementation of the inherited abstract method
        virtual double getArea() const{
            return width * height;
        }
};

class Triangle: public Shape{
    private:
        double base;
        double height;
    public:
        // Constructor with parameters
        Triangle(double b, double h): base(b), height(h) {}
        // Another concrete implementation of the inherited abstract method
        virtual double getArea() const{
            return 0.5 * base * height;
        }
};

// Use a macro to define the invariable pi
#define PI 3.1415926535
class Circle: public Shape{
    private:
        double radius;
    public:
        // Constructor with parameter
        // Note this constructor should be declared explicit
        // since it only takes one parameter
        explicit Circle(double r): radius(r) {}
        // Yet another concrete implementation of the inherited abstract method
        virtual double getArea() const{
            return PI * radius * radius;
        }
};

double sumAreas(const vector<Shape *> & shapes){
    // Use const_iterator instead of iterator to
    // avoid accidentally modifying data
    vector<Shape *>::const_iterator it = shapes.begin();
    double answer = 0;
    while(it != shapes.end()){
        // Subtype polymorphism can only be utilized
        // via pointers or references
        Shape * ptr = *it;
        // getArea() will be dynamically dispatched
        // based on the dynamic type
        answer += ptr->getArea();
        ++it;
    }
    return answer;
}

int main(){
    vector<Shape *> v;
    v.push_back(new Rectangle(2, 2));
    v.push_back(new Circle(1));
    v.push_back(new Triangle(1,2));
    cout<<sumAreas(v)<<endl;
    vector<Shape *>::iterator it = v.begin();
    while(it != v.end()){
        delete *it;
        ++it;
    }
    return EXIT_SUCCESS;
}
