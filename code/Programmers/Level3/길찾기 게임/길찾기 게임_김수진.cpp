#include<bits/stdc++.h>

using namespace std;


struct Node{
    int x;
    int y;
    int index;
    struct Node *left;
    struct Node *right;
    
    ~Node() {
        left = NULL;
        right= NULL;
    }
};

bool compare(Node a, Node b){
    if(a.y==b.y){
        return a.x<b.x;
    }
    return a.y>b.y;
}

void add(Node* root, Node* child){
    if(root->x > child->x){
        if(root->left == nullptr){
            root->left = child; 
        }else{
            add(root->left, child);
        }
    }else if(root->x < child->x){
        if(root->right == nullptr){
            root->right = child;
        }else{
            add(root->right, child);
        }
    }
}

static vector<int> dd;
static vector<int> ss;

void preorder(Node root){
        dd.push_back(root.index);
        if(root.left!=nullptr){
            preorder(*root.left);
        }
        if(root.right!=nullptr){
            preorder(*root.right);
         }
        
}

void postorder(Node root){
    if(root.left!=nullptr){
        postorder(*root.left);
    }
    if(root.right!=nullptr){
        postorder(*root.right);
    }
    ss.push_back(root.index);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    int index = 1;
    
    vector<Node> node;
    
    for(auto i : nodeinfo){
        node.push_back({i[0],i[1],index});
        index++;
    }
    
    sort(node.begin(),node.end(),compare);
    
    
    for(int j=1; j<node.size();j++){
        add(&node[0],&node[j]);
    }
    
    preorder(node[0]);
    postorder(node[0]);
    
    answer.push_back(dd);
    answer.push_back(ss);

    
    return answer;
}
