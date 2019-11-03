/*
  stygmorgan - a ryhthm station software

  stygmorgan.C  -  Init functions.
  Copyright (C) 2006 Josep Andreu (Holborn)
  Author: Josep Andreu

  This program is free software; you can redistribute it and/or modify
  it under the terms of version 2 of the GNU General Public License
  as published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License (version 2) for more details.

  You should have received a copy of the GNU General Public License
(version2)
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA

*/


#include <Fl/Fl_Preferences.H>
#include <X11/xpm.h>
#include "stygmorgan.h"


int
Pexitprogram,programa,espera,pera,chsel,x,y,sponmix,wabout,exitwithhelp,jack,alsa;
Pixmap p,mask;
XWMHints *hints;
int nojack;
song S[129];
songcon SongF;


RMGMO::RMGMO ()
{
  
  //inicio de variables
  jack=1;
  usesysex=0;
  pbStart=0;
  pbAutoF=0;
  ulase=0;
  wmore=0;
  tapaga=0;
  osemi=0;
  semi=0;
  memset(cocas ,0 ,sizeof cocas);
  memset(lastvelo,0,sizeof lastvelo);
  genmidi=0;
  ajusta=1;
  wpreferences=0;
  wabout=0;
  wsequencer=0;
  weventeditor=0;
  wmixereditor=0;
  wpatterneditor=0;
  wstyleeditor=0;
  CNPattern=0;
  CNStyle=0;
  imenu=1;
  MTempo=0;
  finito=0;
  mirado=0;
  cc1=0;
  posanti=0;
  anti=0;
  sponmix=0;
  vnegra=0;
  anegra=0;
  scompas=0;
  cas=1;
  CambiaTempo=0;
  splay=0;
  ventana=0;
  Respect=0;
  BankLSBLS=0;
  BankTruco=0;
  IsCoIn=0;
  IsCoOut=0;
  Cyoin=0;
  Cyoout=0;
  Pyoin=0;
  Pyoout=0;
  Ccin=0;
  Ccout=0;
  Pcout=0;
  Pcin=0;
  CambiaMidi=0;
  Sonido=1;
  Estilo=1;
  ponstart=0;
  syncstart=0;
  bcancel=0;
  vuelve=0;
  split=60;
  SStipo=0;
  KeybVol=100;
  AccVol=100;
  pera=0;
  EventoCambia=0;
  chsel=0;
  rela=1.0;
  lppq=1;
  ponvum=0;
  vum=0;
  cambioc=0;
  sel=0;
  sema=0;
  cc=0;
  sic=0;
  nic=0;
  ultimalanegra=0;
  ultimalacas=0;
  AFill=0;
  vcompas=0;
  rema= 0;
  endi = 0;
  hay = 0;
  espera=0;
  tiene=0;
  siguiente=1;
  nb=1;
  isnewr=0;
  isnew=0;
  isnews=0;
  numstyles=0;
  bplay=0;
  tick=0;
  bpm=120;
  fundi = 0;
  mt=1;
  Variacion=1; 
  ctipo=0;
  nStyle.ppq=96;
  nStyle.nominador=4;
  nStyle.Pattern[1].bars=1;
  longic=96*4;
  longi=96*4;
  ev_count=0;
  rtplay=0;
  Pendientes=0;
  PendientesEE=0;
  adatasize=0;
  usejacktransport=0;
  nunegra=1;
  ultrack=0;
  ulcontrol=0;
   
memset(EG, 0, sizeof EG);
memset(PEG,0, sizeof PEG);
memset(&nStyle, 0, sizeof nStyle);
memset(CCn, 0, sizeof CCn);
memset(CStyle,0, sizeof CStyle);
memset(PO, 0, sizeof PO);
memset(POEE, 0, sizeof POEE); 
memset(adata,0,sizeof adata);
memset(Midi_event,0,sizeof Midi_event);




//Inicio Mixer



for (int i=0; i<16; i++)

      {
        CM[i].OnOff     =   1;
        CM[i].solo      =   0;
        CM[i].more      =   0;
        CM[i].pan       =  64;
        CM[i].reverb    =   0;
        CM[i].vol       = 100;
        CM[i].chorus    =   0;
        CM[i].program   =   0;
        CM[i].bLSB      =   0;
        CM[i].bMSB      =   0;
        CM[i].ch        =   i;
        CM[i].octave    =   0;
        CM[i].transpose =   0;
      }

        CM[9].bLSB = 1; CM[9].bMSB =1;





strcpy(CCn[0].Nom,"BANK");
strcpy(CCn[1].Nom,"MODWHEEL");
strcpy(CCn[2].Nom,"BREATH");
strcpy(CCn[4].Nom,"FOOT");
strcpy(CCn[5].Nom,"PORTAMENTO_TIME");
strcpy(CCn[6].Nom,"DATA_ENTRY");
strcpy(CCn[7].Nom,"MAIN_VOLUME");
strcpy(CCn[8].Nom,"BALANCE");
strcpy(CCn[10].Nom,"PAN");
strcpy(CCn[11].Nom,"EXPRESSION");
strcpy(CCn[12].Nom,"EFFECT1");
strcpy(CCn[13].Nom,"EFFECT2");
strcpy(CCn[16].Nom,"GENERAL_PURPOSE1");
strcpy(CCn[17].Nom,"GENERAL_PURPOSE2");
strcpy(CCn[18].Nom,"GENERAL_PURPOSE3");
strcpy(CCn[19].Nom,"GENERAL_PURPOSE4");
strcpy(CCn[32].Nom,"BANK");
strcpy(CCn[33].Nom,"MODWHEEL");
strcpy(CCn[34].Nom,"BREATH");
strcpy(CCn[35].Nom,"FOOT");
strcpy(CCn[37].Nom,"PORTAMENTO_TIME");
strcpy(CCn[38].Nom,"DATA_ENTRY");
strcpy(CCn[39].Nom,"MAIN_VOLUME");
strcpy(CCn[40].Nom,"BALANCE");
strcpy(CCn[42].Nom,"PAN");
strcpy(CCn[43].Nom,"EXPRESSION");
strcpy(CCn[44].Nom,"EFFECT1");
strcpy(CCn[45].Nom,"EFFECT2");
strcpy(CCn[48].Nom,"GENERAL_PURPOSE1");
strcpy(CCn[49].Nom,"GENERAL_PURPOSE2");
strcpy(CCn[50].Nom,"GENERAL_PURPOSE3");
strcpy(CCn[51].Nom,"GENERAL_PURPOSE4");
strcpy(CCn[64].Nom,"SUSTAIN");
strcpy(CCn[65].Nom,"PORTAMENTO");
strcpy(CCn[66].Nom,"SOSTENUTO");
strcpy(CCn[67].Nom,"SOFT_PEDAL");
strcpy(CCn[68].Nom,"LEGATO_FOOTSWITCH");
strcpy(CCn[69].Nom,"HOLD2");
strcpy(CCn[70].Nom,"SC1_SOUND_VARIATION");
strcpy(CCn[71].Nom,"SC2_TIMBRE");
strcpy(CCn[72].Nom,"SC3_RELEASE_TIME");
strcpy(CCn[73].Nom,"SC4_ATTACK_TIME");
strcpy(CCn[74].Nom,"SC5_BRIGHTNESS");
strcpy(CCn[75].Nom,"SC6");
strcpy(CCn[76].Nom,"SC7");
strcpy(CCn[77].Nom,"SC8");
strcpy(CCn[79].Nom,"SC9");
strcpy(CCn[79].Nom,"SC10");
strcpy(CCn[80].Nom,"GENERAL_PURPOSE5");
strcpy(CCn[81].Nom,"GENERAL_PURPOSE6");
strcpy(CCn[82].Nom,"GENERAL_PURPOSE7");
strcpy(CCn[83].Nom,"GENERAL_PURPOSE8");
strcpy(CCn[84].Nom,"PORTAMENTO_CONTROL");
strcpy(CCn[91].Nom,"REVERB_DEPTH");
strcpy(CCn[92].Nom,"TREMOLO_DEPTH");
strcpy(CCn[93].Nom,"CHORUS_DEPTH");
strcpy(CCn[94].Nom,"DETUNE_DEPTH");
strcpy(CCn[95].Nom,"PHASER_DEPTH");
strcpy(CCn[96].Nom,"DATA_INCREMENT");
strcpy(CCn[97].Nom,"DATA_DECREMENT");
strcpy(CCn[98].Nom,"NONREG_PARM_NUM_LSB");
strcpy(CCn[99].Nom,"NONREG_PARM_NUM_MSB");
strcpy(CCn[100].Nom,"REGIST_PARM_NUM_LSB");
strcpy(CCn[101].Nom,"REGIST_PARM_NUM_MSB");
strcpy(CCn[120].Nom,"ALL_SOUNDS_OFF");
strcpy(CCn[121].Nom,"RESET_CONTROLLERS");
strcpy(CCn[122].Nom,"LOCAL_CONTROL_SWITCH");
strcpy(CCn[123].Nom,"ALL_NOTES_OFF");
strcpy(CCn[124].Nom,"OMNI_OFF");
strcpy(CCn[125].Nom,"OMNI_ON");
strcpy(CCn[126].Nom,"MONO1");
strcpy(CCn[127].Nom,"MONO2");


{
static const char *stnom[] = {"8 Beat","16 Beat","Jazz","Swing","Salsa","Disco-Dance","March-Polka","Reggae","Country",
"World","Ballad","Waltz","Rock","Blues","Shuffle","Brasilian","Funk","Other"};
for (int i=0; i<=17; i++) strcpy(CStyle[i].Nom, stnom[i]);
}



{
static const char *stnom[] = {"Drums","Bass","Acc 1","Acc 2","Acc 3","Acc 4","Acc 5","Left 1","Left 2","Right 1","Right 2","Right 3"};
for (int i=0; i<=11; i++) strcpy(UTNames[i].Nom,stnom[i]);
}

{
static const char *stnom[] = {"Volume","Chorus","Reverb","Pan"};
for (int i=0; i<=3; i++) strcpy(UCNames[i].Nom,stnom[i]);
}

bzero(Ch ,sizeof(Ch));


Ch[0][2]=2;   Ch[6][2]=1;   Ch[12][2]=1;   Ch[18][2]=2;   Ch[24][2]=2;     Ch[31][7]=1;
Ch[0][4]=1;   Ch[6][4]=1;   Ch[12][3]=1;   Ch[18][3]=1;   Ch[24][4]=1;
Ch[0][7]=1;   Ch[6][7]=1;   Ch[12][5]=2;   Ch[18][5]=2;   Ch[24][7]=1;
Ch[0][9]=2;   Ch[6][9]=1;   Ch[12][7]=1;   Ch[18][6]=1;   Ch[24][9]=1;
              Ch[6][11]=2;                 Ch[18][8]=2;   Ch[24][10]=1;
                                           Ch[18][9]=1;
                                           Ch[18][11]=2;

Ch[1][2]=2;   Ch[7][2]=2;   Ch[13][2]=1;   Ch[19][4]=1;   Ch[25][1]=1;     Ch[32][2]=2;
Ch[1][4]=1;   Ch[7][4]=1;   Ch[13][3]=1;   Ch[19][7]=1;   Ch[25][4]=1;     Ch[32][5]=1;
Ch[1][7]=1;   Ch[7][6]=2;   Ch[13][5]=2;   Ch[19][10]=1;  Ch[25][7]=1;     Ch[32][7]=1;
Ch[1][9]=1;   Ch[7][8]=1;   Ch[13][7]=1;                  Ch[25][10]=1;
Ch[1][11]=2;  Ch[7][10]=2;  Ch[13][10]=1;


Ch[2][2]=2;   Ch[8][2]=2;   Ch[14][2]=2;   Ch[20][5]=1;   Ch[26][1]=2;     Ch[33][2]=1;
Ch[2][4]=1;   Ch[8][3]=1;   Ch[14][3]=1;   Ch[20][7]=1;   Ch[26][4]=1;     Ch[33][4]=2;
Ch[2][7]=1;   Ch[8][5]=2;   Ch[14][5]=1;   Ch[20][10]=1;  Ch[26][5]=2;     Ch[33][7]=1;
Ch[2][9]=2;   Ch[8][7]=1;   Ch[14][7]=1;                  Ch[26][7]=1;     Ch[33][9]=2;
Ch[2][11]=1;                Ch[14][10]=1;                 Ch[26][8]=1;
                                                          Ch[26][10]=1;

Ch[3][2]=2;   Ch[9][2]=2;   Ch[15][2]=2;   Ch[21][2]=2;   Ch[27][1]=2;
Ch[3][4]=1;   Ch[9][3]=1;   Ch[15][3]=1;   Ch[21][4]=1;   Ch[27][3]=1;
Ch[3][6]=1;   Ch[9][5]=2;   Ch[15][5]=2;   Ch[21][6]=1;   Ch[27][4]=1;
Ch[3][7]=1;   Ch[9][7]=1;   Ch[15][7]=1;   Ch[21][10]=1;  Ch[27][6]=2;
Ch[3][9]=2;   Ch[9][9]=1;   Ch[15][11]=1;                 Ch[27][7]=1;
Ch[3][11]=1;                                              Ch[27][9]=2;
                                                          Ch[27][10]=1;
 
Ch[4][2]=1;   Ch[10][3]=1;  Ch[16][2]=1;   Ch[22][2]=1;   Ch[28][2]=2;
Ch[4][4]=1;   Ch[10][5]=2;  Ch[16][3]=1;   Ch[22][4]=1;   Ch[28][4]=1;
Ch[4][7]=1;   Ch[10][7]=1;  Ch[16][5]=2;   Ch[22][7]=1;   Ch[28][5]=2;
Ch[4][9]=2;   Ch[10][10]=1; Ch[16][7]=1;   Ch[22][9]=2;   Ch[28][8]=1;
                            Ch[16][11]=1;  Ch[22][10]=1;  Ch[28][9]=2;
                                                          Ch[28][11]=1;

Ch[5][2]=1;   Ch[11][1]=2;  Ch[17][3]=1;   Ch[23][2]=2;   Ch[29][2]=2;
Ch[5][4]=1;   Ch[11][3]=1;  Ch[17][5]=2;   Ch[23][4]=1;   Ch[29][4]=1;
Ch[5][7]=1;   Ch[11][5]=2;  Ch[17][6]=1;   Ch[23][6]=1;   Ch[29][6]=2;
Ch[5][9]=2;   Ch[11][6]=1;  Ch[17][8]=2;   Ch[23][7]=1;   Ch[29][8]=1;
Ch[5][11]=1;  Ch[11][8]=2;                 Ch[23][9]=2;   Ch[29][10]=1;
              Ch[11][10]=1;                Ch[23][10]=1;


IniciaTablas();

bzero(ChN,sizeof(ChN));

{ 
static const char *stnom [] = { "","6","Maj7","lyd","Maj(9)","Maj7(9)","6/9","+","m","m6","m7","m7(b5)","m9","m7(9)","m7(11)","m(Maj7)","m/(Maj7)(9)","dim","dim7","7","7(Sus4)","7(b5)","7(9)","7(#11)","7(13)","7(b9)","7(b13)","7(#9)","+Maj7","+7","1+8","1+5","(Sus4)","2" };
for (int i=0; i<=33; i++) 
{
strcpy(ChN[i].Nom,stnom[i]);
ChN[i].tipo=i;
ChN[i].mt=Calculamt(i);
}
}

ChN[1].num=1;
ChN[6].num=1;
ChN[9].num=1;
ChN[32].num=1;




IniciaChords();

{
static const char *stnom[] = {"C","Db","D","Eb","E","F","Gb","G","Ab","A","Bb","B","C","C#","D","D#","E","F","F#","G","G#","A","A#","B"};

for (int i=0; i<=11; i++) strcpy(NC[i].Nom,stnom[i]);
for (int i=0; i<=23; i++) strcpy(NCE[i].Nom,stnom[i]);
}
NCE[0].note = 0;    NCE[1].note = 1;   NCE[2].note = 2;   NCE[3].note = 3;
NCE[4].note = 4;    NCE[5].note = 5;   NCE[6].note = 6;   NCE[7].note = -5;
NCE[8].note = -4;   NCE[9].note = -3;  NCE[10].note = -2; NCE[11].note = -1;
NCE[12].note = 0;   NCE[13].note = 1;  NCE[14].note = 2;  NCE[15].note = 3;
NCE[16].note = 4;   NCE[17].note = 5;  NCE[18].note = 6;  NCE[19].note = -5;
NCE[20].note = -4;  NCE[21].note = -3; NCE[22].note = -2; NCE[23].note = -1;


  //ALSA init


  snd_seq_open (&midi_out, "hw", SND_SEQ_OPEN_OUTPUT,0);
  snd_seq_set_client_name(midi_out, "stygmorgan");  
  snd_config_update_free_global();


  snd_seq_open (&midi_in, "hw", SND_SEQ_OPEN_INPUT, 0);
  snd_seq_set_client_name(midi_in, "stygmorgan");
  snd_config_update_free_global();

  char portname[50];
  sprintf (portname, "stygmorgan IN");

  pmidi_in = snd_seq_create_simple_port (midi_in, portname,
					 SND_SEQ_PORT_CAP_WRITE |
					 SND_SEQ_PORT_CAP_SUBS_WRITE,
					 SND_SEQ_PORT_TYPE_APPLICATION);

  sprintf (portname, "stygmorgan OUT");


      pmidi_out =
	snd_seq_create_simple_port (midi_out, portname,
				    SND_SEQ_PORT_CAP_READ |
				    SND_SEQ_PORT_CAP_SUBS_READ,
				    SND_SEQ_PORT_TYPE_APPLICATION);

Fl_Preferences stygmorgan (Fl_Preferences::USER, WEBSITE , PACKAGE);

int val=0;
char nomfile[196];
char orden[256];
stygmorgan.get("FirstTime",val,0);

if (val==0)
{
 bzero(nomfile,sizeof(nomfile));
 bzero(orden,sizeof(orden));
 sprintf (nomfile, "%s%s", getenv ("HOME"), "/.stygmorgan");
 sprintf (orden, "mkdir %s",nomfile);
 system(orden);
 bzero(orden,sizeof(orden));
 sprintf(orden, "cp %s/* %s",DATADIR,nomfile);  
 system(orden);
 bzero(orden,sizeof(orden));
 sprintf(orden, "7z x %s/MisStyles.STYR.xz",nomfile);
 system(orden);
 stygmorgan.set("FirstTime",1);
 sprintf(StylesFilename,"%s/MisStyles.STYR",nomfile);
 sprintf(SoundsFilename,"%s/MisSounds.SNDR",nomfile);
 sprintf(PresetFilename,"%s/GMPresetList.txt",nomfile);
 sprintf(DrumSetFilename,"%s/GMDN.txt",nomfile);
 sprintf(RegisFilename,"%s/MisReg",nomfile);

 
 stygmorgan.set("StylesFilename", StylesFilename);
 stygmorgan.set("SoundsFilename", SoundsFilename);
 stygmorgan.set("PresetFilename", PresetFilename);
 stygmorgan.set("DrumSetFilename", DrumSetFilename);
 stygmorgan.set("RegistrationFilename", RegisFilename);
 
 
 stygmorgan.set("TempDir",nomfile); 
 strcpy(TempDir,nomfile); 

}



stygmorgan.get("StylesFilename", StylesFilename,"",126);
stygmorgan.get("SoundsFilename", SoundsFilename,"",126);
stygmorgan.get("PresetFilename", PresetFilename,"",126);
stygmorgan.get("DrumSetFilename", DrumSetFilename,"",126);
stygmorgan.get("RegistrationFilename", RegisFilename,"",126);
stygmorgan.get("TempDir",TempDir,"",126);


  loadpreset(PresetFilename);
  loaddrumset(DrumSetFilename);
  readstyles(StylesFilename);
  readsounds(SoundsFilename);
  readregistrations(RegisFilename);

stygmorgan.get("UseSysEX",usesysex,0);

if (usesysex)
{
stygmorgan.get("ButStart",TextSTART,"",126);
stygmorgan.get("ButAutoF",TextAUTOF,"",126);
ConvierteHexString();
}

stygmorgan.get("MutesPatternChange", Respect,0);
stygmorgan.get("Bank_LSB_0", BankLSBLS,0);
stygmorgan.get("Bank_Truco_0", BankTruco,0);
stygmorgan.get("usejacktransport",usejacktransport,0);

stygmorgan.get("AutoSF", val,0);

if(val) cargaASF();

stygmorgan.get("AConnect", val,0);

if(val) Conecta(); 

stygmorgan.get("TypeChordRec", val,0);
TipoRecChord=val;
espera=1;
};


RMGMO::~RMGMO ()
{
  snd_seq_close (midi_out);
  snd_seq_close (midi_in);
};

void
RMGMO::IniciaTablas()
{

int i=0;
int j=0;
int k=0;
int l=0;

bzero(TCh, sizeof(TCh));


for(i=0; i<=33; i++)
 {
  for(j=0; j<=33; j++)
   {
    if (i==j)
      {
        for (k=1; k<=11; k++) TCh[i][j][k]=0;
        continue;
      }
    for(k=1; k<=11; k++)
         {
           if ( Ch[i][k] != 0)
             {
              if ( Ch[j][k]==1)
                { 
                    TCh[i][j][k]=0;
                    continue;
                 }
              if (Ch[j][k] != 1)
                 {
                  l=k;
                      while ( Ch[j][l] != 1)
                            {
                              l--;
                              if (l==0) 
                              { 
                                 TCh[i][j][k]=l - k;
                                 break;
                              }
                            }
                      TCh[i][j][k]=l - k;

                 }

             }

         }

   }
 }



};


void

RMGMO::IniciaChords()
{
int i,j;
int notas=1;
int numno[6];

NumChord3=0;
NumChord4=0;
NumChord5=0;

bzero(Chord3, sizeof(Chord3));
bzero(Chord4, sizeof(Chord4));
bzero(Chord5, sizeof(Chord5));

  for(i=0; i<=33; i++)
      {
        notas=1;
        bzero(numno,sizeof(numno));

     for(j=1; j<=11; j++)
             {
           if( Ch[i][j]==1 )
                {
                  notas++;
                  numno[notas]=j;
                }
             }



        switch(notas)
          {
             case 3:
               strcpy(Chord3[NumChord3].Nom,ChN[i].Nom);
               Chord3[NumChord3].di1=numno[2];
               Chord3[NumChord3].di2=numno[3]-numno[2];
               Chord3[NumChord3].fund=1;
               Chord3[NumChord3].tipo=i;
               Chord3[NumChord3].mt=Calculamt(i);
               NumChord3++;
               if (ChN[i].num == 1) break; 
               strcpy(Chord3[NumChord3].Nom,ChN[i].Nom);
               Chord3[NumChord3].di1=numno[3]-numno[2];
               Chord3[NumChord3].di2=12-numno[3];
               Chord3[NumChord3].fund=3;
               Chord3[NumChord3].tipo=i;
               Chord3[NumChord3].mt=Calculamt(i);
               NumChord3++;
               strcpy(Chord3[NumChord3].Nom,ChN[i].Nom);
               Chord3[NumChord3].di1=12-numno[3];
               Chord3[NumChord3].di2=numno[2];
               Chord3[NumChord3].fund=2;
               Chord3[NumChord3].tipo=i;
               Chord3[NumChord3].mt=Calculamt(i);
               NumChord3++;
               break;
              case 4:
                strcpy(Chord4[NumChord4].Nom,ChN[i].Nom);
               Chord4[NumChord4].di1=numno[2];
               Chord4[NumChord4].di2=numno[3]-numno[2];
               Chord4[NumChord4].di3=numno[4]-numno[3];
               Chord4[NumChord4].fund=1;
               Chord4[NumChord4].tipo=i;
               Chord4[NumChord4].mt=Calculamt(i);
               NumChord4++;
               if (ChN[i].num == 1) break;
               strcpy(Chord4[NumChord4].Nom,ChN[i].Nom); 
               Chord4[NumChord4].di1=numno[3]-numno[2];
               Chord4[NumChord4].di2=numno[4]-numno[3];
               Chord4[NumChord4].di3=12-numno[4];
               Chord4[NumChord4].fund=4;
               Chord4[NumChord4].tipo=i;
               Chord4[NumChord4].mt=Calculamt(i);
               NumChord4++;
               strcpy(Chord4[NumChord4].Nom,ChN[i].Nom);
               Chord4[NumChord4].di1=numno[4]-numno[3];
               Chord4[NumChord4].di2=12-numno[4];
               Chord4[NumChord4].di3=numno[2];
               Chord4[NumChord4].fund=3;
               Chord4[NumChord4].tipo=i;
               Chord4[NumChord4].mt=Calculamt(i);
               NumChord4++;
               strcpy(Chord4[NumChord4].Nom,ChN[i].Nom);
               Chord4[NumChord4].di1=12-numno[4];
               Chord4[NumChord4].di2=numno[2];
               Chord4[NumChord4].di3=numno[3]-numno[2];
               Chord4[NumChord4].fund=2;
               Chord4[NumChord4].tipo=i;
               Chord4[NumChord4].mt=Calculamt(i);
               NumChord4++;
               strcpy(Chord4[NumChord4].Nom,ChN[i].Nom);
               Chord4[NumChord4].di1=numno[2]+(12-numno[4]);
               Chord4[NumChord4].di2=numno[3]-numno[2];
               Chord4[NumChord4].di3=12-numno[3];
               Chord4[NumChord4].fund=4;
               Chord4[NumChord4].tipo=i;
               Chord4[NumChord4].mt=Calculamt(i);
               NumChord4++;
               break;
 
            case 5:
               strcpy(Chord5[NumChord5].Nom,ChN[i].Nom);
               Chord5[NumChord5].di1=numno[2];
               Chord5[NumChord5].di2=numno[3]-numno[2];
               Chord5[NumChord5].di3=numno[4]-numno[3];
               Chord5[NumChord5].di4=numno[5]-numno[4];
               Chord5[NumChord5].fund=1;
               Chord5[NumChord5].tipo=i;
               Chord5[NumChord5].mt=Calculamt(i);
               NumChord5++;
               if (ChN[i].num == 1) break;
               strcpy(Chord5[NumChord5].Nom,ChN[i].Nom);
               Chord5[NumChord5].di1=numno[3]-numno[2];
               Chord5[NumChord5].di2=numno[4]-numno[3];
               Chord5[NumChord5].di3=numno[5]-numno[4];
               Chord5[NumChord5].di4=12-numno[5];

               Chord5[NumChord5].fund=5;
               Chord5[NumChord5].tipo=i;
               Chord5[NumChord5].mt=Calculamt(i);
               NumChord5++;
               strcpy(Chord5[NumChord5].Nom,ChN[i].Nom);
               Chord5[NumChord5].di1=numno[4]-numno[3];
               Chord5[NumChord5].di2=numno[5]-numno[4];
               Chord5[NumChord5].di3=12 - numno[5];
               Chord5[NumChord5].di4=numno[2];
               Chord5[NumChord5].fund=4;
               Chord5[NumChord5].tipo=i;
               Chord5[NumChord5].mt=Calculamt(i);
               NumChord5++;
               strcpy(Chord5[NumChord5].Nom,ChN[i].Nom);
               Chord5[NumChord5].di1=numno[5]-numno[4];
               Chord5[NumChord5].di2=12-numno[5];
               Chord5[NumChord5].di3=numno[2];
               Chord5[NumChord5].di4=numno[3]-numno[2];
               Chord5[NumChord5].fund=3;
               Chord5[NumChord5].tipo=i;
               Chord5[NumChord5].mt=Calculamt(i);
               NumChord5++;
               strcpy(Chord5[NumChord5].Nom,ChN[i].Nom);
               Chord5[NumChord5].di1=12 - numno[5];
               Chord5[NumChord5].di2=numno[2];
               Chord5[NumChord5].di3=numno[3]-numno[2];
               Chord5[NumChord5].di4=numno[4]-numno[3];
               Chord5[NumChord5].fund=2;
               Chord5[NumChord5].tipo=i;
               Chord5[NumChord5].mt=Calculamt(i);
               NumChord5++;
               strcpy(Chord5[NumChord5].Nom,ChN[i].Nom);
               Chord5[NumChord5].di1=numno[2]+(12-numno[5]);
               Chord5[NumChord5].di2=numno[3]-numno[2];
               Chord5[NumChord5].di3=numno[4]-numno[3];
               Chord5[NumChord5].di4=12-numno[4];
               Chord5[NumChord5].fund=5;
               Chord5[NumChord5].tipo=i;
               Chord5[NumChord5].mt=Calculamt(i);
               NumChord5++;
               break;





           }

      }





};


unsigned long  
RMGMO::Calculamt(int acorde)
{

int k;
unsigned long resu;


    if (acorde==0) return(1);

    resu=1;

    for(k=0; k<=acorde; k++) resu *= 2; 


return(resu);

};



void
RMGMO::Conecta()
{

     FILE *fp;

     int client=0;
     int puerto=0;
     char temp[128];
     char temp1[128];
     char temp2[128];
     char *nume;

    if ((IsCoIn) || (IsCoOut)) disconectaaconnect();

    Fl_Preferences stygmorgan (Fl_Preferences::USER, WEBSITE, PACKAGE);

    stygmorgan.get("MidiInDevice", MID,"",127);
    stygmorgan.get("MidiOutDevice", MOD,"",127);

    if ((fp = fopen ("/proc/asound/seq/clients", "r")) != NULL)
        {
              bzero (temp, sizeof (temp));

                    while (fgets (temp, sizeof temp, fp) != NULL)
                      {

                            if (strstr(temp,"Client") != NULL)

                              {

                               strcpy(temp1,temp);
                               strtok(temp1," ");
                               nume=strtok(NULL,"\"");
                               sscanf(nume,"%d",&client);

                              }

                           if (strstr(temp,"Port") != NULL)
                              {
                                  strcpy(temp2,temp);
                                  strtok(temp2," ");
                                  nume=strtok(NULL,"  ");
                                  sscanf(nume,"%d",&puerto);
                                  if (strstr(temp,"stygmorgan IN") != 0 )
                                     {
                                      Cyoin=client;
                                      Pyoin=puerto;
                                     }
                                  if (strstr(temp,"stygmorgan OUT") != 0 )
                                     {
                                      Cyoout=client;
                                      Pyoout=puerto;
                                     }
                                  if (strstr(temp,MID) != 0 )
                                     {
                                      Ccin=client;
                                      Pcin=puerto;
                                     }
                                  if (strstr(temp,MOD) != 0 )
                                     {
                                      Ccout=client;
                                      Pcout=puerto;
                                     }

                               } 
                      } 
           }

       fclose(fp);
       conectaaconnect();
};




void
RMGMO::conectaaconnect()
{
  char tempi[128];

       if (MID != NULL)
       {
       bzero(tempi,sizeof(tempi));
       sprintf(tempi, "aconnect %d:%d  %d:%d",Ccin,Pcin,Cyoin,Pyoin);
       system(tempi);
       IsCoIn=1;
       }

       if (MOD != NULL )
       {
       bzero(tempi,sizeof(tempi));
       sprintf(tempi, "aconnect %d:%d  %d:%d",Cyoout,Pyoout,Ccout,Pcout);
       system(tempi);
       IsCoOut=1;
       }

};


void
RMGMO::disconectaaconnect()
{
     char tempi[128];
 
       if (MID != NULL)
       {
       bzero(tempi,sizeof(tempi));
       sprintf(tempi, "aconnect -d %d:%d  %d:%d",Ccin,Pcin,Cyoin,Pyoin);
       system(tempi);
       IsCoIn=0;
       }

       if (MOD != NULL )
       {
       bzero(tempi,sizeof(tempi));
       sprintf(tempi, "aconnect -d %d:%d  %d:%d",Cyoout,Pyoout,Ccout,Pcout);
       system(tempi);
       IsCoOut=0;
       }

};


void
RMGMO::cargaASF()
{
       Fl_Preferences stygmorgan (Fl_Preferences::USER, "stygmorgan.berlios.de", "stygmorgan");
       stygmorgan.get("SFFile", ASFFilename,"",126);
       char temp[512];
       sprintf(temp,"asfxload %s",ASFFilename);
       system(temp);
}

