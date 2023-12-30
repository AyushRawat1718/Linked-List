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
    while (current != NULL){
        cout<<current->data<<" ";
        current = current->next;
    }
    cout<<endl;
}

//Inserting the element at start of L.L.
void insertAtHead(Node* &head, int data){
    Node* new_node = new Node(data);
    new_node->next = head;
    head = new_node;
}

//Inserting the element at end of L.L.
void insertAtEnd(Node* &head, int data){
    Node* new_node = new Node(data);
    Node* current_node = head;
    while(current_node->next != NULL){
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

//Inserting the element at given position in L.L.
void insertAtPosition(Node* &head, int position, int data){
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

int main() {
    Node* head = new Node(10);
    insertAtPosition(head, 2, 11);
    insertAtPosition(head, 3, 12);
    insertAtPosition(head, 4, 13);
    insertAtPosition(head, 5, 14);
    insertAtPosition(head, 6, 15);
    insertAtPosition(head, 7, 16);

    Traversal(head);
    deleteAtPosition(head, 7);
    Traversal(head);

    return 0;
}