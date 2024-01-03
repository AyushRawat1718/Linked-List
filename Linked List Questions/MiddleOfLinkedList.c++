// Given the head of the singly linked list, return a pointer pointing to the middle of the linked list. If there are an odd number of elements, return the middle element & if there are even number of elements return the one which is farther from the head node(ex. L.L. => 1 -> 2 -> 3 -> 4 -> NULL, in this case we have even number of elements then middle element could be 2 or 3, so according to the question we have to return 3, b/c it is farther from the head node.)

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
//Approach - 1 (Find Length of the L.L. then calculate the position of the middle element and then fetch it)

int getLength(Node* &head){
    int counter = 0;
    Node* current_node = head;
    while (current_node != NULL){
        counter++;
        current_node = current_node->next;
    }
    return counter;
}

Node* get_MiddlePointer_1(Node* &head){
    int length = getLength(head);
    if (length == 0){
        return NULL;
    }
    int requiredPositon = (length/2) + 1; //This is the case for both even and odd length
    int position = 1;
    Node* curr_node = head;
    while (position != requiredPositon){
        position++;
        curr_node = curr_node->next;
    }
    return curr_node;
}

//--------------------------------------------------------------------------------------------------------------------
// Approach - 2 (Create two pointers (slow & fast), each time fast moves two step and slow moves one step, when the fast have reached null, then slow will be at the middle node)
// In this approach there will be the need of the small changes as per the question, so here we will be starting the slow from head & fast from the head->next.

Node* get_MiddlePointer_2(Node* &head){
    //When Linked List is empty or having only one element.
    if (head == NULL || head->next == NULL){
        return head;
    }

    Node* slow_ptr = head;
    Node* fast_ptr = head->next;

    while (fast_ptr != NULL){
        fast_ptr = fast_ptr->next;
        if (fast_ptr != NULL){ //Check whether fast have already reached NULL, if no then move fast_ptr else not
            fast_ptr = fast_ptr->next;
        }
        slow_ptr = slow_ptr->next;
    }
    return slow_ptr;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    Node* head = array_to_LL(arr);
    Traversal(head);
    cout<<"The middle element of this L.L. is "<<get_MiddlePointer_2(head)->data<<" & its pointer is "<<get_MiddlePointer_2(head)<<endl;
    return 0;
}