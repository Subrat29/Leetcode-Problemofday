#include<bits/stdc++.h>
using namespace std;

// tc: n
// sc: n

TreeNode* dfs(string &s, int &i, int depth) {
    int n = s.size();
    int cnt = 0;

    while(i<n && s[i] == '-'){
        i++;
        cnt++;
    }

    if(cnt != depth){
        i -= cnt;
        return nullptr;
    }

    // now parse digits
    int num = 0;
    while(i<n && isdigit(s[i])){
        num = num*10 + s[i]-'0';
        i++;
    }

    TreeNode* node = new TreeNode(num);
    node->left = dfs(s, i, depth+1);
    node->right = dfs(s, i, depth+1);

    return node;
}

TreeNode* recoverFromPreorder(string traversal) {
    int i = 0;
    return dfs(traversal, i, 0);
}

int main(){
    return 0;
}