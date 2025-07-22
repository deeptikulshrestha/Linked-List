#include<iostream>
#include<vector>
using namespace std;
class Node{
    public :
    int data;
    Node* next;
    Node(int val) {
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
void printLinkedList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
Node* deleteHead(Node* head){
    if(head==NULL) return head;
    Node* temp = head;
    head = head-> next;
    delete temp;
    return head;

}

int main(){
    vector<int> arr = {12,13,5,3,2};
    Node* head = convertArr2LL(arr);
    head = deleteHead(head);
    printLinkedList(head);
}