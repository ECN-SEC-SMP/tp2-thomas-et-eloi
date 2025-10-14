
# TP1 - Création et manipulation d'un lexique

- SEC 2
- Eloi Tourangin - eloi.tourangin@eleves.ec-nantes.fr
- Thomas Verron - thomas.verron@eleves.ec-nantes.fr

Ce projet implemente une hiérarchie de classes pour modéliser différents types de véhicules.
Voici les classes :

- `Vehicule` : Classe de base abstraite représentant un véhicule générique.

## Table des matières

- [Compilation et éxecution](#compilation-et-éxecution)

<div style="page-break-after: always;"></div>

# Compilation et éxecution

```bash
# Compiler
make

# Exécuter
./build/main.out
```

ou executer le script bash

```bash
./build_and_execute.sh
```

# Classe Vehicule

La classe `Vehicule` est une classe abstraite qui sert de base pour différents types de véhicules. Elle contient des attributs et des méthodes communes à tous les véhicules.

## Attributs

- `vitesse_` : Vitesse actuelle du véhicule.
- `vitesseMax_`' : Vitesse maximale du véhicule.
- `nbPlaces_` : Nombre maximum de places dans le véhicule.
- `occupants_` : Nombre actuel d'occupants dans le véhicule.
- `etat_` : État du véhicule (0 : ARRET, 1 : MARCHE, 2 : PANNE_LEGERE, 3 : PANNE_SEVERE).

## Méthodes

- `Vehicule(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0)` : Constructeur de la classe.
- `demarrer()` : Démarre le véhicule.
- `arreter()` : Arrête le véhicule.
- `depanner()` : Dépanne le véhicule.
- `accelerer(int increment)` : Accélère le véhicule d'un certain incrément.
- `freiner(int decrement)` : Freine le véhicule d'un certain décrément.
- `monter(int nbOcc)` : Fait monter un certain nombre d'occupants
- `descendre(int nbOcc)` : Fait descendre un certain nombre d'occupants.
- `mettreEnPanne(double random)` : Met le véhicule en panne selon une probabilité
- `getEtat() const` : Retourne l'état actuel du véhicule sous forme de chaîne de caractères.
- `~Vehicule()` : Destructeur de la classe.
- `operator<<` : Surcharge de l'opérateur d'insertion pour afficher les informations du véhicule.

### Constructeur Vehicule

### Méthode demarrer

### Méthode arreter

### Méthode depanner

### Méthode accelerer

### Méthode freiner

### Méthode monter

### Méthode descendre

### Méthode mettreEnPanne

### Méthode getEtat

### Destructeur ~Vehicule

### Surcharge de l'opérateur <<