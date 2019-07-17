#include <iostream>
using namespace std;

class Point{
    private:
        int x;
        int y;
    public:
        void setPoint(int a, int b){
            x = a;
            y = b;
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
};

int main(void){
    Point a, b, c;
    a.setPoint(1,1);
    b.setPoint(2,2);
    c = a + b;
    c.printPoint();
    a += b;
    a.printPoint();
    return 0;
}
