declare name        "objMatrixAuro13"; // modifier le nom de votre greffon
declare version     "1.0";
declare author      "D.Blanchemain";
declare license     "BSD";
declare copyright   "(c)D.Blanchemain 2020";
import("stdfaust.lib");
Matrix(N,M) =_:filters(1):delay:freeverb(1)<: par(out, M, *(Fader(1,out): si.smoo)) :> par(out, M, _)
with {
tabSpeakerX(0)=-1.000;
tabSpeakerY(0)=-0.181;
tabSpeakerZ(0)=1.000;
tabSpeakerD(0)=1.426;
tabSpeakerX(1)=1.000;
tabSpeakerY(1)=-0.181;
tabSpeakerZ(1)=1.000;
tabSpeakerD(1)=1.426;
tabSpeakerX(2)=-0.002;
tabSpeakerY(2)=-0.181;
tabSpeakerZ(2)=1.000;
tabSpeakerD(2)=1.016;
tabSpeakerX(3)=-1.000;
tabSpeakerY(3)=-0.181;
tabSpeakerZ(3)=-0.500;
tabSpeakerD(3)=1.133;
tabSpeakerX(4)=1.000;
tabSpeakerY(4)=-0.181;
tabSpeakerZ(4)=-0.500;
tabSpeakerD(4)=1.133;
tabSpeakerX(5)=-1.000;
tabSpeakerY(5)=-0.181;
tabSpeakerZ(5)=0.500;
tabSpeakerD(5)=1.133;
tabSpeakerX(6)=1.000;
tabSpeakerY(6)=-0.181;
tabSpeakerZ(6)=0.500;
tabSpeakerD(6)=1.133;
tabSpeakerX(7)=-1.000;
tabSpeakerY(7)=0.812;
tabSpeakerZ(7)=1.000;
tabSpeakerD(7)=1.631;
tabSpeakerX(8)=1.000;
tabSpeakerY(8)=0.812;
tabSpeakerZ(8)=1.000;
tabSpeakerD(8)=1.631;
tabSpeakerX(9)=-1.000;
tabSpeakerY(9)=0.812;
tabSpeakerZ(9)=-1.000;
tabSpeakerD(9)=1.631;
tabSpeakerX(10)=1.000;
tabSpeakerY(10)=0.812;
tabSpeakerZ(10)=-1.000;
tabSpeakerD(10)=1.631;
tabSpeakerX(11)=0.002;
tabSpeakerY(11)=0.812;
tabSpeakerZ(11)=1.000;
tabSpeakerD(11)=1.288;
tabSpeakerX(12)=0.007;
tabSpeakerY(12)=1.000;
tabSpeakerZ(12)=0.000;
tabSpeakerD(12)=1.000;
dtencGen(in, out) = sqrt(pow(tabSpeakerX(out)-x(in),2) + pow(tabSpeakerY(out)+y(in),2) + pow(tabSpeakerZ(out)-z(in),2));
dgain(in, out) = ba.db2linear((-50/tabSpeakerD(out))*dtencGen(in,out));
x(i) = hslider("/X%i",0,-1,1,0.01);
y(i) = hslider("/Y%i",0,-1,1,0.01);
z(i) = hslider("/Z%i",0,-1,1,0.01);
Fader(in,out)= vgroup("[1]Input %2in",dgain(in,out));
cdistance(in)=sqrt(pow(0-x(in),2) + pow(0+y(in),2) + pow(0-z(in),2));
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
process = Matrix(1,13); // le deuxième chiffre permet de définir la dimension de votre espace :9,10, ...

