#define _CRT_SECURE_NO_WARNINGS
#include "Word.h"
#include <cstdio>
#include <iostream>
#include <iomanip>

namespace sdds {
    int searchWords(const Word words[], int num, const char word[]) {
        int i;
        int foundIndex = -1;
        for (i = 0; foundIndex == -1 && i < num; i++) {
            if (strCmp(words[i].letters, word) == 0) {
                foundIndex = i;
            }
        }
        return foundIndex;
    }

    void addWord(Word words[], int* index, const char newWord[]) {
        strCpy(words[*index].letters, newWord);
        words[*index].count++;
        (*index)++;
    }

    int readWord(char* word, FILE* fptr, int maxLen) {
        int ch;
        int i = 0;
        do {
            ch = fgetc(fptr);
            word[i++] = ch;
        } while (ch != EOF && !isspace(ch) && i < maxLen);
        word[i] = '\0';
        return !(i == 1 && ch == EOF);
    }

    void title(const char* value, int len) {
        std::cout << value << std::endl;
        std::cout << std::setw(len) << std::left << "Word";
        std::cout << "No of  occurrence." << std::endl << "------------------------------------------------" << std::endl;
    }

    void endList() {
        std::cout << "------------------------------------------------" << std::endl;
    }

    void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord) {
        std::cout << "Total number of words used: " << totNoWrds << std::endl;
        std::cout << "Total number of words overall: " << totalOverAll << std::endl;
        std::cout << "Longest word used had " << longestWord << " characters." << std::endl;
    }

    void print(const Word* w, int gotoNextLine, int len) {
        std::cout << std::setw(len) << std::left << w->letters;
        std::cout << std::setw(3) << std::right << w->count;
        if (gotoNextLine) std::cout << std::endl;
    }

    int findMaxLen(const Word words[], int noOfWords) {
        int longest = 0;
        int i;
        for (i = 0; i < noOfWords; i++) {
            if (longest < strLen(words[i].letters))
                longest = strLen(words[i].letters);
        }
        return longest;
    }

    void listWords(const Word words[], int noOfWords, const char* theTitle) {
        int i;
        int maxLen = findMaxLen(words, noOfWords);
        title(theTitle, maxLen);
        for (i = 0; i < noOfWords; i++) {
            print(&words[i], true, maxLen);
        }
        endList();
    }

    void swap(Word* p1, Word* p2) {
        Word w;
        w = *p1;
        *p1 = *p2;
        *p2 = w;
    }

    void sort(Word words[], int cnt, int sortType) {
        int i, j;
        for (i = 0; i < cnt - 1; i++) {
            for (j = 0; j < cnt - i - 1; j++) {
                if (sortType == SORT_BY_OCCURANCE) {
                    if (words[j].count < words[j + 1].count) {
                        swap(&words[j], &words[j + 1]);
                    }
                }
                else if (sortType == SORT_ALPHABETICALLY) {
                    if (strCmp(words[j].letters, words[j + 1].letters) > 0) {
                        swap(&words[j], &words[j + 1]);
                    }
                }
                else {

                }
            }
        }
    }

    int totalCount(const Word* words, int num) {
        int total = 0;
        do {
            total += words[--num].count;
        } while (num);
        return total;
    }

    void wordStats(const char* filename) {
        FILE* fptr = fopen(filename, "r");
        Word words[MAX_NO_OF_WORDS] = { {"",0} };
        char word[MAX_WORD_LEN];
        char lowerCaseWord[MAX_WORD_LEN];
        int NoOfWords = 0;
        int maxLen = 0;
        int foundIndex = 0;
        int wordCount = 0;
        if (fptr) {
            while (readWord(word, fptr, MAX_WORD_LEN)) {
                trim(word);
                toLowerCaseAndCopy(lowerCaseWord, word);
                if (lowerCaseWord[0] != 0) {
                    wordCount++;
                    if (maxLen < strLen(lowerCaseWord)) {
                        maxLen = strLen(lowerCaseWord);
                    }
                    if (NoOfWords == 0) {
                        addWord(words, &NoOfWords, lowerCaseWord);
                    }
                    else {
                        foundIndex = searchWords(words, NoOfWords, lowerCaseWord);
                        if (foundIndex < 0) {
                            foundIndex = NoOfWords;
                            addWord(words, &NoOfWords, lowerCaseWord);
                        }
                        else {
                            words[foundIndex].count++;
                        }
                    }
                }
            }
            std::cout << "---------------------------------------------------" << std::endl <<
                "Read " << wordCount << " words!" << std::endl <<
                "---------------------------------------------------" << std::endl;
            sort(words, NoOfWords, 1);
            listWords(words, NoOfWords, "List of words Sorted by occurance");
            sort(words, NoOfWords, 0);
            listWords(words, NoOfWords, "List of words Sorted alphabetically");
            totalWordsStat(NoOfWords, totalCount(words, NoOfWords), maxLen);
            fclose(fptr);
        }
        else {
            std::cout << "File \"" << filename << "\" not found!" << std::endl;
        }
    }

    void programTitle() {
        std::cout <<
            "This program reads a text file and analyzes and reports the number" << std::endl << "of words and their occurrences in the text file." << std::endl;
    }
}