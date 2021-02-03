#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <stdlib.h>
#include <vector>

#include <GL/gl.h>
#include <GL/glu.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "selectFile.h"

sf::RenderWindow winPrincipale(sf::VideoMode(810,846), "Vue de dessus");
sf::RenderWindow winInput;

sf::RenderWindow winSelectGrp;
sf::RenderWindow winParam;
sf::RenderWindow win3D;
sf::ContextSettings settings;

std::string defGui;
std::string defInstall;
std::string home;
std::string pref;
sf::RectangleShape menuBar;
sf::RectangleShape verticalBar;
sf::RectangleShape horizontalBar;
sf::RectangleShape vBar1;
sf::RectangleShape hBar1;
sf::RectangleShape vBar2;
sf::RectangleShape hBar2;

sf::RectangleShape bkgToolType;

std::wstring tip[20];

selectFile fileSelector; 
std::string nameFile;


sf::Font font;

float scaleWidth;
float scaleHeight;
sf::Texture imageF1;
sf::Texture imageF2;
sf::Texture imageF3;
sf::Texture imageF4;
sf::Texture imageF5;
sf::Texture imageF6;
sf::Texture imageF7;
sf::Texture imageF8;
sf::Texture imageF9;
sf::Texture imageF10;
sf::Texture imageF11;
sf::Texture imageF12;
sf::Texture imageF13;
sf::Texture imageF14;
sf::Texture imageF15;
sf::Texture imageF16;
sf::Texture imageF17;
sf::Texture imageF18;
sf::Texture imageF19;
sf::Texture imageF20;
sf::Texture imageF21;
sf::Texture imageF22;
sf::Texture imageF23;
sf::Texture imageF24;
sf::Texture imageF25;
sf::Texture imageF26;
sf::Texture imageF27;
sf::Texture imageF28;
sf::Texture imageF29;

sf::Sprite spaceNew;
sf::Texture grille3d;
sf::Texture repere;
sf::Texture repere2;
sf::Sprite teteDessus;
sf::Sprite teteDroite;
sf::Sprite teteDos;
sf::Sprite virtual3D;
sf::Sprite preferences;
sf::Sprite param;
sf::Sprite selectGroupe;
sf::Sprite trash;
sf::Sprite trash2;
sf::Sprite trash3;
sf::Sprite mv1;
sf::Sprite mv2;
sf::Sprite mv3;
sf::Sprite expansion;
sf::Sprite contraction;
sf::Sprite roty;
sf::Sprite rotx;
sf::Sprite rotz;
sf::Sprite winD;
sf::Sprite winA;
sf::Sprite winR;
sf::Sprite winI3D;
sf::Sprite repere3D;
sf::Sprite repere2D;
sf::Sprite validSp;
sf::Sprite  tabSprite[32];
sf::Texture  tabTexture[32];
sf::CircleShape confDaw1;
sf::CircleShape selectMixer;
sf::Sprite openFile;
sf::Sprite file;
sf::Sprite floppy;
sf::Sprite fileok;
sf::Sprite fileAnnul;
struct speaker{			// Structure pour les enceintes  sweetspot
		int num;
	   float x;            // x
	   float y;            //y
	   float z;            //y
	   float dim;
	 };
speaker tabSpeaker[64];
struct entree{				// Structure des objets 3D
		int input;
	   int groupe;       // groupe
	   int track;
	   int flagTrack;
	   float x;            // x
	   float y;            //y
	   float z;            //y
	   float r;
	   float scale;
	   sf::Sprite spriteD;
	   sf::Sprite spriteR;
	   sf::Sprite spriteA;
	   sf::Sprite sprite3D;
	 };
int defautGroupe;
int defautTrack;
float defautR;
std::vector<entree> tabEntree;

bool flagFileMode;

void onEventResized(sf::Event e);
void mouseWheel(sf::Event e);
void onKeyPressed(sf::Event e);
void onClick(sf::Event e);
void onMouseUp(sf::Event e);
void onMouseMove(sf::Event e);

sf::Text defServeur;
sf::Text defPort;
sf::Text dTrack;
int defTrack;

sf::Text toolType;

void onResizedParam(sf::Event e);
void onClickParam(sf::Event e);
void validerParam();
void onMouseMoveParam(sf::Event e);
void newParamText(sf::Event e);
void readParam();

void nSelectMixer();
void refInput(sf::Event e);

void newInstanceSpace();
void saveSpace();
void openSpace();
//*****************************************************************************************************************
//																Fenêtre Input
//*****************************************************************************************************************
sf::Text labelInput;
sf::Text labelTrack;
sf::Text labelType;
sf::Text labelScale;
sf::Text labelGroupe;

sf::Text carla;

sf::Texture inpt;
sf::Texture bNoSelect;
sf::Texture bselect;
sf::Texture selectC;
sf::Texture inpbar1;
sf::Sprite inpInput;
sf::Sprite inpTrack;
sf::Sprite inpScale;
sf::Sprite inpSelect;
sf::Sprite inpGroupe;
sf::Sprite selectGrp;
sf::Text inpText;
sf::Text trackText;
sf::Text scaleText;
sf::Text inpBarText;
sf::Text trackBarText;
sf::Text labelInpBarText;
sf::Text labelTrackBarText;
sf::Sprite inpBarTrack;
sf::Sprite inpBarInput;
int inpIndex;
bool flagTxt;
std::string apptxt;

sf::RectangleShape winInpCurseur;
bool flagInpCurseur;
sf::Clock clockCurseur;

void onClickInput(sf::Event e);
void onClickSelectGrp(sf::Event e);
void newInputText(sf::Event e);

sf::Text labelInputFile;
sf::Text inpTextFile;

//*****************************************************************************************************************
//																Fenêtre 3D
//*****************************************************************************************************************
float w3WxScale;
float w3HyScale;
float rxquad;
float ryquad;
float rzquad;
float Theta;
float Phi;
float tx;
float ty;
float pTheta;				// Rotation 
float pPhi;
int drawWine3D;
GLUquadricObj *quadratic;
float oldX;
float oldY;
float sTx;
float sTy;

void init3D();
void drawCube(GLfloat s,GLfloat e,GLfloat e2);
void drawMur(float echX, float echY);
void drawSprite();
void onButtonPressed3();
void onMouseMove3(sf::Event e);

void newSurface();
//*****************************************************************************************************************
//																Gestion des objets
//*****************************************************************************************************************
int objActif;
int objMove;
float oldPosX;
float oldPosY;
float oldPosZ;
bool flagObjActif;
void objetCreate();
void delObjet(int obj);
void delGrpObjet(int obj);
void delAllObjet();
sf::Vector3f defGrpBarycentre();
sf::Vector3f defBarycentre();
void defGrpExpansion(float dt);
void rotateY3D();
void rotateX3D();
void rotateZ3D();
void onButtonPressedOutils();
void objetCoordCtrl(int id);
sf::Vector2f  objetCoordToPDessus(float x, float y);
sf::Vector2f objetCoordFromPDessus(float x, float y);
sf::Vector2f objetCoordFromPDroite(float x, float y);
sf::Vector2f objetCoordFromPArriere(float x, float y);
sf::Vector2f objetCoordFromP3D(float x, float y);
sf::Vector2f objetCoordToPDroite(float x, float y);
sf::Vector2f objetCoordToPArriere(float x, float y);
sf::Vector3f objetCoordToP3D(float x, float y, float z);

void quaternionRotation(float a, float b, float c, float d);
//void quaternionRotation(float a, float b, float c);
// *****************************************************************************************************************
//																Gestion de l'espace
// *****************************************************************************************************************
int prefDAW;
std::string prefServeur;
int prefPortD;

void gain(int in);
void sendOSCcoordPluginArdour(int track,int plug,int piid,float value);
void sendOSCcoordPluginReaper(int track,int piid,float value);
