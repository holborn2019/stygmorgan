/*
  stygmorgan - a ryhthm station software

  stygmorgan.graphfunc.C  -  Some  ui parts
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
RMGMO::AyudaSolo(int mcanal)
{
int i;

for (i=0; i<=4; i++) 
   {
        solo[i]=CM[i].OnOff;
        CM[i].OnOff=0;
    }

 for (i=9; i<=15; i++)
   {
    solo[i]=CM[i].OnOff;
    CM[i].OnOff=0;
    }

   CM[mcanal].OnOff=1;

};

void 
RMGMO::AyudaQuitaSolo()
{
int i;

for (i=0; i<=4; i++) 
   {
        CM[i].OnOff=solo[i];
    }
for (i=9; i<=15; i++) 
   {
       CM[i].OnOff=solo[i];
   }
};


void
RMGMO::BuscaNext()
{

int i;

for(i=1; i<=4; i++)
{
  if (sbot[i])
      {
      siguiente=tvb[i];
      break;
      }
}

for(i=12; i<=14; i++)
     { 
      if (sbot[i])
           {
            siguiente=0;
            break;
           }
      }
};

int
RMGMO::ChecaExporta()
{
  int i;
  int hayend=0;
  int hayestile=0;
  
  for (i=1; i<=128; i++)
   {
      if (S[i].fin) 
        {
         hayend=1;
        } 
      if (S[i].style !=0)
        {
         hayestile=1;
        }
   }
   
  if (hayend==0) return(2);
  if (hayestile==0) return(3);
  
  return(0);
}


