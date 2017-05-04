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

 void insertWord(Dictionary d)
 {

 	printf("Dame la palabra: \n");
 	Text word = text_readLine(NULL);

 	printf("Dame la definicion: \n");
 	Text definition = text_readLine(NULL);
 	dict_set(d, word, definition);
 }

 void getDefinition(Dictionary d)
 {
 	printf("Dame la palabra a buscar\n");
 	Text word = text_readLine(NULL);;
 	Text definition = dict_get(d, word);
 	text_println(definition);
 }

 void printDict(Dictionary d)
 {
 	char** words = dict_keys(d);
 	int size = dict_size(d), i;
 	for (i = 0; i < size; i++)
 	{
 		puts(words[i]);
 	}
 }

 int main() {
 	Text word = NULL;
 	Text definition = NULL;
 	Dictionary dictionary = NULL;

 	char aaa;
 //	char** a;

 	printf("Bienvenido al dicionario, estamos agregando palabras para fines ilustrativos\n");
 	dictionary = dict_create();

 	word = text_create("Casa");
 	definition = text_create("Donde vives");
 	dict_set(dictionary, word, definition);
 	//text_destroy(word);
 	//text_destroy(definition);
 	word = text_create("Hola!");
 	definition = text_create("Saludo en español");
 	dict_set(dictionary, word, definition);
 	//text_destroy(word);
 	//text_destroy(definition);
 	word = text_create("Piña");
 	definition = text_create("La casa de bob esponja");
 	dict_set(dictionary, word, definition);
 	//text_destroy(word);
 	//text_destroy(definition);
 	word = text_create("Pizza");
 	definition = text_create("Lo más delicioso del mundo");
 	dict_set(dictionary, word, definition);
 	//text_destroy(word);
 	//text_destroy(definition);
 	word = text_create("Mamá");
 	definition = text_create("Ejemplo de tilde");
 	dict_set(dictionary, word, definition);
 	//text_destroy(word);
 	//text_destroy(definition);

 	word = text_create("Casa");
 	definition = dict_get(dictionary, word);
 //	text_println(definition);
 	//scanf_s("%c", &aaa);

 	word = text_create("PiZza");
 	definition = dict_get(dictionary, word);
 //	text_println(definition);
 	//scanf_s("%c", &aaa);

 	word = text_create("PIñA");
 	definition = dict_get(dictionary, word);
 //	text_println(definition);

 	word = text_create("Ballena");
 	definition = text_create("Mamifero marino");
 	dict_set(dictionary, word, definition);

 	word = text_create("Bebe");
 	definition = text_create("Persona chiquita");
 	dict_set(dictionary, word, definition);
 	/*
 	a = dict_keys(dictionary);
 	int deep = dict_getSize(dictionary);
 	printf("///////////////////////////////\n");
 	for (int i = 0; i < deep; i++)
 	{
 		puts(a[i]);
 	}
 	*/
 	Bool end = FALSE;
 	int option = 0;
 	while (!end)
 	{
 		printf("Que desea hacer?\n");
 		printf("1. Insertar palabra\n");
 		printf("2. Obtener definición\n");
 		printf("3. Ver el diccionario completo\n");
 		printf("4. Salir\n");
 		scanf_s("%d", &option);

 		switch (option)
 		{
 		case 1:
 			insertWord(dictionary);
 			break;
 		case 2:
 			getDefinition(dictionary);
 			break;
 		case 3:
 			printDict(dictionary);
 			break;
 		case 4:
 			end = TRUE;
 			break;
 		default:
 			printf("Selecciona una opción valida\n");
 			break;
 		}
 	}

 	dict_destroy(dictionary);

 	scanf_s("%c", &aaa);

 	return 0;
 }
