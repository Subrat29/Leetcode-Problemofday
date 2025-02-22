#include <bits/stdc++.h>

// buildtree: tc - n, sc - n, h
// findelements: set space - n
// find: tc - 1, sc - 1 

// Tot time: n
// Tot space: n

class FindElements {
    public:
        unordered_set<int> s;
        void buildTree(TreeNode* root){
            if(!root)
            return;
    
            if(root->left){
                root->left->val = 2*root->val + 1;
                s.insert(2*root->val + 1);
                buildTree(root->left);
            }
    
            if(root->right){
                root->right->val = 2*root->val + 2;
                s.insert(2*root->val + 2);            
                buildTree(root->right);
            }
        }
    
        FindElements(TreeNode* root) {
            root->val = 0;
            s.insert(0);
            buildTree(root);
        }
        
        bool find(int target) {
            return s.find(target) != s.end() ? true : false;
        }
    };

int main()
{
    return 0;
}