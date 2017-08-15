/* Victor Forbes - 9293394 */

#ifndef MY_UTILS_H
#define MY_UTILS_H

#define true 1
#define false 0

#define and &&
#define or ||

typedef unsigned char bool;

char *readStretch(FILE *);

int wordCompare(const void *, const void *);

void quickSort(void *, int, int, int, int (*)(const void *, const void *));

#endif