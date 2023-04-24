#pragma once
#include "Istoric_Jucator.h"
class Istoric_Jucator_Sah :
    public Istoric_Jucator
{
public:
    void Afiseaza_Adversarii() override;
    void Afiseaza_Progres() override;
    Istoric_Jucator_Sah(const Istoric_Jucator_Sah&);
};

