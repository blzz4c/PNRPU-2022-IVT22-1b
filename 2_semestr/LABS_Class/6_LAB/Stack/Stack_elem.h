#pragma once
#include <iostream>
using namespace std;

class Stack_elem 
{
    int data;
    Stack_elem* next;
public:
    Stack_elem();
    Stack_elem(Stack_elem*, int);
    Stack_elem(const Stack_elem&);
    int get_data() { return data; }
    Stack_elem* get_next() { return next; }
    void set_data(int new_data) { data = new_data; }
    void set_next(Stack_elem* new_next) { next = new_next; }
};