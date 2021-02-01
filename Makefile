LIB ?= /usr/local/lib
INC = ../../architecture

DESTDIR ?=
PREFIX ?= /usr/local

prefix := $(DESTDIR)$(PREFIX)

all: multiSpace3D spaceCreate lv2

spaceCreate: spaceCreate.cpp
	$(CXX)  -std=c++17 -O3 spaceCreate.cpp selectFile.cpp  info.cpp -I $(INC) -lstdc++fs -lsfml-graphics -lsfml-window -lsfml-system -llo -lGL -lGLU  -lGL  -DGL_GLEXT_PROTOTYPES -lboost_system -lboost_filesystem  -lpthread `pkg-config --cflags --libs` -o spaceCreate

multiSpace3D: multiSpace3D.cpp
	$(CXX)  -std=c++17 -O3 multiSpace3D.cpp selectFile.cpp info.cpp -I $(INC) -lstdc++fs -lsfml-graphics -lsfml-window -lsfml-system -llo -lGL -lGLU  -lGL  -DGL_GLEXT_PROTOTYPES -lboost_system -lboost_filesystem  -lpthread `pkg-config --cflags --libs` -o multiSpace3D.bin


lv2:
	./pluginsLv2.sh
	mv ./Plugins/DSP/Auro11.lv2 ./Plugins/Linux
	mv ./Plugins/DSP/Auro13.lv2 ./Plugins/Linux
	mv ./Plugins/DSP/Auro51.lv2 ./Plugins/Linux
	mv ./Plugins/DSP/Auro71.lv2 ./Plugins/Linux
	mv ./Plugins/DSP/Auro91.lv2 ./Plugins/Linux
	mv ./Plugins/DSP/dispositifDb64.lv2 ./Plugins/Linux
	mv ./Plugins/DSP/Dominium.lv2 ./Plugins/Linux
	mv ./Plugins/DSP/Ircam.lv2 ./Plugins/Linux
	mv ./Plugins/DSP/Klangdom.lv2 ./Plugins/Linux
	mv ./Plugins/DSP/M17.lv2 ./Plugins/Linux
	mv ./Plugins/DSP/micadome.lv2 ./Plugins/Linux
	mv ./Plugins/DSP/NHK22.lv2 ./Plugins/Linux
	mv ./Plugins/DSP/RfStudio.lv2 ./Plugins/Linux
	mv ./Plugins/DSP/Satosphere.lv2 ./Plugins/Linux
	mv ./Plugins/DSP/ZKM23.lv2 ./Plugins/Linux
	


install: 
	cp multiSpace3D.bin $(prefix)/bin/
	cp multiSpace3D.sh $(prefix)/bin/
	chmod 755 $(prefix)/bin/multiSpace3D.bin
	chmod 755 $(prefix)/bin/multiSpace3D.sh
	if [ -d "$(prefix)/share/multiSpace3D" ]; then \
    	mkdir $(prefix)/share/multiSpace3D;\
	fi
	
	cp -Rf gui $(prefix)/share/multiSpace3D/gui
	cp -Rf Plugins $(prefix)/share/multiSpace3D/Plugins
	cp -Rf Themes $(prefix)/share/multiSpace3D/Themes
	cp -Rf Lang $(prefix)/share/multiSpace3D/Lang
	cp  preferences.spc $(prefix)/share/multiSpace3D
	cp  spaceCreate $(prefix)/share/multiSpace3D
	chmod 755 $(prefix)/share/multiSpace3D/spaceCreate
    cp pluginsVst.sh $(prefix)/share/multiSpace3D
    chmod 755 $(prefix)/share/multiSpace3D/pluginsVst.sh
    cp pluginsLv2.sh $(prefix)/share/multiSpace3D
    chmod 755 $(prefix)/share/multiSpace3D/pluginsLv2.sh
	

clean:
	rm -f multiSpace3D.bin
	rm -f spaceCreate
	
desinstall :
	rm $(prefix)/bin/multiSpace3D.bin
	rm $(prefix)/bin/multiSpace3D.sh
	rm -r $(prefix)/share/multiSpace3D
	
