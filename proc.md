## DIFFERENCE ENTRE LES CPU CISC & RISC

|                        | RISC                                                             |    CISC                                           |
|------------------------|------------------------------------------------------------------|-------------------------------------------------|
|**Acronyme**            | ordinateur à jeu d'instructions réduit                            |complexe instruction set computer                |
|**Définition**          | ensemble d'instructions plus petit avec peu de nœuds d'adressage  |ensemble d’instructions plus important comprenant de nombreux nœuds d’adressage |
|**Unité de mémoire**      | pas de mémoire, matérielle séparer pour les instructions       | mémoire pour implémenter les instructions |
|**Programme**            | il a une unité de programmation câblée                           | il a une unité de micro-programmation  |
|**Conception**           | design complexe complier | design facile à remplir |
|**Décodage**             | décodage des instructions est simple | décodage des instructions est complexe |
|**Calculs**              | plus rapides et précis | calculs sont lents et précis |
|**Temps**                | le temps d'exécution est très inférieur | Le temps d'exécution est très élevé |
|**Mémoire externe**      | ne nécessite pas de mémoire externe pour les calculs | nécessite de la mémoire externe pour les calculs |
|**Pipelining**           | fonctionne correctement | ne fonctionne pas correctement |
|**Espace disque**        | l'espace est enregistré | l'espace est gaspillé |
| **Application**         | utilisé dans les applications haut de gamme telles que le traitement vidéo, les télécommunications et le traitement d'images | Utilisé dans les applications bas de gamme telles que les systèmes de sécurité, les automatisations domestiques, etc |

## DIFFERENCE ENTRE LES ARCHITECTURES DE HARVARD & VON NEUMANN

### 1. Von Neumann

Un microcontrolleur basé sur une structure Von Neuman (1) stocke les programmes et les données dans la même zone mémoire. Une instruction contient le code opératoire et l’adresse de l’opérande. 

### 2. Harvard

Cette structure se distingue de l’architecture Von Neuman uniquement par le fait que les mémoires programmes et données sont séparées. L’accès à chacune des deux mémoires se fait via un chemin distinct. Cette organisation permet de transférer une instruction et des données simultanément, ce qui améliore les performances.

|                            | Architecture  Harvard  | Architecture de von Neumann  |
|----------------------------|-----------------------|------------------------------|
| Arrangement                | CPU est connecté à la fois à la mémoire de données (RAM) et à la mémoire de programme (ROM) |  il n'y a pas de mémoire de données et de programme séparée. Au lieu de cela, une seule connexion mémoire est donnée au CPU |   
| Configuration matérielle   | nécessite plus de matériel car il nécessitera des données et un bus d'adresses distincts pour chaque mémoire | Contrairement à l'architecture Harvard, cela nécessite moins de matériel car seule une mémoire commune doit être atteinte |   
| Espace requis              | Cela nécessite plus d'espace | L'architecture Von-Neumann nécessite moins d'espace |
| Rapidité d'exécution | La vitesse d'exécution est plus rapide car le processeur récupère simultanément les données et les instructions | La vitesse d'exécution est plus lente car il ne peut pas récupérer les données et les instructions en même temps |
| Utilisation de l'espace | Il en résulte un gaspillage d'espace car s'il reste de l'espace dans la mémoire de données, la mémoire d'instructions ne peut pas utiliser l'espace de la mémoire de données et vice-versa | L'espace n'est pas gaspillé car l'espace de la mémoire de données peut être utilisé par la mémoire d'instructions et vice-versa |
