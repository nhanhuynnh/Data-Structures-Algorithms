#include<iostream>
using namespace std;
#include<string.h>
#include<deque>
#include<conio.h>
class GraphNode
{
    private:
       int data;
       deque<GraphNode*>element_list;
    public: 
       GraphNode(int data = 0);
       ~GraphNode();
       GraphNode *AddChild(int DaTa);
       void printBFSNode();  
       void FindBFS();  
       void DemoBFS_Tree();  
};
GraphNode::GraphNode(int dt){
    data = dt;
}
GraphNode::~GraphNode(){
    element_list.clear();
}
GraphNode *GraphNode::AddChild(int dt){
    GraphNode *p = new GraphNode;
    p->data = dt;
    element_list.push_back(p);
    return p;
}
void GraphNode::printBFSNode(){
    cout<<data<<"  ";
}
void GraphNode::FindBFS(){
    deque<GraphNode*>my_list;
    my_list.push_back(this);

    while(my_list.size() > 0){
        GraphNode* pNode = *my_list.begin();
        pNode->printBFSNode();

        for(int i = 0; i < pNode->element_list.size(); i++){
            my_list.push_back(pNode->element_list.at(i));
        }
        my_list.pop_front();

    }
}
void GraphNode::DemoBFS_Tree(){
    GraphNode* bfs_head_node = new GraphNode(1);

    GraphNode* ele_1 = bfs_head_node->AddChild(2);
    GraphNode* ele_2 = bfs_head_node->AddChild(7);
    GraphNode* ele_3 = bfs_head_node->AddChild(8);
    
    GraphNode* ele_11 = ele_1->AddChild(3);
    GraphNode* ele_12 = ele_1->AddChild(6);

    GraphNode* ele_31 = ele_3->AddChild(9);
    ele_3->AddChild(12);

    ele_11->AddChild(4);
    ele_12->AddChild(5);

    ele_31->AddChild(10);
    ele_31->AddChild(11);

    cout<<"\nList BFS: "<<" ";
    bfs_head_node->FindBFS();
}
int main(){
    GraphNode l;
    l.DemoBFS_Tree();
    return 0;
}