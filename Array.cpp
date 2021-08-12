// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <iostream>
#include <stdexcept> //std::out_of_range

Array::Array (void)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
//RESPONSE placed each member variable on it's own line.
: data_ (),
cur_size_ (),
max_size_ ()
{

}

Array::Array (size_t length)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
//RESPONSE placed each member variable on it's own line.
: data_ (),
cur_size_ (length),
max_size_ (length)
{

}

Array::Array (size_t length, char fill)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
//RESPONSE placed each member variable on it's own line.
: data_ (),
cur_size_ (length),
max_size_ (length)
{
  for(size_t i=0; i<length; i++){
    data_[i] = fill;
  }
}


Array::Array (const Array & arr)
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.
//RESPONSE placed each member variable on it's own line.
: data_ (arr.data_),
cur_size_ (arr.cur_size_),
max_size_ (arr.max_size_)
{

}

Array::~Array (void)
{
  delete[] data_;
}

const Array & Array::operator = (const Array & rhs)
{
    // COMMENT The assignment operator needs to create a deep copy of the source
    // array. Otherwise, the copy will share a pointer with the original. When one goes out
    // of scope, the other will eventually crash.

    // COMMENT You have a recursive call here.
    //RESPONSE reads data_ variable from rhs and assigns it to self.data_
  data_ = rhs.data_;
  return *this;
}

char & Array::operator [] (size_t index)
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.
    //RESPONSE Tested range then threw exception if out of range, else continue.
  if(index > cur_size_ || index < 0){
    throw "Out of Range";
  } else{
    return data_[index];
  }
}

const char & Array::operator [] (size_t index) const
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.
    //RESPONSE Tested range then threw exception if out of range, else continue.
  if(index > cur_size_ || index < 0){
    throw "Out of Range";
  } else{
    return data_[index];
  }
}

char Array::get (size_t index) const
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.
    //RESPONSE Tested range then threw exception if out of range, else continue.
  if(index > cur_size_ || index < 0){
    throw "Out of Range";
  } else{
    return data_[index];
  }
}

void Array::set (size_t index, char value)
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.
    //RESPONSE Tested range then threw exception if out of range, else continue.
  if(index > cur_size_ || index < 0){
    throw "Out of Range";
  } else{
    data_[index] = value;
  }
}

void Array::resize (size_t new_size)
{
    // COMMENT The resize method should only increase the size of the allocation if
    // the new size is larger than the current memory allocation for the array. If resized,
    // you need to preserve the old data. Otherwise, you can just update cur_size_ to
    // reflect the new size.
    //RESPONSE Checked to see how new size comapres to max size to preserve data
    //but change allocation.

  if(new_size < cur_size_){
    throw "Truncated";
  } else if(new_size > max_size_){
    max_size_ = new_size;
  }
}

int Array::find (char ch) const
{
  int counter = 0;
  for(size_t i=0; i<cur_size_; i++){
    if(ch == data_[i]){
      return counter;
    } else{
      counter++;
    }
  }
  return -1;
}

int Array::find (char ch, size_t start) const
{
    // COMMENT You are to throw out of range exception if the index is invalid,
    // and not catch it.
    //RESPONSE Tested range then threw exception if out of range, else continue.
  if(start>cur_size_ || start < 0){
    throw "Out of Range";
  } else{
    int counter = 0;
    for(size_t i=start; i<cur_size_; i++){
      if(ch == data_[i]){
        return counter;
      } else{
        counter++;
      }
    }
  }
  return -1;
}

bool Array::operator == (const Array & rhs) const
{
    // COMMENT Check for self comparison first.
    //RESPONSE checked if self equaled the same address of rhs.
  if(this == &rhs){
    return true;
  }
  for(size_t i=0; i<cur_size_; i++){
    if(data_[i] != rhs[i]){
      return false;
    }
  }
  return true;
}

bool Array::operator != (const Array & rhs) const
{
    // COMMENT You can define operator != in terms of operator ==.
    //RESPONSE Defined != operator using ==
  if(*this == rhs){
    return false;
  } else{
    return true;
  }
}

void Array::fill (char ch)
{
  for(size_t i=0; i<cur_size_; i++){
    data_[i] = ch;
  }
}

void Array::shrink (void)
{
    // COMMENT Just updating the size is not shrinking the array. You also
    // need to update the array allocation.
    //RESPONSE Removed excess memory from data_ by only taking current size
    //updated max_size_ to shrinker allocated memory

  char* shrinker = new char(cur_size_);
  for(size_t i; i < cur_size_; i++){
    shrinker[i] = data_[i];
  }
  delete[] data_;
  data_ = shrinker;
  max_size_ = cur_size_;
}

void Array::reverse (void)
{
    // COMMENT There is no need to create a copy of the array to reverse its contents
    //RESPONSE Reversed array using for loop swapping highest and lowest index
    for(int low=0, high = cur_size_; low < high; low++, high--){
      int temp = low;
      low = high;
      high = temp;
    }
}

Array Array::slice (size_t begin) const
{

  char* copied = new char[cur_size_];
  int counter = 0;
  for(size_t i=begin; i<cur_size_; i++){
    copied[counter] = data_[i];
  }
  return *copied;
}

Array Array::slice (size_t begin, size_t end) const
{
  char* copied = new char[cur_size_];
  int counter = 0;
  for(size_t i=begin; i<end; i++){
    copied[counter] = data_[i];
  }
  return *copied;
}
