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
#include "Voiture.hpp"
#include "Bateau.hpp"
#include "VoitureAmphibie.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void testVehiculeConstruct();
void testVehiculeDemarrer();
void testVehiculeArreter();
void testVehiculeDepanner();
void testVehiculeAccelerer();
void testVehiculeFreiner();
void testVehiculeMonter();
void testVehiculeDescendre();
void testVehiculeMettreEnPanne();

void testVehicule();

void testVoitureConstruct();
void testVoitureDemarrer();
void testVoitureArreter();

void testVoiture();

void testBateauConstruct();
void testBateauDemarrer();
void testBateauArreter();

void testBateau();

void testVoitureAmphibieConstruct();
void testVoitureAmphibieAfficherAttributs();
void testVoitureAmphibieDemarrer();
void testVoitureAmphibieArreter();
void testVoitureAmphibieModesIndependants();

void testVoitureAmphibie();

void testVehiculeConstruct()
{
    cout << "=== Test du constructeur de Vehicule ===" << endl
         << endl;

    try
    {
        Vehicule vehiculeTest(120, 0, 0);
        cout << "Véhicule crée (pas sensé arriver)." << endl;
    }
    catch (invalid_argument *e)
    {
        std::cerr << "Erreur constructeur : " << e->what() << '\n';
    }

    try
    {
        Vehicule vehiculeTest(120, 5, 6);
        cout << "Véhicule crée (pas sensé arriver)." << endl;
    }
    catch (invalid_argument *e)
    {
        std::cerr << "Erreur constructeur : " << e->what() << '\n';
    }

    try
    {
        Vehicule vehiculeTest(120, 5, 2);
        cout << "Véhicule créé sans pb." << endl;
    }
    catch (invalid_argument *e)
    {
        std::cerr << "Erreur constrcuteur : " << e->what() << '\n';
    }
}

void testVehiculeDemarrer()
{
    cout << "=== Test de la méthode demarrer() ===" << endl
         << endl;

    Vehicule vehiculeTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    try
    {
        vehiculeTest.demarrer();
        cout << "Véhicule démarré avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du démarrage : " << e->what() << '\n';
    }

    try
    {
        vehiculeTest.demarrer();
        cout << "Véhicule démarré avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du démarrage : " << e->what() << '\n';
    }

    vehiculeTest.mettreEnPanne(0.3); // Met en panne légère

    try
    {
        vehiculeTest.demarrer();
        cout << "Véhicule démarré avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du démarrage : " << e->what() << '\n';
    }
}

void testVehiculeArreter()
{
    cout << "=== Test de la méthode arreter() ===" << endl
         << endl;

    Vehicule vehiculeTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    vehiculeTest.demarrer();
    vehiculeTest.accelerer(50); // Accélération normale

    try
    {
        vehiculeTest.arreter();
        cout << "Véhicule arrêté avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de l'arrêt : " << e->what() << '\n';
    }

    vehiculeTest.freiner(50); // Freinage normal

    try
    {
        vehiculeTest.arreter();
        cout << "Véhicule arrêté avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de l'arrêt : " << e->what() << '\n';
    }

    try
    {
        vehiculeTest.arreter();
        cout << "Véhicule arrêté avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de l'arrêt : " << e->what() << '\n';
    }
}

void testVehiculeDepanner()
{
    cout << "=== Test de la méthode depanner() ===" << endl
         << endl;

    Vehicule vehiculeTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    try
    {
        vehiculeTest.depanner();
        cout << "Véhicule dépanné avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du dépannage : " << e->what() << '\n';
    }

    vehiculeTest.demarrer();

    try
    {
        vehiculeTest.depanner();
        cout << "Véhicule dépanné avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du dépannage : " << e->what() << '\n';
    }

    vehiculeTest.arreter();
    vehiculeTest.mettreEnPanne(0.3); // Met en panne légère

    try
    {
        vehiculeTest.depanner();
        cout << "Véhicule dépanné avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du dépannage : " << e->what() << '\n';
    }
}

void testVehiculeAccelerer()
{
    cout << "=== Test de la méthode accelerer() ===" << endl
         << endl;

    Vehicule vehiculeTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    try
    {
        vehiculeTest.accelerer(10); // Tentative de vitesse à l'arret
        cout << "Accélération réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (runtime_error *e)
    {
        cout << "Erreur lors de l'accélération : " << e->what() << endl;
        delete e;
    }

    vehiculeTest.demarrer();

    try
    {
        vehiculeTest.accelerer(-10); // Tentative de vitesse négative
        cout << "Accélération réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    try
    {
        vehiculeTest.accelerer(150); // Dépasse la vitesse max de 120
        cout << "Accélération réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    try
    {
        vehiculeTest.accelerer(50); // Accélération normale
        cout << "Accélération à 50 km/h réussie." << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Erreur inattendue : " << e->what() << endl;
        delete e;
    }
}

void testVehiculeFreiner()
{
    cout << "=== Test de la méthode freiner() ===" << endl
         << endl;

    Vehicule vehiculeTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    try
    {
        vehiculeTest.freiner(10); // Tentative de freinage à l'arret
        cout << "Freinage réussi (ne devrait pas s'afficher)" << endl;
    }
    catch (runtime_error *e)
    {
        cout << "Erreur lors du freinage : " << e->what() << endl;
        delete e;
    }

    vehiculeTest.demarrer();
    vehiculeTest.accelerer(50); // Accélération normale

    try
    {
        vehiculeTest.freiner(-10); // Tentative de freinage négatif
        cout << "Freinage réussi (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    try
    {
        vehiculeTest.freiner(20); // Freinage normal
        cout << "Freinage de 20 km/h réussi." << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Erreur inattendue : " << e->what() << endl;
        delete e;
    }

    try
    {
        vehiculeTest.freiner(50); // Freinage excessif (30 - 50 = -20)
        cout << "Freinage réussi (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée lors du freinage excessif : " << e->what() << endl;
        delete e;
    }
}

void testVehiculeMonter()
{
    cout << "=== Test de la méthode monter(int nbOcc) ===" << endl
         << endl;

    Vehicule vehiculeTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    try
    {
        vehiculeTest.monter(-1); // Tentative de monter un nombre négatif de personnes
        cout << "Montée réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    try
    {
        vehiculeTest.monter(6); // Tente d'ajouter 6 personnes dans un véhicule de 5 places
        cout << "Montée réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    vehiculeTest.demarrer();
    try
    {
        vehiculeTest.monter(2); // Tentative de monter des personnes alors que le véhicule est en marche
        cout << "Montée réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (runtime_error *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    vehiculeTest.arreter();

    try
    {
        vehiculeTest.monter(3); // Ajoute 3 personnes
        cout << "Montées dans le véhicule réussies." << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Erreur inattendue : " << e->what() << endl;
        delete e;
    }
}

void testVehiculeDescendre()
{
    cout << "=== Test de la méthode descendre(int nbOcc) ===" << endl
         << endl;

    Vehicule vehiculeTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    try
    {
        vehiculeTest.descendre(-1); // Tentative de descendre un nombre négatif de personnes
        cout << "Descente réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    try
    {
        vehiculeTest.descendre(1); // Tente de faire descendre 1 personne alors qu'il n'y en a pas
        cout << "Descente réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    vehiculeTest.monter(3); // Ajoute 3 personnes

    try
    {
        vehiculeTest.descendre(5); // Tente de faire descendre 5 personnes
        cout << "Descente réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    vehiculeTest.demarrer();

    try
    {
        vehiculeTest.descendre(2); // Tentative de descendre des personnes alors que le véhicule est en marche
        cout << "Descente réussie (ne devrait pas s'afficher)" << endl;
    }
    catch (runtime_error *e)
    {
        cout << "Exception capturée : " << e->what() << endl;
        delete e;
    }

    vehiculeTest.arreter();

    try
    {
        vehiculeTest.descendre(2); // Fait descendre 2 personnes
        cout << "Descente réussie." << endl;
    }
    catch (invalid_argument *e)
    {
        cout << "Erreur inattendue : " << e->what() << endl;
        delete e;
    }
}
void testVehiculeMettreEnPanne()
{
    cout << "=== Test de la méthode mettreEnPanne(double random) ===" << endl
         << endl;

    Vehicule vehiculeTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    vehiculeTest.demarrer();

    try
    {
        vehiculeTest.mettreEnPanne(0.3); // Met en panne légère
        cout << "Véhicule mis en panne avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de la mise en panne : " << e->what() << '\n';
    }

    try
    {
        vehiculeTest.mettreEnPanne(0.7); // Tentative de mettre en panne un véhicule déjà en panne
        cout << "Véhicule mis en panne avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de la mise en panne : " << e->what() << '\n';
    }
}

void testVehicule()
{
    testVehiculeConstruct();
    cout << endl;
    testVehiculeDemarrer();
    cout << endl;
    testVehiculeArreter();
    cout << endl;
    testVehiculeDepanner();
    cout << endl;
    testVehiculeAccelerer();
    cout << endl;
    testVehiculeFreiner();
    cout << endl;
    testVehiculeMonter();
    cout << endl;
    testVehiculeDescendre();
    cout << endl;
    testVehiculeMettreEnPanne();
}

void testVoitureConstruct()
{
    cout << "=== Test du constructeur de Voiture ===" << endl
         << endl;

    try
    {
        Voiture voitureTest(120, 6, 0);
        cout << "Voiture 6 place créée (impossible)." << endl;
    }
    catch (invalid_argument *e)
    {
        std::cerr << "Erreur lors de la création : " << e->what() << '\n';
    }

    try
    {
        Voiture voitureTest(120, 2, 4);
        cout << "Voiture créée avec + de personne que de place (impossible)." << endl;
    }
    catch (invalid_argument *e)
    {
        std::cerr << "Erreur lors de la création : " << e->what() << '\n';
    }

    try
    {
        Voiture voitureTest(120, 5, 4);
        cout << "Voiture créée avec succès." << endl;
    }
    catch (invalid_argument *e)
    {
        std::cerr << "Erreur lors de la création : " << e->what() << '\n';
    }
}

void testVoitureDemarrer()
{
    cout << "=== Test de la méthode demarrer() ===" << endl
         << endl;

    Voiture voitureTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    try
    {
        voitureTest.demarrer();
        cout << "Voiture démarré avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du démarrage : " << e->what() << '\n';
    }

    try
    {
        voitureTest.demarrer();
        cout << "Voiture démarré avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du démarrage : " << e->what() << '\n';
    }

    voitureTest.mettreEnPanne(0.3); // Met en panne légère

    try
    {
        voitureTest.demarrer();
        cout << "Voiture démarré avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du démarrage : " << e->what() << '\n';
    }
}

void testVoitureArreter()
{
    cout << "=== Test de la méthode arreter() ===" << endl
         << endl;

    Voiture voitureTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    voitureTest.demarrer();
    voitureTest.accelerer(50); // Accélération normale

    try
    {
        voitureTest.arreter();
        cout << "Voiture arrêté avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de l'arrêt : " << e->what() << '\n';
    }

    voitureTest.freiner(50); // Freinage normal

    try
    {
        voitureTest.arreter();
        cout << "Voiture arrêté avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de l'arrêt : " << e->what() << '\n';
    }

    try
    {
        voitureTest.arreter();
        cout << "Voiture arrêté avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de l'arrêt : " << e->what() << '\n';
    }
}

void testVoiture()
{
    testVoitureConstruct();
    cout << endl;
    testVoitureDemarrer();
    cout << endl;
    testVoitureArreter();
}

void testBateauConstruct()
{
    cout << "=== Test du constructeur de Bateau ===" << endl
         << endl;

    try
    {
        Bateau bateauTest(350, 6, 0);
        cout << "Bateau tro prapide créée (impossible)." << endl;
    }
    catch (invalid_argument *e)
    {
        std::cerr << "Erreur lors de la création : " << e->what() << '\n';
    }

    try
    {
        Bateau bateauTest(120, 2, 4);
        cout << "Bateau créée avec + de personne que de place (impossible)." << endl;
    }
    catch (invalid_argument *e)
    {
        std::cerr << "Erreur lors de la création : " << e->what() << '\n';
    }

    try
    {
        Bateau bateauTest(120, 5, 4);
        cout << "Bateau créée avec succès." << endl;
    }
    catch (invalid_argument *e)
    {
        std::cerr << "Erreur lors de la création : " << e->what() << '\n';
    }
}

void testBateauDemarrer()
{
    cout << "=== Test de la méthode demarrer() ===" << endl
         << endl;

    Bateau bateauTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    try
    {
        bateauTest.demarrer();
        cout << "Bateau démarré avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du démarrage : " << e->what() << '\n';
    }

    try
    {
        bateauTest.demarrer();
        cout << "Bateau démarré avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du démarrage : " << e->what() << '\n';
    }

    bateauTest.mettreEnPanne(0.3); // Met en panne légère

    try
    {
        bateauTest.demarrer();
        cout << "Bateau démarré avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du démarrage : " << e->what() << '\n';
    }
}

void testBateauArreter()
{
    cout << "=== Test de la méthode arreter() ===" << endl
         << endl;

    Bateau bateauTest(120, 5, 0); // vitesseMax=120, nbPlaces=5, occupants=0

    bateauTest.demarrer();
    bateauTest.accelerer(50); // Accélération normale

    try
    {
        bateauTest.arreter();
        cout << "Bateau arrêté avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de l'arrêt : " << e->what() << '\n';
    }

    bateauTest.freiner(50); // Freinage normal

    try
    {
        bateauTest.arreter();
        cout << "Bateau arrêté avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de l'arrêt : " << e->what() << '\n';
    }

    try
    {
        bateauTest.arreter();
        cout << "Voiture arrêté avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de l'arrêt : " << e->what() << '\n';
    }
}

void testBateau()
{
    testBateauConstruct();
    cout << endl;
    testBateauDemarrer();
    cout << endl;
    testBateauArreter();
}

void testVoitureAmphibieConstruct()
{
    cout << "=== Test du constructeur de VoitureAmphibie ===" << endl
         << endl;

    try
    {
        VoitureAmphibie voitureAmphibieTest(150, 250, 6, 0);
        cout << "Voiture amphibie 6 places créée (impossible - limite voiture)." << endl;
    }
    catch (invalid_argument *e)
    {
        std::cerr << "Erreur lors de la création : " << e->what() << '\n';
    }

    try
    {
        VoitureAmphibie voitureAmphibieTest(150, 350, 4, 0);
        cout << "Voiture amphibie avec bateau trop rapide créée (impossible)." << endl;
    }
    catch (invalid_argument *e)
    {
        std::cerr << "Erreur lors de la création : " << e->what() << '\n';
    }

    try
    {
        VoitureAmphibie voitureAmphibieTest(150, 250, 3, 5);
        cout << "Voiture amphibie avec + de personnes que de places créée (impossible)." << endl;
    }
    catch (invalid_argument *e)
    {
        std::cerr << "Erreur lors de la création : " << e->what() << '\n';
    }

    try
    {
        VoitureAmphibie voitureAmphibieTest(180, 80, 4, 2);
        cout << "Voiture amphibie créée avec succès (180 km/h sur route, 80 km/h sur eau)." << endl;
    }
    catch (invalid_argument *e)
    {
        std::cerr << "Erreur lors de la création : " << e->what() << '\n';
    }
}

void testVoitureAmphibieAfficherAttributs()
{
    cout << "=== Test de la méthode afficherAttributs() ===" << endl
         << endl;

    VoitureAmphibie voitureAmphibieTest(200, 100, 4, 2);

    cout << "Affichage des attributs juste après la création :" << endl;
    voitureAmphibieTest.afficherAttributs();

    cout << "\nDémarrage du mode voiture et accélération..." << endl;
    voitureAmphibieTest.Voiture::demarrer();
    voitureAmphibieTest.Voiture::accelerer(50);

    cout << "Démarrage du mode bateau et accélération..." << endl;
    voitureAmphibieTest.Bateau::demarrer();
    voitureAmphibieTest.Bateau::accelerer(30);

    cout << "\nAffichage des attributs après accélération des deux modes :" << endl;
    voitureAmphibieTest.afficherAttributs();

    cout << "On voit bien que la voiture amphibie possède 2 ensembles d'attributs différents !" << endl;
}

void testVoitureAmphibieDemarrer()
{
    cout << "=== Test de la méthode demarrer() ===" << endl
         << endl;

    VoitureAmphibie voitureAmphibieTest(200, 100, 4, 0);

    try
    {
        voitureAmphibieTest.demarrer();
        cout << "Voiture amphibie démarrée avec succès (démarre les 2 modes)." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du démarrage : " << e->what() << '\n';
    }

    cout << endl;

    try
    {
        voitureAmphibieTest.demarrer();
        cout << "Tentative de redémarrer (devrait échouer car déjà en marche)." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du démarrage : " << e->what() << '\n';
    }

    cout << endl;

    voitureAmphibieTest.Voiture::mettreEnPanne(0.3);
    cout << "Mode voiture mis en panne..." << endl;

    try
    {
        voitureAmphibieTest.demarrer();
        cout << "Tentative de démarrage avec un mode en panne." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors du démarrage : " << e->what() << '\n';
    }
}

void testVoitureAmphibieArreter()
{
    cout << "=== Test de la méthode arreter() ===" << endl
         << endl;

    VoitureAmphibie voitureAmphibieTest(200, 100, 4, 0);

    voitureAmphibieTest.demarrer();
    voitureAmphibieTest.Voiture::accelerer(80);
    voitureAmphibieTest.Bateau::accelerer(50);

    cout << "Voiture amphibie en mouvement (voiture: 80 km/h, bateau: 50 km/h)" << endl;

    try
    {
        voitureAmphibieTest.arreter();
        cout << "Tentative d'arrêt sans freiner (devrait échouer)." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de l'arrêt : " << e->what() << '\n';
    }

    cout << endl;

    voitureAmphibieTest.Voiture::freiner(80);
    voitureAmphibieTest.Bateau::freiner(50);

    cout << "Après freinage complet des deux modes..." << endl;

    try
    {
        voitureAmphibieTest.arreter();
        cout << "Voiture amphibie arrêtée avec succès." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de l'arrêt : " << e->what() << '\n';
    }

    cout << endl;

    try
    {
        voitureAmphibieTest.arreter();
        cout << "Tentative d'arrêt alors qu'elle est déjà arrêtée." << endl;
    }
    catch (runtime_error *e)
    {
        cerr << "Erreur lors de l'arrêt : " << e->what() << '\n';
    }
}

void testVoitureAmphibieModesIndependants()
{
    cout << "=== Test de l'indépendance des modes Voiture et Bateau ===" << endl
         << endl;

    VoitureAmphibie voitureAmphibieTest(200, 100, 4, 2);

    cout << "Démonstration que les deux modes sont indépendants :" << endl
         << endl;

    voitureAmphibieTest.Voiture::demarrer();
    voitureAmphibieTest.Voiture::accelerer(120);

    voitureAmphibieTest.Bateau::demarrer();
    voitureAmphibieTest.Bateau::accelerer(60);

    voitureAmphibieTest.afficherAttributs();

    voitureAmphibieTest.Voiture::freiner(120);
    voitureAmphibieTest.Voiture::arreter();

    voitureAmphibieTest.Bateau::mettreEnPanne(0.7);

    voitureAmphibieTest.afficherAttributs();
}

void testVoitureAmphibie()
{
    testVoitureAmphibieConstruct();
    cout << endl;
    testVoitureAmphibieAfficherAttributs();
    cout << endl;
    testVoitureAmphibieDemarrer();
    cout << endl;
    testVoitureAmphibieArreter();
    cout << endl;
    testVoitureAmphibieModesIndependants();
}

int main()
{
    // testVehicule();
    // testVoiture();
    // testBateau();
    testVoitureAmphibie();
    return 0;
}
