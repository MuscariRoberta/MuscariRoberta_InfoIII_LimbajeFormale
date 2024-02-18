#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

char* concatenate(const char* s1, const char* s2)
{
	char* rezultat = new char[strlen(s1) + strlen(s2) + 1];
	strcpy(rezultat, s1);
	strcat(rezultat, s2);
	return rezultat;
}

char* invers(const char* s)
{
	char* inv = new char[strlen(s) + 1];
	int lungime = strlen(s);
	for (int i = 0; i < lungime; i++)
		inv[i] = s[lungime - i - 1];
	inv[lungime] = '\0';
	return inv;
}

void substitutie(char* sir, char a, char b)
{
	int l = strlen(sir);
	for (int i = 0; i < l; i++)
		if (sir[i] == a) sir[i] = b;
}

size_t lungime(const char* s) {
	return strlen(s);
}

int main()
{
	char A[] = { 'a', 'b' , 'c' };
	char B[] = { 'x', 'y', 'z' };
	char C[] = { '1', '2', '3' };
	//concatenare
	const char* sir1 = "abba";
	const char* sir2 = "xyz";
	char* rezultat = concatenate(sir1, sir2);
	cout << "Concatenare: ";
	std::cout << rezultat << std::endl;
	delete[] rezultat;
	//inversare
	const char* s = "123";
	char* inv = invers(s);
	cout << "Inversare: ";
	std::cout << inv << std::endl;
	delete[] inv;
	//substitutie
	char sir[] = "aa ab ac baa";
	char a = 'a';
	char b = 'z';
	substitutie(sir, a, b);
	cout << "Substitutie: ";
	std::cout << sir << std::endl;
	//lungime
	const char* s3 = "a b aa ab ba";
	cout << "Lungime: ";
std:cout << lungime(s3);
	return 0;
}