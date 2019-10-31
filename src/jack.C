/*
  stygmorgan - a sty file GM player organ software

  jack.C  -   jack I/O
  Copyright (C) 2008-2019 Josep Andreu
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

#include <jack/jack.h>
#include <jack/midiport.h>
#include <jack/transport.h>
#include "jack.h"


RMGMO *JackOUT;

jack_client_t *jackclient;
void *dataout;
int jackprocess (jack_nframes_t nframes, void *arg);


void
JACKInit (RMGMO * rmgmo_)
{
if(alsa==0)
{
    JackOUT = rmgmo_;
   
    char temp[64];
    sprintf (temp, "stygmorgan");
    JackOUT->jackclient = jack_client_open (temp, JackOUT->options, &JackOUT->status, NULL);
 
    if (JackOUT->jackclient == NULL) {
        fprintf (stderr, "Cannot make a jack client, is jackd running?\n");
        jack = 0;
       }
    if(jack)
    {
    strcpy (JackOUT->jackcliname, jack_get_client_name (JackOUT->jackclient));
    JackOUT->J_SAMPLE_RATE = jack_get_sample_rate (JackOUT->jackclient);
    JackOUT->J_PERIOD = jack_get_buffer_size (JackOUT->jackclient);
    }
}
}

int
JACKstart (RMGMO * rmgmo_, jack_client_t * jackclient_)
{


    JackOUT = rmgmo_;
    jackclient = jackclient_;

    jack_set_sync_callback(jackclient, timebase, NULL);
    jack_set_process_callback (jackclient, jackprocess, 0);

    jack_on_shutdown (jackclient, jackshutdown, 0);


    JackOUT->jack_midi_in =
        jack_port_register(jackclient, "in", JACK_DEFAULT_MIDI_TYPE, JackPortIsInput, 0);

    JackOUT->jack_midi_out =
        jack_port_register(jackclient, "out", JACK_DEFAULT_MIDI_TYPE, JackPortIsOutput, 0);


    if (jack_activate (jackclient)) {
        fprintf (stderr, "Cannot activate jack client.\n");
        return (2);
    };


    return 3;

};



int
jackprocess (jack_nframes_t nframes, void *arg)
{

    int i,count;
    jack_midi_event_t midievent;
    jack_position_t pos;
    jack_transport_state_t astate;


     astate = jack_transport_query(jackclient, &pos);

     if(JackOUT->usejacktransport)
     {
     if( JackOUT->bpm != pos.beats_per_minute)
     {
      JackOUT->bpm = pos.beats_per_minute;
      JackOUT->CambiaTempo=1;
      JackOUT->set_tempo();
     } 
     }
  
     if ((astate == 1) && (JackOUT->bplay==0)) JackOUT->rtplay=1;
     if ((astate == 0) && (JackOUT->rtplay==3)) JackOUT->rtplay=2;



    float *data = (float *)jack_port_get_buffer(JackOUT->jack_midi_in, nframes);

    count = jack_midi_get_event_count(data);
    dataout = jack_port_get_buffer(JackOUT->jack_midi_out, nframes);
    jack_midi_clear_buffer(dataout);

 
     for (i = 0; i < count; i++) {
        jack_midi_event_get(&midievent, data, i);
        JackOUT->jack_process_midievents(&midievent);
    }


    if(JackOUT->ev_count > 0)
    {
    for (i=0; i<JackOUT->ev_count; i++) {
    jack_midi_event_write(dataout,JackOUT->Midi_event[i].time,JackOUT->Midi_event[i].data, JackOUT->Midi_event[i].len);
    }
    memset(JackOUT->adata,0,sizeof JackOUT->adata);    
    JackOUT->adatasize = 0;
    JackOUT->ev_count = 0;
    }

    return 0;
};


void
JACKfinish ()
{

    jack_client_close (jackclient);
    usleep (1000);
};



void
jackshutdown (void *arg)
{
 printf ("Jack Shut Down, sorry.\n");
};



int
timebase(jack_transport_state_t state, jack_position_t *pos, void *arg)
{

    return(1);

}





