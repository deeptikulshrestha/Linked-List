#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertarr2DLL(vector<int> & arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i =1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;

    }
    return head;
}
Node* deleteHead2d(Node* head){
    if(head==NULL || head->next == NULL) return NULL;
    Node* prev = head;
    head = head->next;
    head-> back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}
void print(Node* head){
    while(head!= NULL){
        cout << head->data << " ";
        head = head->next;
    }
}



Node* deleteTail2d(Node* head){
    if(head==NULL ||head->next == NULL){
        return NULL;
    }
    Node* tail = head;

    while(tail->next!=NULL){
        tail = tail->next;

    }
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;
}

Node* deleteK2d(Node* head, int k){
    if(head==NULL) return NULL;
    int count= 0;
    Node* temp = head;
    while(temp != NULL){
        count++;
        if(count == k) break;
        temp = temp->next;
    }
        
       Node* prev = temp->back;
       Node* front = temp->next; 

       if(prev==NULL && front ==NULL){
        return NULL;
       }

       else if(prev ==NULL){
        return deleteHead2d(head);
        
       }

       else if(front ==NULL){
        return deleteTail2d(head);
       }
       prev->next = front;
       front->back = prev;
       temp->next = nullptr;
       temp->back = nullptr;
       delete temp;
       return head;
       
}

void deleteNode2d(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front==NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->next = temp->back = nullptr;
    free(temp);
}

int main(){
    vector<int> arr = {12,4,5,2,7,8};
    Node* head = convertarr2DLL(arr);
    deleteNode2d(head->next);
    print(head);
    return 0;
}