#! /bin/sh 

if [ -d $HOME/.config/multiSpace3D ] ; then 

	echo "Le dossier de travail ($HOME)/multiSpace3D existe" 

else 

	mkdir $HOME/.config/multiSpace3D 
	cp  /usr/local/share/multiSpace3D/preferences.spc $HOME/.config/multiSpace3D/

fi 

/usr/local/bin/multiSpace3D.bin  /usr/local/share/multiSpace3D $HOME

