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

void insertion_sort(int s[], int n)
{
	int i, j;

	for (i = 0; i < n; i++) {
		j = i;
		for (; j > 0 ;) {
			if (s[j] < s[j - 1]) {
				swap(&s[j], &s[j - 1]);
			}
			j = j - 1;
		}

	}

}

void insertion_sort_v2(int s[], int n)
{
	int i, j, key;

	for (i = 0; i < n; i++) {
		key = s[i];
		j = i - 1;
		while (j >= 0 && s[j] > key) {
			s[j + 1] = s[j];
			j = j - 1;
		}
		s[j + 1] = key;

	}
}








