/**
 * @file Bateau.hpp
 * @author Eloi Tourangin (eloi.tourangin@eleves.ec-nantes.fr) & Thomas Verron (thomas.verron@eleves.ec-nantes.fr)
 * @brief 
 * @version 0.1
 * @date 14-10-2025
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Vehicule.hpp"

class Bateau : public Vehicule
{
public:
    Bateau(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0);

    virtual void demarrer();

    virtual void arreter();

    virtual ~Bateau();
};