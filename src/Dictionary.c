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
    //Si se agragó el elemento, la bandera será falso
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
            case 'G':
                if(n->g == NULL){
                    n->g->data->word = compare_word;
                    n->g->data->def = def;
                    flag = false;
                }
                n = n->g;
                break;
            case 'H':
                if(n->f == NULL){
                    n->h->data->word = compare_word;
                    n->h->data->def = def;
                    flag = false;
                }
                n = n->h;
                break;
            case 'I':
                if(n->i == NULL){
                    n->i->data->word = compare_word;
                    n->i->data->def = def;
                    flag = false;
                }
                n = n->i;
                break;
            case 'J':
                if(n->j == NULL){
                    n->j->data->word = compare_word;
                    n->j->data->def = def;
                    flag = false;
                }
                n = n->j;
                break;
            case 'K':
                if(n->k == NULL){
                    n->k->data->word = compare_word;
                    n->k->data->def = def;
                    flag = false;
                }
                n = n->k;
                break;
            case 'L':
                if(n->l == NULL){
                    n->l->data->word = compare_word;
                    n->l->data->def = def;
                    flag = false;
                }
                n = n->l;
                break;
            case 'M':
                if(n->m == NULL){
                    n->m->data->word = compare_word;
                    n->m->data->def = def;
                    flag = false;
                }
                n = n->m;
                break;
            case 'N':
                if(n->n == NULL){
                    n->n->data->word = compare_word;
                    n->n->data->def = def;
                    flag = false;
                }
                n = n->n;
                break;
            case 'Ñ':
                if(n->nacute == NULL){
                    n->nacute->data->word = compare_word;
                    n->nacute->data->def = def;
                    flag = false;
                }
                n = n->nacute;
                break;
            case 'O':
                if(n->o == NULL){
                    n->o->data->word = compare_word;
                    n->o->data->def = def;
                    flag = false;
                }
                n = n->o;
                break;
            case 'P':
                if(n->p == NULL){
                    n->p->data->word = compare_word;
                    n->p->data->def = def;
                    flag = false;
                }
                n = n->p;
                break;
            case 'Q':
                if(n->q == NULL){
                    n->q->data->word = compare_word;
                    n->q->data->def = def;
                    flag = false;
                }
                n = n->q;
                break;
            case 'R':
                if(n->r == NULL){
                    n->r->data->word = compare_word;
                    n->r->data->def = def;
                    flag = false;
                }
                n = n->r;
                break;
            case 'S':
                if(n->s == NULL){
                    n->s->data->word = compare_word;
                    n->s->data->def = def;
                    flag = false;
                }
                n = n->s;
                break;
            case 'T':
                if(n->t == NULL){
                    n->t->data->word = compare_word;
                    n->t->data->def = def;
                    flag = false;
                }
                n = n->t;
                break;
            case 'U':
                if(n->u == NULL){
                    n->u->data->word = compare_word;
                    n->u->data->def = def;
                    flag = false;
                }
                n = n->u;
                break;
            case 'V':
                if(n->v == NULL){
                    n->v->data->word = compare_word;
                    n->v->data->def = def;
                    flag = false;
                }
                n = n->v;
                break;
            case 'W':
                if(n->w == NULL){
                    n->w->data->word = compare_word;
                    n->w->data->def = def;
                    flag = false;
                }
                n = n->w;
                break;
            case 'X':
                if(n->x == NULL){
                    n->x->data->word = compare_word;
                    n->x->data->def = def;
                    flag = false;
                }
                n = n->x;
                break;
            case 'Y':
                if(n->y == NULL){
                    n->y->data->word = compare_word;
                    n->y->data->def = def;
                    flag = false;
                }
                n = n->y;
                break;
            case 'Z':
                if(n->z == NULL){
                    n->z->data->word = compare_word;
                    n->z->data->def = def;
                    flag = false;
                }
                n = n->z;
                break;
            case '_':
                if(n->underscore == NULL){
                    n->underscore->data->word = compare_word;
                    n->underscore->data->def = def;
                    flag = false;
                }
                n = n->underscore;
            break;
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



    while(text_compare(n->data->key, compare_word)){
        if(n == NULL){
            // Manejar la palabra inexistente
            return "Deninición no existe";
        }
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
            case 'ñ': 
                n = n->nacute;
                break;
        }
        // Vamos al caracter siquiente, al inicio del hacemos la comparación para salir del nodo 
        cursor_pos++;
    }
    return n->data->def;
}