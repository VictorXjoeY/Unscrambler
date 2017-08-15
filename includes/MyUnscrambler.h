#ifndef MY_UNSCRAMBLER_H
#define MY_UNSCRAMBLER_H

typedef struct ScrambledWord ScrambledWord;

typedef struct UnscrambledWords UnscrambledWords;

ScrambledWord *createScrambledWord(const char *);

UnscrambledWords *createUnscrambledWords();

void unscramble(Trie *, const ScrambledWord *);

void eraseScrambledWord(ScrambledWord *);

void eraseUnscrambledWords(UnscrambledWords *);

#endif