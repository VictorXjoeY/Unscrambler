/* Victor Forbes - 9293394 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyUtils.h"

int partition(void *, int, int, int, int (*)(const void *, const void *));

void swap(void *, int, int, int);

char *readStretch(FILE *fp){
    char *stretch = NULL;
    int i = 0;

    do{
        stretch = (char *)realloc(stretch, (i + 1) * sizeof(char));
        fscanf(fp, "%c", stretch + i);
        i++;
    }while (!feof(fp) && stretch[i - 1] != '\n');

    stretch[i - 1] = '\0';

    return stretch;
}

int wordCompare(const void *a, const void *b){
	int x, y;

	x = strlen(*((char **)a));
	y = strlen(*((char **)b));

	if (x == y){
		return strcmp(*((char **)a), *((char **)b));
	}

	return x - y;
}

void quickSort(void *vector, int size, int start, int end, int (*compare)(const void *, const void *)){
    int q;

    if (start <= end){
        q = partition(vector, size, start, end, compare);
        quickSort(vector, size, start, q - 1, compare);
        quickSort(vector, size, q + 1, end, compare);
    }
}

int partition(void *vector, int size, int left, int right, int (*compare)(const void *, const void *)){
    int i, j;

    i = left;

    for (j = left + 1; j <= right; j++){
        if (compare(vector + j * size, vector + left * size) < 0){
            i++;
            swap(vector, size, i, j);
        }
    }

    swap(vector, size, left, i);

    return i;
}

void swap(void *vector, int size, int x, int y){
    void *aux;

    if (x != y){
        aux = malloc(size);

        memcpy(aux, vector + x * size, size);
        memcpy(vector + x * size, vector + y * size, size);
        memcpy(vector + y * size, aux, size);

        free(aux);
    }
}