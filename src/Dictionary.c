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
};

struct srtDictionaryHead{
    Node initial;
    unsigned int deep;
};
typedef enum { A, B, C, D, E, F, G, H, I, J, K, L, M ,N, O, P, Q, R, S, T, U, V, W, X, Y, Z, NACUTE, UNDERSCORE} Letter;

Dictionary dict_create(){
    Dictionary dict = (Dictionary)calloc(1, sizeof(struct srtDictionaryHead));
    return dict;
}

unsigned int dict_size(Dictionary d){
    return d->deep;
}

void set_node_data(Node n, Text word, Text key, Text def){
    n->key = text_clone(key);
    n->word = text_clone(word);
    n->def = text_clone(def);
}

void dict_set(Dictionary d, Text word, Text def){
    //Si se agragó el elemento, la bandera será falso
    bool flag = true;
    int cursor_pos = 0;
    unsigned char cursor_value = 0;
    Node n = d->initial;
    Text compare_word = text_ansi(word);
    compare_word = text_toUpperCase(word);
    //Si es el primer nodo
    if(n == NULL){
        n = (Node) malloc(sizeof(struct strNode));
        set_node_data(n, word, compare_word, def);
        flag = false;
    }

    // TODO: Aquí puede tronar si recorrimos toda la palabra y no encontramos coincidencia
    while(flag){
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
            n = (Node) malloc(sizeof(struct strNode));
            set_node_data(n, word, compare_word, def);
            flag = false;
        }
        cursor_pos++;
    }
    if(!flag){
        d->deep++;
    }
}

Text dict_get(Dictionary dict, Text word){
    int cursor_pos = 0;
    unsigned char cursor_value = 0;
    Node n = dict->initial;
    Text compare_word = text_ansi(word);
    compare_word = text_toUpperCase(word);
    Text return_text = NULL;
    bool flag = true;

    if(n == NULL){
        // Manejar que el nodo inicial es null
        flag = false;
    }

    while(text_compare(n->key, compare_word) && flag){
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
    return_text = n->def;
    return return_text;
}

char** dict_keys (Dictionary d)
{
    //Aquí se van a almacenar los apuntadores a las palabras
    char **alm = (char**)malloc(sizeof(char*) * d->deep);
    Node n = (Node)calloc(1, sizeof(struct strNode));
    n = d->initial;
    Stack s = stack_create();
    //Este arreglo va a contar la letra que vamos por nivel
    Letter *counter = (Letter*)malloc(sizeof(Letter));
    //Contador para el arreglo
    int i = 0;
    //Este va a llevar la cuenta del nivel que va
    unsigned int level = 1;
    //Bandera que dice si hubo un cambio en el nivel
    bool changed;
    Bool finish = FALSE;
    if(d->deep > 0)
    {
        stack_push(s, d);
        alm[i] = text_getChars(n->word);
        i++;
    }
    while(i < d->deep || !finish)
    {
        changed = false;
        counter[level] = A;
        switch (counter[level])
        {
            /*
            Se va a evaluar el contrador counter en el nivel del arbol que esté.
            Dependiendo de la letra en la que vaya, preguntara si es nulo; si sí es nulo,
            el auxiliar cambiara y se bajará un nivel, de lo contrario continuará con la
            siguiente letra
            */
            case A:
                if (n->a != NULL) {
                    n = n->a;
                    changed = true;
                    break;
                }
                counter[level]++;
            case B:
                if (n->b != NULL) {
                    n = n->b;
                    changed = true;
                    break;
                }
                counter[level]++;
            case C:
                if (n->c != NULL) {
                    n = n->c;
                    changed = true;
                    break;
                }
                counter[level]++;
            case D:
                if (n->d != NULL) {
                    n = n->d;
                    changed = true;
                    break;
                }
                counter[level]++;
            case E:
                if (n->e != NULL) {
                    n = n->e;
                    changed = true;
                    break;
                }
                counter[level]++;
            case F:
                if (n->f != NULL) {
                    n = n->f;
                    changed = true;
                    break;
                }
                counter[level]++;
            case G:
                if (n->g != NULL) {
                    n = n->g;
                    changed = true;
                    break;
                }
                counter[level]++;
            case H:
                if (n->h != NULL) {
                    n = n->h;
                    changed = true;
                    break;
                }
                counter[level]++;
            case I:
                if (n->i != NULL) {
                    n = n->i;
                    changed = true;
                    break;
                }
                counter[level]++;
            case J:
                if (n->j != NULL) {
                    n = n->j;
                    changed = true;
                    break;
                }
                counter[level]++;
            case K:
                if (n->k != NULL) {
                    n = n->k;
                    changed = true;
                    break;
                }
                counter[level]++;
            case L:
                if (n->l != NULL) {
                    n = n->l;
                    changed = true;
                    break;
                }
                counter[level]++;
            case M:
                if (n->m != NULL) {
                    n = n->m;
                    changed = true;
                    break;
                }
                counter[level]++;
            case N:
                if (n->n != NULL) {
                    n = n->n;
                    changed = true;
                    break;
                }
                counter[level]++;
            case O:
                if (n->o != NULL) {
                    n = n->o;
                    changed = true;
                    break;
                }
                counter[level]++;
            case P:
                if (n->p != NULL) {
                    n = n->p;
                    changed = true;
                    break;
                }
                counter[level]++;
            case Q:
                if (n->q != NULL) {
                    n = n->q;
                    changed = true;
                    break;
                }
                counter[level]++;
            case R:
                if (n->r != NULL) {
                    n = n->r;
                    changed = true;
                    break;
                }
                counter[level]++;
            case S:
                if (n->s != NULL) {
                    n = n->s;
                    changed = true;
                    break;
                }
                counter[level]++;
            case T:
                if (n->t != NULL) {
                    n = n->t;
                    changed = true;
                    break;
                }
                counter[level]++;
            case U:
                if (n->u != NULL) {
                    n = n->u;
                    changed = true;
                    break;
                }
                counter[level]++;
            case V:
                if (n->v != NULL) {
                    n = n->v;
                    changed = true;
                    break;
                }
                counter[level]++;
            case W:
                if (n->w != NULL) {
                    n = n->w;
                    changed = true;
                    break;
                }
                counter[level]++;
            case X:
                if (n->x != NULL) {
                    n = n->x;
                    changed = true;
                    break;
                }
                counter[level]++;
            case Y:
                if (n->y != NULL) {
                    n = n->y;
                    changed = true;
                    break;
                }
                counter[level]++;
            case Z:
                if (n->z != NULL) {
                    n = n->z;
                    changed = true;
                    break;
                }
                counter[level]++;
            case NACUTE:
                if (n->nacute != NULL) {
                    n = n->nacute;
                    changed = true;
                    break;
                }
                counter[level]++;
            case UNDERSCORE:
                if (n->underscore != NULL) {
                    n = n->underscore;
                    changed = true;
                    break;
                }
            }
        //Si hubo un cambio
        if (changed)
        {
            //El nivel aumenta
            level ++;
            //Se hace el push en el stack
            stack_push(s, n);
            //Se agrega al arreglo
            alm[i] = text_getChars(n->word);
            //El contador del arreglo aumenta
            i++;
        }
        else
        {
            if (!stack_isEmpty(s)) {
                //Eliminamos el ultimo elemento para regresar en el tiempo
                //al nivel superior
                stack_pop(s);
                n = stack_top(s);
                level --;
            }
            //Si el stack esta vacio significa que estamos en el elemento raiz
            //Y si no hubo cambios, debe terminar el ciclo
            else finish = TRUE;
        }
        counter = (Letter*)realloc(counter, level * sizeof(Letter));
    }
    stack_destroy(s);
    free(n);
    free(counter);
    return alm;
}
