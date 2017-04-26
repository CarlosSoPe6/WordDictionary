/**
 * main.c
 * Impementación del TDA Dictionary
 */

#include <stdio.h>
#include "Bool.h"
#include "Dictionary.h"
#include "Stack.h"
#include "Text.h"

int main() {
	Text word = NULL;
	Text definition = NULL;
	Dictionary dictionary = NULL;

	char aaa;
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
	//scanf_s("%c", &aaa);

	word = text_create("PiZza");
	definition = dict_get(dictionary, word);
	text_println(definition);
	//scanf_s("%c", &aaa);

	word = text_create("PIñA");
	definition = dict_get(dictionary, word);
	text_println(definition);

	a = dict_keys(dictionary);

	scanf_s("%c", &aaa);

	return 0;
}