#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyUtils.h"
#include "MyTrie.h"
#include "MyUnscrambler.h"

#include <time.h>

int main(int argc, char *argv[]){
	FILE *fp = fopen("Dictionary.txt", "r"); // Opening the dictionary.
	Trie *t = createTrie();
	ScrambledWord *sw;
	char *word;
	int i, n;

	double generateTrieTime, printTrieTime, unscrambleTime;
	clock_t start, end;
	start = clock();

	// Reading number of words.
	fscanf(fp, "%d%*c", &n);

	// Reading each word from the disk and inserting in the Trie.
	for (i = 0; i < n; i++){
		word = readStretch(fp);
		insertWord(t, word);
		free(word);
	}

	// Closing the file.
	fclose(fp);

	end = clock();
	generateTrieTime = (double)(end - start) / CLOCKS_PER_SEC;

	start = clock();

	// Printing the Trie. Each character is a tree node.
	printTrie(t);

	end = clock();
	printTrieTime = (double)(end - start) / CLOCKS_PER_SEC;

	// Reading the scrambled word and organizing it to make it
	// easier to process.
	printf("Word to be unscrambled: ");
	word = readStretch(stdin);
	sw = createScrambledWord(word);
	free(word);

	start = clock();

	// Generating all the possible words that could be written
	// using the characters in the scrambled word.
	unscramble(t, sw);

	end = clock();
	unscrambleTime = (double)(end - start) / CLOCKS_PER_SEC;

	printf("Time it took to generate the Trie: %.3lf\n", generateTrieTime);
	printf("Time it took to print the Trie: %.3lf\n", printTrieTime);
	printf("Time it took to unscramble the word: %.3lf\n", unscrambleTime);

	// Freeing allocated memory.
	eraseScrambledWord(sw);
	eraseTrie(t);

	return 0;
}