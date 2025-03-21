
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
bool chaineaugmentante(int* c[], int* f[], int n, int ch[], int s, int t) {
    bool* visite = new bool[n];
    for (int i = 0; i < n; i++) {
        visite[i] = false;
        ch[i] = -1;
    }

    std::queue<int> file;
    file.push(s);
    visite[s] = true;

    while (!file.empty()) {
        int u = file.front();
        file.pop();

        for (int v = 0; v < n; v++) {
            if (!visite[v] && c[u][v] - f[u][v] > 0) {
                file.push(v);
                ch[v] = u;
                visite[v] = true;
            }
        }
    }

    bool resultat = visite[t]; // Si t est atteint → chaîne augmentante trouvée

    delete[] visite;
    return resultat;
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
int increment(int* c[], int* f[], int n, int ch[], int s, int t)
{
	return(0);

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
int fordfulkerson(int* c[], int* f[], int n, int s, int t, bool* S)
{
	return(0);
}


