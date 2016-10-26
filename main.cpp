//Victor Zuniga
//CS 310
//Project 1

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstddef>
#include <list>
#include <math.h>
using namespace std;

void insertionsort(int arr[], int len)
{
  int i,j,key;
  for(j = 1; j < len; j++)
    {
      key = arr[j];
      for(i = j - 1; i >= 0 && arr[i] > key; i--)
        {
          arr[i + 1] = arr[i];
        }
      arr[i + 1] = key;
    }
}

void merge(int arr1[], int arr2[], int arr[], double len1, double len2, double len)
{
  int i = 0;
  int j = 0;
  while(i + j < len)
    {
      if(j == len2 || ((i < len1) && (arr1[i] < arr2[j])))
        {
          arr[i + j] = arr1[i];
          i++;
        }
      else
        {
          arr[i + j] = arr2[j];
          j++;
        }
    }
}

void mergesort(int arr[], double len)
{
  if(len < 2) return;

  double mid = floor(len/2);
  int tmid = mid;
  double mid2 = ceil(len/2);
  int tmid2 = mid2;
  int arr1[tmid];
  int arr2[tmid2];
  for(int i = 0; i < mid; i++) arr1[i] = arr[i];
  for(int j = mid; j < len; j++) arr2[j-tmid] = arr[j];

  mergesort(arr1, mid);
  mergesort(arr2, mid2);
  merge(arr1, arr2, arr, mid, mid2, len);
}

int main()
{
  int blah[] = {10, 5, 7, 2, 3, 8, 4, 1, 9, 6};
  int blah2[] = {10, 5, 7, 2, 3, 8, 4, 1, 9, 6};
  double len = sizeof(blah)/sizeof(*blah);
  mergesort(blah, len);
  insertionsort(blah2, len);
  for(int i = 0; i < 10; i++)
    {
      cout<<blah[i]<<"  ";
      cout<<blah2[i]<<"  ";
    }

  return 0;
}
