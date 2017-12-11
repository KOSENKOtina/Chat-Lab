#ifndef visionnaire_h
#define visionnaire_h

#include <string>
#include <ctype.h>

int Mod(int a, int b);
std::string Cipher(std::string input, std::string key, bool encipher);
std::string Encipher(std::string input, std::string key);
std::string Decipher(std::string input, std::string key);

#endif