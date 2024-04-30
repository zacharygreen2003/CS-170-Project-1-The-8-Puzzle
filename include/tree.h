#include "node.h"
#include <vector>

using namespace std;

class Tree 
{
    private:
        Node* head;
    public:
        Tree();
        Tree(Node*);
        void SetHead(Node*);
        vector<Node*> ParentList(Node*);
        bool Contains(Node*);
};