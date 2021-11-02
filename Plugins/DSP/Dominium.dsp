declare name        "objMatrixDominium"; // modifier le nom de votre greffon
declare version     "1.0";
declare author      "D.Blanchemain";
declare license     "BSD";
declare copyright   "(c)D.Blanchemain 2020";
import("stdfaust.lib");
Matrix(N,M) =_*cdistance:filter:transpose:delay:freeverb<: par(out, M, *(Fader(1,out): si.smoo)) :> par(out, M, _)
with {
tabSpeakerX(0)=-0.500;
tabSpeakerY(0)=0.000;
tabSpeakerZ(0)=1.000;
tabSpeakerD(0)=1.118;
tabSpeakerX(1)=0.500;
tabSpeakerY(1)=0.000;
tabSpeakerZ(1)=1.000;
tabSpeakerD(1)=1.118;
tabSpeakerX(2)=0.000;
tabSpeakerY(2)=0.000;
tabSpeakerZ(2)=1.000;
tabSpeakerD(2)=1.000;
tabSpeakerX(3)=-1.000;
tabSpeakerY(3)=0.000;
tabSpeakerZ(3)=0.500;
tabSpeakerD(3)=1.118;
tabSpeakerX(4)=1.000;
tabSpeakerY(4)=0.000;
tabSpeakerZ(4)=0.500;
tabSpeakerD(4)=1.118;
tabSpeakerX(5)=-1.000;
tabSpeakerY(5)=0.000;
tabSpeakerZ(5)=-0.500;
tabSpeakerD(5)=1.118;
tabSpeakerX(6)=1.000;
tabSpeakerY(6)=0.000;
tabSpeakerZ(6)=-0.500;
tabSpeakerD(6)=1.118;
tabSpeakerX(7)=-1.000;
tabSpeakerY(7)=1.000;
tabSpeakerZ(7)=0.500;
tabSpeakerD(7)=1.500;
tabSpeakerX(8)=-1.000;
tabSpeakerY(8)=-1.000;
tabSpeakerZ(8)=1.000;
tabSpeakerD(8)=1.732;
tabSpeakerX(9)=1.000;
tabSpeakerY(9)=1.000;
tabSpeakerZ(9)=0.500;
tabSpeakerD(9)=1.500;
tabSpeakerX(10)=1.000;
tabSpeakerY(10)=-1.000;
tabSpeakerZ(10)=1.000;
tabSpeakerD(10)=1.732;
tabSpeakerX(11)=-1.000;
tabSpeakerY(11)=1.000;
tabSpeakerZ(11)=-0.500;
tabSpeakerD(11)=1.500;
tabSpeakerX(12)=-1.000;
tabSpeakerY(12)=-1.000;
tabSpeakerZ(12)=-1.000;
tabSpeakerD(12)=1.732;
tabSpeakerX(13)=1.000;
tabSpeakerY(13)=1.000;
tabSpeakerZ(13)=-0.500;
tabSpeakerD(13)=1.500;
tabSpeakerX(14)=1.000;
tabSpeakerY(14)=-1.000;
tabSpeakerZ(14)=-1.000;
tabSpeakerD(14)=1.732;
tabSpeakerX(15)=-0.500;
tabSpeakerY(15)=0.000;
tabSpeakerZ(15)=-1.000;
tabSpeakerD(15)=1.118;
tabSpeakerX(16)=0.500;
tabSpeakerY(16)=0.000;
tabSpeakerZ(16)=-1.000;
tabSpeakerD(16)=1.118;
tabSpeakerX(17)=0.000;
tabSpeakerY(17)=1.000;
tabSpeakerZ(17)=0.000;
tabSpeakerD(17)=1.000;
dtencGen(in, out) = sqrt(pow(tabSpeakerX(out)-x(in),2) + pow(tabSpeakerY(out)-y(in),2) + pow(tabSpeakerZ(out)-z(in),2));
hspot = hslider("Hot Spot",-20,-50,0,1);
dgain(in, out) = ba.db2linear((hspot/tabSpeakerD(out))*dtencGen(in,out));
x(i) = hslider("/X%i",0,-1,1,0.01);
y(i) = hslider("/Y%i",0,-1,1,0.01);
z(i) = hslider("/Z%i",0,-1,1,0.01);
Fader(in,out)= vgroup("[1]Input %2in",dgain(in,out));
cdistance=hslider("dt",1,0,1,0.1);

paramDistance(x)=hgroup("[2]Distance",x);
//-----------------------------------------------------------
//                   LPF 
//-----------------------------------------------------------
//minfreq=paramDistance(vslider("LPF Min",100, 20, 2000, 1));
ampfreq=paramDistance(vslider("LPF Amp",5000, 20, 19980, 1));
rpf=ampfreq:floor;
LPF=fi.lowpass(3,rpf);
fbp = checkbox("[0] Bypass  [tooltip: When this is checked, the filters has no effect]");
filter=paramDistance(vgroup("FILTERS",ba.bypass1(fbp,hgroup("[1]",LPF))));

//-----------------------------------------------------------
//                   Pitchshifting
//-----------------------------------------------------------

pwindow=paramDistance(hslider("window (samples)[style:knob]", 1000, 50, 10000, 1));
pxfade=paramDistance(hslider("xfade (samples)[style:knob]", 10, 1, 10000, 1));
pshift=paramDistance(vslider("shift (semitones) ", 0, -12, +12, 0.1):si.smoo);
pbp = checkbox("[0] Bypass  [tooltip: When this is checked, the filters has no effect]");
transpose=paramDistance(vgroup("Transpose",ba.bypass1(pbp,hgroup("[1]",ef.transpose(pwindow,pxfade,pshift)))));


//-----------------------------------------------------------
//                  Delay
//-----------------------------------------------------------
delay_group(x) = paramDistance(vgroup("[2]DELAY", x));
cbp =delay_group(vgroup("[0]",checkbox("Bypass	[tooltip: When this is checked, Delay has no effect]")));
voice   = delay_group(vgroup("[1]",(+ : de.sdelay(N, interp, dtime)) ~ *(fback)));
N = int(2^19);
interp  = hslider("[2]interpolation[unit:ms][style:knob]",10,1,100,0.1)*ma.SR/1000.0;
fback = hslider("[1]feedback[style:knob]",0,0,100,0.1)/100.0;
dtime = hslider("[0]delay[unit:ms][style:knob]", 0, 0, 1000, 0.01)*ma.SR/1000.0;
delay = ba.bypass1(cbp,voice);
//-----------------------------------------------------------
//                 Freeverb
//-----------------------------------------------------------
scaleroom   = 0.28;
offsetroom  = 0.7;
allpassfeed = 0.5;
scaledamp   = 0.4;
fixedgain   = 0.1;
origSR = ma.SR;
g=parameters(vslider("[1] Wet [tooltip: The amount of reverb applied to the signal
		between 0 and 1 with 1 for the maximum amount of reverb.]", 0.3333, 0.3, 1, 0.025));
freeverbMono=_<: (*(g)*fixedgain :re.mono_freeverb(combfeed, allpassfeed, damping, spatSpread)),*(1-g):> _;
parameters(x) = paramDistance(hgroup("[3]Freeverb",x));
knobGroup(x) = parameters(vgroup("[1]",x));
fvbp = knobGroup(checkbox("[0] Bypass	[tooltip: When this is checked, the freeverb	has no effect]"));
damping = knobGroup(vslider("[1] Damp [style: knob] [tooltip: Somehow control the density of the reverb.]",0.5, 0, 1, 0.025)*scaledamp*origSR/ma.SR);
combfeed = knobGroup(vslider("[2] RoomSize [style: knob] [tooltip: The room size	between 0 and 1 with 1 for the largest room.]", 0.5, 0, 1, 0.025)*scaleroom*origSR/ma.SR + offsetroom);
spatSpread = knobGroup(vslider("[3] Stereo Spread [style: knob] [tooltip: Spatial spread between 0 and 1 with 1 for maximum spread.]",0.5,0,1,0.01)*46*ma.SR/origSR: int);
freeverb = ba.bypass1(fvbp,freeverbMono);
};
process = Matrix(1,18); // le deuxième chiffre permet de définir la dimension de votre espace :9,10, ...

