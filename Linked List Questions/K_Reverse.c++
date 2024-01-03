/*
Given the head of the Linked List and an integer K. We have to reverse the Linked list in groups of size K & return head.

Note : In case the number of elements in the last cannot be evenly divided into groups of size k, then just reverse the last group (with any size).

Ex : I/P => 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> Null & K = 3

O/P => 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 8 -> 7 -> Null

*/

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

Node* kReverse(Node* &head, int k){
    //Base Case
    if (head == NULL || head->next == NULL || k == 1){
        return head;
    }

    //Reverse first k nodes
    Node* prev = NULL;
    Node* curr = head;
    Node* forward;
    int ctr = 0;
    while (curr != NULL && ctr < k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        ctr++; //If we don't do this, it will eventually reverse complete L.L.
    }

    //Connect the starting reversed part with the rest of the reversed part
    head->next = kReverse(curr, k);

    // As we know our prev pointer is on the first node of the reversed L.L
    head = prev; //Updating the head is also necessary
    return head;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8};
    Node* head = array_to_LL(arr);
    Traversal(head);
    Node* new_head = kReverse(head, 3);
    Traversal(new_head);
    return 0;
}