declare name        "objMatrixZKM23.dsp"; // modifier le nom de votre greffon
declare version     "1.0";
declare author      "D.Blanchemain";
declare license     "BSD";
declare copyright   "(c)D.Blanchemain 2020";
import("stdfaust.lib");
Matrix(N,M) =_*cdistance:filter:transpose:delay:freeverb<: par(out, M, *(Fader(1,out): si.smoo)) :> par(out, M, _)
with {
tabSpeakerX(0)=-0.007;
tabSpeakerY(0)=-0.374;
tabSpeakerZ(0)=1.000;
tabSpeakerD(0)=1.068;
tabSpeakerX(1)=0.600;
tabSpeakerY(1)=-0.374;
tabSpeakerZ(1)=0.808;
tabSpeakerD(1)=1.074;
tabSpeakerX(2)=1.000;
tabSpeakerY(2)=-0.374;
tabSpeakerZ(2)=0.283;
tabSpeakerD(2)=1.104;
tabSpeakerX(3)=1.000;
tabSpeakerY(3)=-0.374;
tabSpeakerZ(3)=-0.318;
tabSpeakerD(3)=1.114;
tabSpeakerX(4)=0.615;
tabSpeakerY(4)=-0.374;
tabSpeakerZ(4)=-0.798;
tabSpeakerD(4)=1.075;
tabSpeakerX(5)=0.007;
tabSpeakerY(5)=-0.374;
tabSpeakerZ(5)=-1.000;
tabSpeakerD(5)=1.068;
tabSpeakerX(6)=-0.600;
tabSpeakerY(6)=-0.374;
tabSpeakerZ(6)=-0.793;
tabSpeakerD(6)=1.062;
tabSpeakerX(7)=-1.000;
tabSpeakerY(7)=-0.374;
tabSpeakerZ(7)=-0.303;
tabSpeakerD(7)=1.110;
tabSpeakerX(8)=-1.000;
tabSpeakerY(8)=-0.374;
tabSpeakerZ(8)=0.283;
tabSpeakerD(8)=1.104;
tabSpeakerX(9)=-0.585;
tabSpeakerY(9)=-0.374;
tabSpeakerZ(9)=0.808;
tabSpeakerD(9)=1.066;
tabSpeakerX(10)=0.294;
tabSpeakerY(10)=0.219;
tabSpeakerZ(10)=0.803;
tabSpeakerD(10)=0.883;
tabSpeakerX(11)=0.807;
tabSpeakerY(11)=0.219;
tabSpeakerZ(11)=0.283;
tabSpeakerD(11)=0.883;
tabSpeakerX(12)=0.807;
tabSpeakerY(12)=0.219;
tabSpeakerZ(12)=-0.394;
tabSpeakerD(12)=0.925;
tabSpeakerX(13)=0.279;
tabSpeakerY(13)=0.219;
tabSpeakerZ(13)=-0.803;
tabSpeakerD(13)=0.878;
tabSpeakerX(14)=-0.304;
tabSpeakerY(14)=0.219;
tabSpeakerZ(14)=-0.798;
tabSpeakerD(14)=0.881;
tabSpeakerX(15)=-0.793;
tabSpeakerY(15)=0.219;
tabSpeakerZ(15)=-0.394;
tabSpeakerD(15)=0.912;
tabSpeakerX(16)=-0.802;
tabSpeakerY(16)=0.219;
tabSpeakerZ(16)=0.278;
tabSpeakerD(16)=0.877;
tabSpeakerX(17)=-0.319;
tabSpeakerY(17)=0.219;
tabSpeakerZ(17)=0.808;
tabSpeakerD(17)=0.896;
tabSpeakerX(18)=-0.057;
tabSpeakerY(18)=0.807;
tabSpeakerZ(18)=0.207;
tabSpeakerD(18)=0.835;
tabSpeakerX(19)=-0.314;
tabSpeakerY(19)=0.807;
tabSpeakerZ(19)=-0.061;
tabSpeakerD(19)=0.868;
tabSpeakerX(20)=-0.052;
tabSpeakerY(20)=0.807;
tabSpeakerZ(20)=-0.354;
tabSpeakerD(20)=0.883;
tabSpeakerX(21)=0.225;
tabSpeakerY(21)=0.807;
tabSpeakerZ(21)=-0.076;
tabSpeakerD(21)=0.841;
tabSpeakerX(22)=-0.067;
tabSpeakerY(22)=1.000;
tabSpeakerZ(22)=-0.056;
tabSpeakerD(22)=1.004;
dtencGen(in, out) = sqrt(pow(tabSpeakerX(out)-x(in),2) + pow(tabSpeakerY(out)-y(in),2) + pow(tabSpeakerZ(out)-z(in),2));
process = Matrix(1,23); // le deuxième chiffre permet de définir la dimension de votre espace :9,10, ...
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
ampfreq=vslider("LPF Amp[unit:Hz]",5000, 20, 19980, 1);
rpf=ampfreq:floor;
LPF=fi.lowpass(3,rpf);
fbp = checkbox("[0] Bypass  [tooltip: When this is checked, the filters has no effect]");
filter=paramDistance(vgroup("FILTERS",ba.bypass1(fbp,hgroup("[1]",LPF))));
//-----------------------------------------------------------
//                   Pitchshifting
//-----------------------------------------------------------
paramPitch(x)=vgroup("[2]Param",x);pwindow=paramPitch(vslider("window (samples)[style:knob]", 1000, 50, 10000, 1));
pxfade=paramPitch(vslider("xfade (samples)[style:knob]", 10, 1, 10000, 1));
pshift=vslider("shift (semitones) ", 0, -12, +12, 0.1):si.smoo;
pbp = checkbox("[0] Bypass  [tooltip: When this is checked, the filters has no effect]");
transpose=paramDistance(vgroup("TRANSPOSE",ba.bypass1(pbp,hgroup("[1]",ef.transpose(pwindow,pxfade,pshift)))));
//-----------------------------------------------------------
//                  Delay
//-----------------------------------------------------------
delay_group(x) = paramDistance(vgroup("[2]DELAY", x));
cbp =delay_group(vgroup("[0]",checkbox("Bypass	[tooltip: When this is checked, Delay has no effect]")));
voice   = delay_group(vgroup("[1]",(+ : de.sdelay(N, interp, dtime)) ~ *(fback)));
N = int(2^19);
interp  = hslider("interpolation[unit:ms][style:knob]",10,1,100,0.1)*ma.SR/1000.0;
fback = hslider("feedback[style:knob]",0,0,100,0.1)/100.0;
dtime = hslider("delay[unit:ms][style:knob]", 0, 0, 1000, 0.01)*ma.SR/1000.0;
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
g=parameters(vslider("[1] Wet [tooltip: The amount of reverb applied to the signal between 0 and 1 with 1 for the maximum amount of reverb.]", 0.3333, 0.3, 1, 0.025));
freeverbMono=_<: (*(g)*fixedgain :re.mono_freeverb(combfeed, allpassfeed, damping, spatSpread)),*(1-g):> _;
parameters(x) = paramDistance(hgroup("[3]Freeverb",x));
knobGroup(x) = parameters(vgroup("[1]",x));
fvbp = knobGroup(checkbox("[0] Bypass	[tooltip: When this is checked, the freeverb	has no effect]"));
damping = knobGroup(vslider("[1] Damp [style: knob] [tooltip: Somehow control the density of the reverb.]",0.5, 0, 1, 0.025)*scaledamp*origSR/ma.SR);
combfeed = knobGroup(vslider("[2] RoomSize [style: knob] [tooltip: The room size	between 0 and 1 with 1 for the largest room.]", 0.5, 0, 1, 0.025)*scaleroom*origSR/ma.SR + offsetroom);
spatSpread = knobGroup(vslider("[3] Stereo Spread [style: knob] [tooltip: Spatial spread between 0 and 1 with 1 for maximum spread.]",0.5,0,1,0.01)*46*ma.SR/origSR: int);
freeverb = ba.bypass1(fvbp,freeverbMono);
};
process = Matrix(1,23);
