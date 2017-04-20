/**
 * Dictionary.c
 * TDA dictionary
 */
#include <stdio.h>
#include <stdlib.h>

#include "Dictionary.h"
#include "Text.h"
#include "Stack.h"

typedef struct strNode* Node;
typedef struct strData Data;

struct strData{
    Text key;
    Text word;
    Text def;
}
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
    Data data;
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

void dict_set(Dictionary d, Text word, Text def){
    int i;
    bool flag = true;
    int cursor_pos = 0;
    char cursor_value = 0;
    Node n = d->initial
    Text compare_word = text_ansi(word);
    compare_word = text_upperCase(word);
    //Si es el primer nodo
    if(n == NULL){
        return
    }

    // TODO aquí puede tronar si recorrimos toda la palabra y no encontramos coincidencia
    while(flag){
        cursor_value = text_charAt(word, cursor_pos);
        switch(cursor_value){
            case 'A':
                if(n->a == NULL){
                    n->a->data->word = compare_word;
                    n->a->data->def = def;
                    flag = false;
                }
                n = n->a;
                break;
            case 'B':
                if(n->b == NULL){
                    n->b->data->word = compare_word;
                    n->b->data->def = def;
                    flag = false;
                }
                n = n->b;
                break;
            case 'C':
                if(n->c == NULL){
                    n->c->data->word = compare_word;
                    n->c->data->def = def;
                    flag = false;
                }
                n = n->c;
                break;
            case 'D':
                if(n->d == NULL){
                    n->d->data->word = compare_word;
                    n->d->data->def = def;
                    flag = false;
                }
                n = n->d;
                break;
            case 'E':
                if(n->e == NULL){
                    n->e->data->word = compare_word;
                    n->e->data->def = def;
                    flag = false;
                }
                n = n->e;
                break;
            case 'F':
            if(n->f == NULL){
                n->f->data->word = compare_word;
                n->f->data->def = def;
                flag = false;
            }
            n = n->f;
            break;
            case 'G':break;
            case 'H':break;
            case 'I':break;
            case 'J':break;
            case 'K':break;
            case 'L':break;
            case 'M':break;
            case 'N':break;
            case 'Ñ':break;
            case 'O':break;
            case 'P':break;
            case 'Q':break;
            case 'R':break;
            case 'S':break;
            case 'T':break;
            case 'U':break;
            case 'V':break;
            case 'W':break;
            case 'X':break;
            case 'Y':break;
            case 'Z':break;
            case '_':break;
        }
        cursor_pos++;
    }
}
