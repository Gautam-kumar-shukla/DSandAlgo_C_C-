// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

bool is_palindrome(int input) {
	int temp = input, digit = 0, rev_num = 0;

	//reverse the nuber and conpare
	while (temp > 0) {
		digit = temp % 10;
		temp = temp / 10;
		rev_num = rev_num * 10 + digit;

	}

	if (rev_num == input) {
		return true;
	}
	else {
		return false;
	}
	
}

int main()
{
	int n;
	char ch;

	printf("Enter a number \n");
	scanf_s("%d", &n);

	if (is_palindrome(n)) {
		printf("Entered number is palindrome");
	}
	else
	{
		printf("entered nunbre is not palidnrome");

	}
	scanf_s("%s", &ch);
	return 0;
}





