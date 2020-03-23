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
    int getWeight(Vertix destination){
        char desId = destination.getId();
        if(info.find(desId) == info.end()){
            cout<<"ERROR: Vertices are not adjacent!"<<endl;
            return INT_MAX;
        }
        else{
            return info.find(desId)->second;
        } 
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
};


int main()
{   
    // Construction of the graph
    Vertix A('A');
    A.addEdge('B', 3);
    A.addEdge('D', 5);
    A.addEdge('F', 4);
    Vertix B('B');
    B.addEdge('A', 3);
    B.addEdge('C', 3);
    Vertix C('C');
    C.addEdge('B', 3);
    C.addEdge('D', 6);
    C.addEdge('E', 1);
    Vertix D('D');
    D.addEdge('A', 5);
    D.addEdge('C', 6);
    D.addEdge('E', 3);
    D.addEdge('F', 2);
    Vertix E('E');
    E.addEdge('C', 1);
    E.addEdge('D', 3);
    E.addEdge('F', 5);
    Vertix F('F');
    F.addEdge('A', 4);
    F.addEdge('D', 2);
    F.addEdge('E', 5);
    Graph maze;
    maze.addVertix(A);
    maze.addVertix(B);
    maze.addVertix(C);
    maze.addVertix(D);
    maze.addVertix(E);
    maze.addVertix(F);

    // Validation of the graph
    vector<Vertix> nodeList;
    nodeList.push_back(A);
    nodeList.push_back(B);
    nodeList.push_back(C);
    nodeList.push_back(D);
    nodeList.push_back(E);
    nodeList.push_back(F);
    for(int j=0; j<nodeList.size(); j++){
        Vertix currNode = nodeList[j];
        char currId = currNode.getId();
        vector<Vertix> ans = maze.findAdjacency(currId);
        cout<<currId<<" is adjacent to: ";
        for(unsigned int i=0; i<ans.size(); i++){
            cout<<ans[i].getId()<<"("<<currNode.getWeight(ans[i])<<") ";
        }
        cout<<endl;
    }

    //Test functionality
    return EXIT_SUCCESS;
}
