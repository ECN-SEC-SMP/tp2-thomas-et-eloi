/**
 * @file Bateau.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr) & Thomas Verron (thomas.verron@eleves.ec-nantes.fr)
 * @brief Implémentation de la classe Bateau
 * @version 0.1
 * @date 14-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #include "Bateau.hpp"

/**
 * @brief Construct a new Bateau:: Bateau object
 * 
 * @param vitesseMax Vitesse maximale du bateau (maximum 300)
 * @param nbPlaces Nombre de places
 * @param occupants Nombre d'occupants initiaux
 */
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
 * @brief Arrête le bateau
 * Le bateau doit être à vitesse nulle avant de pouvoir s'arrêter
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

/**
 * @brief Destroy the Bateau:: Bateau object
 */
Bateau::~Bateau()
{
    // cout << "Le Bateau a été détruit." << endl;
}