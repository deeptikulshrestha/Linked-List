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
     Node(int val, Node* nextNode) { // << Add this
        data = val;
        next = nextNode;
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
Node* deleteTail(Node* head){
    if(head==NULL || head->next == NULL) return NULL;
    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next =nullptr;
    return head;
}

Node* deleteEl(Node* head, int el){
    if(head==NULL) return head;
    if(head->data ==el){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }
         prev = temp;
    temp = temp->next;
    }
    return head;
}

Node* insertHead(Node* head, int val){
    Node* temp = new Node(val, head);
    return temp;
}

Node* insertTail(Node* head,int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp = head;
    while(temp->next !=NULL){
        temp=temp->next;
    }

    Node* newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node* insertval(Node* head,int el,int val){
    if(head==NULL){
        return NULL;
    }
    if(head->data == val){
        Node* temp = new Node(el,head);
        return temp;
    }
    
    Node* temp = head;
    while(temp->next!=NULL){

        if(temp->next->data ==val){
            Node* x = new Node(el);
            x->next = temp->next;
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main(){
    vector<int> arr = {12,13,4,5,6};
    Node* head = convertArr2LL(arr);
    head = insertval(head,8,6);
    printLinkedList(head);
}