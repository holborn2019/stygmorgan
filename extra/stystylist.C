#include <alsa/asoundlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <string.h>


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
};


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

} nStyle;

struct EventosGrabacion
{
int tipo;
snd_seq_tick_time_t tick;
int nota;
int canal;
int velocity;
int length;
} PEG[22][6000],tempEG;

struct NomControl
{
char Nom[24];
} CCn[128];


void
show_help ()
{
  fprintf (stderr, "Usage: stystylist -i [Input File] [-o] [Output File]\n\n" );
  fprintf (stderr,
	   "  -h ,     --help \t\t\t display command-line help and exit\n");
  fprintf (stderr,
	   "  -i ,     --input \t\t\t Input File\n");
  fprintf (stderr,
	   "  -o ,     --output \t\t\t Output File\n");
  fprintf (stderr, "\n");

}

int
main(int argc, char *argv[])
{
 int option_index = 0, opt;
 int exitwithhelp = 0;
 int i,j,all_ok,have_output;
 long tam;
 FILE *fn;
 FILE *fs;
 char Outputfile[256];
 char Inputfile[256];
 char wbuf[2048];

 bzero(Outputfile , sizeof(Outputfile));
 bzero(Inputfile, sizeof(Inputfile));
 
 fprintf (stderr,"\nstystylist show stygmoran style info.\nstystylist - Copyright (c) Josep Andreu 2019\n\n");

  struct option opts[] = {
    {"input", 1, NULL, 'i'},
    {"output", 1, NULL, 'o'},
    {"help", 0, NULL, 'h'},
    {0, 0, 0, 0}
  };

  while (1)
    {
      opt = getopt_long (argc, argv, "i:o:h", opts, &option_index);
      char *optarguments = optarg;

      if (opt == -1)
	break;
      switch (opt)
	{
	case 'h':
	  exitwithhelp = 1;
	  break;
       	case 'i':
        if (optarguments != NULL)
	    {
	    strcpy(Inputfile,optarguments); 
            if ((fs = fopen (Inputfile, "r")) == NULL) return 0;
            all_ok=1;
            }
          break;  
        case 'o':
           if (optarguments != NULL)
	    {
	    have_output = 1;
            strcpy(Outputfile,optarguments);
            }
            break;
         }

    }

  if (exitwithhelp != 0)
    {
      show_help ();
      return (0);
    };

  if ((argc < 5) || (!all_ok))
{
    fprintf (stderr, "Try 'stystylist --help' for usage options.\n");
    return(0);
}    

 memset(&tempEG ,0 , sizeof (tempEG)); 
 memset(&C ,0 , sizeof (C));
 memset(&PEG ,0 ,sizeof (PEG));
 memset(&nStyle, 0, sizeof (nStyle)); 
 memset(CCn, 0, sizeof CCn);


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





  if ((fn = fopen (Outputfile, "w")) == NULL)  return(0);

   memset (wbuf, 0, sizeof (wbuf));
   sprintf(wbuf,"Style details on %s\n",Inputfile);    
   fputs (wbuf, fn);

   memset (wbuf, 0, sizeof (wbuf));
   sprintf(wbuf,"\n\n");    
   fputs (wbuf, fn);


 while (!feof(fs))
            {
                i = fread(&nStyle, sizeof(nStyle),1,fs);
                if(feof(fs)) break;  
                for(i=0; i<22; i++)
                {
                tam = (long)(sizeof(tempEG) * nStyle.Pattern[i].eventos);
                 fread(&PEG[i][0],tam,1,fs); 
                }


 
   memset (wbuf, 0, sizeof (wbuf));
   sprintf(wbuf,"Name: %s\n",nStyle.Name);    
   fputs (wbuf, fn);
 
   memset (wbuf, 0, sizeof (wbuf));
   sprintf(wbuf,"Type: %d Style: %d Num.Patterns: %d\n",nStyle.tipo,nStyle.style,nStyle.numpat);    
   fputs (wbuf, fn);
 
   memset (wbuf, 0, sizeof (wbuf));
   sprintf(wbuf,"ppq: %d cpq: %d bpm: %d Nominator: %d Denominator: %d har %d\n",nStyle.ppq,nStyle.cpq,nStyle.bpm,nStyle.nominador,nStyle.denominator,nStyle.har);    
   fputs (wbuf, fn);
   
                  for (i=1; i<nStyle.numpat;i++)
                      {
                         for (j=0; j<nStyle.Pattern[i].eventos;j++)
                         {  
                            if (PEG[i][j].tipo == 10)
                                  {
                                     memset (wbuf, 0, sizeof (wbuf));
                                     sprintf(wbuf,"WARNING: Estilo:%s Variacion:%s evento %d\n",nStyle.Name,nStyle.Pattern[i].Name,j);    
                                     fputs (wbuf, fn);
                                  }
                            
                            if (PEG[i][j].tipo == 3)
                                  {
                                
                                 switch(PEG[i][j].nota)
                                      {
                                      
                                        case 0:
                                        break;
                                        case 1:
                                        break;                                        
                                        case 2:
                                        break;
                                        case 3:
                                        break;
                                        case 5:
                                        break; 
                                        case 6:
                                        break;
                                        case 7:
                                        break;
                                        case 8:
                                        break;
                                        case 10:
                                        break;
                                        case 11:
                                        break;
                                        case 32:
                                        break;
                                        case 64:
                                        break;
                                        case 65:
                                        break;
                                        case 66:
                                        break;
                                        case 68:
                                        break; 
                                        case 84:
                                        break;
                                        case 91:
                                        break;
                                        case 93:
                                        break;
                                        case 98:
                                        break;
                                        case 99:
                                        break;
                                        case 100:
                                        break;
                                        case 101:
                                        break;
                                        case 120:
                                        break;
                                        case 121:
                                        break;
                                        case123:
                                        break;
                                        case 124:
                                        break;
                                        case 125:
                                        break;
                                        case126:
                                        break;
                                        case 127:
                                        break;
                                        default:
                                        memset (wbuf, 0, sizeof (wbuf));
                                        sprintf(wbuf,"WARNING: Variacion:%s evento %d Control:%d %s\n",nStyle.Pattern[i].Name,j,PEG[i][j].nota,CCn[PEG[i][j].nota].Nom);
                                        fputs (wbuf, fn);
                                        
                                        }     
                                   }
                                                        
                          }    

                       }   


   memset (wbuf, 0, sizeof (wbuf));
   sprintf(wbuf,"\n\n");    
   fputs (wbuf, fn);



              }


fclose(fs);
fclose(fn);
exit(0);
}


