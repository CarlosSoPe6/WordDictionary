/**
 * main.c
 * Impementación del TDA Dictionary
 */
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "Bool.h"
 #include "Dictionary.h"
 #include "Stack.h"
 #include "Text.h"

 void insertWord(Dictionary d)
 {
     //char *aux = (char*) malloc(100 * sizeof(char));
	 char aux[256];
     //El primer gets nunca funciona
     gets(aux);
     printf("Dame la palabra: \n");
     //scanf("%s", aux);
	 gets(aux);

     //aux = (char*)realloc(aux, (strlen(aux) + 1) * sizeof(char));
     Text word = text_create(aux);

     printf("Dame la definicion: \n");
     //aux = (char*) malloc(500 * sizeof(char));
     gets(aux);
	 //sscanf("%s", aux);
     //aux = (char*)realloc(aux, (strlen(aux) + 1) * sizeof(char));
     Text definition = text_create(aux);
     dict_set(d, word, definition);
 }

 void getDefinition(Dictionary d)
 {
    char *aux = (char*) malloc(100 * sizeof(char));
    //El primer gets nunca funciona
    gets(aux);
  	printf("Dame la palabra a buscar\n");
    gets(aux);
    aux = (char*)realloc(aux, (strlen(aux) + 1) * sizeof(char));
 	Text word = text_create(aux);
    printf("Definicion: ");
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

 	printf("Bienvenido al dicionario, estamos agregando palabras para fines ilustrativos\n");
 	dictionary = dict_create();

 	word = text_create("Casa");
 	definition = text_create("Donde vives");
 	dict_set(dictionary, word, definition);

 	word = text_create("Hola!");
 	definition = text_create("Saludo en español");
 	dict_set(dictionary, word, definition);

 	word = text_create("Piña");
 	definition = text_create("La casa de bob esponja");
 	dict_set(dictionary, word, definition);

 	word = text_create("Pizza");
 	definition = text_create("Lo más delicioso del mundo");
 	dict_set(dictionary, word, definition);

 	word = text_create("Mamá");
 	definition = text_create("Persona que te dio a luz");
 	dict_set(dictionary, word, definition);

// 	word = text_create("Ballena");
//    definition = text_create("Mamifero marino");
//    dict_set(dictionary, word, definition);

 	word = text_create("Bebe");
 	definition = text_create("Persona chiquita");
 	dict_set(dictionary, word, definition);

 	Bool end = FALSE;
 	int option = 0;
 	while (!end)
 	{
 		printf("Que desea hacer?\n");
 		printf("1. Insertar palabra\n");
 		printf("2. Obtener definición\n");
 		printf("3. Ver el diccionario completo\n");
		printf("4. Imprimir la estructura del arbol\n");
 		printf("5. Salir\n");
 		scanf("%d", &option);

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
			dict_print(dictionary);
			break;
 		case 5:
 			end = TRUE;
 			break;
 		default:
 			printf("Selecciona una opción valida\n");
 			break;
 		}
 	}

 	dict_destroy(dictionary);

 	return 0;
 }
