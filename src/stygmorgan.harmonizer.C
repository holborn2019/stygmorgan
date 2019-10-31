/*
  stygmorgan - a ryhthm station software

  stygmorgan.harmonizer.C  -  Most of the functions of the organ
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


#include "stygmorgan.h"



int
RMGMO::miranota(int lanota, int canal)
{
int intervalo;
int notafinal;
int afundi;
int ptranspose;
int poctave;

if (pcp[canal]== 9) return(lanota); 
afundi=fundi;
lanota = lanota - chro[canal];
intervalo=lanota % 12;
if ((TipoRecChord==2) && (intervalo==0) && (pchar[canal])) afundi=bass;

if (genmidi)
{
 ptranspose = nStyle.Pattern[Variacion].CM[pcp[canal]].transpose;
 poctave = nStyle.Pattern[Variacion].CM[pcp[canal]].octave;
}
else
{
ptranspose = CM[pcp[canal]].transpose;
poctave = CM[pcp[canal]].octave;
}

if ( (pchar[canal]) && (sema) && (pcp[canal]==10))
{
sema=0;
lanota -=intervalo;
notafinal=lanota + NCE[afundi].note + ptranspose + transpose + (12
* poctave);
return(notafinal);

}

if (nttc[canal] != 0 ) lanota = lanota+TCh[tcr[canal]][ctipo][intervalo];


notafinal=lanota + NCE[afundi].note + ptranspose + transpose + (12
* poctave);

if ((pcp[canal]==10) && (notafinal< 23)) notafinal += 12;
if ((nttc[canal]==2) && (notafinal< 52)) notafinal += 12;

return(notafinal);

}



void
RMGMO::allio()
{
int i;

for (i=0;i<16; i++)
    {
     if (pclio[i])  
     {
     if (genmidi==0) silent(123,i,i);     
     if (genmidi==1) PonNotesOffChannel(i,ptick);   
     }      
    
     if (pcpon[i]) repon(i);
     }
};


void
RMGMO::repon(int track)
{
int ct=0;
int lanota=0;
int ncanal=0;
unsigned int largo=0;

if(!bplay) return;

while (PEG[Variacion][ct].tick < (espacio * 2))

{

if ((PEG[Variacion][ct].tipo == 2) && (PEG[Variacion][ct].canal == track))

   {
       ncanal=pcp[PEG[Variacion][ct].canal];
       lanota=miranota(PEG[Variacion][ct].nota,PEG[Variacion][ct].canal); 
       largo=buscalargo(track,cs); 



      if (largo > ( unsigned int) (nStyle.ppq / 4) )
      {
      if (genmidi==0) PonPlay(2, ptick, lanota,ncanal,PEG[Variacion][ct].velocity,largo);
      else 
      {
      if (cas >1)
      Ponlo(2,ptick,lanota,ncanal,PEG[Variacion][ct].velocity,largo);
      }
      }
   }

ct++;
}
};


int
RMGMO::buscalargo(int track,int ct)
{
int resu=0; 

 while ( PEG[Variacion][ct].tick<= (ptick + espacio ))
 {
   ct++;
   if ( ct >= nStyle.Pattern[Variacion].eventos)
   {
   return(longi - ptick);

   }
 }

 while( ct < nStyle.Pattern[Variacion].eventos)

 {
   if ((PEG[Variacion][ct].tipo==2) && (PEG[Variacion][ct].canal==track))
  {
    resu= PEG[Variacion][ct].tick - ptick;
    return(resu); 
  }
 ct++;
 }
resu=longi - ptick;
return(resu);

};



