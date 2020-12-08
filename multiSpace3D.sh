#! /bin/sh 

dir=$HOME/space3D

if [ -d $HOME/space3D ] ; then 

	echo "Le dossier de travail ($HOME)/space3D existe" 

else 

	mkdir $HOME/space3D 

echo "Le dossier de travail ($HOME)/space3D est créé" 

	cp  /usr/local/share/space3D/preferences.spc $HOME/space3D
	cp -Rf /usr/local/share/space3D/Plugins/ $HOME/space3D
	cp -Rf /usr/local/share/space3D/DSP/ $HOME/space3D/
fi 

/usr/local/bin/multiSpace3D.bin  /usr/local/share/space3D $HOME

