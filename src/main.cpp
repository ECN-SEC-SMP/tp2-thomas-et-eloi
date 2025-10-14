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

void testDemarrer();
void testArreter();
void testDepanner();
void testAccelerer();
void testFreiner();
void testMonter();
void testDescendre();
void testMettreEnPanne();

void testVehicule();

void testDemarrer()
{
    cout << "=== Test de la méthode demarrer() ===" << endl
         << endl;

    Vehicule voitureTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0
    
    try
    {
        voitureTest.demarrer();
        cout << "Véhicule démarré avec succès." << endl;
    }
    catch(runtime_error *e)
    {
        cerr << "Erreur lors du démarrage : " << e->what() << '\n';
    }

    try
    {
        voitureTest.demarrer();
        cout << "Véhicule démarré avec succès." << endl;
    }
    catch(runtime_error *e)
    {
        cerr << "Erreur lors du démarrage : " << e->what() << '\n';
    }

    voitureTest.mettreEnPanne(0.3); // Met en panne légère

    try
    {
        voitureTest.demarrer();
        cout << "Véhicule démarré avec succès." << endl;
    }
    catch(runtime_error *e)
    {
        cerr << "Erreur lors du démarrage : " << e->what() << '\n';
    }
}

void testArreter()
{
    cout << "=== Test de la méthode arreter() ===" << endl
         << endl;

    Vehicule voitureTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    voitureTest.demarrer();
    voitureTest.accelerer(50); // Accélération normale

    try
    {
        voitureTest.arreter();
        cout << "Véhicule arrêté avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de l'arrêt : " << e->what() << '\n';
    }

    voitureTest.freiner(50); // Freinage normal

    try
    {
        voitureTest.arreter();
        cout << "Véhicule arrêté avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de l'arrêt : " << e->what() << '\n';
    }

    try
    {
        voitureTest.arreter();
        cout << "Véhicule arrêté avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de l'arrêt : " << e->what() << '\n';
    }
}

void testDepanner()
{
    cout << "=== Test de la méthode depanner() ===" << endl
         << endl;

    Vehicule voitureTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    try
    {
        voitureTest.depanner();
        cout << "Véhicule dépanné avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du dépannage : " << e->what() << '\n';
    }

    voitureTest.demarrer();

    try
    {
        voitureTest.depanner();
        cout << "Véhicule dépanné avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du dépannage : " << e->what() << '\n';
    }

    voitureTest.arreter();
    voitureTest.mettreEnPanne(0.3); // Met en panne légère

    try
    {
        voitureTest.depanner();
        cout << "Véhicule dépanné avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du dépannage : " << e->what() << '\n';
    }
}

void testAccelerer()
{
    cout << "=== Test de la méthode accelerer() ===" << endl
         << endl;

    Vehicule voitureTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    try
    {
        voitureTest.accelerer(10); // Tentative de vitesse à l'arret
        cout << "Accélération réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (runtime_error *e)
    {
        cout << "Erreur lors de l'accélération : " << e->what() << endl;
        delete e;
    }

    voitureTest.demarrer();

    try
    {
        voitureTest.accelerer(-10); // Tentative de vitesse négative
        cout << "Accélération réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    try
    {
        voitureTest.accelerer(150); // Dépasse la vitesse max de 120
        cout << "Accélération réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    try
    {
        voitureTest.accelerer(50); // Accélération normale
        cout << "Accélération à 50 km/h réussie." << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Erreur inattendue : " << e->what() << endl;
        delete e;
    }
}

void testFreiner()
{
    cout << "=== Test de la méthode freiner() ===" << endl
         << endl;

    Vehicule voitureTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    try
    {
        voitureTest.freiner(10); // Tentative de freinage à l'arret
        cout << "Freinage réussi (ne devrait pas s'afficher)" << endl;
    }
    catch (runtime_error *e)
    {
        cout << "Erreur lors du freinage : " << e->what() << endl;
        delete e;
    }

    voitureTest.demarrer();
    voitureTest.accelerer(50); // Accélération normale

    try
    {
        voitureTest.freiner(-10); // Tentative de freinage négatif
        cout << "Freinage réussi (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    try
    {
        voitureTest.freiner(20); // Freinage normal
        cout << "Freinage de 20 km/h réussi." << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Erreur inattendue : " << e->what() << endl;
        delete e;
    }

    try
    {
        voitureTest.freiner(50); // Freinage excessif (30 - 50 = -20)
        cout << "Freinage réussi (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée lors du freinage excessif : " << e->what() << endl;
        delete e;
    }
}

void testMonter()
{
    cout << "=== Test de la méthode monter(int nbOcc) ===" << endl
         << endl;

    Vehicule voitureTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    try
    {
        voitureTest.monter(-1); // Tentative de monter un nombre négatif de personnes
        cout << "Montée réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    try
    {
        voitureTest.monter(6); // Tente d'ajouter 6 personnes dans un véhicule de 5 places
        cout << "Montée réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    voitureTest.demarrer();
    try
    {
        voitureTest.monter(2); // Tentative de monter des personnes alors que le véhicule est en marche
        cout << "Montée réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (runtime_error *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    voitureTest.arreter();

    try
    {
        voitureTest.monter(3); // Ajoute 3 personnes
        cout << "Montées dans le véhicule réussies." << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Erreur inattendue : " << e->what() << endl;
        delete e;
    }
}

void testDescendre()
{
    cout << "=== Test de la méthode descendre(int nbOcc) ===" << endl
         << endl;

    Vehicule voitureTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    try
    {
        voitureTest.descendre(-1); // Tentative de descendre un nombre négatif de personnes
        cout << "Descente réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    try
    {
        voitureTest.descendre(1); // Tente de faire descendre 1 personne alors qu'il n'y en a pas
        cout << "Descente réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    voitureTest.monter(3); // Ajoute 3 personnes

    try
    {
        voitureTest.descendre(5); // Tente de faire descendre 5 personnes
        cout << "Descente réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    voitureTest.demarrer();

    try
    {
        voitureTest.descendre(2); // Tentative de descendre des personnes alors que le véhicule est en marche
        cout << "Descente réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (runtime_error *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    voitureTest.arreter();

    try
    {
        voitureTest.descendre(2); // Fait descendre 2 personnes
        cout << "Descente réussie." << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Erreur inattendue : " << e->what() << endl;
        delete e;
    }
}
void testMettreEnPanne()
{
    cout << "=== Test de la méthode mettreEnPanne(double random) ===" << endl
         << endl;

    Vehicule voitureTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    voitureTest.demarrer();

    try
    {
        voitureTest.mettreEnPanne(0.3); // Met en panne légère
        cout << "Véhicule mis en panne avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de la mise en panne : " << e->what() << '\n';
    }

    try
    {
        voitureTest.mettreEnPanne(0.7); // Tentative de mettre en panne un véhicule déjà en panne
        cout << "Véhicule mis en panne avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de la mise en panne : " << e->what() << '\n';
    }
}

void testVehicule()
{
    testDemarrer();
    cout << endl;
    testArreter();
    cout << endl;
    testDepanner();
    cout << endl;
    testAccelerer();
    cout << endl;
    testFreiner();
    cout << endl;
    testMonter();
    cout << endl;
    testDescendre();
    cout << endl;
    testMettreEnPanne();
}

int main()
{
    testVehicule();
    return 0;
}
