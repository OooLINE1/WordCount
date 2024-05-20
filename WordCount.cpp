#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<assert.h>
#include <fstream>
using namespace std;

long charac(string file) {
	char a;
	long count = 0;
	ifstream infile;
	infile.open(file.data());
	assert(infile.is_open());
	while (!infile.eof()) {
		infile >> a;
		count = count + 1;
	}
	//if (count >= 2) {
	//	count = count - 1;
	//}
	infile.close();
	return count;
}

long word(string file) {
	char a;
	long word = 0;
	int count = 0;
	ifstream infile;
	infile.open(file.data());
	assert(infile.is_open());
	infile >> noskipws;
	while (!infile.eof()) {
		infile >> a;
		if (a >= 65 && a <= 122 && count == 0) {
			count = count + 1;
		}
		if (count != 0 && a < 65 && a != 45) {
			word = word + 1;
			count = 0;
		}
		if (count != 0 && a > 122) {
			word = word + 1;
			count = 0;
		}
	}
	if (count != 0) {
		word = word + 1;
	}
	infile.close();
	return word;
}

int main(int text, char *text1[]) {
	string chac = "-c";
	string w = "-w";
	if (text == 2 || text == 1) {
		Sleep(5);
	}
	else {
		if (text1[1] == chac) {
			printf("×Ö·ûÊý£º%ld\n", charac(text1[2]));
		}
		else if (text1[1] == w) {
			printf("µ¥´ÊÊý£º%ld", word(text1[2]));
		}
	}
	return 0;
}

