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

    int Q1_prev = 0, Q3_prev = 0;

    int fast_cnt = 0;

    std::cout << "------ Locations of Pointers ------" << std::endl;
    while(fast_ptr != nullptr){ // Traversing through the list once, O(n) time complexity and O(1) space complexity.

        fast_ptr = fast_ptr->next;
        fast_cnt++;
        
        if(fast_cnt % 4 == 0){ // every 4 times fast pointer moves, move q1 pointer once
            Q1_prev = Q1_ptr->value;
            Q1_ptr = Q1_ptr->next;
        }
        else{
            Q3_prev = Q3_ptr->value;
            Q3_ptr = Q3_ptr->next;
        }

    }

    std::cout << "Estimated Q1: " << Q1_ptr->value << ", Estimated Q3: " << Q3_ptr->value << ", Length: " << fast_cnt/2 << std::endl;

    if((fast_cnt/2) % 2 == 0){
        std::cout << "Actual Q1: " << ((float)(Q1_prev) + Q1_ptr->value)/2 << ", Actual Q3: " << ((float)(Q3_prev) + Q3_ptr->value)/2 << std::endl;
        return (((float)(Q3_prev) + Q3_ptr->value)/2) - (((float)(Q1_prev) + Q1_ptr->value)/2);
    }
    else{
        std::cout << "Actual Q1: " << Q1_ptr->value << ", Actual Q3: " << Q3_prev << std::endl;
        return Q3_prev - Q1_ptr->value;
    }
}