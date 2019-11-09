/*
  stygmorgan - a ryhthm station software

    stygmorgan.h  -  Main declarations
    Copyright (C) 2006 Josep Andreu (Holborn)
    Author: Josep Andreu

   This program is free software; you can redistribute it and/or modify
   it under the terms of version 2 of the GNU General Public License
   as published by the Free Software Foundation.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License (version 2) for more details.

   You should have received a copy of the GNU General Public License (version2)
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
   
*/






#ifndef stygmorgan_h
#define stygmorgan_h

#include <alsa/asoundlib.h>
#include <stdio.h>
#include <ctype.h>
#include <X11/xpm.h>
#include <jack/jack.h>
#include <jack/midiport.h>


#include "config.h"
#define MAGIC_FILE 0x4d546864
#define MAGIC_TRACK 0x4d54726b
#define CASM 0x4341534d
#define CSEG 0x43534547
#define Sdec 0x53646563
#define Ctab 0x43746162
#define Cntt 0x436e7474
#define POLY 6

extern int Pexitprogram,programa,espera,pera,chsel,x,y,sponmix,wabout,whelp;
extern Pixmap p,mask;
extern XWMHints *hints;
extern int jack,alsa,exitwithhelp;
extern struct song

{
 int a;
 int b;
 int c;
 int d;
 int e;
 int f;
 int fin;
 int style;
 int pattern;
 char go_to[4];
 int times;
 char go_af[4];
 int atimes;
 char ch1[20];
 char ch2[20];
 char ch3[20];
 char ch4[20];
 int ar8;
 int ar16;
 int ar8a;
 int ar16a;
} S[129];

struct MasterTempoData
{
 int bar;
 int black;
 int tempo;

};


extern struct songcon
{
 char title[100];
 int bpm;
 int MasterT;
 MasterTempoData TemT[200];
 song S[129];
} SongF;




class RMGMO

{

public:

   RMGMO();
  ~RMGMO();
   void ConvierteHexString();
    int BuscaPosTempo(int Compas, int Negra);
   void calctempo(int NewTempo);
   void PonerTempoMidiFile();
   void PonNotesOffChannel(int canal, snd_seq_tick_time_t gtick);
   void deleteregistration(int regis);
   void deletesound(int sound);
   int ChecaExporta();
   void seqbuscacs(int siguiente,unsigned int ktick);
   void ponPendientes(int gnota,int gcanal,snd_seq_tick_time_t gtick);
   void ponPendientesEE(int gnota,int gcanal,long time);
   void Ponlo(int tipo,snd_seq_tick_time_t gtick, int gnota, int canal,int gvelo, int glen);
   void cambiopat(unsigned int ktick);
   long calculadelta(int);
   void PonNotesOff(int force,snd_seq_tick_time_t gtick);
   void ActuPen();
   void ActuPenEE();
   void parsetracks();
   void generatracks();
   void PonAjusta();
   int CheckChord(char *chord);
   void UsaTempoTrack();
   void BorraTiempo(int i);
   void InsertaTiempo(int i);
   void MiraCambioTempoM(int tcompas,int neg);
   void BuscaTempo();
   void saveMidiFile(char *filename);
   void MiraFin();
   void CheckAnti();
   void MiraAnti(int vn);
   int BuscaM(int nb);
   int mirasaltos(int nb);
   void BuscaRepes();
   void MiraCosas();
   void MiraAcorde(int mcas,int pos);
   void PonPatron(int vari);  
   int buscalargo(int track,int ct);
   void repon(int track);
   void cargaASF();
   void conectaaconnect();
   void disconectaaconnect();
   void BuscaNext();
   void AyudaQuitaSolo();
   void AyudaSolo(int mcanal);
   void RegaPon();
   void PonaReg();
   void saveregistration();
   void readregistrations(char *filename);
   void readregistration(int regis);
   void writeregistration(int regis);
   void readsinglestyle(char *filename);
   void savesinglestyle(char *filename);

   int ev_count;
   void SeqPlay();
   int plus(int nota);
   void Conecta();
   void XGGM();
   void ActuVarVol(int a, int b);
   void ActuAccVol();
   void ActuKeybVol();
   void IniciaChords();
   unsigned long Calculamt(int acorde); 
   void IniciaTablas();
   void PonUnoMas(int index);
   void InsertaEvento(int index, int tipo, int canal);
   void ponsitio(int evento);
   void ActuaEvento(int multi, int pvelo, int plength, unsigned int pos, int note, int velo, int length, int velopor, int lenpor );
   int buscanum(const char *var);
   void convnotaval(char *var, int i);
   void convnota(char *var, int i);
   void convtickcompas(char *var, int i);
   void convtickcompasval(char *var, int i);
   void borraevento(int num);
   void envionota(int canal,int nota, int velocity);
   void loaddrumset(char *filename);
   void buscacs(int vari);
   void MiraSiNext();
   void AsignaTabla();
   void silent(int data,int c1, int c2);
   void allio();
   void writestyle(int estilo);
   void writestylec(int estilo,int funcion );
   void writesound(int sound);
   void readstyle(int estilo);
   void readsound(int sound);
   void procesaregleido();
   void procesasoleido();
   void procesaleido();
   void savestyle();
   void savesong(char *filename);
   void loadsong(char *filename);
   void savesound();
   void readstyles(char *filename);
   void readsounds(char *filename);
   void ponbasemix();
   void ponmixpatternenmix(int patron);
   void ponsoundenmix();
   void ponmixensound();
   void ponmixenmixpattern(int patron);
   void ponmixpattern(int pista);
   void BuscaSi();
   int bpn(char *Name);
   int CalculaBanco(int i);
   void mirapc(int variacion);
   void loadpreset(char *filename);
   void panico(int data, int canal1, int canal2);
   void ostart();
   void ostop();
   void midievents(snd_seq_event_t *midievent);
   void sacadirecto(long len, snd_seq_event_t *midievent);
   void sacaorgan(int len, snd_seq_event_t *midievent, snd_seq_tick_time_t gtick, int glen);
   void miramidi();
   void MiraChord();
   void enviosincro(int tipo);
   void enviocontrol(int canal, int control, int value);
   void envioprograma(int canal, int programa);
   void enviobend(int canal, int valor);
   void set_tempo();
   void init_queue();
   void clear_queue();
   snd_seq_tick_time_t get_tick();
   void process_midi_controller_events(int parameter, int value);
   void jack_process_midievents (jack_midi_event_t *midievent);
   void PonNotesOffOrgan(int force, snd_seq_tick_time_t gtick); 
   void pontempoenjack(); 
   int ImportaMidi(char *filename);
   void PonPlay(int tipo, snd_seq_tick_time_t gtick, int gnota, int gcanal, int gvelocity, int glength);
   void PonGraba(int tipo, snd_seq_tick_time_t gtick, int gnota, int gcanal, int gvelocity);
   int miranota(int nota, int canal); 
   void EPlay();
   int leer_bytes(FILE *fp, int n);
   unsigned long leer_delta(FILE *fp);

  snd_seq_tick_time_t tick;
  snd_seq_t *seq_handle;
  snd_seq_t *midi_in;
  snd_seq_t *midi_out;
  snd_seq_tick_time_t ptick, ttick;

    jack_client_t *jackclient;
    jack_options_t options;
    jack_status_t status;
    char jackcliname[64];

     int adatasize;
     unsigned char adata[2048];



    unsigned char START[64];
    char TextSTART[128];
    unsigned char AUTOF[64];
    char TextAUTOF[128];
    int usesysex;
    int pbStart;
    int pbAutoF;
    int ulase;
    int wmore;
    int tapaga;
    int semi,osemi;
    int cocas[16];
    int lastvelo[16];
  
  
  int rtplay;
  int SNomi;
  int TiempoBase;
  int genmidi;
  int nunegra;
  int divisor;
  int ajusta;
  int anegra;
  int wpreferences;
  int wdrummixer;
  int wsequencer;
  int weventeditor;
  int wmixereditor;
  int wpatterneditor;
  int wstyleeditor;
  int CNStyle;
  int CNPattern;
  int imenu;
  int MTempo;
  int finito;
  int mirado;
  int cc1;
  snd_seq_tick_time_t posanti;
  int anti;
  int vnegra;
  int scompas;
  int cas;
  int splay;
  int ventana;
  int Respect;
  int BankLSBLS;
  int BankTruco;
  int IsCoOut;
  int IsCoIn;
  int Cyoin;
  int Cyoout;
  int Pyoin;
  int Pyoout;
  int Ccin;
  int Ccout;
  int Pcout;
  int Pcin;
  int CambiaMidi;
  int Sonido;
  int Estilo;  
  char MID[128],MOD[128]; 
  int ponstart;
  int syncstart;
  int bass;
  int TipoRecChord;
  int bcancel;
  int vuelve;
  unsigned int espacio;
  int numLista[1000];
  int SStipo;
  int AccVol;
  int KeybVol;
  int NumChord3;
  int NumChord4;
  int NumChord5;
  int selevent;
  int seltipo;
  int selcanal;
  int EventoCambia;
  double rela;
  int lppq;
  int vum,ponvum;
  int sel;
  int sic,nic,cc,sema,cambioc;
  int ultimalanegra;
  int ultimalacas;
  int AFill;
  int rema;
  int ultima;
  int hay,endi;
  int siguiente;
  int tiene;
  int tbotvar[22];
  int sbot[22];
  int tvb[22];
  int losquehayqueponer[130];
  int NotaVel[130];
  int VelPorce[130];
  int nb;
  int ultrack;
  int ulcontrol;
  char
  StylesFilename[256],SoundsFilename[256],PresetFilename[256],DrumSetFilename[256],ASFFilename[256],RegisFilename[256];
  char TempDir[128];
  int negra,onegra;
  int isnew,isnews,isnewr;
  int numstyles,numsounds,numregis;
  long mt;
  int note_active[POLY];
  int rnote[POLY];
  int gate[POLY];
  int solo[17];
  int transpose, pedal, bplay, bpm, cs, pmidi_in, pmidi_out, grabaconta, queue_id;
  int cMidiRead, LaUltima;
  int ctipo, fundi;
  int tempo;
  int CambiaTempo;
  int Variacion;
  int patrones;
  int usejacktransport;
  int J_SAMPLE_RATE;
  int J_PERIOD;
  jack_port_t *jack_midi_in, *jack_midi_out;



  int split;
  int selmix;
  char dcompas[3];
  int pc[16];
  int pcp[16];
  int tcr[16];
  int chro[16];
  int nttc[16];
  int pchar[16];
  int pclio[16];
  int pcpon[16];
  unsigned int longi, longic,vcompas;
  char NombreAcorde[20];


   int TCh[34][34][12];
   int Ch[34][13];


  int delta;


  int Pendientes;
  int PendientesEE;

  char drums[22000];
  int cdrums;
  int stdrums;
  int deltadrums;
  char bajo[10000];
  int cbajo;
  int stbajo;
  int deltabajo;
  char acc1[22000];
  int cacc1;
  int stacc1;
  int deltaacc1;
  char acc2[22000];
  int cacc2;
  int stacc2;
  int deltaacc2;
  char acc3[22000];
  int cacc3;
  int stacc3;
  int deltaacc3;
  char acc4[22000];
  int cacc4;
  int stacc4;
  int deltaacc4;
  char acc5[22000];
  int cacc5;
  int stacc5;
  int deltaacc5;




struct ClaseStyle
{
 char Nom[32];
} CStyle[18];


struct UidUTNames
{
 char Nom[16];
} UTNames[18];

struct UidUCNames
{
  char Nom[16];
} UCNames[5];
  

struct CanalMixer
{ int OnOff;
  int solo;
  int more;
  int pan;
  int reverb;
  int chorus;
  int vol;
  int program;
  int ch;
  int bMSB;
  int bLSB;
  int octave;
  int transpose;
} CM[16];


struct sonido
{ char Name[64];
  CanalMixer CM[5];
} nSound,tSound;


struct NomSonidos
{
 int num;
 char Name[64];
 int tipo;
 int style;
} SoundNom[200];

struct NomRegistra
{
 int num;
 char Name[64];
 int tipo;
 int style;
} RegisNom[200];





struct Registration
{
 char Name[32];
 int tipo;
 int numstyle;
 int numsound;
 int tempo;
 int syncstart;
 int volacc;
 int volsound;
 int StySound;
 int TipoChordRec;
 int Pattern;
 int har;
 int AFill;
 int split;
 int transpose;


} R,Rtemp;



struct EventosGrabacion
{
int tipo;
snd_seq_tick_time_t tick;
int nota;
int canal;
int velocity;
int length;
} PEG[22][6000],EG[64000],tempEG;




struct mcasm
{
int track;
char Name[16];
int Canal;
int ReadOnly;
int NoteMute1;
int NoteMute0;
int ChMute4;
int ChMute3;
int ChMute2;
int ChMute1;
int ChMute0;
int ChRoot;
int ChType;
int NTR;
int NTT;
int HKey;
int LLim;
int HLim;
int RTR;
int u[16];
long ChM;
} C;

struct StylePattern
{ 
char Name[32];
unsigned int bars;
int start;
int stop;
int eventos;
int numcasm;
mcasm casm[16];
CanalMixer CM[16];
};


struct StyleStr

{ 
char Name[32];
int tipo;
int style;
int ppq;
int cpq;
int nominador;
int denominator;
int har;
int bpm;
int numpat;
StylePattern Pattern[22];

} nStyle,tStyle;



struct NomStyles
{
 int num;
 char Name[32];
 int tipo;
 int style;
} StyleNom[1000];



struct NomControl
{
char Nom[24];
} CCn[128];

struct NomChord
{
 char Nom[3];
} NC[13];


struct NomChordExtended
{
 char Nom[3];
 int  note; 
} NCE[25];


struct TipoCh

{
int num;
char Nom[16];
int tipo;
int mt;
} ChN[34];





struct Ch3

{
 int tipo;
 long mt;
 int fund;
 int di1;
 int di2;
 char Nom[10];
} Chord3[17];

struct Ch4

{
  int tipo;
  long mt;
  int fund;
  int di1;
  int di2;
  int di3;
  char Nom[16];
} Chord4[62];

struct Ch5

{
  int tipo;
  long mt;
  int fund;
  int di1;
  int di2;
  int di3;
  int di4;
  char Nom[16];
} Chord5[67];


struct PBList
  {
    int Prog;
    char ProgName[24];
  };

struct PPList
  {
    int Banco;
    PBList PBanco[129];
  }  PresetList[129];


struct NotaDrum
{
char Nom[24];
int Note;
};


struct ProgDrum
{
 int ProgD;
 NotaDrum DNN[62];
} PD[60];


struct Repetidor
{
 int times;
} Repe[129];

struct Saltador
{
 int times;
 int pasa;
} Salta[129];


struct Pendingoff
{
 int canal;
 int nota;
 unsigned int delta;
 int estado;

} PO[256],POAC[256];


struct PendingoffEE
{
 int canal;
 int nota;
 long delta;
 int estado;

} POEE[256],POACEE[256];



struct Midi_Event {
    jack_nframes_t  time;
    int             len;    /* Length of MIDI message, in bytes. */
    jack_midi_data_t  *data;

} Midi_event[2048];




};
#endif


