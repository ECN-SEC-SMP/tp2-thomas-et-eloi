/**
 * @file Voiture.hpp
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

class Voiture : public Vehicule
{
public:
    Voiture(int vitesseMax = 0, int nbPlaces = 1, int occupants = 0);

    virtual void demarrer();

    virtual void arreter();

    virtual ~Voiture();
};