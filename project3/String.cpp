#include "String.h"
#include <iostream>
#include <stdio.h>

using namespace std;

String::String() = default;
String::String(const string& str):str(str){}
String::String(const String& other)
{
	str = other.str;
}

void String::loadfile(const string& filename)
{
	ifstream file(filename);
	if (file.is_open()) {
		getline(file, str);
		file.close();
		cout << "Чтение файла успешно завершено." << endl;
	}
	else {
		cerr << "Неудалось произвести чтение файла." << endl;
	}
}

string String::getStr()
{
	return str;
}

ostream& operator<<(ostream& out, const String& other)
{
	return out << other.str << endl;
}

vector<string> String::Chisla()
{
    istringstream my_stream(str);
    string word;
    vector<string> valid_words;
    string decChars = "0123456789";
    bool isNegtive = false;
    while (my_stream >> word) {
        if (!word.empty()) {
            int countValidChar = 0;
            for (auto ind = 0; ind < word.size(); ind++) {
                if (word[ind] == '-')
                {
                    isNegtive = true;
                    break;
                }
                for (auto i = 0; i < decChars.size(); i++) {
                    if (word[ind] == decChars[i])
                    {
                        countValidChar++;
                        break;
                    }
                }
            }
            if (word.size() == countValidChar && isNegtive == false)
                valid_words.push_back(word);
            isNegtive = false;
        }
    }
    return valid_words;
}
void String::writeResultsToFile(const string& filename, vector<string> words)
{
	ofstream file(filename);
	file << "Отсортированная строка:" << endl;
	for (const auto& word : words) {
		file << word << endl;
	}
	cout << "Отсортированная строка была успешно записана в файл." << endl;
}