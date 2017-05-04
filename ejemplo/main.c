/**
 * main.c
 * Impementación del TDA Dictionary
 */

#include <stdio.h>
#include <stdlib.h>
#include "Bool.h"
#include "Dictionary.h"
#include "Stack.h"
#include "Text.h"

int main() {
	Text word = NULL;
	Text definition = NULL;
	Dictionary dictionary = NULL;

	char** a;

	printf("Bienvenido al dicionario, estamos agregando palabras para fines ilustrativos\n");
	dictionary = dict_create();
	word = text_create("Puto");
	definition = text_create("El que lo lea");
	dict_set(dictionary, word, definition);
	text_destroy(word);
	text_destroy(definition);
	word = text_create("Casa");
	definition = text_create("Donde vives");
	dict_set(dictionary, word, definition);
	text_destroy(word);
	text_destroy(definition);
	word = text_create("Hola!");
	definition = text_create("Saludo en español");
	dict_set(dictionary, word, definition);
	text_destroy(word);
	text_destroy(definition);
	word = text_create("Piña");
	definition = text_create("La casa de bob esponja");
	dict_set(dictionary, word, definition);
	text_destroy(word);
	text_destroy(definition);
	word = text_create("Pizza");
	definition = text_create("Lo más delicioso del mundo");
	dict_set(dictionary, word, definition);
	text_destroy(word);
	text_destroy(definition);
	word = text_create("Mamá");
	definition = text_create("Ejemplo de tilde");
	dict_set(dictionary, word, definition);
	text_destroy(word);
	text_destroy(definition);

	word = text_create("Casa");
	definition = dict_get(dictionary, word);
	text_println(definition);

	word = text_create("PiZza");
	definition = dict_get(dictionary, word);
	text_println(definition);

	word = text_create("PIñA");
	definition = dict_get(dictionary, word);
	text_println(definition);

	a = dict_keys(dictionary);
	int deep = dict_getSize(dictionary);
	printf("///////////////////////////////\n");
	for (int i = 0; i < deep; i++)
	{
		puts(a[i]);
	}

	dict_destroy(dictionary);
	system("pause");

	return 0;
}
