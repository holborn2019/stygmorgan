// generated by Fast Light User Interface Designer (fluid) version 1.0304

#include <libintl.h>
#include "stygmppui.h"
//Copyright(c) 2006 Josep Andreu (holborn)
//License GNU/GPL version 2
#include <Fl/Fl_Check_Button.H>

void rmgmpp::cb_rmgmppwin_i(Fl_Double_Window*, void*) {
  pera=2;
rmgmppwin->hide();
rmgmo->wpatterneditor=0;
rmgmppwin->clear();
delete rmgmppwin;
}
void rmgmpp::cb_rmgmppwin(Fl_Double_Window* o, void* v) {
  ((rmgmpp*)(o->user_data()))->cb_rmgmppwin_i(o,v);
}

void rmgmpp::cb_Cancel_i(Fl_Button*, void*) {
  rmgmo->bcancel=1;
rmgmppwin->do_callback();
}
void rmgmpp::cb_Cancel(Fl_Button* o, void* v) {
  ((rmgmpp*)(o->parent()->user_data()))->cb_Cancel_i(o,v);
}

void rmgmpp::cb_Ok_i(Fl_Button*, void*) {
  calcula();
rmgmppwin->do_callback();
}
void rmgmpp::cb_Ok(Fl_Button* o, void* v) {
  ((rmgmpp*)(o->parent()->user_data()))->cb_Ok_i(o,v);
}

void rmgmpp::cb_PatChoice_i(Fl_Choice* o, void*) {
  calcula();
ASeCh((int)o->value());
}
void rmgmpp::cb_PatChoice(Fl_Choice* o, void* v) {
  ((rmgmpp*)(o->parent()->user_data()))->cb_PatChoice_i(o,v);
}

void rmgmpp::cb_DChannel_i(Fl_Counter* o, void*) {
  o->parent()->redraw();
rmgmo->nStyle.Pattern[rmgmo->Variacion].casm[(int)PatChoice->value()].Canal=(int)o->value()-1;
}
void rmgmpp::cb_DChannel(Fl_Counter* o, void* v) {
  ((rmgmpp*)(o->parent()->user_data()))->cb_DChannel_i(o,v);
}

void rmgmpp::cb_ChordRoot_i(Fl_Counter* o, void*) {
  o->parent()->redraw();
DChordRoot->copy_label(rmgmo->NC[(int)o->value()].Nom);
rmgmo->nStyle.Pattern[rmgmo->Variacion].casm[(int)PatChoice->value()].ChRoot=(int)o->value();
}
void rmgmpp::cb_ChordRoot(Fl_Counter* o, void* v) {
  ((rmgmpp*)(o->parent()->user_data()))->cb_ChordRoot_i(o,v);
}

void rmgmpp::cb_ChordType_i(Fl_Counter* o, void*) {
  o->parent()->redraw();
DChordType->copy_label(rmgmo->ChN[(int)o->value()].Nom);
rmgmo->nStyle.Pattern[rmgmo->Variacion].casm[(int)PatChoice->value()].ChType=(int)o->value();
}
void rmgmpp::cb_ChordType(Fl_Counter* o, void* v) {
  ((rmgmpp*)(o->parent()->user_data()))->cb_ChordType_i(o,v);
}

void rmgmpp::cb_NTT_i(Fl_Counter* o, void*) {
  o->parent()->redraw();
rmgmo->nStyle.Pattern[rmgmo->Variacion].casm[(int)PatChoice->value()].NTT=(int)o->value();
}
void rmgmpp::cb_NTT(Fl_Counter* o, void* v) {
  ((rmgmpp*)(o->parent()->user_data()))->cb_NTT_i(o,v);
}

void rmgmpp::cb_RTR_i(Fl_Counter* o, void*) {
  o->parent()->redraw();
rmgmo->nStyle.Pattern[rmgmo->Variacion].casm[(int)PatChoice->value()].RTR=(int)o->value();
}
void rmgmpp::cb_RTR(Fl_Counter* o, void* v) {
  ((rmgmpp*)(o->parent()->user_data()))->cb_RTR_i(o,v);
}

rmgmpp::rmgmpp(RMGMO *rmgmo_) {
  char temp[128];
  static const char *pepe [] ={"stygmorgan"};
  
  int argc=1;
  char **argv= (char **) pepe;
  Fl::visual(FL_DOUBLE|FL_INDEX);
  Fl::visual(FL_RGB);
  rmgmo=rmgmo_;
  make_window();
  rmgmppwin->position(x,y);
  bzero(temp,sizeof(temp));
  sprintf(temp, "%s %s - %s - %s - Pattern Parameters",PACKAGE,VERSION,rmgmo->nStyle.Name,rmgmo->nStyle.Pattern[rmgmo->Variacion].Name);
  rmgmppwin->label(temp);
  rmgmppwin->icon((char *)p);
  rmgmppwin->show(argc,argv);
}

Fl_Double_Window* rmgmpp::make_window() {
  { rmgmppwin = new Fl_Double_Window(830, 335);
    rmgmppwin->color((Fl_Color)44);
    rmgmppwin->labelcolor(FL_BACKGROUND2_COLOR);
    rmgmppwin->callback((Fl_Callback*)cb_rmgmppwin, (void*)(this));
    { Fl_Button* o = new Fl_Button(735, 275, 80, 25, gettext("Cancel"));
      o->box(FL_PLASTIC_THIN_UP_BOX);
      o->color((Fl_Color)11);
      o->selection_color((Fl_Color)3);
      o->callback((Fl_Callback*)cb_Cancel);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(735, 305, 80, 25, gettext("Ok"));
      o->box(FL_PLASTIC_THIN_UP_BOX);
      o->color((Fl_Color)11);
      o->selection_color((Fl_Color)3);
      o->callback((Fl_Callback*)cb_Ok);
    } // Fl_Button* o
    { PatChoice = new Fl_Choice(10, 25, 150, 25, gettext("Original Channel/Track"));
      PatChoice->down_box(FL_BORDER_BOX);
      PatChoice->color((Fl_Color)44);
      PatChoice->selection_color(FL_DARK1);
      PatChoice->labelsize(11);
      PatChoice->labelcolor(FL_BACKGROUND2_COLOR);
      PatChoice->textcolor(FL_BACKGROUND2_COLOR);
      PatChoice->callback((Fl_Callback*)cb_PatChoice);
      PatChoice->align(Fl_Align(FL_ALIGN_TOP_LEFT));
    } // Fl_Choice* PatChoice
    { DChannel = new Fl_Counter(10, 75, 100, 25, gettext("Dest. Channel"));
      DChannel->type(1);
      DChannel->box(FL_NO_BOX);
      DChannel->selection_color(FL_DARK1);
      DChannel->labelsize(11);
      DChannel->labelcolor(FL_BACKGROUND2_COLOR);
      DChannel->minimum(1);
      DChannel->maximum(16);
      DChannel->step(1);
      DChannel->value(1);
      DChannel->textcolor(FL_BACKGROUND2_COLOR);
      DChannel->callback((Fl_Callback*)cb_DChannel);
      DChannel->align(Fl_Align(FL_ALIGN_TOP_LEFT));
    } // Fl_Counter* DChannel
    { ChordRoot = new Fl_Counter(10, 120, 100, 25, gettext("Chord Root"));
      ChordRoot->type(1);
      ChordRoot->box(FL_NO_BOX);
      ChordRoot->color((Fl_Color)44);
      ChordRoot->labelsize(11);
      ChordRoot->labelcolor(FL_BACKGROUND2_COLOR);
      ChordRoot->minimum(1);
      ChordRoot->maximum(12);
      ChordRoot->step(1);
      ChordRoot->value(1);
      ChordRoot->textcolor(FL_BACKGROUND2_COLOR);
      ChordRoot->callback((Fl_Callback*)cb_ChordRoot);
      ChordRoot->align(Fl_Align(FL_ALIGN_TOP_LEFT));
    } // Fl_Counter* ChordRoot
    { ChordType = new Fl_Counter(10, 165, 100, 25, gettext("Chord Type"));
      ChordType->type(1);
      ChordType->box(FL_NO_BOX);
      ChordType->color((Fl_Color)44);
      ChordType->selection_color(FL_DARK1);
      ChordType->labelsize(11);
      ChordType->labelcolor(FL_BACKGROUND2_COLOR);
      ChordType->minimum(0);
      ChordType->maximum(32);
      ChordType->step(1);
      ChordType->value(1);
      ChordType->textcolor(FL_BACKGROUND2_COLOR);
      ChordType->callback((Fl_Callback*)cb_ChordType);
      ChordType->align(Fl_Align(FL_ALIGN_TOP_LEFT));
    } // Fl_Counter* ChordType
    { DChordRoot = new Fl_Box(120, 120, 90, 30);
      DChordRoot->box(FL_DOWN_BOX);
      DChordRoot->color((Fl_Color)44);
      DChordRoot->labelcolor((Fl_Color)1);
    } // Fl_Box* DChordRoot
    { DChordType = new Fl_Box(120, 165, 90, 30);
      DChordType->box(FL_DOWN_BOX);
      DChordType->color((Fl_Color)44);
      DChordType->labelcolor((Fl_Color)1);
    } // Fl_Box* DChordType
    { NTT = new Fl_Counter(10, 210, 100, 25, gettext("NTT"));
      NTT->type(1);
      NTT->box(FL_NO_BOX);
      NTT->color((Fl_Color)44);
      NTT->selection_color(FL_DARK1);
      NTT->labelsize(11);
      NTT->labelcolor(FL_BACKGROUND2_COLOR);
      NTT->minimum(1);
      NTT->maximum(12);
      NTT->step(1);
      NTT->value(1);
      NTT->textcolor(FL_BACKGROUND2_COLOR);
      NTT->callback((Fl_Callback*)cb_NTT);
      NTT->align(Fl_Align(FL_ALIGN_TOP_LEFT));
    } // Fl_Counter* NTT
    { RTR = new Fl_Counter(10, 255, 100, 25, gettext("RTR"));
      RTR->type(1);
      RTR->box(FL_NO_BOX);
      RTR->color((Fl_Color)44);
      RTR->selection_color(FL_DARK1);
      RTR->labelsize(11);
      RTR->labelcolor(FL_BACKGROUND2_COLOR);
      RTR->minimum(1);
      RTR->maximum(12);
      RTR->step(1);
      RTR->value(1);
      RTR->textcolor(FL_BACKGROUND2_COLOR);
      RTR->callback((Fl_Callback*)cb_RTR);
      RTR->align(Fl_Align(FL_ALIGN_TOP_LEFT));
    } // Fl_Counter* RTR
    { Fl_Box* o = new Fl_Box(215, 20, 610, 245);
      o->box(FL_DOWN_BOX);
      o->color((Fl_Color)44);
    } // Fl_Box* o
    rmgmppwin->end();
  } // Fl_Double_Window* rmgmppwin
  int i,j,k,l,udata;
  char temp[128];
  char pep[64];
  
  
  DChannel->clear_visible_focus();
  DChordRoot->clear_visible_focus();
  NTT->clear_visible_focus();
  RTR->clear_visible_focus();
  
  
  for (i=0; i<rmgmo->nStyle.Pattern[rmgmo->Variacion].numcasm; i++)
  {
  bzero(pep,sizeof(pep));
  for (j=0;j<(int)strlen(rmgmo->nStyle.Pattern[rmgmo->Variacion].casm[i].Name);j++)
  if (rmgmo->nStyle.Pattern[rmgmo->Variacion].casm[i].Name[j]!=47)pep[j]=rmgmo->nStyle.Pattern[rmgmo->Variacion].casm[i].Name[j];
  bzero(temp,sizeof(temp));
  sprintf(temp ,"%d_%s",rmgmo->nStyle.Pattern[rmgmo->Variacion].casm[i].track+1,pep);
  PatChoice->add(temp);
  }
  
  PatChoice->value(0);
  k=0;
  l=0;
  udata=100;
  for(j=0; j<=4; j++)
   {
  
  for (i=0;i<8; i++)
   {
  
   switch (i)
      {
        case 1:
            l=90;   
            break;
        default:
            l=75;
      }
      
                  
  Fl_Check_Button *obot = new Fl_Check_Button(230+i*l, 50+j*45, 45, 25,rmgmo->ChN[k].Nom);
        obot->down_box(FL_NO_BOX);
        obot->align(FL_ALIGN_TOP_LEFT);
        obot->labelcolor((Fl_Color)FL_WHITE);
        obot->color((Fl_Color)44);
        obot->selection_color((Fl_Color)3);
        obot->labelsize((Fl_Fontsize)11);
        obot->clear_visible_focus();  
        obot->user_data((void*) udata);
  
        
  k++;
  udata=100+k;
  
  rmgmppwin->add(obot);
  
  if ((j==4) && (i==1)) break;
  }
  
  }
  rmgmppwin->end();
  
  rmgmo->ulase=0;
  ASeCh(0);
  return rmgmppwin;
}

void rmgmpp::ASeCh(int tr) {
  int i,j;
  unsigned long lolo=0;
  Fl_Check_Button *pepe;
  
  rmgmo->ulase=tr;
  DChannel->value(rmgmo->nStyle.Pattern[rmgmo->Variacion].casm[tr].Canal+1);
  ChordRoot->value(rmgmo->nStyle.Pattern[rmgmo->Variacion].casm[tr].ChRoot);
  ChordType->value(rmgmo->nStyle.Pattern[rmgmo->Variacion].casm[tr].ChType);
  ChordRoot->do_callback();
  ChordType->do_callback();
  NTT->value(rmgmo->nStyle.Pattern[rmgmo->Variacion].casm[tr].NTT);
  RTR->value(rmgmo->nStyle.Pattern[rmgmo->Variacion].casm[tr].RTR);
  
  for(i=0; i<33; i++)
  {
  lolo=1;
  if (i==0) lolo = 1; else 
  for (j=1; j<=i; j++) lolo *=2;
  pepe = (Fl_Check_Button*) rmgmppwin->child(11+i);
  if ( (rmgmo->nStyle.Pattern[rmgmo->Variacion].casm[tr].ChM & lolo) == lolo) pepe->value(1); else pepe->value(0); 
     
  }
}

void rmgmpp::calcula() {
  int i,j;
  unsigned long tito=0;
  unsigned long lolo=0;
  Fl_Check_Button *pepe;
  
  for(i=0; i<33; i++)
  {
  
  lolo=1;
  if (i==0) lolo = 1; else for (j=1; j<=i; j++) lolo *=2;
  
  pepe = (Fl_Check_Button*) rmgmppwin->child(11+i);
  
  if ((int) pepe->value() == 1) tito=tito+lolo;
  
  }
  
  rmgmo->nStyle.Pattern[rmgmo->Variacion].casm[rmgmo->ulase].ChM=tito;
}
