#! /bin/sh 

dir=$HOME/multiSpace3D

if [ -d $HOME/multiSpace3D ] ; then 

	echo "Le dossier de travail ($HOME)/multiSpace3D existe" 

else 

	mkdir $HOME/multiSpace3D 

echo "Le dossier de travail ($HOME)/multiSpace3D est créé" 

	cp  /usr/local/share/multiSpace3D/preferences.spc $HOME/multiSpace3D
	cp -Rf /usr/local/share/multiSpace3D/Plugins/ $HOME/multiSpace3D
	cp -Rf /usr/local/share/multiSpace3D/DSP/ $HOME/multiSpace3D/
fi 

/usr/local/bin/multiSpace3D.bin  /usr/local/share/multiSpace3D $HOME

