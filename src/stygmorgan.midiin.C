/*
  stygmorgan - a ryhthm station software

  stygmorgan.midiin.C  -  MIDI In functions.
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
RMGMO::miramidi()
{
  snd_seq_event_t *midievent;


if (snd_seq_event_input_pending (midi_in, 1))
{
    do
    {
        midievent = NULL;
        snd_seq_event_input (midi_in, &midievent);
        midievents(midievent);
        snd_seq_ev_clear(midievent);
        snd_seq_free_event(midievent);
    }
    while (snd_seq_event_input_pending (midi_in, 0));
}



};



void
RMGMO::midievents (snd_seq_event_t *midievent)
{

  int i;

  if(midievent == NULL)  return;
  if(midievent->type == 42) return;

  if ((midievent->type == SND_SEQ_EVENT_NOTEON) || (midievent->type == SND_SEQ_EVENT_NOTEOFF))
    {
      int cmdnote = midievent->data.note.note;
      int cmdvelo = midievent->data.note.velocity;

      if (midievent->type == SND_SEQ_EVENT_NOTEOFF)  cmdvelo=0;


      if (cmdvelo != vum )
         { 
           vum=cmdvelo;
           ponvum=1;
         }

      if (cmdnote < split)
      {

          for (i=0; i<POLY; i++)
          {
              if ((midievent->type == SND_SEQ_EVENT_NOTEON) && (cmdvelo != 0))
                  {
                    if (note_active[i] ==0)  
                      {
                        note_active[i] = 1;
                        rnote[i] = cmdnote;
                        gate[i]=1;
                        break;
                      }
                  }
           
 
          if ((midievent->type == SND_SEQ_EVENT_NOTEON) && (cmdvelo == 0))
                {

                  if ((note_active[i]) && (rnote[i]==cmdnote))
                    {
                      note_active[i] = 0;
                      if (pedal == 0) gate[i]= 0;
                      break;
                     }

                }


          if (midievent->type == SND_SEQ_EVENT_NOTEOFF)
                {

                  if ((note_active[i]) && (rnote[i]==cmdnote)) 
                    {
                      note_active[i] = 0;
                      if (pedal == 0) gate[i]= 0;
                      break;
                    }

                }
          }

      if ((cmdvelo > 20) && (splay==0) && (genmidi==0))  MiraChord();


      if (CM[0].OnOff)
        {
          midievent->data.note.channel=0;
          midievent->data.note.note=cmdnote+12+(12*CM[0].octave)+CM[0].transpose+transpose;
          midievent->data.note.velocity=cmdvelo;
          sacadirecto(3,midievent);
         }
      if (CM[1].OnOff)
        {
          midievent->data.note.channel=1;
          midievent->data.note.note=cmdnote+12+(12*CM[1].octave)+CM[1].transpose+transpose;
          midievent->data.note.velocity=cmdvelo;
          sacadirecto(3,midievent);
        }

   }
   else
   {

      if (CM[2].OnOff)
        {
          midievent->data.note.channel=2;
          midievent->data.note.note=cmdnote+(12*CM[2].octave)+CM[2].transpose+transpose;
          midievent->data.note.velocity=cmdvelo;
          sacadirecto(3,midievent);

        }
      if (CM[3].OnOff)
        {
          midievent->data.note.channel=3;
          midievent->data.note.note=cmdnote+(12*CM[3].octave)+CM[3].transpose+transpose;
          midievent->data.note.velocity=cmdvelo;
          sacadirecto(3,midievent);
        }
      if (CM[4].OnOff)
        {
          midievent->data.note.channel=4;
          midievent->data.note.note=cmdnote+(12*CM[4].octave)+CM[4].transpose+transpose;
          midievent->data.note.velocity=cmdvelo;
          sacadirecto(3,midievent);      
        }
    }
  }

    if (midievent->type == SND_SEQ_EVENT_CHANPRESS)
   
       {
      
      if (CM[0].OnOff)
      {     
      midievent->data.control.channel = 0;
      sacadirecto(2,midievent);
      }
      if (CM[1].OnOff)
      {     
      midievent->data.control.channel = 1;
      sacadirecto(2,midievent);
      }
      if (CM[2].OnOff)
      { 
      midievent->data.control.channel = 2;
      sacadirecto(2,midievent);
      }
      if (CM[3].OnOff)
      {
      midievent->data.control.channel = 3;
      sacadirecto(2,midievent);
      }
      if (CM[4].OnOff)
      {
      midievent->data.control.channel = 4;
      sacadirecto(2,midievent);
      }

     };




  if  (midievent->type == SND_SEQ_EVENT_CONTROLLER)
    {


       if (midievent->data.control.param == 64)
        {
          if (midievent->data.control.value < 64)
            {
             pedal = 0;
             for (i=0; i<POLY; i++) gate[i]=0;
            }
          if (midievent->data.control.value > 63)
            pedal = 1;
        }
      sacadirecto(3,midievent);

      if (CM[2].OnOff)
      { 
      midievent->data.control.channel = 2;
      sacadirecto(3,midievent);
      }
      if (CM[3].OnOff)
      {
      midievent->data.control.channel = 3;
      sacadirecto(3,midievent);
      }
      if (CM[4].OnOff)
      {
      midievent->data.control.channel = 4;
      sacadirecto(3,midievent);
      }

     };

   if (midievent->type == SND_SEQ_EVENT_PITCHBEND)
   {

    if (CM[2].OnOff)
    {
    midievent->data.control.channel = 2;
      sacadirecto(3,midievent);
    }
    if (CM[3].OnOff)
    {
    midievent->data.control.channel = 3;
      sacadirecto(3,midievent);
    }
    if (CM[4].OnOff)
    {
    midievent->data.control.channel = 4;
      sacadirecto(3,midievent);
    }
    };


  if (midievent->type == SND_SEQ_EVENT_PGMCHANGE)

    {

      programa = midievent->data.control.value;
      if (pera==0)
      {
      if (programa==0)
      {
        if (sel) sel=0; else sel=1;
      }  
      cambioc=1;
      }
    }


if  ((usesysex) && (midievent->type == SND_SEQ_EVENT_SYSEX))
    {    

unsigned char *data = (unsigned char *) midievent->data.ext.ptr;


if ( strcmp((const char *)data,(const char *) START) == 0 ) pbStart=1;
if ( strcmp((const char *)data,(const char *) AUTOF) == 0 ) pbAutoF=1;


    }



 snd_seq_free_event(midievent);

};


void
RMGMO::jack_process_midievents(jack_midi_event_t *_jack_midi_event)
{

        int i;
        snd_seq_event_t midievent;
        snd_midi_event_t *dpunt;
        unsigned char adata[256];

            
        struct Midi_Event *ev = (struct Midi_Event *)_jack_midi_event;
        for(i=0;i<ev->len;i++) adata[i]=ev->data[i];
        snd_seq_ev_clear(&midievent);
        snd_midi_event_new((size_t)ev->len,&dpunt);
        snd_midi_event_encode(dpunt,adata,ev->len,&midievent);
        midievents(&midievent);

}

