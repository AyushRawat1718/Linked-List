#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    //constructor of node
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //destructor of node
    ~Node(){
        int val = this->data;
        cout<<val<<" was deleted"<<endl;
        if (this->next != NULL){
            delete this->next;
        }
    }
};

//Traversing the L.L.
void Traversal(Node* &head){
    Node* current = head;
    cout<<"Your Linked List: ";
    while (current != NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
    cout<<"Current Head: "<<head->data<<endl;
}

//Inserting the element in a empty L.L. or when head is pointing to NULL
Node* startLL(int data){
    Node* head = new Node(data);
    return head;
}

//Inserting the element at start of L.L.
void insertAtHead(Node* &head, int data){
    //This code will handle the cases where the L.L. is empty, or when the head is pointing to NULL
    Node* new_node = new Node(data);
    new_node->next = head;
    head = new_node;
}

//Inserting the element at end of L.L.
void insertAtEnd(Node* &head, int data){
    //If L.L. is empty
    if (head == NULL){
        head = startLL(data);
        return;
    }
    Node* new_node = new Node(data);
    Node* current_node = head;
    while (current_node->next != NULL){
        current_node = current_node->next;
    }
    //Now we have reached to last node
    current_node->next = new_node;
}

//Inserting the element at given position in L.L.
void insertAtPosition(Node* &head, int position, int data){
    //If L.L. is empty 
    if (head == NULL){
        head = startLL(data);
        return;
    }

    //For insertion at head
    if (position == 1){
        insertAtHead(head, data);
        return;
    }

    //For insertion at other positions
    else{
        Node* new_node = new Node(data);
        Node* current_node = head;
        int current_position = 1;
        while (current_position != position-1){
            current_position++;
            current_node = current_node->next;
        }
        //Now we have reached the correct position.
        new_node->next = current_node->next;
        current_node->next = new_node;  
    }
}

//Deleting the element at given position in L.L.
void deleteAtPosition(Node* &head, int position){
    Node* current_node = head;
    //For deletion at head
    if (position == 1){
        head = head->next;

        //For deleting the node
        current_node->next = NULL; //Very Imp Step
        delete current_node;
    }

    //For deletion at other positions
    else{
        int current_position = 2;
        Node* prev_node = head;
        current_node = prev_node->next;

        while (current_position != position){
            prev_node = current_node;
            current_node = current_node->next;
            current_position++;
        }

        //Now our current_node is the node that we want to delete
        prev_node->next = current_node->next;

        //For deleting the node
        current_node->next = NULL; //Very Imp Step
        delete current_node;
    }
}

//Search element in L.L
bool searchKey(Node* &head, int key){
    Node* current_node = head;
    while(current_node != NULL){
        if (current_node->data == key) return true;
        else current_node = current_node->next;
    }

    return false;
}

//Length of L.L.
int length(Node* &head){
    Node* current_node = head;
    int counter = 0;
    while (current_node != NULL){
        counter++;
        current_node = current_node->next;
    }

    return counter;
}

Node* array_to_LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    int index = 1; //Updated b/c first element is inserted in Linked List

    for (index; index < arr.size(); index++){
        insertAtEnd(head, arr[index]);
    }
    return head;
}



int main() {
    vector<int> arr = {11,12,13,14,15,16,17,18};

    Node* head = array_to_LL(arr);

    Traversal(head);

    cout<<"Current Length of this Linked List is: "<<length(head)<<endl;

    int del_pos;
    cout<<"Enter the position for deletion of node: ";
    cin>>del_pos;
    deleteAtPosition(head, del_pos);

    Traversal(head);

    cout<<"Current Length of this Linked List is: "<<length(head)<<endl;

    int key;
    cout<<"Enter the integer to be searched: ";
    cin>>key;
    if (searchKey(head, key)){
        cout<<key<<" is present"<<endl;
    }
    else{
        cout<<key<<" is absent"<<endl;
    }

    return 0;
}