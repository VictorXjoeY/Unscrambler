#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyUtils.h"
#include "MyTrie.h"
#include "MyUnscrambler.h"

struct ScrambledWord{
	char *word;
	int *vector;
};

struct UnscrambledWords{
	char **word;
	int n;
};

ScrambledWord *createScrambledWord(const char *word){
	ScrambledWord *sw = (ScrambledWord *)malloc(sizeof(ScrambledWord));
	int i;

	sw->vector = (int *)calloc(AMOUNT_OF_CHARACTERS, sizeof(int));

	for (i = 0; i < strlen(word); i++){
		sw->vector[word[i] - 'a']++;
	}

	sw->word = (char *)malloc((strlen(word) + 1) * sizeof(char));
	strcpy(sw->word, word);

	return sw;
}

UnscrambledWords *createUnscrambledWords(){
	return (UnscrambledWords *)calloc(1, sizeof(UnscrambledWords));
}

void unscrambleAux(Trie *t, const ScrambledWord *sw, UnscrambledWords *uw, char *word, int x){
	int i;
	
	if (t->flag){
		uw->word = (char **)realloc(uw->word, (uw->n + 1) * sizeof(char *));
		uw->word[uw->n] = (char *)malloc((strlen(word) + 1) * sizeof(char));
		strcpy(uw->word[uw->n], word);
		uw->n++;
	}

	for (i = 0; i < AMOUNT_OF_CHARACTERS; i++){
		if (sw->vector[i] and t->vector[i]){
			sw->vector[i]--;
			word[x] = t->vector[i]->c;
			unscrambleAux(t->vector[i], sw, uw, word, x + 1);
			sw->vector[i]++;
			word[x] = '\0';
		}
	}
}

void unscramble(Trie *t, const ScrambledWord *sw){
	char *word = (char *)calloc(100, sizeof(char));
	UnscrambledWords *uw = createUnscrambledWords();
	int i;

	unscrambleAux(t, sw, uw, word, 0);

	quickSort(uw->word, sizeof(char *), 0, uw->n - 1, &wordCompare);

	printf("--- %d words found! ---\n", uw->n);
	for (i = 0; i < uw->n; i++){
		printf("%s\n", uw->word[i]);
	}
	printf("--- %d words found! ---\n", uw->n);

	free(word);
	eraseUnscrambledWords(uw);
}

void eraseScrambledWord(ScrambledWord *sw){
	free(sw->word);
	free(sw->vector);
	free(sw);
}

void eraseUnscrambledWords(UnscrambledWords *uw){
	int i;

	for (i = 0; i < uw->n; i++){
		free(uw->word[i]);
	}

	free(uw->word);
	free(uw);
}