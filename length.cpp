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
int length(Node* head){
    int count = 0;
    Node* temp = head;

    while(temp){
        cout<< temp->data << " ";
        temp = temp->next;
        count++;
    }
    return count;
}

Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int main(){
    vector<int> arr = {10, 20, 30, 40, 50};
    Node* head = convertArr2LL(arr);
    
    cout << "Linked List: ";
    int len = length(head);
    
    cout << "\nLength of linked list: " << len << endl;
    return 0;
}