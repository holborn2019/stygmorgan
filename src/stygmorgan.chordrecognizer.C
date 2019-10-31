
/*
  stygmorgan - a ryhthm station software

  stygmorgan.chordrecognizer.C  -  Most of the functions of the organ
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


void 

RMGMO::MiraChord()
{

int i,j;
int anote[POLY];
int nnotes=0;
char AName[20];
int temp;
int di1,di2,di3,di4;
//int tienebass=0;

for (i=0; i<POLY; i++) 
	{
	if (( note_active[i] == 1) && (rnote[i] < 60))
{
                anote[nnotes] = rnote[i];
 		nnotes++;
		}
	}



if ((nnotes < 3) || (nnotes > 5) ) return;


for (i=1; i<nnotes; i++)
        {
     for (j=0; j<nnotes -1; j++)
         {
     if (anote[j] > anote[j+1])
           {
             temp = anote[j];
              anote[j] = anote[j+1];
              anote[j+1] = temp;
           }
         }
        }



bass  = anote[0] % 12;

sigue:

if (nnotes == 3)
   {

	di1=anote[1] - anote[0];
	di2=anote[2] - anote[1];

	j =-1;

 	while(j<=NumChord3)

	{
	j++;
	if ((Chord3[j].di1 == di1) && (Chord3[j].di2 == di2))
		{ 

                        ctipo = Chord3[j].tipo; 
                        mt = Chord3[j].mt;
                        int elke = anote[Chord3[j].fund-1];
                        fundi = elke % 12;
                        sprintf(AName,"%s%s",NC[fundi].Nom,Chord3[j].Nom);

                        if ((TipoRecChord==2) && (bass!=fundi))
                        {

                        bzero(AName,sizeof(AName));
                        sprintf(AName,"%s%s/%s",NC[fundi].Nom,Chord3[j].Nom,NCE[bass+plus(fundi)].Nom);
                        }

                        if (strcmp(AName, NombreAcorde) != 0)
                        { 
                          strcpy(NombreAcorde,AName);
                          cc=1;
                          BuscaSi();
                          if ((syncstart) && (bplay==0)) ponstart=1;
		        }
                        return;
                }
        }

   }

if (nnotes == 4)
   {

        di1=anote[1] - anote[0];
        di2=anote[2] - anote[1];
        di3=anote[3] - anote[2];
        j =-1;

        while(j<=NumChord4)

        {
        j++;
        if ((Chord4[j].di1 == di1) && (Chord4[j].di2 == di2) && (Chord4[j].di3 == di3))
                {
                        ctipo = Chord4[j].tipo;
                        mt = Chord4[j].mt;
                        int elke = anote[Chord4[j].fund-1];
                        fundi = elke % 12;
                        sprintf(AName,"%s%s",NC[fundi].Nom,Chord4[j].Nom);
                        if ((TipoRecChord==2) && (bass!=fundi)) 
                        {
                        bzero(AName,sizeof(AName));
                        sprintf(AName,"%s%s/%s",NC[fundi].Nom,Chord4[j].Nom,NCE[bass+plus(fundi)].Nom);
                        }

                        if (strcmp(AName, NombreAcorde) != 0)
                          {
                            strcpy(NombreAcorde,AName);
                            cc=1;
                            BuscaSi();
                            if ((syncstart) && (bplay==0)) ponstart=1;
                          }
                        return;
                  }

        }



   }

if (nnotes == 5)
   {

        di1=anote[1] - anote[0];
        di2=anote[2] - anote[1];
        di3=anote[3] - anote[2];
        di4=anote[4] - anote[3];
        j =-1;

        while(j < NumChord5)

        {
        j++;
        if ((Chord5[j].di1 == di1) && (Chord5[j].di2 == di2) && (Chord5[j].di3 == di3) && (Chord5[j].di4 == di4))
                {

                        ctipo = Chord5[j].tipo;
                        mt = Chord5[j].mt;
                        int elke = anote[Chord5[j].fund-1];
                        fundi = elke % 12;
                        sprintf(AName,"%s%s",NC[fundi].Nom,Chord5[j].Nom);
                        if ((TipoRecChord==2) && (bass!=fundi))
                        {
                        bzero(AName,sizeof(AName));
                        sprintf(AName,"%s%s/%s",NC[fundi].Nom,Chord5[j].Nom,NCE[bass+plus(fundi)].Nom);
                        }

                       if (strcmp(AName, NombreAcorde) != 0)
                          {
                           strcpy(NombreAcorde,AName);
                           cc=1;
                           BuscaSi();
                           if ((syncstart) && (bplay==0)) ponstart=1;
                          }
                        return;

                  }

         }

    }



if (TipoRecChord==2)
{
if (nnotes==5)
{
// tienebass=1;
 bass=anote[0] % 12;

for(i=1; i<=4; i++) anote[i-1]=anote[i];
 nnotes=4;
 goto sigue; 
}
}


if (nnotes==5)
{
 nnotes=4;
 goto sigue;
}

if (nnotes==4)
{
 nnotes=3;
 goto sigue;
}



};



int
RMGMO::plus(int nota)
{
  switch(nota)
   {
    case 2:
    return(12);
    break;
    case 4:
    return(12);
    break;
    case 7:
    return(12);
    break;
    case 9:
    return(12);
    break;
    case 11:
    return(12);
    break;
    default:
    return(0);
   }

};


