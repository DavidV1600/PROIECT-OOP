#pragma once
#include "Istoric_Jucator.h"
#include "Jucator_Tenis.h"
class Istoric_Jucator_Tenis :
    public Istoric_Jucator<Jucator_Tenis>
{
public:
    void Afiseaza_Adversarii() override;
    void Afiseaza_Progres() override;
    Istoric_Jucator_Tenis(const Istoric_Jucator_Tenis&);
};

