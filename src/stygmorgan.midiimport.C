/*
  stymorgan - a ryhthm station software

  stygmorgan.midiimport.C  -  MIDI Import functions.
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
#include <FL/filename.H>

int 
RMGMO::ImportaMidi(char *filename)
{

// Open Midi File 

  FILE *fs;
  int Nutrak, MNtracks, MTiempoBase,MFormato;
  int TrackLen, dato, nota, velo;
  int DeltaMayor=0;
  int TTdelta = 0;
  int Tdelta = 0;
  int tipo, canal;
  int i,j;
  int ya=0;
  int numpa = 0;
  char chtemp[32];
  cMidiRead = 0;
  grabaconta=0;
  memset(&nStyle, 0, sizeof nStyle);
  memset(PEG,0, sizeof PEG);

  if ((fs = fopen (filename, "rb")) != NULL)
   {

     strcpy(nStyle.Name,fl_filename_name(filename));


// Check if is Midi File

  if (MAGIC_FILE != leer_bytes(fs, 4))

     { 
       fclose(fs);
       printf("Sorry %s not seems a midi file\n",filename);
       return(1);
     }


  if ( leer_bytes(fs,4) != 6)

      {
       fclose(fs);
       printf("Sorry %s not seems a midi file\n",filename);
       return(1);
     }



// Check if is Midi File type 1


MFormato= leer_bytes(fs,2);


MNtracks = leer_bytes(fs,2);
MTiempoBase = leer_bytes(fs,2);


nStyle.ppq=MTiempoBase;
nStyle.har=0;
nStyle.bpm=120;
nStyle.nominador=4;
nStyle.denominator=2;
// Search track importable


for (Nutrak = 1; Nutrak <= MNtracks; Nutrak++)

{

//Read track Header


             if (MAGIC_TRACK != leer_bytes(fs, 4))
             {
             printf("Track %d Track Head ?\n",Nutrak);
             }

TrackLen = leer_bytes(fs,4);

// import data

if ( TTdelta > DeltaMayor) DeltaMayor=TTdelta;

tipo= 0;
canal = 0;
cMidiRead = 0;
longi = 0;
TTdelta = 0;
Tdelta = 0;
LaUltima = 0;

while (cMidiRead < TrackLen)
         {
          Tdelta = leer_delta(fs);
          TTdelta += Tdelta;
          dato = leer_bytes(fs,1);
          if ((dato & 0x80) == 0 )
          {
              ungetc(dato,fs);
              cMidiRead--;
          }
          else
          {
          tipo = dato & 0xf0;
          canal = dato & 0x0f;
          }

          switch(tipo)
           {

            case MIDI_CMD_NOTE_ON:

              		nota = leer_bytes(fs,1);
          		velo = leer_bytes(fs,1);
          	        PonGraba(2,TTdelta,nota,canal,velo);
                        break;

            case MIDI_CMD_NOTE_OFF:
                        nota = leer_bytes(fs,1);
                        velo = leer_bytes(fs,1);
                        PonGraba(2,TTdelta,nota,canal,0);
                        break;


            case MIDI_CMD_NOTE_PRESSURE:
                        nota = leer_bytes(fs,1);
                        velo = leer_bytes(fs,1);
                        PonGraba(2,TTdelta,nota,canal,velo);
                        break;

            case MIDI_CMD_CONTROL:
                        nota = leer_bytes(fs,1);
                        velo = leer_bytes(fs,1);
                        PonGraba(3,TTdelta,nota,canal,velo);
                        break;

            case MIDI_CMD_PGM_CHANGE:
                        nota = leer_bytes(fs,1);
                        PonGraba(4,TTdelta,nota,canal,0);
                        break;

            case MIDI_CMD_CHANNEL_PRESSURE:
                        nota = leer_bytes(fs,1);
                        break;

            case MIDI_CMD_BENDER:
                        nota = leer_bytes(fs, 1);
                        nota |= leer_bytes(fs, 1) << 7;
                        nota -= 0x2000;
                        PonGraba(5,TTdelta,nota,canal,0);
                        break;

            case MIDI_CMD_COMMON_SYSEX:
                        if (canal == 0x0f)
                         {
                           int tipo = leer_bytes(fs, 1);

                           if (tipo == 0x2f)
                            {
                              while (cMidiRead < TrackLen)
                                   leer_bytes(fs,1);
                              break;
                             }


                            if (tipo == 0x58)
                             {
                              velo = leer_delta(fs);
                              nStyle.nominador=leer_bytes(fs,1);
                              nStyle.denominator=leer_bytes(fs,1);
                              nStyle.cpq = leer_bytes(fs,1);
                              leer_bytes(fs,1);
                              PonAjusta();
                              break;
                             }

                           if (tipo == 0x51)
                             {
                              velo = leer_delta(fs);
                              nStyle.bpm = (int)( 6e7 / leer_bytes(fs,3));
                              bpm=nStyle.bpm;
                              if ((nStyle.bpm < 40 ) || (nStyle.bpm > 300))
                              {                            
                              nStyle.bpm=100;
                              bpm=100;
                              }
                              break; 
                             }

                           if (tipo == 0x06)
                           {
                             velo = leer_delta(fs);
                             bzero(chtemp,sizeof(chtemp));
                             for (i=0; i<velo; i++) chtemp[i] = leer_bytes(fs,1);
                             char *pepa = chtemp;
                             if (strcmp (pepa , "SInt") == 0) ya=1;
                             if (ya)
                             { 
                             strcpy(nStyle.Pattern[numpa].Name,chtemp);
                             nStyle.Pattern[numpa].start= TTdelta;
                             if (numpa > 0 )
                             {
                             nStyle.Pattern[numpa-1].stop = TTdelta;
                             nStyle.Pattern[numpa-1].bars = (nStyle.Pattern[numpa-1].stop - nStyle.Pattern[numpa-1].start) / (nStyle.ppq * nStyle.nominador / ajusta);
                             }
                            numpa++;
                             }
                            break;
                            }

                          }

                        velo = leer_delta(fs);
                        nota = leer_bytes(fs,velo);
                        break;


            }


}
}

int ajusta=1;
switch(nStyle.denominator)
{
 case 2:
    ajusta=1;
    break;
 case 3:
    ajusta=2;
    break;
 case 4:
    ajusta=4;
}

if (numpa > 0)
{
	nStyle.Pattern[numpa-1].stop = TTdelta;
	nStyle.Pattern[numpa-1].bars = (nStyle.Pattern[numpa-1].stop - nStyle.Pattern[numpa-1].start)/ (nStyle.ppq*nStyle.nominador / ajusta);

}

else
{
	numpa = 1;
	nStyle.Pattern[numpa].start=0;
	strcpy(nStyle.Pattern[numpa].Name,"All");
	nStyle.Pattern[numpa].stop = DeltaMayor;
	nStyle.Pattern[numpa].bars = DeltaMayor / (nStyle.ppq*nStyle.nominador / ajusta);
	nStyle.Pattern[0].bars=0;
	nStyle.Pattern[0].start=0;
	nStyle.Pattern[0].stop =0;

}


nStyle.numpat=numpa;


// leer CASM

i=0;

while( i == 0  )

    {
    i=leer_bytes(fs,1);

    }
  ungetc(i,fs);

  if (CASM  != leer_bytes(fs ,4))

{

	printf("No CASM section found, thst's really bad\n");

	memset (&C ,0 ,sizeof C);

	for (i=0; i<=numpa; i++)
	{
		for (j=0; j<=15; j++)
		{
			C.track=j;
			sprintf(C.Name,"Track %d",j); 
			C.Canal=j;
			if (j<6) C.Canal=10+j;
			if ((j>5) && (j<9)) C.Canal=j+4;
			C.ReadOnly=1;
			C.NoteMute1=0x0f;
			C.NoteMute0=0xff;
			C.ChMute4=0x03;
			C.ChMute3=0xff;
			C.ChMute2=0xff;
			C.ChMute1=0xff;
			C.ChMute0=0xff;
			C.ChRoot=0;
			C.ChType=2;
			C.NTR=1;
			if (j==9) C.NTT=0; else C.NTT=2;
			C.HKey=7;
			C.LLim=0;
			C.HLim=0x7f;
			C.RTR=1;
			memset(C.u, 0 ,sizeof C.u);
			C.ChM = 0;
			C.ChM <<= 8; C.ChM |= C.ChMute4;
			C.ChM <<= 8; C.ChM |= C.ChMute3;
			C.ChM <<= 8; C.ChM |= C.ChMute2;
			C.ChM <<= 8; C.ChM |= C.ChMute1;
			C.ChM <<= 8; C.ChM |= C.ChMute0;
			nStyle.Pattern[i].casm[j] = C;
			nStyle.Pattern[i].numcasm=16;
		}
	}
	printf("I try to generate a CASM section\n");
}

else

{
	int dato=0;
	int sdecl=0;
	int ctabl=0;
	int cnttl=0;
	char temp[16000];
	char  temp2[16000];
	int ncomas=0;
	int cnumpat=0;
	int sigo=0;
	int k=0;
	//char *ptemp;
	memset (&C ,0 ,sizeof C);
	cMidiRead=0;
	leer_bytes(fs,4);


	while (sigo == 0 )
	{
      		dato = leer_bytes(fs,4);
 		switch (dato)

		 {
		        case CSEG:
		        leer_bytes(fs,4);
		        break;

		        case Sdec:
        		ncomas=0;
        		sdecl = leer_bytes(fs,4);
        		bzero(temp,sizeof(temp));
        		for(i=0; i<sdecl; i++) 
        		{
        			temp[i]=leer_bytes(fs,1);
        			if (temp[i] == 0x2c ) ncomas++;
        		}
                        break;
 
		        case Cntt:
        		cnttl=leer_bytes(fs,4);
        		leer_bytes(fs,cnttl);
		        break;
 
		        case Ctab:
		        ctabl = leer_bytes(fs,4);
        		C.track=leer_bytes(fs,1);
        		for(i=0; i<8; i++) C.Name[i]=leer_bytes(fs,1);
        		C.Canal=leer_bytes(fs,1);
        		C.ReadOnly=leer_bytes(fs,1);
        		C.NoteMute1=leer_bytes(fs,1);
        		C.NoteMute0=leer_bytes(fs,1);
        		C.ChMute4=leer_bytes(fs,1);
        		C.ChMute3=leer_bytes(fs,1);
        		C.ChMute2=leer_bytes(fs,1);
        		C.ChMute1=leer_bytes(fs,1);
        		C.ChMute0=leer_bytes(fs,1);
        		C.ChRoot=leer_bytes(fs,1);
        		C.ChType=leer_bytes(fs,1);
        		C.NTR=leer_bytes(fs,1);
        		C.NTT=leer_bytes(fs,1);
        		C.HKey=leer_bytes(fs,1);
        		C.LLim=leer_bytes(fs,1);
        		C.HLim=leer_bytes(fs,1);
        		C.RTR=leer_bytes(fs,1);
        		i=26;
        		while (i < ctabl)
        		{
        			C.u[i-26]=leer_bytes(fs,1);
        			i++;
        		} 
        		C.ChM = 0;
        		C.ChM <<= 8; C.ChM |= C.ChMute4;
        		C.ChM <<= 8; C.ChM |= C.ChMute3;
        		C.ChM <<= 8; C.ChM |= C.ChMute2;
        		C.ChM <<= 8; C.ChM |= C.ChMute1;
        		C.ChM <<= 8; C.ChM |= C.ChMute0;

		        // Aqui poner los Tabs a sitio


		        k=0;
        		strcpy(temp2,temp);
        		//ptemp= temp2;
        		cnumpat = bpn(strtok(temp2,","));
        		nStyle.Pattern[cnumpat].casm[nStyle.Pattern[cnumpat].numcasm] = C;
        		nStyle.Pattern[cnumpat].numcasm++;
		        while (k < ncomas)
        		{
        			cnumpat = bpn(strtok(NULL,","));
        			nStyle.Pattern[cnumpat].casm[nStyle.Pattern[cnumpat].numcasm] = C;
        			nStyle.Pattern[cnumpat].numcasm++;
        			k++;
        		}
		        break;
		        default:
        		sigo=1;
		}
	}
}




fclose(fs);

//Ordena

if (MFormato==1)
{
	printf("Rearranging Pattern\n");
	for (i=1; i<grabaconta; i++)
  	{
  		for (j=0; j<grabaconta -1; j++)
     		{

			if (EG[j].tick > EG[j+1].tick) 
			{
				tempEG = EG[j];
                 		EG[j] = EG[j+1];
                 		EG[j+1] = tempEG;
		 	}

		}
	}

}



// Prepara mixer de patron


ponbasemix();

// Separa patrones


for(i=0; i<=numpa; i++)
        {

        unsigned int min=nStyle.Pattern[i].start;
        unsigned int max=nStyle.Pattern[i].stop;
        int jj = 0;


        for (j=0; j<grabaconta; j++)
                {

                if ((EG[j].tick >= min) && (EG[j].tick < max) && (jj<6000))

                      {
                      if ((EG[j].tick+EG[j].length) > max) EG[j].length=(max - EG[j].tick) -10;
                      PEG[i][jj] = EG[j];
                      PEG[i][jj].tick = PEG[i][jj].tick - min;
                      jj++;
                      }
                 }

          if (jj >= 6000) printf("Pattern %d is too large\n",i);
          nStyle.Pattern[i].eventos=jj;
          ponmixpattern(i);

         }


return(0);

}

else return(1);

};

int 
RMGMO::leer_bytes(FILE *fp, int n)
{
        int  valor;
        int  i;
        int  lectura;

        valor = 0;
        for (i = 0; i < n; i++) {
                valor <<= 8;
                lectura = getc(fp);
                cMidiRead++;
                if (lectura == -1)
                     {
                      //printf ("Unexpected end of file\n");

                     }
                valor |= lectura;
        }

        return valor;
};



unsigned long
RMGMO::leer_delta (FILE *fp)
{

        unsigned long valor;
        int c;

        if ((valor = getc(fp)) & 0x80) {
                valor &= 0x7f;
                do  {
                        valor = (valor << 7) + ((c = getc(fp)) & 0x7f);
                        cMidiRead++;
                }  while (c & 0x80);

        }
        cMidiRead++;
        return valor;


};





void 
RMGMO::PonGraba(int tipo, snd_seq_tick_time_t gtick, int gnota, int gcanal, int gvelocity)

{

int i;

grabaconta++;


if (grabaconta >= 64000) printf("Record Memory Full\n");
if (grabaconta < 64000)

{
  switch(tipo)
    {
     case 1:
     case 2:
        if (gvelocity != 0)
        {
        EG[grabaconta].tipo = tipo;
        EG[grabaconta].tick = gtick;
        EG[grabaconta].nota = gnota;
        EG[grabaconta].canal = gcanal;
        EG[grabaconta].velocity = gvelocity;
        EG[grabaconta].length = 0;
        }
        if (gvelocity == 0)
        {
        for (i=grabaconta; i>=1; i--)
            {
             if ((EG[i].tipo == tipo) && (EG[i].canal == gcanal) && (EG[i].nota == gnota))
                     {
                      EG[i].length = gtick - EG[i].tick;
                      grabaconta--;
                        break;
                     }
             }
         }
        break;

        case 3:
        EG[grabaconta].tipo = tipo;
        EG[grabaconta].tick = gtick;
        EG[grabaconta].canal = gcanal;
        EG[grabaconta].nota = gnota;
        EG[grabaconta].velocity = gvelocity;
        break;

        case 4:
        EG[grabaconta].tipo = tipo;
        EG[grabaconta].tick = gtick;
        EG[grabaconta].canal = gcanal;
        EG[grabaconta].nota = gnota;
        break;
        case 5:
        EG[grabaconta].tipo = tipo;
        EG[grabaconta].tick = gtick;
        EG[grabaconta].canal = gcanal;
        EG[grabaconta].nota = gnota;
        EG[grabaconta].velocity=gvelocity;
        break;



    }
}


};



void
RMGMO::ponmixpattern(int pattern)
{

int i,j,k;
int lito=0;

for (i=0; i<nStyle.Pattern[pattern].eventos; i++)

{
    lito=PEG[pattern][i].canal;

    if (pattern==0)
    {
    lito=PEG[pattern][i].canal;

         for(j=0;j<=nStyle.Pattern[1].numcasm; j++)
            {
              if (nStyle.Pattern[1].casm[j].track == lito)
                  {
                   lito=nStyle.Pattern[1].casm[j].Canal;
                   break;
                  }
             }
    }
    else
    {
    for(k=0; k<=nStyle.Pattern[pattern].numcasm; k++)
        {

           if (nStyle.Pattern[pattern].casm[k].track == PEG[pattern][i].canal)
           {
            lito=nStyle.Pattern[pattern].casm[k].Canal;
            break;
           }

        } 
    }

   if(strcmp(nStyle.Pattern[pattern].Name,"All") == 0)
   lito=nStyle.Pattern[pattern].casm[PEG[pattern][i].canal].Canal;

 if ((  PEG[pattern][i].tick < 5 ) || ( pattern == 0))
   {

  switch (PEG[pattern][i].tipo)

   {

    case 3:

           switch(PEG[pattern][i].nota)
             {
              case  7:
              PEG[pattern][i].tipo=10;
              if (pattern == 0)
              {
              for( j=1; j<nStyle.numpat; j++)
              nStyle.Pattern[j].CM[lito].vol = PEG[pattern][i].velocity;
              }
              else
              nStyle.Pattern[pattern].CM[lito].vol = PEG[pattern][i].velocity;

              break; 

              case 10:
              PEG[pattern][i].tipo=10;
              if (pattern == 0)
              {
              for( j=1; j<nStyle.numpat; j++) 
              nStyle.Pattern[j].CM[lito].pan = PEG[pattern][i].velocity;
              }
              else
              nStyle.Pattern[pattern].CM[lito].pan = PEG[pattern][i].velocity;
              break;

              case 91:
              PEG[pattern][i].tipo=10;
              if (pattern == 0)
              {
              for( j=1; j<nStyle.numpat; j++)
              nStyle.Pattern[j].CM[lito].reverb = PEG[pattern][i].velocity;
              }
              else
              nStyle.Pattern[pattern].CM[lito].reverb = PEG[pattern][i].velocity;
              break; 
 
              case 93:
              PEG[pattern][i].tipo=10;
              if (pattern == 0)
              {
              for( j=1; j<nStyle.numpat; j++)
              nStyle.Pattern[j].CM[lito].chorus = PEG[pattern][i].velocity;
              }
              else
              nStyle.Pattern[pattern].CM[lito].chorus = PEG[pattern][i].velocity; 

            }
         break;


   case 4:
               PEG[pattern][i].tipo=10;
               if (pattern == 0)
               {
               for( j=1; j<=nStyle.numpat; j++)
               nStyle.Pattern[j].CM[lito].program = PEG[pattern][i].nota;
               }
               else
               nStyle.Pattern[pattern].CM[lito].program = PEG[pattern][i].nota;
               break;

   }


 }



  }




};



void
RMGMO::ponbasemix()
{
int i,pista;

for (pista=1; pista<=nStyle.numpat;pista++)
{
for(i=9; i<16; i++)
 {

  nStyle.Pattern[pista].CM[i].OnOff=1;
  nStyle.Pattern[pista].CM[i].vol=100;
  nStyle.Pattern[pista].CM[i].pan=64;
  nStyle.Pattern[pista].CM[i].reverb=0;
  nStyle.Pattern[pista].CM[i].chorus=0;
  nStyle.Pattern[pista].CM[i].transpose=0;
  nStyle.Pattern[pista].CM[i].octave=0;
  nStyle.Pattern[pista].CM[i].ch=i;
  nStyle.Pattern[pista].CM[i].bMSB=0;
  nStyle.Pattern[pista].CM[i].bLSB=0;
  nStyle.Pattern[pista].CM[i].solo=0;
  nStyle.Pattern[pista].CM[i].more=0;
 }
  nStyle.Pattern[pista].CM[9].bMSB=1;
  nStyle.Pattern[pista].CM[9].bLSB=1;
}

};




