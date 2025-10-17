/**
 * @file Bateau.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr) & Thomas Verron (thomas.verron@eleves.ec-nantes.fr)
 * @brief 
 * @version 0.1
 * @date 14-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include "Bateau.hpp"


Bateau::Bateau(int vitesseMax, int nbPlaces, int occupants) : Vehicule(vitesseMax, nbPlaces, occupants)
{
    if (vitesseMax > 300)
    {
        throw new invalid_argument("La vitesse d'un bateau ne peut pas dépasser 300.");
    }
}

/**
 * @brief Démarre le Bateau
 *
 */
void Bateau::demarrer()
{
    if (this->etat_ == MARCHE)
    {
        throw new runtime_error("Le bateau est déjà en marche !");
    }

    if ((this->etat_ == PANNE_LEGERE) || (this->etat_ == PANNE_SEVERE))
    {
        throw new runtime_error("Le bateau est en panne !");
    }

    this->etat_ = MARCHE;
    cout << "Le bateau à démarré." << endl;
}

/**
 * @brief
 *
 */
void Bateau::arreter()
{
    if (this->vitesse_ != 0)
    {
        throw new runtime_error("Le bateau doit d'abord freiner !");
    }

    if (this->etat_ == ARRET)
    {
        throw new runtime_error("Le bateau est déjà à l'arrêt !");
    }

    this->etat_ = ARRET;
    cout << "Le bateau s'est arrêté." << endl;
}

Bateau::~Bateau()
{
    // cout << "Le Bateau a été détruit." << endl;
}