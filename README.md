# TP – Flot Maximum avec Parcours en Largeur (Algorithme d’Edmonds-Karp)

Ce projet est un TP d’algorithmique portant sur le **calcul du flot maximum** dans un graphe orienté pondéré, à l’aide de l’algorithme d’**Edmonds-Karp**, une version optimisée de Ford-Fulkerson utilisant un **parcours en largeur (BFS)** pour trouver les chaînes augmentantes.

---

## 📁 Structure du projet

- `main.cpp` : Point d’entrée du programme, utilisé pour les tests.
- `utilities.cpp` : Implémentation des fonctions principales : `chaineaugmentante` et `fordfulkerson`.
- `utilities.h` : Fichier d’en-tête contenant les déclarations des fonctions.
- `README.md` : Ce fichier de description du projet.

---

## 🎯 Objectifs du TP

- Utiliser un **parcours en largeur** (file) au lieu d’un parcours en profondeur (pile).
- Implémenter la fonction `chaineaugmentante` pour détecter s’il existe un chemin de la source `s` au puits `t` dans le graphe résiduel.
- Implémenter la fonction `fordfulkerson` pour calculer le **flot maximum** et construire la **coupe minimale (S, S̄)**.

---

## ⚙️ Compilation (sans Makefile)

Compile avec `g++` :

```bash
g++ main.cpp utilities.cpp -o flot
```

## ▶️ Exécution
```bash
./flot
```
