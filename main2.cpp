//Victor Zuniga
//CS 310
//Project 1

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <list>
using namespace std;
#include "Genandsort.h"

int main()
{
  //generate files of random numbers
  Genandsort g;
  g.number_generator(10);
  g.number_generator(100);
  g.number_generator(1000);
  g.number_generator(10000);
  g.number_generator(100000);

  /***************************************************************/
  //initialize filein and fileout
  ifstream filein;
  filein.open("10.txt");
  ofstream fileout;
  fileout.open("10_insertionsort.txt");

  //initialize inputNum and nums
  int inputNum;
  std::list<int> nums;

  //insert numbers from filein to nums list
  while(filein>>inputNum){nums.push_back(inputNum);}
  
  //sort nums, write sorted list to appropriate file, close file
  std::list<int> insertion = g.insertionsort(nums);
  for(std::list<int>::iterator it=insertion.begin(); it!= insertion.end(); it++)
  {fileout<<*it<<"\n";}
  fileout.close(); 

  //open appropriate file for next sort, sort, write sorted list to file, close file
  fileout.open("10_mergesort.txt");
  std::list<int> merge = g.mergesort(nums);
  for(std::list<int>::iterator it=merge.begin(); it!=merge.end(); it++)
  {fileout<<*it<<"\n";}
  fileout.close();

  //clear lists and close filein
  insertion.clear();
  merge.clear();
  nums.clear();
  filein.close();

  /***************************************************************/
  //open next filein and read numbers into nums list
  filein.open("100.txt");
  while(filein>>inputNum){nums.push_back(inputNum);}

  //open, sort, write, close
  fileout.open("100_insertionsort.txt");
  insertion = g.insertionsort(nums);
  for(std::list<int>::iterator it=insertion.begin(); it!=insertion.end(); it++)
  {fileout<<*it<<"\n";}
  fileout.close();

  //open, sort, write, close
  fileout.open("100_mergesort.txt");
  merge = g.mergesort(nums);
  for(std::list<int>::iterator it=merge.begin(); it!=merge.end(); it++)
  {fileout<<*it<<"\n";}
  fileout.close();

  //clear lists, close filein
  insertion.clear();
  merge.clear();
  nums.clear();
  filein.close();
  
  /***************************************************************/
  //open filein, read numbers
  filein.open("1000.txt");
  while(filein>>inputNum){nums.push_back(inputNum);}

  //open, sort, write, close
  fileout.open("1000_insertionsort.txt");
  insertion = g.insertionsort(nums);
  for(std::list<int>::iterator it=insertion.begin(); it!=insertion.end(); it++)
  {fileout<<*it<<"\n";}
  fileout.close();

  /////pick up with mergesort on 1000
  

  return 0;
}
