/*
 * Text.c
 *
 *  Created on: 15/03/2017
 *      Author: hpiza
 */
#include "Text.h"
#include "Bool.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct strText {
	char *chars;
	unsigned int length;
};

Text text_create(char *chars) {
	Text text = (Text) malloc(sizeof(struct strText));
	text->length = strlen(chars);
	text->chars = (char*) malloc((text->length + 1) * sizeof(char));
	strcpy(text->chars, chars);
	text->chars[text->length] = '\0';

	return text;
}

void text_println(Text text) {
	puts(text->chars);
}

unsigned int text_length(Text text) {
	return text->length;
}

void text_destroy(Text text)
{
	free(text->chars);
	free(text);
}

Text text_toLowerCase(Text text)
{
	int i;
	int len = text->length;

	for (i = 0; i < len; ++i)
	{
		if (text->chars[i] >= 'A' && text->chars[i] <= 'Z')
		{
			text->chars[i] += 32;
		}
		//Si es Ñ (165 en ASCII)
		if (text->chars[i] == (char)165)
			text->chars[i]++;//La ñ se encuentra una posicion arriba que Ñ en ASCII
	}
	Text out = text_create(text->chars);
	return out;
}

Text text_toUpperCase(Text text)
{
	int i;
	int len = text->length;

	for (i = 0; i < len; ++i)
	{
		if (text->chars[i] >= 'a' && text->chars[i] <= 'z')
		{
			text->chars[i] -= 32;
		}
		//Si es Ñ (165 en ASCII)
		if (text->chars[i] == 'ñ')
			text->chars[i]--;
	}
	Text out = text_create(text->chars);
	return out;
}

int text_indexOf(Text text, char letra)
{
	int i, len = text->length;
	for (i = 0; i < len; ++i)
	{
		if(text->chars[i] == letra)
			return i;
	}
	return -1;
}

Text text_concat(Text destino, const Text entrada)
{
	int i;
	Text final = text_create(destino->chars);
	int final_len = final->length, entrada_len = entrada->length;
	final->chars = (char*)realloc(final->chars, (final_len + entrada_len) * sizeof(char));
	for (i = 0; i < entrada_len; ++i)
	{
		final->chars[i + final_len] = entrada->chars[i];
	}
	final->chars[final_len + entrada_len] = '\0';
	final->length = final_len + entrada_len;

	return final;
}

void text_append(Text text, char* palabra)
{
	int i;
	int text_len = text->length, palabra_len = strlen(palabra);
	text->chars = (char*)realloc(text->chars, sizeof(char) * (text_len + palabra_len));
	for (i = 0; i < palabra_len; ++i)
	{
		text->chars[i + text_len] = palabra[i];
	}
	text->length += palabra_len;
}

Text text_replace(Text text, char oldChar, char newChar )
{
	int i, len = text->length;
	for (i = 0; i < len; ++i)
		if (text->chars[i] == oldChar)
			text->chars[i] = newChar;

	return text;
}

Text text_ansi(Text t)
{
	unsigned int len = t->length;
	int i;
	for (i = 0; i < len; i++) {
		//Si la letra es á, í, ó, ú
		if (t->chars[i] >= 160 && t->chars[i] <== 163) {
			//Se le van a restar 63, que es la diferencia en ASCII con sus respectivas sin acento
			//Ejemplo: á = 160, a = 97
			t->chars[i] -= 63;
		}
		//Si la no está de la 'A' a la 'Z' ni de la 'a' a la 'z', incluyendo las ñ's
		else if ((t->chars[i] <= 'A' && t->chars[i] >= 'Z') || (t->chars[i] <= 'a' && t->chars[i] >= 'z') || (t->chars[i] != 'Ñ' && t->chars[i] != 'ñ'))
		{
			//Para todas las demas vocales con acento dispersas en ASCII
			switch (len->chars[i])
			{
				case 130:
					t->chars[i] = 'e';
					break;
				case 181:
					t->chars[i] = 'A';
					break;
				case 144:
					t->chars[i] = 'E';
					break;
				case 214:
					t->chars[i] = 'I';
					break;
				case 224:
					t->chars[i] = 'O';
					break;
				case 233:
					t->chars[i] = 'U';
					break;
				default:
					t->chars[i] = '_';
			}
		}
	}
}

Text text_charAt(Text t, int p)
{
	return t->chars[p];
}

bool text_compare(Text t1, Text t2){
    return strcmp(t1, t2);
}