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
Vehicule::Vehicule(int vitesseMax, int nbPlaces, int occupants)
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
void Vehicule::demarrer()
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
void Vehicule::arreter()
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
void Vehicule::depanner()
{
    if (this->etat_ == MARCHE)
    {
        throw new invalid_argument("Le vehicule doit être à l'arrêt pour le dépannage !");
    }
    else if (this->etat_ == ARRET)
    {
        throw new invalid_argument("Le vehicule n'est pas en panne !");
    }
    else if ((this->etat_ == PANNE_LEGERE) || (this->etat_ == PANNE_SEVERE))
    {
        this->etat_ = ARRET;
    }
}

void Vehicule::accelerer(int increment) {
    if(this->etat_ != MARCHE) {
        throw new invalid_argument("Impossible d'accélérer !");
    }
    if((this->vitesse_ + increment) < 0) {
        throw new invalid_argument("Valeur négative");
    }
    if((this->vitesse_ + increment) > this->vitesseMax_) {
        throw new invalid_argument("Valeur trop élevée");
    }
    this->vitesse_ += increment;
}

/**
 * @brief 
 * 
 * @param decrement 
 */
void Vehicule::freiner(int decrement)
{
    if (this->etat_ != MARCHE)
    {
        throw new invalid_argument("Le vehicule n'est pas en marche !");
    }
    if (decrement < 0)
    {
        throw new invalid_argument("Le decrement doit être positif !");
    }
        this->accelerer(-decrement);
}

/**
 * @brief 
 * 
 * @param nbOcc 
 */
void Vehicule::monter(int nbOcc) {
    if (nbOcc < 0) {
        throw new invalid_argument("Le nombre de personne qui montent ne peut pas être négatif");
    }
    if(nbOcc + this->occupants_ > this->nbPlaces_){
        throw new invalid_argument("Le nombre de place dans la voiture est insuffisant !");
    }
    this->occupants_ += nbOcc;
}

/**
 * @brief 
 * 
 * @param nbOcc 
 */
void Vehicule::descendre(int nbOcc) {
    if (nbOcc < 0) {
        throw new invalid_argument("Le nombre de personne qui descendent ne peut pas être négatif");
    }
    if(this->occupants_ - nbOcc < 0){
        throw new invalid_argument("Trop de personnes, descendent ! Le nombre de personne dans la voiture ne peut pas être négatif");
    }
    this->occupants_ -= nbOcc;
}

/**
 * @brief 
 * 
 * @param random 
 */
void Vehicule::mettreEnPanne(double random) {
    if(random<0.5) {
        this->etat_ = PANNE_LEGERE;
    }
    else {
        this->etat_ = PANNE_SEVERE;
    }
}

/**
 * @brief 
 * 
 * @return string 
 */
string Vehicule::getEtat() const {
    switch(this->etat_) {
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
Vehicule::~Vehicule() {
    //dtor
    this->vitesse_ = 0;
    this->vitesseMax_ = 0;
    this->nbPlaces_ = 0;
    this->occupants_ = 0;
    this->etat_ = 0;
}

/**
 * @brief 
 * 
 * @param s 
 * @param v 
 * @return ostream& 
 */
ostream& operator<<(ostream& s,Vehicule const& v) {
    s << "Fiche technique de " << &v << " :" << endl;
    s << "Vitesse : " << v.vitesse_ << endl;
    s << "Vitesse max : " << v.vitesseMax_ << endl;
    s << "Nombre de places : " << v.nbPlaces_ << endl;
    s << "Nombre d'occupants : " << v.occupants_ << endl;
    s << "Etat : " << v.getEtat() << endl;
    return s;
}