/**
 * @file VoitureAmphibie.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr) & Thomas Verron (thomas.verron@eleves.ec-nantes.fr)
 * @brief Implémentation de la classe VoitureAmphibie
 * @version 0.1
 * @date 17-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "VoitureAmphibie.hpp"

/**
 * @brief Construct a new Voiture Amphibie:: Voiture Amphibie object
 * 
 * @param vitesseMaxVoiture Vitesse maximale en mode voiture
 * @param vitesseMaxBateau Vitesse maximale en mode bateau
 * @param nbPlaces Nombre de places
 * @param occupants Nombre d'occupants initiaux
 */
VoitureAmphibie::VoitureAmphibie(int vitesseMaxVoiture, int vitesseMaxBateau, int nbPlaces, int occupants)
    : Voiture(vitesseMaxVoiture, nbPlaces, occupants), 
      Bateau(vitesseMaxBateau, nbPlaces, occupants)
{
    cout << "Création d'une voiture amphibie avec vitesse max voiture: " 
         << vitesseMaxVoiture << " km/h et vitesse max bateau: " 
         << vitesseMaxBateau << " km/h" << endl;
}

/**
 * @brief Affiche les différentes valeurs des attributs hérités de Voiture et Bateau
 * Cette méthode illustre que la VoitureAmphibie possède en double les attributs 
 * hérités de Vehicule avec des valeurs différentes
 */
void VoitureAmphibie::afficherAttributs() const
{
    cout << "\n===== Attributs de la Voiture Amphibie =====" << endl;
    
    cout << "\n--- Mode VOITURE (hérité de Voiture) ---" << endl;
    cout << "  Vitesse actuelle: " << Voiture::vitesse_ << " km/h" << endl;
    cout << "  Vitesse maximale: " << Voiture::vitesseMax_ << " km/h" << endl;
    cout << "  Nombre de places: " << Voiture::nbPlaces_ << endl;
    cout << "  Nombre d'occupants: " << Voiture::occupants_ << endl;
    cout << "  État: " << Voiture::getEtat() << endl;
    
    cout << "\n--- Mode BATEAU (hérité de Bateau) ---" << endl;
    cout << "  Vitesse actuelle: " << Bateau::vitesse_ << " km/h" << endl;
    cout << "  Vitesse maximale: " << Bateau::vitesseMax_ << " km/h" << endl;
    cout << "  Nombre de places: " << Bateau::nbPlaces_ << endl;
    cout << "  Nombre d'occupants: " << Bateau::occupants_ << endl;
    cout << "  État: " << Bateau::getEtat() << endl;
}

/**
 * @brief Démarre le véhicule amphibie (démarre les deux modes)
 */
void VoitureAmphibie::demarrer()
{
    cout << "Démarrage de la voiture amphibie..." << endl;
    cout << "  Mode voiture: ";
    try {
        Voiture::demarrer();
    } catch (exception* e) {
        cout << e->what() << endl;
    }
    
    cout << "  Mode bateau: ";
    try {
        Bateau::demarrer();
    } catch (exception* e) {
        cout << e->what() << endl;
    }
}

/**
 * @brief Arrête le véhicule amphibie (arrête les deux modes)
 */
void VoitureAmphibie::arreter()
{
    cout << "Arrêt de la voiture amphibie..." << endl;
    cout << "  Mode voiture: ";
    try {
        Voiture::arreter();
    } catch (exception* e) {
        cout << e->what() << endl;
    }
    
    cout << "  Mode bateau: ";
    try {
        Bateau::arreter();
    } catch (exception* e) {
        cout << e->what() << endl;
    }
}

/**
 * @brief Destroy the Voiture Amphibie:: Voiture Amphibie object
 */
VoitureAmphibie::~VoitureAmphibie()
{
    cout << "Destruction de la voiture amphibie" << endl;
}
