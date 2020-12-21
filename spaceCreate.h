#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <stdlib.h>
#include <vector>

#include <tgmath.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


sf::RenderWindow winCreate(sf::VideoMode(1050,846), "Espace",sf::Style::Close);
sf::RenderWindow win3D;
sf::ContextSettings settings;

std::string defGui;
std::string home;
sf::Font font;

float oldWinSizeX;
float oldWinSizeY;
float scaleX;
float scaleY;

float PI;

int nbcolonnes;
int nblignes;
int nbHlignes; 

sf::VertexArray linei(sf::Lines, 2);
sf::VertexArray linej(sf::Lines, 2);
sf::VertexArray linek(sf::Lines, 2);

sf::Texture imageF1;
sf::Sprite fond3D;
sf::Sprite fond3D2;
float base3Dy;
sf::RectangleShape vueDessus;
sf::Texture imageF2;
sf::Sprite curseurV;
sf::Texture imageF3;
sf::Sprite cvalue;
sf::Texture imageF4;
sf::Sprite rightRed;
sf::Texture imageF5;
sf::Sprite speaker;
sf::Texture imageF6;
sf::Sprite fileOpen;
sf::Texture imageF7;
sf::Sprite fileSave;
sf::Texture imageF8;
sf::Sprite faustIde;
sf::Texture imageF9;
sf::Sprite overAll;
sf::Texture imageF10;
sf::Texture imageF11;
sf::Sprite repere1;
sf::Texture imageF12;
sf::Sprite boutonV;
sf::Sprite boutonV2;
sf::Texture imageF13;
sf::Sprite triTop;
sf::Texture imageF14;
sf::Sprite triBot;
sf::Texture imageF15;
sf::Sprite file;
sf::Texture imageF16;

sf::Sprite coordXbox;
sf::Sprite coordYbox;
sf::Sprite coordZbox;
sf::Text txtCvalue;

sf::Text newFile;
sf::Text coordXtxt;
sf::Text coordYtxt;
sf::Text coordZtxt;
sf::Text coordXlab;
sf::Text coordYlab;
sf::Text coordZlab;
sf::Text txtBoxvalue;
sf::Text labelOverAll;

sf::Text boutonTxt;
sf::Text boutonTxt2;

sf::Text titreTableau;
sf::Text titreTableau2;
sf::Text tableauS;
sf::Text tableauC;
sf::Text tableauX;
sf::Text tableauXb;
sf::Text tableauY;
sf::Text tableauZ;
sf::Text tableauZb;

sf::Text tableauA;
sf::Text tableauE;
sf::Text tableauR;
sf::Text tableauValue;

int offsetTableau;
bool flagSlider;
float oldSliderY;

std::string apptxt;
int tabId;
int tabType;
bool flagTxt;

sf::RectangleShape fFront;
sf::RectangleShape fRect;
sf::RectangleShape fPlan;
sf::RectangleShape fPlani;

sf::RectangleShape sTableau;
sf::RectangleShape sTableau2;
sf::RectangleShape sTableau3;
sf::RectangleShape sTableau4;
sf::RectangleShape sTableau5;
sf::RectangleShape sTableauFslider;
sf::RectangleShape sTableauSlider;

sf::RectangleShape selectSpeaker;
int curSelect;
sf::RectangleShape pSpeaker;

std::vector<float> newPlan;
std::vector<sf::Vector2f> newBoxPlan;
sf::Sprite nbox;

float w3WxScale;
float w3HyScale;
sf::Sprite repere3D;
sf::Sprite repere2D;
sf::Texture grille3d;
sf::Texture repere;
sf::Texture repere2;
float Theta;
float Phi;
float rxquad;
float ryquad;
float rzquad;
float oldX;
float oldY;
float pTheta;				// Rotation 
float pPhi;
int drawWine3D;
GLUquadricObj *quadratic;
float tx;
float ty;
float sTx;
float sTy;
sf::Sprite dtexture;

bool flagObjActif;
bool flagCurseurV;
bool flagAll;
float planActif;
float curseurValue;
struct nSpeaker{			// Structure pour les enceintes  sweetspot
		int sortie;
		int canal;
	   float x;            // x
	   float y;            //y
	   float z;            //y
	 };
std::vector<nSpeaker> tabSpeaker;
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

void onEventResized(sf::Event e);
void mouseWheel(sf::Event e);
void onKeyPressed(sf::Event e);
void onClick(sf::Event e);
void onMouseUp(sf::Event e);
void onMouseMove(sf::Event e);

void space3DDraw();
void spacePDraw();
void curseurPos();
void defPlan();
void nplanDraw();
void speakerDraw();
void tableauDraw();
void tableauDrawValue();
void tableauTxtS(sf::Event e);
void tableauRenumS(int debut);
void tableauRenumC(int debut);


bool comparared(const nSpeaker lhs, const nSpeaker rhs);
void triTableauZd();
bool comparares(const nSpeaker lhs, const nSpeaker rhs);
void triTableauZs();
bool comparareSorta(const nSpeaker lhs, const nSpeaker rhs);
void triTableauSa();
bool comparareSortd(const nSpeaker lhs, const nSpeaker rhs);
void triTableauSd();
bool comparareCanala(const nSpeaker lhs, const nSpeaker rhs);
void triTableauCd();
bool comparareCanald(const nSpeaker lhs, const nSpeaker rhs);
void triTableauCa();

void studioDraw();

void saveSpace();
void loadSpace();
void saveDSP();
void saveTableauHtml();

void init3D();
void drawMur(float echX, float echY);
void drawSprite();
void onButtonPressed3();
void onMouseMove3(sf::Event e);
