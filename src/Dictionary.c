/**
 * Dictionary.c
 * TDA dictionary
 */
#include <stdio.h>
#include <stdlib.h>

#include "Bool.h"
#include "Dictionary.h"
#include "Text.h"
#include "Stack.h"

typedef struct strNode* Node;

struct strNode{
    Node a;
    Node b;
    Node c;
    Node d;
    Node e;
    Node f;
    Node g;
    Node h;
    Node i;
    Node j;
    Node k;
    Node l;
    Node m;
    Node n;
    Node nacute;
    Node o;
    Node p;
    Node q;
    Node r;
    Node s;
    Node t;
    Node u;
    Node v;
    Node w;
    Node x;
    Node y;
    Node z;
    Node underscore;
    Text key;
    Text word;
    Text def;
}

struct srtDictionaryHead{
    Node initial
    unsigned int deep;
}

Dictionary dict_create(){
    Node n = calloc(1, sizeof(struct strNode));
    Dictionary dict = (Dictionary)malloc(sizeof(struct srtDictionaryHead));
    dict->deep = 0;
    dict->initial = n;
    return n;
}

unsigned int dict_size(Dictionary d){
    return d->deep;
}

void set_node_data(node, Text word, Text key, Text def){
    n->key = compare_word = text_create(key);
    n->word = text_create(word);
    n->def = text_create(def);
}

void dict_set(Dictionary d, Text word, Text def){
    int i;
    //Si se agragó el elemento, la bandera será falso
    bool flag = true;
    int cursor_pos = 0;
    char cursor_value = 0;
    Node n = d->initial;
    Data d = NULL;
    Text compare_word = text_ansi(word);
    compare_word = text_upperCase(word);
    //Si es el primer nodo
    if(n == NULL){
        n = (Node) malloc(sizeof(strNode));
        set_node_data(n, word, , def);
        flag = false;
    }

    // TODO: Aquí puede tronar si recorrimos toda la palabra y no encontramos coincidencia
    while(flag){
        cursor_value = text_charAt(word, cursor_pos);
        switch(cursor_value){
            case 'A'
                n = n->a;
                break;
            case 'B':
                n = n->b;
                break;
            case 'C':
                n = n->c;
                break;
            case 'D':
                n = n->d;
                break;
            case 'E':
                n = n->e;
                break;
            case 'F':
                n = n->f;
                break;
            case 'G':
                n = n->g;
                break;
            case 'H':
                n = n->h;
                break;
            case 'I':
                n = n->i;
                break;
            case 'J':
                n = n->j;
                break;
            case 'K':
                n = n->k;
                break;
            case 'L':
                n = n->l;
                break;
            case 'M':
                n = n->m;
                break;
            case 'N':
                n = n->n;
                break;
            case 165:
                n = n->nacute;
                break;
            case 'O':
                break;
            case 'P':
                n = n->p;
                break;
            case 'Q':
                n = n->q;
                break;
            case 'R':
                n = n->r;
                break;
            case 'S':
                n = n->s;
                break;
            case 'T':
                n = n->t;
                break;
            case 'U':
                n = n->u;
                break;
            case 'V':
                n = n->v;
                break;
            case 'W':
                n = n->w;
                break;
            case 'X':
                n = n->x;
                break;
            case 'Y':
                n = n->y;
                break;
            case 'Z':
                n = n->z;
                break;
            case '_':
                n = n->underscore;
            break;        
        }
        if(n == NULL){
            n = (Node) malloc(sizeof(strNode));
            set_node_data(n, word, , def);
            flag = false;
        }
        cursor_pos++;
    }
}

Text dict_get(Dictionary dict, Text word){
    int cursor_pos = 0;
    char cursor_value = 0;
    Node n = d->initial
    Text compare_word = text_ansi(word);
    compare_word = text_upperCase(word);
    Text return_text = NULL;
    bool flaf = true;

    if(n == NULL){
        // Manejar que el nodo inicial es null
        flag = false;
    }

    while(text_compare(n->data->key, compare_word) && flag){
        cursor_value = text_charAt(word, cursor_pos);
        switch(cursor_value){
            case 'A':
                n = n->a;
                break;
            case 'B':
                n = n->b;
                break;
            case 'C':
                n = n->c;
                break;
            case 'C':
                n = n->c;
                break;
            case 'D':
                n = n->d;
                break;
            case 'E':
                n = n->e;
                break;
            case 'F':
                n = n->f;
                break;
            case 'G':
                n = n->f;
                break;
            case 'H':
                n = n->h;
                break;
            case 'I':
                n = n->i;
                break;
            case 'J':
                n = n->j;
                break;
            case 'K':
                n = n->k;
                break;
            case 'L':
                n = n->l;
                break;
            case 'M':
                n = n->m;
                break;
            case 'N':
                n = n->n;
                break;
            case 'O':
                n = n->o;
                break;
            case 'P':
                n = n->p;
                break;
            case 'R':
                n = n->r;
                break;
            case 'S':
                n = n->s;
                break;
            case 'T':
                n = n->t;
                break;
            case 'U':
                n = n->u;
                break;
            case 'V':
                n = n->v;
                break;
            case 'W':
                n = n->w;
                break;
            case 'X':
                n = n->x;
                break;
            case 'Y':
                n = n->y;
                break;
            case 'Z':
                n = n->z;
                break;
            case '_':
                n = n->underscore;
                break;
            // TODO: Reemplazar Ñ con el código ascii
            case 165: 
                n = n->nacute;
                break;
        }
        // Vamos al caracter siquiente, al inicio del hacemos la comparación para salir del nodo 
        if(n == NULL){
            // Manejar que no exixtieron coinidencias
            flag = false;
        }
        cursor_pos++;
    }
    return n->data->def;
}