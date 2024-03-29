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
#include <lo/lo.h>
#include <lo/lo_cpp.h>
#include <atomic>
#include <boost/filesystem.hpp>

#include <GL/gl.h>
#include <GL/glu.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "multiSpace3D.h"

using namespace std;

int main(int argc, char* argv[]){

std::stringstream adr;
adr << std::fixed << argv[1]<<"/gui/";
defInstall=argv[1];
home=argv[2];
defGui=adr.str();
pref=home+"/.config/multiSpace3D";
readParam();
adr.clear();
adr.str("");
adr << std::fixed << argv[1]<<"/gui";
fileSelector.setSelectorGui(adr.str());
fileSelector.setSelectorTheme(defInstall+"/Themes/base");
fileSelector.setTitreSelector(L"Sélecteur de fichier");

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
defautGroupe=0;
defautTrack=1;
defautR=0.04;
objActif=65536;
flagFileMode=0;
/*
prefDAW=0;
prefServeur="localhost";
prefPortD=3819;
*/
objMove=0;
flagDistance=0;
flagTxt=0;

sf::Texture genimg1;
adr << std::fixed << defGui<<"g7002.png";
if (!genimg1.loadFromFile(adr.str()))
  return EXIT_FAILURE; 
tabTexture[0]=genimg1;
sf::Sprite spgen1(genimg1);
adr.clear();
adr.str("");
sf::Texture genimg2;
adr << std::fixed << defGui<<"g4813.png"; 
if (!genimg2.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[1]=genimg2;
sf::Sprite spgen2(genimg2);
adr.clear();
adr.str("");
sf::Texture genimg3;
adr << std::fixed << defGui<<"g7012.png";
if (!genimg3.loadFromFile(adr.str()))
     return EXIT_FAILURE;
tabTexture[2]=genimg3;
sf::Sprite spgen3(genimg3);
adr.clear();
adr.str("");
sf::Texture genimg4;
adr << std::fixed << defGui<<"g7022.png";
if (!genimg4.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[3]=genimg4;
sf::Sprite spgen4(genimg4);
adr.clear();
adr.str("");
sf::Texture genimg5;
adr << std::fixed << defGui<<"g7010.png";
 if (!genimg5.loadFromFile(adr.str()))
     return EXIT_FAILURE;
tabTexture[4]=genimg5;
sf::Sprite spgen5(genimg5);
adr.clear();
adr.str("");
sf::Texture genimg6;
adr << std::fixed << defGui<<"g7004.png";
if (!genimg6.loadFromFile(adr.str()))
     return EXIT_FAILURE;
tabTexture[5]=genimg6;
sf::Sprite spgen6(genimg6);
adr.clear();
adr.str("");
sf::Texture genimg7;
adr << std::fixed << defGui<<"g7017.png";
 if (!genimg7.loadFromFile(adr.str()))
     return EXIT_FAILURE;
tabTexture[6]=genimg7;
sf::Sprite spgen7(genimg7);
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"g7016.png";
sf::Texture genimg8;
if (!genimg8.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[7]=genimg8;
adr.clear();
adr.str("");
sf::Sprite spgen8(genimg8);
adr << std::fixed << defGui<<"g4794.png";
sf::Texture genimg9;
if (!genimg9.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[8]=genimg9;
sf::Sprite spgen9(genimg9);
adr.clear();
adr.str("");
sf::Texture genimg10;
adr << std::fixed << defGui<<"g7013.png";
if (!genimg10.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[9]=genimg10;
sf::Sprite spgen10(genimg10);
adr.clear();
adr.str("");
sf::Texture genimg11;
adr << std::fixed << defGui<<"g4894c.png";
if (!genimg11.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[10]=genimg11;
sf::Sprite spgen11(genimg11);
adr.clear();
adr.str("");
sf::Texture genimg12;
adr << std::fixed << defGui<<"g7009.png";
if (!genimg12.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[11]=genimg12;
sf::Sprite spgen12(genimg12);
adr.clear();
adr.str("");
sf::Texture genimg13;
adr << std::fixed << defGui<<"g7006.png";
if (!genimg13.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[12]=genimg13;
sf::Sprite spgen13(genimg13);
adr.clear();
adr.str("");
sf::Texture genimg14;
adr << std::fixed << defGui<<"g7019.png"; 
if (!genimg14.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[13]=genimg14;
sf::Sprite spgen14(genimg14);
adr.clear();
adr.str("");
sf::Texture genimg15;
adr << std::fixed << defGui<<"g7018.png";
if (!genimg15.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[14]=genimg15;
sf::Sprite spgen15(genimg15);
adr.clear();
adr.str("");
sf::Texture genimg16;
adr << std::fixed << defGui<<"g7014.png";
if (!genimg16.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[15]=genimg16;
sf::Sprite spgen16(genimg16);
adr.clear();
adr.str("");
sf::Texture genimg17;
adr << std::fixed << defGui<<"g6928.png";
if (!genimg17.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[16]=genimg17;
sf::Sprite spgen17(genimg17);
adr.clear();
adr.str("");
sf::Texture genimg18;
adr << std::fixed << defGui<<"g7003.png";
if (!genimg18.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[17]=genimg18;
sf::Sprite spgen18(genimg18);
adr.clear();
adr.str("");
sf::Texture genimg19;
adr << std::fixed << defGui<<"g5074.png";
if (!genimg19.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[18]=genimg19;
sf::Sprite spgen19(genimg19);
adr.clear();
adr.str("");
sf::Texture genimg20;
adr << std::fixed << defGui<<"g7011.png";
if (!genimg20.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[19]=genimg20;
sf::Sprite spgen20(genimg20);
adr.clear();
adr.str("");
sf::Texture genimg21;
adr << std::fixed << defGui<<"g7007.png";
if (!genimg21.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[20]=genimg21;
sf::Sprite spgen21(genimg21);
adr.clear();
adr.str("");
sf::Texture genimg22;
adr << std::fixed << defGui<<"g7023.png";
if (!genimg22.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[21]=genimg22;
sf::Sprite spgen22(genimg22);
adr.clear();
adr.str("");
sf::Texture genimg23;
adr << std::fixed << defGui<<"g7021.png";
if (!genimg23.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[22]=genimg23;
sf::Sprite spgen23(genimg23);
adr.clear();
adr.str("");
sf::Texture genimg24;
adr << std::fixed << defGui<<"g5074.png";
if (!genimg24.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[23]=genimg24;
sf::Sprite spgen24(genimg24);
adr.clear();
adr.str("");
sf::Texture genimg25;
adr << std::fixed << defGui<<"g7005.png";
if (!genimg25.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[24]=genimg25;
sf::Sprite spgen25(genimg25);
adr.clear();
adr.str("");
sf::Texture genimg26;
adr << std::fixed << defGui<<"g5100.png";
if (!genimg26.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[25]=genimg26;
sf::Sprite spgen26(genimg26);
adr.clear();
adr.str("");
sf::Texture genimg27;
adr << std::fixed << defGui<<"g4906.png"; 
if (!genimg27.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[26]=genimg27;
sf::Sprite spgen27(genimg27);
adr.clear();
adr.str("");
sf::Texture genimg28;
adr << std::fixed << defGui<<"g7001.png"; 
if (!genimg28.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[27]=genimg28;
sf::Sprite spgen28(genimg28);
adr.clear();
adr.str("");
sf::Texture genimg29;
adr << std::fixed << defGui<<"g7000.png";
if (!genimg29.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[28]=genimg29;
sf::Sprite spgen29(genimg29);
adr.clear();
adr.str("");
sf::Texture genimg30;
adr << std::fixed << defGui<<"g7020.png";
if (!genimg30.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[29]=genimg30;
sf::Sprite spgen30(genimg30);
adr.clear();
adr.str("");
sf::Texture genimg31;
adr << std::fixed << defGui<<"g4971.png";
if (!genimg31.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[30]=genimg31;
sf::Sprite spgen31(genimg31);
adr.clear();
adr.str("");
sf::Texture genimg32;
adr << std::fixed << defGui<<"g7024.png"; 
if (!genimg32.loadFromFile(adr.str()))
    return EXIT_FAILURE;
tabTexture[31]=genimg32;
sf::Sprite spgen32(genimg32);
adr.clear();
adr.str("");

menuBar.setSize(sf::Vector2f(800,28));
menuBar.setFillColor(sf::Color(203,213,217));

verticalBar.setSize(sf::Vector2f(10,838));
verticalBar.setPosition(sf::Vector2f(400,28));
verticalBar.setFillColor(sf::Color(203,213,217));
horizontalBar.setSize(sf::Vector2f(810,10));
horizontalBar.setPosition(sf::Vector2f(0,428));
horizontalBar.setFillColor(sf::Color(203,213,217));
vBar1.setSize(sf::Vector2f(1,838));
vBar1.setPosition(sf::Vector2f(200,28));
vBar1.setFillColor(sf::Color(203,213,217));
hBar1.setSize(sf::Vector2f(810,1));
hBar1.setPosition(sf::Vector2f(0,228));
hBar1.setFillColor(sf::Color(203,213,217));
vBar2.setSize(sf::Vector2f(1,400));
vBar2.setPosition(sf::Vector2f(610,28));
vBar2.setFillColor(sf::Color(203,213,217));
hBar2.setSize(sf::Vector2f(400,1));
hBar2.setPosition(sf::Vector2f(0,638));
hBar2.setFillColor(sf::Color(203,213,217));

adr << std::fixed << defGui<<"teteDessus.png";
if (!imageF1.loadFromFile(adr.str()))
   return EXIT_FAILURE;
teteDessus.setTexture(imageF1);
teteDessus.setPosition(sf::Vector2f(170, 204));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"teteDroite.png";
if (!imageF2.loadFromFile(adr.str()))
  return EXIT_FAILURE;
teteDroite.setTexture(imageF2);
teteDroite.setPosition(sf::Vector2f(588,204));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"teteDos.png";
if (!imageF3.loadFromFile(adr.str()))
  return EXIT_FAILURE;
teteDos.setTexture(imageF3);
teteDos.setPosition(sf::Vector2f(172,604));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"distance.png";
if (!imageF4.loadFromFile(adr.str()))
  return EXIT_FAILURE;
distanceFond.setTexture(imageF4);
distanceFond.setPosition(sf::Vector2f(410,438));
adr.clear();
adr.str("");



scaleWidth=1;
scaleHeight=1;
pTheta=0.1;				// Rotation 
pPhi=0;
centreDx=608.0;
centreDy=638.0;

adr << std::fixed << defGui<<"FreeSans.ttf";
if (!font.loadFromFile(adr.str()))
	 return EXIT_FAILURE;
adr.clear();
adr.str("");

adr << std::fixed << defGui<<"space.png";
if (!imageF5.loadFromFile(adr.str()))
   return EXIT_FAILURE;
selectGroupe.setTexture(imageF5);
selectGroupe.setPosition(sf::Vector2f(106,2));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"trash.png";
if (!imageF6.loadFromFile(adr.str()))
   return EXIT_FAILURE;
trash.setTexture(imageF6);
trash.setPosition(sf::Vector2f(150,2));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"trash2.png";
if (!imageF7.loadFromFile(adr.str()))
   return EXIT_FAILURE;
trash2.setTexture(imageF7);
trash2.setPosition(sf::Vector2f(174,2));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"trash3.png";
if (!imageF8.loadFromFile(adr.str()))
   return EXIT_FAILURE;
trash3.setTexture(imageF8);
trash3.setPosition(sf::Vector2f(198,2));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"mv1.png";
if (!imageF9.loadFromFile(adr.str()))
   return EXIT_FAILURE;
mv1.setTexture(imageF9);
mv1.setPosition(sf::Vector2f(222,2));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"mv3.png";
if (!imageF10.loadFromFile(adr.str()))
   return EXIT_FAILURE;
mv2.setTexture(imageF10);
mv2.setPosition(sf::Vector2f(250,2));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"mvx.png";
if (!imageF11.loadFromFile(adr.str()))
   return EXIT_FAILURE;
mv3.setTexture(imageF11);
mv3.setPosition(sf::Vector2f(278,2));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"expansion.png";
if (!imageF12.loadFromFile(adr.str()))
   return EXIT_FAILURE;
expansion.setTexture(imageF12);
expansion.setPosition(sf::Vector2f(306,2));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"contraction.png";
if (!imageF13.loadFromFile(adr.str()))
   return EXIT_FAILURE;
contraction.setTexture(imageF13);
contraction.setPosition(sf::Vector2f(334,2));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"roty.png";
if (!imageF21.loadFromFile(adr.str()))
  return EXIT_FAILURE;
roty.setTexture(imageF21);
roty.setPosition(sf::Vector2f(362, 2));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"rotx.png";
if (!imageF22.loadFromFile(adr.str()))
  return EXIT_FAILURE;
rotx.setTexture(imageF22);
rotx.setPosition(sf::Vector2f(390, 2));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"rotz.png";
if (!imageF23.loadFromFile(adr.str()))
  return EXIT_FAILURE;
rotz.setTexture(imageF23);
rotz.setPosition(sf::Vector2f(418, 2));
adr.clear();
adr.str("");

adr << std::fixed << defGui<<"teteDessus24.png";
if (!imageF17.loadFromFile(adr.str()))
   return EXIT_FAILURE;
winD.setTexture(imageF17);
winD.setPosition(sf::Vector2f(570,2));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"teteDroite24.png";
if (!imageF18.loadFromFile(adr.str()))
   return EXIT_FAILURE;
winR.setTexture(imageF18);
winR.setPosition(sf::Vector2f(600,2));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"teteDos24.png";
if (!imageF19.loadFromFile(adr.str()))
   return EXIT_FAILURE;
winA.setTexture(imageF19);
winA.setPosition(sf::Vector2f(630,2));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"if3D.png";
if (!imageF20.loadFromFile(adr.str()))
   return EXIT_FAILURE;
winI3D.setTexture(imageF20);
winI3D.setPosition(sf::Vector2f(720,2));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"preferences.png";
if (!imageF14.loadFromFile(adr.str()))
   return EXIT_FAILURE;
preferences.setTexture(imageF14);
preferences.setPosition(sf::Vector2f(10,4));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"param.png";
if (!imageF15.loadFromFile(adr.str()))
   return EXIT_FAILURE;
param.setTexture(imageF15);
param.setPosition(sf::Vector2f(0,0));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"spaceNew.png";
if (!imageF24.loadFromFile(adr.str()))
   return EXIT_FAILURE;
spaceNew.setTexture(imageF24);
spaceNew.setPosition(sf::Vector2f(680,2));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"open.png";
if (!imageF25.loadFromFile(adr.str()))
   return EXIT_FAILURE;
openFile.setTexture(imageF25);
openFile.setPosition(sf::Vector2f(42,2));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"saisie3.png";
if (!imageF26.loadFromFile(adr.str()))
   return EXIT_FAILURE;
file.setTexture(imageF26);
file.setPosition(sf::Vector2f(4, 4));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"floppy.png";
if (!imageF27.loadFromFile(adr.str()))
   return EXIT_FAILURE;
floppy.setTexture(imageF27);
floppy.setPosition(sf::Vector2f(74, 3));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"ok.png";
if (!imageF28.loadFromFile(adr.str()))
   return EXIT_FAILURE;
fileok.setTexture(imageF28);
fileok.setPosition(sf::Vector2f(150, 31));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"bAnnuler.png";
if (!imageF29.loadFromFile(adr.str()))
   return EXIT_FAILURE;
fileAnnul.setTexture(imageF29);
fileAnnul.setPosition(sf::Vector2f(90, 31));
adr.clear();
adr.str("");

confDaw1.setRadius(4.f);
confDaw1.setFillColor(sf::Color(0,0,0));

defServeur.setFont(font);
defServeur.setCharacterSize(13);
defServeur.setPosition(378-defServeur.getLocalBounds().width-2,92);
defServeur.setFillColor(sf::Color(0,0,0));
defPort.setFont(font);
defPort.setCharacterSize(13);
defPort.setPosition(458-defPort.getLocalBounds().width-2,92);
defPort.setFillColor(sf::Color(0,0,0));

bkgToolType.setSize(sf::Vector2f(100,24));
bkgToolType.setPosition(sf::Vector2f(80,88));
bkgToolType.setFillColor(sf::Color(203,213,217,0));

toolType.setFont(font);
toolType.setString(L"Paramètres");
toolType.setCharacterSize(13);
toolType.setPosition(100,92);
toolType.setFillColor(sf::Color(0,0,0,0));

carla.setFont(font);
carla.setString("Carla");
carla.setCharacterSize(13);
carla.setPosition(74,83);
carla.setFillColor(sf::Color(0,0,0,255));
reaper.setFont(font);
reaper.setString("Reaper");
reaper.setCharacterSize(13);
reaper.setPosition(74,110);
reaper.setFillColor(sf::Color(0,0,0,255));

canalTextF1.setFont(font);	
canalTextF1.setString(" 1");
canalTextF1.setCharacterSize(12);
canalTextF1.setFillColor(sf::Color(255, 255, 255));
string ctxt;
genTcolor[0]=sf::Color(255, 255, 255);
 genTcolor[1]=sf::Color(255,255,255);
 genTcolor[2]=sf::Color(255,255,255);
 genTcolor[3]=sf::Color(255,255,255);
 genTcolor[4]=sf::Color(255,255,255);
 genTcolor[5]=sf::Color(255, 255, 255);
 genTcolor[6]=sf::Color(255,255,255);
 genTcolor[7]=sf::Color(255,255,255);
 genTcolor[8]=sf::Color(255,255,255);
 genTcolor[9]=sf::Color(255,255,255);
 genTcolor[10]=sf::Color(0, 0, 0);
 genTcolor[11]=sf::Color(0,0,0);
 genTcolor[12]=sf::Color(255,255,255);
 genTcolor[13]=sf::Color(255, 255, 255);
 genTcolor[14]=sf::Color(255,255,255);
 genTcolor[15]=sf::Color(255, 255, 255);
 genTcolor[16]=sf::Color(255, 255, 255);
 genTcolor[17]=sf::Color(0, 0,0);
 genTcolor[18]=sf::Color(0, 0, 0);
 genTcolor[19]=sf::Color(0, 0, 0);
 genTcolor[20]=sf::Color(0, 0, 0);
 genTcolor[21]=sf::Color(0,0,0);
 genTcolor[22]=sf::Color(255,255,255);
 genTcolor[23]=sf::Color(0,0,0);
 genTcolor[24]=sf::Color(0,0,0);
 genTcolor[25]=sf::Color(0, 0,0);
 genTcolor[26]=sf::Color(255,255,255);
 genTcolor[27]=sf::Color(255,255,255);
 genTcolor[28]=sf::Color(255,255,255);
 genTcolor[29]=sf::Color(0,0,0);
 genTcolor[30]=sf::Color(255,255,255);
 genTcolor[31]=sf::Color(0,0,0);


string s="Paramètres";
tip[0]=sf::String::fromUtf8(s.begin(),s.end());
s="Fichiers";
tip[1]=sf::String::fromUtf8(s.begin(),s.end());
s="Sauvegarder";
tip[2]=sf::String::fromUtf8(s.begin(),s.end());
s="Nouvelle instance";
tip[3]=sf::String::fromUtf8(s.begin(),s.end());
s="Supprimer mixer";
tip[4]=sf::String::fromUtf8(s.begin(),s.end());
s="Supprimer groupe";
tip[5]=sf::String::fromUtf8(s.begin(),s.end());
s="Tout supprimer";
tip[6]=sf::String::fromUtf8(s.begin(),s.end());
s="Déplacement : mixer";
tip[7]=sf::String::fromUtf8(s.begin(),s.end());
s="Déplacement : groupe";
tip[8]=sf::String::fromUtf8(s.begin(),s.end());
s="Tout déplacer";
tip[9]=sf::String::fromUtf8(s.begin(),s.end());
s="Expansion groupe";
tip[10]=sf::String::fromUtf8(s.begin(),s.end());
s="Contraction groupe";
tip[11]=sf::String::fromUtf8(s.begin(),s.end());
s="Rotation Z";
tip[12]=sf::String::fromUtf8(s.begin(),s.end());
s="Rotation Y";
tip[13]=sf::String::fromUtf8(s.begin(),s.end());
s="Rotation X";
tip[14]=sf::String::fromUtf8(s.begin(),s.end());
s="Recherche/Création de mixer";
tip[15]=sf::String::fromUtf8(s.begin(),s.end());
s="Nouveau studio";
tip[16]=sf::String::fromUtf8(s.begin(),s.end());
s="Fenêtre 3D";
tip[17]=sf::String::fromUtf8(s.begin(),s.end());
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


//************************************************************************************************
//																Input
//************************************************************************************************
labelInput.setFont(font);
labelInput.setString("Piste");
labelInput.setCharacterSize(13);
labelInput.setPosition(sf::Vector2f(8, 8));
labelInput.setFillColor(sf::Color(0,0,0));
labelInput2.setFont(font);
labelInput2.setString("Greffon");
labelInput2.setCharacterSize(13);
labelInput2.setPosition(sf::Vector2f(8, 38));
labelInput2.setFillColor(sf::Color(0,0,0));
labelGroupe.setFont(font);
labelGroupe.setString("Groupe");
labelGroupe.setCharacterSize(13);
labelGroupe.setPosition(sf::Vector2f(8, 70));
labelGroupe.setFillColor(sf::Color(0,0,0));

labelDt.setFont(font);
labelDt.setString("Rt");
labelDt.setCharacterSize(13);
labelDt.setPosition(sf::Vector2f(584, 5));
labelDt.setFillColor(sf::Color(0,0,0));

labelAide.setFont(font);
labelAide.setString("Aide");
labelAide.setCharacterSize(13);
labelAide.setPosition(sf::Vector2f(770, 5));
labelAide.setFillColor(sf::Color(0,0,0));


inpText.setFont(font);
inpText.setString("");
inpText.setCharacterSize(13);
inpText.setPosition(sf::Vector2f(8, 8));
inpText.setFillColor(sf::Color(0,0,0));
inpText2.setFont(font);
inpText2.setString("");
inpText2.setCharacterSize(13);
inpText2.setPosition(sf::Vector2f(114, 38));
inpText2.setFillColor(sf::Color(0,0,0));


inpTextFile.setFont(font);
inpTextFile.setString("");
inpTextFile.setCharacterSize(13);
inpTextFile.setFillColor(sf::Color(0,0,0));


labelInpBarText.setFont(font);
labelInpBarText.setString("Piste : ");
labelInpBarText.setCharacterSize(13);
labelInpBarText.setPosition(sf::Vector2f(464, 5));
labelInpBarText.setFillColor(sf::Color(0,0,0));
inpBarText.setFont(font);
inpBarText.setString("");
inpBarText.setCharacterSize(13);
inpBarText.setPosition(sf::Vector2f(546, 5));
inpBarText.setFillColor(sf::Color(0,0,0));
inpBarText2.setFont(font);
inpBarText2.setString("");
inpBarText2.setCharacterSize(13);
inpBarText2.setPosition(sf::Vector2f(658, 5));
inpBarText2.setFillColor(sf::Color(0,0,0));

trackBarText.setFont(font);
trackBarText.setString("");
trackBarText.setCharacterSize(13);
trackBarText.setPosition(sf::Vector2f(688, 5));
trackBarText.setFillColor(sf::Color(0,0,0));

adr << std::fixed << defGui<<"right.png";
if (!imageF16.loadFromFile(adr.str()))
   return EXIT_FAILURE;
validSp.setTexture(imageF16);
validSp.setPosition(sf::Vector2f(555,2));
adr.clear();
adr.str("");

flagInpCurseur=0;
winInpCurseur.setSize(sf::Vector2f(2,12));
winInpCurseur.setFillColor(sf::Color(0,0,0,255));
winInpCurseur.setPosition(122,12);

selectMixer.setFillColor(sf::Color(255, 255, 255,0));
selectMixer.setRadius(12.0);
selectMixer.setOutlineColor(sf::Color(255, 255, 255,255));
selectMixer.setOutlineThickness(1.0);

selectDMixer.setFillColor(sf::Color(255, 0, 0,255));
selectDMixer.setRadius(6.0);


adr << std::fixed << defGui<<"saisie.png";												// Image de la sphère de rotation
if (!inpt.loadFromFile(adr.str()))
   return EXIT_FAILURE;
inpt.setSmooth(true);
inpInput.setTexture(inpt);
inpInput.setPosition(sf::Vector2f(74,6));
inpInput2.setTexture(inpt);
inpInput2.setPosition(sf::Vector2f(74,36));
adr.clear();
adr.str("");
inpTrack.setTexture(inpt);
inpTrack.setPosition(sf::Vector2f(74,36));
inpScale.setTexture(inpt);
inpScale.setPosition(sf::Vector2f(74,96));
adr << std::fixed << defGui<<"saisie2.png";												// Image de la sphère de rotation
if (!inpbar1.loadFromFile(adr.str()))
   return EXIT_FAILURE;
inpbar1.setSmooth(true);
inpBarInput.setTexture(inpbar1);
inpBarInput.setPosition(sf::Vector2f(504,3));
inpBarInput2.setTexture(inpbar1);
inpBarInput2.setPosition(sf::Vector2f(610,3));
adr.clear();
adr.str("");
inpBarTrack.setTexture(inpbar1);
inpBarTrack.setPosition(sf::Vector2f(610,3));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"bNoSelect.png";												// Image de la sphère de rotation
if (!bNoSelect.loadFromFile(adr.str()))
   return EXIT_FAILURE;
bNoSelect.setSmooth(true);
inpSelect.setTexture(bNoSelect);
inpSelect.setPosition(sf::Vector2f(74,69));
adr.clear();
adr.str("");
adr << std::fixed << defGui<<"bselect.png";												// Image de la sphère de rotation
if (!bselect.loadFromFile(adr.str()))
   return EXIT_FAILURE;
bselect.setSmooth(true);
adr.clear();
adr.str("");
inpGroupe.setTexture(tabTexture[defautGroupe]);
inpGroupe.setPosition(sf::Vector2f(88,64));
adr << std::fixed << defGui<<"objetColor.png";												// Image de la sphère de rotation
if (!selectC.loadFromFile(adr.str()))
   return EXIT_FAILURE;
selectC.setSmooth(true);
adr.clear();
adr.str("");
selectGrp.setTexture(selectC);
selectGrp.setPosition(sf::Vector2f(0,0));

//************************************************************************************************
//																Outils
//************************************************************************************************
//****************************************************************************************
//													serveur OSC
//****************************************************************************************
/*
int foo_handler(const char *path, const char *types, lo_arg ** argv,
int argc, void *data, void *user_data);
lo::ServerThread st(9000);
    if (!st.is_valid()) {
        std::cout << "Nope."<< 9000<< std::endl;
        return 1;
    }
st.set_callbacks([&st](){printf("Thread init: %p.\n",&st);},
                     [](){printf("Thread cleanup.\n");});

std::cout << "URL: " << st.url()<< std::endl;
 std::atomic<int> received(0);
 
 st.add_method("/orientation", "fff",
                  [&received](lo_arg **argv, int)
                  //{std::cout << "/rotationvector" << (++received) << " arg0: "
                  //           << argv[0]->f<<" arg1: " << argv[1]->f <<" arg2: "<< argv[2]->f <<" arg3: "<< argv[3]->f<<" arg4: "<< argv[4]->f<< std::endl;}
                  {quaternionRotation(argv[0]->f, argv[1]->f, argv[2]->f,0);});
//Start the server.
   st.start();
*/

//******************************************************************************************
objetCreate();
char * cstr = new char [home.length()+1];
std::strcpy (cstr, home.c_str());
int ncwd=chdir(cstr);
string ctx;
while (winPrincipale.isOpen()) {
	sf::Event eventPrincipal;
	sf::Event eventInput;
	sf::Event eventInputFile;
	sf::Event eventSelectGrp;
	sf::Event eventParam;
	sf::Event event3D;
  
	while (winPrincipale.pollEvent(eventPrincipal)){        
 			switch (eventPrincipal.type){
  			case sf::Event::Closed:
					//writeConfGui();
					//writePreferences();
					winPrincipale.close();
					break;
			case sf::Event::Resized:
					onEventResized(eventPrincipal);
					break;
  			case sf::Event::KeyPressed:
  					onKeyPressed(eventPrincipal);
					break;
			case sf::Event::MouseButtonPressed:
					onClick(eventPrincipal);
					break;
			case sf::Event::MouseWheelScrolled:
					mouseWheel(eventPrincipal);
					break;
			case sf::Event::MouseButtonReleased:
					onMouseUp(eventPrincipal);
					break;
			case sf::Event::MouseMoved:
					onMouseMove(eventPrincipal);
					break;
			case sf::Event::TextEntered:
	     			   refInput(eventPrincipal);
					   break;
		  			default:
					break;
  		  	}            
	}
	while (winInput.pollEvent(eventInput)){        
 			switch (eventInput.type){
  			case sf::Event::Closed:
					//writeConfGui();
					//writePreferences();
					winInput.close();
			case sf::Event::TextEntered:
	     			   newInputText(eventInput);
					   break;
			case sf::Event::MouseButtonPressed:
					onClickInput(eventInput);
					break;
			}      
	}
	
	while (winSelectGrp.pollEvent(eventSelectGrp)){        
 			switch (eventSelectGrp.type){
  			case sf::Event::Closed:
					//writeConfGui();
					//writePreferences();
					winSelectGrp.close();
					break;
			case sf::Event::MouseButtonPressed:
					onClickSelectGrp(eventSelectGrp);
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
	while (winParam.pollEvent(eventParam)){        
 			switch (eventParam.type){
  			case sf::Event::Closed:
					winParam.close();
					break;
			case sf::Event::MouseButtonPressed:
					onClickParam(eventParam);
					break;
			case sf::Event::TextEntered:
	     			   newParamText(eventParam);
					   break;
			case sf::Event::MouseMoved:
					onMouseMoveParam(eventParam);
					break;
		  	default:
					break;
  		  	}            
	}
	 
	winPrincipale.setActive(true);
	winPrincipale.pushGLStates();
	winPrincipale.clear(sf::Color(19,37,53));
    
	winPrincipale.draw(menuBar);
	winPrincipale.draw(preferences);
	winPrincipale.draw(openFile);
	winPrincipale.draw(floppy);
	winPrincipale.draw(selectGroupe);
	winPrincipale.draw(trash);
	winPrincipale.draw(trash2);
	winPrincipale.draw(trash3);
	winPrincipale.draw(mv1);
	winPrincipale.draw(mv2);
	winPrincipale.draw(mv3);
	winPrincipale.draw(expansion);
	winPrincipale.draw(contraction);
	winPrincipale.draw(roty);
	winPrincipale.draw(rotx);
	winPrincipale.draw(rotz);
	winPrincipale.draw(winI3D);
	
	
	winPrincipale.draw(inpBarInput);
	winPrincipale.draw(inpBarInput2);
	//winPrincipale.draw(inpBarTrack);
	winPrincipale.draw(labelInpBarText);
	winPrincipale.draw(inpBarText);
	winPrincipale.draw(inpBarText2);
	winPrincipale.draw(validSp);
	
	winPrincipale.draw(labelDt);
	winPrincipale.draw(labelAide);
	
	winPrincipale.draw(verticalBar);
	winPrincipale.draw(horizontalBar);
	winPrincipale.draw(vBar1);
	winPrincipale.draw(hBar1);
	winPrincipale.draw(vBar2);
	winPrincipale.draw(hBar2);
	
	winPrincipale.draw(teteDessus);
	winPrincipale.draw(teteDroite);
	winPrincipale.draw(teteDos);
	winPrincipale.draw(distanceFond);
	winPrincipale.draw(spaceNew);
	
	for(int i=0; i<tabEntree.size();i++){
		sf::Vector2f obj=objetCoordToPDessus(tabEntree[i].z, tabEntree[i].x);
		tabEntree[i].spriteD.setPosition(sf::Vector2f(obj.x,obj.y));
		winPrincipale.draw(tabEntree[i].spriteD);
		canalTextF1.setFillColor(genTcolor[tabEntree[i].groupe]);
		ctxt=to_string(tabEntree[i].track);
		canalTextF1.setString(ctxt);
          if(tabEntree[i].track<10){
			 	canalTextF1.setPosition(sf::Vector2f(obj.x+8, obj.y+5));
			 }else{
			 	canalTextF1.setPosition(sf::Vector2f(obj.x+5, obj.y+5));
			 }
			 winPrincipale.draw(canalTextF1);
		
		obj=objetCoordToPDroite(tabEntree[i].z, tabEntree[i].y);
		tabEntree[i].spriteR.setPosition(sf::Vector2f(obj.x,obj.y));
		winPrincipale.draw(tabEntree[i].spriteR);
		if(tabEntree[i].track<10){
			 	canalTextF1.setPosition(sf::Vector2f(obj.x+8, obj.y+5));
			 }else{
			 	canalTextF1.setPosition(sf::Vector2f(obj.x+5, obj.y+5));
			 }
			 winPrincipale.draw(canalTextF1);
		
		obj=objetCoordToPArriere(tabEntree[i].x, tabEntree[i].y);
		tabEntree[i].spriteA.setPosition(sf::Vector2f(obj.x,obj.y));
		winPrincipale.draw(tabEntree[i].spriteA);
		if(tabEntree[i].track<10){
			 	canalTextF1.setPosition(sf::Vector2f(obj.x+8, obj.y+5));
			 }else{
			 	canalTextF1.setPosition(sf::Vector2f(obj.x+5, obj.y+5));
			 }
			 winPrincipale.draw(canalTextF1);
		
		/*sf::Vector3f obj2=objetCoordToP3D(tabEntree[i].x, tabEntree[i].y,tabEntree[i].z);
		tabEntree[i].sprite3D.setPosition(sf::Vector2f(obj2.x,obj2.y));
		tabEntree[i].sprite3D.setPosition(sf::Vector2f(tabEntree[i].dx,tabEntree[i].dy));
		tabEntree[i].sprite3D.setScale(0.5,0.5);
		winPrincipale.draw(tabEntree[i].sprite3D);
		*/
		
	}
	if(objActif!=65536){
		sf::Vector2f obj=objetCoordToPDessus(tabEntree[objActif].z, tabEntree[objActif].x);
		selectMixer.setPosition(sf::Vector2f(obj.x,obj.y));
		winPrincipale.draw(selectMixer);
		obj=objetCoordToPDroite(tabEntree[objActif].z, tabEntree[objActif].y);
		selectMixer.setPosition(sf::Vector2f(obj.x,obj.y));
		winPrincipale.draw(selectMixer);
		obj=objetCoordToPArriere(tabEntree[objActif].x, tabEntree[objActif].y);
		selectMixer.setPosition(sf::Vector2f(obj.x,obj.y));
		winPrincipale.draw(selectMixer);
		selectDMixer.setPosition(sf::Vector2f(tabEntree[objActif].dx-6,tabEntree[objActif].dy-6));
		winPrincipale.draw(selectDMixer);
	}
	
	if(sf::Mouse::isButtonPressed(sf::Mouse::Right)){  // événements souris
 	 	onButtonPressedOutils();
 	}
 	winPrincipale.draw(bkgToolType);
 	winPrincipale.draw(toolType);
	
	winPrincipale.display();
	winPrincipale.popGLStates();
	winPrincipale.setActive(false);
	
	if(winInput.isOpen()){
		winInput.setActive(true);
    	winInput.pushGLStates();
    	winInput.clear(sf::Color(203,213,217));
    	
		winInput.draw(labelInput);
		winInput.draw(labelInput2);
		winInput.draw(labelGroupe);
		winInput.draw(inpInput);  
		winInput.draw(inpInput2);  	
    	winInput.draw(inpGroupe);
    	
    	winInput.draw(inpText);
    	winInput.draw(inpText2);
    	
    	if(flagInpCurseur==1){
			if(clockCurseur.getElapsedTime()>sf::seconds(0.8f)){
				winInput.draw(winInpCurseur);
				if(clockCurseur.getElapsedTime()>sf::seconds(1.6f)){
					clockCurseur.restart();
				}
			}
		}
    	
    	winInput.display();
    	winInput.popGLStates();
    	winInput.setActive(false);
	}
	
	if(winSelectGrp.isOpen()){
		winSelectGrp.setActive(true);
    	winSelectGrp.pushGLStates();
    	winSelectGrp.clear(sf::Color(203,213,217));
    	
    	winSelectGrp.draw(selectGrp);
		
    	winSelectGrp.display();
    	winSelectGrp.popGLStates();
    	winSelectGrp.setActive(false);
	}
	if(winParam.isOpen()){
		winParam.setActive(true);
    	winParam.pushGLStates();
    	winParam.clear(sf::Color(19,37,53));
    	
    	winParam.draw(param);
    	winParam.draw(confDaw1);
    	winParam.draw(defServeur);
    	winParam.draw(defPort);
    	winParam.draw(carla);
    	winParam.draw(reaper);
    	if(flagInpCurseur==1){
			if(clockCurseur.getElapsedTime()>sf::seconds(0.8f)){
				winParam.draw(winInpCurseur);
				if(clockCurseur.getElapsedTime()>sf::seconds(1.6f)){
					clockCurseur.restart();
				}
			}
		}
    	
    	winParam.display();
    	winParam.popGLStates();
    	winParam.setActive(false);
	}
	
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
	   
	    glPushMatrix();
	  		glTranslatef(tx*w3WxScale,ty*w3HyScale,0); 
	  	 	drawCube(-0.01,0.04*w3WxScale,0.04*w3HyScale);
	  	 glPopMatrix();
		 
		 /*
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

//**************************************************************************************************
//													Fenêtre Input
//**************************************************************************************************

void onClickInput(sf::Event e){
	stringstream adr;
	if (e.mouseButton.button == sf::Mouse::Left){
 		//std::cout << " Palette the left button was pressed" << std::endl;
 		//std::cout << "mouse x: " << e.mouseButton.x << std::endl;
 		//std::cout << "mouse y: " << e.mouseButton.y << std::endl;
   }
	if(e.mouseButton.x>90 && e.mouseButton.x<114 && e.mouseButton.y>66 && e.mouseButton.y<88){
		winSelectGrp.create(sf::VideoMode(473,128), "Groupe");
	}
	if(e.mouseButton.x>76 && e.mouseButton.x<124  && e.mouseButton.y>8 && e.mouseButton.y<28){
   	inpIndex=1;
   	apptxt="";
   	inpText.setString("");
   	winInpCurseur.setPosition(120,12);
	 	flagInpCurseur=1;
	 	clockCurseur.restart();
   }
   if(e.mouseButton.x>76 && e.mouseButton.x<124  && e.mouseButton.y>38 && e.mouseButton.y<58){
   	inpIndex=2;
   	apptxt="";
   	inpText2.setString("");
   	winInpCurseur.setPosition(120,42);
	 	flagInpCurseur=1;
	 	clockCurseur.restart();
   }
   
   
   if(e.mouseButton.x>126 && e.mouseButton.x<138 && e.mouseButton.y>10 && e.mouseButton.y<20){
   	int dp=tabEntree[objActif].track;
   	dp=dp+1;
   	if(dp>64){
   		dp=64;
   	}
   	tabEntree[objActif].track=dp;
   	string s=to_string(dp);
   	inpText.setString(s);
   	inpText.setPosition(120-inpText.getLocalBounds().width-2,10);
   	inpBarText.setString(to_string(tabEntree[objActif].track));
      inpBarText.setPosition(551-inpBarText.getLocalBounds().width-2,4);
   }
   if(e.mouseButton.x>126 && e.mouseButton.x<138 && e.mouseButton.y>21 && e.mouseButton.y<30){
   	int dp=tabEntree[objActif].track;
   	dp=dp-1;
   	if(dp<0){
   		dp=0;
   	}
   	tabEntree[objActif].track=dp;
   	string s=to_string(dp);
   	inpText.setString(s);
   	inpText.setPosition(120-inpText.getLocalBounds().width-2,10);
   	inpBarText.setString(to_string(tabEntree[objActif].track));
      inpBarText.setPosition(551-inpBarText.getLocalBounds().width-2,4);
   }
   if(e.mouseButton.x>126 && e.mouseButton.x<138 && e.mouseButton.y>40 && e.mouseButton.y<50){
   	int dp=tabEntree[objActif].greffon;
   	dp=dp+1;
   	if(dp>64){
   		dp=64;
   	}
   	tabEntree[objActif].greffon=dp;
   	string s=to_string(dp);
   	inpText2.setString(s);
   	inpText2.setPosition(120-inpText2.getLocalBounds().width-2,38);
   }
   if(e.mouseButton.x>126 && e.mouseButton.x<138 && e.mouseButton.y>50 && e.mouseButton.y<60){
   	int dp=tabEntree[objActif].greffon;
   	dp=dp-1;
   	if(dp<0){
   		dp=0;
   	}
   	tabEntree[objActif].greffon=dp;
   	string s=to_string(dp);
   	inpText2.setString(s);
   	inpText2.setPosition(120-inpText2.getLocalBounds().width-2,38);
   }
   
   if(e.mouseButton.x>75 && e.mouseButton.x<90 && e.mouseButton.y>72 && e.mouseButton.y<86){
   	if(tabEntree[objActif].flagTrack==0){
   		tabEntree[objActif].flagTrack=1;
   		inpSelect.setTexture(bselect);
   	}else{
   		tabEntree[objActif].flagTrack=0;
   		inpSelect.setTexture(bNoSelect);
   	}
   }
}


void newInputText(sf::Event e){
   int key=e.key.code;
   stringstream adr;
   if (e.text.unicode < 128){
		if(key==8){
	      apptxt=apptxt.substr(0,apptxt.length()-1);
	      
	 	}else{
			apptxt=apptxt+static_cast<char>(e.text.unicode);
			flagTxt=1;
		}
		switch (inpIndex){
       		case 1:
       			if(apptxt==""){
       				apptxt="1";
       			}
       			adr << std::fixed<< std::setprecision(0)<<apptxt;
       			tabEntree[objActif].track=stoi(adr.str());
       			inpText.setString(to_string(tabEntree[objActif].track));
       			inpText.setPosition(118-inpText.getLocalBounds().width-2,10);
       			inpBarText.setString(to_string(tabEntree[objActif].track));
       			inpBarText.setPosition(551-inpBarText.getLocalBounds().width-2,4);
       			break;
       		case 2:
       			if(apptxt==""){
       				apptxt="1";
       			}
       			adr << std::fixed<< std::setprecision(0)<<apptxt;
       			tabEntree[objActif].greffon=stoi(adr.str());
       			inpText2.setString(to_string(tabEntree[objActif].greffon));
       			inpText2.setPosition(120-inpText2.getLocalBounds().width-2,40);
       			break;
       		default:
       			break;
	    }
	    
   }
   adr.clear();
  	adr.str(""); 
}


void onClickSelectGrp(sf::Event e){
	int id=(e.mouseButton.x/59)+((e.mouseButton.y/32)*8);
	tabEntree[objActif].groupe=id;
	defautGroupe=id;
	tabEntree[objActif].spriteD.setTexture(tabTexture[id]);
	tabEntree[objActif].spriteR.setTexture(tabTexture[id]);
	tabEntree[objActif].spriteA.setTexture(tabTexture[id]);
	tabEntree[objActif].sprite3D.setTexture(tabTexture[id]);
	winSelectGrp.close();
}
//**************************************************************************************************
//													Fenêtre 3D
//**************************************************************************************************
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
void drawCube(GLfloat s,GLfloat e,GLfloat e2){
	 glPushMatrix();															// Le pupitre central
    glScalef(e,e2,e);
    glTranslatef(s+tx,ty,0);
    glBegin(GL_QUADS);

    glColor4f(255,0,0,0.5); //face rouge
    glVertex3d(1,1,1);
    glVertex3d(1,1,-1);
    glVertex3d(-1,1,-1);
    glVertex3d(-1,1,1);

    glColor4f(0,255,0,0.5); //face verte
    glVertex3d(1,-1,1);
    glVertex3d(1,-1,-1);
    glVertex3d(1,1,-1);
    glVertex3d(1,1,1);

    glColor4f(0,0,255,0.5); //face bleue
    glVertex3d(-1,-1,1);
    glVertex3d(-1,-1,-1);
    glVertex3d(1,-1,-1);
    glVertex3d(1,-1,1);

    glColor4f(255,255,0,0.5); //face jaune
    glVertex3d(-1,1,1);
    glVertex3d(-1,1,-1);
    glVertex3d(-1,-1,-1);
    glVertex3d(-1,-1,1);

    glColor4f(0,255,255,0.5); //face cyan
    glVertex3d(1,1,-1);
    glVertex3d(1,-1,-1);
    glVertex3d(-1,-1,-1);
    glVertex3d(-1,1,-1);

    glColor4f(255,0,255,0.5); //face magenta
    glVertex3d(1,-1,1);
    glVertex3d(1,1,1);
    glVertex3d(-1,1,1);
    glVertex3d(-1,-1,1);

    glEnd();
	 glPopMatrix();
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
	for(int i=0;i<tabEntree.size();i++){
  	  	glPushMatrix();
  	 	sf::Texture::bind(&tabTexture[tabEntree[i].groupe]);
  		glTranslatef((-tabEntree[i].x+tx)*w3WxScale,-(tabEntree[i].y+ty)*w3HyScale,(tabEntree[i].z*w3WxScale)); 
  	 	gluSphere(quadratic,tabEntree[i].r,32,32);
  	 	sf::Texture::bind(NULL);
  	 	glPopMatrix();
   }
}
void onMouseMove3(sf::Event e){  
	//std::cout << "Window 3D mouse x: " << e.mouseMove.x << std::endl;
   //std::cout << "mouse y: " << e.mouseMove.y << std::endl;                    
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
void onButtonPressed3(){
  if(win3D.hasFocus()){
  sf::Vector2i position = sf::Mouse::getPosition(win3D);                       // Rotation avec la Sphère
	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		//std::cout << "buttonPressed 3D mouse x: " << position.x << std::endl;
      //std::cout << "mouse y: " << position.y << std::endl;
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
//**************************************************************************************************
//													Fenêtre principale
//**************************************************************************************************
void onEventResized(sf::Event e){
	sf::FloatRect visibleArea(0, 0, e.size.width, e.size.height);
   winPrincipale.setView(sf::View(visibleArea));
   menuBar.setSize(sf::Vector2f(e.size.width,28));
   float fw=winPrincipale.getSize().x;
   float fh=winPrincipale.getSize().y;
   scaleWidth=fw/810;
   scaleHeight=fh/838;
   //std::cout << " scaleWidth: " << scaleWidth <<" scaleHeight: " << scaleHeight <<std::endl;
   //std::cout << " e.size.width: " << e.size.width << " e.size.height: " << e.size.height <<std::endl;
   
   
   verticalBar.setSize(sf::Vector2f(10,e.size.height));
	verticalBar.setPosition(sf::Vector2f((e.size.width/2)-5,28));
	verticalBar.setFillColor(sf::Color(203,213,217));
	horizontalBar.setSize(sf::Vector2f(e.size.width,10));
	horizontalBar.setPosition(sf::Vector2f(0,(e.size.height/2)+9));
	horizontalBar.setFillColor(sf::Color(203,213,217));
	float wt=(e.size.width-10)/4;
	float ht=(e.size.height-38)/4;
	vBar1.setSize(sf::Vector2f(1,e.size.height));
	vBar1.setPosition(sf::Vector2f(wt,28));
	vBar1.setFillColor(sf::Color(203,213,217));
	hBar1.setSize(sf::Vector2f(e.size.width,1));
	hBar1.setPosition(sf::Vector2f(0,ht+28));
	hBar1.setFillColor(sf::Color(203,213,217));
	vBar2.setSize(sf::Vector2f(1,(e.size.height-28)/2));
	vBar2.setPosition(sf::Vector2f((3*wt)+10,28));
	vBar2.setFillColor(sf::Color(203,213,217));
	hBar2.setSize(sf::Vector2f(e.size.width/2,1));
	hBar2.setPosition(sf::Vector2f(0,(3*ht)+38));
	hBar2.setFillColor(sf::Color(203,213,217));
	teteDessus.setPosition(sf::Vector2f(170*scaleWidth, 204*scaleHeight));
	teteDessus.setScale(sf::Vector2f(scaleWidth, scaleHeight));
	teteDroite.setPosition(sf::Vector2f(588*scaleWidth,204*scaleHeight));
	teteDroite.setScale(sf::Vector2f(scaleWidth, scaleHeight));
	teteDos.setPosition(sf::Vector2f(172*scaleWidth,604*scaleHeight));
	teteDos.setScale(sf::Vector2f(scaleWidth, scaleHeight));
	distanceFond.setPosition(sf::Vector2f(410*scaleWidth,436*scaleHeight));
	distanceFond.setScale(sf::Vector2f(scaleWidth, scaleHeight));
}
void mouseWheel(sf::Event e){
	if (e.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel){
		if(e.mouseWheelScroll.x>verticalBar.getPosition().x+10 &&  e.mouseWheelScroll.y>horizontalBar.getPosition().x+10){
			if(e.mouseWheelScroll.delta==1){
				tabEntree[objActif].z=tabEntree[objActif].z+0.01;
				if(tabEntree[objActif].z>1){
		 			tabEntree[objActif].z=1;
				} 	
			}else{
				tabEntree[objActif].z=tabEntree[objActif].z-0.01;
				if(tabEntree[objActif].z<-1){
		 			tabEntree[objActif].z=-1;
				} 	
			}
		}
	}
}
void onButtonPressedOutils(){
	sf::Vector2i position = sf::Mouse::getPosition(winPrincipale); 
	if(position.x>308 && position.x<330 && position.y>6 && position.y<26){
   	defGrpExpansion(0.001);
   }
   if(position.x>336 && position.x<356 && position.y>6 && position.y<26){
   	defGrpExpansion(-0.001);
   }
   if(position.x>364 && position.x<386 && position.y>6 && position.y<26){
   	rotateY3D();
   }
   if(position.x>392 && position.x<414 && position.y>6 && position.y<26){
   	rotateX3D();
   }
   if(position.x>420 && position.x<440 && position.y>6 && position.y<26){
   	rotateZ3D();
   }
}
void onKeyPressed(sf::Event e){
	flagTxt=0;
	//std::cout << "event.key.code "<<e.key.code << std::endl;
	if (e.key.code == 76){
		tabEntree[objActif].x=tabEntree[objActif].x+0.1;
		tabEntree[objActif].z=tabEntree[objActif].z-0.1;
		objetCoordCtrl(objActif);
	}
	if (e.key.code == 77){
		tabEntree[objActif].x=tabEntree[objActif].x+0.1;
		objetCoordCtrl(objActif);
	}
	if (e.key.code == 78){
		tabEntree[objActif].x=tabEntree[objActif].x+0.1;
		tabEntree[objActif].z=tabEntree[objActif].z+0.1;
		objetCoordCtrl(objActif);
	}
	if (e.key.code == 79){
		tabEntree[objActif].z=tabEntree[objActif].z-0.1;
		objetCoordCtrl(objActif);
	}
	if (e.key.code == 81){
		tabEntree[objActif].z=tabEntree[objActif].z+0.1;
		objetCoordCtrl(objActif);
	}
	if (e.key.code == 82){
		tabEntree[objActif].x=tabEntree[objActif].x-0.1;
		tabEntree[objActif].z=tabEntree[objActif].z-0.1;
		objetCoordCtrl(objActif);
	}
	if (e.key.code == 83){
		tabEntree[objActif].x=tabEntree[objActif].x-0.1;
		objetCoordCtrl(objActif);
	}
	if (e.key.code == 84){
		tabEntree[objActif].x=tabEntree[objActif].x-0.1;
		tabEntree[objActif].z=tabEntree[objActif].z+0.1;
		objetCoordCtrl(objActif);
	}
	if (e.key.code == 73){
		tabEntree[objActif].y=tabEntree[objActif].y-0.1;
		objetCoordCtrl(objActif);
	}
	if (e.key.code == 74){
		tabEntree[objActif].y=tabEntree[objActif].y+0.1;
		objetCoordCtrl(objActif);
	}
	if (e.key.code == 4){
		defGrpExpansion(0.01);
	}
	if (e.key.code == 2){
		defGrpExpansion(-0.01);
	}
	if (e.key.code == 23){
		rotateX3D();
	}
	if (e.key.code == 24){
		rotateY3D();
	}
	if (e.key.code == 25){
		rotateZ3D();
	}
}

void onClick(sf::Event e){
	if (e.mouseButton.button == sf::Mouse::Left){
 		//std::cout << " Palette the left button was pressed" << std::endl;
 		//std::cout << "mouse x: " << e.mouseButton.x << std::endl;
 		//std::cout << "mouse y: " << e.mouseButton.y << std::endl;
   }
   
   if(e.mouseButton.x<verticalBar.getPosition().x && e.mouseButton.y<horizontalBar.getPosition().y){
	   for(int i=0; i<tabEntree.size();i++){
			sf::Vector2f obj=objetCoordToPDessus(tabEntree[i].z, tabEntree[i].x);
			if(e.mouseButton.x>obj.x && e.mouseButton.x<obj.x+24 && e.mouseButton.y>obj.y && e.mouseButton.y<obj.y+24){
				objActif=i;
				flagObjActif=1;
				oldPosX=e.mouseButton.x;
				oldPosY=e.mouseButton.y;
				inpBarText.setString(to_string(tabEntree[objActif].track));
				if (e.mouseButton.button == sf::Mouse::Right){
					winInput.create(sf::VideoMode(150,94), "Input");
					inpText.setString(to_string(tabEntree[objActif].track));
					inpText2.setString(to_string(tabEntree[objActif].greffon));

					scaleText.setString(to_string(tabEntree[objActif].scale));

				}
				break;
			}
	   }

   	if(objActif!=65536 && e.mouseButton.y>28){
   		sf::Vector2f obj=objetCoordFromPDessus(e.mouseButton.x, e.mouseButton.y);
   		tabEntree[objActif].z=obj.x;
   		tabEntree[objActif].x=obj.y;
   		inpBarText.setString(to_string(tabEntree[objActif].track));
   	}
   }
   if(e.mouseButton.x>verticalBar.getPosition().x+10 && e.mouseButton.y<horizontalBar.getPosition().y){
	   for(int i=0; i<tabEntree.size();i++){
			sf::Vector2f obj=objetCoordToPDroite(tabEntree[i].z, tabEntree[i].y);
			if(e.mouseButton.x>obj.x && e.mouseButton.x<obj.x+24 && e.mouseButton.y>obj.y && e.mouseButton.y<obj.y+24){
				objActif=i;
				flagObjActif=1;
				oldPosX=e.mouseButton.x;
				oldPosY=e.mouseButton.y;
				inpBarText.setString(to_string(tabEntree[objActif].track));
				if (e.mouseButton.button == sf::Mouse::Right){
					winInput.create(sf::VideoMode(150,94), "Input");
					inpText.setString(to_string(tabEntree[objActif].track));
					inpText2.setString(to_string(tabEntree[objActif].greffon));
					trackBarText.setString(to_string(tabEntree[objActif].track));
					scaleText.setString(to_string(tabEntree[objActif].scale));
				}
				break;
			}
	   }
	   if(objActif!=65536  && e.mouseButton.y>28){
   		sf::Vector2f obj=objetCoordFromPDroite(e.mouseButton.x, e.mouseButton.y);
   		tabEntree[objActif].z=obj.x;
   		tabEntree[objActif].y=obj.y;
   	}
   }
   if(e.mouseButton.x<verticalBar.getPosition().x+10 && e.mouseButton.y>horizontalBar.getPosition().y+10){
	   for(int i=0; i<tabEntree.size();i++){
			sf::Vector2f obj=objetCoordToPArriere(tabEntree[i].x, tabEntree[i].y);
			if(e.mouseButton.x>obj.x && e.mouseButton.x<obj.x+24 && e.mouseButton.y>obj.y && e.mouseButton.y<obj.y+24){
				objActif=i;
				flagObjActif=1;
				oldPosX=e.mouseButton.x;
				oldPosY=e.mouseButton.y;
				inpBarText.setString(to_string(tabEntree[objActif].track));
				if (e.mouseButton.button == sf::Mouse::Right){
					winInput.create(sf::VideoMode(150,94), "Input");
					inpText.setString(to_string(tabEntree[objActif].track));
					inpText2.setString(to_string(tabEntree[objActif].greffon));
					trackBarText.setString(to_string(tabEntree[objActif].track));
					scaleText.setString(to_string(tabEntree[objActif].scale));
				}
			}
	   }
	   if(objActif!=65536){
   		sf::Vector2f obj=objetCoordFromPArriere(e.mouseButton.x, e.mouseButton.y);
   		tabEntree[objActif].x=obj.x;
   		tabEntree[objActif].y=obj.y;
   	}
   }
   if(e.mouseButton.x>verticalBar.getPosition().x+10 && e.mouseButton.y>horizontalBar.getPosition().y+10){   // click distance
   	if(flagDistance==0){
   		flagDistance=1;
   	}else{
   		flagDistance=0;
   	}
	   if(objActif!=65536){
 			sf::Vector3f obj=objetDistance(e.mouseButton.x,e.mouseButton.y);
 			float dt=1-(obj.z/192);
      	if(dt>0){
				tabEntree[objActif].dx=e.mouseButton.x;
   			tabEntree[objActif].dy=e.mouseButton.y;
   			tabEntree[objActif].d=dt;
   			defDistance(objActif);
   		}
   		
   		//std::cout << " cx1 " <<tabEntree[objActif].dx<< " cy1 " <<tabEntree[objActif].dy<< " d " <<tabEntree[objActif].d<< std::endl;
   	}
   }
   
   if(e.mouseButton.x>106 && e.mouseButton.x<136 && e.mouseButton.y>6 && e.mouseButton.y<26){
   	newInstanceSpace();
   }
   if(e.mouseButton.x>150 && e.mouseButton.x<170 && e.mouseButton.y>6 && e.mouseButton.y<26){
   	delObjet(objActif);
   }
   if(e.mouseButton.x>176 && e.mouseButton.x<192 && e.mouseButton.y>6 && e.mouseButton.y<26){
   	delGrpObjet(objActif);
   }
   if(e.mouseButton.x>198 && e.mouseButton.x<218 && e.mouseButton.y>6 && e.mouseButton.y<26){
   	delAllObjet();
   }
   if(e.mouseButton.x>224 && e.mouseButton.x<244 && e.mouseButton.y>6 && e.mouseButton.y<26){
   	objMove=0;
   }
   if(e.mouseButton.x>252 && e.mouseButton.x<272 && e.mouseButton.y>6 && e.mouseButton.y<26){
   	objMove=1;
   }
   if(e.mouseButton.x>280 && e.mouseButton.x<302 && e.mouseButton.y>6 && e.mouseButton.y<26){
   	objMove=2;
   }
   if(e.mouseButton.x>308 && e.mouseButton.x<330 && e.mouseButton.y>6 && e.mouseButton.y<26){
   	defGrpExpansion(0.01);
   }
   if(e.mouseButton.x>336 && e.mouseButton.x<356 && e.mouseButton.y>6 && e.mouseButton.y<26){
   	defGrpExpansion(-0.01);
   }
   if(e.mouseButton.x>364 && e.mouseButton.x<386 && e.mouseButton.y>6 && e.mouseButton.y<26){
   	rotateY3D();
   }
   if(e.mouseButton.x>392 && e.mouseButton.x<414 && e.mouseButton.y>6 && e.mouseButton.y<26){
   	rotateX3D();
   }
   if(e.mouseButton.x>420 && e.mouseButton.x<440 && e.mouseButton.y>6 && e.mouseButton.y<26){
   	rotateZ3D();
   }
   if(e.mouseButton.x>508 && e.mouseButton.x<554 && e.mouseButton.y>6 && e.mouseButton.y<26){
   	flagTxt=1;
   	inpIndex=1;
   	apptxt="";
   	inpBarText.setString("");
   }
   if(e.mouseButton.x>612 && e.mouseButton.x<660 && e.mouseButton.y>6 && e.mouseButton.y<26){
   	flagTxt=1;
   	inpIndex=2;
   	apptxt="";
   	inpBarText2.setString("");
   }
   if(e.mouseButton.x>562 && e.mouseButton.x<576&& e.mouseButton.y>6 && e.mouseButton.y<26){
  		flagTxt=0;
     	nSelectMixer();
   }
   if(e.mouseButton.x>720 && e.mouseButton.x<745 && e.mouseButton.y>6 && e.mouseButton.y<26){
   	win3D.create (sf::VideoMode(800,800), "Vue 3D",sf::Style::Close , settings);
		init3D();
		drawWine3D=1;
		tx=-0.16;
		ty=0.01;
   }
   if(e.mouseButton.x>10 && e.mouseButton.x<34 && e.mouseButton.y>6 && e.mouseButton.y<26){
   	winParam.create (sf::VideoMode(500,180), L"Paramètres",sf::Style::Default , settings);
   }
   if(e.mouseButton.x>44 && e.mouseButton.x<72 && e.mouseButton.y>2 && e.mouseButton.y<26){
   	openSpace();
   }
   if(e.mouseButton.x>74 && e.mouseButton.x<102 && e.mouseButton.y>2 && e.mouseButton.y<26){
   	saveSpace();
   }
   if(e.mouseButton.x>681 && e.mouseButton.x<710 && e.mouseButton.y>2 && e.mouseButton.y<28){
   	std::cout << " newSurface" << std::endl;
   	newSurface();
   }
   if(e.mouseButton.x>768 && e.mouseButton.x<798 && e.mouseButton.y>1 && e.mouseButton.y<28){
		system("firefox http://blanchemain.info/Documents/Programmation/index.php?page=multiSpace3D");
	}
}
void onMouseUp(sf::Event e){
	flagObjActif=0;
	flagTxt=0;
	if(flagDistance==1){
		flagDistance=0;
		
	}
}
void onMouseMove(sf::Event e){
 		//std::cout << "mouse x: " << e.mouseMove.x << std::endl;
 		//std::cout << "mouse y: " << e.mouseMove.y << std::endl;
   
   if(e.mouseMove.y<30){
   	if(e.mouseMove.x>0 && e.mouseMove.x<36){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(84,24));
   	  toolType.setString(tip[0]);
   	  toolType.setPosition(e.mouseMove.x+30,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   	if(e.mouseMove.x>42 && e.mouseMove.x<68){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(64,24));
   	  toolType.setString(tip[1]);
   	  toolType.setPosition(e.mouseMove.x+34,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   	if(e.mouseMove.x>72 && e.mouseMove.x<102){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(86,24));
   	  toolType.setString(tip[2]);
   	  toolType.setPosition(e.mouseMove.x+28,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   	if(e.mouseMove.x>102 && e.mouseMove.x<142){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(106,24));
   	  toolType.setString(tip[3]);
   	  toolType.setPosition(e.mouseMove.x+24,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   	if(e.mouseMove.x>146 && e.mouseMove.x<170){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(104,24));
   	  toolType.setString(tip[4]);
   	  toolType.setPosition(e.mouseMove.x+26,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   	if(e.mouseMove.x>170 && e.mouseMove.x<194){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(116,24));
   	  toolType.setString(tip[5]);
   	  toolType.setPosition(e.mouseMove.x+26,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   	if(e.mouseMove.x>196 && e.mouseMove.x<218){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(94,24));
   	  toolType.setString(tip[6]);
   	  toolType.setPosition(e.mouseMove.x+25,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   	if(e.mouseMove.x>220 && e.mouseMove.x<248){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(124,24));
   	  toolType.setString(tip[7]);
   	  toolType.setPosition(e.mouseMove.x+26,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   	if(e.mouseMove.x>248 && e.mouseMove.x<276){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(132,24));
   	  toolType.setString(tip[8]);
   	  toolType.setPosition(e.mouseMove.x+26,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   	if(e.mouseMove.x>276 && e.mouseMove.x<304){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(88,24));
   	  toolType.setString(tip[9]);
   	  toolType.setPosition(e.mouseMove.x+25,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   	if(e.mouseMove.x>304 && e.mouseMove.x<332){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(112,24));
   	  toolType.setString(tip[10]);
   	  toolType.setPosition(e.mouseMove.x+26,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   	if(e.mouseMove.x>334 && e.mouseMove.x<360){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(120,24));
   	  toolType.setString(tip[11]);
   	  toolType.setPosition(e.mouseMove.x+26,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   	if(e.mouseMove.x>360 && e.mouseMove.x<388){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(70,24));
   	  toolType.setString(tip[12]);
   	  toolType.setPosition(e.mouseMove.x+25,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   	if(e.mouseMove.x>388 && e.mouseMove.x<416){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(70,24));
   	  toolType.setString(tip[13]);
   	  toolType.setPosition(e.mouseMove.x+26,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   	if(e.mouseMove.x>416 && e.mouseMove.x<444){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(70,24));
   	  toolType.setString(tip[14]);
   	  toolType.setPosition(e.mouseMove.x+25,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   	if(e.mouseMove.x>504 && e.mouseMove.x<580){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(174,24));
   	  toolType.setString(tip[15]);
   	  toolType.setPosition(e.mouseMove.x+28,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   	if(e.mouseMove.x>630 && e.mouseMove.x<665){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(100,24));
   	  toolType.setString(tip[16]);
   	  toolType.setPosition(e.mouseMove.x+25,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   	if(e.mouseMove.x>696 && e.mouseMove.x<726){
   	  bkgToolType.setPosition(e.mouseMove.x+20,e.mouseMove.y+20);
   	  bkgToolType.setFillColor(sf::Color(203,213,217,255));
   	  bkgToolType.setSize(sf::Vector2f(72,24));
   	  toolType.setString(tip[17]);
   	  toolType.setPosition(e.mouseMove.x+25,e.mouseMove.y+24);
   	  toolType.setFillColor(sf::Color(0,0,0,255));
   	}
   }
   
   if(e.mouseMove.y>30){
   bkgToolType.setFillColor(sf::Color(203,213,217,0));
	toolType.setFillColor(sf::Color(0,0,0,0));
	}
	objetCoordFromPDessus(e.mouseMove.x, e.mouseMove.y);
	if(flagObjActif==1 && e.mouseMove.x<verticalBar.getPosition().x && e.mouseMove.y<horizontalBar.getPosition().y){
		
		sf::Vector2f obj=objetCoordFromPDessus(e.mouseMove.x, e.mouseMove.y);
		float mx;
		float my;
		switch (objMove){
			case 0:
				tabEntree[objActif].z=obj.x;
				tabEntree[objActif].x=obj.y;
				gain(objActif);
				break;
			case 1:
				mx=(e.mouseMove.x-oldPosX)*(2.0/verticalBar.getPosition().x);
				my=(e.mouseMove.y-oldPosY)*(2.0/(horizontalBar.getPosition().y-26));
				
				for(int i=0;i<tabEntree.size();i++){
					if(tabEntree[i].groupe==tabEntree[objActif].groupe){
						tabEntree[i].z=tabEntree[i].z+mx;
						tabEntree[i].x=tabEntree[i].x+my;
						if(tabEntree[i].z<-1){
							tabEntree[i].z=-1;
						}
						if(tabEntree[i].z>1){
							tabEntree[i].z=1;
						}
						if(tabEntree[i].x<-1){
							tabEntree[i].x=-1;
						}
						if(tabEntree[i].x>1){
							tabEntree[i].x=1;
						}
						gain(i);
					}
				}
			   break;
			case 2:
				mx=(e.mouseMove.x-oldPosX)*(2.0/verticalBar.getPosition().x);
				my=(e.mouseMove.y-oldPosY)*(2.0/verticalBar.getPosition().x);
				for(int i=0;i<tabEntree.size();i++){
						tabEntree[i].z=tabEntree[i].z+mx;
						tabEntree[i].x=tabEntree[i].x+my;
						if(tabEntree[i].z<-1){
							tabEntree[i].z=-1;
						}
						if(tabEntree[i].z>1){
							tabEntree[i].z=1;
						}
						if(tabEntree[i].x<-1){
							tabEntree[i].x=-1;
						}
						if(tabEntree[i].x>1){
							tabEntree[i].x=1;
						}
						gain(i);
				}
			   break;
		}
		oldPosX=e.mouseMove.x;
		oldPosY=e.mouseMove.y;
	}
	if(flagObjActif==1 && e.mouseMove.x>verticalBar.getPosition().x+10 && e.mouseMove.y<horizontalBar.getPosition().y){
		sf::Vector2f obj=objetCoordFromPDroite(e.mouseMove.x, e.mouseMove.y);
		float mx;
		float my;
		switch (objMove){
			case 0:
				tabEntree[objActif].z=obj.x;
				tabEntree[objActif].y=obj.y;
				gain(objActif);
				break;
			case 1:
				mx=(e.mouseMove.x-oldPosX)*(2.0/verticalBar.getPosition().x);
				my=(e.mouseMove.y-oldPosY)*(2.0/(horizontalBar.getPosition().y-26));
				
				for(int i=0;i<tabEntree.size();i++){
					if(tabEntree[i].groupe==tabEntree[objActif].groupe){
						tabEntree[i].z=tabEntree[i].z+mx;
						tabEntree[i].y=tabEntree[i].y+my;
						if(tabEntree[i].z<-1){
							tabEntree[i].z=-1;
						}
						if(tabEntree[i].z>1){
							tabEntree[i].z=1;
						}
						if(tabEntree[i].y<-1){
							tabEntree[i].y=-1;
						}
						if(tabEntree[i].y>1){
							tabEntree[i].y=1;
						}
						gain(i);
					}
				}
			   break;
			case 2:
				mx=(e.mouseMove.x-oldPosX)*(2.0/verticalBar.getPosition().x);
				my=(e.mouseMove.y-oldPosY)*(2.0/verticalBar.getPosition().x);
				for(int i=0;i<tabEntree.size();i++){
						tabEntree[i].z=tabEntree[i].z+mx;
						tabEntree[i].y=tabEntree[i].y+my;
						if(tabEntree[i].z<-1){
							tabEntree[i].z=-1;
						}
						if(tabEntree[i].z>1){
							tabEntree[i].z=1;
						}
						if(tabEntree[i].y<-1){
							tabEntree[i].y=-1;
						}
						if(tabEntree[i].y>1){
							tabEntree[i].y=1;
						}
						gain(i);
				}
			   break;
		}
		oldPosX=e.mouseMove.x;
		oldPosY=e.mouseMove.y;
	}
	if(flagObjActif==1 && e.mouseMove.x<verticalBar.getPosition().x && e.mouseMove.y>horizontalBar.getPosition().y+10){
		sf::Vector2f obj=objetCoordFromPArriere(e.mouseMove.x, e.mouseMove.y);
		
		float mx;
		float my;
		switch (objMove){
			case 0:
				tabEntree[objActif].x=obj.x;
				tabEntree[objActif].y=obj.y;
				gain(objActif);
				break;
			case 1:
				mx=(e.mouseMove.x-oldPosX)*(2.0/verticalBar.getPosition().x);
				my=(e.mouseMove.y-oldPosY)*(2.0/(horizontalBar.getPosition().y-26));
				
				for(int i=0;i<tabEntree.size();i++){
					if(tabEntree[i].groupe==tabEntree[objActif].groupe){
						tabEntree[i].x=tabEntree[i].x+mx;
						tabEntree[i].y=tabEntree[i].y+my;
						if(tabEntree[i].x<-1){
							tabEntree[i].x=-1;
						}
						if(tabEntree[i].x>1){
							tabEntree[i].x=1;
						}
						if(tabEntree[i].y<-1){
							tabEntree[i].y=-1;
						}
						if(tabEntree[i].y>1){
							tabEntree[i].y=1;
						}
						gain(i);
					}
				}
			   break;
			case 2:
				mx=(e.mouseMove.x-oldPosX)*(2.0/verticalBar.getPosition().x);
				my=(e.mouseMove.y-oldPosY)*(2.0/verticalBar.getPosition().x);
				for(int i=0;i<tabEntree.size();i++){
						tabEntree[i].x=tabEntree[i].x+mx;
						tabEntree[i].y=tabEntree[i].y+my;
						if(tabEntree[i].x<-1){
							tabEntree[i].x=-1;
						}
						if(tabEntree[i].x>1){
							tabEntree[i].x=1;
						}
						if(tabEntree[i].y<-1){
							tabEntree[i].y=-1;
						}
						if(tabEntree[i].y>1){
							tabEntree[i].y=1;
						}
						gain(i);
				}
			   break;
		}
		oldPosX=e.mouseMove.x;
		oldPosY=e.mouseMove.y;
	}

	if(flagDistance==1 && e.mouseMove.x>verticalBar.getPosition().x+10 && e.mouseMove.y>horizontalBar.getPosition().y+10){ // move distance
      sf::Vector3f obj=objetDistance(e.mouseMove.x,e.mouseMove.y);
      float dt=1-(obj.z/192);
      
   	//std::cout << " cx1 " <<tabEntree[objActif].dx<< " cy1 " <<tabEntree[objActif].dy<< " d " <<dt<< std::endl;	
		float my;
		float mx;
		switch (objMove){
			case 0:
				if(dt>0){
					tabEntree[objActif].dx=e.mouseMove.x;
	   			tabEntree[objActif].dy=e.mouseMove.y;
	   			tabEntree[objActif].d=1-(obj.z/96);
	   		}
				defDistance(objActif);
				break;
			case 1:
				for(int i=0;i<tabEntree.size();i++){
					if(tabEntree[i].groupe==tabEntree[objActif].groupe){
						if(dt>0){
							tabEntree[i].dx=e.mouseMove.x;
	   					tabEntree[i].dy=e.mouseMove.y;
	   					tabEntree[i].d=1-(obj.z/96);
	   				}
					defDistance(i);
					}
				}
			   break;
			case 2:
				for(int i=0;i<tabEntree.size();i++){
					if(dt>0){
						tabEntree[i].dx=e.mouseMove.x;
   					tabEntree[i].dy=e.mouseMove.y;
   					tabEntree[i].d=1-(obj.z/96);
   				}
						defDistance(i);
				}
			   break;
		}
		
		oldPosX=e.mouseMove.x;
		oldPosY=e.mouseMove.y;
	}
}


void refInput(sf::Event e){
   int key=e.key.code;
   stringstream adr;
   if (e.text.unicode < 128){
		if(key==8){
	      apptxt=apptxt.substr(0,apptxt.length()-1);
	 	}else{
			apptxt=apptxt+static_cast<char>(e.text.unicode);
			flagTxt=1;
		}
		switch (inpIndex){
       		case 1:
       			inpBarText.setString(apptxt);
	      		inpBarText.setPosition(551-inpBarText.getLocalBounds().width-6,4);
	      		inpIndex=0;
       			break;
       		case 2:
       			if(apptxt==""){
       				apptxt="1";
       			}
       			adr << std::fixed<< std::setprecision(0)<<apptxt;
       			pTheta=stoi(adr.str());
       			inpBarText2.setString(to_string((int)pTheta));
       			inpBarText2.setPosition(658-inpBarText2.getLocalBounds().width-6,4);
       			break;
       		default:
       			break;
	    }
	    
   }
   
}
void newInstanceSpace(){
	string defApp=defInstall+"/multiSpace3D.sh &";
	system(defApp.c_str());
}
void newSurface(){
	string cmd=defInstall+"/spaceCreate " +defInstall+" "+home+" &";
   char* dest = new char[cmd.length() + 1];
   std::copy(cmd.begin(), cmd.end(), dest);
   std::cout << " space " << cmd << std::endl;
   system(dest);
}

void saveSpace(){
	string path=getcwd(NULL,0);
	fileSelector.initSelector(path);
	nameFile=fileSelector.selector();
	//std::cout << " save space " << nameFile << std::endl;

	string wfile=fileSelector.getPath()+"/"+nameFile;
	//std::cout << "wfile" << wfile << std::endl;
	//std::cout << "file :"<<wfile<< std::endl;
	if(nameFile!=""){
		ofstream fichier(wfile, ios::out | ios::trunc);
		if(fichier){
			for(int i=0;i<tabEntree.size();i++){
				fichier<<tabEntree[i].input<<","<<tabEntree[i].track<<","<<tabEntree[i].greffon<<","<<tabEntree[i].groupe<<","<<tabEntree[i].x<<","<<tabEntree[i].y<<","<<tabEntree[i].z<<","<<tabEntree[i].dx<<","<<tabEntree[i].dy<<","<<tabEntree[i].d<<","<< endl;
		   }
	   }else{  // sinon
     		cerr << "Erreur à l'ouverture du fichier!" << endl;
		}
	   fichier.close();
   }

}
void openSpace(){
	string path=getcwd(NULL,0);
	fileSelector.initSelector(path);
	nameFile=fileSelector.selector();
	std::string::size_type sz;
	string contenu;
	size_t pos = 0;
	std::string token[10];
	std::string delimiter = ",";
	entree nsp;
	//string nameFile;
	//nameFile=inpTextFile.getString();
	//std::cout << "path "<< fileSelector.getPath()<<" open space " << nameFile << std::endl;
	string wfile=fileSelector.getPath()+"/"+nameFile;
	//std::cout << "wfile" << wfile << std::endl;
	
	int i=0;
	//std::cout << "file :"<<wfile<< std::endl;
	if(nameFile!=""){
		tabEntree.clear(); 
		ifstream fichier(wfile, ios::in);
		if(fichier){
			while(getline(fichier, contenu)){
				//std::cout << "ligne :"<<contenu<< std::endl;
				while ((pos = contenu.find(delimiter)) != std::string::npos) {
    				token[i] = contenu.substr(0, pos);
    				//std::cout << token[i] << std::endl;
    				i++;
    				contenu.erase(0, pos + delimiter.length());
				}
				i=0;
				nsp.input=stoi(token[0]);
				nsp.track=stoi(token[1]);
				nsp.greffon=stoi(token[2]);
				nsp.groupe=stoi(token[3]);
				nsp.x=stof(token[4],&sz);
				nsp.y=stof(token[5]);
				nsp.z=stof(token[6]);
				nsp.dx=stof(token[7],&sz);
				nsp.dy=stof(token[8]);
				nsp.d=stof(token[9]);
				nsp.r=defautR;
		      nsp.scale=1;
				
				nsp.spriteD.setTexture(tabTexture[nsp.groupe]);
				nsp.spriteR.setTexture(tabTexture[nsp.groupe]);
				nsp.spriteA.setTexture(tabTexture[nsp.groupe]);
				nsp.sprite3D.setTexture(tabTexture[nsp.groupe]);
				tabEntree.push_back(nsp);
			}
	   }else{  // sinon
     		cerr << "Erreur à l'ouverture du fichier!" << endl;
		}
	   fichier.close();
   }
   
}
//***************************************************************************************************************
//																Fenêtre Param
//***************************************************************************************************************
void onResizedParam(sf::Event e){
	sf::FloatRect visibleArea(0, 0, e.size.width, e.size.height);
   winParam.setView(sf::View(visibleArea));
}
void newParamText(sf::Event e){
   int key=e.key.code;
   stringstream adr;
   if (e.text.unicode < 128){
		if(key==8){
	      apptxt=apptxt.substr(0,apptxt.length()-1);
	 	}else{
			apptxt=apptxt+static_cast<char>(e.text.unicode);
			flagTxt=1;
		}
		switch (inpIndex2){
       		case 1:
       			prefServeur=apptxt;
       			defServeur.setString(apptxt);
       			defServeur.setPosition(378-defServeur.getLocalBounds().width-2,92);
       			break;
       		case 2:
       				if(apptxt.length()>0){
		       			adr << std::fixed<< std::setprecision(0)<<apptxt;
		       			prefPortD=stoi(adr.str());
		       			defPort.setString(to_string(prefPortD));
		       			defPort.setPosition(458-defPort.getLocalBounds().width-2,92);
		       			adr.clear();
	  						adr.str("");
  						} 
       			break;
       		default:
       			break;
	    }
	    
   }
   
}
void onClickParam(sf::Event e){
	if (e.mouseButton.button == sf::Mouse::Left){
 		//std::cout << " Palette the left button was pressed" << std::endl;
 		//std::cout << "mouse x: " << e.mouseButton.x << std::endl;
 		//std::cout << "mouse y: " << e.mouseButton.y << std::endl;
   }
   if(e.mouseButton.x>54 && e.mouseButton.x<68 && e.mouseButton.y>58 && e.mouseButton.y<72){
   	confDaw1.setPosition(sf::Vector2f(56, 59));
   	prefDAW=0;
   }
   if(e.mouseButton.x>54 && e.mouseButton.x<68 && e.mouseButton.y>84 && e.mouseButton.y<100){
   	confDaw1.setPosition(sf::Vector2f(56, 87));
   	prefDAW=1;
   }
   if(e.mouseButton.x>54 && e.mouseButton.x<68 && e.mouseButton.y>114 && e.mouseButton.y<130){
   	confDaw1.setPosition(sf::Vector2f(56, 114));
   	prefDAW=2;
   }
   if(e.mouseButton.x>294 && e.mouseButton.x<380 && e.mouseButton.y>92 && e.mouseButton.y<112){
   	inpIndex2=1;
   	apptxt="";
   	defServeur.setString("");
   	winInpCurseur.setPosition(378,94);
	 	flagInpCurseur=1;
	 	clockCurseur.restart();
	}
	if(e.mouseButton.x>416 && e.mouseButton.x<462 && e.mouseButton.y>92 && e.mouseButton.y<112){
   	inpIndex2=2;
   	apptxt="";
   	defPort.setString("");
   	winInpCurseur.setPosition(458,94);
	 	flagInpCurseur=1;
	 	clockCurseur.restart();
	}
	if(e.mouseButton.x>418 && e.mouseButton.x<468 && e.mouseButton.y>136 && e.mouseButton.y<164){
   	validerParam();
   	winParam.close();
   }
   if(e.mouseButton.x>358 && e.mouseButton.x<414 && e.mouseButton.y>136 && e.mouseButton.y<164){
   	winParam.close();
   }
}

void validerParam(){
	char * cstr = new char [pref.length()+1];
	std::strcpy (cstr, pref.c_str());
	int ncwd=chdir(cstr);
	string nameFile="preferences.spc";
	ofstream fichier(nameFile, ios::out | ios::trunc);
	if(fichier){  // si l'ouverture a réussi
      fichier<<"DAW="<< prefDAW<<endl;
      fichier<<"destination="<< prefServeur<<endl;
      fichier<<"portD="<< prefPortD<<endl;
      fichier<<"track="<< defTrack<<endl;
		fichier.close();  // on referme le fichier
   }else{  // sinon
     cerr << "Erreur à l'ouverture Préférences!" << endl;
	}
}
void readParam(){
	char * cstr = new char [pref.length()+1];
	std::strcpy (cstr, pref.c_str());
	int ncwd=chdir(cstr);
	string nameFile="preferences.spc";
	ifstream fichier(nameFile, ios::in);
	string contenu;
	string pf[2];
	int i=0;
	if(fichier){  // si l'ouverture a réussi
		while(getline(fichier, contenu)){
	     	cstr = new char [contenu.length()+1];
	     	std::strcpy (cstr, contenu.c_str());
	     	char * p = std::strtok (cstr,"=");
			i=0;
			while (p!=0){
 				pf[i]=p;
 				i++;
				p = std::strtok(NULL," ");
  			}
  			if(pf[0]=="DAW"){
	  			prefDAW=stoi(pf[1]);
  			}
  			if(pf[0]=="destination"){
	  			prefServeur=pf[1];
	  			defServeur.setString(prefServeur);
  			}
  			if(pf[0]=="portD"){
	  			prefPortD=stoi(pf[1]);
	  			defPort.setString(pf[1]);
  			}
  		}
  		fichier.close();  // on referme le fichier
   }else{  // sinon
     cerr << "Erreur à l'ouverture Préférences!" << endl;
	}
	if(prefDAW==0){
  		confDaw1.setPosition(sf::Vector2f(56, 59));
	}
   if(prefDAW==1){
   	confDaw1.setPosition(sf::Vector2f(56, 87));
   }
   if(prefDAW==2){
   	confDaw1.setPosition(sf::Vector2f(56, 114));
	}	
}
void onMouseMoveParam(sf::Event e){
	//std::cout << "Window Param mouse x: " << e.mouseMove.x << std::endl;
   //std::cout << "mouse y: " << e.mouseMove.y << std::endl;
   
}


//*****************************************************************************************************************
//																Gestion des objets
//*****************************************************************************************************************
void objetCoordCtrl(int id){
	if(tabEntree[id].x<-1){
		tabEntree[id].x=-1;
	}
	if(tabEntree[id].x>1){
		tabEntree[id].x=1;
	}
	if(tabEntree[id].y<-1){
		tabEntree[id].y=-1;
	}
	if(tabEntree[id].y>1){
		tabEntree[id].y=1;
	}
	if(tabEntree[id].z<-1){
		tabEntree[id].z=-1;
	}
	if(tabEntree[id].z>1){
		tabEntree[id].z=1;
	}
}
void objetCreate(){
	entree ngen;
	ngen.input=tabEntree.size();
	ngen.groupe=defautGroupe;
	ngen.track=defautTrack;
	ngen.greffon=1;
	ngen.flagTrack=0;
	ngen.x=0.0;
	ngen.y=0.0;
	ngen.z=0.0;
	ngen.d=0.0;
	ngen.dx=centreDx;
	ngen.dy=centreDy;
	ngen.r=defautR;
	ngen.scale=1;
	ngen.spriteD.setTexture(tabTexture[defautGroupe]);
	ngen.spriteR.setTexture(tabTexture[defautGroupe]);
	ngen.spriteA.setTexture(tabTexture[defautGroupe]);
	ngen.sprite3D.setTexture(tabTexture[defautGroupe]);
	tabEntree.push_back(ngen);
	objActif=tabEntree.size()-1;
	inpBarText.setString(to_string(tabEntree[objActif].track));
	inpText.setString(to_string(tabEntree[objActif].track));
	inpText.setPosition(120-inpText.getLocalBounds().width-2,10);
	gain(objActif);
std::cout << " objetCreate "<< tabEntree.size()<< std::endl;

}
void nSelectMixer(){
	string s=inpBarText.getString();
	int nwMixer=stoi(s);
	int flag=0;
	for(int i=0;i<tabEntree.size();i++){
		if(tabEntree[i].track==nwMixer){
			objActif=i;
			flag=1;
			inpText.setString(to_string(tabEntree[i].track));
			break;
		}
	}
	if(flag==0){
		entree ngen;
		ngen.input=nwMixer;
		ngen.groupe=defautGroupe;
		ngen.track=stoi(s);
		ngen.greffon=1;
		ngen.flagTrack=0;
		ngen.x=0.0;
		ngen.y=0.0;
		ngen.z=0.0;
		ngen.d=0.0;
		ngen.dx=centreDx;
	   ngen.dy=centreDy;
		ngen.r=defautR;
		ngen.scale=1;
		ngen.spriteD.setTexture(tabTexture[defautGroupe]);
		ngen.spriteR.setTexture(tabTexture[defautGroupe]);
		ngen.spriteA.setTexture(tabTexture[defautGroupe]);
		ngen.sprite3D.setTexture(tabTexture[defautGroupe]);
		tabEntree.push_back(ngen);
		objActif=tabEntree.size()-1;
		string s=inpBarText.getString();
		inpText.setString(s);
		tabEntree[objActif].track=stoi(s);
		inpBarText.setString(to_string(tabEntree[objActif].track));
		gain(objActif);
	}
}
sf::Vector2f objetCoordToPDessus(float x, float y){
	float cx1= (x*(verticalBar.getPosition().x/2.0)+(verticalBar.getPosition().x/2.0))-(12*scaleWidth);
	float cy1= (y*(verticalBar.getPosition().x/2.0)+((horizontalBar.getPosition().y-28)/2.0)+28)-(12*scaleHeight);
	if(cy1<16){
		cy1=16;
	}
	if(cy1>horizontalBar.getPosition().y-12){
		cy1=horizontalBar.getPosition().y-12;
	}
	return sf::Vector2f(cx1,cy1);
}
sf::Vector2f objetCoordToPDroite(float x, float y){
	float cx1= (x*(verticalBar.getPosition().x/2.0)+(verticalBar.getPosition().x/2.0))-(12*scaleWidth)+(verticalBar.getPosition().x+10);
	float cy1= (y*((horizontalBar.getPosition().y-28)/2.0))+(((horizontalBar.getPosition().y-28)/2.0)+28)-(12*scaleHeight);
	
	return sf::Vector2f(cx1,cy1);
}
sf::Vector2f objetCoordToPArriere(float x, float y){
	float cx1= (x*(verticalBar.getPosition().x/2.0)+(verticalBar.getPosition().x/2.0))-(12*scaleWidth);
	float cy1= (y*((horizontalBar.getPosition().y-28)/2.0))+(((horizontalBar.getPosition().y-28)/2.0)+28)-(12*scaleHeight)+(horizontalBar.getPosition().y-22);
	return sf::Vector2f(cx1,cy1);
}

sf::Vector3f objetDistance(float x, float y){
	float d;
   float cx1= x;
	float cy1= y;
   			
   d=sqrt(pow((centreDx*scaleWidth)-cx1,2)+pow((centreDy*scaleHeight)-cy1,2));
   
	return sf::Vector3f(x,y,d);
}
sf::Vector3f objetCoordToP3D(float x, float y, float z){
	float lscale=((z*(verticalBar.getPosition().x/2.0))-(verticalBar.getPosition().x/2.0))/verticalBar.getPosition().x;
	if(lscale<0){
		lscale=-lscale;
	}
	if(lscale<0.33){
		lscale=0.33;
	}
	float cx1= ((x*lscale*((verticalBar.getPosition().x)/2.0)+((verticalBar.getPosition().x+10)/2.0))+verticalBar.getPosition().x+10)-(12*scaleHeight);
	float cy1= ((y*lscale*((horizontalBar.getPosition().y-28)/2.0))+(((horizontalBar.getPosition().y-28)/2.0))-(12*scaleHeight)+(horizontalBar.getPosition().y+10))+2;
	
	return sf::Vector3f(cx1,cy1,lscale);
}
sf::Vector2f objetCoordFromPDessus(float x, float y){
	float cx1=(2.0/verticalBar.getPosition().x)*(x-(verticalBar.getPosition().x/2.0));
	float cy1=(2.0/verticalBar.getPosition().x)*((y-28)-(horizontalBar.getPosition().y-28)/2.0);
	if(cx1<-1){
		cx1=-1;
	}
	if(cx1>1){
		cx1=1;
	}
	if(cy1<-1){
		cy1=-1;
	}
	if(cy1>1){
		cy1=1;
	}
	return sf::Vector2f(cx1,cy1);
}
sf::Vector2f objetCoordFromPDroite(float x, float y){
	float cx1=(2.0/verticalBar.getPosition().x)*(x-((verticalBar.getPosition().x/2.0)+verticalBar.getPosition().x+10));
	float cy1=(2.0/(horizontalBar.getPosition().y-28))*((y-28)-(horizontalBar.getPosition().y-28)/2.0);
	if(cx1<-1){
		cx1=-1;
	}
	if(cx1>1){
		cx1=1;
	}
	if(cy1<-1){
		cy1=-1;
	}
	if(cy1>1){
		cy1=1;
	}
	return sf::Vector2f(cx1,cy1);
}
sf::Vector2f objetCoordFromPArriere(float x, float y){
	float cx1=(2.0/verticalBar.getPosition().x)*(x-(verticalBar.getPosition().x/2.0));
	float cy1=(2.0/(horizontalBar.getPosition().y-28))*((y-28)-(((horizontalBar.getPosition().y-28)/2.0)+horizontalBar.getPosition().y-28));
	if(cx1<-1){
		cx1=-1;
	}
	if(cx1>1){
		cx1=1;
	}
	if(cy1<-1){
		cy1=-1;
	}
	if(cy1>1){
		cy1=1;
	}
	return sf::Vector2f(cx1,cy1);
}
sf::Vector2f objetCoordFromP3D(float x, float y){
	/*
	float cx1=(2.0/verticalBar.getPosition().x)*(x-((verticalBar.getPosition().x/2.0)+verticalBar.getPosition().x+10));
	float cy1=(2.0/(horizontalBar.getPosition().y-28))*((y-28)-(((horizontalBar.getPosition().y-28)/2.0)+horizontalBar.getPosition().y-28));
	if(cx1<-1){
		cx1=-1;
	}
	if(cx1>1){
		cx1=1;
	}
	if(cy1<-1){
		cy1=-1;
	}
	if(cy1>1){
		cy1=1;
	}
	return sf::Vector2f(cx1,cy1);
	*/
}

void delObjet(int obj){
	tabEntree[obj].x=0;
	tabEntree[obj].y=0;
	tabEntree[obj].z=0;
	gain(obj);
	tabEntree.erase(tabEntree.begin()+obj);
	objActif=65536;
}
void delGrpObjet(int obj){
	for(int i=0;i<tabEntree.size();i++){
		if(i!=obj && tabEntree[i].groupe==tabEntree[obj].groupe){
			tabEntree[i].x=0;
			tabEntree[i].y=0;
			tabEntree[i].z=0;
			gain(i);
			tabEntree.erase(tabEntree.begin()+i);
		}
	}
	tabEntree[obj].x=0;
	tabEntree[obj].y=0;
	tabEntree[obj].z=0;
	gain(obj);
	tabEntree.erase(tabEntree.begin()+obj);
	objActif=65536;
}
void delAllObjet(){
	for(int i=0;i<tabEntree.size();i++){
		tabEntree[i].x=0;
		tabEntree[i].y=0;
		tabEntree[i].z=0;
		gain(i);
	}
	tabEntree.clear();
	objActif=65536;
}
sf::Vector3f defGrpBarycentre(){
	sf::Vector3f baryGrp;
	float barX=0;
	float barY=0;
	float barZ=0;
	for(int i=0;i<tabEntree.size();i++){
		if(tabEntree[i].groupe==tabEntree[objActif].groupe){
			barX=barX+tabEntree[i].x;
			barY=barY+tabEntree[i].y;
			barZ=barZ+tabEntree[i].z;
		}
	}
	baryGrp.x=barX/tabEntree.size();
	baryGrp.y=barY/tabEntree.size();
	baryGrp.z=barZ/tabEntree.size();
	return baryGrp;
}
sf::Vector3f defBarycentre(){
	sf::Vector3f baryGrp;
	float barX=0;
	float barY=0;
	float barZ=0;
	for(int i=0;i<tabEntree.size();i++){
		barX=barX+tabEntree[i].x;
		barY=barY+tabEntree[i].y;
		barZ=barZ+tabEntree[i].z;
	}
	baryGrp.x=barX/tabEntree.size();
	baryGrp.y=barY/tabEntree.size();
	baryGrp.z=barZ/tabEntree.size();
	return baryGrp;
}
void defGrpExpansion(float dt){
	sf::Vector3f bary=defGrpBarycentre();
	for(int i=0;i<tabEntree.size();i++){
		if(tabEntree[i].groupe==tabEntree[objActif].groupe){
			if(tabEntree[i].x<=bary.x){
				tabEntree[i].x=tabEntree[i].x-dt;
				if(tabEntree[i].y<=bary.y){
					tabEntree[i].y=tabEntree[i].y-dt;
					if(tabEntree[i].z<=bary.z){
						tabEntree[i].z=tabEntree[i].z-dt;
					}else{
						tabEntree[i].z=tabEntree[i].z+dt;
					}	
				}else{
					tabEntree[i].y=tabEntree[i].y+dt;
					if(tabEntree[i].z<=bary.z){
						tabEntree[i].z=tabEntree[i].z-dt;
					}else{
						tabEntree[i].z=tabEntree[i].z+dt;
					}
				}
			}else{
				tabEntree[i].x=tabEntree[i].x+dt;
				if(tabEntree[i].y<=bary.y){
					tabEntree[i].y=tabEntree[i].y-dt;
					if(tabEntree[i].z<=bary.z){
						tabEntree[i].z=tabEntree[i].z-dt;
					}else{
						tabEntree[i].z=tabEntree[i].z+dt;
					}	
				}else{
					tabEntree[i].y=tabEntree[i].y+dt;
					if(tabEntree[i].z<=bary.z){
						tabEntree[i].z=tabEntree[i].z-dt;
					}else{
						tabEntree[i].z=tabEntree[i].z+dt;
					}
				}
			}
		}
		gain(i);
	}
}

void quaternionRotation(float a, float b, float c, float d){
	//std::cout <<  " quaternion arg0: "<< a<<" arg1: " << b <<" arg2: "<< c << std::endl;
	
	if(objActif!=65536){
		float v1new;
		float v2new;
		float v3new;
		
		if(a>90 && a<270){
			v1new=((2.0/179)*a)-2;
			if(v1new>1){
				v1new=1;
			}
			if(v1new>1){
				v1new=1;
			}
		}else{
			v1new=tabEntree[objActif].x;
		}
		v2new=tabEntree[objActif].y;
		if(b>-90 && b<90){
			v2new=(1.0/90)*b;
			if(v2new>1){
				v2new=1;
			}
			if(v2new<-1){
				v2new=-1;
			}
		}
		
		if(c>-90 && c<89){
			v3new=((1.0/89)*c);
			if(v3new>1){
				v3new=1;
			}
			if(v3new<-1){
				v3new=-1;
			}
		}else{
			v3new=tabEntree[objActif].z;
		}
		
		tabEntree[objActif].x=v1new;
		tabEntree[objActif].y=v2new;
		tabEntree[objActif].z=v3new;
		
		//std::cout <<  " rotation x: "<< v2new<<" y: " << v3new <<" z: "<< v1new << std::endl;
	}
}

void rotateY3D(){
	float cosAngle= cos(pTheta*M_PI/180);
  	float sinAngle= sin(pTheta*M_PI/180);
  	float newX;
  	float newY;
  	sf::Vector3f bary;
  	
  	switch(objMove){
		  case 0:
			   newX = (tabEntree[objActif].z)*cosAngle-(tabEntree[objActif].x)*sinAngle; // ligne modifiée
			   newY = (tabEntree[objActif].x)*cosAngle+(tabEntree[objActif].z)*sinAngle; // ligne modifiée
			   tabEntree[objActif].z =newX; // ligne ajoutée
			   tabEntree[objActif].x = newY; // ligne ajoutée
			   if(tabEntree[objActif].z>1){
	 				tabEntree[objActif].z=1;
	 			}
	 			if(tabEntree[objActif].z<-1){
	 				tabEntree[objActif].z=-1;
	 			}
	 			if(tabEntree[objActif].x>1){
	 				tabEntree[objActif].x=1;
	 			}
	 			if(tabEntree[objActif].x<-1){
	 				tabEntree[objActif].x=-1;
	 			}
				gain(objActif);
		  break;
		  case 1:
		  		bary=defGrpBarycentre();
		  		for(int i=0;i<tabEntree.size();i++){
				 	if(tabEntree[i].groupe==tabEntree[objActif].groupe){
		  				newX = (tabEntree[i].z-bary.z)*cosAngle-(tabEntree[i].x-bary.x)*sinAngle;
			   		newY = (tabEntree[i].x-bary.x)*cosAngle+(tabEntree[i].z-bary.z)*sinAngle;
		  				tabEntree[i].z =newX+bary.z; // ligne ajoutée
					   tabEntree[i].x = newY+bary.x; // ligne ajoutée
					   if(tabEntree[i].z>1){
			 				tabEntree[i].z=1;
			 			}
			 			if(tabEntree[i].z<-1){
			 				tabEntree[i].z=-1;
			 			}
			 			if(tabEntree[i].x>1){
			 				tabEntree[i].x=1;
			 			}
			 			if(tabEntree[i].x<-1){
			 				tabEntree[i].x=-1;
			 			}
			 			gain(i);
			 		}
			 	}
		  break;
		  case 2:
		  		bary=defBarycentre();
		  		for(int i=0;i<tabEntree.size();i++){
	  				newX = (tabEntree[i].z-bary.z)*cosAngle-(tabEntree[i].x-bary.x)*sinAngle;
		   		newY = (tabEntree[i].x-bary.x)*cosAngle+(tabEntree[i].z-bary.z)*sinAngle;
	  				tabEntree[i].z =newX+bary.z; // ligne ajoutée
				   tabEntree[i].x = newY+bary.x; // ligne ajoutée
				   if(tabEntree[i].z>1){
		 				tabEntree[i].z=1;
		 			}
		 			if(tabEntree[i].z<-1){
		 				tabEntree[i].z=-1;
		 			}
		 			if(tabEntree[i].x>1){
		 				tabEntree[i].x=1;
		 			}
		 			if(tabEntree[i].x<-1){
		 				tabEntree[i].x=-1;
		 			}
		 			gain(i);
			 	}
			break;
			default:
         break;
       }
}
void rotateX3D(){
	float cosAngle= cos(pTheta*M_PI/180);
  	float sinAngle= sin(pTheta*M_PI/180);
  	float newX;
  	float newY;
  	sf::Vector3f bary;
  	switch(objMove){
		  case 0:
			   newX = (tabEntree[objActif].z)*cosAngle-(tabEntree[objActif].y)*sinAngle; // ligne modifiée
			   newY = (tabEntree[objActif].y)*cosAngle+(tabEntree[objActif].z)*sinAngle; // ligne modifiée
			   tabEntree[objActif].z =newX; // ligne ajoutée
			   tabEntree[objActif].y = newY; // ligne ajoutée
			   if(tabEntree[objActif].z>1){
	 				tabEntree[objActif].z=1;
	 			}
	 			if(tabEntree[objActif].z<-1){
	 				tabEntree[objActif].z=-1;
	 			}
	 			if(tabEntree[objActif].y>1){
	 				tabEntree[objActif].y=1;
	 			}
	 			if(tabEntree[objActif].y<-1){
	 				tabEntree[objActif].y=-1;
	 			}
				gain(objActif);
		  break;
		  case 1:
		  		bary=defGrpBarycentre();
		  		for(int i=0;i<tabEntree.size();i++){
				 	if(tabEntree[i].groupe==tabEntree[objActif].groupe){
		  				newX = (tabEntree[i].z-bary.z)*cosAngle-(tabEntree[i].y-bary.y)*sinAngle;
			   		newY = (tabEntree[i].y-bary.y)*cosAngle+(tabEntree[i].z-bary.z)*sinAngle;
		  				tabEntree[i].z =newX+bary.z; // ligne ajoutée
					   tabEntree[i].y = newY+bary.y; // ligne ajoutée
					   if(tabEntree[i].z>1){
			 				tabEntree[i].z=1;
			 			}
			 			if(tabEntree[i].z<-1){
			 				tabEntree[i].z=-1;
			 			}
			 			if(tabEntree[i].y>1){
			 				tabEntree[i].y=1;
			 			}
			 			if(tabEntree[i].y<-1){
			 				tabEntree[i].y=-1;
			 			}
			 			gain(i);
			 		}
			 	}
		  break;
		  case 2:
		  		bary=defBarycentre();
		  		for(int i=0;i<tabEntree.size();i++){
	  				newX = (tabEntree[i].z-bary.z)*cosAngle-(tabEntree[i].y-bary.y)*sinAngle;
		   		newY = (tabEntree[i].y-bary.y)*cosAngle+(tabEntree[i].z-bary.z)*sinAngle;
	  				tabEntree[i].z =newX+bary.z; // ligne ajoutée
				   tabEntree[i].y = newY+bary.y; // ligne ajoutée
				   if(tabEntree[i].z>1){
		 				tabEntree[i].z=1;
		 			}
		 			if(tabEntree[i].z<-1){
		 				tabEntree[i].z=-1;
		 			}
		 			if(tabEntree[i].y>1){
		 				tabEntree[i].y=1;
		 			}
		 			if(tabEntree[i].y<-1){
		 				tabEntree[i].y=-1;
		 			}
		 			gain(i);
			 	}
			break;
			default:
         break;
       }
}
void rotateZ3D(){
	float cosAngle= cos(pTheta*M_PI/180);
  	float sinAngle= sin(pTheta*M_PI/180);
  	float newX;
  	float newY;
  	sf::Vector3f bary;
  	switch(objMove){
		  case 0:
			   newX = (tabEntree[objActif].x)*cosAngle-(tabEntree[objActif].y)*sinAngle; // ligne modifiée
			   newY = (tabEntree[objActif].y)*cosAngle+(tabEntree[objActif].x)*sinAngle; // ligne modifiée
			   tabEntree[objActif].x =newX; // ligne ajoutée
			   tabEntree[objActif].y = newY; // ligne ajoutée
			   if(tabEntree[objActif].x>1){
	 				tabEntree[objActif].x=1;
	 			}
	 			if(tabEntree[objActif].x<-1){
	 				tabEntree[objActif].x=-1;
	 			}
	 			if(tabEntree[objActif].y>1){
	 				tabEntree[objActif].y=1;
	 			}
	 			if(tabEntree[objActif].y<-1){
	 				tabEntree[objActif].y=-1;
	 			}
				gain(objActif);
		  break;
		  case 1:
		  		bary=defGrpBarycentre();
		  		for(int i=0;i<tabEntree.size();i++){
				 	if(tabEntree[i].groupe==tabEntree[objActif].groupe){
		  				newX = (tabEntree[i].x-bary.x)*cosAngle-(tabEntree[i].y-bary.y)*sinAngle;
			   		newY = (tabEntree[i].y-bary.y)*cosAngle+(tabEntree[i].x-bary.x)*sinAngle;
		  				tabEntree[i].x =newX+bary.x; // ligne ajoutée
					   tabEntree[i].y = newY+bary.y; // ligne ajoutée
					   if(tabEntree[i].x>1){
			 				tabEntree[i].x=1;
			 			}
			 			if(tabEntree[i].x<-1){
			 				tabEntree[i].x=-1;
			 			}
			 			if(tabEntree[i].y>1){
			 				tabEntree[i].y=1;
			 			}
			 			if(tabEntree[i].y<-1){
			 				tabEntree[i].y=-1;
			 			}
			 			gain(i);
			 		}
			 	}
		  break;
		  case 2:
		  		bary=defBarycentre();
		  		for(int i=0;i<tabEntree.size();i++){
	  				newX = (tabEntree[i].x-bary.x)*cosAngle-(tabEntree[i].y-bary.y)*sinAngle;
		   		newY = (tabEntree[i].y-bary.y)*cosAngle+(tabEntree[i].x-bary.x)*sinAngle;
	  				tabEntree[i].x =newX+bary.x; // ligne ajoutée
				   tabEntree[i].y = newY+bary.y; // ligne ajoutée
				   if(tabEntree[i].x>1){
		 				tabEntree[i].x=1;
		 			}
		 			if(tabEntree[i].x<-1){
		 				tabEntree[i].x=-1;
		 			}
		 			if(tabEntree[i].y>1){
		 				tabEntree[i].y=1;
		 			}
		 			if(tabEntree[i].y<-1){
		 				tabEntree[i].y=-1;
		 			}
		 			gain(i);
			 	}
			break;
			default:
         break;
       }
}
// ***********************************************************************************************************************************
//
// ***********************************************************************************************************************************
void defDistance(int in){
	int piid=0;
  	piid=0;
  	defTrack=tabEntree[in].track;
  	float vd=(1+tabEntree[in].d)/2;
  	float cvd=vd*vd*vd;
  	switch(prefDAW){
  		
  		case 0:
 				sendOSCcoordPluginArdour(defTrack,tabEntree[in].greffon,piid+6,20+(19980*cvd));
 				sendOSCcoordPluginArdour(defTrack,tabEntree[in].greffon,piid+10,(vd*12)-12);
 				sendOSCcoordPluginArdour(defTrack,tabEntree[in].greffon,piid+12,990-(1000*vd));
 				sendOSCcoordPluginArdour(defTrack,tabEntree[in].greffon,piid+19,1-vd);
 				sendOSCcoordPluginArdour(defTrack,tabEntree[in].greffon,piid+20,vd);
 		   	break;
 		case 1:
 		   	sendOSCcoordPluginCarla(tabEntree[in].greffon-1,piid+5,20+(19980*cvd));
 		   	sendOSCcoordPluginCarla(tabEntree[in].greffon-1,piid+9,(vd*12)-12);
 		   	sendOSCcoordPluginCarla(tabEntree[in].greffon-1,piid+11,980-(1000*(tabEntree[in].d)));
 		   	sendOSCcoordPluginCarla(tabEntree[in].greffon-1,piid+18,1-vd);
 		   	sendOSCcoordPluginCarla(tabEntree[in].greffon-1,piid+19,vd);
 		   	break;
 		case 2:
 				sendOSCcoordPluginReaper2(defTrack,tabEntree[in].greffon,piid+6,tabEntree[in].d);
 				sendOSCcoordPluginReaper(defTrack,tabEntree[in].greffon,piid+10,(tabEntree[in].d/2)-0.5);
 				sendOSCcoordPluginReaper(defTrack,tabEntree[in].greffon,piid+12,1-(1+tabEntree[in].d));
 				sendOSCcoordPluginReaper(defTrack,tabEntree[in].greffon,piid+19,1-(1+tabEntree[in].d));
 				sendOSCcoordPluginReaper(defTrack,tabEntree[in].greffon,piid+20,tabEntree[in].d);
 		   	break;
 	   default:
 		   	break;
 		}
}
void gain(int in){
	int piid=0;
  	piid=0;
  	defTrack=tabEntree[in].track;
  	switch(prefDAW){
  		case 0:
 				sendOSCcoordPluginArdour(defTrack,tabEntree[in].greffon,piid+1,tabEntree[in].x);
 				sendOSCcoordPluginArdour(defTrack,tabEntree[in].greffon,piid+2,tabEntree[in].y);
 				sendOSCcoordPluginArdour(defTrack,tabEntree[in].greffon,piid+3,tabEntree[in].z);	
 		   	break;
 		case 1:
 		   	sendOSCcoordPluginCarla(tabEntree[in].greffon-1,piid,tabEntree[in].x);
 		   	sendOSCcoordPluginCarla(tabEntree[in].greffon-1,piid+1,tabEntree[in].y);
 		   	sendOSCcoordPluginCarla(tabEntree[in].greffon-1,piid+2,tabEntree[in].z);
 		   	break;
 		case 2:
 				sendOSCcoordPluginReaper(defTrack,tabEntree[in].greffon,piid+1,tabEntree[in].x);
 		   	sendOSCcoordPluginReaper(defTrack,tabEntree[in].greffon,piid+2,-tabEntree[in].y);
 		   	sendOSCcoordPluginReaper(defTrack,tabEntree[in].greffon,piid+3,tabEntree[in].z);
 		   	break;
 	   default:
 		   	break;
 		}
	//std::cout<< " dtrack "<<defTrack<<" in " <<tabEntree[in].input<<" x "<<tabEntree[in].x<<" y "<<tabEntree[in].y<<" z "<<tabEntree[in].z << std::endl;
}
void sendOSCcoordPluginArdour(int track,int plug,int piid,float value){
 lo::Address a(prefServeur, prefPortD);
 a.send("/strip/plugin/parameter", "iiif",track,plug,piid,value); 
}
void sendOSCcoordPluginCarla(int track,int piid,float value){
 std::stringstream adr;
 lo::Address a(prefServeur, prefPortD);
 adr << std::fixed << "/Carla/"<<track<<"/set_parameter_value";
 string message=adr.str();
 adr.clear();
 adr.str("");
 a.send(message, "if", piid, value); 
 //std::cout << "message carla= "<<message<<" gain= "<<value << std::endl;
}
void sendOSCcoordPluginReaper(int track,int plug,int piid,float value){
 std::stringstream adr;
 lo::Address a(prefServeur, prefPortD);
 adr << std::fixed << "/track/"<<track<<"/fx/"<<plug<<"/fxparam/"<<piid<<"/value";
 string message=adr.str();
 adr.clear();
 adr.str("");
 a.send(message, "f", (value+1)/2); 
 //std::cout << "message reaper= "<<message<<" param= "<<(value+1)/2 << std::endl;
}
void sendOSCcoordPluginReaper2(int track,int plug,int piid,float value){
 std::stringstream adr;
 lo::Address a(prefServeur, prefPortD);
 adr << std::fixed << "/track/"<<track<<"/fx/"<<plug<<"/fxparam/"<<piid<<"/value";
 string message=adr.str();
 adr.clear();
 adr.str("");
 float vl=(value+1)/2;
 float dvl=vl*vl*vl;
 a.send(message, "f", dvl); 
 //std::cout << "message reaper= "<<message<<" param= "<<dvl << std::endl;
}
