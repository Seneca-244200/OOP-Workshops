#ifndef WORD_H
#define WORD_H

#include "cStrTools.h"
#include <cstdio> 

const int MAX_WORD_LEN = 21;
const int MAX_NO_OF_WORDS = 500;
const int SORT_BY_OCCURANCE = 1;
const int SORT_ALPHABETICALLY = 0;
namespace sdds {
	
	struct Word {
		char letters[MAX_WORD_LEN];
		int count;
	};

	int searchWords(const Word words[], int num, const char word[]);
	void addWord(Word words[], int* index, const char newWord[]);
	int readWord(char* word, FILE* fptr, int maxLen);
	void title(const char* value, int len);
	void endList();
	void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
	void print(const Word* w, int gotoNextLine, int len);
	int findMaxLen(const Word words[], int noOfWords);
	void listWords(const Word words[], int noOfWords, const char* theTitle);
	void swap(Word* p1, Word* p2);
	void sort(Word words[], int cnt, int sortType);
	int totalCount(const Word* words, int num);
	void wordStats(const char* filename);
	void programTitle();
}
#endif // WORD_H

