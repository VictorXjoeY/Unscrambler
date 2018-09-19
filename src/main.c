/* Victor Forbes - 9293394 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trie.h"

int compare(const void *a, const void *b){
	int len_a, len_b;

	len_a = strlen(*(char **)a);
	len_b = strlen(*(char **)b);

	if (len_a == len_b){
		return strcmp(*(char **)a, *(char **)b);
	}

	return len_a - len_b;
}

int main(int argc, char *argv[]){
	char *str, **ans;
	int n, i;
	FILE *fp;
	Trie *t;

	t = trie_create();

	printf("Inserting dictionary...\n");

	// Inserting the entire dictionary.
	fp = fopen("dictionary.txt", "r");

	while (fscanf(fp, " %ms", &str) != EOF){
		trie_insert(t, str);
		free(str);
	}

	fclose(fp);

	printf("Dictionary inserted!\n");
	
	// Reading scrambled word.
	printf("Unscramble: ");
	scanf(" %ms", &str);

	// Unscrambling.
	printf("Unscrambling %s...\n", str);
	unscramble(t, str, &ans, &n);
	free(str);

	// Sorting solutions.
	qsort(ans, n, sizeof(char *), compare);

	// Printing solutions.
	printf("Unscrambled! Found %d words:\n", n);

	for (i = 0; i < n; i++){
		printf("%s\n", ans[i]);
		free(ans[i]);
	}

	free(ans);

	trie_destroy(t);

	return 0;
}