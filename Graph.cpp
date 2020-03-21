#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

class Vertix{
private:
    char id;
    map<char, int> info;
public:
    Vertix(char name){
        id = name;
    }
    Vertix(char name, map<char, int> edges){
        id = name;
        info = edges;
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

// Overload operator == for class Vertix
bool operator==(Vertix lhs, Vertix rhs){
    if(lhs.getId() == rhs.getId()){
        return true;
    }
    else{
        return false;
    }
}

class Path{
private:
    vector<Vertix> route;
public:
    unsigned int getSize(){
        return route.size();
    }
    void addStop(Vertix node){
        route.push_back(node);
    }
    Vertix getLastNode(){
        return route.back();
    }
    void printPath(){
        if(route.size() == 0){
            cout<<"The path is empty!"<<endl;
        }
        else if(route.size() == 1){
            cout<<route[0].getId()<<endl;
        }
        else{
            unsigned int sz = route.size();
            unsigned int curr = 0;
            cout<<"BEGIN->"<<route[curr].getId();
            curr += 1;
            while(curr<sz){
                cout<<"->"<<route[curr].getId();
                curr += 1;
            }
            cout<<"->END"<<endl;
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
    vector<Vertix> findAdjacency(char id){
        vector<Vertix> ans;
        if(maze.find(id) == maze.end()){
            cout<<"No such vertix in the graph!"<<endl;
            return ans;
        }
        else{
            map<char, int> vertixInfo = maze.find(id)->second;
            vector<char> idList;
            // Get a list of the name of all adjacent vertices
            for(map<char, int>::iterator it = vertixInfo.begin(); it != vertixInfo.end(); it++){
                idList.push_back(it->first);
            }
            // Construct a list of vertices based on the name list
            for(unsigned int i=0; i<idList.size(); i++){
                char currId = idList[i];
                map<char, int> currInfo = maze.find(currId)->second; 
                Vertix curr(currId, currInfo);
                ans.push_back(curr);
            }
            return ans;
        }
    }
    Path DFS(Vertix from, Vertix to){
        Path ans;
        if(maze.find(from.getId()) == maze.end()){
            cout<<"Source vertix does not exist!"<<endl;
            return ans;
        }
        if(maze.find(to.getId()) == maze.end()){
            cout<<"Destination vertix does not exist!"<<endl;
            return ans;
        }
        vector<Path> todo;
        vector<Vertix> visited;
        Path init;
        init.addStop(from);
        todo.push_back(init);
        while(todo.size() != 0){
            Path currentPath = todo.back();
            todo.pop_back();
            Vertix currentNode = currentPath.getLastNode();
            if(currentNode == to){
                return currentPath;
            }
            bool isVisited = false;
            for(unsigned int i=0; i<visited.size(); i++){
                if(visited[i] == currentNode){
                    isVisited = true;
                    break;
                }
                else{
                    continue;
                }
            }
            if(isVisited == false){
                visited.push_back(currentNode);
                vector<Vertix> currentAdjacent = findAdjacency(currentNode.getId());
                for(unsigned int i=0; i<currentAdjacent.size(); i++){
                    Path newPath = currentPath;
                    newPath.addStop(currentAdjacent[i]);
                    todo.push_back(newPath);
                }
            }
        }
        cout<<"No valid path exists!"<<endl;
        return ans;   
    }
    Path BFS(Vertix from, Vertix to){
        Path ans;
        if(maze.find(from.getId()) == maze.end()){
            cout<<"Source vertix does not exist!"<<endl;
            return ans;
        }
        if(maze.find(to.getId()) == maze.end()){
            cout<<"Destination vertix does not exist!"<<endl;
            return ans;
        }
        queue<Path> todo;
        vector<Vertix> visited;
        Path init;
        init.addStop(from);
        todo.push(init);
        while(todo.size() != 0){
            Path currentPath = todo.front();
            todo.pop();
            Vertix currentNode = currentPath.getLastNode();
            if(currentNode == to){
                return currentPath;
            }
            bool isVisited = false;
            for(unsigned int i=0; i<visited.size(); i++){
                if(visited[i] == currentNode){
                    isVisited = true;
                    break;
                }
                else{
                    continue;
                }
            }
            if(isVisited == false){
                visited.push_back(currentNode);
                vector<Vertix> currentAdjacent = findAdjacency(currentNode.getId());
                for(unsigned int i=0; i<currentAdjacent.size(); i++){
                    Path newPath = currentPath;
                    newPath.addStop(currentAdjacent[i]);
                    todo.push(newPath);
                }
            }
        }
        cout<<"No valid path exists!"<<endl;
        return ans;
    }
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
    Path dfsAns = maze.DFS(A, C);
    dfsAns.printPath();
    Path bfsAns = maze.BFS(A, C);
    bfsAns.printPath();
    return EXIT_SUCCESS;
}
