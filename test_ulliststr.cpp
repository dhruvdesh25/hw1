#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite
void printlist(ULListStr& list) {
  for (size_t i = 0; i < list.size(); i++)
  {
    cout << list.get(i) << endl;
  }
}

int main() {
  ULListStr list;

  // 4 2 1 3
  list.push_back("1");
  list.push_front("2");
  list.push_back("3");
  list.push_front("4");

  printlist(list);

  cout <<"Front " << list.front() << endl;
  cout <<"Back " << list.back() << endl;
  list.pop_back();
  list.pop_front();   
  cout <<"List: " ;
  printlist(list);




}
