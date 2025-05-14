#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Tree{
    public:
    int val;
    Tree* left;
    Tree* right;
    Tree(int valNode , Tree* leftnode ,Tree* rightnode){
        val=valNode;
        left=leftnode;
        right=rightnode;
    }
};

//Preorder - Inorder - PostOrder traversal in One go.
vector<vector<int>> TreeTraversal(Tree* root){
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;

    stack<pair<Tree*,int>> stk;
    pair<Tree*,int> temp = {root,1};
    stk.push(temp);
    while(!stk.empty()){
        pair<Tree*,int> row = stk.top();
        stk.pop();
        if(row.second==1){
            preorder.push_back(row.first->val);
            row={row.first,2};
            stk.push(row);
            if(row.first->left){
                row={row.first->left,1};
                stk.push(row);
            }
        }else if(row.second==2) {
             inorder.push_back(row.first->val);
            row={row.first,3};
            stk.push(row);
             if(row.first->right){
                row={row.first->right,1};
                stk.push(row);
            }
        }else if(row.second==3){
            postorder.push_back(row.first->val);

        }
    } 

    vector<vector<int>> result = {preorder,inorder,postorder};
    return result;
}


int main(){
    
}