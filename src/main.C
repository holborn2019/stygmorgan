  /*
    stygmorgan - a ryhthm station software

    main.c  -  Main file of the organ
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


  #include <getopt.h>
  #include <sched.h>
  #include <sys/mman.h>
  #include "stygmorgan.h"
  #include "stygmorganui.h"
  #include "stygmaboutui.h"
  #include "stygmeditui.h"
  #include "stygmstui.h"
  #include "stygmprefui.h"
  #include "stygmppui.h"
  #include "stygmsequi.h"
  #include "stygmhelpui.h"
  #include "stygmdmui.h"
  #include "jack.h"


  RMGMO rmgmo;

  void pon_realtime()

  {
      sched_param scprior;
      scprior.sched_priority=11;
      int prior=sched_setscheduler(0,SCHED_FIFO,&scprior);
      if (prior==0) printf("SCHED_FIFO\n");
  };



  int main(int argc, char *argv[])

  {
    fprintf (stderr,"\n%s %s - Copyright (c) 2006-2019 Josep Andreu (Holborn)\n",PACKAGE,VERSION);
    if (argc == 1)
      fprintf (stderr, "Try 'stygmorgan --help' for command-line options.\n");


    struct option opts[] = {
      {"load",   1, NULL,'l'},
      {"sload",  1, NULL,'d'},
      {"rload",  1, NULL,'e'},
      {"ppreset",1, NULL,'p'},
      {"rpreset",1, NULL,'r'},
      {"alsa",   0, NULL,'a'}, 
      {"help",   0, NULL,'h'},
      {0, 0, 0, 0}
    };


  Pexitprogram = 0;
  alsa = 0;
  opterr = 0;
  int option_index = 0, opt, exitwithhelp = 0;

    while (1)
      {
        opt = getopt_long (argc, argv, "l:d:e:p:r:ah", opts, &option_index);
        char *optarguments = optarg;

        if (opt == -1)
          break;


        switch (opt)
          {
          case 'h':
            exitwithhelp = 1;
            break;

          case 'a':
            alsa=1;    
            jack = 0;
            break;               

          case 'l':
            if (optarguments != NULL)
              {
                rmgmo.readstyles(optarguments);
                break;
              }

          case 'd':
            if (optarguments != NULL)
              {
                rmgmo.readsounds(optarguments);
                break;
              }

          case 'p':
            if (optarguments != NULL)
              { 
                rmgmo.loadpreset(optarguments);
                break;
              }

          case 'r':
            if (optarguments != NULL)
              {
                rmgmo.loaddrumset(optarguments);
                break;
              }

          case 'e':
            if (optarguments != NULL)
              {
                rmgmo.readregistrations(optarguments);
                break;
              }

          };
      };

    if (exitwithhelp != 0)
      {

        fprintf (stderr, "\nUsage: rmgmorgan [OPTIONS]\n\n");

        fprintf (stderr, "\tProgram Options:\n");
        fprintf (stderr, "\t----------------\n\n");
        fprintf (stderr, "\t-h       --help          \t Display this command-help.\n");
        fprintf (stderr, "\t-l <File>, --load <File>   \t Read styles file.\n");
        fprintf (stderr, "\t-d <File>, --sload <File>  \t Read sounds file.\n");
        fprintf (stderr, "\t-e <File>, --rload <File>  \t Read registrations file.\n");
        fprintf (stderr, "\t-p <File>, --ppreset <File>\t Load preset program names.\n");
        fprintf (stderr, "\t-r <File>, --rpreset <File>\t Load preset drums note names.\n\n");
        fprintf (stderr, "\t-a        --alsa          \t  Just use ALSA\n"); 
        fprintf (stderr, "\tFLTK Options:\n");
        fprintf (stderr, "\t-------------\n\n");
        fprintf (stderr, "\t-bg2 color\n");
        fprintf (stderr, "\t-bg color\n");
        fprintf (stderr, "\t-di[splay] host:n.n\n");
        fprintf (stderr, "\t-dn[d]\n");
        fprintf (stderr, "\t-fg color\n");
        fprintf (stderr, "\t-g[eometry] WxH+X+Y\n");
        fprintf (stderr, "\t-i[conic]\n");
        fprintf (stderr, "\t-k[bd]\n");
        fprintf (stderr, "\t-na[me] classname\n");
        fprintf (stderr, "\t-nod[nd]\n");
        fprintf (stderr, "\t-nok[bd]\n");
        fprintf (stderr, "\t-not[ooltips]\n");
        fprintf (stderr, "\t-s[cheme] scheme\n");
        fprintf (stderr, "\t-ti[tle] windowtitle\n");
        fprintf (stderr, "\t-to[oltips]\n\n");

        return (0);
    }    

      pon_realtime();
      mlockall(MCL_CURRENT | MCL_FUTURE);

    
    if (alsa==0) 
    {
     JACKInit(&rmgmo);
     if(jack)JACKstart (&rmgmo, rmgmo.jackclient);
    }

    new stygmorgan(argc,argv,&rmgmo);
  
  
  
    while (Pexitprogram == 0)
      {
             Fl::wait();

             if (rmgmo.ventana !=0)
               { 
                   switch(rmgmo.ventana)
                     {
                       case 1:
                       new about;
                       break;

                       case 2:
                       new rmgmedit(&rmgmo);
                       break; 

                       case 3:
                       new rmgmpp(&rmgmo);
                       break;

                       case 4:
                       new rmgmstye(&rmgmo);
                       break;

                       case 5:
                       new rmgmpref(&rmgmo);
                       break;

                       case 6:
                       new sequencer(&rmgmo);
                       break;

                       case 7:
                       new stygmhelp;
                       break;
                       
                       case 8:
                       new Drummixer(&rmgmo);
                       break; 
                        
                     } 

                   rmgmo.ventana=0;
               }
      }

  if (jack) JACKfinish ();
     exit(0);

  }



