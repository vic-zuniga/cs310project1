//Victor Zuniga
//CS 310
//Project 1

#ifndef GENANDSORT_H
#define GENANDSORT_H

class Genandsort
{
 private:
  std::list<int> merge(std::list<int> b, std::list<int> c, std::list<int> a);

 public:
  //Genandsort();

  void number_generator(int size);
  std::list<int> insertionsort(std::list<int> nums);
  std::list<int> mergesort(std::list<int> nums);
  
};

#endif
