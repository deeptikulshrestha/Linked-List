#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};
Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

int Search(Node* head,int val){
    Node* temp = head;
    while(temp){
        if(temp->data==val) return 1;
        temp = temp-> next;
    }
    return 0;
}

int main(){
    vector<int> arr = {12,3,4,5,6};
    Node* head = convertArr2LL(arr);

    int search = Search(head,10);
    if (search) {
        cout << "Value found in linked list" << endl;
    } else {
        cout << "Value not found in linked list" << endl;
    }
    return 0;
}