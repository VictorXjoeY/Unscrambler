/* Victor Forbes - 9293394 */

#ifndef MY_TRIE_H
#define MY_TRIE_H

#define AMOUNT_OF_CHARACTERS 26

typedef struct Trie Trie;

struct Trie{
	char c;
	bool flag;
	Trie **vector;
};

Trie *createTrie();

void insertWord(Trie *, const char *);

bool containsWord(const Trie *, const char *);

void printTrie(const Trie *);

void eraseTrie(Trie *);

#endif