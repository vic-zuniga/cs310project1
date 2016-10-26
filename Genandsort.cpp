//Victor Zuniga
//CS 310
//Project 1

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <list>
#include <math.h>
using namespace std;
#include "Genandsort.h"

//Genandsort::Genandsort(){}

void Genandsort::number_generator(int size)
{
  srand(time(NULL));
  const string f = ".txt";
  stringstream s;
  s << size << f;
  int r;
  ofstream file;
  file.open(s.str().c_str());
  for(int i = 0; i < size; i++)
    {
      r = rand();
      file << r << "\n";
    }
  file.close();
}

  /***************************************************************/

std::list<int> Genandsort::insertionsort(std::list<int> nums)
{
  int arr[nums.size()];
  int tmp = 0;
  int i,j,key;
  std::list<int> sortnums;
  for(std::list<int>::iterator it=nums.begin(); it!=nums.end(); it++)
  {
    arr[tmp] = *it;
    tmp++;
  }
  
  for(j=2; j < nums.size(); j++)
  {
    key = arr[j];
    for(i = j - 1; i >= 0 && arr[i] > key; i--)
    {
      arr[i + 1] = arr[i];
    }
    arr[i + 1] = key;
  }

  tmp = nums.size();
  nums.clear();

  for(int k = 0; k < tmp; k++)
  {
    nums.push_back(arr[k]);
  }
  return nums;
}

  /***************************************************************/

std::list<int> Genandsort::merge(std::list<int> b, std::list<int> c, std::list<int> a)
{
  while(!b.empty() && !c.empty()) //lists b and c are both not empty
  {
    if(b.front() < c.front()) //first element in b is less than first element in c
    {
      a.push_back(b.front()); //place leftmost element of b at the rightmost position of a
      b.pop_front(); //remove leftmost element of b
    }
    else //first element in c is less than/equal to first element in b
    {
      a.push_back(c.front()); //place leftmost element of c at the rightmost position of a
      c.pop_front(); //remove leftmost element of c
    }
  }

  while(!b.empty())
  {
    a.push_back(b.front());
    b.pop_front();
  }

  while(!c.empty())
  {
    a.push_back(c.front());
    c.pop_front();
  }

  return a;
}

  /***************************************************************/
std::list<int> Genandsort::mergesort(std::list<int> nums)
{
  int n = nums.size(); //set n to size of nums
  if(n < 2) return nums; //list is trivially sorted

  std::list<int> b, c, d; //create lists

  while(b.size() < floor(n/2)) //while b is smaller than half of n (floor division)
  {
    b.push_back(nums.front()); //place the leftmost element of nums at the rightmost position of b
    nums.pop_front(); //remove the leftmost element of nums
  }
  while(!nums.empty()) //while b is equal/larger than half of n and nums is not empty
  {
    c.push_back(nums.front()); //place the leftmost element of nums at the rightmost position of c
    nums.pop_front(); //remove the leftmost element of nums
  }
 
  mergesort(b); //perform mergesort on first half
  mergesort(c); //perform mergesort on second half
  d = merge(b,c,nums); //merge sorted halves
  
  return d; //return merged whole
}


