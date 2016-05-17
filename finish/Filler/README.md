# Filler

Créer un joueur pour affronter d’autres étudiants sur le plateau du Filler. Le principe est simple : deux joueurs 
s’affrontent sur un plateau, et doivent placer, tour à tour, la pièce que le maître du jeu (fourni sous la forme d’un exécutable
Ruby) leur donne, gagnant ainsi des points. La partie s’arrête dès qu’une pièce ne peut plus être placée.

La stratégie adopté était la suivante :
* Se rapprocher de l'enemie jusqu'à le toucher.
* Lui bloquer des opportunitées en l'entourant.
  * Favoriser le positionnement qui touche au maximum l'adversaire.
* Remplir le reste de la map une fois l'adversaire bloquer.

les joueurs sont représentés par O et X.

![filler 1](/images/filler1.png)  ![filler 2](/images/filler2.png) ![filler 3](/images/filler3.png)
