/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 8
   PROGRAMMER: Branden Hidalgo
   LOGON ID:   z1663752
   DUE DATE:
    
   FUNCTION:   Purpose: Sort a list of items using the recursive merge sort alogrithm
*********************************************************************/
    
#ifndef  MERGESORT_H
#define  MERGESORT_H


//this function merges two sorted subvectors
template <class T>
void merge(vector<T>& set,int low, int mid, int high, bool (*compare)(const T&, const T&))
{
 
   vector<T> temp(high - low + 1);

int i = low;  
int j = mid+1;  
int k = 0; 

   // While not at the end of either subvector
   while (i <= mid && j <= high)
      {
      if (compare(set[j], set[i]))
         {
	  temp[k] = set[j];
          j++;
 	  k++;
         }
      else
         {
          temp[k] = set[i];
  	  i++;
  	  k++;
         }
      }

   // Copy over any remaining elements of left subvector
   while (i <= mid)
      {
       temp[k] = set[i];
       i++;
       k++;
      }

   // Copy over any remaining elements of right subvector
   while (j <= high)
      {
       temp[k] = set[j];
       j++;
       k++;
      }

   // Copy merged elements back into original vector
   for (i = 0, j = low; j <= high; i++, j++)
       set[j] = temp[i];
}

//This recursive function divides a vector into two subvectors, sorts them,
// and then merges the two sorted subvectors.
template <class T>
void mergeSort(vector<T>& set,int low, int high, bool (*compare)(const T&, const T&))
{
int mid;

   if (low < high)
      {
      mid = (low + high)/2;     

      // Divide and conquer
   mergeSort(set, low, mid, compare);
   mergeSort(set, mid + 1, high, compare);

      //Combine
 merge(set, low, mid, high, compare);

      }
}

//sort the items in the vector set using merge sort and calls the recursive
//merge sort function
template <class T>
void mergeSort(vector<T>& set, bool (*compare)(const T&, const T&))
{
 mergeSort(set, 0, set.size()-1, compare);
}




#endif
