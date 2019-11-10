/*
  stygmorgan - a ryhthm station software

    stygmorgan.fileio.C  -  Input/Output files
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


void
RMGMO::loadpreset(char *filename)

{
strcpy(PresetFilename,filename);

  int i = 0, j = 0;
  for (i = 0; i <= 127; i++)
    {
      for (j = 0; j <= 127; j++)
        {
          PresetList[i].Banco = i;
          PresetList[i].PBanco[i].Prog = j;
        }
    }

  FILE *fp;
  char temp[256];
  int bb = 0, pp = 0;
  char nn[80];
  if ((fp = fopen (filename, "r")) != NULL)
    {

      bzero (temp, sizeof (temp));
      while (fgets (temp, sizeof temp, fp) != NULL)
        {
          sscanf (temp, "%d %d %[^]]c", &bb, &pp, (char*) nn);

            for (i = 0; i <=(int) strlen (temp); i++)
            PresetList[bb].PBanco[pp].ProgName[i] = nn[i];
        }
       fclose(fp);
    }

};



void
RMGMO::readsinglestyle(char *filename)
{

int i;
long tam;
FILE *fs;

  if ((fs = fopen (filename, "rb")) != NULL)
       {
        i = fread(&nStyle, sizeof(nStyle),1,fs);
        for(i=0; i<22; i++)
        {
         tam =(long) ( sizeof(tempEG) * nStyle.Pattern[i].eventos);
         fread(&PEG[i][0],tam,1,fs);
        }
        fclose(fs);
       }
PonAjusta();
}



void
RMGMO::savesinglestyle(char *filename)
{

int i;
long tam;
FILE *fs;

     if ((fs = fopen (filename, "ab")) != NULL)
        {
         fwrite(&nStyle, sizeof(nStyle),1,fs);
         for(i=0; i<22; i++)
                {
                 tam = (long)(sizeof(tempEG) * nStyle.Pattern[i].eventos);
                 fwrite(&PEG[i][0],tam,1,fs);
                }


         fclose(fs);
        }
}

void
RMGMO::readstyles(char *filename)
{
int i;
long tam;
FILE *fs;

 numstyles=0;
 strcpy(StylesFilename,filename);
// gg=0;

 if ((fs = fopen (filename, "rb")) != NULL)
     {
        while (!feof(fs))
            {
                i = fread(&nStyle, sizeof(nStyle),1,fs);
                if (feof(fs) == 0) procesaleido(); else break;
                for(i=0; i<22; i++)
                {
                 tam = (long)(sizeof(tempEG) * nStyle.Pattern[i].eventos);
                 fread(&PEG[i][0],tam,1,fs); 
                }
             }
             fclose(fs);
      }

};

void
RMGMO::savestyle()

{
int i;
long tam;
FILE *fs;
char filef[80];
char *filename;

 isnew=0;

 bzero(filef, sizeof(filef));
 filename = filef;
 strcpy(filename,StylesFilename);

     if ((fs = fopen (filename, "ab")) != NULL)
        {
         fwrite(&nStyle, sizeof(nStyle),1,fs);
         for(i=0; i<22; i++)
                {
                 tam = (long)(sizeof(tempEG) * nStyle.Pattern[i].eventos);
                 fwrite(&PEG[i][0],tam,1,fs);
                }
         fclose(fs);
        }

};


void
RMGMO::savesong(char *filename)

{
int i;
FILE *fs;

for (i=0; i<=128;i++)  SongF.S[i] = S[i];

     if ((fs = fopen (filename, "wb")) != NULL)
        {
         fwrite(&SongF, sizeof(SongF),1,fs);
         fclose(fs);
        }

};


void
RMGMO::readstyle(int estilo)
{
int i;
long tam;
int kk=0;
FILE *fs;
char filef[80];
char *filename;

 bzero(filef, sizeof(filef));
 filename = filef;
 strcpy(filename,StylesFilename);

  if ((fs = fopen (filename, "rb")) != NULL)
       {
               while (!feof(fs) && (kk < estilo))
                 {
                  i = fread(&nStyle, sizeof(nStyle),1,fs);
                 for(i=0; i<22; i++)
                     {
                       tam =(long) ( sizeof(tempEG) * nStyle.Pattern[i].eventos);
                       fread(&PEG[i][0],tam,1,fs);
                     }
                  kk++;
                 }
       fclose(fs);
       }
PonAjusta();

memcpy(&eStyle,&nStyle,sizeof(StyleStr));

memcpy(&ePEG,&PEG,sizeof(PEG));

};

void
RMGMO::writestyle(int estilo)
{

int i;
long tam;
int kk=0;
FILE *fs;
char filef[80];
char *filename;

 bzero(filef, sizeof(filef));
 filename = filef;
 strcpy(filename,StylesFilename);
 
 estilo--;

  if ((fs = fopen (filename, "r+b")) != NULL)
       {
               while ( (!feof(fs))  && (kk < estilo ) )
                 {
                  i = fread(&tStyle, sizeof(tStyle),1,fs);
                  for(i=0; i<22; i++)
                     {
                       tam = (long) (sizeof(tempEG) * tStyle.Pattern[i].eventos);
                       fread(&EG[0],tam,1,fs);
                     }

                  kk++; 
                 }

               fwrite(&nStyle, sizeof(nStyle),1,fs);
               for(i=0; i<22; i++)
                {
                 tam =(long) (sizeof(tempEG) * nStyle.Pattern[i].eventos);
                 fwrite(&PEG[i][0],tam,1,fs);
                }
       fclose(fs);
       }
 };





void
RMGMO::writestylec(int estilo,int funcion)
{

int i;
long tam;
int kk=0;
FILE *fs,*fn;
char tempfile[512];
char filef[512];
char *filename;

 bzero(tempfile,sizeof(tempfile));

 sprintf(tempfile,"%s/tempstygm",TempDir);

 bzero(filef, sizeof(filef));
 filename = filef;

 strcpy(filename,StylesFilename);

 estilo--;

  if ((fn = fopen (tempfile, "ab")) != NULL)
    { 
  if ((fs = fopen (filename, "rb")) != NULL)
       {
         while ( !feof(fs)) 
                {

                    if (kk != estilo)
                       {
                            i = fread(&tStyle, sizeof(tStyle),1,fs);
                            if (i==0) break;
                            i = fwrite(&tStyle, sizeof(tStyle),1,fn);
                            for(i=0; i<22; i++)
                                {
                                   tam = (long) (sizeof(tempEG) * tStyle.Pattern[i].eventos);
                                   fread(&EG[0],tam,1,fs);
                                   fwrite(&EG[0],tam,1,fn);
                                }


                        }
                    else
                       {
                             fread(&tStyle, sizeof(tStyle),1,fs);
                             if (funcion==0) fwrite(&nStyle, sizeof(nStyle),1,fn);
                             for(i=0; i<22; i++)
                                  {
                                   tam = (long) (sizeof(tempEG) * tStyle.Pattern[i].eventos);
                                   fread(&EG[0],tam,1,fs);
                                   if(funcion==0)
                                    {
                                      tam =(long) (sizeof(tempEG) * nStyle.Pattern[i].eventos);
                                      fwrite(&PEG[i][0],tam,1,fn);
                                    }
                                  }
                        }

                     kk++;

                 }


       EventoCambia=0;
       fclose(fn);
       fclose(fs);
       char temp[3512];
       bzero(temp,sizeof(temp));
       sprintf(temp,"mv %s %s.bak ; mv %s %s",StylesFilename,StylesFilename,tempfile,StylesFilename);
       system(temp);

       }
     }

 };


void
RMGMO::deletesound(int sound)
{

int i;
int kk=0;
FILE *fs,*fn;
char tempfile[512];
char filef[80];
char *filename;

 bzero(tempfile,sizeof(tempfile));

 sprintf(tempfile,"%s/tempstysnd",TempDir);

 bzero(filef, sizeof(filef));
 filename = filef;

 strcpy(filename,SoundsFilename);

sound--;

  if ((fn = fopen (tempfile, "ab")) != NULL)
    { 
  if ((fs = fopen (filename, "rb")) != NULL)
       {
         while ( !feof(fs)) 
                {

                    if (kk != sound)
                       {
                            i = fread(&tSound, sizeof(tSound),1,fs);
                            if (i==0) break;
                            i = fwrite(&tSound, sizeof(tSound),1,fn);
                        }
                    else
                       {
                             fread(&tSound, sizeof(tSound),1,fs);
                        }

                     kk++;

                 }


       fclose(fn);
       fclose(fs);
       char temp[3512];
       bzero(temp,sizeof(temp));
       sprintf(temp,"mv %s %s.bak ; mv %s %s",SoundsFilename,SoundsFilename,tempfile,SoundsFilename);
       system(temp);

       }
     }

 };




void
RMGMO::readsounds(char *filename)
{

FILE *fs;

 numsounds=0;
 strcpy(SoundsFilename,filename); 


 if ((fs = fopen (filename, "rb")) != NULL)
     {
        while (!feof(fs))
            {
                fread(&nSound, sizeof(nSound),1,fs);
                if (feof(fs) == 0) procesasoleido(); else break;

            }
             fclose(fs);
      }

};


void
RMGMO::savesound()

{

FILE *fs;
char filef[80];
char *filename;

 bzero(filef, sizeof(filef));
 filename = filef;

 strcpy(filename,SoundsFilename);


     if ((fs = fopen (filename, "ab")) != NULL)
        {
         fwrite(&nSound, sizeof(nSound),1,fs);
         fclose(fs);
        }


};


void
RMGMO::readsound(int sound)
{


int kk=0;
FILE *fs;
char filef[80];
char *filename;

 bzero(filef, sizeof(filef));
 filename = filef;

 strcpy(filename,SoundsFilename);


  if ((fs = fopen (filename, "rb")) != NULL)
       {
               while (!feof(fs) && (kk < sound))
                 {
                  fread(&nSound, sizeof(nSound),1,fs);
                  kk++; 
                 }

       fclose(fs);
       }

 };


void
RMGMO::loadsong(char *filename)
{

FILE *fs;


  if ((fs = fopen (filename, "rb")) != NULL)
       {
               while (!feof(fs))
                 {
                  fread(&SongF, sizeof(SongF),1,fs);

                 }

       fclose(fs);

   for(int i=0;i<=128;i++)  S[i] = SongF.S[i];

       }

 };


void
RMGMO::writesound(int sound)
{


int kk=0;
FILE *fs;
char filef[80];
char *filename;

 bzero(filef, sizeof(filef));
 filename = filef;

 strcpy(filename,SoundsFilename);
 sound--;

  if ((fs = fopen (filename, "r+b")) != NULL)
       {
               while ( (!feof(fs))  && (kk < sound ) )
                 {
                  fread(&tSound, sizeof(tSound),1,fs);
                  kk++; 
                 }

               fwrite(&nSound, sizeof(nSound),1,fs);

       fclose(fs);
       }
 };




void
RMGMO::loaddrumset(char *filename)
{

strcpy(DrumSetFilename,filename);

int  i = 0, j = 0, bb = 0 , pp = 0;
FILE *fp;
char temp[256];
char nn[80];


  for (i = 0; i <= 59; i++)
    {
      for (j = 27; j <= 88; j++)
        {
          PD[i].ProgD = i;
          PD[i].DNN[i].Note  = j;
        }
    }
  bb = 0;
  pp = 0;
  bzero (nn, sizeof(nn));

  if ((fp = fopen (filename, "r")) != NULL)
    {

      bzero (temp, sizeof (temp));
      while (fgets (temp, sizeof temp, fp) != NULL)
        {
          sscanf (temp, "%d %d %[^]]c", &bb, &pp, (char*) nn);

            for (i = 0; i <= (int)strlen (temp); i++)
            PD[bb].DNN[pp].Nom[i] = nn[i];

        }
    }

};

void
RMGMO::readregistrations(char *filename)
{


FILE *fs;

 numregis=0;
 strcpy(RegisFilename,filename); 

 if ((fs = fopen (filename, "rb")) != NULL)
     {
        while (!feof(fs))
            {
                fread(&R, sizeof(R),1,fs);
                if (feof(fs) == 0) procesaregleido(); else break;
            }
             fclose(fs);
      }

};


void
RMGMO::saveregistration()
{

FILE *fs;
char filef[80];
char *filename;

 bzero(filef, sizeof(filef));
 filename = filef;

 strcpy(filename,RegisFilename);


     if ((fs = fopen (filename, "ab")) != NULL)
        {
         fwrite(&R, sizeof(R),1,fs);

         fclose(fs);
        }
};


void
RMGMO::readregistration(int regis)
{

int kk=0;
FILE *fs;
char filef[80];
char *filename;

 bzero(filef, sizeof(filef));
 filename = filef;

 strcpy(filename,RegisFilename);


  if ((fs = fopen (filename, "rb")) != NULL)
       {
               while (!feof(fs) && (kk < regis))
                 {
                  fread(&R, sizeof(R),1,fs);
                  kk++; 
                 }

       fclose(fs);
       }
 };


void
RMGMO::writeregistration(int regis)
{

int kk=0;
FILE *fs;
char filef[80];
char *filename;

 bzero(filef, sizeof(filef));
 filename = filef;

 strcpy(filename,RegisFilename);
 regis--;

  if ((fs = fopen (filename, "r+b")) != NULL)
       {
               while ( (!feof(fs))  && (kk < regis ) )
                 {
                  fread(&Rtemp, sizeof(Rtemp),1,fs);
                  kk++; 
                 }

               fwrite(&R, sizeof(R),1,fs);  

       fclose(fs);
       }

 };


void
RMGMO::deleteregistration(int regis)
{
int i;
int kk=0;
FILE *fs,*fn;
char tempfile[512];
char filef[80];
char *filename;

 bzero(tempfile,sizeof(tempfile));
 sprintf(tempfile,"%s/tempstyreg",TempDir);
 bzero(filef, sizeof(filef));
 filename = filef;
 strcpy(filename,RegisFilename);
 regis--;
  if ((fn = fopen (tempfile, "ab")) != NULL)
    { 
  if ((fs = fopen (filename, "rb")) != NULL)
       {
         while ( !feof(fs)) 
                {

                    if (kk != regis)
                       {
                            i = fread(&Rtemp, sizeof(Rtemp),1,fs);
                            if (i==0) break;
                            i = fwrite(&Rtemp, sizeof(Rtemp),1,fn);
                        }
                    else
                       {
                             fread(&Rtemp, sizeof(Rtemp),1,fs);
                        }

                     kk++;

                 }
       fclose(fn);
       fclose(fs);
       char temp[3256];
       bzero(temp,sizeof(temp));
       sprintf(temp,"mv %s %s.bak ; mv %s %s",RegisFilename,RegisFilename,tempfile,RegisFilename);
       system(temp);
       }
     }
 };
 
 

