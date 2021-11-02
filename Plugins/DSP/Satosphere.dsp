declare name        "objMatrixSatosphere"; // modifier le nom de votre greffon
declare version     "1.0";
declare author      "D.Blanchemain";
declare license     "BSD";
declare copyright   "(c)D.Blanchemain 2020";
import("stdfaust.lib");
Matrix(N,M) =_*cdistance:filter:transpose:delay:freeverb<: par(out, M, *(Fader(1,out): si.smoo)) :> par(out, M, _)
with {
tabSpeakerX(0)=-0.062;
tabSpeakerY(0)=1.000;
tabSpeakerZ(0)=-0.061;
tabSpeakerD(0)=1.004;
tabSpeakerX(1)=-0.412;
tabSpeakerY(1)=0.779;
tabSpeakerZ(1)=0.081;
tabSpeakerD(1)=0.885;
tabSpeakerX(2)=-0.328;
tabSpeakerY(2)=0.779;
tabSpeakerZ(2)=-0.323;
tabSpeakerD(2)=0.905;
tabSpeakerX(3)=0.002;
tabSpeakerY(3)=0.779;
tabSpeakerZ(3)=-0.449;
tabSpeakerD(3)=0.899;
tabSpeakerX(4)=0.299;
tabSpeakerY(4)=0.779;
tabSpeakerZ(4)=-0.182;
tabSpeakerD(4)=0.854;
tabSpeakerX(5)=0.225;
tabSpeakerY(5)=0.779;
tabSpeakerZ(5)=0.242;
tabSpeakerD(5)=0.846;
tabSpeakerX(6)=-0.131;
tabSpeakerY(6)=0.779;
tabSpeakerZ(6)=0.384;
tabSpeakerD(6)=0.878;
tabSpeakerX(7)=-0.052;
tabSpeakerY(7)=0.214;
tabSpeakerZ(7)=0.672;
tabSpeakerD(7)=0.707;
tabSpeakerX(8)=-0.407;
tabSpeakerY(8)=0.214;
tabSpeakerZ(8)=0.561;
tabSpeakerD(8)=0.725;
tabSpeakerX(9)=-0.689;
tabSpeakerY(9)=0.214;
tabSpeakerZ(9)=0.359;
tabSpeakerD(9)=0.806;
tabSpeakerX(10)=-0.847;
tabSpeakerY(10)=0.214;
tabSpeakerZ(10)=0.000;
tabSpeakerD(10)=0.874;
tabSpeakerX(11)=-0.699;
tabSpeakerY(11)=0.214;
tabSpeakerZ(11)=-0.348;
tabSpeakerD(11)=0.810;
tabSpeakerX(12)=-0.422;
tabSpeakerY(12)=0.214;
tabSpeakerZ(12)=-0.581;
tabSpeakerD(12)=0.749;
tabSpeakerX(13)=-0.062;
tabSpeakerY(13)=0.214;
tabSpeakerZ(13)=-0.667;
tabSpeakerD(13)=0.703;
tabSpeakerX(14)=0.348;
tabSpeakerY(14)=0.214;
tabSpeakerZ(14)=-0.581;
tabSpeakerD(14)=0.710;
tabSpeakerX(15)=0.635;
tabSpeakerY(15)=0.214;
tabSpeakerZ(15)=-0.333;
tabSpeakerD(15)=0.748;
tabSpeakerX(16)=0.798;
tabSpeakerY(16)=0.214;
tabSpeakerZ(16)=0.010;
tabSpeakerD(16)=0.826;
tabSpeakerX(17)=0.644;
tabSpeakerY(17)=0.214;
tabSpeakerZ(17)=0.369;
tabSpeakerD(17)=0.773;
tabSpeakerX(18)=0.358;
tabSpeakerY(18)=0.214;
tabSpeakerZ(18)=0.596;
tabSpeakerD(18)=0.727;
tabSpeakerX(19)=0.007;
tabSpeakerY(19)=-0.181;
tabSpeakerZ(19)=1.000;
tabSpeakerD(19)=1.016;
tabSpeakerX(20)=-0.501;
tabSpeakerY(20)=-0.181;
tabSpeakerZ(20)=0.798;
tabSpeakerD(20)=0.960;
tabSpeakerX(21)=-0.872;
tabSpeakerY(21)=-0.181;
tabSpeakerZ(21)=0.414;
tabSpeakerD(21)=0.982;
tabSpeakerX(22)=-1.000;
tabSpeakerY(22)=-0.181;
tabSpeakerZ(22)=-0.051;
tabSpeakerD(22)=1.018;
tabSpeakerX(23)=-0.872;
tabSpeakerY(23)=-0.181;
tabSpeakerZ(23)=-0.495;
tabSpeakerD(23)=1.019;
tabSpeakerX(24)=-0.506;
tabSpeakerY(24)=-0.181;
tabSpeakerZ(24)=-0.793;
tabSpeakerD(24)=0.958;
tabSpeakerX(25)=-0.002;
tabSpeakerY(25)=-0.181;
tabSpeakerZ(25)=-1.000;
tabSpeakerD(25)=1.016;
tabSpeakerX(26)=0.501;
tabSpeakerY(26)=-0.181;
tabSpeakerZ(26)=-0.823;
tabSpeakerD(26)=0.981;
tabSpeakerX(27)=0.872;
tabSpeakerY(27)=-0.181;
tabSpeakerZ(27)=-0.460;
tabSpeakerD(27)=1.002;
tabSpeakerX(28)=1.000;
tabSpeakerY(28)=-0.181;
tabSpeakerZ(28)=-0.005;
tabSpeakerD(28)=1.016;
tabSpeakerX(29)=0.847;
tabSpeakerY(29)=-0.181;
tabSpeakerZ(29)=0.480;
tabSpeakerD(29)=0.990;
tabSpeakerX(30)=0.511;
tabSpeakerY(30)=-0.181;
tabSpeakerZ(30)=0.904;
tabSpeakerD(30)=1.054;
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

pwindow=paramDistance(hslider("window (samples)", 1000, 50, 10000, 1));
pxfade=paramDistance(hslider("xfade (samples)", 10, 1, 10000, 1));
pshift=paramDistance(hslider("shift (semitones) ", 0, -12, +12, 0.1));
pbp = checkbox("[0] Bypass  [tooltip: When this is checked, the filters has no effect]");
transpose=paramDistance(vgroup("Transpose",ba.bypass1(pbp,hgroup("[1]",ef.transpose(pwindow,pxfade,pshift)))));


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
process = Matrix(1,31); // le deuxième chiffre permet de définir la dimension de votre espace :9,10, ...

