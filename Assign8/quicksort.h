/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8
   PROGRAMMER: Branden Hidalgo
   LOGON ID:   z1663752
   DUE DATE:
 
   FUNCTION:   This program builds and sorts lists using the quick
               sort algorithm.
*********************************************************************/  

#ifndef  QUICKSORT_H
#define  QUICKSORT_H

//Swap two T items
template <class T>
void swap( T& x,  T& y)
{
 T temp;
 temp = x;
 x = y;
 y = temp;
 
 
}


template <class T>
int partition(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
 int pivotIndex, mid;
   T pivotValue;

   mid = (start + end) / 2;

   swap(set[start],set[mid]);

 pivotIndex = start;
   pivotValue = set[start];
 
   for (int scan = start + 1; scan <= end; scan++)
      {
      if (compare(set[scan], pivotValue))
         {
         pivotIndex++;
      swap(set[pivotIndex],set[scan]);
         }
      }

   swap(set[start],set[pivotIndex]);

   return pivotIndex; 
}

//The recursive quicksort function
template <class T>
void quickSort(vector<T>& set, int start, int end, bool (*compare)(const T&, const T&))
{
int pivotPoint;

   if (start < end)
      {
      pivotPoint = partition(set, start, end, compare);     // Get the pivot point
      quickSort(set, start, pivotPoint - 1, compare);       // Sort first sublist
      quickSort(set, pivotPoint + 1, end, compare);         // Sort second sublist
      }
}

//This function calls the recursive quick sort function
template <class T>
void quickSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
 quickSort(set, 0, set.size()-1, compare);
}




#endif
