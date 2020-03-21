#include <iostream>
#include <map>

using namespace std;

class Vertix{
private:
    map<char, int> info;
public:
    void addEdge(char id, int weight){
        info.insert(pair<char, int>(id, weight));
    }
    map<char, int> getInfo(){
        return info;
    }
};

class Graph{
private:
    map<char, map<char, int> > maze;
public:
    void addVertix(char id, Vertix V){
        maze.insert(pair<char, map<char, int> >(id, V.getInfo()));
    }
    bool isNeighbor(char from, char to){
        if(maze.find(from) == maze.end()){
            cout<<"Vertix doesn't exist!"<<endl;
            return false;
        }
        else{
            map<char, int> vertixInfo = maze.find(from)->second;
            if(vertixInfo.find(to) != vertixInfo.end()){
                return true;
            }
            else{
                return false;
            }
        }
    }
};


int main()
{   
    Vertix A;
    A.addEdge('B', 1);
    A.addEdge('D', 1);
    Vertix B;
    B.addEdge('A', 1);
    B.addEdge('C', 1);
    B.addEdge('D', 1);
    Vertix C;
    C.addEdge('B', 1);
    C.addEdge('G', 1);
    Vertix D;
    D.addEdge('A', 1);
    D.addEdge('B', 1);
    D.addEdge('F', 1);
    Vertix E;
    E.addEdge('F', 1);
    E.addEdge('G', 1);
    Vertix F;
    F.addEdge('D', 1);
    F.addEdge('E', 1);
    Vertix G;
    G.addEdge('C', 1);
    G.addEdge('E', 1);
    Graph maze;
    maze.addVertix('A', A);
    maze.addVertix('B', B);
    maze.addVertix('C', C);
    maze.addVertix('D', D);
    maze.addVertix('E', E);
    maze.addVertix('F', F);
    maze.addVertix('G', G);
    cout<<maze.isNeighbor('A', 'B')<<endl;
    cout<<maze.isNeighbor('A', 'C')<<endl;
    cout<<maze.isNeighbor('H', 'D')<<endl;
    return EXIT_SUCCESS;
}
