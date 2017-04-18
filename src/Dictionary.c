/**
 * Dictionary.c
 * TDA dictionary
 */
#include <stdio.h>
#include <stdlib.h>

#include "Dictionary.h"

typedef struct strNode* Node;
typedef struct strData Data;

struct strData{
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
}

struct srtDictionaryHead{
    Node initial
    unsigned int deep;
}