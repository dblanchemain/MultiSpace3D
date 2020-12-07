LIB ?= /usr/local/lib
INC = ../../architecture

DESTDIR ?=
PREFIX ?= /usr/local

prefix := $(DESTDIR)$(PREFIX)

all: space3D spaceCreate

spaceCreate: spaceCreate.cpp
	$(CXX)  -std=c++17 -O3 spaceCreate.cpp -I $(INC) -lstdc++fs -lsfml-graphics -lsfml-window -lsfml-system -llo -lGL -lGLU  -lGL  -DGL_GLEXT_PROTOTYPES  -lpthread `pkg-config --cflags --libs` -o spaceCreate

space3D: space3D.cpp
	$(CXX)  -std=c++17 -O3 space3D.cpp -I $(INC) -lstdc++fs -lsfml-graphics -lsfml-window -lsfml-system -llo -lGL -lGLU  -lGL  -DGL_GLEXT_PROTOTYPES  -lpthread `pkg-config --cflags --libs` -o space3D.bin



install: 
	cp space3D.bin $(prefix)/bin
	cp space3D.sh $(prefix)/bin/space3D.sh
	chmod 755 $(prefix)/bin/space3D.bin
	chmod 755 $(prefix)/bin/space3D.sh
	if [ -d "$(prefix)/share/space3D" ]; \
    	mkdir $(prefix)/share/space3D;\
	fi
	
	cp -Rf gui $(prefix)/share/space3D/gui
	cp -Rf Plugins $(prefix)/share/space3D/Plugins
	cp  preferences.spc $(prefix)/share/space3D
	cp  spaceCreate $(prefix)/share/space3D
	chmod 755 $(prefix)/share/space3D/spaceCreate

clean:
	rm -f space3D.bin
	rm -f spaceCreate
	
desinstall :
	rm $(prefix)/bin/space3D.bin
	rm $(prefix)/bin/space3D.sh
	rm -r $(prefix)/share/space3D
	
