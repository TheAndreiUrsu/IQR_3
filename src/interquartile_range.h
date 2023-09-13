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
    Node* Q1_ptr = head; // Moves once every time fast_ptr moves.
    Node* Q3_ptr = head; // Moves twice every time Q1_ptr moves.

    //int Q1_prev = 0, Q3_prev = 0;
    
    int len = 0; // Stores the length of the list to determine which case to do.
    int fast_cnt = 0;

    while(fast_ptr != nullptr){ // Traversing through the list once, O(n) time complexity and O(1) space complexity.
        
        std::cout << "fast ptr: " << fast_ptr->value << std::endl;
        std::cout << "Q3: " << Q3_ptr->value << std::endl;
        
        fast_ptr = fast_ptr->next;
        fast_cnt++;
        len++;

        if(fast_cnt % 4 == 0){ // Everytime fast pointer moves 4 times, move the Q1 pointer.
            //Q1_prev = Q1_ptr->value;
            Q1_ptr = Q1_ptr->next;
        }
        else if(fast_cnt % 2 == 0){
            Q3_ptr = Q3_ptr->next->next->next;
        }

    }

    std::cout << "Q1: " << Q1_ptr->value << ", Q3: " << Q3_ptr->value << ", Length: " << len << std::endl;

    // if(len % 2 == 0)
    //      std::cout << "Q1_prev: " << Q1_prev << ", Q1: " << Q1_ptr->value << ", Q3_prev: " << Q3_prev << ", Q3: " << Q3_ptr->value << ", Length: " << len << std::endl;
    // else
    //      std::cout << "Q1: " << Q1_ptr->value << ", Q3: " << Q3_ptr->value << ", Length: " << len << std::endl;

    if(len % 2 == 0) // Even case.
        return -1; //return ((static_cast<float>(Q3_prev) + Q3_ptr->value)/2 - (static_cast<float>(Q1_prev) + Q1_ptr->value)/2);
    else // Odd case.
        return 0; //return Q3_ptr->value - Q1_ptr->value;
}