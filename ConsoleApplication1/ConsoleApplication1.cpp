// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "sort.h"
#include <random>

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

static const char lut[513] =
"000102030405060708090A0B0C0D0E0F"
"101112131415161718191A1B1C1D1E1F"
"202122232425262728292A2B2C2D2E2F"
"303132333435363738393A3B3C3D3E3F"
"404142434445464748494A4B4C4D4E4F"
"505152535455565758595A5B5C5D5E5F"
"606162636465666768696A6B6C6D6E6F"
"707172737475767778797A7B7C7D7E7F"
"808182838485868788898A8B8C8D8E8F"
"909192939495969798999A9B9C9D9E9F"
"A0A1A2A3A4A5A6A7A8A9AAABACADAEAF"
"B0B1B2B3B4B5B6B7B8B9BABBBCBDBEBF"
"C0C1C2C3C4C5C6C7C8C9CACBCCCDCECF"
"D0D1D2D3D4D5D6D7D8D9DADBDCDDDEDF"
"E0E1E2E3E4E5E6E7E8E9EAEBECEDEEEF"
"F0F1F2F3F4F5F6F7F8F9FAFBFCFDFEFF";

#define BIN_TO_HEX(c, bin, lut)  \
	do { unsigned char pos; \
		pos = (((bin) & (0xFF)) * 2);\
		(*c++) = (lut[pos++]);\
		(*c++) = (lut[pos]);\
		(*c) = ('\0');\
	} while(0)
	
/* Test sorting of random numbers in different batch size
*/
std::uniform_int_distribution<long long> dist(1, 2000000);
std::random_device rd;  //Will be used to obtain a seed for the random number engine
std::mt19937 gen(rd());

void batch_sort() {
	int arr[30];
	int output_array[100];
	int sort_length = sizeof(arr) / sizeof(arr[0]);
	std::cout << "length of array:" << sort_length << std::endl;
	bool random_generated = false;
	int sort_idx = 0;
	for (int i = 0; i < 100; i++) {
		/* Run this below loop 1000/30 times.*/
		if (!random_generated) {
			for (sort_idx = 0; sort_idx < sort_length; sort_idx++) {
				arr[sort_idx] = dist(gen);
			}
			random_generated = true;
			std::sort(std::begin(arr), std::end((arr)));
			/* Reset index to start for consuming */
			sort_idx = 0;
		}
		output_array[i] = arr[sort_idx++];
		/* Update rand no count as consumed */
		/* keep printing to check sort order */
		std::cout << "elements:" << output_array[i] <<std::endl;
		if (sort_idx == sort_length) {
			std::cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@ Consumed 30 elements" << std::endl;
			random_generated = false;
		}
	}
}

int main()
{  
	string wait_for_input;
	unsigned char data = 100;
	//std::cout << "Enter any decimal data" << std::endl;
	//std::cin >> data;

	batch_sort();
	std::cin >> wait_for_input;
	printf("value in hex = %02X", data);
	char str[4];
	char *pStr = str;
	BIN_TO_HEX(pStr, data, lut);
	std::cout << "converted in hex: " << str << std::endl;
	std::cin >> wait_for_input;


#if 0

	//int n;
//	char ch;
	int s[5] = { 10, 2, 9, 1, 3 };

//	format_string();
	//insertion_sort(s, (sizeof(s) / sizeof(s[0])));
	//insertion_sort_v2(s, (sizeof(s) / sizeof(s[0])));
	selection_sort(s, (sizeof(s) / sizeof(s[0])));
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
	return 0;
#endif
	return 0;
}





