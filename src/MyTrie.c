#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyUtils.h"
#include "MyTrie.h"

Trie *createTrie(){
	Trie *t = (Trie *)malloc(sizeof(Trie));

	t->vector = (Trie **)calloc(AMOUNT_OF_CHARACTERS, sizeof(Trie *));

	t->flag = false;

	return t;
}

void eraseTrie(Trie *t){
	int i;

	for (i = 0; i < AMOUNT_OF_CHARACTERS; i++){
		if (t->vector[i]){
			eraseTrie(t->vector[i]);
		}
	}

	free(t->vector);
	free(t);
}

void insertWordAux(Trie *t, const char *word, int x, int n){
	if (x == n){
		t->flag = true;
	}
	else{
		if (!t->vector[word[x] - 'a']){
			t->vector[word[x] - 'a'] = createTrie();
			t->vector[word[x] - 'a']->c = word[x];
		}

		insertWordAux(t->vector[word[x] - 'a'], word, x + 1, n);
	}
}

void insertWord(Trie *t, const char *word){
	insertWordAux(t, word, 0, strlen(word));
}

bool containsWordAux(const Trie *t, const char *word, int x, int n){
	if (t){
		if (x == n){
			return t->flag;
		}

		return containsWordAux(t->vector[word[x] - 'a'], word, x + 1, n);
	}
	
	return false;
}

bool containsWord(const Trie *t, const char *word){
	return containsWordAux(t, word, 0, strlen(word));
}

void printTrieAux(const Trie *t){
	int i;

	if (t){
		printf("%c", t->c);

		for (i = 0; i < AMOUNT_OF_CHARACTERS; i++){
			printTrieAux(t->vector[i]);
		}
	}
}

void printTrie(const Trie *t){
	int i;

	for (i = 0; i < AMOUNT_OF_CHARACTERS; i++){
		printTrieAux(t->vector[i]);
	}

	printf("\n");
}