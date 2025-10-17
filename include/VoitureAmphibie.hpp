/**
 * @file VoitureAmphibie.hpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr) & Thomas Verron (thomas.verron@eleves.ec-nantes.fr)
 * @brief Classe VoitureAmphibie héritant de Voiture et Bateau
 * @version 0.1
 * @date 17-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Voiture.hpp"
#include "Bateau.hpp"

/**
 * @brief Classe représentant un véhicule amphibie (voiture et bateau)
 * Hérite à la fois de Voiture et de Bateau, possédant ainsi deux instances
 * des attributs de Vehicule avec des vitesses maximales différentes
 */
class VoitureAmphibie : public Voiture, public Bateau
{
public:
    /**
     * @brief Constructeur de VoitureAmphibie
     * @param vitesseMaxVoiture Vitesse maximale en mode voiture
     * @param vitesseMaxBateau Vitesse maximale en mode bateau
     * @param nbPlaces Nombre de places
     * @param occupants Nombre d'occupants initiaux
     */
    VoitureAmphibie(int vitesseMaxVoiture = 0, int vitesseMaxBateau = 0, int nbPlaces = 1, int occupants = 0);

    /**
     * @brief Affiche les différentes valeurs des attributs hérités
     * Montre les valeurs des attributs provenant de Voiture et de Bateau
     */
    void afficherAttributs() const;

    /**
     * @brief Démarre le véhicule amphibie
     */
    virtual void demarrer();

    /**
     * @brief Arrête le véhicule amphibie
     */
    virtual void arreter();

    /**
     * @brief Destructeur
     */
    virtual ~VoitureAmphibie();
};
