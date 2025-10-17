/**
 * @file Bateau.hpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr) & Thomas Verron (thomas.verron@eleves.ec-nantes.fr)
 * @brief Classe représentant un bateau, dérivée de Vehicule
 * @version 0.1
 * @date 14-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Vehicule.hpp"

/**
 * @brief Classe représentant un bateau
 * Hérite de Vehicule avec une contrainte sur la vitesse maximale (300 km/h)
 */
class Bateau : public Vehicule
{
public:
    /**
     * @brief Constructeur de Bateau
     * @param vitesseMax Vitesse maximale du bateau (par défaut 0, maximum 300)
     * @param nbPlaces Nombre de places (par défaut 1)
     * @param occupants Nombre d'occupants initiaux (par défaut 0)
     * @throw invalid_argument Si la vitesse maximale est supérieure à 300
     */
    Bateau(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0);

    /**
     * @brief Démarre le bateau
     * @throw runtime_error Si le bateau est déjà en marche ou en panne
     */
    virtual void demarrer();

    /**
     * @brief Arrête le bateau
     * @throw runtime_error Si le bateau n'est pas à vitesse nulle ou déjà à l'arrêt
     */
    virtual void arreter();

    /**
     * @brief Destructeur de Bateau
     */
    virtual ~Bateau();
};