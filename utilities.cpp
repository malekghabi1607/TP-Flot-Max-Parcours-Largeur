/*
 * utilities.cpp
 * Fonctions utilitaires pour le calcul de flot maximum (algorithme d’Edmonds-Karp)
 * Auteur : Malek
 */

#include <iostream>
#include <fstream>
#include <queue>
#include "utilities.h"

using namespace std;

void affichage(int* mat[], int n)
{
	for(int i = 0; i < n; i++){
		for(int j = 0; j < (n-1); j++)
			cout << mat[i][j] << "\t";
		cout << mat[i][n-1] << endl;		
	}
	cout << endl;
}

/****************************************************/
/* Entrées :                                        */
/* c : matrice des capacités des arcs du réseau     */
/* f : matrice des flots sur les arcs               */
/* n : nombre de noeuds du réseau                   */
/* s : sommet source                                */                            
/* t : sommet destination                           */
/* Sortie : ch : chaîne augmentante de s à t        */
/* (s'il en existe)                                 */
/****************************************************/
/* Indication  : La chaîne augmentante doit être    */
/* trouvée par un parcours en largeur du réseau.    */
/* Un tel parcours se code en utilisant la méthode  */
/* présentée en cours, en remplaçant toutefois la   */
/* pile par une file                                */
/****************************************************/
 


// Recherche d’une chaîne augmentante par BFS (Edmonds-Karp)
void chaineaugmentante(int* c[], int* f[], int n, int ch[], int s, int t)
{
    queue<int> q;
    bool visite[n];

    for (int i = 0; i < n; i++) {
        visite[i] = false;
        ch[i] = -1;
    }

    q.push(s);
    visite[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            int residuel = c[u][v] - f[u][v];
            if (!visite[v] && residuel > 0) {
                visite[v] = true;
                ch[v] = u;
                if (v == t) return;
                q.push(v);
            }
        }
    }
}

/****************************************************/
/* Entrées :                                        */
/* c : matrice des capacités des arcs du réseau     */
/* f : matrice des flots sur les arcs               */
/* n : nombre de noeuds du réseau                   */
/* s : sommet source                                */                            
/* t : sommet destination                           */
/* ch : chaîne augmentante de s à t                 */
/* Sortie : valeur d'augmentation du flot           */
/****************************************************/

// Incrémente le flot sur la chaîne trouvée
int increment(int* c[], int* f[], int n, int ch[], int s, int t)
{
    int flux = 1000000;
    if (ch[t] == -1) return 0;

    for (int v = t; v != s; v = ch[v]) {
        int u = ch[v];
        flux = min(flux, c[u][v] - f[u][v]);
    }

    for (int v = t; v != s; v = ch[v]) {
        int u = ch[v];
        f[u][v] += flux;
        f[v][u] -= flux;
    }

    return flux;
}


/****************************************************/
/* Entrées :                                        */
/* c : matrice des capacités des arcs du réseau     */
/* f : matrice des flots sur les arcs               */
/* n : nombre de noeuds du réseau                   */
/* s : sommet source                                */                            
/* t : sommet destination                           */
/****************************************************/
/* Sorties :                                        */
/* Flot Max de s à t                                */
/* Coupe minimum stockée dans S                     */
/****************************************************/

// Algorithme de Ford-Fulkerson avec parcours en largeur (Edmonds-Karp)
int fordfulkerson(int* c[], int* f[], int n, int s, int t, bool* S)
{
    int flot_max = 0;
    int ch[n];

    while (true)
    {
        for (int i = 0; i < n; i++) ch[i] = -1;
        chaineaugmentante(c, f, n, ch, s, t);
        if (ch[t] == -1) break;
        flot_max += increment(c, f, n, ch, s, t);
    }

    // Marquage des sommets accessibles pour la coupe minimum
    bool visite[n];
    for (int i = 0; i < n; i++) visite[i] = false;

    queue<int> q;
    q.push(s);
    visite[s] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            int residuel = c[u][v] - f[u][v];
            if (!visite[v] && residuel > 0) {
                visite[v] = true;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        S[i] = visite[i];
    }

    return flot_max;
}

