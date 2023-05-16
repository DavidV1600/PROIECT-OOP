#include <iostream>
#include <fstream>
#include "Turneu.h"
#include "Jucator_Sah.h"
#include "Jucator_Tenis.h"
#include "Jucator_Sah_Tenis.h"
#include "Turneu_Sah.h"
#include "Turneu_Tenis.h"
#include "Premiu_Sah.h"
#include "Premiu_Tenis.h"
#include <exception>
#include <stdexcept>
#include <memory>
using namespace std;
ifstream fin("poo.in");
//taskkill /F /IM Proiect-OOP.exe

std::vector<std::shared_ptr<Turneu>>Lista_Turnee_Create;
std::vector<std::shared_ptr<Turneu>>Lista_Turnee_Sah;
std::vector<std::shared_ptr<Turneu>>Lista_Turnee_Tenis;

void Creare_Turneu_Sah();
void Creare_Turneu_Tenis();
void Meniu_Start();
void Afisare_Turnee();
void Afisare_Turnee_Sah();
void Afisare_Turnee_Tenis();
void Editare_Turneu(std::shared_ptr<Turneu>);
void Alegere_Turneu();
void Alegere_Turneu_Sah();
void Alegere_Turneu_Tenis();
void Stergere_Echipa(std::shared_ptr<Turneu>);
void Setare_Premiu_Turneu_Sah(std::shared_ptr<Turneu>) {};///SA SCOT ASTEA

void Meniu_Start() {
    int tasta;
    std::cout << "-----------------------------------------------\n";
    std::cout << "Apasa [1] pentru a creea Turneu de Sah\n";
    std::cout << "Apasa [2] pentru a creea Turneu de Tenis\n";
    std::cout << "Apasa [3] pentru a vedea toate turneele create\n";
    std::cout << "Apasa [4] pentru a vedea toate turneele de sah create\n";
    std::cout << "Apasa [5] pentru a vedea toate turneele de tenis create\n";
    std::cout << "Apasa [6] pentru a edita toate turneele create\n";
    std::cout << "Apasa [7] pentru a edita toate turneele de sah create\n";
    std::cout << "Apasa [8] pentru a edita toate turneele de tenis create\n";
    std::cout << "-----------------------------------------------\n";

    std::cin >> tasta;
    std::cin.get();
    switch (tasta)
    {
    case 1:
        Creare_Turneu_Sah();
        break;
    case 2:
        Creare_Turneu_Tenis();
        break;
    case 3:
        Afisare_Turnee();
        break;
    case 4:
        Afisare_Turnee_Sah();
        break;
    case 5:
        Afisare_Turnee_Tenis();
        break;
    case 6:
        Alegere_Turneu();
        break;
    case 7:
        Alegere_Turneu_Sah();
        break;
    case 8:
        Alegere_Turneu_Tenis();
        break;
    default:
        std::cout << "Introducere invalida!\n\n";
        Meniu_Start();
        break;
    }
}

void Creare_Turneu_Sah()
{
    std::shared_ptr<Turneu>A = std::make_shared<Turneu_Sah>();///Unique Pointer pentru Sah

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
        std::cin >> *A;
        for (int i = 0; i < A->get_nr_Maxim_Echipe(); ++i)
        {
            Echipa b(1);
            std::cin >> b;
            A->add_Echipa(b);
        }
        Lista_Turnee_Create.push_back(A);
        Lista_Turnee_Sah.push_back(A);
        Meniu_Start();
        break;
    default:
        std::cout << "Tasta Invalida!\n\n";
        break;

    }
}
void Creare_Turneu_Tenis()
{
    std::shared_ptr<Turneu>A = std::make_shared<Turneu_Tenis>();
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
        std::cin >> *A;
        for (int i = 0; i < A->get_nr_Maxim_Echipe(); ++i)
        {
            Echipa b(2);
            std::cin >> b;
            A->add_Echipa(b);
        }
        Lista_Turnee_Create.push_back(A);
        Lista_Turnee_Tenis.push_back(A);
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
        std::cout <<"Apasa [" << i + 1 << "] pentru a vizualiza: "<< Lista_Turnee_Create[i]->get_nume_Turneu() << '\n';
    }
    std::cout << "----------------------------------------\n";


    std::cin >> tasta;
    std::cin.get();
    if (tasta == 0)
        Meniu_Start();
    else if (tasta > 0 && tasta <= Lista_Turnee_Create.size())
        std::cout << *Lista_Turnee_Create[tasta-1];///poate o sa fac si afisarea diferita petru turneee sa o fac virtuala pe viitor
    else
        std::cout << "Introducere Invalida!\n\n";
    Afisare_Turnee();
}
void Afisare_Turnee_Sah()
{
    int tasta;
    std::cout << "----------------------------------------\n";
    std::cout << "Apasa [0] pentru a te intoarce\n";
    for (int i = 0; i < Lista_Turnee_Sah.size(); ++i)
    {
        std::cout << "Apasa [" << i + 1 << "] pentru a vizualiza: " << Lista_Turnee_Sah[i]->get_nume_Turneu() << '\n';
    }
    std::cout << "----------------------------------------\n";

    std::cin >> tasta;
    std::cin.get();
    if (tasta == 0)
        Meniu_Start();
    else if (tasta > 0 && tasta <= Lista_Turnee_Sah.size())
        std::cout << *Lista_Turnee_Sah[tasta - 1];///poate o sa fac si afisarea diferita petru turneee sa o fac virtuala pe viitor
    else
        std::cout << "Introducere Invalida!\n\n";
    Afisare_Turnee_Sah();
}
void Afisare_Turnee_Tenis()
{
    int tasta;
    std::cout << "----------------------------------------\n";
    std::cout << "Apasa [0] pentru a te intoarce\n";
    for (int i = 0; i < Lista_Turnee_Tenis.size(); ++i)
    {
        std::cout << "Apasa [" << i + 1 << "] pentru a vizualiza: " << Lista_Turnee_Tenis[i]->get_nume_Turneu() << '\n';
    }
    std::cout << "----------------------------------------\n";

    std::cin >> tasta;
    std::cin.get();
    if (tasta == 0)
        Meniu_Start();
    else if (tasta > 0 && tasta <= Lista_Turnee_Tenis.size())
        std::cout << *Lista_Turnee_Tenis[tasta - 1];///poate o sa fac si afisarea diferita petru turneee sa o fac virtuala pe viitor
    else
        std::cout << "Introducere Invalida!\n\n";
    Afisare_Turnee_Tenis();
}

void Alegere_Turneu()
{
    int tasta;
    std::cout << "-----------------------\n";
    std::cout << "Apasa [0] pentru a te intoarce\n";
    for (int i = 0; i < Lista_Turnee_Create.size(); ++i)
    {
        std::cout << "Apasa [" << i + 1 << "] pentru a edita: " << Lista_Turnee_Create[i]->get_nume_Turneu() << '\n';
    }
    std::cout << "-------------------------\n";

    std::cin >> tasta;
    std::cin.get();
    if (tasta > 0 && tasta <= Lista_Turnee_Create.size())
    {
        //Editare_Turneu(Lista_Turnee_Create[tasta - 1]);
        Lista_Turnee_Create[tasta - 1]->Editare_Turneu();
        Alegere_Turneu();
    }
    else if (tasta == 0)
        Meniu_Start();
    else
    {
        std::cout << "Introducere Invalida!\n\n";
        Alegere_Turneu();
    }
}
void Alegere_Turneu_Sah()
{
    int tasta;
    std::cout << "-----------------------\n";
    std::cout << "Apasa [0] pentru a te intoarce\n";
    for (int i = 0; i < Lista_Turnee_Sah.size(); ++i)
    {
        std::cout << "Apasa [" << i + 1 << "] pentru a edita: " << Lista_Turnee_Sah[i]->get_nume_Turneu() << '\n';
    }
    std::cout << "-------------------------\n";

    std::cin >> tasta;
    std::cin.get();
    if (tasta > 0 && tasta <= Lista_Turnee_Sah.size())
    {
        //Editare_Turneu_Sah(Lista_Turnee_Sah[tasta - 1]);
        Lista_Turnee_Sah[tasta - 1]->Editare_Turneu();
        Alegere_Turneu_Sah();
    }
    else if (tasta == 0)
        Meniu_Start();
    else
    {
        std::cout << "Introducere Invalida!\n\n";
        Alegere_Turneu_Sah();
    }
}
void Alegere_Turneu_Tenis()
{
    int tasta;
    std::cout << "-----------------------\n";
    std::cout << "Apasa [0] pentru a te intoarce\n";
    for (int i = 0; i < Lista_Turnee_Tenis.size(); ++i)
    {
        std::cout << "Apasa [" << i + 1 << "] pentru a edita: " << Lista_Turnee_Tenis[i]->get_nume_Turneu() << '\n';
    }
    std::cout << "-------------------------\n";

    std::cin >> tasta;
    std::cin.get();
    if (tasta > 0 && tasta <= Lista_Turnee_Tenis.size())
    {
        //Editare_Turneu_Tenis(Lista_Turnee_Tenis[tasta - 1]);
        Lista_Turnee_Tenis[tasta - 1]->Editare_Turneu();
        Alegere_Turneu_Tenis();
    }
    else if (tasta == 0)
        Meniu_Start();
    else
    {
        std::cout << "Introducere Invalida!\n\n";
        Alegere_Turneu_Tenis();
    }
}

void Editare_Turneu(std::shared_ptr<Turneu> A)
{
    int tasta;
    std::cout << "--------------------------------------------------------\n";
    std::cout << "Apasa [0] pentru a te intoarce \n";
    std::cout << "Apasa [1] pentru a adauga echipa\n";
    std::cout << "Apasa [2] pentru a sterge echipa\n";
    std::cout << "Apasa [3] schimba numele turneului\n";
    std::cout << "Apasa [4] schimba taxa de participare\n";
    std::cout << "Apasa [5] pentru a schimba premiul total\n";
    std::cout << "Apasa [6] pentru a schimba numarul de echipe admis\n";
    std::cout << "Apasa [7] pentru a schimba numarul de runde\n";
    std::cout << "Apasa [8] pentru a incepe turneul\n";  ///Aci tre sa vad ce fct bag
    std::cout << "---------------------------------------------------------\n";///TRE sa fac cumva sa pot seta premiul per turneu...

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
        A->add_Echipa(b);
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
        A->set_nume_Turneu(nume_nou);
        Editare_Turneu(A);
        break; }
    case 4:
        std::cout << "Introdu taxa de participare noua: ";

        std::cin >> tasta;
        std::cin.get();
        A->set_taxa_Participare(tasta);
        Editare_Turneu(A);
        break;
    case 5:
        std::cout << "Introdu noul premiu total: ";

        std::cin >> tasta;
        std::cin.get();
        A->set_premiu_Total(tasta);
        Editare_Turneu(A);
        break;
    case 6:
        std::cout << "Introdu noul nr maxim de echipe admis: ";

        std::cin >> tasta;
        std::cin.get();
        A->set_nr_Maxim_Echipe(tasta);
        Editare_Turneu(A);
        break;
    case 7:
        std::cout << "Introdu noul nr de runde: ";

        std::cin >> tasta;
        std::cin.get();
        A->set_nr_Runde(tasta);
        Editare_Turneu(A);
        break;
    case 8:
        A->Sortare_Echipe_Inaintea_Rundei();
        A->Incepe_Turneu();
        break;
    case 9:
        Setare_Premiu_Turneu_Sah(A);
        break;
    default:
        std::cout << "Introducere invalida!\n\n";
        Editare_Turneu(A);
        break;
    }
}

void Stergere_Echipa(std::shared_ptr<Turneu> A)
{
    int tasta;
    std::cout << "-----------------------------------------\n";
    std::cout << "Apasa [0] pentru a te intoarce\n";
    for (int i = 0; i < A->get_nr_Echipe_actual(); ++i)
    {
        std::cout << "Apasa [" << i + 1 << "] pentru a sterge echipa: " << A->get_Echipe()[i].get_Nume() << '\n';

    }
    std::cout << "---------------------------------------------\n";

    std::cin >> tasta;
    std::cin.get();
    if (tasta == 0)
        Editare_Turneu(A);
    else if (tasta > 0 && tasta <= A->get_nr_Echipe_actual())
        A->sterge_Echipa(A->get_Echipe()[tasta-1]);
    else
    {
        std::cout << "Introducere Invalida!\n\n";
        Stergere_Echipa(A);
    }

}

/*void Setare_Premiu_Turneu_Sah(std::shared_ptr<Turneu>A)
{
    std::cout << "---------------------------------\n";
    std::cout << "Apasa [0] pentru a te intoarce\n";
    std::cout << "Apasa [1] pentru a seta fondul de premii al turneului\n";
    std::cout << "Apasa [2] pentru a seta numarul de premianti\n";
    std::cout << "Apasa [3] pentru a seta numarul de premi\n";
    std::cout << "Apasa [4] pentru a seta suma per premiu\n";
    std::cout << "Apasa [5] pentru a seta procentajul din suma totala per premiu\n";
    std::cout << "------------------------------------\n";
    int tasta;
    switch (tasta)
    {
    case 0:
        Editare_Turneu_Sah(A);
        break;
    case 1:
        std::cout << "Introdu fondul de premii total: ";
        std::cin >> tasta;
        std::cin.get();
        A->set_premiu_Total(tasta);
        break;
    case 2:
        std::shared_ptr<Turneu_Sah*> A_Sah= std::dynamic_pointer_cast<Turneu_Sah*>(A);
        A_Sah->get_Premiu_Sah()->set_nr_Premii(tasta);
    default:
        std::cout << "Tasta invalida mai incercati!\n";
        Setare_Premiu_Turneu_Sah(A);
        break;
    }
}*/

int main()
{
    Meniu_Start();
    //std::unique_ptr<Premiu>G = std::make_unique<Premiu_Sah>();///Unique Pointer
    /*Turneu T;
    T.set_nr_Maxim_Echipe(2);
    Echipa A;
    Echipa B;
    Jucator a1("23", "a1");
    Jucator a2("24", "a2");
    Jucator a3("25", "a3");
    Jucator a4("35", "a4");
    A.Add_Membru(a1);
    A.Add_Membru(a2);
    A.Add_Membru(a3);
    B.Add_Membru(a4);
    B.Add_Membru(a2);
    A.Gaseste_Pozitia_In_Echipa(a1);
    cout << A;
    A.Inverseaza_Ordinea_Jucatorilor();
    cout << A;
    A.Gaseste_Pozitia_In_Echipa(a4);
    T.add_Echipa(A);
    T.add_Echipa(B);
    T.Gasire_Echipa(B);
    */
    return 0;
}
