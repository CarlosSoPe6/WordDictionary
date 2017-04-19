/**
 * Dictionary.h
 * TDA dictionary
 */

#include "Text.h"

#ifndef _H_DICT_
#define _H_DICT_

typedef struct srtDictionaryHead * Dictionary;

Dictionary dict_create();
unsigned int dict_size(Dictionary);
void dict_set(Dictionary, Text, Text);
Text dict_get(Dictionary, Text);
Text * dict_keys(Dictionary);
void dict_destroy();

#endif
