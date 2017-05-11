/**
 * Dictionary.h
 */

#include "Bool.h"
#include "Text.h"

#ifndef _H_DICT_
#define _H_DICT_

typedef struct srtDictionaryHead * Dictionary;

Dictionary dict_create();
unsigned int dict_size(Dictionary);
void dict_set(Dictionary, Text, Text);
Text dict_get(Dictionary, Text);
void dict_destroy(Dictionary);
char** dict_keys (Dictionary);
void dict_print(Dictionary);
int dict_getSize(Dictionary);

#endif
