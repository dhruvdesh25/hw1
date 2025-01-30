/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;

void printlist(Node* head){
  while(head != NULL)
  {
    cout << head->value << ">";
    head = head->next;
    cout << "NULL" <<endl;

  }
}

void deletelist(Node* head){
  while(head != NULL)
  {
    Node* temp = head;
    head = head->next;
    delete temp;

  }
}

int main(int argc, char* argv[])
{
   Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, new Node(6, NULL))))));
   Node* odds = NULL;
   Node* evens = NULL;

   split(head,odds,evens);
  //  printlist(odds);
  //  printlist(evens);
  
   deletelist(odds);
   deletelist(evens);
   

  
}


