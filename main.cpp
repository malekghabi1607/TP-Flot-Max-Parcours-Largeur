#include <iostream>
#include "utilities.h"

using namespace std;

int main() {
    cout << "Test de Malek" << endl;

    int matrice1[6][6] = {
        {0, 6, 6, 0, 0, 0},
        {6, 0, 0, 5, 0, 0},
        {6, 0, 0, 4, 3, 0},
        {0, 5, 4, 0, 0, 7},
        {0, 0, 3, 0, 0, 4},
        {0, 0, 0, 7, 4, 0}
    };

    int matrice2[6][6] = {0};  // Matrice des flots initialisée à zéro

    int* c[] = {matrice1[0], matrice1[1], matrice1[2], matrice1[3], matrice1[4], matrice1[5]};
    int* f[] = {matrice2[0], matrice2[1], matrice2[2], matrice2[3], matrice2[4], matrice2[5]};

    bool S[6];  // Tableau pour stocker la coupe minimum

    cout << "\nMatrice des flots avant exécution :" << endl;
    affichage(f, 6);

    int flot_max = fordfulkerson(c, f, 6, 0, 5, S);

    cout << "\nFlot maximum : " << flot_max << endl;

    cout << "Coupe minimum : ";
    for (int i = 0; i < 6; i++) {
        if (S[i]) cout << i << " ";
    }
    cout << endl;

    cout << "\nMatrice des flots après exécution :" << endl;
    affichage(f, 6);

    return 0;
}
