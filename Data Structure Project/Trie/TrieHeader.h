#ifndef TRIEHEADER_H_INCLUDED
#define TRIEHEADER_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <ctime>

#define ARRAY_SIZE 129

using namespace std;

struct TrieNode
{
    TrieNode *children[ARRAY_SIZE];
    int value;
};

struct Trie
{
    TrieNode *root;
    int Count;
};

TrieNode *createNode();
void Initialize(Trie *trie);
void Insert(Trie *trie, char *key);
int FreeNode(TrieNode *node);
int LeafNode(TrieNode *node);
bool DeleteHelper(TrieNode *node, char *key, int level, int length);
void Delete(Trie *trie, char *key);
bool DestroyedHelper(TrieNode *node);
void Destroyed(Trie *trie);
bool haveWord(Trie *node, char *key);
void ReplaceWord(char *oldWord, char *newWord, Trie *node);
void Display(Trie *node, char *key);
void readFile(Trie *trie);

void autoCompleteHelper(TrieNode *node, vector<char> temp, char *key, int level, int index);
void autoComplete(Trie *trie, char *key);

void setCountZero();
void allWordsHelper(TrieNode *node, vector<char> temp, int level);
void allWords(Trie *trie);

int chckMatchAndResize(string text, string pattern);
void StarBeforeWordHelper(TrieNode *node, vector<char> temp, int level, string pattern);
void StarBeforeWord(Trie *trie, string pattern);

bool chckMatch(string text, string pattern);
void StringMatchingHelper(TrieNode *node, vector<char> temp, int level, string pattern);
void StringMatching(Trie *trie, string pattern);


#endif // TRIEHEADER_H_INCLUDED
