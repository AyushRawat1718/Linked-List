#include <bits/stdc++.h>
using namespace std;

//----------------------------------------------Required Code------------------------------------------------------

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//Inserting the element in a empty L.L. or when head is pointing to NULL
Node* startLL(int data){
    Node* head = new Node(data);
    return head;
}

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

Node* array_to_LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    int index = 1; //Updated b/c first element is inserted in Linked List

    for (index; index < arr.size(); index++){
        insertAtEnd(head, arr[index]);
    }
    return head;
}

//----------------------------------------------Main Logic Code-----------------------------------------------------

//Approach - 1 (Iterative)

void ReverseLL_IterativeApproach(Node* &head){
    //Handling the cases when Linked List is empty or when Linked List have only one element
    if (head == NULL || head->next == NULL){
        return ;
    }

    Node* prev_node = NULL;
    Node* curr_node = head;
    Node* next_node;

    while (curr_node != NULL){
        next_node = curr_node->next;
        curr_node->next = prev_node;
        prev_node = curr_node;
        curr_node = next_node;
    }
    head = prev_node; //Imp Step
}

//--------------------------------------------------------------------------------------------------------------------

//Approach - 2 (Recursive)

void reverse_1(Node* &head, Node* prev, Node* curr){

    if (curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr->next; //To keep track of the forward part of L.L.

    // Similar Concept as of iteration
    curr->next = prev;
    prev = curr;
    curr = forward;

    reverse_1(head, prev, curr);
}

void ReverseLL_RecursiveApproach(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    reverse_1(head, prev, curr);
}


int main() {
    vector<int> arr = {4,5,7,9};
    Node* head = array_to_LL(arr);
    cout<<"Before Reversal"<<endl;
    Traversal(head);
    ReverseLL_RecursiveApproach(head);
    cout<<"After Reversal"<<endl;
    Traversal(head);
    return 0;
}