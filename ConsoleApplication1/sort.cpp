#include "stdafx.h"
#include "sort.h"

static void swap(int *a, int *b) {
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}
/*
Insertion sort: Method for sorting that starts with 
a single element (thus forming a trivial sorted list)
and then incrementally sorts the remaining element so that
the list stay sorted

I | N S E R T I O N S O R T
I N | S E R T I O N  S O R T
I N S | E R T I O N S O R T 
E I N S | R T I O N  S O R T
E I N R S | T I O N S O R T 
E I N R S T | I O N S O R T 

*/

/*Insertion sort
The below implementation is straight forward .
Its converted to code from the text of insertion sort which is 

1. Create two partition. One called trivial sorted partition with first element
2. Another partition with rest of the unsorted element .
3. Outer loop controls the unsorted partition whereas inner loop controls the sorted partition.
3. Outer loop each time sends the current first element to the inner loop which is s[j]
4. Inner loop compares the received first element of outer loop to its elements from sorted partitions
    Inner loops navigates to sorted partiton using [j-1] index .
	Jth=====> index is unsorted partition
	j-1th ====> index is sorted partition.
*/



void insertion_sort(int s[], int n)
{
	int i, j;

	for (i = 1; i < n; i++) {
		j = i;
		for (; j > 0 ;) {
			/* jth index is from un-sorted partition
			   j-1th index is from sorted partiton.
			   if the element from unsorted partition is less than sorted partion 
			   then swap and keep swapping untill it is false.
			   If it is not then no need to compare further
			*/
			if (s[j] < s[j - 1]) {
				swap(&s[j], &s[j - 1]);
			}
			else {
				break;
			}
			j = j - 1;
		}

	}

}
/* Insertion sort v2 method:

As we know in both insertion sort and selection sort, we start with two partition of array
namely "trivially sorted array" which is nothing but array with index 0 and rest all the elements are 
part of unsorted array.

In case of insertion sort, let's start with the array index 0 as first partition (sorted array)
and keep rest all in unsorted array. It will have two loops as described below.

1. Outer loop will run for unsorted array and inner loop will run for sorted array.
2. Outer loop will start from the index i=1 and hence inner loop will start from (1-i=0)th index, 
   containing only one element as trivially sorted partition.
3. Inner loop can have two different variants, in the below one following steps can be used.
  3a. Store the first element of unsorted array as key.
  3b. Now enter the inner loop, while first checking that we have valid inner index (index >= 0)
	  and value at highest index of current sorted array is greater than the 
	  value at first index of unsorted array which is nothing but stored as "key".
	  If the condition is true , that means the "key" element should go inside the sorted array
	  or "Insert" it inside the current sorted array.
  3c. To find the exact insertion point ,first move the highest element of sorted array to the 
      postion where "key" is stored in unsorted array===>line number 68. 
  3d. Now decrement the index of sorted array by one, so that we can compare the "key" from the next element 
      of the sorted array.
  3e. Keep repeating this pattern (3b to 3d) untill sorted array's element are less than the "key". The moment
	  we reached index where the sorted array element is less than "key", then come out of loop and copy the key at
	  one index greater than than the current index where we broke out of the loop ===> line no 80.

4. Keep doing this for all the next elements of unsorted array as traversed by outer loop one by one. 

*/
void insertion_sort_v2(int s[], int n)
{
	int i, j, key;

	for (i = 0; i < n; i++) {
		key = s[i];  /* This is picking elements one by one from unsorted array, controlled by outer loop */
		j = i - 1;  /* This is for picking elements from sorted array */

		/* Compare the highest element of sorted array partition(initially it will be at 0th index )
		   from the first element of unsorted array partition(initially it will be at 1th index)
		*/
		while (j >= 0 && s[j] > key) {
			/* If the element of sorted partition is > than first element("key") of unsorted partition
			   then we need to also compare this first element("key" to previous elements in sorted partition as well.
			   This is needed to find the exact postion where we can insert the element("key") from unsorted
			   partition into sorted partition. But before doing that we can definitely move the element
			   of sorted partion which we just compared to the postion of the index of first element("key") of 
			   unsorted array .
			
			*/
			s[j + 1] = s[j]; /* Move the element from sorted partiton to the index of first element in unsorted partition*/
			j = j - 1; /* Decrement the index of sorted partiton , so that we can compare the key with rest of the elements in 
					      sorted partition
					   */
		}
		s[j + 1] = key; /* Once we are out of the loop , it means this is the place where we can insert the key */

	}
}

int find_min(int arr[], int n)
{
	int j, temp;
	int min = arr[0];

	for (j = 1; j < n; j++) {
		if (arr[j] < min) {
			temp = min;
			min = arr[j];
			arr[j] = temp;
		}
	}
	return min;
	
}

void selection_sort(int s[], int n)
{
	int i, j, min;
	int *p = s;

	for (i = 0; i < n; i++) {
		min = find_min(s + i, n - i);
		s[i] = min;
	}

}







