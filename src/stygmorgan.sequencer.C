/*
  stygmorgan - a ryhthm station software

  stygmorgan.sequencer.C  -  Most of the sequencer functions.
  Copyright (C) 2006 - 2019 Josep Andreu (Holborn)
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

#include "stygmorgan.h"


void

RMGMO::SeqPlay()
{

int lanota;
int ncanal;


if (nStyle.ppq == 0) return;
ttick = get_tick();
ptick = ttick - (longi * patrones) - rema;
negra=(( ptick/ nunegra ) % divisor) + 1;
semi=(ptick /  (nunegra / 4)) % (divisor * 4) + 1;
vcompas = (ptick / longic);
if (negra != vnegra)
{
vnegra=negra;
nic=1;
if (vnegra==1)
{
 scompas++;
 if (scompas > 1) cas++;
 MiraFin();
 cas=mirasaltos(cas);
 MiraCosas();
 ptick = ttick - (longi * patrones) - rema;
 sic=1;

}
if ((anti) && ((vnegra==1) || (vnegra==3)))
{
 anti=0;
 posanti=0;
}
if ((vnegra==2) || (vnegra==4)) MiraAnti(vnegra);
MiraAcorde(0,vnegra);
if (SongF.MasterT) UsaTempoTrack();
}

if ( ptick >= longi)
    {
      patrones++;
      cs=0;
      ptick=0;
    }

if (jack) PonNotesOffOrgan(0,ttick);


while (PEG[Variacion][cs].tipo==0) cs++;



        while ((PEG[Variacion][cs].tick <= ptick) && (cs < nStyle.Pattern[Variacion].eventos))
         {
          if ((anti !=0 ) && (PEG[Variacion][cs].tick >= posanti)) CheckAnti();


            if (pc[PEG[Variacion][cs].canal])
               {

                ncanal = pcp[PEG[Variacion][cs].canal];

                if (PEG[Variacion][cs].tipo==2)
                {
                lanota=miranota(PEG[Variacion][cs].nota,PEG[Variacion][cs].canal);
                }
                else lanota=PEG[Variacion][cs].nota;

                PonPlay(PEG[Variacion][cs].tipo, PEG[Variacion][cs].tick, lanota,ncanal,PEG[Variacion][cs].velocity,PEG[Variacion][cs].length);

                }
            cs++;

          }





};



void
RMGMO::PonPatron(int vari)
{
buscacs(vari);
Variacion=vari;
mirapc(Variacion);
//if ( ptick > 0 ) rema=0;
cs=0;
ptick = 0;
BuscaSi();
ponmixpatternenmix(Variacion);
sponmix=1;
}


void
RMGMO::MiraAcorde(int mcas,int pos)
{
int i;
int ncas;
int HayBass=0;
char prefundi[8];
char resto[20];
char sufijo[16];
char sufbass[4];

bzero(NombreAcorde,sizeof(NombreAcorde));

if (mcas==0) ncas = cas; else ncas = mcas;


 switch(pos)
  {
    case 1:
    strcpy(NombreAcorde,S[ncas].ch1);
    break;
    case 2:
    strcpy(NombreAcorde,S[ncas].ch2);
    break;
    case 3:
    strcpy(NombreAcorde,S[ncas].ch3);
    break;
    case 4:
    strcpy(NombreAcorde,S[ncas].ch4);

  }


if (strlen(NombreAcorde)==0) return;

bzero(prefundi,sizeof(prefundi));
bzero(sufijo,sizeof(sufijo));
bzero(sufbass,sizeof(sufbass));
bzero(resto,sizeof(resto));

if (( NombreAcorde[1] == 'b')  || (NombreAcorde[1] == '#'))
        {
           for (i=0; i<=1; i++) prefundi[i] = NombreAcorde[i];
           for (i=2; i<=(int) strlen(NombreAcorde); i++) resto[i-2]=NombreAcorde[i];
        }
         else
        {
          prefundi[0] = NombreAcorde[0];
          for(i=1; i<=(int) strlen(NombreAcorde); i++) resto[i-1]=NombreAcorde[i];
        }

for (i=0; i<=23; i++)
{
  if (strcmp(NCE[i].Nom,prefundi) == 0)
       {
          fundi = i % 12;
          break;
       }
}




if (resto[strlen(resto)-2]=='/')
 {
   HayBass=1;
   for (i=0; i<(int) strlen(resto)-2; i++) sufijo[i]=resto[i];
   sufbass[0]=resto[strlen(resto)-1];
   sufbass[1]=resto[strlen(resto)];
 }

if (resto[strlen(resto)-3]=='/')
 { 

   HayBass=1;
   for (i=0; i<(int) strlen(resto)-3; i++) sufijo[i]=resto[i];
   sufbass[0]=resto[strlen(resto)-2];
   sufbass[1]=resto[strlen(resto)-1];
   sufbass[2]=resto[strlen(resto)];
 } 


if ( HayBass==0) strcpy(sufijo,resto);


for (int i=0; i<=33; i++)
     {
      if (strcmp(ChN[i].Nom,sufijo) == 0)
          {
            ctipo=ChN[i].tipo;
            mt=ChN[i].mt;
            break;
          }
     }


if (HayBass==1)
 {
   for (int i=0; i<=23; i++)
      {
         if (strcmp(NCE[i].Nom,sufbass) == 0)
             {
                bass= i % 12;
                break;
             }
      }

 }


if (HayBass==0) bass=fundi;

BuscaSi();

cc1=1;

};

    
void
RMGMO::MiraCosas()
{

if ((S[cas].style !=0) && (S[cas].style != Estilo))

{
  Estilo = S[cas].style;
  readstyle(Estilo);
  set_tempo();
  if(jack)pontempoenjack();
  PonPatron(S[cas].pattern);
  CNStyle=1;
  CNPattern=1;
}



if ((S[cas].pattern != 0 ) && (S[cas].pattern !=Variacion))
{
PonPatron(S[cas].pattern);
CNPattern=1;
}


};



void
RMGMO::BuscaRepes()
{

int i;

for (i=1; i<=128; i++)
{

  if (S[i].times != 0) Repe[i].times = S[i].times; else Repe[i].times = 0;
  if (S[i].atimes !=0) Salta[i].times = S[i].atimes; else Salta[i].times = 0;
  Salta[i].pasa = 0;
}

};

int
RMGMO::mirasaltos(int nb)
{

char elchardm;

                if (strlen(S[nb].go_to) != 0)
                        {
                elchardm = S[nb].go_to[0];
                if (elchardm > 90) elchardm -= 32; 
			switch(elchardm)
				{
                                case 'A':
                                if (Repe[nb].times > 0) 
                                {
                                Repe[nb].times--;
                                nb = BuscaM(1);
                                }
                                break;
       				case 'B':
                                if (Repe[nb].times > 0) 
                                {
                                Repe[nb].times--;
                                nb = BuscaM(2);
       				}
                                break;
       				case 'C':
                                if (Repe[nb].times > 0)
                                {
                                Repe[nb].times--;
       				nb = BuscaM(3);
                                }
       				break;
       				case 'D':
                                if (Repe[nb].times > 0)
                                {
                                Repe[nb].times--;
       				nb = BuscaM(4);
                                }
       				break;
                                case 'E':
                                if (Repe[nb].times > 0) 
                                {
                                Repe[nb].times--;
                                nb = BuscaM(5);
                                }
       				break;
       				case 'F':
                                if (Repe[nb].times > 0) 
                                {
                                Repe[nb].times--;
                                nb = BuscaM(6);
       				}
                                break;
                                }
                          if (Repe[nb].times == 0) Repe[nb].times = S[nb].times;	
                           }
			
                   if (strlen(S[nb].go_af) != 0)
                        {
                     elchardm = S[nb].go_af[0];
                     if (elchardm > 90) elchardm -= 32;
			switch(elchardm)
		           {
                                case 'A':
                                if (Salta[nb].times > 0) 
                                {
                                Salta[nb].pasa++;
                                if (Salta[nb].pasa == Salta[nb].times) 
                                {
                                nb = BuscaM(1);
                                Salta[nb].pasa = 0;
                                }
                                }
              			break;
       				case 'B':
                                if (Salta[nb].times > 0) 
                                {
                                Salta[nb].pasa++;
                                if (Salta[nb].pasa == Salta[nb].times)
                                {
                                nb = BuscaM(2);
                                Salta[nb].pasa = 0;
                                }
       				}
                                break;
       				case 'C':
                                if (Salta[nb].times > 0)
                                {
                                Salta[nb].pasa++;
                                if (Salta[nb].pasa == Salta[nb].times)
                                {
       				nb = BuscaM(3);
                                Salta[nb].pasa = 0;
                                }
                                }
       				break;
       				case 'D':
                                if (Salta[nb].times > 0)
                                {
                                Salta[nb].pasa++;
                                if (Salta[nb].pasa == Salta[nb].times)
                                {
       				nb = BuscaM(4);
                                Salta[nb].pasa = 0;
                                }
                                }
       				break;
                                case 'E':
                                if (Salta[nb].times > 0) 
                                {
                                Salta[nb].pasa++;
                                if (Salta[nb].pasa == Salta[nb].times)
                                {
                                nb = BuscaM(5);
                                Salta[nb].pasa = 0;
                                }
                                }
       				break;
       				case 'F':
                                if (Salta[nb].times > 0) 
                                   {
                                     Salta[nb].pasa++;
                                     if (Salta[nb].pasa == Salta[nb].times)
                                        {
                                           nb = BuscaM(6);
                                           Salta[nb].pasa = 0;
                                        }
       				    }
                              }
                          }

return(nb);

};



int
RMGMO::BuscaM(int i) {

int k=0;

 while(k<=128)

  {
   k++;
   if ((i==1) && (S[k].a == 1)) return(k);
   if ((i==2) && (S[k].b == 1)) return(k);
   if ((i==3) && (S[k].c == 1)) return(k);
   if ((i==4) && (S[k].d == 1)) return(k);
   if ((i==5) && (S[k].e == 1)) return(k);
   if ((i==6) && (S[k].f == 1)) return(k);

  }
   return(cas);

};



void
RMGMO::MiraAnti(int vn)
{


if (vn==4)

{

  if (S[cas].ar8)
     {
       mirado=0;
       anti=nStyle.ppq/2;
       posanti=(vcompas * longic) + (3 * nStyle.ppq) + anti;
       return;
     }
  if (S[cas].ar16)
     {
       mirado=0;
       anti=nStyle.ppq/4;
       posanti=(vcompas * longic) + (3 * nStyle.ppq) + (anti*3);
       return;
     }
}

if (vn==2)

{

  if (S[cas].ar8a)
     { 
       mirado=0;
       anti=nStyle.ppq/2;
       posanti=(vcompas * longic) + nStyle.ppq + anti;
       return;
     }
  if (S[cas].ar16a)
     {
       mirado=0;
       anti=nStyle.ppq/4;
       posanti=(vcompas*longic) + nStyle.ppq + (anti*3);
       return;
     }
}


};

void
RMGMO::CheckAnti()
{

if (mirado==1) return;

int pos;
int mcas;

pos=vnegra+1;
mcas=cas;

if (pos>divisor) 
{
pos=1;
mcas +=1;
}

MiraAcorde(mcas,pos);
mirado=1;
}


void
RMGMO::MiraFin()
{

if (S[cas].fin)
{
 splay=0;
 finito=1;
}

};



void
RMGMO::UsaTempoTrack()
{

int i;

for (i=1; i<200; i++)
 {
   if (SongF.TemT[i].bar == 0) break;
   if ((SongF.TemT[i].bar == cas) && (SongF.TemT[i].black == vnegra))
       {
        bpm = SongF.TemT[i].tempo;
        set_tempo();
        if(jack)pontempoenjack();
        MTempo=bpm;
        break;
       }
 }
};

void
RMGMO::BorraTiempo(int i)
{

int j;

for(j=i; j<199; j++)

 {
   SongF.TemT[j].bar = SongF.TemT[j+1].bar;
   SongF.TemT[j].black = SongF.TemT[j+1].black;
   SongF.TemT[j].tempo = SongF.TemT[j+1].tempo;
 }

};

void
RMGMO::InsertaTiempo(int i)
{

int j;


for (j=198; j>=i; j--)
{
   SongF.TemT[j+1].bar = SongF.TemT[j].bar;
   SongF.TemT[j+1].black = SongF.TemT[j].black;
   SongF.TemT[j+1].tempo = SongF.TemT[j].tempo;
}
};


void
RMGMO::BuscaTempo()
{

int i;

for (i=1; i<200; i++)
{
   if (SongF.TemT[i].bar == 0) break;
   if (SongF.TemT[i].bar <= cas)
         {
           bpm = SongF.TemT[i].tempo;

         }
   if  (SongF.TemT[i].bar > cas) break;

}
};


int
RMGMO::CheckChord(char *chord)
{
int i;
int PasaNota=0;
int PasaAcorde=0;
int PasaBajo=0;
int HayBass=0;
char prefundi[8];
char resto[20];
char sufijo[16];
char sufbass[4];


if (strlen(chord) ==0) return(1);

bzero(prefundi,sizeof(prefundi));
bzero(sufijo,sizeof(sufijo));
bzero(sufbass,sizeof(sufbass));
bzero(resto,sizeof(resto));

if (( chord[1] == 'b')  || (chord[1] == '#'))
        {
           for (i=0; i<=1; i++) prefundi[i] = chord[i];
           for (i=2; i<=(int) strlen(chord); i++) resto[i-2]=chord[i];
        }
         else
        {
          prefundi[0] = chord[0];
          for(i=1; i<=(int) strlen(chord); i++) resto[i-1]=chord[i];
        }

for (i=0; i<=23; i++)
{
  if (strcmp(NCE[i].Nom,prefundi) == 0)
       {
          PasaNota=1;
          break;
       }
}




if (resto[strlen(resto)-2]=='/')
 {
   HayBass=1;
   for (i=0; i<(int) strlen(resto)-2; i++) sufijo[i]=resto[i];
   sufbass[0]=resto[strlen(resto)-1];
   sufbass[1]=resto[strlen(resto)];
 }

if (resto[strlen(resto)-3]=='/')
 {

   HayBass=1;
   for (i=0; i<(int) strlen(resto)-3; i++) sufijo[i]=resto[i];
   sufbass[0]=resto[strlen(resto)-2];
   sufbass[1]=resto[strlen(resto)-1];
   sufbass[2]=resto[strlen(resto)];
 }


if ( HayBass==0) strcpy(sufijo,resto); 


for (int i=0; i<=33; i++)
     {
      if (strcmp(ChN[i].Nom,sufijo) == 0)
          {
            PasaAcorde=1;
            break;
          }
     }


if (HayBass==1)
 {
   for (int i=0; i<=23; i++)
      {
         if (strcmp(NCE[i].Nom,sufbass) == 0)
             {
                PasaBajo=1;
                break;
             }
      }

 }



if ( HayBass)
{
if ((PasaNota) && (PasaAcorde) && (PasaBajo)) return(1); else return(2);
}


if ((PasaNota) && (PasaAcorde)) return(1);

return(2);

};



