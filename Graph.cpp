#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Vertix{
private:
    char id;
    map<char, int> info;
public:
    Vertix(char name){
        id = name;
    }
    void addEdge(char id, int weight){
        info.insert(pair<char, int>(id, weight));
    }
    char getId(){
        return id;
    }
    map<char, int> getInfo(){
        return info;
    }
};

class Path{
private:
    vector<char> route;
public:
    unsigned int getSize(){
        return route.size();
    }
    void addStop(Vertix node){
        route.push_back(node.getId());
    }
    void printPath(){
        if(route.size() == 0){
            cout<<"The path is empty!"<<endl;
        }
        else if(route.size() == 1){
            cout<<route[0]<<endl;
        }
        else{
            unsigned int sz = route.size();
            unsigned int curr = 0;
            cout<<route[0];
            curr += 1;
            while(curr<sz){
                cout<<"->"<<route[curr];
                curr += 1;
            }
            cout<<endl;
        }
    }
};

class Graph{
private:
    map<char, map<char, int> > maze;
public:
    void addVertix(Vertix V){
        maze.insert(pair<char, map<char, int> >(V.getId(), V.getInfo()));
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
    // Path DFS(char from, char to){
    //     Path ans;
    //     if(maze.find(from) == maze.end()){
    //         cout<<"Source vertix does not exist!"<<endl;
    //         return ans;
    //     }
    //     if(maze.find(to) == maze.end()){
    //         cout<<"Destination vertix does not exist!"<<endl;
    //         return ans;
    //     }
    //     vector<Path> todo;
    //     vector<Vertix> visited;
    // }
};


int main()
{   
    // Construction of the graph
    Vertix A('A');
    A.addEdge('B', 1);
    A.addEdge('D', 1);
    Vertix B('B');
    B.addEdge('A', 1);
    B.addEdge('C', 1);
    B.addEdge('D', 1);
    Vertix C('C');
    C.addEdge('B', 1);
    C.addEdge('G', 1);
    Vertix D('D');
    D.addEdge('A', 1);
    D.addEdge('B', 1);
    D.addEdge('F', 1);
    Vertix E('E');
    E.addEdge('F', 1);
    E.addEdge('G', 1);
    Vertix F('F');
    F.addEdge('D', 1);
    F.addEdge('E', 1);
    Vertix G('G');
    G.addEdge('C', 1);
    G.addEdge('E', 1);
    Graph maze;
    maze.addVertix(A);
    maze.addVertix(B);
    maze.addVertix(C);
    maze.addVertix(D);
    maze.addVertix(E);
    maze.addVertix(F);
    maze.addVertix(G);

    // Test functionalities
    Path way;
    way.addStop(A);
    way.addStop(B);
    way.addStop(C);
    way.printPath();
    return EXIT_SUCCESS;
}
