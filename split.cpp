/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
// #include <cstddef>
// #include <iostream>
// using namespace std;


/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if (in == nullptr)
  {
    return;
  }
  Node* next = in -> next;
  in->next = nullptr;
  
  if (in->value % 2 == 0)
  { 
    evens = in;
    split(next, odds, evens->next);
    // if (evens == nullptr) {
    //     evens = in;
    // }
    // else {
    //     Node* whattamidoing = evens;
    //     evens = in;
    //     evens->next = whattamidoing;
    // }
  }
  else{
    odds = in;
    split(next, odds->next, evens);
    // if(odds = nullptr)
    // {
    //   odds = in;
    // }
    // else 
    // {
    //   Node* whattamidoing = odds;
    //     odds = in;
    //     odds->next = whattamidoing;
    // }
  }

  // split (nextnode, odds, evens);
  in = nullptr;
}
/* If you needed a helper function, write it here */
