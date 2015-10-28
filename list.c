#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
void init(list *l) {
	l->head = NULL;
	l->length = 0;
}
void insert(list *l, node* tmp) {
	node *p;
	int i;
	if(l->head == NULL) {
		l->head = tmp;
		tmp->next = NULL;
		l->length = 1;
	}
	else{
	p = l->head;
	while(p->next && (p->next->freq < tmp->freq))
		p = p->next;	
	tmp->next =p->next;
	p->next = tmp;
	(l->length)++;
	
	}
}
int search(list l, int freq) {
		node *p;
		int pos = 0;
		p = l.head;
		while(p!= NULL && (p->freq < freq)){
			//printf("frequency seen %lu\n",p->freq);
			p =  p->next;
			pos++;
		}
		return pos;
}

node *removal(list *l) {
	node *p = l->head;
	if(l->head)
		l->head = l->head->next;
	//printf("%c\n",l->head->str);
	return p;
	
}
/* can insert at positions [0..length] */
void printlist(list l) {
	node *p;
	p =l.head;
	while(p) {
		printf("(%d %lu) ",p->str,p->freq);
		p = p->next;
	}
	printf("\n");
}
void printnexttwo(node *q) {
	node *p = q;
	printf("%d -%lu\n", p->next->str,p->next->freq);
	p = p->next;
	printf("%d -%lu\n", p->next->str,p->next->freq);
}
