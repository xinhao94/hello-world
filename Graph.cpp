#include <iostream>
#include <set>

using namespace std;

class Graph{
public:
    unsigned addNode();
    void removeNode(unsigned whichNode);
    void addEdge(unsigned from, unsigned to, double weight);
    void removeEdge(unsigned from, unsigned to);
    unsigned getNodeCount() const;
    set<pair<unsigned, double> > getAdjacencies(unsigned whichNode) const;
    double getEdge(unsigned from, unsigned to) const;
    bool isAdjacent(unsigned from, unsigned to) const;
};

int main()
{
    return EXIT_SUCCESS;
}
