#include<iostream>
#include<vector>
using namespace std;
class GraphNode
{
    private:
       int Data;
       vector<GraphNode*>element_list;
    public: 
       GraphNode(int data = 0);
       ~GraphNode();
       GraphNode *AddChild(int data);
       void FindDFS();  
       void DemoDFS_Tree();  
};
GraphNode::GraphNode(int data){
    Data = data;
}
GraphNode::~GraphNode(){
    for(int i = 0; i < element_list.size(); i++){
        delete (element_list[i]);
    }
    element_list.clear();
}
GraphNode *GraphNode::AddChild(int data){
    GraphNode *p = new GraphNode();
    p->Data = data;
    element_list.push_back(p);
    return p;
}
void GraphNode::FindDFS(){
    cout<<Data<<"\n";
    for(int i = 0; i < element_list.size(); i++){
        GraphNode *p = element_list.at(i);
        if(p)
           p->FindDFS(); 
    } 
}
GraphNode *DFS_Head = new GraphNode(1);
void GraphNode::DemoDFS_Tree(){
    GraphNode *ele_1 = DFS_Head->AddChild(2);
    GraphNode *ele_11 =ele_1->AddChild(3);
    ele_11->AddChild(4);
    ele_11->AddChild(5);

    ele_1->AddChild(6);

    DFS_Head->AddChild(7);
    GraphNode *ele_3 = DFS_Head->AddChild(8);
    GraphNode *ele_31 =ele_3->AddChild(9);
    ele_31->AddChild(10);
    ele_31->AddChild(11);

    ele_3->AddChild(12);

    cout<<"Show list DFS: "<<endl;
    DFS_Head->FindDFS();
}
int main(){
    GraphNode l;
    l.DemoDFS_Tree();
    return 0;
}