#include "../src/interquartile_range.h"
#include <vector>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

/*
	To check output (At the interquartile_range directory):
		g++ -std=c++14 -Werror -Wuninitialized -o test test-unit/test.cpp && ./test
*/

TEST_CASE("Function: IQR 1", "[given]") {
	std::vector<int> v = {2, 4, 4, 5, 6, 7, 8};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 3.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 2", "[given]") {
	std::vector<int> v = {1, 2, 3, 4};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 2.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 3", "[output_hidden]") {
	std::vector<int> v = {1, 8, 15, 43, 82, 101, 110, 2456, 55345, 137556};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 2441.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
} 

TEST_CASE("Function: IQR 4", "[output_hidden]") {
	std::vector<int> v = {2,4,4,5,6,7,8,9,10,11,28,29,30,41,42};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 24.00);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 5", "[output_hidden]") {
	std::vector<int> v = {-8, -1, 15, 43, 82, 101, 110, 2456, 55345, 137556, 137576, 137577};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 96421.50);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

TEST_CASE("Function: IQR 6", "[output_hidden]") {
	std::vector<int> v = {-8, -1, 15, 43, 82, 101, 110, 2456, 55345, 137556, 137576, 137577, 137578};
	Node* head = nullptr;
	for(int i: v)
		head = insertEnd(head, i);

	REQUIRE(interQuartile(head) == 137537.0);
	
    while (head != nullptr) 
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

