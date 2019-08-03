#include <iostream>
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
        double getDistance(Point & obj) const{
            return sqrt(pow(double(x-obj.x),2) + pow(double(y-obj.y),2));
        }
        double getSlope(Point & obj) const{
            return (y-obj.y)/(x-obj.x);
        }
};

int main(void){
    int size = 5;
    Point * point_arr = new Point[size];
    for(int i=0; i<size; i++){
        point_arr[i].printPoint();
    }
    Point ** point_ptrs = new Point*[size];
    for(int i=0; i<size; i++){
        point_ptrs[i] = new Point(i,i);
    }
    for(int i=0; i<size; i++){
        point_ptrs[i]->printPoint();
    }
    return EXIT_SUCCESS;
}
