#include <iostream>
using namespace std;

class Point{
    private:
        int x;
        int y;
    public:
        // Constructor without parameters
        Point(): x(0), y(0){}
        // Constructor with parameters
        Point(int init_x, int init_y): x(init_x), y(init_y){}
        // Print out a type Point object
        void printPoint(void){
            cout<<"("<<x<<","<<y<<")"<<endl; 
        }
};

class Polygon{
    private:
        Point * points;
        size_t numPoints;
    public:
        // Constructor without parameters
        Polygon(): points(NULL), numPoints(0){}
        // Constructor with parameters
        Polygon(size_t n):  points(new Point[n]), numPoints(n){}
        // Destructor
        ~Polygon(){
            delete[] points;
        }
        // Copy constructor: make a deep copy
        Polygon(const Polygon & rhs): points(new Point[rhs.numPoints]), numPoints(rhs.numPoints){
            for(size_t i=0; i<numPoints; i++){
                points[i] = rhs.points[i];
            }
        }
        // Print out a type Polygon object
        void printPolygon(void){
            cout<<"This object has "<<numPoints<<" point(s) as follows:"<<endl;
            for(size_t i=0; i<numPoints; i++){
                points[i].printPoint();
            }
        }
};

int main(void){
    Polygon poly(6);
    poly.printPolygon();
    return EXIT_SUCCESS;
}
