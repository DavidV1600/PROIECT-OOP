# Proiect-OOP
 
## Aplicatie de creat Competitii Sportive

## Clase implementate:

### Jucator, Jucator_Sah, Jucator_Tenis, Jucator_Sah_Tenis:
Reprezinta un om, membru al unei echipe si retine datele acestuia(cnp,nume,prenume,etc);

Este capabila sa citeasca datele unui Jucator si sa le afiseze;
### Echipa:
Reprezinta o echipa, formata din mai multi jucatorii are ca date membre(numele echipei,jucatorii,elo-ul echipei,numarul de jucatorii);

Este capabila sa citeasca o echipa si membri acesteia, sa calculeze media elo a jucatoriilor ei, aceasta fiind elo-ul echipei si sa le afiseze;

### Meci, Meci_Sah, Meci_Tenis:
Reprezinta un meci, disputat intre 2 echipe cu un scor si un rezultat final care decide castigatorul;

Este capabila sa afiseze scorul celor doua echipe si castigatorul meciului;

### Runda:
Este o runda a turneului, formata dintr-o lista de meciuri, retinand numarul rundei actuale si al meciurilor disputate;

Este capabila sa afiseze o lista cu toate meciurile jucate si cu rezultatele acestora;

### Turneu, Turneu_Sah, Turneu_Tenis:
Este clasa principala, cu mostenitoarele ei, care este formata dintr-o lista de echipe participante, o lista de runde, numarul acestora, o taxa de inscriere per echipa, numele turneului si fondul de premii;

Este capabila sa citeasca toate echipele participante la turneu si restul datelor membre ale clasei, sa le afiseze;

### Istoric_Jucator, Istoric_Jucator_Sah, Istoric_Jucator_Tenis:
Este capabila sa retina istoric de elo al unui jucator, sau de clasament ATP in functie de tipul jucatorului, si sa retina adversarii acestuia

### Premiu, Premiu_Sah, Premiu_Tenis:
Este interfata responsabila de premii, cu mostenitoarele ei, care retin cate premii se acorda la turneu, cati oamenii au primit premii si o lista cu toate premiile date

### Exceptie_Custom:
Este o clasa care mosteneste clasa exception si care ii suprascrie functia what(), pentru a afisa un mesaj personalizat

