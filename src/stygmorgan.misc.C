/*
  stygmorgan - a ryhthm station software

    stygmorgan.misc.C  -  Miscelaneous functions
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

#include "stygmorgan.h"


int
RMGMO::CalculaBanco(int i)
{
int banco;
  banco = (127 * CM[i].bLSB) + CM[i].bMSB;
    if (banco<129) return(banco);
    return(CM[i].bMSB);

};

int
RMGMO::bpn(char *Name)

{
    int k=0;
    while (k < nStyle.numpat)

      {
       if ( strcmp (Name, nStyle.Pattern[k].Name) == 0)
       {
       return(k);
       }
        k++;

      }
    return(20);
}


void 
RMGMO::procesaleido()
{


 StyleNom[numstyles].num=numstyles;
 strcpy(StyleNom[numstyles].Name,nStyle.Name);
 StyleNom[numstyles].tipo=nStyle.tipo;
 StyleNom[numstyles].style=nStyle.style;

numstyles++; 

};


void 
RMGMO::procesasoleido()
{


 SoundNom[numsounds].num=numsounds;
 strcpy(SoundNom[numsounds].Name,nSound.Name);

numsounds++; 

};

void 
RMGMO::procesaregleido()
{

 RegisNom[numregis].num=numregis;
 RegisNom[numregis].style=R.tipo;
 strcpy(RegisNom[numregis].Name,R.Name);

numregis++; 
 
};




void
RMGMO::AsignaTabla()
{

int i;
memset(tvb , 0 ,sizeof(tvb));


for (i=1; i<=nStyle.numpat; i++)
 {
   if (strcmp(nStyle.Pattern[i].Name,"All") == 0)
   {  tvb[1]=i; tbotvar[i]=1;break;}
   if (strcmp(nStyle.Pattern[i].Name,"Main A") == 0)
   {  tvb[1]=i; tbotvar[i]=1;continue;}
   if (strcmp(nStyle.Pattern[i].Name,"Main B") == 0) 
   { tvb[2]=i; tbotvar[i]=2;continue;}
   if (strcmp(nStyle.Pattern[i].Name,"Main C") == 0)
   { tvb[3]=i; tbotvar[i]=3;continue;}
   if (strcmp(nStyle.Pattern[i].Name,"Main D") == 0)
   { tvb[4]=i; tbotvar[i]=4;continue;}
   if (strcmp(nStyle.Pattern[i].Name,"Fill In AA") == 0)
   { tvb[5]=i; tbotvar[i]=5;continue;}
   if (strcmp(nStyle.Pattern[i].Name,"Fill In BB") == 0)
   { tvb[6]=i; tbotvar[i]=6;continue;}
   if (strcmp(nStyle.Pattern[i].Name,"Fill In CC") == 0)
   { tvb[7]=i; tbotvar[i]=7;continue;}
   if (strcmp(nStyle.Pattern[i].Name,"Fill In DD") == 0)
   { tvb[8]=i; tbotvar[i]=8;continue;}
   if (strcmp(nStyle.Pattern[i].Name,"Intro A") == 0)
   { tvb[9]=i; tbotvar[i]=9;continue;}
   if (strcmp(nStyle.Pattern[i].Name,"Intro B") == 0)
   { tvb[10]=i; tbotvar[i]=10;continue;}
   if (strcmp(nStyle.Pattern[i].Name,"Intro C") == 0)
   { tvb[11]=i; tbotvar[i]=11;continue;}
   if (strcmp(nStyle.Pattern[i].Name,"Ending A") == 0)
   { tvb[12]=i; tbotvar[i]=12;continue;}
   if (strcmp(nStyle.Pattern[i].Name,"Ending B") == 0)
   { tvb[13]=i; tbotvar[i]=13;continue;}
   if (strcmp(nStyle.Pattern[i].Name,"Ending C") == 0)
   { tvb[14]=i; tbotvar[i]=14;continue;}
   if (strcmp(nStyle.Pattern[i].Name,"Fill In BA") == 0)
   { tvb[15]=i; tbotvar[i]=15;continue;}
   if (strcmp(nStyle.Pattern[i].Name,"Fill In AB") == 0)
   { tvb[16]=i; tbotvar[i]=16;continue;}

}

};

void
RMGMO::ponsoundenmix()
{
   int i;

  for(i=0; i<=4; i++)
  {
   enviocontrol(i,11,127);

   CM[i].OnOff = nSound.CM[i].OnOff;
   CM[i].bMSB = nSound.CM[i].bMSB;
   CM[i].bLSB = nSound.CM[i].bLSB;

if ( CM[i].program != nSound.CM[i].program)
   {   
    CM[i].program = nSound.CM[i].program;
    envioprograma(i,CM[i].program);
   }
   
if ( CM[i].vol != nSound.CM[i].vol)
   {
   CM[i].vol = nSound.CM[i].vol;
   ActuVarVol(i,i); 
   }

if ( CM[i].chorus != nSound.CM[i].chorus)   
   {
   CM[i].chorus = nSound.CM[i].chorus;
   enviocontrol(i,93,CM[i].chorus);
   }
   
if ( CM[i].reverb != nSound.CM[i].reverb)
   {   
   CM[i].reverb = nSound.CM[i].reverb;
   enviocontrol(i,91,CM[i].reverb);
   }

if ( CM[i].pan != nSound.CM[i].pan)  
   {
   CM[i].pan = nSound.CM[i].pan;
   enviocontrol(i,10,CM[i].pan);
   }
   
   enviobend(i,0);

   CM[i].octave = nSound.CM[i].octave;
   CM[i].transpose = nSound.CM[i].transpose;
   CM[i].solo = nSound.CM[i].solo;
   CM[i].more = nSound.CM[i].more;


  }
}


void
RMGMO::ponmixensound()
{
   int i;

  for(i=0; i<=4; i++)
  {

   nSound.CM[i].OnOff=CM[i].OnOff;
   nSound.CM[i].program=CM[i].program;
   nSound.CM[i].vol=CM[i].vol;
   nSound.CM[i].chorus=CM[i].chorus;
   nSound.CM[i].reverb=CM[i].reverb;
   nSound.CM[i].pan=CM[i].pan;
   nSound.CM[i].bMSB=CM[i].bMSB;
   nSound.CM[i].bLSB=CM[i].bLSB;
   nSound.CM[i].octave=CM[i].octave;
   nSound.CM[i].transpose=CM[i].transpose;
   nSound.CM[i].solo=CM[i].solo;
   nSound.CM[i].more=CM[i].more;

  }
};



void 
RMGMO::borraevento(int num)
{

int i;
for(i=num; i<nStyle.Pattern[Variacion].eventos; i++)

  PEG[Variacion][i]=PEG[Variacion][i+1];


nStyle.Pattern[Variacion].eventos--;
EventoCambia=1;

};


void 
RMGMO::convtickcompas(char *var, int i)
{

  sprintf(var,"%02d/%d/%04d", (PEG[Variacion][i].tick / longic) + 1, 
 ((PEG[Variacion][i].tick % longic) / nStyle.ppq) +1 , PEG[Variacion][i].tick % nStyle.ppq);

};


void 
RMGMO::convtickcompasval(char *var, int i)
{

 sprintf(var," %03d/%d/%04d", (i / longic) + 1, 
 ((i % longic) / nStyle.ppq) +1 , i % nStyle.ppq);



};



void 
RMGMO::convnota(char *var, int i)
{

if (pcp[PEG[Variacion][i].canal]==9)
      { 
         if (CM[9].program < 60)
         sprintf(var,"%s",PD[CM[9].program].DNN[PEG[Variacion][i].nota].Nom); 
         if (strlen(var) < 3) sprintf(var,"%s%d",NCE[PEG[Variacion][i].nota % 12].Nom,(PEG[Variacion][i].nota /12)-1);
      } 
      else  sprintf(var,"%s%d",NCE[PEG[Variacion][i].nota % 12].Nom,(PEG[Variacion][i].nota / 12) -1);
};


void 
RMGMO::convnotaval(char *var, int i)
{


switch(seltipo)
{
      case 2:

if (selcanal==9)
      {
         if (CM[9].program < 60)
         sprintf(var,"%s",PD[CM[9].program].DNN[i].Nom);
         if (strlen(var) < 3) sprintf(var,"%s%d",NCE[i%12].Nom, (i/12)-1);
      }
      else

       sprintf(var,"%s%d",NCE[i % 12].Nom, (i/12)-1);

      break;
      case 3:

        sprintf(var,"%s",CCn[i].Nom);
      break;
      case 4:
      sprintf(var,"%s",PresetList[CalculaBanco(selcanal)].PBanco[i].ProgName);
         break;

      case 5:

       sprintf(var,"%d",i);

}


};


int
RMGMO::buscanum(const char *var)
{
int i;
char temp1[128],temp2[256];
sscanf (var,"%s %d %s",(char*)&temp1,&i,(char*)&temp2);

return(i);

};




void
RMGMO::ActuaEvento(int multi, int pvelo, int plength, unsigned int pos, int note, int velo, int length, int velopor, int lenpor)
{

  switch(seltipo)
    {

     case 2:

         PEG[Variacion][selevent].nota=note;
         if ( velopor != 0)
           {
            PEG[Variacion][selevent].velocity += (PEG[Variacion][selevent].velocity * velopor / 100);
            if (PEG[Variacion][selevent].velocity > 127 ) PEG[Variacion][selevent].velocity=127;
            if (PEG[Variacion][selevent].velocity < 0 ) PEG[Variacion][selevent].velocity=0;
            }
            else  if (pvelo == 0) PEG[Variacion][selevent].velocity=velo;

         if (lenpor !=0)
            {
            PEG[Variacion][selevent].length += (PEG[Variacion][selevent].length * lenpor / 100);
            if (PEG[Variacion][selevent].length < 0 ) PEG[Variacion][selevent].length=0;
            }
            else  if (plength == 0) PEG[Variacion][selevent].length=length;
         break;
     case 3:
         PEG[Variacion][selevent].nota=note;
         if ( velopor != 0)
                    {
                       PEG[Variacion][selevent].velocity += (PEG[Variacion][selevent].velocity * velopor / 100);
                       if (PEG[Variacion][selevent].velocity > 127 ) PEG[Variacion][selevent].velocity=127;
                       if (PEG[Variacion][selevent].velocity < 0 ) PEG[Variacion][selevent].velocity=0;
                    }
           else
         if (pvelo == 0) PEG[Variacion][selevent].velocity=velo;
         break;
     case 4:
         PEG[Variacion][selevent].nota=note;
         break;
     case 5:
         PEG[Variacion][selevent].nota=note;
         break;

    }

     if ((multi==0) && PEG[Variacion][selevent].tick != pos)
       {
           PEG[Variacion][selevent].tick = pos;
           ponsitio(selevent);
       }



};

void
RMGMO::ponsitio(int evento)
{


      tempEG=PEG[Variacion][evento];


while (tempEG.tick < PEG[Variacion][evento-1].tick)

    {
       PEG[Variacion][evento]=PEG[Variacion][evento-1];
       PEG[Variacion][evento-1]=tempEG;
       evento--;
       if (evento==0) break;
    }

while (tempEG.tick > PEG[Variacion][evento+1].tick)

      {
        PEG[Variacion][evento]=PEG[Variacion][evento+1];
        PEG[Variacion][evento+1]=tempEG;
        evento++;
        if (evento==nStyle.Pattern[Variacion].eventos) break;
      }

};


void 
RMGMO::InsertaEvento(int index, int tipo, int canal)
{

       switch(tipo)
        {
          case 2:
          tempEG.nota=60;
          tempEG.velocity=64;
          tempEG.length=20;
          break;
          case 3:
          tempEG.nota=11;
          tempEG.velocity=64;
          tempEG.length=0;
          break;
          case 4:
          tempEG.nota=0;
          tempEG.velocity=0;
          tempEG.length=0;
          break;
          case 5:
          tempEG.nota=0;
          tempEG.velocity=0;
          tempEG.length=0;
        }

 if (index == 0) tempEG.tick = 0; else
   tempEG.tick=PEG[Variacion][index].tick;
       tempEG.canal=canal;
       tempEG.tipo=tipo;

PonUnoMas(index);

};


void
RMGMO::PonUnoMas(int index)
{

int i;

if (nStyle.Pattern[Variacion].eventos==6000)
{
  printf("Sorry Pattern is Full\n");
  return;
}

for(i=nStyle.Pattern[Variacion].eventos; i>=index; i--)
{
  PEG[Variacion][i+1]=PEG[Variacion][i];
};

PEG[Variacion][index]=tempEG;

nStyle.Pattern[Variacion].eventos++;

EventoCambia=1;

};


void
RMGMO::D1Db1toRide()
{

  int i;
  
         
       for (i=0;i<nStyle.Pattern[Variacion].eventos;i++)    
         {
             if (pcp[PEG[Variacion][i].canal]==9)
           {
             switch (PEG[Variacion][i].nota)
               {
                   case 25:
                    PEG[Variacion][i].nota=51;
                    break;
  
                   case 26:
                    PEG[Variacion][i].nota=51;
                    break;
                }  
            }
          }

};


void
RMGMO::HighQtoLowFloorTom()
{

  int i;
  
         
       for (i=0;i<nStyle.Pattern[Variacion].eventos;i++)    
         {
             if (pcp[PEG[Variacion][i].canal]==9)
           {
             switch (PEG[Variacion][i].nota)
               {
                   case 27:
                    PEG[Variacion][i].nota=41;
                    break;
                }  
            }
          }
};

void
RMGMO::G0toCastanets()
{

  int i;
  
         
       for (i=0;i<nStyle.Pattern[Variacion].eventos;i++)    
         {
             if (pcp[PEG[Variacion][i].canal]==9)
           {
             switch (PEG[Variacion][i].nota)
               {
                   case 19:
                    PEG[Variacion][i].nota=85;
                    break;
                }  
            }
          }
};





void
RMGMO::XGGM()
{
  int i;


  for (i=0;i<nStyle.Pattern[Variacion].eventos;i++)
    {

        if (pcp[PEG[Variacion][i].canal]==9)
           {
             switch (PEG[Variacion][i].nota)
               {
                   case 25:
                      PEG[Variacion][i].nota=38;
                      break;
                   case 26:
                      PEG[Variacion][i].nota=40;
                      break; 
                   case 27:
                      PEG[Variacion][i].nota=39;
                      break;
                   case 33:
                      PEG[Variacion][i].nota=35;
                      break;
                   case 32:
                      PEG[Variacion][i].nota=31;
                      break;
                }
             }

     }

};



void
RMGMO::PonaReg()
{
  R.tipo=nStyle.style;
  R.numstyle=Estilo;
  R.numsound=Sonido;
  R.tempo=bpm;
  R.syncstart=syncstart;
  R.volacc=KeybVol;
  R.volsound=AccVol;
  R.StySound=sel;
  R.TipoChordRec=TipoRecChord;
  R.Pattern=Variacion;
  R.har=0;
  R.AFill=AFill;
  R.transpose=transpose;
  R.split=split;
}


void
RMGMO::RegaPon()
{

  Estilo=R.numstyle;
  Sonido=R.numsound;
  bpm=R.tempo;
  syncstart=R.syncstart;
  KeybVol=R.volacc;
  AccVol=R.volsound;
  sel=R.StySound;
  TipoRecChord=R.TipoChordRec;
  Variacion=R.Pattern;
  AFill=R.AFill;
  transpose=R.transpose;
  split=R.split;
}



int
RMGMO::BuscaPosTempo(int Compas, int Negra)
{

int i=1;

while( SongF.TemT[i].bar < Compas ) 
{
if (SongF.TemT[i].bar==0) break;

 i++;
 
if (i>=200) return(0);

}


while((SongF.TemT[i].bar == Compas) && ( SongF.TemT[i].black < Negra )) 
{

if (SongF.TemT[i].bar==0) break;

i++;
if (i>=200) return(0);
}


return(i); 
 
};


void
RMGMO::ConvierteHexString()
{

int i,j;
unsigned int k;
char temp[4];
char temp1[4];


if (TextSTART != NULL)
{

bzero(START,sizeof(START));
j=0;

for (i=0; i<(int)strlen(TextSTART); i=i+3)
{
 
  bzero(temp, sizeof(temp));
  bzero(temp1,sizeof(temp1));  

  temp[0]=TextSTART[i]; temp[1]=TextSTART[i+1]; temp[2]=TextSTART[i+2];
  
  sscanf(temp,"%x", &k);
  START[j]=k;
  j++;
}
}

if (TextAUTOF != NULL)
{

bzero(AUTOF,sizeof(AUTOF));
j=0;

for (i=0; i<(int)strlen(TextAUTOF); i=i+3)
{
 
  bzero(temp, sizeof(temp));
  bzero(temp1,sizeof(temp1));  

  temp[0]=TextAUTOF[i]; temp[1]=TextAUTOF[i+1]; temp[2]=TextAUTOF[i+2];
  
  sscanf(temp,"%x", &k);
  AUTOF[j]=k;
  j++;
}
}

};



void
RMGMO::ponPendientesEE(int gnota,int gcanal,long time)
{

int k=0;
int i;

while ((POEE[k].estado==1) && (POEE[k].delta <= time))
{
  k++;
}

for (i=PendientesEE; i>=k; i--)  POEE[i+1]=POEE[i];
POEE[k].estado=1;
POEE[k].nota=gnota;
POEE[k].canal=gcanal;
POEE[k].delta=time;
PendientesEE++;

};


void
RMGMO::ActuPenEE()

{

 int i;

bzero(POACEE, sizeof(POACEE));
PendientesEE = 0;
for (i=0; i<=78; i++)

{
  if (POEE[i].estado == 1)
  {

  POACEE[Pendientes]=POEE[i];
  PendientesEE++;
  }
}

bzero(POEE,sizeof(POEE));
for (i=0; i<PendientesEE; i++) POEE[i]=POACEE[i];

};


void
RMGMO::revertfromcopy()
{

  memcpy(&nStyle,&eStyle,sizeof(StyleStr));
  memcpy(&PEG,&ePEG,sizeof(PEG));
  
}

  



















 



