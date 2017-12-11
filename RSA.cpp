
#include <cmath>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;


/////////////////////////////////////////////////////////////////////
//Алгоритм "решето Сундарама". Выбирает все простые числа
//до заданного (случайно сгенерированного).
int sundaram(int n)
{
	int *a = new int[n], i, j, k;
	memset(a, 0, sizeof(int) * n);
	for (i = 1; 3 * i + 1 < n; i++)
	{
		for (j = 1; (k = i + j + 2 * i*j) < n && j <= i; j++)
			a[k] = 1;
	}
	//Выбирает из списка простых чисел ближайшее к заданному.
	for (i = n - 1; i >= 1; i--)
		if (a[i] == 0)
		{
			return (2 * i + 1);
			break;
		}
	delete[] a;
}

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}


	char* string_to_char(const string& str) {
		int size = str.size();
		char *ch = new char[size + 1];
		for (int i = 0; i < size; i++)
			ch[i] = str[i];
		ch[size] = 0;
		return ch;
	}

	unsigned int* encrypt(char txt[],int tlen,  pair<unsigned int, unsigned int> open_key) {
		int b = 301;
		int c;
		int i = 0;
		
		unsigned int *CryptoText = new unsigned int[tlen];
		for (int j = 0; j < tlen; j++)
		{
			c = 1;
			unsigned int i = 0;
			int ASCIIcode = (static_cast<int>(txt[j])) + b;
			while (i<open_key.first)
			{
				c = c*ASCIIcode;
				c = c % open_key.second;
				i++;
			}
			CryptoText[j] = c;
			b += 1;
		}
		return CryptoText;
	}

	unsigned int* decrypt(unsigned int crypto[], int crlen, pair<unsigned int, unsigned int> secret) {
		int b = 301;
		int m;
		unsigned int *Tdecrypt = new unsigned int[crlen];
		for (int j = 0; j < crlen; j++)
		{
			m = 1;
			unsigned int i = 0;
			while (i<secret.first)
			{
				m = m*crypto[j];
				m = m % secret.second;
				i++;
			}
			m = m - b;
			Tdecrypt[j] = m;
			b += 1;
		}
		return Tdecrypt;
	}

	pair< pair< unsigned int, unsigned int>, pair<unsigned int, unsigned int> > generate_keys() {
		srand((unsigned)time(NULL));
		int p = rand() % 100;
		int q = rand() % 100;
		int p_simple = sundaram(p);
		int q_simple = sundaram(q);
	
		unsigned int n = p_simple*q_simple;
		int d, d_simple = 0;
		while (d_simple != 1)
		{
			d = rand() % 100;
			d_simple = gcd(d, ((p_simple - 1)*(q_simple - 1)));
		}
		unsigned int e = 1, e_simple = 0;
		while (e_simple != 1)
		{
			e += 1;
			e_simple = (e*d) % ((p_simple - 1)*(q_simple - 1));
		}
		pair<unsigned int, unsigned int> open(e, n);
		pair<unsigned int, unsigned int> secret(d, n);
		pair< pair<unsigned int, unsigned int>, pair<unsigned int, unsigned int> > keys (open, secret);
		return keys;
	}

	void readDecrypt(unsigned int decr[], int decrlen) {
		for (int i = 0; i < decrlen; ++i)
			cout << static_cast<char>(decr[i]);
	}
	
	string from_ascii(unsigned int decr[], int decrlen) {
		string s = "";
		for (int i = 0; i < decrlen; ++i)
			s+= static_cast<char>(decr[i]);
		return s;
	}
	unsigned int* to_ascii(char* txt) {
		string s = txt;
		unsigned int* n = new unsigned int[s.length()];
		for (int i = 0; i < s.length(); ++i) 
			n[i] = static_cast<int>(txt[i]);
		return n;
	}