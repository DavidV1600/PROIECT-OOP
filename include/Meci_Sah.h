#pragma once
#include "Meci.h"
#include "Jucator_Sah.h"
class Meci_Sah :
    public Meci, public Jucator_Sah
{
public:
   void schimba_Diferenta_Elo_International(Meci&, Jucator_Sah&, Jucator_Sah&);
   void schimba_Diferenta_Elo_National(Meci&, Jucator_Sah &,Jucator_Sah &);
   void schimba_Diferenta_Elo_Online(Meci&, Jucator_Sah &,Jucator_Sah &);
};

