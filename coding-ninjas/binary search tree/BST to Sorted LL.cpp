/*Code: BST to Sorted LL
Send Feedback
Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
Output Format:
The first and only line of output prints the elements of sorted linked list.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2 5 6 7 8 10*/

class foo{
    public:
    Node<int>* head;
	Node<int>* tail;
};
foo constructhelper(BinaryTreeNode<int>* root){
    if(root==NULL){
        foo f;
        f.head=NULL;
        f.tail=NULL;
        return f;
    }
    Node<int>* x=new Node<int>(root->data);
    foo left=constructhelper(root->left);
    foo right=constructhelper(root->right);
    foo result;
    if(left.head==NULL){
        result.head=x;
        result.head->next=right.head;
        if(right.tail==NULL){
            result.tail=x;
        }else{
            result.tail=right.tail;
        } 
    }else{
        result.head=left.head;
        left.tail->next=x;
        x->next=right.head;
        if(right.tail==NULL){
            result.tail=x;
        }else{
            result.tail=right.tail;
        }        
    }
    return result;    
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    foo result=constructhelper(root);
    return result.head;
}
