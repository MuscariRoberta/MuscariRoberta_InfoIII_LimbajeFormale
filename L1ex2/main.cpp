#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

std::string concatenate(const std::string& s1, const std::string& s2)
{
	return s1 + s2;
}

std::string repeat(const std::string& s, int n) {
	std::string rez;
	for (int i = 0; i < n; ++i)
		rez += s;
	return rez;
}

std::string reverse(const std::string& s) {
	std::string r;
	for (int i = s.length() - 1; i >= 0; --i)
		r += s[i];
	return r;
}

std::string extract(const std::string& s, int i, int j) {
	if (i < 0 || j >= s.length() || i > j) 
		return ""; // Returnez un șir gol în caz de indici incorecți
	return s.substr(i, j - i + 1); 
}

std::string replace(const std::string& s, const std::string& sub, const std::string& new_sub) {
	std::string rezultat = s; 
	size_t pozitie = rezultat.find(sub);
	if (pozitie != std::string::npos)
		rezultat.replace(pozitie, sub.length(), new_sub);
	return rezultat;
}
int main()
{
	std::string s1 = "abbc";
	std::string s2 = "x1y1";
	std::string R = concatenate(s1,s2);
	std::cout << R << std::endl;

	std::string s = "abc";
	int n = 3;
	std::string rez = repeat(s,n);
	cout << "Repeat: ";
	std::cout << rez << std::endl;

	std::string sir = "1234";
	std::string r = reverse(sir);
	cout << "Reverse: ";
	std::cout << r << std::endl;

	std::string s3 = "abcdefgij";
	std::string re = extract(s3, 3, 6);
	cout << "Extract: ";
	std::cout << re << std::endl;

	std::string s4 = "1234567";
	std::string sub = "345";
	std::string new_sub = "aaa";
	std::string rezultat = replace(s4, sub, new_sub);
	cout << "Replace: ";
	std::cout << rezultat << std::endl;
	return 0;
}