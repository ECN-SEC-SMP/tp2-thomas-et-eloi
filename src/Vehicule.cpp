/**
 * @file Vehicule.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr) & Thomas Verron (thomas.verron@eleves.ec-nantes.fr)
 * @brief 
 * @version 0.1
 * @date 14-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "Vehicule.hpp"

/**
 * @brief Construct a new Vehicule:: Vehicule object
 * 
 * @param vitesseMax 
 * @param nbPlaces 
 * @param occupants 
 */
Vehicule::Vehicule(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0)
{
    this->vitesseMax_ = vitesseMax;
    this->nbPlaces_ = nbPlaces;
    this->occupants_ = occupants;
    this->etat_ = ARRET;
}

/**
 * @brief 
 * 
 */
Vehicule::demarrer()
{
    if (this->etat_ == MARCHE)
    {
        throw new invalid_argument("Le vehicule est déjà en marche !");
    }
    else if ((this->etat_ == PANNE_LEGERE) || (this->etat_ == PANNE_SEVERE))
    {
        throw new invalid_argument("Le vehicule est en panne !");
    }
    else
    {
        this->etat_ = MARCHE;
    }
}

/**
 * @brief 
 * 
 */
Vehicule::arreter()
{
    if (this->vitesse_ != 0)
    {
        throw new invalid_argument("Le vehicule doit d'abord freiner !");
    }
    else
    {
        this->etat_ = ARRET;
    }
}

/**
 * @brief 
 * 
 */
Vehicule::depanner()
{
    if (this->etats_ == MARCHE)
    {
        throw new invalid_argument("Le vehicule doit être à l'arrêt pour le dépannage !");
    }
    else if (this->etats_ == ARRET)
    {
        throw new invalid_argument("Le vehicule n'est pas en panne !");
    }
    else if ((this->etat_ == PANNE_LEGERE) || (this->etat_ == PANNE_SEVERE))
    {
        this->etats_ = ARRET;
    }
}
