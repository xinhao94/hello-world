#include <iostream>
#include <set>

using namespace std;

template<typename N, typename E, bool directed>
class Graph{
public:
    void addNode(const N & nodeInfo);
    void removeNode(const N & nodeInfo);
    void addEdge(const N & fromNode, const N & toNode, const E & edgeInfo);
    void removeEdge(const N & fromNode, const N & toNode);
    set<const N &> getNodes() const;
    set<pair<const N &, const E &> > getAdjacencies(const N & whichNode);
    const E & getEdge(const N & fromNode, const N & toNode) const;
    bool isAdjacent(const N & fromNode, const N & toNode) const;
};

int main()
{
    return EXIT_SUCCESS;
}
