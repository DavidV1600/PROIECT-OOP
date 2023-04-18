#include <iostream>
#include <fstream>
#include "Turneu.h"
#include "Jucator_Sah.h"
#include "Jucator_Tenis.h"
#include "Turneu_Sah.h"
#include "Premiu_Sah.h"
#include "Premiu_Tenis.h"
#include <exception>
#include <stdexcept>
using namespace std;
ifstream fin("poo.in");
//taskkill /F /IM Proiect-OOP.exe

std::vector<Turneu>Lista_Turnee_Create;

void Creare_Turneu();
void Meniu_Start();
void Afisare_Turnee();
void Editare_Turneu(Turneu&);
void Alegere_Turneu();
void Stergere_Echipa(Turneu&);

void Meniu_Start() {
    int tasta;
    std::cout << "-----------------------------------------------\n";
    std::cout << "Apasa [1] pentru a creea Turneu\n";
    std::cout << "Apasa [2] pentru a vedea turneele create\n";
    std::cout << "Apasa [3] pentru a edita turneele create\n";
    std::cout << "-----------------------------------------------\n";
    std::cin >> tasta;
    std::cin.get();
    switch (tasta)
    {
    case 1:
        Creare_Turneu();
        break;
    case 2:
        Afisare_Turnee();
        break;
    case 3:
        Alegere_Turneu();
        break;
    default:
        std::cout << "Introducere invalida!\n\n";
        Meniu_Start();
        break;
    }
}

void Creare_Turneu()
{
    Turneu A;
    int tasta;
    std::cout << "-------------------------------------------------\n";
    std::cout << "Apasa [0] pentru a te intoarce\n";
    std::cout << "Apasa [1] pentru a incepe sa introduci datele turneului\n";
    std::cout << "-------------------------------------------------\n";
    std::cin >> tasta;
    std::cin.get();
    switch (tasta)
    {
    case 0:
        Meniu_Start();
        break;
    case 1:
        std::cin >> A;
        for (int i = 0; i < A.get_nr_Maxim_Echipe(); ++i)
        {
            Echipa b;
            std::cin >> b;
            A.add_Echipa(b);
        }
        Lista_Turnee_Create.push_back(A);
        Meniu_Start();
            break;
    default:
        std::cout << "Tasta Invalida!\n\n";
        break;

    }
}

void Afisare_Turnee()
{
    int tasta;
    std::cout << "----------------------------------------\n";
    std::cout << "Apasa [0] pentru a te intoarce\n";
    for (int i = 0; i < Lista_Turnee_Create.size(); ++i)
    {
        std::cout <<"Apasa [" << i + 1 << "] pentru a vizualiza: "<< Lista_Turnee_Create[i].get_nume_Turneu() << '\n';
    }
    std::cout << "----------------------------------------\n";
    std::cin >> tasta;
    std::cin.get();
    if (tasta == 0)
        Meniu_Start();
    else if (tasta > 0 && tasta <= Lista_Turnee_Create.size())
        std::cout << Lista_Turnee_Create[tasta-1];
    else
        std::cout << "Introducere Invalida!\n\n";
    Afisare_Turnee();
}

void Alegere_Turneu()
{
    int tasta;
    std::cout << "-----------------------\n";
    std::cout << "Apasa [0] pentru a te intoarce\n";
    for (int i = 0; i < Lista_Turnee_Create.size(); ++i)
    {
        std::cout << "Apasa [" << i + 1 << "] pentru a edita: " << Lista_Turnee_Create[i].get_nume_Turneu() << '\n';
    }
    std::cout << "-------------------------\n";
    std::cin >> tasta;
    std::cin.get();
    if (tasta > 0 && tasta <= Lista_Turnee_Create.size())
    {
        Editare_Turneu(Lista_Turnee_Create[tasta - 1]);
    }
    else if (tasta == 0)
        Meniu_Start();
    else
    {
        std::cout << "Introducere Invalida!\n\n";
        Alegere_Turneu();
    }
}

void Editare_Turneu(Turneu& A)
{
    int tasta;
    std::cout << "--------------------------------------------------------\n";
    std::cout << "Apasa [0] pentur a te intoarce \n";
    std::cout << "Apasa [1] pentru a adauga echipa\n";
    std::cout << "Apasa [2] pentru a sterge echipa\n";
    std::cout << "Apasa [3] schimba numele turneului\n";
    std::cout << "Apasa [4] schimba taxa de participare\n";
    std::cout << "Apasa [5] pentru a schimba premiul total\n";
    std::cout << "Apasa [6] pentru a schimba numarul de echipe admis\n";
    std::cout << "Apasa [7] pentru a schimba numarul de runde\n";
    std::cout << "---------------------------------------------------------\n";
    std::cin >> tasta;
    std::cin.get();

    switch (tasta)
    {
    case 0:
        Alegere_Turneu();
        break;
    case 1: {
        Echipa b;
        std::cin >> b;
        A.add_Echipa(b);
        Editare_Turneu(A);
        break;
    }
    case 2: {
        Stergere_Echipa(A);///Aci trebe functie
        Editare_Turneu(A);
        break;
    }
          break;
    case 3: {
        char nume_nou[30];
        std::cout << "Introdu numele nou: ";
        std::cin >> nume_nou;
        A.set_nume_Turneu(nume_nou);
        Editare_Turneu(A);
        break; }
    case 4:
        std::cout << "Introdu taxa de participare noua: ";
        std::cin >> tasta;
        std::cin.get();
        A.set_taxa_Participare(tasta);
        Editare_Turneu(A);
        break;
    case 5:
        std::cout << "Introdu noul premiu total: ";
        std::cin >> tasta;
        std::cin.get();
        A.set_premiu_Total(tasta);
        Editare_Turneu(A);
        break;
    case 6:
        std::cout << "Introdu noul nr maxim de echipe admis: ";
        std::cin >> tasta;
        std::cin.get();
        A.set_nr_Maxim_Echipe(tasta);
        Editare_Turneu(A);
        break;
    case 7:
        std::cout << "Introdu noul nr de runde: ";
        std::cin >> tasta;
        std::cin.get();
        A.set_nr_Runde(tasta);
        Editare_Turneu(A);
        break;
    default:
        std::cout << "Introducere invalida!\n\n";
        Editare_Turneu(A);
        break;
    }
}

void Stergere_Echipa(Turneu& A)
{
    int tasta;
    std::cout << "-----------------------------------------\n";
    std::cout << "Apasa [0] pentru a te intoarce\n";
    for (int i = 0; i < A.get_nr_Echipe_actual(); ++i)
    {
        std::cout << "Apasa [" << i + 1 << "] pentru a sterge echipa: " << A.get_Echipe()[i].get_Nume() << '\n';

    }
    std::cout << "---------------------------------------------\n";
    std::cin >> tasta;
    std::cin.get();
    if (tasta == 0)
        Editare_Turneu(A);
    else if (tasta > 0 && tasta <= A.get_nr_Echipe_actual())
        A.sterge_Echipa(A.get_Echipe()[tasta-1]);
    else
    {
        std::cout << "Introducere Invalida!\n\n";
        Stergere_Echipa(A);
    }

}

int main()
{
    Meniu_Start();
    /*Turneu T;
    cin >> T;                         ///Citesc turneu
    int nr_Echipe;
    int nr_Jucatori;
    cout << "Introdu Numar Echipe: ";
    cin >> nr_Echipe;
    nr_Echipe = min(T.get_nr_Maxim_Echipe(), nr_Echipe);
    cin.get();
    for (int i = 1; i <= nr_Echipe; ++i)
    {
        Echipa e;
        e.Citire_Nume_Echipa();
        cout << "Introdu Numar Jucatori Echipa " << e.get_Nume() << ": ";
        cin >> nr_Jucatori;
        for (int j = 1; j <= nr_Jucatori; ++j)
        {
            cout << "Introdu datele jucatorului " << j << " din echipa " << e.get_Nume() << ":\n";
            Jucator a;
            cin.get();
            cin >> a;
            e.Add_Membru(a);
        }
        cin.get();
        T.add_Echipa(e);

    }
    T.Incepe_Turneu();
    */
    /*
        Jucator a("07434983","Sper","Ghita",10,false,2058);
        Jucator b("38749993","FierSper","Lucian",13,true,1895);
        Jucator c("293849843","Ler","Mihai",15,true,3895);
        Jucator d("293849843","FierMer","Andrei",15,false,1235);
        Echipa sper,fier,ler,mer;
        sper.Add_Membru(a);
        fier.Add_Membru(b);
        ler.Add_Membru(c);
        mer.Add_Membru(d);
        sper.Add_Membru(b);
        fier.Add_Membru(d);
        sper.set_Nume("Echipa sper");
        fier.set_Nume("Echipa fier");
        ler.set_Nume("Echipa ler");
        mer.set_Nume("Echipa mer");
        Turneu t1;
        t1.add_Echipa(sper);
        t1.add_Echipa(fier);
        t1.add_Echipa(ler);
        t1.add_Echipa(mer);
        t1.set_nr_Runde(2);
        t1.Incepe_Turneu();
    */
    return 0;
}
