#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <dirent.h>
#include <vector>
#include <iomanip>
#include <experimental/filesystem>
#include <atomic>
#include <boost/filesystem.hpp>
#include <tgmath.h>

#include <GL/gl.h>
#include <GL/glu.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "spaceCreate.h"

using namespace std;

int main(int argc, char* argv[]){

std::stringstream adr;
adr << std::fixed << argv[1]<<"/gui/";
defGui=adr.str();
defInstall=argv[1];
adr.clear();
adr.str("");
home=argv[2];
adr << std::fixed << argv[1]<<"/gui";
fileSelector.setSelectorGui(adr.str());
fileSelector.setSelectorTheme(defInstall+"/Themes/base");
fileSelector.setTitreSelector("File selector");
fileSelector.setSelectorLang(defInstall+"/Lang/divers.Fr");

fileSelector.setSelectorWidth(500);
fileSelector.setSelectorHeight(436);
sf::Color bkg=sf::Color(std::stoul("e3e9ecff",nullptr,16));
fileSelector.setSelectorBkgColor(bkg);
sf::Color bc=sf::Color(std::stoul("c3ccd0ff",nullptr,16));
fileSelector.setSelectorBarColor(bc);
bkg=sf::Color(std::stoul("ffffffff",nullptr,16));
fileSelector.setSelectorPathColor(bkg);
bc=sf::Color(std::stoul("ffffffff",nullptr,16));
fileSelector.setSelectorFileColor(bc);
bc=sf::Color(std::stoul("646464ff",nullptr,16));
fileSelector.setSelectorLineColor(bc);
bc=sf::Color(std::stoul("efefefff",nullptr,16));
fileSelector.setSelectorSlider1Color(bc);
bc=sf::Color(std::stoul("efefefff",nullptr,16));
fileSelector.setSelectorSlider2Color(bc);
bc=sf::Color(std::stoul("000000ff",nullptr,16));
fileSelector.setSelectorSlider1thColor(bc);
bc=sf::Color(std::stoul("000000ff",nullptr,16));
fileSelector.setSelectorSlider2thColor(bc);
sf::Color fc=sf::Color(std::stoul("000000ff",nullptr,16));
fileSelector.setSelectorFontColor(fc);
fileSelector.setSelectorFontSize(13);
fileSelector.setSelectFontSize(13);


adr.clear();
adr.str("");

PI= 3.14159265359;

flagObjActif=0;
flagCurseurV=0;
flagAll=0;
planActif=255;
curseurValue=0;
nblignes=10;
nbHlignes=10;
nbcolonnes=10;
curSelect=65535;

base3Dy=20;
oldWinSizeX=1050;
oldWinSizeY=846;
scaleX=1;
scaleY=1;
offsetTableau=0;
oldSliderY=554;
flagSlider=0;
apptxt="0";
tabId=0;
tabType=0;
flagTxt=0;
newFile.setString("");

adr << std::fixed << defGui<<"FreeSans.ttf";
if (!font.loadFromFile(adr.str()))
	 return EXIT_FAILURE;
adr.clear();
adr.str("");

newFile.setFont(font);
newFile.setCharacterSize(13);
newFile.setFillColor(sf::Color(0,0,0));
newFile.setPosition(732,518);
txtCvalue.setFont(font);
txtCvalue.setCharacterSize(13);
txtCvalue.setFillColor(sf::Color(0,0,0));
txtBoxvalue.setFont(font);
txtBoxvalue.setCharacterSize(13);
txtBoxvalue.setFillColor(sf::Color(0,0,0));
coordXlab.setFont(font);
coordXlab.setCharacterSize(13);
coordXlab.setFillColor(sf::Color(255,255,255));
coordXlab.setPosition(sf::Vector2f(760,477));
coordXlab.setString("X");
coordYlab.setFont(font);
coordYlab.setCharacterSize(13);
coordYlab.setString("Y");
coordYlab.setFillColor(sf::Color(255,255,255));
coordYlab.setPosition(860,477);
coordZlab.setFont(font);
coordZlab.setCharacterSize(13);
coordZlab.setString("Z");
coordZlab.setFillColor(sf::Color(255,255,255));
coordZlab.setPosition(960,477);
coordXtxt.setFont(font);
coordXtxt.setCharacterSize(13);
coordXtxt.setFillColor(sf::Color(0,0,0));
coordYtxt.setFont(font);
coordYtxt.setCharacterSize(13);
coordYtxt.setFillColor(sf::Color(0,0,0));
coordZtxt.setFont(font);
coordZtxt.setCharacterSize(13);
coordZtxt.setFillColor(sf::Color(0,0,0));

labelOverAll.setFont(font);
labelOverAll.setCharacterSize(13);
labelOverAll.setFillColor(sf::Color(255,255,255));
labelOverAll.setString("All");
labelOverAll.setPosition(540,477);

titreTableau.setFont(font);
titreTableau.setCharacterSize(13);
titreTableau.setFillColor(sf::Color(0,0,0));
titreTableau.setString(L"Coordonnées Cartésiennes");
titreTableau.setPosition(798,508);


tableauS.setFont(font);
tableauS.setCharacterSize(13);
tableauS.setFillColor(sf::Color(0,0,0));
tableauS.setString("S");
tableauC.setFont(font);
tableauC.setCharacterSize(13);
tableauC.setFillColor(sf::Color(0,0,0));
tableauC.setString("C");
tableauX.setFont(font);
tableauX.setCharacterSize(13);
tableauX.setFillColor(sf::Color(0,0,0));
tableauX.setString("X");
tableauY.setFont(font);
tableauY.setCharacterSize(13);
tableauY.setFillColor(sf::Color(0,0,0));
tableauY.setString("Y");
tableauZ.setFont(font);
tableauZ.setCharacterSize(13);
tableauZ.setFillColor(sf::Color(0,0,0));
tableauZ.setString("Z");
tableauZb.setFont(font);
tableauZb.setCharacterSize(13);
tableauZb.setFillColor(sf::Color(0,0,0));
tableauZb.setString("-Z");
tableauXb.setFont(font);
tableauXb.setCharacterSize(13);
tableauXb.setFillColor(sf::Color(255,255,255));
tableauXb.setString("-X");

boutonTxt.setFont(font);
boutonTxt.setCharacterSize(13);
boutonTxt.setFillColor(sf::Color(0,0,0));
boutonTxt.setPosition(sf::Vector2f(592, 686));
boutonTxt.setString("Renum. Sorties");
boutonTxt2.setFont(font);
boutonTxt2.setCharacterSize(13);
boutonTxt2.setFillColor(sf::Color(0,0,0));
boutonTxt2.setPosition(sf::Vector2f(592, 716));
boutonTxt2.setString("Renum. Canaux");

tableauValue.setFont(font);
tableauValue.setCharacterSize(13);
tableauValue.setFillColor(sf::Color(0,0,0));
tableauValue.setString("");

tableauS.setPosition(sf::Vector2f(764,533));
tableauC.setPosition(sf::Vector2f(796,533));
tableauX.setPosition(sf::Vector2f(844,533));
tableauY.setPosition(sf::Vector2f(900,533));
tableauZ.setPosition(sf::Vector2f(956,533));



adr << std::fixed << defGui<<"virtualCreateb.png";
if (!imageF1.loadFromFile(adr.str()))
   return EXIT_FAILURE;
fond3D.setTexture(imageF1);
fond3D.setPosition(sf::Vector2f(0, 0));
fond3D2.setTexture(imageF1);
fond3D2.setPosition(sf::Vector2f(0, 450));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"curseurV.png";
if (!imageF2.loadFromFile(adr.str()))
   return EXIT_FAILURE;
curseurV.setTexture(imageF2);
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"saisie.png";
if (!imageF3.loadFromFile(adr.str()))
   return EXIT_FAILURE;
nbox.setTexture(imageF3);
coordXbox.setTexture(imageF3);
coordXbox.setPosition(sf::Vector2f(780,475));
coordYbox.setTexture(imageF3);
coordYbox.setPosition(sf::Vector2f(880,475));
coordZbox.setTexture(imageF3);
coordZbox.setPosition(sf::Vector2f(980,475));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"rightRed.png";
if (!imageF4.loadFromFile(adr.str()))
   return EXIT_FAILURE;
rightRed.setTexture(imageF4);
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"speaker.png";
if (!imageF5.loadFromFile(adr.str()))
   return EXIT_FAILURE;
speaker.setTexture(imageF5);
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"open.png";
if (!imageF6.loadFromFile(adr.str()))
   return EXIT_FAILURE;
fileOpen.setTexture(imageF6);
fileOpen.setPosition(sf::Vector2f(644, 474));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"floppy.png";
if (!imageF7.loadFromFile(adr.str()))
   return EXIT_FAILURE;
fileSave.setTexture(imageF7);
fileSave.setPosition(sf::Vector2f(674, 474));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"faustide.png";
if (!imageF8.loadFromFile(adr.str()))
   return EXIT_FAILURE;
faustIde.setTexture(imageF8);
faustIde.setPosition(sf::Vector2f(704, 474));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"bNoSelect.png";
if (!imageF9.loadFromFile(adr.str()))
   return EXIT_FAILURE;
overAll.setTexture(imageF9);
overAll.setPosition(sf::Vector2f(564, 477));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"bselect.png";
if (!imageF10.loadFromFile(adr.str()))
   return EXIT_FAILURE;
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"repere3d.png";
if (!imageF11.loadFromFile(adr.str()))
   return EXIT_FAILURE;
repere1.setTexture(imageF11);
repere1.setPosition(sf::Vector2f(570, 552));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"bvide.png";
if (!imageF12.loadFromFile(adr.str()))
   return EXIT_FAILURE;
boutonV.setTexture(imageF12);
boutonV.setPosition(sf::Vector2f(584, 684));
boutonV2.setTexture(imageF12);
boutonV2.setPosition(sf::Vector2f(584, 714));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"triTop.png";
if (!imageF13.loadFromFile(adr.str()))
   return EXIT_FAILURE;
triTop.setTexture(imageF13);
triTop.setPosition(sf::Vector2f(920, 532));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"triBot.png";
if (!imageF14.loadFromFile(adr.str()))
   return EXIT_FAILURE;
triBot.setTexture(imageF14);
triBot.setPosition(sf::Vector2f(920, 542));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"saisie3.png";
if (!imageF15.loadFromFile(adr.str()))
   return EXIT_FAILURE;
file.setTexture(imageF15);
file.setPosition(sf::Vector2f(540, 510));
adr.clear();
adr.str("");

adr << std::fixed << defGui<<"g7002.png";
if (!imageF16.loadFromFile(adr.str()))
   return EXIT_FAILURE;
dtexture.setTexture(imageF16);
dtexture.setPosition(sf::Vector2f(540, 510));
adr.clear();
adr.str("");

vueDessus.setSize(sf::Vector2f(450,450));
vueDessus.setFillColor(sf::Color(203,213,217));
vueDessus.setPosition(sf::Vector2f(600, 0));


fRect.setFillColor(sf::Color(255,255,255,0));
fRect.setOutlineColor(sf::Color(255,255,255,255));
fRect.setOutlineThickness(1);
fFront.setPosition(sf::Vector2f(1,base3Dy));
fFront.setFillColor(sf::Color(0,0,0,255));
fFront.setOutlineColor(sf::Color(255,255,255,255));
fFront.setOutlineThickness(1);

fPlan.setFillColor(sf::Color(203,213,217,255));
fPlan.setOutlineColor(sf::Color(255,0,255));
fPlan.setOutlineThickness(1);
fPlani.setFillColor(sf::Color(0,0,0,0));
fPlani.setOutlineColor(sf::Color(0,0,255));
fPlani.setOutlineThickness(1);

sTableau.setFillColor(sf::Color(203,213,217,255));
sTableau.setOutlineColor(sf::Color(0,0,0));
sTableau.setOutlineThickness(3);
sTableau.setPosition(sf::Vector2f(754,504));
sTableau.setSize(sf::Vector2f(240,337));
sTableau2.setFillColor(sf::Color(203,213,217,255));
sTableau2.setOutlineColor(sf::Color(0,0,0));
sTableau2.setOutlineThickness(1);
sTableau2.setPosition(sf::Vector2f(754,504));
sTableau2.setSize(sf::Vector2f(240,24));

sTableau3.setFillColor(sf::Color(203,213,217,255));
sTableau3.setOutlineColor(sf::Color(0,0,0));
sTableau3.setOutlineThickness(1);
sTableau3.setPosition(sf::Vector2f(818,504));
sTableau3.setSize(sf::Vector2f(3,336));

sTableau4.setFillColor(sf::Color(203,213,217,255));
sTableau4.setOutlineColor(sf::Color(0,0,0));
sTableau4.setOutlineThickness(1);
//sTableau4.setPosition(sf::Vector2f(706,559));
sTableau4.setSize(sf::Vector2f(58,24));

sTableau5.setFillColor(sf::Color(203,213,217,255));
sTableau5.setOutlineColor(sf::Color(0,0,0));
sTableau5.setOutlineThickness(1);
//sTableau4.setPosition(sf::Vector2f(706,559));
sTableau5.setSize(sf::Vector2f(32,24));

sTableauFslider.setFillColor(sf::Color(203,213,217,255));
sTableauFslider.setOutlineColor(sf::Color(0,0,0));
sTableauFslider.setOutlineThickness(1);
sTableauFslider.setPosition(sf::Vector2f(998,552));
sTableauFslider.setSize(sf::Vector2f(20,288));
sTableauSlider.setFillColor(sf::Color(158,167,171));
sTableauSlider.setOutlineColor(sf::Color(0,0,0));
sTableauSlider.setOutlineThickness(1);
sTableauSlider.setPosition(sf::Vector2f(1000,554));
sTableauSlider.setSize(sf::Vector2f(16,40));

selectSpeaker.setFillColor(sf::Color(0,0,0,0));
selectSpeaker.setOutlineColor(sf::Color(0,0,0,255));
selectSpeaker.setOutlineThickness(1);
selectSpeaker.setSize(sf::Vector2f(23,23));

pSpeaker.setSize(sf::Vector2f(40,80));
pSpeaker.setFillColor(sf::Color(255,255,255,255));


bkgToolType.setSize(sf::Vector2f(100,24));
bkgToolType.setPosition(sf::Vector2f(80,88));
bkgToolType.setFillColor(sf::Color(203,213,217,0));

toolType.setFont(font);
toolType.setString(L"Paramètres");
toolType.setCharacterSize(13);
toolType.setPosition(100,92);
toolType.setFillColor(sf::Color(0,0,0,0));
string s="Afficher tous les hauts-parleurs";
tip[0]=sf::String::fromUtf8(s.begin(),s.end());
s="Fichiers";
tip[1]=sf::String::fromUtf8(s.begin(),s.end());
s="Sauvegarder";
tip[2]=sf::String::fromUtf8(s.begin(),s.end());
s="Fichier DSP";
tip[3]=sf::String::fromUtf8(s.begin(),s.end());
s="Fenêtre 3D";
tip[4]=sf::String::fromUtf8(s.begin(),s.end());
//************************************************************************************************
//                                              init win3D
//************************************************************************************************
adr << std::fixed << defGui<<"grille3b.png";										// Image de texture pour les murs
if (!grille3d.loadFromFile(adr.str()))  
	return EXIT_FAILURE;
grille3d.setSmooth(true);
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"sphereRot.png";												// Image de la sphère de rotation
if (!repere.loadFromFile(adr.str()))
   return EXIT_FAILURE;
repere.setSmooth(true);
repere3D.setTexture(repere);
repere3D.setPosition(sf::Vector2f(18.0, 620.0));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"repere2d72.png";										// Image translation
if (!repere2.loadFromFile(adr.str()))
   return EXIT_FAILURE;
repere2.setSmooth(true);
repere2D.setTexture(repere2);
repere2D.setPosition(sf::Vector2f(18.0, 710.0));
adr.clear();
adr.str("");
settings.depthBits = 32;
settings.stencilBits = 8;
settings.antialiasingLevel = 4;
settings.majorVersion = 1;
settings.minorVersion = 1; 

init3D();

//************************************************************************************************************
while (winCreate.isOpen()) {
	sf::Event eventCreate;
	sf::Event event3D;
	
  
	while (winCreate.pollEvent(eventCreate)){        
 			switch (eventCreate.type){
  			case sf::Event::Closed:
					//writeConfGui();
					//writePreferences();
					winCreate.close();
					break;
			case sf::Event::Resized:
					onEventResized(eventCreate);
					break;
  			case sf::Event::KeyPressed:
  					onKeyPressed(eventCreate);
					break;
			case sf::Event::MouseButtonPressed:
					onClick(eventCreate);
					break;
			case sf::Event::MouseWheelScrolled:
					mouseWheel(eventCreate);
					break;
			case sf::Event::MouseButtonReleased:
					onMouseUp(eventCreate);
					break;
			case sf::Event::MouseMoved:
					onMouseMove(eventCreate);
					break;
			case sf::Event::TextEntered:
	     			   tableauTxtS(eventCreate);
					   break;
		  			default:
					break;
  		  	}            
	}
	while (win3D.pollEvent(event3D)){        							// on regarde le type de l'évènement...
 			switch (event3D.type){
	  			case sf::Event::Closed:
	  				drawWine3D=0;
	  				pTheta=0.1;
	      		win3D.close();
	      		break;
	      	case sf::Event::MouseMoved:
	     			onMouseMove3(event3D);
	      	break;				
	  			default:// on ne traite pas les autres types d'évènements
	      	break;
  		  	}            
   }
	
	winCreate.setActive(true);
	winCreate.pushGLStates();
	winCreate.clear(sf::Color(19,37,53));
    
	space3DDraw();
	spacePDraw();
	curseurPos();
	winCreate.draw(curseurV);
	winCreate.draw(txtCvalue);
	winCreate.draw(fond3D2);	
	nplanDraw();
	if(newBoxPlan.size()>0){
		winCreate.draw(rightRed);
	}
	speakerDraw();
	winCreate.draw(coordXbox);
	winCreate.draw(coordYbox);
	winCreate.draw(coordZbox);
	winCreate.draw(coordXtxt);
	winCreate.draw(coordYtxt);
	winCreate.draw(coordZtxt);
	winCreate.draw(coordXlab);
	winCreate.draw(coordYlab);
	coordZlab.setPosition(960,477);
	winCreate.draw(coordZlab);
	
	winCreate.draw(labelOverAll);
	winCreate.draw(overAll);
	winCreate.draw(fileOpen);
	winCreate.draw(fileSave);
	winCreate.draw(faustIde);
	
	tableauDraw();
	tableauDrawValue();
	
	winCreate.draw(repere1);
	winCreate.draw(boutonV);
	winCreate.draw(boutonV2);
	winCreate.draw(boutonTxt);
	winCreate.draw(boutonTxt2);
	
	winCreate.draw(file);
	winCreate.draw(newFile);
	studioDraw();	
	
	winCreate.draw(bkgToolType);
 	winCreate.draw(toolType);
	
	winCreate.display();
	winCreate.popGLStates();
	winCreate.setActive(false);
	
	if(win3D.isOpen()){
		win3D.setActive(true);
    	win3D.pushGLStates();
    	win3D.clear(sf::Color(19,37,53));
    	
    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);			//Construction de l'espace
	    win3D.clear(sf::Color(6,12,27,1));  // 203,213,217  6,12,27,1
	    
	    glLoadIdentity();
	    gluLookAt(-rxquad,ryquad,rzquad,0,0,0,0,1,0);
		 glTranslatef(0.0f,0.0f,0.0f);
															  // dessin des objets
	 	 glColor4f(255,255,0,1);
	 	 
	 	 gluQuadricDrawStyle(quadratic,GLU_FILL);
	  	 drawSprite();
		 
	 	 
	    sf::Texture::bind(&grille3d);          // Repère 3D
	    drawMur(1.0*w3WxScale,1.0*w3HyScale);
	    sf::Texture::bind(NULL);
	    /*
	    glPushMatrix();
	  		glTranslatef(tx*w3WxScale,ty*w3HyScale,0); 
	  	 	drawCube(-0.01,0.04*w3WxScale,0.04*w3HyScale);
	  	 glPopMatrix();
		 
		 
	 	 if(pseudoSpeaker==1){
	 	 	drawSpeaker();
	 	 }   
	 	 */
	    win3D.draw(repere3D);
	    win3D.draw(repere2D);
		 if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){  // événements souris pour la sphère
	 	 	onButtonPressed3();
	 	 }	
    	
    	win3D.display();
    	win3D.popGLStates();
    	win3D.setActive(false);
	}
 }
}

void onEventResized(sf::Event e){
sf::FloatRect visibleArea(0, 0, winCreate.getSize().x, winCreate.getSize().y);
winCreate.setView(sf::View(visibleArea));
scaleX=visibleArea.width/oldWinSizeX;
scaleY=visibleArea.height/oldWinSizeY;
//oldWinSizeX=winCreate.getSize().x;
//oldWinSizeY=winCreate.getSize().y;
std::cout << " scaleX " << scaleX << " scaleY " << scaleY << std::endl;
}
void mouseWheel(sf::Event e){
	int nposy;
	if (e.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel && e.mouseWheelScroll.x>754 && e.mouseWheelScroll.x<994 && e.mouseWheelScroll.y>530 && e.mouseWheelScroll.y< 842){
		
		 if(e.mouseWheelScroll.delta==1){
		 	nposy=sTableauSlider.getPosition().y-1;
		 	
		 	if(offsetTableau<1){
		 		offsetTableau=0;
		 	}else{
		 		offsetTableau=offsetTableau-1;
		 		sTableauSlider.setPosition(sf::Vector2f(sTableauSlider.getPosition().x,nposy));
		 	}
		 }else{
		 	nposy=sTableauSlider.getPosition().y+1;
		 	if(offsetTableau<tabSpeaker.size()){
		 		sTableauSlider.setPosition(sf::Vector2f(sTableauSlider.getPosition().x,nposy));
		 		offsetTableau=offsetTableau+1;
		 	}else{
		 		
		 	}
		 }
	}
}

void onKeyPressed(sf::Event e){
			std::cout << "key " <<e.key.code << std::endl;
			bool flagSp=0;
	if (e.key.code == sf::Keyboard::Delete){
		tabSpeaker.erase(tabSpeaker.begin()+curSelect);
		tabType=3;
		curSelect=65535;
	}
	
}
void onClick(sf::Event e){
	stringstream adr;
	string s;
	float cx;
	float cy;
	if (e.mouseButton.button == sf::Mouse::Left){
 		std::cout << " Palette the left button was pressed" << std::endl;
 		std::cout << "mouse x: " << e.mouseButton.x << std::endl;
 		std::cout << "mouse y: " << e.mouseButton.y << std::endl;
   }
   for(int i=0;i<newBoxPlan.size();i++){
   	if(e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>newBoxPlan[i].x && e.mouseButton.x<newBoxPlan[i].x+65 && e.mouseButton.y>newBoxPlan[i].y && e.mouseButton.y<newBoxPlan[i].y+65){
   		rightRed.setPosition(sf::Vector2f(newBoxPlan[i].x+65,newBoxPlan[i].y));
   		adr << std::fixed<< std::setprecision(3)<<newPlan[i];
         s=adr.str();
         coordYtxt.setString(s);
	   	coordYtxt.setPosition(928-coordYtxt.getLocalBounds().width,478);
	   	adr.clear();
         adr.str("");
         planActif=newPlan[i];
	   	std::cout << "coordYtxt " << s<< std::endl;
	   	break;
   	}
   }
   if(e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>curseurV.getPosition().x && e.mouseButton.x<curseurV.getPosition().x+85 && e.mouseButton.y>curseurV.getPosition().y && e.mouseButton.y<curseurV.getPosition().y+22+base3Dy){
   	flagCurseurV=1;
   	flagObjActif=0;
   }
   if(e.mouseButton.button == sf::Mouse::Right && e.mouseButton.x>curseurV.getPosition().x && e.mouseButton.x<curseurV.getPosition().x+85 && e.mouseButton.y>curseurV.getPosition().y && e.mouseButton.y<curseurV.getPosition().y+22+base3Dy){
   	defPlan();
   }
   if(planActif!=255 && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>fPlani.getPosition().x && e.mouseButton.x<fPlani.getPosition().x+fPlani.getSize().x+12 && e.mouseButton.y>fPlani.getPosition().y && e.mouseButton.y<fPlani.getPosition().y+fFront.getSize().y){
   	for(int i=0;i<tabSpeaker.size();i++){
   		cx=fPlani.getPosition().x+(fPlani.getSize().x*((tabSpeaker[i].x+1)/2));
		   cy=fPlani.getPosition().y+(fPlani.getSize().y*((tabSpeaker[i].y+1)/2));
			if(tabSpeaker[i].z==planActif && e.mouseButton.x>cx && e.mouseButton.x<cx+24 && e.mouseButton.y>cy && e.mouseButton.y<cy+24){
				flagObjActif=1;
				curSelect=i;
				std::cout << "curselect " << curSelect<< std::endl;
				break;
			}
		}
		if(flagObjActif==0){
	   	nSpeaker nsp;
	   	nsp.z=planActif;
	   	nsp.sortie=tabSpeaker.size()+1;
	   	nsp.canal=tabSpeaker.size()+1;
	   	flagCurseurV=0;
	   	flagObjActif=1;
	   	cx=-1+((e.mouseButton.x-12-fPlani.getPosition().x)*(2/fPlani.getSize().x));
	   	if(cx>0.99){
   			cx=1;

		   }
		   if(cx<-0.99){
		   	cx=-1;
		   }
		   nsp.x=cx;
	   	adr << std::fixed<< std::setprecision(3)<<cx;
         s=adr.str();
         coordZtxt.setString(s);
	   	coordZtxt.setPosition(1028-coordZtxt.getLocalBounds().width,478);
	   	adr.clear();
         adr.str("");
         cy=-1+((e.mouseButton.y-12-fPlani.getPosition().y)*(2/fPlani.getSize().y));
         if(cy>0.99){
   			cy=1;
		   }
		   if(cy<-0.99){
		   	cy=-1;
		   }
		   nsp.y=cy;
         adr << std::fixed<< std::setprecision(3)<<cy;
         s=adr.str();
         coordXtxt.setString(s);
	   	coordXtxt.setPosition(828-coordXtxt.getLocalBounds().width,478);
	   	adr.clear();
         adr.str("");
         curSelect=tabSpeaker.size();
         tabSpeaker.push_back(nsp);
         
	   }
   }
   if(planActif!=255 && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>754 && e.mouseButton.x<786 && e.mouseButton.y>556 && e.mouseButton.y<842){
   	tabId=((e.mouseButton.y-556)/24)+offsetTableau;
		tabType=0;
		curSelect=tabId;
		apptxt="";
		std::cout << "s " << curSelect<<  std::endl;
   }
   if(planActif!=255 && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>786 && e.mouseButton.x<818 && e.mouseButton.y>556 && e.mouseButton.y<842){
   	tabId=((e.mouseButton.y-556)/24)+offsetTableau;
		tabType=1;
		curSelect=tabId;
		apptxt="";
		std::cout << "c " <<  std::endl;
   }
   if(e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>540 && e.mouseButton.x<740 && e.mouseButton.y>512 && e.mouseButton.y<534){
		tabType=2;
		apptxt="";
		newFile.setString("");
   }
   if(planActif!=255 && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>586 && e.mouseButton.x<690 && e.mouseButton.y>686 && e.mouseButton.y<710){
   	tableauRenumS(0);
   }
   if(planActif!=255 && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>586 && e.mouseButton.x<690 && e.mouseButton.y>716 && e.mouseButton.y<740){
   	tableauRenumC(0);
   }
   if(planActif!=255 && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>774 && e.mouseButton.x<782 && e.mouseButton.y>530 && e.mouseButton.y<540){
   	triTableauSa();
   }
   if(planActif!=255 && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>774 && e.mouseButton.x<782 && e.mouseButton.y>540 && e.mouseButton.y<550){
   	triTableauSd();
   }
   if(planActif!=255 && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>810 && e.mouseButton.x<818 && e.mouseButton.y>530 && e.mouseButton.y<540){
   	triTableauCa();
   }
   if(planActif!=255 && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>810 && e.mouseButton.x<818 && e.mouseButton.y>540 && e.mouseButton.y<550){
   	triTableauCd();
   }
   if(planActif!=255 && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>920 && e.mouseButton.x<930 && e.mouseButton.y>530 && e.mouseButton.y<540){
   	triTableauZs();
   }
   if(planActif!=255 && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>920 && e.mouseButton.x<930 && e.mouseButton.y>540 && e.mouseButton.y<550){
   	triTableauZd();
   }
   if(planActif!=255 && tabSpeaker.size()>0 && e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>676 && e.mouseButton.x<696 && e.mouseButton.y>474 && e.mouseButton.y<498){
   	saveSpace();
   }
   if(e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>644 && e.mouseButton.x<668 && e.mouseButton.y>474 && e.mouseButton.y<498){
   	loadSpace();
   }
   if(e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>704 && e.mouseButton.x<728 && e.mouseButton.y>474 && e.mouseButton.y<498){
   	saveDSP();
   }
   if(e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>565 && e.mouseButton.x<580 && e.mouseButton.y>480 && e.mouseButton.y<494){
   	if(flagAll==0){
   		flagAll=1;
   		overAll.setTexture(imageF10);
   	}else{
   		flagAll=0;
   		overAll.setTexture(imageF9);
   	}
   }
   if(e.mouseButton.button == sf::Mouse::Left && e.mouseButton.x>1000 && e.mouseButton.x<1016 && e.mouseButton.y>sTableauSlider.getPosition().y && e.mouseButton.y<sTableauSlider.getPosition().y+sTableauSlider.getSize().y){
   	flagSlider=1;
   	oldSliderY=e.mouseButton.y;
   }
   if(e.mouseButton.x>570 && e.mouseButton.x<704 && e.mouseButton.y>545 && e.mouseButton.y<666){
   	win3D.create (sf::VideoMode(800,800), "Vue 3D",sf::Style::Close , settings);
		init3D();
		drawWine3D=1;
		tx=-0.16;
		ty=0.01;
		pTheta=2;
   }
   
}
void onMouseUp(sf::Event e){
	flagObjActif=0;
	flagCurseurV=0;
	flagSlider=0;
}
void onMouseMove(sf::Event e){
	std::cout << "Window Dessus mouse x: " << e.mouseMove.x << std::endl;
   std::cout << "mouse y: " << e.mouseMove.y << std::endl;
   stringstream adr;
   string s;
   if (e.mouseMove.x>540 && e.mouseMove.y>472){
		if(e.mouseMove.x>540 && e.mouseMove.x<584 && e.mouseMove.y<496 ){
		  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
		  bkgToolType.setFillColor(sf::Color(8,241,251,255));
		  bkgToolType.setSize(sf::Vector2f(192,24));
		  toolType.setString(tip[0]);
		  toolType.setPosition(e.mouseMove.x+34,e.mouseMove.y+24);
		  toolType.setFillColor(sf::Color(0,0,0,255));
		}
		if(e.mouseMove.x>642 && e.mouseMove.x<668 && e.mouseMove.y<500){
		  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
		  bkgToolType.setFillColor(sf::Color(8,241,251,255));
		  bkgToolType.setSize(sf::Vector2f(70,24));
		  toolType.setString(tip[1]);
		  toolType.setPosition(e.mouseMove.x+34,e.mouseMove.y+24);
		  toolType.setFillColor(sf::Color(0,0,0,255));
		}
		if(e.mouseMove.x>672 && e.mouseMove.x<698 && e.mouseMove.y<500){
		  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
		  bkgToolType.setFillColor(sf::Color(8,241,251,255));
		  bkgToolType.setSize(sf::Vector2f(94,24));
		  toolType.setString(tip[2]);
		  toolType.setPosition(e.mouseMove.x+28,e.mouseMove.y+24);
		  toolType.setFillColor(sf::Color(0,0,0,255));
		}
		if(e.mouseMove.x>700 && e.mouseMove.x<732 && e.mouseMove.y<500){
		  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
		  bkgToolType.setFillColor(sf::Color(8,241,251,255));
		  bkgToolType.setSize(sf::Vector2f(80,24));
		  toolType.setString(tip[3]);
		  toolType.setPosition(e.mouseMove.x+28,e.mouseMove.y+24);
		  toolType.setFillColor(sf::Color(0,0,0,255));
		}
	}
	if(e.mouseMove.x>562 && e.mouseMove.x<712 && e.mouseMove.y>546 && e.mouseMove.y<670){
	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
	  bkgToolType.setFillColor(sf::Color(8,241,251,255));
	  bkgToolType.setSize(sf::Vector2f(78,24));
	  toolType.setString(tip[4]);
	  toolType.setPosition(e.mouseMove.x+28,e.mouseMove.y+24);
	  toolType.setFillColor(sf::Color(0,0,0,255));
	}
	if(e.mouseMove.x>562 && e.mouseMove.y>670 || e.mouseMove.y<472){
		bkgToolType.setFillColor(sf::Color(8,241,251,0));
		toolType.setFillColor(sf::Color(0,0,0,0));
	}	

   float curS;
   float curSy;
   float cx;
   float cy;
   sf::Vector2u wsize=winCreate.getSize();
	float winWidth=wsize.x/2;
	float winHeight=wsize.y/2;
   if(flagCurseurV==1 && e.mouseMove.x>curseurV.getPosition().x && e.mouseMove.x<curseurV.getPosition().x+85 && e.mouseMove.y>base3Dy-2 && e.mouseMove.y<winHeight+base3Dy+2){
   	curseurValue=winHeight-e.mouseMove.y+base3Dy+2;
   }
	if(e.mouseMove.x>fPlani.getPosition().x && e.mouseMove.x<fPlani.getPosition().x+fPlani.getSize().x+12 && e.mouseMove.y>fPlani.getPosition().y && e.mouseMove.y<fPlani.getPosition().y+fFront.getSize().y){
		
		for(int i=0;i<tabSpeaker.size();i++){
				if(tabSpeaker[i].z==planActif){
				cx=fPlani.getPosition().x+(fPlani.getSize().x*((tabSpeaker[i].x+1)/2));
			   cy=fPlani.getPosition().y+(fPlani.getSize().y*((tabSpeaker[i].y+1)/2));
				if(flagObjActif==1 && e.mouseMove.x>cx && e.mouseMove.x<cx+24 && e.mouseMove.y>cy && e.mouseMove.y<cy+24){
					cx=-1+((e.mouseMove.x-12-fPlani.getPosition().x)*(2/fPlani.getSize().x));
			   	if(cx>0.99){
		   			cx=1;
				   }
				   if(cx<-0.99){
				   	cx=-1;
				   }
				   adr << std::fixed<< std::setprecision(3)<<cx;
		         s=adr.str();
		         coordZtxt.setString(s);
			   	coordZtxt.setPosition(1028-coordZtxt.getLocalBounds().width,478);
			   	adr.clear();
		         adr.str("");
				   cy=-1+((e.mouseMove.y-12-fPlani.getPosition().y)*(2/fPlani.getSize().y));
		         if(cy>0.99){
		   			cy=1;
				   }
				   if(cy<-0.99){
				   	cy=-1;
				   }
				   adr << std::fixed<< std::setprecision(3)<<cy;
		         s=adr.str();
		         coordXtxt.setString(s);
			   	coordXtxt.setPosition(828-coordXtxt.getLocalBounds().width,478);
			   	adr.clear();
		         adr.str("");
				   tabSpeaker[i].x=cx;
				   tabSpeaker[i].y=cy;
					break;
				}
			}
		}
	}
	if(flagSlider==1 && e.mouseMove.x>1000 && e.mouseMove.x<1016 && e.mouseMove.y>sTableauSlider.getPosition().y && e.mouseMove.y<sTableauSlider.getPosition().y+sTableauSlider.getSize().y){
	  int nposy=sTableauSlider.getPosition().y+(e.mouseMove.y-oldSliderY);
     if(nposy<556){
   		nposy=554;
     }
     if(nposy+sTableauSlider.getSize().y>844){
   		nposy=804;
     }
     sTableauSlider.setPosition(sTableauSlider.getPosition().x,nposy);
     offsetTableau=(int)nposy-554;

     oldSliderY=e.mouseMove.y; 
   }
}

void space3DDraw(){
	sf::Vector2u wsize=winCreate.getSize();
	float winWidth=526;
	float winHeight=425;
	float fPosX=winWidth/3;
	float fPosY=winHeight/3;
	fRect.setSize(sf::Vector2f(fPosX,fPosY));
	fRect.setPosition(sf::Vector2f(fPosX,fPosY+base3Dy));
	fFront.setSize(sf::Vector2f(winWidth,winHeight)); 
	winCreate.draw(fFront);
	winCreate.draw(fRect);
	sf::Vertex linea[] ={
    sf::Vertex(sf::Vector2f(0, winHeight+base3Dy)),
    sf::Vertex(sf::Vector2f(fPosX, fPosY+fPosY+base3Dy))
   };
   linea[0].color = sf::Color::White;
   linea[1].color = sf::Color::White;
   winCreate.draw(linea, 2, sf::Lines);
   sf::Vertex lineb[] ={
    sf::Vertex(sf::Vector2f(winWidth, winHeight+base3Dy)),
    sf::Vertex(sf::Vector2f(fPosX+fPosX, fPosY+fPosY+base3Dy))
   };
   lineb[0].color = sf::Color::White;
   lineb[1].color = sf::Color::White;
   winCreate.draw(lineb, 2, sf::Lines);
   sf::Vertex linec[] ={
    sf::Vertex(sf::Vector2f(winWidth, base3Dy)),
    sf::Vertex(sf::Vector2f(fPosX+fPosX, fPosY+base3Dy))
   };
   winCreate.draw(linec, 2, sf::Lines);
   sf::Vertex lined[] ={
    sf::Vertex(sf::Vector2f(0, base3Dy)),
    sf::Vertex(sf::Vector2f(fPosX, fPosY+base3Dy))
   };
   lined[0].color=sf::Color::White;
   lined[1].color=sf::Color::White;
   winCreate.draw(lined, 2, sf::Lines);
   linei[0].color = sf::Color::Blue;
   linei[1].color = sf::Color::Blue;
   linej[0].color = sf::Color::Blue;
   linej[1].color = sf::Color::Blue;
   linek[0].color = sf::Color::Blue;
   linek[1].color = sf::Color::Blue;
   float deltaFline=winWidth/nblignes;
   float deltaRlines=fPosX/nblignes;
   
   for(int i=1;i<nblignes;i++){
   	linei[0].position = sf::Vector2f(i*deltaFline,winHeight+base3Dy);
   	linei[1].position = sf::Vector2f(fPosX+(i*deltaRlines),fPosY+fPosY+base3Dy);
   	winCreate.draw(linei);
   	linej[0].position = sf::Vector2f(i*deltaFline,base3Dy);
   	linej[1].position = sf::Vector2f(fPosX+(i*deltaRlines),fPosY+base3Dy);
   	winCreate.draw(linej); 
   	linek[0].position = sf::Vector2f(fPosX+(i*deltaRlines),fPosY+fPosY+base3Dy);
   	linek[1].position = sf::Vector2f(fPosX+(i*deltaRlines),fPosY+base3Dy);
   	winCreate.draw(linek); 
   }
   float deltaFCol=winHeight/nbcolonnes;
   float deltaRCol=fPosY/nbcolonnes;
   for(int i=1;i<nbcolonnes;i++){
   	linei[0].position = sf::Vector2f(0,(i*deltaFCol)+base3Dy);
   	linei[1].position = sf::Vector2f(fPosX,fPosY+base3Dy+(i*deltaRCol));
   	winCreate.draw(linei);
   	linej[0].position = sf::Vector2f(winWidth,i*deltaFCol+base3Dy);
   	linej[1].position = sf::Vector2f(fPosX+fPosX,fPosY+base3Dy+(i*deltaRCol));
   	winCreate.draw(linej);
   }
   float deltaFHly=fPosY/nbHlignes;
   float deltaFHlx=fPosX/nbHlignes;
   for(int i=1;i<nbHlignes;i++){
   	linei[0].position = sf::Vector2f(fPosX-(i*deltaFHlx),fPosY+fPosY+base3Dy+(i*deltaFHly));
   	linei[1].position = sf::Vector2f(fPosX+fPosX+(i*deltaFHlx),fPosY+fPosY+base3Dy+(i*deltaFHly));
   	winCreate.draw(linei);
   }
   for(int i=1;i<nbHlignes;i++){
   	linei[0].position = sf::Vector2f(fPosX-(i*deltaFHlx),base3Dy+fPosY-(i*deltaFHly));
   	linei[1].position = sf::Vector2f(fPosX+fPosX+(i*deltaFHlx),+base3Dy+fPosY-(i*deltaFHly));
   	winCreate.draw(linei);
   }
   for(int i=1;i<nbHlignes;i++){
   	linei[0].position = sf::Vector2f(fPosX-(i*deltaFHlx),base3Dy+fPosY-(i*deltaFHly));
   	linei[1].position = sf::Vector2f(fPosX-(i*deltaFHlx),fPosY+fPosY+base3Dy+(i*deltaFHly));
   	winCreate.draw(linei);
   }
   for(int i=1;i<nbHlignes;i++){
   	linei[0].position = sf::Vector2f(fPosX+fPosX+(i*deltaFHlx),base3Dy+fPosY-(i*deltaFHly));
   	linei[1].position = sf::Vector2f(fPosX+fPosX+(i*deltaFHlx),fPosY+fPosY+base3Dy+(i*deltaFHly));
   	winCreate.draw(linei);
   }
   deltaFHlx=fPosX/nbHlignes;
   deltaFHly=fPosY/nbHlignes;
   for(int i=1;i<nbHlignes;i++){
   	linei[0].position = sf::Vector2f(fPosX,base3Dy+fPosY+(i*deltaFHly));
   	linei[1].position = sf::Vector2f(fPosX+fPosX,base3Dy+fPosY+(i*deltaFHly));
   	winCreate.draw(linei);
   }
}
void spacePDraw(){
	sf::Vector2u wsize=winCreate.getSize();
	float winWidth=526;
	float winHeight=425;
	fPlan.setSize(sf::Vector2f(winWidth-110,winHeight+base3Dy-20));
	fPlan.setPosition(sf::Vector2f(winWidth+112,1+base3Dy));
	winCreate.draw(fPlan);
	fPlani.setSize(sf::Vector2f(winWidth-130,winHeight-40+base3Dy));
	fPlani.setPosition(sf::Vector2f(winWidth+120,11+base3Dy));
	winCreate.draw(fPlani);
	float deltaPx=fPlani.getSize().y/nblignes;
   float deltaPz=fPlani.getSize().x/nblignes;
   for(int i=1;i<nblignes;i++){
   	linei[0].position = sf::Vector2f(fPlani.getPosition().x,fPlani.getPosition().y+deltaPx*i);
   	linei[1].position = sf::Vector2f(fPlani.getPosition().x+fPlani.getSize().x,fPlani.getPosition().y+deltaPx*i);
   	winCreate.draw(linei);
   }
   for(int i=1;i<nblignes;i++){
   	linei[0].position = sf::Vector2f(fPlani.getPosition().x+deltaPz*i,fPlani.getPosition().y);
   	linei[1].position = sf::Vector2f(fPlani.getPosition().x+deltaPz*i,fPlani.getPosition().y+fPlani.getSize().y);
   	winCreate.draw(linei);
   }
   linei[0].position = sf::Vector2f(660,458);
   linei[1].position = sf::Vector2f(1030,458);
   linei[0].color = sf::Color::White;
   linei[1].color = sf::Color::White;
   winCreate.draw(linei);
   tableauZb.setPosition(640,450);
   tableauZb.setFillColor(sf::Color(255,255,255));
   winCreate.draw(tableauZb);
   coordZlab.setPosition(1034,450);
   winCreate.draw(coordZlab);
   linei[0].position = sf::Vector2f(630,24);
   linei[1].position = sf::Vector2f(630,444);
   winCreate.draw(linei);
   linei[0].color = sf::Color::Blue;
   linei[1].color = sf::Color::Blue;
   tableauXb.setPosition(620,8);
   winCreate.draw(tableauXb);
   coordXlab.setPosition(624,446);
   winCreate.draw(coordXlab);
}
void curseurPos(){
	stringstream adr;
	sf::Vector2u wsize=winCreate.getSize();
	float winWidth=526;
	float winHeight=425; 
	curseurV.setPosition(sf::Vector2f((winWidth+4), (winHeight-6-curseurValue+base3Dy)));
	float cs=-1+(curseurValue*(2/winHeight));
	if(cs>0.99){
   		cs=1;
   }
   if(cs<-0.99){
   		cs=-1;
   }

	adr << std::fixed<< std::setprecision(3)<<cs;
   string s=adr.str();
   txtCvalue.setString(s);
	txtCvalue.setPosition(winWidth+72-txtCvalue.getLocalBounds().width-2,winHeight-3-curseurValue+base3Dy);
}
void defPlan(){
	string s=txtCvalue.getString();
	float sv=stof(s);
	newPlan.push_back(sv);
	newBoxPlan.push_back(sf::Vector2f((curseurV.getPosition().x+20)*scaleX,curseurV.getPosition().y*scaleY));
	rightRed.setPosition(sf::Vector2f(curseurV.getPosition().x+85,curseurV.getPosition().y));
}
void nplanDraw(){
	stringstream adr;
	string s;
	float sv;
	sf::Vector2u wsize=winCreate.getSize();
	float winWidth=wsize.x/2;
	float winHeight=wsize.y/2;
	float ratioY=fRect.getSize().y/fFront.getSize().y;
	linei[0].color = sf::Color::Red;
   linei[1].color = sf::Color::Red;
	for(int i=0;i<newPlan.size();i++){
		sv=fFront.getSize().y-(((newPlan[i]+1)/2)*fFront.getSize().y);
		linei[0].position = sf::Vector2f(fRect.getPosition().x+fRect.getPosition().x,fRect.getPosition().y+(sv*ratioY));
   	linei[1].position = sf::Vector2f(fFront.getPosition().x+fFront.getSize().x,sv+20);
   	winCreate.draw(linei);
   	linei[0].position = sf::Vector2f(fRect.getPosition().x,fRect.getPosition().y+(sv*ratioY));
   	linei[1].position = sf::Vector2f(fRect.getPosition().x+fRect.getSize().x,fRect.getPosition().y+(sv*ratioY));
   	winCreate.draw(linei);
   	linei[0].position = sf::Vector2f(fRect.getPosition().x,fRect.getPosition().y+(sv*ratioY));
   	linei[1].position = sf::Vector2f(fFront.getPosition().x,sv+20);
   	winCreate.draw(linei);
	}
	for(int i=0;i<newBoxPlan.size();i++){
		nbox.setPosition(sf::Vector2f(newBoxPlan[i].x*scaleX,newBoxPlan[i].y*scaleY));
		winCreate.draw(nbox);
		adr << std::fixed<< std::setprecision(3)<<newPlan[i];
      string s=adr.str();
      txtBoxvalue.setString(s);
	   txtBoxvalue.setPosition(((newBoxPlan[i].x+48)*scaleX)-txtBoxvalue.getLocalBounds().width-2,(newBoxPlan[i].y+2)*scaleY);
	   winCreate.draw(txtBoxvalue);
	   adr.clear();
      adr.str(""); 
	}
}
void speakerDraw(){
	float cx;
	float cy;
	for(int i=0;i<tabSpeaker.size();i++){
		if(tabSpeaker[i].z==planActif){
			cx=fPlani.getPosition().x+(fPlani.getSize().x*((tabSpeaker[i].x+1)/2));
			cy=fPlani.getPosition().y+(fPlani.getSize().y*((tabSpeaker[i].y+1)/2));
			speaker.setPosition(sf::Vector2f(cx,cy));
			winCreate.draw(speaker);
			if(curSelect==i){
				selectSpeaker.setPosition(sf::Vector2f(cx,cy));
				winCreate.draw(selectSpeaker);
			}
		}
	}
}
void tableauDraw(){
	winCreate.draw(sTableau);
	winCreate.draw(sTableau2);
	winCreate.draw(titreTableau);
	for(int j=0;j<13;j++){
			for(int i=0;i<2;i++){
				sTableau5.setPosition(sf::Vector2f(754+(i*32),529+(j*24)));
				winCreate.draw(sTableau5);
			}
			for(int i=0;i<3;i++){
				sTableau4.setPosition(sf::Vector2f(818+(i*58),529+(j*24)));
				winCreate.draw(sTableau4);
			}
	}
	winCreate.draw(tableauS);
	triTop.setPosition(sf::Vector2f(776, 532));
	triBot.setPosition(sf::Vector2f(776, 542));
	winCreate.draw(triTop);
	winCreate.draw(triBot);
	winCreate.draw(tableauC);
	triTop.setPosition(sf::Vector2f(810, 532));
	triBot.setPosition(sf::Vector2f(810, 542));
	winCreate.draw(triTop);
	winCreate.draw(triBot);
	winCreate.draw(tableauX);
	winCreate.draw(tableauY);
	winCreate.draw(tableauZ);

	winCreate.draw(sTableauFslider);
	winCreate.draw(sTableauSlider);
	triTop.setPosition(sf::Vector2f(920, 532));
	triBot.setPosition(sf::Vector2f(920, 542));
	winCreate.draw(triTop);
	winCreate.draw(triBot);
}
void tableauDrawValue(){
	stringstream adr;
	string s="";
	tableauValue.setString(s);
	for(int i=0;i<12;i++){
		tableauValue.setPosition(782-tableauValue.getLocalBounds().width-2,556+(i*24));
		tableauValue.setPosition(814-tableauValue.getLocalBounds().width-2,556+(i*24));
		tableauValue.setPosition(990-tableauValue.getLocalBounds().width-2,556+(i*24));
		tableauValue.setPosition(872-tableauValue.getLocalBounds().width-2,556+(i*24));
		tableauValue.setPosition(930-tableauValue.getLocalBounds().width-2,556+(i*24));
	}
	if(tabSpeaker.size()>0){
		for(int i=0;i<12;i++){
			if(i+offsetTableau<tabSpeaker.size()){
		      s=to_string(tabSpeaker[i+offsetTableau].sortie);
		      tableauValue.setString(s);
			   tableauValue.setPosition(782-tableauValue.getLocalBounds().width-2,556+(i*24));
			   if(curSelect==i+offsetTableau){
			   	tableauValue.setFillColor(sf::Color(255,0,0,255));
			   }else{
					tableauValue.setFillColor(sf::Color(0,0,0,255));
				}
			   winCreate.draw(tableauValue);
		      s=to_string(tabSpeaker[i+offsetTableau].canal);
		      tableauValue.setString(s);
			   tableauValue.setPosition(814-tableauValue.getLocalBounds().width-2,556+(i*24));
			   if(curSelect==i+offsetTableau){
			   	tableauValue.setFillColor(sf::Color(255,0,0,255));
			   }else{
					tableauValue.setFillColor(sf::Color(0,0,0,255));
				}
			   winCreate.draw(tableauValue);
		
				adr << std::fixed<< std::setprecision(3)<<tabSpeaker[i+offsetTableau].x;
		      s=adr.str();
		      tableauValue.setString(s);
			   tableauValue.setPosition(990-tableauValue.getLocalBounds().width-2,556+(i*24));
			   if(curSelect==i+offsetTableau){
			   	tableauValue.setFillColor(sf::Color(255,0,0,255));
			   }else{
					tableauValue.setFillColor(sf::Color(0,0,0,255));
				}
			   winCreate.draw(tableauValue);
			   adr.clear();
		      adr.str("");
		      adr << std::fixed<< std::setprecision(3)<<tabSpeaker[i+offsetTableau].y;
		      s=adr.str();
		      tableauValue.setString(s);
			   tableauValue.setPosition(872-tableauValue.getLocalBounds().width-2,556+(i*24));
			   if(curSelect==i+offsetTableau){
			   	tableauValue.setFillColor(sf::Color(255,0,0,255));
			   }else{
					tableauValue.setFillColor(sf::Color(0,0,0,255));
				}
			   winCreate.draw(tableauValue);
			   adr.clear();
		      adr.str("");
		      adr << std::fixed<< std::setprecision(3)<<tabSpeaker[i+offsetTableau].z;
		      s=adr.str();
		      tableauValue.setString(s);
			   tableauValue.setPosition(930-tableauValue.getLocalBounds().width-2,556+(i*24));
			   if(curSelect==i+offsetTableau){
			   	tableauValue.setFillColor(sf::Color(255,0,0,255));
			   }else{
					tableauValue.setFillColor(sf::Color(0,0,0,255));
				}
			   winCreate.draw(tableauValue);
			   adr.clear();
		      adr.str("");
		
			}
		}
	}
}
void tableauTxtS(sf::Event e){
	int key=e.key.code;
   stringstream adr;
   string s;
   if (e.text.unicode < 128){
   	switch (key){
		 	case 8:
	      	apptxt=apptxt.substr(0,apptxt.length()-1);
	      	break;
	      case 58:
	      	apptxt=apptxt.substr(0,apptxt.length()-1);
	      	std::cout << " key " << key<< std::endl;
	      	break;
	      break;
	 	   default :
				apptxt=apptxt+static_cast<char>(e.text.unicode);
				flagTxt=1;
				break;
		}
      switch (tabType){
      	case 0:
      		s=apptxt;
      		if(tabSpeaker.size()>tabId){
      			tabSpeaker[tabId].sortie=stoi(s);
      		}
      		break;
      	case 1:
      		s=apptxt;
      		if(tabSpeaker.size()>tabId){
      			tabSpeaker[tabId].canal=stoi(s);
      		}
      		break;
      	case 2:
      		s=apptxt;
      		if(apptxt!=""){
      			newFile.setString(s);
      			newFile.setPosition(736-newFile.getLocalBounds().width-2,512);
      		}
      		break;
      	default:
      		break;
      }
   }
}
void tableauRenumS(int debut){
	int ct;
	if(tabSpeaker.size()>1){
		ct=tabSpeaker[debut].sortie+1;
		std::cout << " ct " << ct << " " <<tabSpeaker[debut].sortie<< " " <<tabSpeaker[0].sortie<< std::endl;
		for(int i=debut+1;i<tabSpeaker.size();i++){
			if(tabSpeaker[i].sortie!=0){
				tabSpeaker[i].sortie=ct;
				ct=ct+1;
			}
		}
	}
}
void tableauRenumC(int debut){
	int ct;
	if(tabSpeaker.size()>1){
		ct=tabSpeaker[debut].canal+1;
		for(int i=debut+1;i<tabSpeaker.size();i++){
			tabSpeaker[i].canal=ct;
			ct=ct+1;
		}
	}
}

bool comparared(const nSpeaker lhs, const nSpeaker rhs) {
  return lhs.z > rhs.z;
}
void triTableauZd(){
	std::sort(tabSpeaker.begin(), tabSpeaker.end(), comparared);

}
bool comparares(const nSpeaker lhs, const nSpeaker rhs) {
  return lhs.z < rhs.z;
}
void triTableauZs(){
	std::sort(tabSpeaker.begin(), tabSpeaker.end(), comparares);
}
bool comparareSorta(const nSpeaker lhs, const nSpeaker rhs) {
  return lhs.sortie > rhs.sortie;
}
void triTableauSd(){
	std::sort(tabSpeaker.begin(), tabSpeaker.end(), comparareSorta);
}
bool comparareSortd(const nSpeaker lhs, const nSpeaker rhs) {
  return lhs.sortie < rhs.sortie;
}
void triTableauSa(){
	std::sort(tabSpeaker.begin(), tabSpeaker.end(), comparareSortd);
}
bool comparareCanala(const nSpeaker lhs, const nSpeaker rhs) {
  return lhs.canal > rhs.canal;
}
void triTableauCd(){
	std::sort(tabSpeaker.begin(), tabSpeaker.end(), comparareCanala);
}
bool comparareCanald(const nSpeaker lhs, const nSpeaker rhs) {
  return lhs.canal < rhs.canal;
}
void triTableauCa(){
	std::sort(tabSpeaker.begin(), tabSpeaker.end(), comparareCanald);
}

void studioDraw2(){
	float lscale;
	float cx1;
	float cy1;
	for(int i=0;i<tabSpeaker.size();i++){
		if(tabSpeaker[i].x>0.33){
			lscale=0.33;
		}else{
			lscale=(1-tabSpeaker[i].x)/2;
		}
		if(tabSpeaker[i].y>0){
			cx1=(tabSpeaker[i].y*lscale*263)+(263-(40*lscale));
		}else{
			cx1=(tabSpeaker[i].y*lscale*263)+(283-(40*lscale));
		}
		if(tabSpeaker[i].z<0){
			cy1=644-(tabSpeaker[i].z*190*lscale);
		}else{
			cy1=644-(tabSpeaker[i].z*190*lscale);
		}
		pSpeaker.setPosition(sf::Vector2f(cx1,cy1));
		pSpeaker.setScale(lscale,lscale);
		if(flagAll==1){
			winCreate.draw(pSpeaker);
		}else{
			if(tabSpeaker[i].z==planActif){
				winCreate.draw(pSpeaker);
			}
		}
		
	}
}

void studioDraw(){
	float lscale;//0.33
	float cx1;
	float cy1;
	for(int i=0;i<tabSpeaker.size();i++){
		
		lscale=(1-tabSpeaker[i].x)/2;
		cx1=263+((176*tabSpeaker[i].y*lscale)+(87*tabSpeaker[i].y));
		cy1=644-((tabSpeaker[i].z*60*lscale)+(65*tabSpeaker[i].z));

		pSpeaker.setPosition(sf::Vector2f(cx1,cy1));
		pSpeaker.setScale(lscale+0.2,lscale+0.2);
		if(flagAll==1){
			winCreate.draw(pSpeaker);
		}else{
			if(tabSpeaker[i].z==planActif){
				winCreate.draw(pSpeaker);
			}
		}
		
	}
}

void saveSpace(){
	stringstream adr;
	string path=getcwd(NULL,0);
	fileSelector.initSelector(path);
	nameFile=fileSelector.selector();

   string wfile=fileSelector.getPath()+"/"+boost::filesystem::basename(nameFile)+".dst";
	newFile.setString(boost::filesystem::basename(nameFile));
   newFile.setPosition(736-newFile.getLocalBounds().width-2,512);
	std::cout << "file :"<<wfile<< std::endl;
	
	if(nameFile!=""){
		ofstream fichier(wfile, ios::out | ios::trunc);
		if(fichier){
			for(int i=0;i<tabSpeaker.size();i++){
				fichier<<tabSpeaker[i].sortie<<","<<tabSpeaker[i].canal<<","<<tabSpeaker[i].x<<","<<tabSpeaker[i].y<<","<<tabSpeaker[i].z<<","<< endl;
		   }
	   }else{  // sinon
     		cerr << "Erreur à l'ouverture du fichier!" << endl;
		}
	   fichier.close();
   }
   
   saveTableauHtml();
}
void saveTableauHtml(){
stringstream adr;
	string sx="";
	string sy="";
	string sz="";

	string wfile=fileSelector.getPath()+"/"+boost::filesystem::basename(nameFile)+".html";
	std::cout << "file :"<<wfile<< std::endl;
	if(nameFile!=""){
		ofstream fichier(wfile, ios::out | ios::trunc);
		if(fichier){
			fichier<<"<table border=\"1\" align=\"center\" cellpadding=\"10\" cellspacing=\"0\" style=\"background-color:#ffffff;\">"<< endl;
			fichier<<"<body>"<< endl;
			fichier<<"<tr>"<< endl;
			fichier<<"<td colspan=\"2\"><td colspan=\"3\" style=\"text-align:center;\">Coord.Cartésiennes</td>\n";
			fichier<<"</tr>"<< endl;
			fichier<<"<tr>"<< endl;
			fichier<<"<td style=\"text-align:center;\">Sorties</td><td style=\"text-align:center;\">Canal</td><td style=\"text-align:center;\">X</td><td style=\"text-align:center;\">Y</td><td style=\"text-align:center;\">Z</td>\n";
			fichier<<"</tr>"<< endl;
			for(int i=0;i<tabSpeaker.size();i++){
				adr << std::fixed<< std::setprecision(3)<<tabSpeaker[i+offsetTableau].x;
		      sx=adr.str();
		      adr.clear();
		      adr.str("");
		      adr << std::fixed<< std::setprecision(3)<<tabSpeaker[i+offsetTableau].y;
		      sy=adr.str();
		      adr.clear();
		      adr.str("");
		      adr << std::fixed<< std::setprecision(3)<<tabSpeaker[i+offsetTableau].z;
		      sz=adr.str();
		      adr.clear();
		      adr.str("");
				fichier<<"<tr>"<< endl;
				fichier<<"<td style=\"text-align:right;\">"<<tabSpeaker[i].sortie<<"</td><td style=\"text-align:right;\">"<<tabSpeaker[i].canal<<"</td><td style=\"text-align:right;\">"<<sy<<"</td><td style=\"text-align:right;\">"<<sz<<"</td><td style=\"text-align:right;\">"<<sx<<"</td>"<< endl;
				fichier<<"</tr>"<< endl;
		   }
		   fichier<<"</body>"<< endl;
		   fichier<<"</table>"<< endl;
	   }else{  // sinon
     		cerr << "Erreur à l'ouverture du fichier!" << endl;
		}
	   fichier.close();
   }
}
void loadSpace(){
	stringstream adr;
	std::string::size_type sz;
	string contenu;
	size_t pos = 0;
	std::string token[5];
	std::string delimiter = ",";
	nSpeaker nsp;
	tabSpeaker.clear(); 	
	newPlan.clear();
	newBoxPlan.clear();
	tabSpeaker.clear();

	string path=getcwd(NULL,0);
	fileSelector.initSelector(path);
	nameFile=fileSelector.selector();	
	
	string wfile=fileSelector.getPath()+"/"+nameFile;
	std::cout << "file :"<<wfile<< std::endl;
   newFile.setString(boost::filesystem::basename(nameFile));
   newFile.setPosition(736-newFile.getLocalBounds().width-2,512);
	int i=0;
	std::cout << "file :"<<wfile<< std::endl;
	if(nameFile!=""){
		ifstream fichier(wfile, ios::in);
		if(fichier){
			while(getline(fichier, contenu)){
				std::cout << "ligne :"<<contenu<< std::endl;
				while ((pos = contenu.find(delimiter)) != std::string::npos) {
    				token[i] = contenu.substr(0, pos);
    				std::cout << token[i] << std::endl;
    				i++;
    				contenu.erase(0, pos + delimiter.length());
				}
				i=0;
				nsp.sortie=stoi(token[0]);
				nsp.canal=stoi(token[1]);
				nsp.x=stof(token[2],&sz);
				nsp.y=stof(token[3]);
				nsp.z=stof(token[4]);
				tabSpeaker.push_back(nsp);
				if(nsp.z!=planActif){
					txtCvalue.setString(token[1]);
					curseurV.setPosition(530,20+(410*((1-nsp.z)/2)));
					newBoxPlan.push_back(sf::Vector2f(550,curseurV.getPosition().y));
					rightRed.setPosition(sf::Vector2f(615,curseurV.getPosition().y));
					newPlan.push_back(nsp.z);
					planActif=nsp.z;
					std::cout << "nsp.z :"<<nsp.z<< std::endl;
				}
				//defPlan();
			}
	   }else{  // sinon
     		cerr << "Erreur à l'ouverture du fichier!" << endl;
		}
	   fichier.close();
   }
   
}
void saveDSP(){
	stringstream adr;
	string s;
	string s2;
	float d;
	string path=getcwd(NULL,0);
	fileSelector.initSelector(path);
	nameFile=fileSelector.selector();

   string wfile=fileSelector.getPath()+"/"+nameFile;
	
	std::cout << "file :"<<wfile<< std::endl;

	string prog;
	prog=prog+"declare name        \"objMatrix"+nameFile+"\"; // modifier le nom de votre greffon\n";
   prog=prog+"declare version     \"1.0\";\n";
   prog=prog+"declare author      \"D.Blanchemain\";\n";
   prog=prog+"declare license     \"BSD\";\n";
   prog=prog+"declare copyright   \"(c)D.Blanchemain 2020\";\n";
   prog=prog+"import(\"stdfaust.lib\");\n";

	prog=prog+"Matrix(N,M) =_:filters(1):delay:freeverb(1)<: par(out, M, *(Fader(1,out): si.smoo)) :> par(out, M, _)\n";

	prog=prog+"with {\n";
	int j=0;
	for(int i=0;i<tabSpeaker.size();i++){
		if(tabSpeaker[i].sortie!=0){
			s2=to_string(j);
			adr << std::fixed<< std::setprecision(3)<<tabSpeaker[i].y;
			s=adr.str();
			adr.clear();
			adr.str("");
			prog=prog+"tabSpeakerX("+s2+")="+s+";\n";
			adr << std::fixed<< std::setprecision(3)<<tabSpeaker[i].z;
			s=adr.str();
			adr.clear();
			adr.str("");
			prog=prog+"tabSpeakerY("+s2+")="+s+";\n";
			adr << std::fixed<< std::setprecision(3)<<tabSpeaker[i].x;
			s=adr.str();
			adr.clear();
			adr.str("");
			prog=prog+"tabSpeakerZ("+s2+")="+s+";\n";
			d=sqrt((tabSpeaker[i].x*tabSpeaker[i].x)+(tabSpeaker[i].y*tabSpeaker[i].y)+(tabSpeaker[i].z*tabSpeaker[i].z));
			adr << std::fixed<< std::setprecision(3)<<d;
			s=adr.str();
			prog=prog+"tabSpeakerD("+s2+")="+s+";\n";
			adr.clear();
			adr.str("");
			j++;
		}
	}
	prog=prog+"dtencGen(in, out) = sqrt(pow(tabSpeakerX(out)-x(in),2) + pow(tabSpeakerY(out)+y(in),2) + pow(tabSpeakerZ(out)-z(in),2));\n";

   prog=prog+"dgain(in, out) = ba.db2linear((-50/tabSpeakerD(out))*dtencGen(in,out));\n";
    
   prog=prog+"x(i) = hslider(\"/X%i\",0,-1,1,0.01);\n";

   prog=prog+"y(i) = hslider(\"/Y%i\",0,-1,1,0.01);\n";

   prog=prog+"z(i) = hslider(\"/Z%i\",0,-1,1,0.01);\n";

   prog=prog+"Fader(in,out)= vgroup(\"[1]Input %2in\",dgain(in,out));\n";

   prog=prog+"cdistance(in)=sqrt(pow(0-x(in),2) + pow(0+y(in),2) + pow(0-z(in),2));\n";

   prog=prog+"paramDistance(x)=hgroup(\"[2]Distance\",x);\n";
   prog=prog+"//-----------------------------------------------------------\n";
   prog=prog+"//                   LPF \n";
   prog=prog+"//-----------------------------------------------------------\n";
	prog=prog+"minfreq=paramDistance(vslider(\"LPF Min\",100, 20, 2000, 1));\n";
   prog=prog+"ampfreq=paramDistance(vslider(\"LPF Amp\",5000, 20, 19980, 1));\n";
   prog=prog+"rpf(in)=minfreq+(ampfreq*min(1,cdistance(in))):floor;\n";
   prog=prog+"LPF(in)=fi.lowpass(3,rpf(in));\n";

   prog=prog+"fbp = checkbox(\"[0] Bypass  [tooltip: When this is checked, the filters has no effect]\");\n";
   prog=prog+"filters(in)=paramDistance(vgroup(\"FILTERS\",ba.bypass1(fbp,hgroup(\"[1]\",LPF(in)))));\n";
   prog=prog+"//-----------------------------------------------------------\n";
   prog=prog+"//                  Delay\n";
   prog=prog+"//-----------------------------------------------------------\n";
   prog=prog+"delay_group(x) = paramDistance(vgroup(\"[2]DELAY\", x));\n";

	prog=prog+"cbp =delay_group(vgroup(\"[0]\",checkbox(\"Bypass	[tooltip: When this is checked, Delay has no effect]\")));\n";
	prog=prog+"voice   = delay_group(vgroup(\"[1]\",(+ : de.sdelay(N, interp, dtime)) ~ *(fback)));\n";
	prog=prog+"N = int(2^19);\n"; 
	prog=prog+"interp  = hslider(\"interpolation[unit:ms][style:knob]\",10,1,100,0.1)*ma.SR/1000.0;\n";
   prog=prog+"maxtime = hslider(\"maxtime[style:knob]\",100,0,5000,0.1);\n";
	prog=prog+"fback = hslider(\"feedback[style:knob]\",0,0,100,0.1)/100.0;\n";
   prog=prog+"dtime = maxtime-(maxtime*min(1,cdistance(1))*ma.SR/1000.0);\n";
   prog=prog+"delay = ba.bypass1(cbp,voice);\n";
	prog=prog+"//-----------------------------------------------------------\n";
   prog=prog+"//                 Freeverb\n";
   prog=prog+"//-----------------------------------------------------------\n";

	prog=prog+"scaleroom   = 0.28;\n";
	prog=prog+"offsetroom  = 0.7;\n";
	prog=prog+"allpassfeed = 0.5;\n";
	prog=prog+"scaledamp   = 0.4;\n";
	prog=prog+"fixedgain   = 0.1;\n";
	prog=prog+"origSR = 48000;\n";

	prog=prog+"g=1-((1/1.73205)*min(1.73205,cdistance(1)));\n";
	prog=prog+"freeverbMono=_<: (*(g)*fixedgain :re.mono_freeverb(combfeed, allpassfeed, damping, spatSpread)),*(1-g):> _;\n";
	prog=prog+"parameters(x) = paramDistance(hgroup(\"[3]Freeverb\",x));\n";
	
	prog=prog+"knobGroup(x) = parameters(vgroup(\"[1]\",x));\n";
	prog=prog+"fvbp = knobGroup(checkbox(\"[0] Bypass	[tooltip: When this is checked, the freeverb	has no effect]\"));\n";
	prog=prog+"damping = knobGroup(vslider(\"[1] Damp [style: knob] [tooltip: Somehow control the density of the reverb.]\",0.5, 0, 1, 0.025)*scaledamp*origSR/ma.SR);\n";
	prog=prog+"combfeed = knobGroup(vslider(\"[2] RoomSize [style: knob] [tooltip: The room size	between 0 and 1 with 1 for the largest room.]\", 0.5, 0, 1, 0.025)*scaleroom*origSR/ma.SR + offsetroom);\n";
	prog=prog+"spatSpread = knobGroup(vslider(\"[3] Stereo Spread [style: knob] [tooltip: Spatial spread between 0 and 1 with 1 for maximum spread.]\",0.5,0,1,0.01)*46*ma.SR/origSR: int);\n";
	prog=prog+"freeverb(in) = ba.bypass1(fvbp,freeverbMono);\n";

	prog=prog+"};\n";
	prog=prog+"process = Matrix(1,"+to_string(j)+"); // le deuxième chiffre permet de définir la dimension de votre espace :9,10, ...\n";

	if(nameFile!=""){
		ofstream fichier(wfile, ios::out | ios::trunc);
		if(fichier){
			fichier<<prog<< endl;
		}else{  // sinon
     		cerr << "Erreur à l'ouverture du fichier!" << endl;
		}
	   fichier.close();
	}

}
//****************************************************************************************************
//              fenêtre 3d
//****************************************************************************************************
void init3D(){
w3WxScale=1;
w3HyScale=1;

win3D.setVerticalSyncEnabled(true);
win3D.setActive(true);
bool running = true;
glEnable(GL_TEXTURE_2D);           // Texture GL
glShadeModel(GL_SMOOTH);
glEnable(GL_DEPTH_TEST);
glDepthMask(GL_TRUE);
glMatrixMode( GL_PROJECTION );
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
GLfloat color[] = { 1.0f, 1.0f, 1.0f, 1.0f };
glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, color);
glClearDepth(1.0f);
glDepthFunc(GL_LEQUAL);

//glEnable(GL_BLEND);					 // Transparence
//glBlendFunc(GL_SRC_ALPHA,GL_ONE);
glEnable(GL_COLOR_MATERIAL);

glLoadIdentity();
    
glOrtho(1.7f,-1.7f,-1.7f,1.7f, 10, -100);  // Projection orthographique

sf::Vector2i localPosition = sf::Mouse::getPosition(win3D);
oldX=localPosition.x;
oldY=localPosition.y;

quadratic=gluNewQuadric();
gluQuadricNormals(quadratic, GLU_SMOOTH);     // Quadratic
gluQuadricTexture(quadratic, GL_TRUE);   
gluQuadricDrawStyle(quadratic,GLU_FILL);
    
glMatrixMode( GL_MODELVIEW );

Theta=52.5;
Phi=-40.5;
rxquad = cos(Theta*M_PI/180);
ryquad = sin(Phi*M_PI/180);
rzquad = sin(Theta*M_PI/180);
}
void drawMur(float echX, float echY){
	 glPushMatrix();																	// Construction du repère 3D
    glScalef(echX,echY,echX);
    glTranslatef(tx,ty,0);
    glBegin(GL_QUADS);
    glColor4f(255,255,0,0.4); // face jaune
    glTexCoord2f(0.0f, 0.0f);
    glVertex3d(-1,1,1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3d(-1,1,-1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3d(-1,-1,-1);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3d(-1,-1,1);

    glColor4f(0,255,255,0.4); // face cyan
    glTexCoord2f(0.0f, 0.0f);
    glVertex3d(1,1,1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3d(1,-1,1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3d(-1,-1,1);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3d(-1,1,1);
    
    glColor4f(0,255,0,0.4); // face verte
    glTexCoord2f(0.0f, 0.0f);
    glVertex3d(-1,-1,1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3d(-1,-1,-1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3d(1,-1,-1);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3d(1,-1,1);
 
    glEnd();
    
    glPopMatrix();
}
void drawSprite(){	
	glColor4f(1,1,1,1);
	if(flagAll==0){
		for(int i=0;i<tabSpeaker.size();i++){
			if(tabSpeaker[i].z==planActif){
		  	  	glPushMatrix();
		  	 	sf::Texture::bind(&imageF5);
		  		glTranslatef(-(tabSpeaker[i].y+ty+0.18)*w3HyScale,(tabSpeaker[i].z*w3WxScale),(tabSpeaker[i].x+tx+0.14)*w3WxScale); 
		  	 	gluSphere(quadratic,0.04,32,32);
		  	 	sf::Texture::bind(NULL);
		  	 	glPopMatrix();
	  	 	}
	  	 }
  	}else{
  	 	for(int i=0;i<tabSpeaker.size();i++){
  	 		glPushMatrix();
	  	 	sf::Texture::bind(&imageF5);
	  		glTranslatef(-(tabSpeaker[i].y+ty+0.18)*w3HyScale,(tabSpeaker[i].z*w3WxScale),(tabSpeaker[i].x+tx+0.14)*w3WxScale); 
	  	 	gluSphere(quadratic,0.04,32,32);
	  	 	sf::Texture::bind(NULL);
	  	 	glPopMatrix();
  	 	}
   }
}
void onButtonPressed3(){
  if(win3D.hasFocus()){
  sf::Vector2i position = sf::Mouse::getPosition(win3D);                       // Rotation avec la Sphère
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		std::cout << "buttonPressed 3D mouse x: " << position.x << std::endl;
      std::cout << "mouse y: " << position.y << std::endl;
		if(position.x>48*w3WxScale && position.x<58*w3WxScale && position.y>630*w3HyScale && position.y<650*w3HyScale){
		  Phi+=0.5;
		  if (Phi > 40){
         	Phi = 40;
        }
	   }
		if(position.x>48*w3WxScale && position.x<58*w3WxScale && position.y>686*w3HyScale && position.y<702*w3HyScale){
			Phi-=0.5;
    		if (Phi < -90){
        		Phi = -90;
        	}	 
		}
		if(position.x>70*w3WxScale && position.x<90*w3WxScale && position.y>652*w3HyScale && position.y<672*w3HyScale){
		  Theta-=0.5;
		  if (Theta<0.0){
         	Theta = 0.0;
        }
		}
		if(position.x>20*w3WxScale && position.x<40*w3WxScale && position.y>652*w3HyScale && position.y<672*w3HyScale){
		  Theta+=0.5;
		  if (Theta >160.0){
         	Theta = 160.0; 
        }
		}
		if(position.x>20*w3WxScale && position.x<40*w3WxScale && position.y>740*w3HyScale && position.y<750*w3HyScale){
		  tx+=0.01;
		  sTx=sTx+0.1;
		  //std::cout << "tx: " << tx << std::endl;
	   }
	   if(position.x>70*w3WxScale && position.x<90*w3WxScale && position.y>740*w3HyScale && position.y<750*w3HyScale){
		  tx-=0.01;
		  sTx=sTx-0.1;
		  //std::cout << "tx: " << tx << std::endl;
	   }
	   if(position.x>48*w3WxScale && position.x<58*w3WxScale && position.y>712*w3HyScale && position.y<724*w3HyScale){
		  ty+=0.01;
		  sTy=sTy+0.5;
		  //std::cout << "ty: " << ty << std::endl;
	   }
	   if(position.x>48*w3WxScale && position.x<58*w3WxScale && position.y>762*w3HyScale && position.y<784*w3HyScale){
		  ty-=0.01;
		  sTy=sTy-0.5;
		  //std::cout << "ty: " << ty << std::endl;
	   }
		rxquad = cos(Theta*M_PI/180);
      ryquad = sin(Phi*M_PI/180);
      rzquad = sin(Theta*M_PI/180);
    }
  }
}
void onMouseMove3(sf::Event e){  
std::cout << "Window 3D mouse x: " << e.mouseMove.x << std::endl;
   std::cout << "mouse y: " << e.mouseMove.y << std::endl;                    
	  if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
	   	if(e.mouseMove.x<oldX){
	   			Theta+=0.5;
			  		if (Theta<0.0){
	         		Theta = 0.0;										// Rotation avec la souris
	       		 }
	   	}else{
	   		   Theta-=0.5;
			  		if (Theta >180.0){
	         		Theta = 180.0; 
	        		}
	   	}
	   	if(e.mouseMove.y<oldY){
	   			Phi+=0.5;
			  		if (Phi > 40){
	         		Phi = 40;
	       		 }
	   	}else{
	   			Phi-=0.5;
	    			if (Phi < -120){
	        			Phi = -120;
	        		}	
	   	}
	   }
	   rxquad = cos(Theta*M_PI/180);
	   ryquad = sin(Phi*M_PI/180);
	   rzquad = sin(Theta*M_PI/180);
   oldX=e.mouseMove.x;
   oldY=e.mouseMove.y;
}
