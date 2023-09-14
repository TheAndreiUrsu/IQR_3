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
    Node* fast_ptr = head; // Moves 4 at a time.
    Node* Q1_ptr = head;
    Node* Q3_ptr = head;

    int Q1_half = 0, Q3_half = 0;

    int fast_cnt = 0;

    std::cout << std::endl;
    std::cout << "----Location of Pointers----" << std::endl;
    while(fast_ptr != nullptr){ // Traversing through the list once, O(n) time complexity and O(1) space complexity.

        std::cout << "Fast: " << fast_ptr->value << ", Q1: " << Q1_ptr->value << ", Q3: " << Q3_ptr->value << std::endl;

        fast_ptr = fast_ptr->next;
        fast_cnt++;

        if(fast_ptr == nullptr){
            break;
        }

        if(fast_cnt % 4 == 0){ // every 4 times fast pointer moves, move q1 pointer once
            Q1_half = Q1_ptr->value;
            Q1_ptr = Q1_ptr->next;
        }
        else{
            Q3_half = Q3_ptr->value;
            Q3_ptr = Q3_ptr->next;
        }

    }

    float Q3_flt = (float)(Q3_half);

    float Q1_flt = (float)(Q1_half);

    int len = fast_cnt/2;

    std::cout << "Length of 1/2 list: " << len << std::endl;
    if(len % 2 == 0){
        std::cout << "Q1: " << (Q1_flt + Q1_ptr->value)/2 << ", Q3: " << (Q3_flt+Q3_ptr->value)/2 << std::endl;
    }
    else{
        std::cout << "Q1: " << Q1_ptr->value << ", Q3: " << Q3_ptr->value << std::endl;
    }
    
    if(len % 2 == 0)
        return ((Q3_flt+Q3_ptr->value)/2)-((Q1_flt+Q1_ptr->value)/2);

    return Q3_ptr->value-Q1_ptr->value;   
}