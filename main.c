//Victor Zuniga
//CS 310
//Project 1

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <time.h>
#include <string.h>

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

void number_generator(int size)
{
  srand(time(NULL));
  char f[] = ".txt";
  char s[sizeof(char)*(int)log10(size)];
  sprintf(s, "%d", size);
  strcat(s, f);

  int r;
  FILE *outfile;
  outfile = fopen(s, "w");
  for(int i = 0; i < size; i++)
    {
      r = rand();
      fprintf(outfile, "%d\n", r);
    }
  fclose(outfile);
}

void sorter(int size)
{
  char f[] = ".txt";
  char s[size+4];
  char t[size+18];
  char u[size+14];
  //char v[size+14];
  char ins[] = "_insertionsort.txt";
  char mer[] = "_mergesort.txt";
  //char qui[] = "_quicksort.txt";

  sprintf(s, "%d", size);
  sprintf(t, "%d", size);
  sprintf(u, "%d", size);
  //sprintf(v, "%d", size);
  strcat(s, f);
  strcat(t, ins);
  strcat(u, mer);
  //strcat(v, qui);
  
  FILE *infile;
  infile = fopen(s, "r");

  int insertion[size];
  int merge[size];
  //int quick[size];

  FILE *insertionfile;
  insertionfile = fopen(t, "w");
  FILE *mergefile;
  mergefile = fopen(u, "w");
  //FILE *quickfile;
  //quickfile = fopen(v, "w");
  for(int i = 0; i < size; i++)
    {
      fscanf(infile, "%d", &insertion[i]);
      merge[i] = insertion[i];
      //quick[i] = merge[i];
    }
  
  insertionsort(insertion, size);
  mergesort(merge, size);
  //quicksort(quick);
  
  for(int j = 0; j < size; j++)
    {
      fprintf(insertionfile, "%d\n", insertion[j]);
      fprintf(mergefile, "%d\n", merge[j]);
      //fprintf(quickfile, "%d\n", quick[j]);
    }
}

int main()
{


  number_generator(10);
  sorter(10);
  

  /***************************************************************
  int sample[] = {10, 5, 7, 2, 3, 8, 4, 1, 9, 6};
  int sample2[] = {10, 5, 7, 2, 3, 8, 4, 1, 9, 6};
  double len = sizeof(sample)/sizeof(*sample);
  mergesort(sample, len);
  insertionsort(sample2, len);
  for(int i = 0; i < 10; i++)
    {
      printf("%d\n", sample[i]);
      printf("%d\n", sample2[i]);
    }*/

  return 0;
}
