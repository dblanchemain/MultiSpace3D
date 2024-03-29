# MultiSpace3D
MultiSpace3D est un spatialiseur 3D.

Le principe de base est de disposer d’un outil permettant de placer des objets audios statiques ou dynamiques dans l’ espace 3D d’un studio, d’une salle de concert ou de tout autre dispostif haut parlant.

S’il existe de nombreux outils pour Windows et OSX, Linux n’a pas encore vraiment investi ce domaine. Pourtant, l’écriture de l’espace sonore, que ce soit pour une diffusion traditionnelle (concert) ou pour des installations, constitue un champ d’expérimentation extraordinaire.

La <b>documentation</b> se trouve <a href="http://blanchemain.info/Documents/Programmation/index.php?page=multiSpace3D" ><b>ici.</b></a>

<b>Installation du programme</b>

<pre><code>
 
cd multiSpace
sudo make install

multiSpace3D.sh (pour lancer le programme)
</code></pre>

Cette application a été testée sous <b>Debian/LibraZiK2.</b>

MultiSpace3D dépend de SFML 2,4, glm 0.9.8, boost, d’OpenGl et de Liblo que vous devez installer si vous ne l’avez pas déjà fait.

Le programme propose 17 greffons pour Ardour et Reaper aux formats Lv2 et VST :
Auro51, Auro71, Auro91, Auro11, Auro13,micadome, M17, Dominium, NHK222, ZKM23, RfStudio, Ircam, Satosphere, Klangdom,4D sound (48), 4D sound(57) MONOM, dispositifDb64.
Vous pouvez installer ceux qui vous conviennent dans les répertoires correspondants, par exemple ~/.lv2  <br/>
Vous pouvez maintenant utiliser  <strong>Carla</strong>.
Ces greffons sont indispensables pour le fonctionnement complet de l’application. ils se trouvent dans les dossiers $HOME/<dossier github>/multiSpace3D/lv2.

    multiSpace3D.bin constitue l'application proprement dite.
    multiSpace3D.sh est un script de lancement du programme. Vous pouvez l'utiliser pour un lanceur sur le bureau sans avoir besoin d'un terminal.
    Le dossier gui renferme les images nécessaires au fonctionnement de l'application.
    Le dossier Plugins renferme les greffons nécessaires au fonctionnement de l'application.
    Le dossier Plugins/DSP renferme les fichiers de configurations des espaces hauts-parlants et des DSP correspondants.
    Le dossier Plugins/Linux ou Windows renferme les greffons proprement dits.

Les modèles ne sont pas installés automatiquement.

Le script multiSpace3D.sh suppose que le programme est bien installé en /usr/local. Ce script est indispensable, car il transmet des informations de configuration au programme.

<b>Compilation</b>

Avant de compiler, vous devez disposer d’un environnement de développement complet.

MultiSpace3D dépend de SFML 2,4, glm 0.9.8, boost, d’OpenGl et de Liblo que vous devez installer si vous ne l’avez pas déjà fait.

Dans un terminal, ouvrez le dossier correspondant et tapez les commandes ;
<pre><code>
git clone https://github.com/dblanchemain/MultiSpace3D
cd MultiSpace3D
make all
sudo make install
</code></pre>
<pre><code>
multiSpace3D.sh (pour lancer le programme)
</code></pre>

Vous pouvez évidemment modifier le script d’installation s’il ne vous convient pas, mais attention au générateur de script de lancement.

La compilation sous Windows est identique avec Msys2.

<b>Création d'un nouvel espace de projection</b>

Vous pouvez créer un nouvel espace haut-parlant en utilisant cet utilitaire : spaceCreate.

Vous pourrez ainsi définir l'emplacement de tous les haut-parleurs de votre nouvel espace  et générer le fichier DSP associé. Il est possible de le compiler avec l'utiliataire du <b>Grame</b>, <a href="https://faustide.grame.fr/" > <b>faustIde</b></a>, pour créer des greffons LV2 ou vst ou en utilisant les scripts de <b>Faust</b>.
