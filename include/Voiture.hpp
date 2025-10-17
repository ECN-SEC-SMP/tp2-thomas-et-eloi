/**
 * @file Voiture.hpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr) & Thomas Verron (thomas.verron@eleves.ec-nantes.fr)
 * @brief
 * @version 0.1
 * @date 14-10-2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#pragma once

#include "Vehicule.hpp"

/**
 * @brief Classe représentant une voiture
 * Hérite de Vehicule avec une contrainte sur le nombre maximum de places (5)
 */
class Voiture : public Vehicule
{
public:
    /**
     * @brief Constructeur de Voiture
     * @param vitesseMax Vitesse maximale de la voiture (par défaut 0)
     * @param nbPlaces Nombre de places (par défaut 1, maximum 5)
     * @param occupants Nombre d'occupants initiaux (par défaut 0)
     * @throw invalid_argument Si le nombre de places est supérieur à 5
     */
    Voiture(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0);

    /**
     * @brief Démarre la voiture
     * @throw runtime_error Si la voiture est déjà en marche ou en panne
     */
    virtual void demarrer();

    /**
     * @brief Arrête la voiture
     * @throw runtime_error Si la voiture n'est pas à vitesse nulle ou déjà à l'arrêt
     */
    virtual void arreter();

    /**
     * @brief Destructeur de Voiture
     */
    virtual ~Voiture();
};