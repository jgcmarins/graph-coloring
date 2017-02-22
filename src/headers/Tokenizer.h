
#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tokenizer {

	public:

		static vector<string *> *splitString(string *str, const char *delimiter);
};

#endif