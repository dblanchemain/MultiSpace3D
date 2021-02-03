# MultiSpace3D
MultiSpace3D est un spatialiseur 3D.

Le principe de base est de disposer d’un outil permettant de placer des objets audios statiques ou dynamiques dans l’ espace 3D d’un studio, d’une salle de concert ou de tout autre dispostif haut parlant.

S’il existe de nombreux outils pour Windows et OSX, Linux n’a pas encore vraiment investi ce domaine. Pourtant, l’écriture de l’espace sonore, que ce soit pour une diffusion traditionnelle (concert) ou pour des installations, constitue un champ d’expérimentation extraordinaire.

La <b>documentation</b> se trouve <a href="http://blanchemain.info/Documents/Programmation/index.php?page=multiSpace3D" ><b>ici.</b></a>

<b>Installation du programme</b>

Pour LibraZiK2, vous pouvez charger les binaires ici : <a href="http://blanchemain.info/Documents/Programmation/Programmes/multiSpace3D.tar.gz"  style="text-decoration:none;"  >les binaires ici </a> et décompresser l'archive.
<pre><code>
 
cd multiSpace
sudo make install

multiSpace3D.sh (pour lancer le programme)
</code></pre>
Au premier lancement, il créera un dossier multiSpace3D dans votre espace utilisateur dans lequel vous trouverez les greffons et le fichier de configuration.

Cette application a été testée sous <b>Debian/LibraZiK2.</b>

MultiSpace3D dépend de SFML 2,4, glm 0,9,8, boost, d’OpenGl et de Liblo que vous devez installer si vous ne l’avez pas déjà fait.

Le programme propose 15 greffons pour Ardour et Reaper aux formats Lv2 et VST :
Auro51, Auro71, Auro91, Auro11, Auro13,micadome, M17, Dominium, NHK222, ZKM23, RfStudio, Ircam, Satosphere, Klangdom, dispositifDb64.
Vous pouvez installer ceux qui vous conviennent dans les répertoires correspondants, par exemple ~/.lv2 pour Ardour et ~/.vst pour <strong>Reaper</strong>. <br/>
Sous <strong>Linux</strong>, <strong>Reaper</strong> ne reconnaît que les vst mais vous pouvez utiliser <strong>Carla</strong> pour utiliser les <b>Lv2</b> avec Reaper.
Ces greffons sont indispensables pour le fonctionnement complet de l’application. ils se trouvent dans les dossiers $HOME/multiSpace3D/lv2 et $HOME/multiSpace3D/vst (vst Linux 64bits)
Ils ont été compilés à partir des sources du Grame pour le langage Faust et sont sous licence BSD.
Vous trouverez une archive, rassemblant tous ces greffons, pour <b>Debian/LibraZiK2</b> à <a href="http://blanchemain.info/Documents/Programmation/Programmes/linuxPlugins.tar.gz"  style="text-decoration:none;" title="GNU license"  target="_blank" >cette adresse</a>

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

MultiSpace3D dépend de SFML 2,4, glm 0,9,8, d’OpenGl et de Liblo que vous devez installer si vous ne l’avez pas déjà fait.

Dans un terminal, ouvrez le dossier correspondant et tapez les commandes ;
<pre><code>
git clone https://github.com/dblanchemain/MultiSpace3D
cd MultiSpace3D
make all
sudo make install
</code></pre>
Pour compiler les greffons Lv2 et Vst :
<pre><code>
make lv2 ou make vst

multiSpace3D.sh (pour lancer le programme)
</code></pre>
<p>Pour compiler les greffons au format vst, <strong>Faust</strong> a besoin du <b>SDK de Steinberg</b></p>


Make utilise la commande suivante pour compiler :

<pre><code>
$(CXX)  -std=c++17 -O3 multiSpace3D.cpp -I $(INC) -lstdc++fs -lsfml-graphics -lsfml-window -lsfml-system -llo -lGL -lGLU  -lGL  -DGL_GLEXT_PROTOTYPES  -lpthread `pkg-config --cflags --libs` -o multiSpace3D.bin
</code></pre>

Vous pouvez évidemment modifier le script d’installation s’il ne vous convient pas, mais attention au générateur de script de lancement.

Pour LibraZiK2, vous pouvez télécharger les binaires de tous les greffons ici :<a href="http://blanchemain.info/Documents/Programmation/Programmes/linuxPlugins.tar.gz"  style="text-decoration:none;" title="GNU license"  target="_blank" >http://blanchemain.info/Documents/Programmation/Programmes/linuxPlugins.tar.gz</a>

La compilation sous Windows est identique avec Msys2.

<b>Création d'un nouvel espace de projection</b>

Vous pouvez créer un nouvel espace haut-parlant en utilisant cet utilitaire : spaceCreate.

Vous pourrez ainsi définir l'emplacement de tous les haut-parleurs de votre nouvel espace  et générer le fichier DSP associé. Il est possible de le compiler avec l'utiliataire du <b>Grame</b>, <a href="https://faustide.grame.fr/" > <b>faustIde</b></a>, pour créer des greffons LV2 ou vst ou en utilisant les scripts de <b>Faust</b>.
