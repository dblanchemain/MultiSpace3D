declare name        "objMatrixIrcam.dsp"; // modifier le nom de votre greffon
declare version     "1.0";
declare author      "D.Blanchemain";
declare license     "BSD";
declare copyright   "(c)D.Blanchemain 2020";
import("stdfaust.lib");
Matrix(N,M) =_*cdistance:filter:transpose:delay:freeverb<: par(out, M, *(Fader(1,out): si.smoo)) :> par(out, M, _)
with {
tabSpeakerX(0)=0.002;
tabSpeakerY(0)=-0.581;
tabSpeakerZ(0)=0.899;
tabSpeakerD(0)=1.070;
tabSpeakerX(1)=0.778;
tabSpeakerY(1)=-0.581;
tabSpeakerZ(1)=0.606;
tabSpeakerD(1)=1.144;
tabSpeakerX(2)=1.000;
tabSpeakerY(2)=-0.581;
tabSpeakerZ(2)=0.000;
tabSpeakerD(2)=1.157;
tabSpeakerX(3)=0.773;
tabSpeakerY(3)=-0.581;
tabSpeakerZ(3)=-0.601;
tabSpeakerD(3)=1.138;
tabSpeakerX(4)=0.254;
tabSpeakerY(4)=-0.581;
tabSpeakerZ(4)=-1.000;
tabSpeakerD(4)=1.184;
tabSpeakerX(5)=-0.274;
tabSpeakerY(5)=-0.581;
tabSpeakerZ(5)=-1.000;
tabSpeakerD(5)=1.189;
tabSpeakerX(6)=-0.719;
tabSpeakerY(6)=-0.581;
tabSpeakerZ(6)=-0.591;
tabSpeakerD(6)=1.097;
tabSpeakerX(7)=-1.000;
tabSpeakerY(7)=-0.581;
tabSpeakerZ(7)=-0.010;
tabSpeakerD(7)=1.157;
tabSpeakerX(8)=-0.714;
tabSpeakerY(8)=-0.581;
tabSpeakerZ(8)=0.601;
tabSpeakerD(8)=1.099;
tabSpeakerX(9)=0.220;
tabSpeakerY(9)=-0.181;
tabSpeakerZ(9)=0.606;
tabSpeakerD(9)=0.670;
tabSpeakerX(10)=0.664;
tabSpeakerY(10)=-0.181;
tabSpeakerZ(10)=0.162;
tabSpeakerD(10)=0.707;
tabSpeakerX(11)=0.669;
tabSpeakerY(11)=-0.181;
tabSpeakerZ(11)=-0.273;
tabSpeakerD(11)=0.745;
tabSpeakerX(12)=0.353;
tabSpeakerY(12)=-0.181;
tabSpeakerZ(12)=-0.717;
tabSpeakerD(12)=0.820;
tabSpeakerX(13)=-0.042;
tabSpeakerY(13)=-0.181;
tabSpeakerZ(13)=-0.808;
tabSpeakerD(13)=0.829;
tabSpeakerX(14)=-0.506;
tabSpeakerY(14)=-0.181;
tabSpeakerZ(14)=-0.697;
tabSpeakerD(14)=0.880;
tabSpeakerX(15)=-0.743;
tabSpeakerY(15)=-0.181;
tabSpeakerZ(15)=-0.288;
tabSpeakerD(15)=0.817;
tabSpeakerX(16)=-0.743;
tabSpeakerY(16)=-0.181;
tabSpeakerZ(16)=0.152;
tabSpeakerD(16)=0.780;
tabSpeakerX(17)=-0.398;
tabSpeakerY(17)=-0.181;
tabSpeakerZ(17)=0.586;
tabSpeakerD(17)=0.731;
tabSpeakerX(18)=-0.106;
tabSpeakerY(18)=0.525;
tabSpeakerZ(18)=0.348;
tabSpeakerD(18)=0.639;
tabSpeakerX(19)=0.343;
tabSpeakerY(19)=0.525;
tabSpeakerZ(19)=0.086;
tabSpeakerD(19)=0.633;
tabSpeakerX(20)=0.235;
tabSpeakerY(20)=0.525;
tabSpeakerZ(20)=-0.429;
tabSpeakerD(20)=0.718;
tabSpeakerX(21)=-0.215;
tabSpeakerY(21)=0.525;
tabSpeakerZ(21)=-0.545;
tabSpeakerD(21)=0.787;
tabSpeakerX(22)=-0.521;
tabSpeakerY(22)=0.525;
tabSpeakerZ(22)=-0.076;
tabSpeakerD(22)=0.744;
tabSpeakerX(23)=0.007;
tabSpeakerY(23)=1.000;
tabSpeakerZ(23)=-0.005;
tabSpeakerD(23)=1.000;
dtencGen(in, out) = sqrt(pow(tabSpeakerX(out)-x(in),2) + pow(tabSpeakerY(out)-y(in),2) + pow(tabSpeakerZ(out)-z(in),2));
process = Matrix(1,24); // le deuxième chiffre permet de définir la dimension de votre espace :9,10, ...
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
process = Matrix(1,24);
