declare name        "objMatrixRfStudio"; // modifier le nom de votre greffon
declare version     "1.0";
declare author      "D.Blanchemain";
declare license     "BSD";
declare copyright   "(c)D.Blanchemain 2020";
import("stdfaust.lib");
Matrix(N,M) =_*cdistance:filter:transpose:delay:freeverb<: par(out, M, *(Fader(1,out): si.smoo)) :> par(out, M, _)
with {
tabSpeakerX(0)=-0.585;
tabSpeakerY(0)=-0.374;
tabSpeakerZ(0)=1.000;
tabSpeakerD(0)=1.218;
tabSpeakerX(1)=-0.190;
tabSpeakerY(1)=-0.374;
tabSpeakerZ(1)=1.000;
tabSpeakerD(1)=1.084;
tabSpeakerX(2)=0.205;
tabSpeakerY(2)=-0.374;
tabSpeakerZ(2)=1.000;
tabSpeakerD(2)=1.087;
tabSpeakerX(3)=0.605;
tabSpeakerY(3)=-0.374;
tabSpeakerZ(3)=1.000;
tabSpeakerD(3)=1.227;
tabSpeakerX(4)=1.000;
tabSpeakerY(4)=-0.374;
tabSpeakerZ(4)=-0.591;
tabSpeakerD(4)=1.220;
tabSpeakerX(5)=1.000;
tabSpeakerY(5)=-0.374;
tabSpeakerZ(5)=-0.197;
tabSpeakerD(5)=1.086;
tabSpeakerX(6)=1.000;
tabSpeakerY(6)=-0.374;
tabSpeakerZ(6)=0.197;
tabSpeakerD(6)=1.086;
tabSpeakerX(7)=1.000;
tabSpeakerY(7)=-0.374;
tabSpeakerZ(7)=0.601;
tabSpeakerD(7)=1.225;
tabSpeakerX(8)=0.610;
tabSpeakerY(8)=-0.374;
tabSpeakerZ(8)=-1.000;
tabSpeakerD(8)=1.230;
tabSpeakerX(9)=0.210;
tabSpeakerY(9)=-0.374;
tabSpeakerZ(9)=-1.000;
tabSpeakerD(9)=1.088;
tabSpeakerX(10)=-0.195;
tabSpeakerY(10)=-0.374;
tabSpeakerZ(10)=-1.000;
tabSpeakerD(10)=1.085;
tabSpeakerX(11)=-0.590;
tabSpeakerY(11)=-0.374;
tabSpeakerZ(11)=-1.000;
tabSpeakerD(11)=1.220;
tabSpeakerX(12)=-1.000;
tabSpeakerY(12)=-0.374;
tabSpeakerZ(12)=-0.591;
tabSpeakerD(12)=1.220;
tabSpeakerX(13)=-1.000;
tabSpeakerY(13)=-0.374;
tabSpeakerZ(13)=-0.197;
tabSpeakerD(13)=1.086;
tabSpeakerX(14)=-1.000;
tabSpeakerY(14)=-0.374;
tabSpeakerZ(14)=0.207;
tabSpeakerD(14)=1.088;
tabSpeakerX(15)=-1.000;
tabSpeakerY(15)=-0.374;
tabSpeakerZ(15)=0.601;
tabSpeakerD(15)=1.225;
tabSpeakerX(16)=-0.333;
tabSpeakerY(16)=0.219;
tabSpeakerZ(16)=1.000;
tabSpeakerD(16)=1.077;
tabSpeakerX(17)=0.343;
tabSpeakerY(17)=0.219;
tabSpeakerZ(17)=1.000;
tabSpeakerD(17)=1.080;
tabSpeakerX(18)=1.000;
tabSpeakerY(18)=0.219;
tabSpeakerZ(18)=-0.394;
tabSpeakerD(18)=1.097;
tabSpeakerX(19)=1.000;
tabSpeakerY(19)=0.219;
tabSpeakerZ(19)=0.404;
tabSpeakerD(19)=1.101;
tabSpeakerX(20)=0.338;
tabSpeakerY(20)=0.219;
tabSpeakerZ(20)=-1.000;
tabSpeakerD(20)=1.078;
tabSpeakerX(21)=-0.323;
tabSpeakerY(21)=0.219;
tabSpeakerZ(21)=-1.000;
tabSpeakerD(21)=1.074;
tabSpeakerX(22)=-1.000;
tabSpeakerY(22)=0.219;
tabSpeakerZ(22)=-0.399;
tabSpeakerD(22)=1.099;
tabSpeakerX(23)=-1.000;
tabSpeakerY(23)=0.219;
tabSpeakerZ(23)=0.409;
tabSpeakerD(23)=1.102;
tabSpeakerX(24)=-0.402;
tabSpeakerY(24)=0.807;
tabSpeakerZ(24)=-0.056;
tabSpeakerD(24)=0.904;
tabSpeakerX(25)=0.407;
tabSpeakerY(25)=0.807;
tabSpeakerZ(25)=-0.061;
tabSpeakerD(25)=0.906;
tabSpeakerX(26)=0.007;
tabSpeakerY(26)=0.807;
tabSpeakerZ(26)=0.283;
tabSpeakerD(26)=0.855;
tabSpeakerX(27)=0.002;
tabSpeakerY(27)=0.807;
tabSpeakerZ(27)=-0.404;
tabSpeakerD(27)=0.902;
tabSpeakerX(28)=-0.062;
tabSpeakerY(28)=1.000;
tabSpeakerZ(28)=-0.056;
tabSpeakerD(28)=1.003;
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
process = Matrix(1,29); // le deuxième chiffre permet de définir la dimension de votre espace :9,10, ...

