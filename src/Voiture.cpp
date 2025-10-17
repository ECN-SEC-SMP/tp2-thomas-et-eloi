/**
 * @file Voiture.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr) & Thomas Verron (thomas.verron@eleves.ec-nantes.fr)
 * @brief Implémentation de la classe Voiture
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
 * @param vitesseMax Vitesse maximale de la voiture
 * @param nbPlaces Nombre de places (maximum 5)
 * @param occupants Nombre d'occupants initiaux
 */
Voiture::Voiture(int vitesseMax, int nbPlaces, int occupants) : Vehicule(vitesseMax, nbPlaces, occupants)
{
    if (nbPlaces > 5)
    {
        throw new invalid_argument("Une voiture ne peut pas avoir plus de 5 places.");
    }
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
 * @brief Arrête la voiture
 * La voiture doit être à vitesse nulle avant de pouvoir s'arrêter
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

/**
 * @brief Destroy the Voiture:: Voiture object
 */
Voiture::~Voiture()
{
    // cout << "La voiture a été détruit." << endl;
}