/*Decimal Equivalent
Send Feedback
Given a singly linked list of 0s and 1s, find and return its decimal equivalent.
Input Format :
Elements of the linked list ending with -1 (-1 not included)
Output Format:
Decimal equivalent of input LL
Constraints :
1 <= size of list <= 100
Sample Input 1:
1 0 -1
Sample Output 1:
2
Sample Input 2:
1 0 1 -1
Sample Output 2:
5*/
#include <bits/stdc++.h>
using namespace std;
typedef Node<int> node;

int decimal(Node<int> *head) {
    string ans="";
    node* temp=head;
    while(temp!=NULL){
        ans=to_string(temp->data)+ans;
        temp=temp->next;
    }
    //cout<<ans<<endl;
    int res=0;
    for (int i=0;i<ans.size();i++){
        if(ans[i]=='1'){
            res+=pow(2,i)*1;
        }
    }
    return res;
}
