// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "sort.h"

//input str = 10 + 20 -2030 + 20 - 1
using namespace std;

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

/* This was the qns asked in 2015 olympiad. Given a input
   string Maximise the input and remove leading 0s
   */
void format_string() {

	string input_str;
	string res = "";

	cout << "Enter string";
	cin >> input_str;
	for (size_t i = 0; i < input_str.size(); i++) {
		res = res + input_str[i];
		if (input_str[i] == '-') {
			i++;
			res = res + input_str[i];
			i++;
			
			while (i < input_str.size() && input_str[i] == '0') {
				res += "+0";
				i++;
			}
			// Now when this loop comes out we will be out of leading 0.
			// So we need to concatenate "+" is there still exist number 
			// After leading 0
			if (i < input_str.size() && input_str[i] >= '1' && input_str[i] <= '9') {
				res += '+';
			}
			// We have to decrement i by one , because while loop had already gone past one 
			// When it came out and , for loop will increment again, so that character will miss
			// Need to count that character , hence decrementing.
			i--;
		}
	}

	cout << res << endl;
	cin >> input_str;
}

int main()
{  
	string wait_for_input;
	//int n;
//	char ch;
	int s[5] = { 10, 2, 9, 1, 3 };

//	format_string();
	//insertion_sort(s, (sizeof(s) / sizeof(s[0])));
	insertion_sort_v2(s, (sizeof(s) / sizeof(s[0])));
	for (int i = 0; i < 5; i++) {
		printf("%d \n", s[i]);
	}
	cin >> wait_for_input;
	/*printf("Enter a number \n");
	scanf_s("%d", &n);

	if (is_palindrome(n)) {
		printf("Entered number is palindrome");
	}
	else
	{
		printf("entered nunbre is not palidnrome");

	}
	scanf_s("%s", &ch);
	return 0;*/
}





