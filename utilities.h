
/*
 * utilities.h
 * Déclarations des fonctions pour le calcul du flot maximum (algorithme d’Edmonds-Karp)
 * Auteur : Malek
 */

#ifndef _UTIL_H_
#define _UTIL_H_

void affichage(int* mat[], int n);
void chaineaugmentante(int* c[], int* f[], int n, int ch[],int s, int t);
int increment(int* c[], int* f[], int n, int ch[], int s, int t);
int fordfulkerson(int* c[], int* f[], int n, int s, int t, bool* S);

#endif