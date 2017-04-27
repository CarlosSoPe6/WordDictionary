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

#define NACUTE_UPPER 165

typedef struct strNode* Node;

typedef enum { A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, NACUTE, UNDERSCORE } Letter;


struct strNode {
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

struct srtDictionaryHead {
	Node initial;
	unsigned int deep;
};

struct strNavigator {
	Node node;
	Letter current;
};

typedef struct strNavigator * Navigator;

/*
Navigator def
*/

Navigator navigator_create() {
	Navigator n = (Navigator)calloc(1, sizeof(struct strNavigator));
	return n;
}

Dictionary dict_create() {
	Dictionary dict = (Dictionary)calloc(1, sizeof(struct srtDictionaryHead));
	return dict;
}

unsigned int dict_size(Dictionary d) {
	return d->deep;
}

void set_node_data(Node n, Text word, Text key, Text def) {
	n->key = text_clone(key);
	n->word = text_clone(word);
	n->def = text_clone(def);
}

void dict_set(Dictionary d, Text word, Text def) {
	//Si se agragó el elemento, la bandera será falso
	Bool flag = TRUE;
	int cursor_pos = 0;
	unsigned char cursor_value = 0;
	Node n = NULL;
	Text compare_word = text_ansi(word);
	compare_word = text_toUpperCase(word);

	text_println(compare_word);

	//Si es el primer nodo
	if (d->initial == NULL) {
		d->initial = (Node)calloc(1, sizeof(struct strNode));
		set_node_data(d->initial, word, compare_word, def);
		flag = FALSE;
	}

	n = d->initial;

	// TODO: Aquí puede tronar si recorrimos toda la palabra y no encontramos coincidencia
	while (flag) {
		cursor_value = text_charAt(word, cursor_pos);
		switch (cursor_value) {
		case 'A':
			if (n->a == NULL) {
				n->a = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->a, word, compare_word, def);
				flag = FALSE;
			}
			n = n->a;
			break;
		case 'B':
			if (n->b == NULL) {
				n->b = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->b, word, compare_word, def);
				flag = FALSE;
			}
			n = n->b;
			break;
		case 'C':
			if (n->c == NULL) {
				n->c = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->c, word, compare_word, def);
				flag = FALSE;
			}
			n = n->c;
			break;
		case 'D':
			if (n->d == NULL) {
				n->d = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->d, word, compare_word, def);
				flag = FALSE;
			}
			n = n->d;
			break;
		case 'E':
			if (n->e == NULL) {
				n->e = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->e, word, compare_word, def);
				flag = FALSE;
			}
			n = n->e;
			break;
		case 'F':
			if (n->f == NULL) {
				n->f = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->f, word, compare_word, def);
				flag = FALSE;
			}
			n = n->f;
			break;
		case 'G':
			if (n->g == NULL) {
				n->g = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->g, word, compare_word, def);
				flag = FALSE;
			}
			n = n->g;
			break;
		case 'H':
			if (n->h == NULL) {
				n->h = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->h, word, compare_word, def);
				flag = FALSE;
			}
			n = n->h;
			break;
		case 'I':
			if (n->i == NULL) {
				n->i = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->i, word, compare_word, def);
				flag = FALSE;
			}
			n = n->i;
			break;
		case 'J':
			if (n->j == NULL) {
				n->j = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->j, word, compare_word, def);
				flag = FALSE;
			}
			n = n->j;
			break;
		case 'K':
			if (n->k == NULL) {
				n->k = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->k, word, compare_word, def);
				flag = FALSE;
			}
			n = n->k;
			break;
		case 'L':
			if (n->n == NULL) {
				n->n = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->n, word, compare_word, def);
				flag = FALSE;
			}
			n = n->l;
			break;
		case 'M':
			if (n->m == NULL) {
				n->m = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->m, word, compare_word, def);
				flag = FALSE;
			}
			n = n->m;
			break;
		case 'N':
			if (n->n == NULL) {
				n->n = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->n, word, compare_word, def);
				flag = FALSE;
			}
			n = n->n;
			break;
		case (unsigned char)NACUTE_UPPER:
			if (n->nacute == NULL) {
				n->nacute = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->nacute, word, compare_word, def);
				flag = FALSE;
			}
			n = n->nacute;
			break;
		case 'O':
			if (n->o == NULL) {
				n->o = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->o, word, compare_word, def);
				flag = FALSE;
			}
			n = n->o;
			break;
		case 'P':
			if (n->p == NULL) {
				n->p = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->p, word, compare_word, def);
				flag = FALSE;
			}
			n = n->p;
			break;
		case 'Q':
			if (n->q == NULL) {
				n->q = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->q, word, compare_word, def);
				flag = FALSE;
			}
			n = n->q;
			break;
		case 'R':
			if (n->r == NULL) {
				n->r = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->r, word, compare_word, def);
				flag = FALSE;
			}
			n = n->r;
			break;
		case 'S':
			if (n->s == NULL) {
				n->s = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->s, word, compare_word, def);
				flag = FALSE;
			}
			n = n->s;
			break;
		case 'T':
			if (n->t == NULL) {
				n->t = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->t, word, compare_word, def);
				flag = FALSE;
			}
			n = n->t;
			break;
		case 'U':
			if (n->u == NULL) {
				n->u = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->u, word, compare_word, def);
				flag = FALSE;
			}
			n = n->u;
			break;
		case 'V':
			if (n->v == NULL) {
				n->v = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->v, word, compare_word, def);
				flag = FALSE;
			}
			n = n->v;
			break;
		case 'W':
			if (n->w == NULL) {
				n->w = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->w, word, compare_word, def);
				flag = FALSE;
			}
			n = n->w;
			break;
		case 'X':
			if (n->x == NULL) {
				n->x = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->x, word, compare_word, def);
				flag = FALSE;
			}
			n = n->x;
			break;
		case 'Y':
			if (n->y == NULL) {
				n->y = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->y, word, compare_word, def);
				flag = FALSE;
			}
			n = n->y;
			break;
		case 'Z':
			if (n->z == NULL) {
				n->z->underscore = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->z, word, compare_word, def);
				flag = FALSE;
			}
			n = n->z;
			break;
		case '_':
			if (n->underscore == NULL) {
				n->underscore = (Node)calloc(1, sizeof(struct strNode));
				set_node_data(n->underscore, word, compare_word, def);
				flag = FALSE;
			}
			n = n->underscore;
			break;
		}

		cursor_pos++;
	}
	if (!flag) {
		d->deep++;
	}
}

Text dict_get(Dictionary dict, Text word) {
	int cursor_pos = 0;
	unsigned char cursor_value = 0;
	Node n = dict->initial;
	Text compare_word = text_ansi(word);
	compare_word = text_toUpperCase(word);
	Text return_text = NULL;
	Bool flag = TRUE;

	if (n == NULL) {
		// Manejar que el nodo inicial es null
		flag = FALSE;
	} else if(!text_compare(n->key, compare_word)) {
        // La palabra está en el nodo raiz
        flag = FALSE;
    }

	while (flag && text_compare(n->key, compare_word)) {
		cursor_value = text_charAt(word, cursor_pos);
		switch (cursor_value) {
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
		case (unsigned char)NACUTE_UPPER:
			n = n->nacute;
			break;
		}
		// Vamos al caracter siquiente, al inicio del hacemos la comparación para salir del nodo
		if (n == NULL) {
			// Manejar que no exixtieron coinidencias
			flag = FALSE;
		}
		cursor_pos++;
	}
	if (!flag) {
		return_text = text_create("Palabra no encontrada");
	}
	else {
		return_text = n->def;
	}

	return return_text;
}

void capBrench(Node n, char ***array, int *i)
{
	(*array)[*i] = text_getChars(n->word);
	(*i)++;
	if(n->a != NULL) capBrench(n->a, array, i);
	if(n->b != NULL) capBrench(n->b, array, i);
	if(n->c != NULL) capBrench(n->c, array, i);
	if(n->d != NULL) capBrench(n->d, array, i);
	if(n->e != NULL) capBrench(n->e, array, i);
	if(n->f != NULL) capBrench(n->f, array, i);
	if(n->g != NULL) capBrench(n->g, array, i);
	if(n->h != NULL) capBrench(n->h, array, i);
	if(n->i != NULL) capBrench(n->i, array, i);
	if(n->j != NULL) capBrench(n->j, array, i);
	if(n->k != NULL) capBrench(n->k, array, i);
	if(n->l != NULL) capBrench(n->l, array, i);
	if(n->m != NULL) capBrench(n->m, array, i);
	if(n->n != NULL) capBrench(n->n, array, i);
	if(n->nacute != NULL) capBrench(n->nacute, array, i);
	if(n->o != NULL) capBrench(n->o, array, i);
	if(n->p != NULL) capBrench(n->p, array, i);
	if(n->q != NULL) capBrench(n->q, array, i);
	if(n->r != NULL) capBrench(n->r, array, i);
	if(n->s != NULL) capBrench(n->s, array, i);
	if(n->t != NULL) capBrench(n->t, array, i);
	if(n->u != NULL) capBrench(n->u, array, i);
	if(n->v != NULL) capBrench(n->v, array, i);
	if(n->w != NULL) capBrench(n->w, array, i);
	if(n->x != NULL) capBrench(n->x, array, i);
	if(n->y != NULL) capBrench(n->y, array, i);
	if(n->z != NULL) capBrench(n->z, array, i);
	if(n->underscore != NULL) capBrench(n->underscore, array, i);
}

char** dict_keys (Dictionary d)
{
	int i = 0;
	char **array = (char**)malloc(sizeof(char) * d->deep);
	capBrench(d->initial, &array, &i);
	return array;
}

void dict_destroy(Dictionary d) {
	Stack time_machine = NULL;
	Bool flag = FALSE;
	Navigator navigator = NULL;
	Node aux = NULL;

	if (d->initial != NULL) {
		time_machine = stack_create();
		navigator = navigator_create();
		navigator->current = A;
		navigator->node = d->initial;
		flag = TRUE;
	}

	while (navigator != NULL) {
		aux = navigator->node;
		switch (navigator->current) {
		case A:
			if (navigator->node->a != NULL) {
				navigator->current = B;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->a;
				break;
			}
		case B:
			if (navigator->node->b != NULL) {
				navigator->current = C;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->b;
				break;
			}
		case C:
			if (navigator->node->c != NULL) {
				navigator->current = D;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->c;
				break;
			}
		case D:
			if (navigator->node->d != NULL) {
				navigator->current = E;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->d;
				break;
			}
		case E:
			if (navigator->node->e != NULL) {
				navigator->current = F;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->e;
				break;
			}
		case F:
			if (navigator->node->f != NULL) {
				navigator->current = G;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->f;
				break;
			}
		case G:
			if (navigator->node->g != NULL) {
				navigator->current = H;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->g;
				break;
			}
		case H:
			if (navigator->node->h!= NULL) {
				navigator->current = I;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->h;
				break;
			}
		case I:
			if (navigator->node->i != NULL) {
				navigator->current = J;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->i;
				break;
			}
		case J:
			if (navigator->node->j != NULL) {
				navigator->current = K;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->j;
				break;
			}
		case K:
			if (navigator->node->k != NULL) {
				navigator->current = L;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->k;
				break;
			}
		case L:
			if (navigator->node->l != NULL) {
				navigator->current = M;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->l;
				break;
			}
		case M:
			if (navigator->node->m != NULL) {
				navigator->current = N;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->m;
				break;
			}
		case N:
			if (navigator->node->n != NULL) {
				navigator->current = O;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->n;
				break;
			}
		case O:
			if (navigator->node->o != NULL) {
				navigator->current = P;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->o;
				break;
			}
		case P:
			if (navigator->node->p != NULL) {
				navigator->current = Q;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->p;
				break;
			}
		case Q:
			if (navigator->node->q != NULL) {
				navigator->current = R;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->q;
				break;
			}
		case R:
			if (navigator->node->r != NULL) {
				navigator->current = S;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->r;
				break;
			}
		case S:
			if (navigator->node->s != NULL) {
				navigator->current = T;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->s;
				break;
			}
		case T:
			if (navigator->node->t != NULL) {
				navigator->current = U;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->t;
				break;
			}
		case U:
			if (navigator->node->u != NULL) {
				navigator->current = V;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->u;
				break;
			}
		case V:
			if (navigator->node->v != NULL) {
				navigator->current = W;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->v;
				break;
			}
		case W:
			if (navigator->node->w != NULL) {
				navigator->current = X;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->w;
				break;
			}
		case X:
			if (navigator->node->x != NULL) {
				navigator->current = Y;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->x;
				break;
			}
		case Y:
			if (navigator->node->y != NULL) {
				navigator->current = Z;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->y;
				break;
			}
		case Z:
			if (navigator->node->z != NULL) {
				navigator->current = NACUTE;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->z;
				break;
			}
		case NACUTE:
			if (navigator->node->nacute != NULL) {
				navigator->current = UNDERSCORE;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->nacute;
				break;
			}
		case UNDERSCORE:
			if (navigator->node->underscore != NULL) {
				navigator->current = UNDERSCORE + 1;
				stack_push(time_machine, navigator);

				navigator = navigator_create();
				navigator->node = aux->underscore;
				break;
			}
		default:
			free(navigator->node->def);
			free(navigator->node->word);
			free(navigator->node->key);
			free(navigator->node);
			free(navigator);
			navigator = stack_pop(time_machine);
		}

	}
}


int dict_getSize(Dictionary d)
{
	return d->deep;
}
