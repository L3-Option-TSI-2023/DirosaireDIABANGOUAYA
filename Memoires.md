# TOUT SUR LES MEMOIRES 

On appelle mémoire tout dispositif permettant de stocker des informations.
De façon générale, une mémoire est constituée :
- Un **Bus d'adresses** (n)
- Un **Bus de données** (m)
- Et deux **broches**, une pour l'écriture et la lecture et une autre broche pour la selection.

Il existe de nombreux types ou fromats de mémoires qui se distinguent chacune par leurs caractéristiques :
- la technologie (ROM, RAM, Flash, FIFO, etc)
- l'organisation interne : le nombre de cases mémoires N=2^n avec n le nombre de bits d'adresses (n), et le nombre des données 
- la capacité C=mx2^n
- le temps d'accès en ns

On dsitingue 2 grands types de mémoires : les vives et les mortes.

### Les mémoires vives ou RAM (Random Access Memory)

Ce sont des mémoires qui perdent leur contenu sans alimentation. Il en existe deux types 
- Les SRAM pour RAM Statique
- et les DRAM pour RAM dynamique 

Les différences entre ces deux types de mémoires vives sont résumés dans le tableau suivant :

|                              |     SRAM                      |    DRAM                          |
| :--------------------------- | :---------------------------: | :-------------------------------:|
| Technologie de stockage      |     Latch                     |   1e capacité                    |
| Raffraichissement            |   Non                         |      Oui                         |
| Vitesse                      |     plutot élevé (qq ns)      |    plutot lente (diz de ns)      |
| Densité(bit/mm^2)            |     moins dense que le DRAM   |         la plus élevée           |
| Capacité                     |     faible (qq Mo)            |         élevée  (qq Go)          |
| Consommation                 |Proportionnelle à la fréquence |         élevée car refresh       |
| Prix                         |     2500 euros/Gb             |         250 euros/Gb             |


### Les mémoires mortes ou ROM (Read Only Memory)

