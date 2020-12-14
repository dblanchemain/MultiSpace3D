LIB ?= /usr/local/lib
INC = ../../architecture

DESTDIR ?=
PREFIX ?= /usr/local

prefix := $(DESTDIR)$(PREFIX)

all: multiSpace3D spaceCreate

spaceCreate: spaceCreate.cpp
	$(CXX)  -std=c++17 -O3 spaceCreate.cpp -I $(INC) -lstdc++fs -lsfml-graphics -lsfml-window -lsfml-system -llo -lGL -lGLU  -lGL  -DGL_GLEXT_PROTOTYPES  -lpthread `pkg-config --cflags --libs` -o spaceCreate

multiSpace3D: multiSpace3D.cpp
	$(CXX)  -std=c++17 -O3 multiSpace3D.cpp -I $(INC) -lstdc++fs -lsfml-graphics -lsfml-window -lsfml-system -llo -lGL -lGLU  -lGL  -DGL_GLEXT_PROTOTYPES  -lpthread `pkg-config --cflags --libs` -o multiSpace3D.bin



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
	cp  preferences.spc $(prefix)/share/multiSpace3D
	cp  spaceCreate $(prefix)/share/multiSpace3D
	chmod 755 $(prefix)/share/space3D/spaceCreate

clean:
	rm -f multiSpace3D.bin
	rm -f spaceCreate
	
desinstall :
	rm $(prefix)/bin/multiSpace3D.bin
	rm $(prefix)/bin/multiSpace3D.sh
	rm -r $(prefix)/share/space3D
	
