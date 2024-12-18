#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cup.h"

char *contents_to_str[] = {"TEA", "COFFEE", "WATER", "MILK", "MIXED"};
char *material_to_str[] = {"PAPER", "GLASS", "PLASTIC"};

void print_cup(cup *c) {
    printf("%s %d %d %s %s\n", c->color, c->max_oz, c->cur_oz, 
           contents_to_str[c->contents], material_to_str[c->material]);
}

cup *new_cup(int max, int cur, contents contents, enum material m, char *color) {
    cup *p = malloc(sizeof(cup));
    p->max_oz = max;
    p->cur_oz = cur;
    p->contents = contents;
    p->material = m;
    strcpy(p->color, color);
    return p;
}

int fill(cup *c, contents v, int oz) {
    c->cur_oz += oz;
    if (c->contents != v)
        c->contents = MIXED;
    if (c->cur_oz > c->max_oz) {
        c->cur_oz = c->max_oz;
        return -1;
    }
    return c->cur_oz;
}

cup *find_fullest(cup **ca, int num_eles) {
	double largest = ca[0]->cur_oz;
	cup *name;
	double max_oz = 0;
	for (int i = 0; i < num_eles; i++) {
		if (ca[i]->cur_oz > largest) {
			largest = ca[i]->cur_oz;
			name = ca[i];
		} else if (ca[i]->cur_oz == largest) {
			if (ca[i]->max_oz > max_oz) {
				largest = ca[i]->cur_oz;
				name = ca[i];
			}
		}
	}
    return name;
}

void sort_cups(cup **ca, int num_eles) {
	for (int i = 0; i < num_eles-1; i++) {
		for (int j = 0; j < num_eles-i-1; j++) {
			double fullest_j = ca[j]->cur_oz / (double)ca[j]->max_oz;
			double fullest_j1 = ca[j+1]->cur_oz / (double)ca[j+1]->max_oz;
			int cur_oz_j = ca[j]->cur_oz;
			int cur_oz_j1 = ca[j+1]->cur_oz;
			if (fullest_j >= fullest_j1) {
				if (fullest_j == fullest_j1) {
					if(cur_oz_j > cur_oz_j1) {
						cup *t = ca[j];
						ca[j] = ca[j+1];
						ca[j+1] = t;
					}
				}
			} else {
				cup *t = ca[j];
				ca[j] = ca[j+1];
				ca[j+1] = t;
			}
		}
	}
}

void print_cups(cup **ca, int num_eles) {
    for (int i = 0; i < num_eles; i++) {
        printf("cup[%d]: ", i);
        print_cup(ca[i]);
    }
}

