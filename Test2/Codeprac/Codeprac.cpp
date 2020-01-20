// Codeprac.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"


void ques1() {
	char name[50] = "";
	char dob[50] = "";
	std::cin >> name;
	std::cin >> dob;

	for (int i = 0; i < *(&name + 1) - name; i++)
	{
		if (name[i] != 0)
			std::cout << name[i];
		if (dob[i] != 0)
			std::cout << dob[i];

		if (name[i] == 0 && dob[i] == 0)
			break;
	}
}


void ques2() {
	char n[50];
	char opt;
	int tt = 0;

	std::cin >> n;

	for (int i = 1; i < *(&n + 1) - n; i++) {
		if (n[i] == '-') {
			tt = i;
			opt = n[i + 1];
			break;
		}
	}

	char *num = new char[tt];
	int g = 0;

	for (int i = 0; i < tt; i++)
	{
		g = g * 10 + n[i] - '0';
	}

	int temp = 0;
	if (opt == 'o') {
		while (g >= temp) {
			if (temp % 2 != 0) {
				std::cout << temp << '|';
			}
			temp++;
		}
	}
	else if (opt == 'e') {
		while (g >= temp) {
			if (temp % 2 == 0 && temp != 0) {
				std::cout << temp << '|';
			}
			temp++;
		}
	}
}

void ques3() {
	char text[50] = "";
	char c = 0;
	int count = 0, temp = 0;
	std::cin >> text;

	for (int i = 0; text[i] != 0; i++)
	{
		if (text[i] == '/')
			continue;
		temp = text[i];
		for (int j = i; text[j] != 0; j++)
		{
			if (temp == text[j] && text[j] != '/') {
				count++;
				c = text[j];
				text[j] = '/';
			}
		}
		std::cout << c << count << '\n';

		//std::cout << text[i] << count;
		count = 0;
	}
}

int main()
{

	//uncomment the method to test question

	//ques1();
	//ques2();
	//ques3();
	
	
	system("Pause");
	return 0;
}

