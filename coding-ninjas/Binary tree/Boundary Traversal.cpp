/*Boundary Traversal
Send Feedback
Given a binary tree having N nodes, print its boundary traversal.
Input format :
Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place
Output format :
Boundary traversal (separated by space)
Constraints :
1 <= N <= 10^5
Sample Input 1 :
1 2 3 -1 -1 -1 -1
Sample Output 1 :
1 2 3
Sample Input 2 :
1 2 3 4 5 7 -1 -1 -1 6 -1 -1 8 -1 -1 -1 -1
Sample Output 2 :
1 2 4 6 8 7 3*/


void leftBound(BinaryTreeNode<int>* root,vector <int> &v){    
    if(root->left==NULL && root->right==NULL)
        return;
    v.push_back(root->data);
    
    if(root->left!=NULL)
        leftBound(root->left,v);
    else if(root->right !=NULL)
        leftBound(root->right,v);    
}

void rightBound(BinaryTreeNode<int>* root,vector <int> &v){
    
    if(root->left==NULL && root->right==NULL)
        return;
    
    if(root->right!=NULL)
        rightBound(root->right,v);
    else if(root->left !=NULL)
        rightBound(root->left,v);    
    v.push_back(root->data);    
}

void leafBound(BinaryTreeNode<int>* root,vector <int> &v){    
    if(root==NULL)
        return;
    if(root->left==NULL && root->right==NULL){
        v.push_back(root->data);
        return;
    }        
    leafBound(root->left,v);
    leafBound(root->right,v);        
}
void solve(BinaryTreeNode<int>* root){
    vector <int> v;
    leftBound(root,v);
    leafBound(root,v);
    rightBound(root,v);
    v.pop_back();
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}
