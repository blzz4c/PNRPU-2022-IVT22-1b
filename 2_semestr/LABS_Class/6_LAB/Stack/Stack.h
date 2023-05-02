#pragma once
#include "iostream"
#include "Stack_elem.h"
using namespace std;

class Stack 
{
    Stack_elem* top;
    int size;
public:
    Stack();
    Stack(Stack_elem*, int);
    Stack(const Stack&);
    ~Stack();
    Stack_elem* get_top() { return top; }
    int get_size() { return size; }
    void push(Stack_elem*);
    Stack_elem pop();
    bool isEmpty() { return size == 0; }
};