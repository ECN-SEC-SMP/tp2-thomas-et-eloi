/**
 * @file Voiture.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr) & Thomas Verron (thomas.verron@eleves.ec-nantes.fr)
 * @brief
 * @version 0.1
 * @date 14-10-2025
 *
 * @copyright Copyright (c) 2025
 *
 */

#include "Voiture.hpp"

/**
 * @brief Construct a new Voiture:: Voiture object
 * 
 * @param vitesseMax 
 * @param nbPlaces 
 * @param occupants 
 */
Voiture::Voiture(int vitesseMax, int nbPlaces, int occupants)
{
    if (nbPlaces > 5)
    {
        throw new invalid_argument("Une voiture ne peut pas avoir plus de 5 places.");
    }
    if (nbPlaces < 1)
    {
        throw new invalid_argument("Une voiture ne peut pas avoir moins d'une place.");
    }
    if (occupants > nbPlaces)
    {
        throw new invalid_argument("Le nombre d'occupant doit être égal ou inférieur au nombre de places");
    }

    this->vitesse_ = 0;
    this->vitesseMax_ = vitesseMax;
    this->nbPlaces_ = nbPlaces;
    this->occupants_ = occupants;
    this->etat_ = ARRET;

    cout << "La voiture a été créée." << endl;
}

/**
 * @brief Démarre la voiture
 *
 */
void Voiture::demarrer()
{
    if (this->etat_ == MARCHE)
    {
        throw new runtime_error("La voiture est déjà en marche !");
    }

    if ((this->etat_ == PANNE_LEGERE) || (this->etat_ == PANNE_SEVERE))
    {
        throw new runtime_error("La voiture est en panne !");
    }

    this->etat_ = MARCHE;
    cout << "La voiture à démarré." << endl;
}

/**
 * @brief
 *
 */
void Voiture::arreter()
{
    if (this->vitesse_ != 0)
    {
        throw new runtime_error("La voiture doit d'abord freiner !");
    }

    if (this->etat_ == ARRET)
    {
        throw new runtime_error("La voiture est déjà à l'arrêt !");
    }

    this->etat_ = ARRET;
    cout << "La voiture s'est arrêté." << endl;
}

Voiture::~Voiture()
{
    // // dtor
    // this->vitesse_ = 0;
    // this->vitesseMax_ = 0;
    // this->nbPlaces_ = 0;
    // this->occupants_ = 0;
    // this->etat_ = 0;

    cout << "La voiture a été détruit." << endl;
}