#pragma once
#include "Istoric_Jucator.h"
#include "Jucator_Sah.h"
class Istoric_Jucator_Sah :
    public Istoric_Jucator<Jucator_Sah>
{
public:
    void Afiseaza_Adversarii() override;
    void Afiseaza_Progres() override;
    Istoric_Jucator_Sah(const Istoric_Jucator_Sah&);
};

