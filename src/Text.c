/*
* Text.c
*
*  Created on: 15/03/2017
*      Author: hpiza
*/

#include "Bool.h"
#include "Text.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define NACUTE_UPPER 165
#define NACUTE_LOWER 164 

#define AACUTE_UPPER 181
#define AACUTE_LOWER 160 

#define EACUTE_UPPER 144
#define EACUTE_LOWER 130

#define IACUTE_UPPER 214
#define IACUTE_LOWER 161 

#define OACUTE_UPPER 224
#define OACUTE_LOWER 162 

#define UACUTE_UPPER 233
#define UACUTE_LOWER 163 

struct strText {
	char *chars;
	unsigned int length;
};

Text text_create(const char *chars) {
	Text text = (Text)malloc(sizeof(struct strText));
	text->length = strlen((char *)chars) + 1;
	text->chars = (char *)malloc(sizeof(char) * text->length);
	unsigned int i = 0;
	for (i = 0; i < text->length; i++) {
		switch (chars[i])
		{
		case 'ñ':
			text->chars[i] = NACUTE_LOWER;
			break;
		case 'Ñ':
			text->chars[i] = NACUTE_UPPER;
			break;

		case 'á':
			text->chars[i] = AACUTE_LOWER;
			break;
		case 'Á':
			text->chars[i] = AACUTE_UPPER;
			break;

		case 'é':
			text->chars[i] = EACUTE_LOWER;
			break;
		case 'É':
			text->chars[i] = EACUTE_UPPER;
			break;

		case 'í':
			text->chars[i] = IACUTE_LOWER;
			break;
		case 'Í':
			text->chars[i] = IACUTE_UPPER;
			break;

		case 'ó':
			text->chars[i] = OACUTE_LOWER;
			break;
		case 'Ó':
			text->chars[i] = OACUTE_UPPER;
			break;

		case 'ú':
			text->chars[i] = UACUTE_LOWER;
			break;
		case 'Ú':
			text->chars[i] = UACUTE_UPPER;
			break;

		default:
			text->chars[i] = chars[i];
			break;
		}
	}
	text->chars[text->length] = '\0';

	return text;
}

Text text_clone(Text orig) {
	Text the_clone = text_create((char *)orig->chars);
	return the_clone;
}

void text_println(Text text) {
	puts((char *)(text->chars));
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
	Text out = text_create((char *)text->chars);
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
		//Si es ñ (164 en ASCII)
		switch (text->chars[i])
		{
		case (char)NACUTE_LOWER:
			text->chars[i] = NACUTE_UPPER;
			break;
		case (char)AACUTE_LOWER:
			text->chars[i] = AACUTE_UPPER;
			break;
		case (char)EACUTE_LOWER:
			text->chars[i] = EACUTE_UPPER;
			break;
		case (char)IACUTE_LOWER:
			text->chars[i] = IACUTE_UPPER;
			break;
		case (char)OACUTE_LOWER:
			text->chars[i] = OACUTE_UPPER;
			break;
		case (char)UACUTE_LOWER:
			text->chars[i] = UACUTE_UPPER;
			break;
		default:
			break;
		}
	}

	return text;
}

int text_indexOf(Text text, char letra)
{
	int i, len = text->length;
	for (i = 0; i < len; ++i)
	{
		if (text->chars[i] == letra)
			return i;
	}
	return -1;
}

Text text_concat(Text destino, const Text entrada)
{
	int i;
	Text final = text_create((char *)destino->chars);
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

Text text_replace(Text text, char oldChar, char newChar)
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
	unsigned int i;
	for (i = 0; i < len; i++) {
		//Si la letra es á, í, ó, ú
		if (t->chars[i] >= 160 && t->chars[i] <= 163) {
			//Se le van a restar 63, que es la diferencia en ASCII con sus respectivas sin acento
			//Ejemplo: á = 160, a = 97
			t->chars[i] -= 63;
		}
		//Si la no está de la 'A' a la 'Z' ni de la 'a' a la 'z', incluyendo las ñ's
		else if (!(!(t->chars[i] >= 'A' && t->chars[i] <= 'Z') || !(t->chars[i] >= 'a' && t->chars[i] <= 'z') || (t->chars[i] != NACUTE_UPPER && t->chars[i] != NACUTE_LOWER)))
		{
			//Para todas las demas vocales con acento dispersas en ASCII
			switch (t->chars[i])
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
	return t;
}

char text_charAt(Text t, int p)
{
	return t->chars[p];
}

Bool text_compare(Text t1, Text t2) {
	return strcmp((const char*)t1->chars, (const char*)t2->chars);
}