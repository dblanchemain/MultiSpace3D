declare name        "objMatrixMicadome"; // modifier le nom de votre greffon
declare version     "1.0";
declare author      "D.Blanchemain";
declare license     "BSD";
declare copyright   "(c)D.Blanchemain 2020";
import("stdfaust.lib");
Matrix(N,M) =_:filters(1):delay:freeverb(1)<: par(out, M, *(Fader(1,out): si.smoo)) :> par(out, M, _)
with {
tabSpeakerX(0)=-0.437;
tabSpeakerY(0)=-0.388;
tabSpeakerZ(0)=0.965;
tabSpeakerD(0)=1.128;
tabSpeakerX(1)=0.373;
tabSpeakerY(1)=-0.388;
tabSpeakerZ(1)=0.970;
tabSpeakerD(1)=1.109;
tabSpeakerX(2)=-1.000;
tabSpeakerY(2)=-0.388;
tabSpeakerZ(2)=0.399;
tabSpeakerD(2)=1.144;
tabSpeakerX(3)=1.000;
tabSpeakerY(3)=-0.388;
tabSpeakerZ(3)=0.409;
tabSpeakerD(3)=1.148;
tabSpeakerX(4)=-1.000;
tabSpeakerY(4)=-0.388;
tabSpeakerZ(4)=-0.515;
tabSpeakerD(4)=1.190;
tabSpeakerX(5)=1.000;
tabSpeakerY(5)=-0.388;
tabSpeakerZ(5)=-0.515;
tabSpeakerD(5)=1.190;
tabSpeakerX(6)=-0.412;
tabSpeakerY(6)=-0.388;
tabSpeakerZ(6)=-1.000;
tabSpeakerD(6)=1.149;
tabSpeakerX(7)=0.383;
tabSpeakerY(7)=-0.388;
tabSpeakerZ(7)=-1.000;
tabSpeakerD(7)=1.139;
tabSpeakerX(8)=-0.793;
tabSpeakerY(8)=0.412;
tabSpeakerZ(8)=0.242;
tabSpeakerD(8)=0.926;
tabSpeakerX(9)=0.822;
tabSpeakerY(9)=0.412;
tabSpeakerZ(9)=0.247;
tabSpeakerD(9)=0.952;
tabSpeakerX(10)=-0.798;
tabSpeakerY(10)=0.412;
tabSpeakerZ(10)=-0.354;
tabSpeakerD(10)=0.965;
tabSpeakerX(11)=0.802;
tabSpeakerY(11)=0.412;
tabSpeakerZ(11)=-0.348;
tabSpeakerD(11)=0.967;
tabSpeakerX(12)=-0.062;
tabSpeakerY(12)=0.412;
tabSpeakerZ(12)=0.803;
tabSpeakerD(12)=0.905;
tabSpeakerX(13)=-0.062;
tabSpeakerY(13)=0.412;
tabSpeakerZ(13)=-0.793;
tabSpeakerD(13)=0.896;
tabSpeakerX(14)=-0.244;
tabSpeakerY(14)=1.000;
tabSpeakerZ(14)=-0.056;
tabSpeakerD(14)=1.031;
tabSpeakerX(15)=0.121;
tabSpeakerY(15)=1.000;
tabSpeakerZ(15)=-0.051;
tabSpeakerD(15)=1.009;

dtencGen(in, out) = sqrt(pow(tabSpeakerX(out)-x(in),2) + pow(tabSpeakerY(out)-y(in),2) + pow(tabSpeakerZ(out)-z(in),2));
dgain(in, out) = ba.db2linear((-50/tabSpeakerD(out))*dtencGen(in,out));
x(i) = hslider("/X%i",0,-1,1,0.01);
y(i) = hslider("/Y%i",0,-1,1,0.01);
z(i) = hslider("/Z%i",0,-1,1,0.01);
Fader(in,out)= vgroup("[1]Input %2in",dgain(in,out));
cdistance(in)=sqrt(pow(0-x(in),2) + pow(0-y(in),2) + pow(0-z(in),2));
paramDistance(x)=hgroup("[2]Distance",x);
//-----------------------------------------------------------
//                   LPF 
//-----------------------------------------------------------
minfreq=paramDistance(vslider("LPF Min",100, 20, 2000, 1));
ampfreq=paramDistance(vslider("LPF Amp",5000, 20, 19980, 1));
rpf(in)=minfreq+(ampfreq*min(1,cdistance(in))):floor;
LPF(in)=fi.lowpass(3,rpf(in));
fbp = checkbox("[0] Bypass  [tooltip: When this is checked, the filters has no effect]");
filters(in)=paramDistance(vgroup("FILTERS",ba.bypass1(fbp,hgroup("[1]",LPF(in)))));
//-----------------------------------------------------------
//                  Delay
//-----------------------------------------------------------
delay_group(x) = paramDistance(vgroup("[2]DELAY", x));
cbp =delay_group(vgroup("[0]",checkbox("Bypass	[tooltip: When this is checked, Delay has no effect]")));
voice   = delay_group(vgroup("[1]",(+ : de.sdelay(N, interp, dtime)) ~ *(fback)));
N = int(2^19);
interp  = hslider("interpolation[unit:ms][style:knob]",10,1,100,0.1)*ma.SR/1000.0;
maxtime = hslider("maxtime[style:knob]",100,0,5000,0.1);
fback = hslider("feedback[style:knob]",0,0,100,0.1)/100.0;
dtime = maxtime-(maxtime*min(1,cdistance(1))*ma.SR/1000.0);
delay = ba.bypass1(cbp,voice);
//-----------------------------------------------------------
//                 Freeverb
//-----------------------------------------------------------
scaleroom   = 0.28;
offsetroom  = 0.7;
allpassfeed = 0.5;
scaledamp   = 0.4;
fixedgain   = 0.1;
origSR = 48000;
g=1-((1/1.73205)*min(1.73205,cdistance(1)));
freeverbMono=_<: (*(g)*fixedgain :re.mono_freeverb(combfeed, allpassfeed, damping, spatSpread)),*(1-g):> _;
parameters(x) = paramDistance(hgroup("[3]Freeverb",x));
knobGroup(x) = parameters(vgroup("[1]",x));
fvbp = knobGroup(checkbox("[0] Bypass	[tooltip: When this is checked, the freeverb	has no effect]"));
damping = knobGroup(vslider("[1] Damp [style: knob] [tooltip: Somehow control the density of the reverb.]",0.5, 0, 1, 0.025)*scaledamp*origSR/ma.SR);
combfeed = knobGroup(vslider("[2] RoomSize [style: knob] [tooltip: The room size	between 0 and 1 with 1 for the largest room.]", 0.5, 0, 1, 0.025)*scaleroom*origSR/ma.SR + offsetroom);
spatSpread = knobGroup(vslider("[3] Stereo Spread [style: knob] [tooltip: Spatial spread between 0 and 1 with 1 for maximum spread.]",0.5,0,1,0.01)*46*ma.SR/origSR: int);
freeverb(in) = ba.bypass1(fvbp,freeverbMono);
};
process = Matrix(1,16); // le deuxième chiffre permet de définir la dimension de votre espace :9,10, ...

