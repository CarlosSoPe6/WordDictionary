/**
 * Stack.h
 */

#ifndef _H_STACK
#define _H_STACK

typedef enum { false, true } bool;
typedef void* Type;
typedef struct strStack* Stack;
typedef unsigned int UInt;

Stack stack_create();
void  stack_push(Stack, Type);
Type  stack_pop(Stack);
Type  stack_top(Stack);
Bool  stack_isEmpty(Stack);
UInt  stack_size(Stack);
void  stack_destroy(Stack);

#endif