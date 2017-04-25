/**
 * main.c
 * Impementación del TDA Dictionary
 */

#include <stdio.h>
#include <stdlib.h>
#include <Text.h>
#include <Dictionary.h>

int main(){
    Text word = NULL
    Text definition = NULL;
    Dictionary dictionary = NULL;    

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
}