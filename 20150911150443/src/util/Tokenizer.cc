
#include "../headers/Tokenizer.h"

vector<string *> *Tokenizer::splitString(string *str, const char *delimiter) {

	vector<string *> *parts = new vector<string *>();

	string::size_type begin = 0;
	string::size_type end = str->find(delimiter, begin);
	while(end != string::npos) {
		parts->push_back(new string(str->substr(begin, end - begin)));
		begin = end + 1;
		end = str->find(delimiter, begin);
	}

	parts->push_back(new string(str->substr(begin, end - begin)));

	return parts;
}