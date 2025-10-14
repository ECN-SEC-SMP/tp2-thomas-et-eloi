/**
 * @file main.cpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr) & Thomas Verron (thomas.verron@eleves.ec-nantes.fr)
 * @brief 
 * @version 0.1
 * @date 14-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "Vehicule.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int test()
{
    cout << "=== Tests des exceptions de la classe Vehicule ===" << endl << endl;
    
    // Création d'un véhicule pour les tests
    Vehicule voiture(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0
    
    try {
        voiture.demarrer();
        cout << "Véhicule démarré avec succès." << endl;
    } catch (invalid_argument* e) {
        cout << "Erreur lors du démarrage : " << e->what() << endl;
        delete e;
    }
    
    cout << endl << "--- Test 1: Vitesse négative ---" << endl;
    try {
        voiture.accelerer(-10); // Tentative de vitesse négative
        cout << "Accélération réussie (ne devrait pas s'afficher)" << endl;
    } catch (invalid_argument* e) {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }
    
    cout << endl << "--- Test 2: Dépassement de vitesse maximum ---" << endl;
    try {
        voiture.accelerer(150); // Dépasse la vitesse max de 120
        cout << "Accélération réussie (ne devrait pas s'afficher)" << endl;
    } catch (invalid_argument* e) {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }
    
    cout << endl << "--- Test 3: Démarrer un véhicule déjà en marche ---" << endl;
    try {
        voiture.demarrer(); // Déjà en marche
        cout << "Démarrage réussi (ne devrait pas s'afficher)" << endl;
    } catch (invalid_argument* e) {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }
    
    cout << endl << "--- Test 4: Démarrer un véhicule en panne ---" << endl;
    Vehicule voiturePanne(100, 4, 0);
    voiturePanne.mettreEnPanne(0.3); // Met en panne légère
    try {
        voiturePanne.demarrer();
        cout << "Démarrage réussi (ne devrait pas s'afficher)" << endl;
    } catch (invalid_argument* e) {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }
    
    cout << endl << "--- Test 5: Ajouter trop d'occupants ---" << endl;
    try {
        voiture.monter(6); // Tente d'ajouter 6 personnes dans un véhicule de 5 places
        cout << "Montée réussie (ne devrait pas s'afficher)" << endl;
    } catch (invalid_argument* e) {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }
    
    cout << endl << "--- Test 6: Faire descendre plus d'occupants qu'il y en a ---" << endl;
    try {
        voiture.monter(3); // Ajoute 3 personnes
        cout << "3 personnes sont montées dans le véhicule." << endl;
        voiture.descendre(5); // Tente de faire descendre 5 personnes
        cout << "Descente réussie (ne devrait pas s'afficher)" << endl;
    } catch (invalid_argument* e) {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }
    
    cout << endl << "--- Tests supplémentaires ---" << endl;
    
    // Test avec accélération normale
    try {
        voiture.accelerer(50); // Accélération normale
        cout << "Accélération à 50 km/h réussie." << endl;
    } catch (invalid_argument* e) {
        cout << "Erreur inattendue : " << e->what() << endl;
        delete e;
    }
    
    // Test avec freinage normal
    try {
        voiture.freiner(20); // Freinage normal
        cout << "Freinage de 20 km/h réussi." << endl;
    } catch (invalid_argument* e) {
        cout << "Erreur inattendue : " << e->what() << endl;
        delete e;
    }
    
    // Test avec freinage excessif (vitesse négative)
    try {
        voiture.freiner(50); // Freinage excessif (30 - 50 = -20)
        cout << "Freinage réussi (ne devrait pas s'afficher)" << endl;
    } catch (invalid_argument* e) {
        cout << "Exception capturée lors du freinage excessif : " << e->what() << endl;
        delete e;
    }
    
    cout << endl << "État final du véhicule : " << voiture << endl;
    
    cout << "=== Fin des tests ===" << endl;
    
    return 0;
}

int main()
{
    test();
    return 0;
}
