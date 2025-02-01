#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val){
  if(tail_ == NULL || tail_->last == ARRSIZE) {
    Item* newItem = new Item();
    newItem->val[0] = val;
    newItem-> first = 0;
    newItem->last = 1;
    newItem->prev = tail_;
    newItem->next = NULL;
    

    if(tail_)
    {
      tail_->next = newItem;
     
    } else {
      head_ =newItem;
    }
    tail_ = newItem;
  } else {
    tail_->val[tail_->last] = val;
    tail_->last++;

  }
  
  size_++;
}

void ULListStr:: push_front(const std::string& val) {
  if (head_ ==NULL){
    Item* newItem = new Item();
    newItem->val[0] = val;
    newItem->first = 0;
    newItem->last = 1;
    newItem->next = NULL;
    newItem-> prev = NULL;
    head_ = newItem;
    tail_ = newItem;
  } 
  else{
      if (head_->first ==0){
        Item* newItem = new Item();
        newItem->val[ARRSIZE - 1] = val;
        newItem->first = ARRSIZE - 1;
        newItem->last = ARRSIZE;
        newItem->next = head_;
        newItem-> prev = NULL;
        head_->prev = newItem;
        head_ = newItem;
    } 
      else{
        head_->val[head_->first - 1] = val;
        head_->first--;
      }
  }
  size_++;
}

void ULListStr::pop_front(){
   if (empty()) return;

  head_->first++;
  size_--;
  if (head_->first == head_->last)
  {
    Item* temp= head_;
    head_ = head_->next;
    if(head_!=NULL) {
      head_->prev = NULL;
    } else{
      tail_ = NULL;
    }
    delete temp;
  }
  
  if(head_ != NULL && head_->first == ARRSIZE) 
  {
    Item* temp = head_;
    head_ = head_->next;
    if (head_!= NULL)
    {
      head_->prev = NULL;
    }
    else 
    {
      tail_ = NULL;
    }
    delete temp;
  }

}
void ULListStr::pop_back(){
  if (empty()) return;

  tail_->last--;
  size_--;
  if (tail_->first == tail_->last)
  {
    Item* temp= tail_;
    tail_ = tail_->prev;
    if(tail_ !=NULL) {
      tail_->next = NULL;
    }
    else{
      head_ = NULL;
    }
    delete temp;
  }
}

std::string const & ULListStr::back() const {
  if(tail_ == NULL)  throw std:: invalid_argument("List is empty");
  return tail_->val[tail_->last - 1];

}
std::string const & ULListStr::front() const {
  if (head_ == NULL) throw std::invalid_argument("List is empty");
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) return NULL;

  Item* current = head_;
  size_t count = 0;
  while ( current != NULL) {
    size_t itemSize = current->last - current-> first;
    if (count + itemSize > loc){
      return &(current->val[current->first + (loc - count)]);
    }
    count += itemSize;
    current = current->next;
  }
  return NULL;

}




void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
