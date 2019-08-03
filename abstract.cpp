#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;

class Point{
    private:
        int x;
        int y;
    public:
        //default constructor
        Point(): x(0), y(0) {}
        Point(int init_x, int init_y): x(init_x), y(init_x){}
        void setPoint(int a, int b){
            x = a;
            y = b;
        }
        int getX(void) const{
            return x;
        }
        int getY(void) const{
            return y;
        }
        void printPoint(void){
            cout<<"("<<x<<","<<y<<")"<<endl;
        }
        Point operator + (const Point& rhs) const{
            Point ans;
            ans.x = x + rhs.x;
            ans.y = y + rhs.y;
            return ans;
        } 
        Point & operator += (const Point & rhs){
            x += rhs.x;
            y += rhs.y;
            return *this;
        }
        double getDistance(const Point & obj) const{
            return sqrt(pow(double(x-obj.x),2) + pow(double(y-obj.y),2));
        }
        double getSlope(const Point & obj) const{
            return (y-obj.y)/(x-obj.x);
        }
};

class Shape{
    public:
        // Declaration of an abstract method (aka pure virtual member function)
        virtual bool containsPoint(const Point & p) const = 0;
};


int main(){
    return EXIT_SUCCESS;
}
