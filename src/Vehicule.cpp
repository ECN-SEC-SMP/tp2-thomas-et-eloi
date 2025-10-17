/**
 * @file Vehicule.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr) & Thomas Verron (thomas.verron@eleves.ec-nantes.fr)
 * @brief Implémentation de la classe Vehicule
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
 * @param vitesseMax Vitesse maximale du véhicule
 * @param nbPlaces Nombre de places dans le véhicule
 * @param occupants Nombre d'occupants initiaux
 */
Vehicule::Vehicule(int vitesseMax, int nbPlaces, int occupants)
{
    if (nbPlaces < 1)
    {
        throw new invalid_argument("Le véhicule ne peut pas avoir moins d'une place.");
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

    cout << "Le véhicule a été créé." << endl;
}

/**
 * @brief Démarre le véhicule
 *
 */
void Vehicule::demarrer()
{
    if (this->etat_ == MARCHE)
    {
        throw new runtime_error("Le vehicule est déjà en marche !");
    }

    if ((this->etat_ == PANNE_LEGERE) || (this->etat_ == PANNE_SEVERE))
    {
        throw new runtime_error("Le vehicule est en panne !");
    }

    this->etat_ = MARCHE;
    cout << "Le véhicule à démarré." << endl;
}

/**
 * @brief Arrête le véhicule
 * Le véhicule doit d'abord avoir une vitesse nulle avant de s'arrêter
 */
void Vehicule::arreter()
{
    if (this->vitesse_ != 0)
    {
        throw new runtime_error("Le vehicule doit d'abord freiner !");
    }

    if (this->etat_ == ARRET)
    {
        throw new runtime_error("Le vehicule est déjà à l'arrêt !");
    }

    this->etat_ = ARRET;
    cout << "Le véhicule s'est arrêté." << endl;
}

/**
 * @brief Dépanne le véhicule
 * Remet le véhicule à l'état d'arrêt s'il était en panne
 */
void Vehicule::depanner()
{
    if ((this->etat_ == MARCHE) || (this->etat_ == ARRET))
    {
        throw new runtime_error("Le vehicule n'est pas en panne !");
    }

    if ((this->etat_ == PANNE_LEGERE) || (this->etat_ == PANNE_SEVERE))
    {
        this->etat_ = ARRET;
        cout << "Le véhicule a été dépanné." << endl;
    }
}

/**
 * @brief Accélère ou ralentit le véhicule
 * 
 * @param increment Valeur à ajouter à la vitesse actuelle (peut être négative pour ralentir)
 */
void Vehicule::accelerer(int increment)
{
    if (this->etat_ != MARCHE)
    {
        throw new runtime_error("Le véhicule n'est pas en marche !");
    }

    if ((this->vitesse_ + increment) < 0)
    {
        throw new invalid_argument("Valeur négative");
    }

    if ((this->vitesse_ + increment) > this->vitesseMax_)
    {
        throw new invalid_argument("Valeur trop élevée");
    }

    this->vitesse_ += increment;
    if (increment >= 0)
        cout << "Le véhicule accélère de " << increment << " km/h." << endl;
    else
        cout << "Le véhicule freine de " << increment << " km/h." << endl;
}

/**
 * @brief Freine le véhicule
 * 
 * @param decrement Valeur positive à retirer de la vitesse actuelle
 */
void Vehicule::freiner(int decrement)
{
    if (this->etat_ != MARCHE)
    {
        throw new runtime_error("Le vehicule n'est pas en marche !");
    }

    if (decrement < 0)
    {
        throw new invalid_argument("Le decrement doit être positif !");
    }

    this->accelerer(-decrement);
}

/**
 * @brief Fait monter des occupants dans le véhicule
 * 
 * @param nbOcc Nombre de personnes à faire monter
 */
void Vehicule::monter(int nbOcc)
{
    if (this->etat_ != ARRET)
    {
        throw new runtime_error("Le vehicule doit être à l'arrêt pour que des personnes montent !");
    }

    if (nbOcc < 0)
    {
        throw new invalid_argument("Le nombre de personne qui montent ne peut pas être négatif");
    }

    if (nbOcc + this->occupants_ > this->nbPlaces_)
    {
        throw new invalid_argument("Le nombre de place dans la voiture est insuffisant !");
    }

    this->occupants_ += nbOcc;
    cout << nbOcc << " personnes sont montées dans le véhicule." << endl;
}

/**
 * @brief Fait descendre des occupants du véhicule
 * 
 * @param nbOcc Nombre de personnes à faire descendre
 */
void Vehicule::descendre(int nbOcc)
{
    if (this->etat_ != ARRET)
    {
        throw new runtime_error("Le vehicule doit être à l'arrêt pour que des personnes montent !");
    }

    if (nbOcc < 0)
    {
        throw new invalid_argument("Le nombre de personne qui descendent ne peut pas être négatif");
    }

    if (this->occupants_ - nbOcc < 0)
    {
        throw new invalid_argument("Trop de personnes, descendent ! Le nombre de personne dans la voiture ne peut pas être négatif");
    }

    this->occupants_ -= nbOcc;
    cout << nbOcc << " personnes sont descendues du véhicule." << endl;
}

/**
 * @brief Met le véhicule en panne (légère ou sévère)
 * 
 * @param random Valeur aléatoire entre 0 et 1 pour déterminer le type de panne
 */
void Vehicule::mettreEnPanne(double random)
{
    if (this->etat_ == PANNE_LEGERE || this->etat_ == PANNE_SEVERE)
    {
        throw new runtime_error("Le vehicule est déjà en panne !");
    }

    if (random < 0.5)
    {
        this->etat_ = PANNE_LEGERE;
        cout << "Le véhicule est en panne légère." << endl;
    }
    else
    {
        this->etat_ = PANNE_SEVERE;
        cout << "Le véhicule est en panne sévère." << endl;
    }
}

/**
 * @brief Retourne l'état actuel du véhicule sous forme de chaîne de caractères
 * 
 * @return string Représentation textuelle de l'état
 */
string Vehicule::getEtat() const
{
    switch (this->etat_)
    {
    case ARRET:
        return "Arrêt";
    case MARCHE:
        return "Marche";
    case PANNE_LEGERE:
        return "Panne légère";
    case PANNE_SEVERE:
        return "Panne sévère";
    default:
        return "Etat inconnu";
    }
}
/**
 * @brief Destroy the Vehicule:: Vehicule object
 *
 */
Vehicule::~Vehicule()
{
    // dtor
    this->vitesse_ = 0;
    this->vitesseMax_ = 0;
    this->nbPlaces_ = 0;
    this->occupants_ = 0;
    this->etat_ = 0;

    cout << "Le véhicule a été détruit." << endl;
}

/**
 * @brief Opérateur d'affichage pour un véhicule
 * Affiche la fiche technique complète du véhicule
 * 
 * @param s Flux de sortie
 * @param v Véhicule à afficher
 * @return ostream& Référence vers le flux de sortie
 */
ostream &operator<<(ostream &s, Vehicule const &v)
{
    s << "Fiche technique de " << &v << " :" << endl;
    s << "  - Vitesse : " << v.vitesse_ << endl;
    s << "  - Vitesse max : " << v.vitesseMax_ << endl;
    s << "  - Nombre de places : " << v.nbPlaces_ << endl;
    s << "  - Nombre d'occupants : " << v.occupants_ << endl;
    s << "  - Etat : " << v.getEtat() << endl;
    return s;
}