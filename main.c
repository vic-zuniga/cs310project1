//Victor Zuniga
//CS 310
//Project 1

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>
#include <time.h>
#include <string.h>

//Insertionsort function
void insertionsort(int arr[], int len)
{
  int i,j,key;
  for(j = 1; j < len; j++) //loop through the indices of the array
    {
      key = arr[j]; //current element

      for(i = j - 1; i >= 0 && arr[i] > key; i--) //loop through the elements to the left of the key
        {
          arr[i + 1] = arr[i]; //shift elements to the right
        }
      arr[i + 1] = key; //insert key in the proper position
    }
}

//Merge function
void merge(int arr1[], int arr2[], int arr[], double len1, double len2, double len)
{
  int i = 0;
  int j = 0;

  while(i + j < len)
    {
      if(j == len2 || ((i < len1) && (arr1[i] < arr2[j]))) //test whether the next element to be placed in arr comes from arr1
        {
          arr[i + j] = arr1[i]; //insert the next value from arr1 into arr
          i++;
        }
      else
        {
          arr[i + j] = arr2[j]; //insert the next value from arr2 into arr
          j++;
        }
    }
}

//Mergesort function
void mergesort(int arr[], double len)
{
  if(len < 2) return; //array is of length 1; trivially sorted

  double mid = floor(len/2); //midpoint index of the array based on floor division
  int tmid = mid; //int of mid
  double mid2 = ceil(len/2); //midpoint index of the array based on ceiling division
  int tmid2 = mid2; //int of mid2

  int arr1[tmid]; //create subarrays
  int arr2[tmid2];

  for(int i = 0; i < mid; i++) arr1[i] = arr[i]; //fill array1
  for(int j = mid; j < len; j++) arr2[j-tmid] = arr[j]; //fill array2

  mergesort(arr1, mid); //mergesort call on the 1st half
  mergesort(arr2, mid2); //mergesort call on the 2nd half
  merge(arr1, arr2, arr, mid, mid2, len); //merge the sorted halves
}

// Partition function
int partition( int a[], int l, int r) {
   int pivot, i, j, t;                            // Declare all variables before use
   pivot = a[l];                                  // Select first element as pivot
   i = l;
   j = r+1;
    
   while( 1) {
    do ++i; while( a[i] <= pivot && i <= r );     // ++i means increment the value of i, and then return the incremented value.
    do --j; while( a[j] > pivot );
    if( i >= j ) break;
    t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}

// Quicksort function
void quickSort( int a[], int l, int r) {
   int j;
   if( l < r ) {
      j = partition( a, l, r);              // Partition array around first element  
     quickSort( a, l, j-1);                 // Apply quicksort on left of pivot
     quickSort( a, j+1, r);                 // Apply quicksort on right of pivot
   }
}

//Number generator function
void number_generator(int size)
{
  srand(time(NULL)); //set rand function seed based on the time

  char f[] = ".txt";
  char s[sizeof(char)*(int)log10(size)];
  sprintf(s, "%d", size);
  strcat(s, f); //create the output filename based on the size

  int r;
  FILE *outfile;
  outfile = fopen(s, "w");
  for(int i = 0; i < size; i++) //write the amount of random numbers size indicates
    {
      r = rand();
      fprintf(outfile, "%d\n", r);
    }

  fclose(outfile);
}

//Driver function
void sorter(int size)
{
  number_generator(size); // generate the file of random numbers

  char f[] = ".txt"; //create the pieces needed for all of the filenames
  char s[size+4];
  char t[size+18];
  char u[size+14];
  char v[size+14];
  char ins[] = "_insertionsort.txt";
  char mer[] = "_mergesort.txt";
  char qui[] = "_quicksort.txt";

  sprintf(s, "%d", size);
  sprintf(t, "%d", size);
  sprintf(u, "%d", size);
  sprintf(v, "%d", size);
  strcat(s, f); //create the filenames
  strcat(t, ins);
  strcat(u, mer);
  strcat(v, qui);
  
  FILE *infile;
  infile = fopen(s, "r");

  int insertion[size]; //the arrays to be sorted by their respective sort
  int merge[size];
  int quick[size];

  FILE *insertionfile;
  insertionfile = fopen(t, "w");
  FILE *mergefile;
  mergefile = fopen(u, "w");
  FILE *quickfile;
  quickfile = fopen(v, "w");

  for(int i = 0; i < size; i++) //fill the arrays to be sorted with the random numbers from the appropriate file
    {
      fscanf(infile, "%d", &insertion[i]);
      merge[i] = insertion[i];
      quick[i] = merge[i];
    }
  
  // Run insertion sort
  clock_t startIn = clock();
  insertionsort(insertion, size);
  clock_t finishIn = clock();

  double timeIn = ((double)(finishIn-startIn))/CLOCKS_PER_SEC;
  printf("%-32d%-20s%-10f\n", size, "Insertion Sort", timeIn); //runtime
  
  // Run merge sort
  clock_t startMe = clock();
  mergesort(merge, size);
  clock_t finishMe = clock();

  double timeMe = ((double)(finishMe-startMe))/CLOCKS_PER_SEC;
  printf("%-32d%-20s%-10f\n", size, "Merge Sort", timeMe); //runtime

  // Run quicksort
  clock_t startQu = clock();
  quickSort(quick, 0, size);
  clock_t finishQu = clock();

  double timeQu = ((double)(finishQu-startQu))/CLOCKS_PER_SEC;
  printf("%-32d%-20s%-10f\n", size, "Quick Sort", timeQu); //runtime
  
  for(int j = 0; j < size; j++) //write the values in the sorted arrays to the appropriate files
    {
      fprintf(insertionfile, "%d\n", insertion[j]);
      fprintf(mergefile, "%d\n", merge[j]);
      fprintf(quickfile, "%d\n", quick[j]);
    }

  fclose(infile); //close files
  fclose(insertionfile);
  fclose(mergefile);
  fclose(quickfile);
}

int main(int argc, char* argv[])
{

  printf("Input size (N): (# of numbers)  Sorting algorithm:  Time cost (sec):\n");
  sorter(10); //generate random numbers, sort, and create appropriate files
  sorter(100);
  sorter(1000);
  sorter(10000);
  sorter(100000);

  printf("Type Y to delete generated files, type anything else to exit.\n");
  char answer;
  int status;
  scanf("%c", &answer);
  if(answer == 'y' || answer == 'Y')
    {
      system("rm 1*.txt"); 
      printf("Files deleted.\n");
    }

  return 0;
}
