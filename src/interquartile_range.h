/*

*/

/*
    Interquartile Range

    Given a sorted singly linked list without a tail (e.g, head -> 1 -> 2 -> 3 -> 4), 
    return the interquartile range of the data set using the slow and fast pointer 
    approach OR using a methodology that does not iterate over the linked list 
    twice. You must not iterate over the entire linked list more than once and you 
    cannot use arrays, vectors, lists or an STL implementation of List ADT in this problem.

    Sample Input:
        2 4 4 5 6 7 8
    
    Sample Output:
        3.00 
*/

#include <iostream>
#include <iomanip>

class Node {
    public:
        int value;
        Node* next = nullptr;
};

Node* insertEnd(Node* head, int key)
{
    Node* temp = new Node();
    temp->value = key;
    if(head == nullptr)
        head = temp;
    else
    {
        Node* curr = head;
        while(curr->next != nullptr)
            curr = curr->next;
        curr->next = temp;
    }
    return head;
}

// Slow and fast pointer approach.
float interQuartile(Node* head)
{
    int cnt = 0;
    Node* fast_ptr = head;
    Node* Q1_ptr = head;
    Node* Q3_ptr = head->next;

    while(fast_ptr != nullptr && fast_ptr->next != nullptr){
        Q1_ptr = Q1_ptr->next;
        Q3_ptr = Q3_ptr->next->next;
        fast_ptr = fast_ptr->next->next->next;
        cnt += 3;
    }
    cnt++;

    if(cnt % 2 == 1)
        return Q3_ptr->value-Q1_ptr->value;
    else if(cnt % 2 == 0)
        return Q3_ptr->value/2;
}