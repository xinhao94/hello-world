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
        void setPoint(int new_x, int new_y){
            x = new_x;
            y = new_y;
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
        explicit Polygon(size_t n):  points(new Point[n]), numPoints(n){}
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
        // Overloading assignment operator: make a deep copy
        Polygon & operator=(const Polygon & rhs){
            if(this != &rhs){
                Point * temp = new Point[rhs.numPoints];
                for(size_t i=0; i<rhs.numPoints; i++){
                    temp[i] = rhs.points[i];
                }
                delete[] points;
                numPoints = rhs.numPoints;
                points = temp;
            }
            return *this;
        }
        // Print out a type Polygon object
        void printPolygon(void){
            cout<<"This object has "<<numPoints<<" point(s) as follows:"<<endl;
            for(size_t i=0; i<numPoints; i++){
                points[i].printPoint();
            }
        }
        // Assign a point as a vertex
        void setVertex(size_t n, const Point & p){
            if(n>=1 && n<=numPoints){
                points[n-1] = p;
            }
            else{
                cout<<"Assignment failed"<<endl;
            }
        }
};

int main(void){
    Point p1, p2, p3, p4;
    p1.setPoint(0,0);
    p2.setPoint(3,0);
    p3.setPoint(3,2);
    p4.setPoint(0,2);
    Polygon poly(4);
    poly.printPolygon();
    poly.setVertex(1, p1);
    poly.setVertex(2, p2);
    poly.setVertex(3, p3);
    poly.setVertex(4, p4);
    poly.printPolygon();
    Polygon poly_copy(4);
    poly_copy.printPolygon();
    poly_copy = poly;
    poly_copy.printPolygon();
    return EXIT_SUCCESS;
}
