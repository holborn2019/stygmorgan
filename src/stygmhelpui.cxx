// generated by Fast Light User Interface Designer (fluid) version 1.0304

#include <libintl.h>
#include "stygmhelpui.h"
//Copyright(c) 2006 Josep Andreu (holborn)
//License GNU/GPL version 2

stygmhelp::stygmhelp() {
  Fl::visual(FL_DOUBLE|FL_INDEX);
  Fl::visual(FL_RGB);
  
  static const char *pepe [] ={"stygmorgan"};
  char temp[128];
  int argc=1;
  char **argv= (char **) pepe;
  
  Fl_Help_Dialog *visor = new Fl_Help_Dialog;
  bzero(temp,sizeof(temp));
  sprintf(temp,"%s/html/stygmorgan.html",HELPDIR);
  visor->load(temp);
  visor->position(x+100,y+160);
  visor->show(argc,argv);
}
