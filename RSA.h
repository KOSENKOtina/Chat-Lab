#pragma once
#include <string>
#include <iostream>
#include <ctime>

using namespace std;
using std::string;

char* string_to_char(const string& str);
int gcd(int a, int b);
int sundaram(int n);
pair< pair< unsigned int, unsigned int>, pair<unsigned int, unsigned int> > generate_keys();
unsigned int* decrypt(unsigned int crypto[], int crlen, pair<unsigned int, unsigned int> secret);
unsigned int* encrypt(char txt[], int tlen, pair<unsigned int, unsigned int> open_key);
void readDecrypt(unsigned int decr[], int decrlen);
string from_ascii(unsigned int decr[], int decrlen);
unsigned int* to_ascii(char* txt);