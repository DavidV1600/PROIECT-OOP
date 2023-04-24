#pragma once
#include "Istoric_Jucator.h"
class Istoric_Jucator_Tenis :
    public Istoric_Jucator
{
public:
    void Afiseaza_Adversarii() override;
    void Afiseaza_Progres() override;
    Istoric_Jucator_Tenis(const Istoric_Jucator_Tenis&);
};

