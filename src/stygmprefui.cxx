// generated by Fast Light User Interface Designer (fluid) version 1.0304

#include <libintl.h>
#include "stygmprefui.h"
//Copyright(c) 2006 Josep Andreu (holborn)
//License GNU/GPL version 2
#include <Fl/Fl_Preferences.H>
#include <Fl/Fl_File_Chooser.H>

void rmgmpref::cb_rmgmprefwin_i(Fl_Double_Window*, void*) {
  rmgmprefwin->hide();
rmgmo->wpreferences=0;
rmgmprefwin->clear();
delete rmgmprefwin;
}
void rmgmpref::cb_rmgmprefwin(Fl_Double_Window* o, void* v) {
  ((rmgmpref*)(o->user_data()))->cb_rmgmprefwin_i(o,v);
}

void rmgmpref::cb_Cancel_i(Fl_Button*, void*) {
  rmgmprefwin->do_callback();
}
void rmgmpref::cb_Cancel(Fl_Button* o, void* v) {
  ((rmgmpref*)(o->parent()->user_data()))->cb_Cancel_i(o,v);
}

void rmgmpref::cb_Ok_i(Fl_Button*, void*) {
  GuardaPrefs();
rmgmprefwin->do_callback();
}
void rmgmpref::cb_Ok(Fl_Button* o, void* v) {
  ((rmgmpref*)(o->parent()->user_data()))->cb_Ok_i(o,v);
}

void rmgmpref::cb_ASF_i(Fl_Check_Button* o, void*) {
  if ((int) o->value() ) ASFGroup->activate(); else ASFGroup->deactivate();
}
void rmgmpref::cb_ASF(Fl_Check_Button* o, void* v) {
  ((rmgmpref*)(o->parent()->user_data()))->cb_ASF_i(o,v);
}

void rmgmpref::cb_Browse_i(Fl_Button*, void*) {
  char *filename;
filename=fl_file_chooser("Browse:","(*.sf2)",NULL,0);
if (filename==NULL) return;
SFPath->value(filename);
strcpy(rmgmo->ASFFilename,filename);
}
void rmgmpref::cb_Browse(Fl_Button* o, void* v) {
  ((rmgmpref*)(o->parent()->parent()->user_data()))->cb_Browse_i(o,v);
}

void rmgmpref::cb_AConnect_i(Fl_Check_Button* o, void*) {
  if ((int) o->value()) MBros->activate(); else MBros->deactivate();
}
void rmgmpref::cb_AConnect(Fl_Check_Button* o, void* v) {
  ((rmgmpref*)(o->parent()->user_data()))->cb_AConnect_i(o,v);
}

void rmgmpref::cb_Browse1_i(Fl_Button*, void*) {
  char *filename;
filename=fl_dir_chooser("Browse:",rmgmo->TempDir,0);
if (filename==NULL) return;
TempFilesDir->value(filename);
strcpy(rmgmo->TempDir,filename);
}
void rmgmpref::cb_Browse1(Fl_Button* o, void* v) {
  ((rmgmpref*)(o->parent()->user_data()))->cb_Browse1_i(o,v);
}

void rmgmpref::cb_DUseSysEx_i(Fl_Check_Button* o, void*) {
  if((int)o->value())
{
 DTextStart->activate();
 DTextAutoF->activate();
 }
 else
{  
 DTextStart->deactivate();
 DTextAutoF->deactivate();
 };
}
void rmgmpref::cb_DUseSysEx(Fl_Check_Button* o, void* v) {
  ((rmgmpref*)(o->parent()->user_data()))->cb_DUseSysEx_i(o,v);
}

void rmgmpref::cb_DTextStart_i(Fl_Input* o, void*) {
  strcpy(rmgmo->TextSTART,o->value());
}
void rmgmpref::cb_DTextStart(Fl_Input* o, void* v) {
  ((rmgmpref*)(o->parent()->user_data()))->cb_DTextStart_i(o,v);
}

void rmgmpref::cb_DTextAutoF_i(Fl_Input* o, void*) {
  strcpy(rmgmo->TextAUTOF,o->value());
}
void rmgmpref::cb_DTextAutoF(Fl_Input* o, void* v) {
  ((rmgmpref*)(o->parent()->user_data()))->cb_DTextAutoF_i(o,v);
}

rmgmpref::rmgmpref(RMGMO *rmgmo_) {
  Fl::visual(FL_DOUBLE|FL_INDEX);
  Fl::visual(FL_RGB);
  
  
  char temp[128];
  static const char *pepe [] ={"stygmorgan"};
  
  int argc=1;
  char **argv= (char **) pepe;
  
  Fl::visual(FL_DOUBLE|FL_INDEX);
  Fl::visual(FL_RGB);
  rmgmo=rmgmo_;
  make_window();
  rmgmprefwin->position(x+20,y+20);
  bzero(temp,sizeof(temp));
  sprintf(temp,"%s %s - Preferences",PACKAGE,VERSION);
  rmgmprefwin->copy_label(temp);
  rmgmprefwin->icon((char *)p);
  rmgmprefwin->show(argc,argv);
}

Fl_Double_Window* rmgmpref::make_window() {
  { rmgmprefwin = new Fl_Double_Window(540, 515);
    rmgmprefwin->color((Fl_Color)44);
    rmgmprefwin->selection_color((Fl_Color)48);
    rmgmprefwin->callback((Fl_Callback*)cb_rmgmprefwin, (void*)(this));
    { Fl_Button* o = new Fl_Button(455, 455, 80, 25, gettext("Cancel"));
      o->box(FL_PLASTIC_THIN_UP_BOX);
      o->color((Fl_Color)11);
      o->selection_color((Fl_Color)3);
      o->callback((Fl_Callback*)cb_Cancel);
    } // Fl_Button* o
    { Fl_Button* o = new Fl_Button(370, 455, 80, 25, gettext("Ok"));
      o->box(FL_PLASTIC_THIN_UP_BOX);
      o->color((Fl_Color)11);
      o->selection_color((Fl_Color)3);
      o->callback((Fl_Callback*)cb_Ok);
    } // Fl_Button* o
    { ASF = new Fl_Check_Button(5, 205, 267, 25, gettext("Use asfxload to load soundfont at startup?"));
      ASF->down_box(FL_DOWN_BOX);
      ASF->color((Fl_Color)44);
      ASF->selection_color((Fl_Color)3);
      ASF->labelsize(12);
      ASF->labelcolor(FL_BACKGROUND2_COLOR);
      ASF->callback((Fl_Callback*)cb_ASF);
    } // Fl_Check_Button* ASF
    { ASFGroup = new Fl_Group(5, 226, 530, 54);
      ASFGroup->color((Fl_Color)44);
      ASFGroup->selection_color(FL_DARK1);
      ASFGroup->labelcolor(FL_BACKGROUND2_COLOR);
      { SFPath = new Fl_File_Input(5, 240, 530, 30, gettext("SoundFont"));
        SFPath->color((Fl_Color)44);
        SFPath->labelsize(11);
        SFPath->labelcolor(FL_BACKGROUND2_COLOR);
        SFPath->textcolor(FL_BACKGROUND2_COLOR);
        SFPath->align(Fl_Align(FL_ALIGN_TOP_LEFT));
      } // Fl_File_Input* SFPath
      { Fl_Button* o = new Fl_Button(455, 226, 70, 20, gettext("Browse"));
        o->box(FL_PLASTIC_THIN_UP_BOX);
        o->color((Fl_Color)11);
        o->selection_color((Fl_Color)3);
        o->labelsize(11);
        o->callback((Fl_Callback*)cb_Browse);
      } // Fl_Button* o
      ASFGroup->end();
    } // Fl_Group* ASFGroup
    { AConnect = new Fl_Check_Button(5, 10, 270, 25, gettext("auto connect Midi devices at startup?"));
      AConnect->down_box(FL_DOWN_BOX);
      AConnect->color((Fl_Color)44);
      AConnect->selection_color((Fl_Color)3);
      AConnect->labelsize(12);
      AConnect->labelcolor(FL_BACKGROUND2_COLOR);
      AConnect->callback((Fl_Callback*)cb_AConnect);
    } // Fl_Check_Button* AConnect
    { MBros = new Fl_Group(5, 35, 525, 165);
      MBros->box(FL_DOWN_BOX);
      MBros->color((Fl_Color)44);
      MBros->selection_color(FL_DARK1);
      MBros->labelcolor(FL_BACKGROUND2_COLOR);
      { BrIn = new Fl_Browser(15, 60, 250, 135, gettext("Midi Input Devices"));
        BrIn->type(2);
        BrIn->color((Fl_Color)44);
        BrIn->selection_color(FL_DARK1);
        BrIn->labelsize(11);
        BrIn->labelcolor(FL_BACKGROUND2_COLOR);
        BrIn->textcolor(FL_BACKGROUND2_COLOR);
        BrIn->align(Fl_Align(FL_ALIGN_TOP));
        BrIn->when(FL_WHEN_CHANGED);
      } // Fl_Browser* BrIn
      { BrOut = new Fl_Browser(270, 60, 255, 135, gettext("Midi Output Devices "));
        BrOut->type(2);
        BrOut->color((Fl_Color)44);
        BrOut->selection_color(FL_DARK1);
        BrOut->labelsize(11);
        BrOut->labelcolor(FL_BACKGROUND2_COLOR);
        BrOut->textcolor(FL_BACKGROUND2_COLOR);
        BrOut->align(Fl_Align(FL_ALIGN_TOP));
        BrOut->when(FL_WHEN_CHANGED);
      } // Fl_Browser* BrOut
      MBros->end();
    } // Fl_Group* MBros
    { TempFilesDir = new Fl_File_Input(5, 286, 530, 30, gettext("Directory for temporal files"));
      TempFilesDir->color((Fl_Color)44);
      TempFilesDir->selection_color(FL_DARK1);
      TempFilesDir->labelsize(11);
      TempFilesDir->labelcolor(FL_BACKGROUND2_COLOR);
      TempFilesDir->textcolor(FL_BACKGROUND2_COLOR);
      TempFilesDir->align(Fl_Align(FL_ALIGN_TOP_LEFT));
    } // Fl_File_Input* TempFilesDir
    { Fl_Button* o = new Fl_Button(455, 272, 70, 20, gettext("Browse"));
      o->box(FL_PLASTIC_THIN_UP_BOX);
      o->color((Fl_Color)11);
      o->selection_color((Fl_Color)3);
      o->labelsize(11);
      o->callback((Fl_Callback*)cb_Browse1);
    } // Fl_Button* o
    { DRespect = new Fl_Check_Button(5, 440, 270, 25, gettext("Maintain Mutes when pattern changes"));
      DRespect->down_box(FL_DOWN_BOX);
      DRespect->color((Fl_Color)44);
      DRespect->selection_color((Fl_Color)3);
      DRespect->labelsize(12);
      DRespect->labelcolor(FL_BACKGROUND2_COLOR);
    } // Fl_Check_Button* DRespect
    { DUseSysEx = new Fl_Check_Button(5, 320, 270, 25, gettext("Use SysEx messages for Start/AutoF"));
      DUseSysEx->tooltip(gettext("Input form: F0 43 10 .... F7"));
      DUseSysEx->down_box(FL_DOWN_BOX);
      DUseSysEx->color((Fl_Color)44);
      DUseSysEx->selection_color((Fl_Color)3);
      DUseSysEx->labelsize(12);
      DUseSysEx->labelcolor(FL_BACKGROUND2_COLOR);
      DUseSysEx->callback((Fl_Callback*)cb_DUseSysEx);
    } // Fl_Check_Button* DUseSysEx
    { DTextStart = new Fl_Input(5, 360, 465, 25, gettext("SysEx for Start button "));
      DTextStart->tooltip(gettext("Input form: F0 43 10 .... F7"));
      DTextStart->color((Fl_Color)44);
      DTextStart->selection_color(FL_DARK1);
      DTextStart->labelsize(10);
      DTextStart->labelcolor(FL_BACKGROUND2_COLOR);
      DTextStart->textcolor(FL_BACKGROUND2_COLOR);
      DTextStart->callback((Fl_Callback*)cb_DTextStart);
      DTextStart->align(Fl_Align(FL_ALIGN_TOP_LEFT));
    } // Fl_Input* DTextStart
    { DTextAutoF = new Fl_Input(5, 410, 465, 25, gettext("SysEx for Auto Fill-In button "));
      DTextAutoF->tooltip(gettext("Input form: F0 43 10 .... F7"));
      DTextAutoF->color((Fl_Color)44);
      DTextAutoF->selection_color(FL_DARK1);
      DTextAutoF->labelsize(10);
      DTextAutoF->labelcolor(FL_BACKGROUND2_COLOR);
      DTextAutoF->textcolor(FL_BACKGROUND2_COLOR);
      DTextAutoF->callback((Fl_Callback*)cb_DTextAutoF);
      DTextAutoF->align(Fl_Align(FL_ALIGN_TOP_LEFT));
    } // Fl_Input* DTextAutoF
    { BANKLSB0 = new Fl_Check_Button(5, 465, 90, 25, gettext("BANK LSB 0"));
      BANKLSB0->down_box(FL_DOWN_BOX);
      BANKLSB0->color((Fl_Color)44);
      BANKLSB0->selection_color((Fl_Color)3);
      BANKLSB0->labelsize(12);
      BANKLSB0->labelcolor(FL_BACKGROUND2_COLOR);
    } // Fl_Check_Button* BANKLSB0
    { BANKTRUCO = new Fl_Check_Button(95, 465, 100, 25, gettext("BANK Truco"));
      BANKTRUCO->down_box(FL_DOWN_BOX);
      BANKTRUCO->color((Fl_Color)44);
      BANKTRUCO->selection_color((Fl_Color)3);
      BANKTRUCO->labelsize(12);
      BANKTRUCO->labelcolor(FL_BACKGROUND2_COLOR);
    } // Fl_Check_Button* BANKTRUCO
    { JTRANSPORT = new Fl_Check_Button(4, 488, 181, 22, gettext("Use Jack Transport Tempo"));
      JTRANSPORT->down_box(FL_DOWN_BOX);
      JTRANSPORT->color((Fl_Color)44);
      JTRANSPORT->selection_color((Fl_Color)3);
      JTRANSPORT->labelsize(12);
      JTRANSPORT->labelcolor(FL_BACKGROUND2_COLOR);
    } // Fl_Check_Button* JTRANSPORT
    rmgmprefwin->end();
  } // Fl_Double_Window* rmgmprefwin
  int i;
  int val=0;
  char sffile[80];
  
  
  ASF->clear_visible_focus();
  ASF->down_box(FL_NO_BOX);
  ASF->selection_color((Fl_Color)3);
  
  AConnect->clear_visible_focus();
  AConnect->down_box(FL_NO_BOX);
  AConnect->selection_color((Fl_Color)3);
  
  DRespect->clear_visible_focus();
  DRespect->down_box(FL_NO_BOX);
  DRespect->selection_color((Fl_Color)3);
  
  DUseSysEx->clear_visible_focus();
  DUseSysEx->down_box(FL_NO_BOX);
  DUseSysEx->selection_color((Fl_Color)3);
  
  BANKLSB0->clear_visible_focus();
  BANKLSB0->down_box(FL_NO_BOX);
  BANKLSB0->selection_color((Fl_Color)3);
  
  BANKTRUCO->clear_visible_focus();
  BANKTRUCO->down_box(FL_NO_BOX);
  BANKTRUCO->selection_color((Fl_Color)3);
  
  JTRANSPORT->clear_visible_focus();
  JTRANSPORT->down_box(FL_NO_BOX);
  JTRANSPORT->selection_color((Fl_Color)3);
  
  MiraClientes();
  
  Fl_Preferences stygmorgan (Fl_Preferences::USER, WEBSITE, PACKAGE);
  
  stygmorgan.get("TempDir",rmgmo->TempDir,"",126);
  TempFilesDir->value(rmgmo->TempDir);
  
  stygmorgan.get("AutoSF",val,0);
  ASF->value(val);
  ASF->do_callback();
  
  stygmorgan.get("SFFile",sffile,"",126);
  SFPath->value(sffile);
  
  stygmorgan.get("MutesPatternChange",rmgmo->Respect,0);
  DRespect->value(rmgmo->Respect);
  
  stygmorgan.get("Bank_LSB_0",rmgmo->BankLSBLS,0);
  BANKLSB0->value(rmgmo->BankLSBLS);
  
  stygmorgan.get("Bank_Truco_0",rmgmo->BankTruco,0);
  BANKTRUCO->value(rmgmo->BankTruco);
  
  stygmorgan.get("usejacktransport",rmgmo->usejacktransport,0);
  JTRANSPORT->value(rmgmo->usejacktransport);
  
  stygmorgan.get("AConnect",val,0);
  AConnect->value(val);
  AConnect->do_callback();
  
  stygmorgan.get("MidiInDevice",sffile,"",78);
  
  for(i=1;i<=BrIn->size();i++)
   {
      if (strcmp(BrIn->text(i),sffile)==0) 
           { 
             BrIn->select(i,1);
             break;
            } 
    }         
  
  stygmorgan.get("MidiOutDevice",sffile,"",78);
  
  for(i=1;i<=BrOut->size();i++)
   {
      if (strcmp(BrOut->text(i),sffile)==0) 
           { 
             BrOut->select(i,1);
             break;
            } 
    }
    
    
  stygmorgan.get("UseSysEX",rmgmo->usesysex,0);
  DUseSysEx->value(rmgmo->usesysex);
  DUseSysEx->do_callback();
  stygmorgan.get("ButStart",rmgmo->TextSTART,"",126);
  DTextStart->value(rmgmo->TextSTART);
  stygmorgan.get("ButAutoF",rmgmo->TextAUTOF,"",126);
  DTextAutoF->value(rmgmo->TextAUTOF);
  return rmgmprefwin;
}

void rmgmpref::GuardaPrefs() {
  Fl_Preferences stygmorgan (Fl_Preferences::USER, WEBSITE, PACKAGE);
  
  stygmorgan.set("AConnect",(int)AConnect->value());
  if (BrIn->value() > 0 ) 
  {
    stygmorgan.set("MidiInDevice",BrIn->text(BrIn->value()));
    bzero(rmgmo->MID,sizeof(rmgmo->MID));
    strcpy(rmgmo->MID,BrIn->text(BrIn->value()));
    rmgmo->CambiaMidi=1;
  } 
  
  if (BrOut->value() > 0)
  {
   stygmorgan.set("MidiOutDevice",BrOut->text(BrOut->value()));
   bzero(rmgmo->MOD,sizeof(rmgmo->MOD));
   strcpy(rmgmo->MOD,BrOut->text(BrOut->value()));
   rmgmo->CambiaMidi=1; 
  }
  stygmorgan.set("AutoSF",(int)ASF->value());
  stygmorgan.set("SFFile",SFPath->value());
  
  if (((int)ASF->value()) && (SFPath->value() != NULL)) rmgmo->cargaASF();
  
  stygmorgan.set("TempDir",TempFilesDir->value());
  
  rmgmo->Respect=(int)DRespect->value();
  stygmorgan.set("MutesPatternChange",rmgmo->Respect);
  
  rmgmo->BankLSBLS=(int)BANKLSB0->value();
  stygmorgan.set("Bank_LSB_0",rmgmo->BankLSBLS);
  
  rmgmo->BankTruco=(int)BANKTRUCO->value();
  stygmorgan.set("Bank_Truco_0",rmgmo->BankTruco);
  
  rmgmo->usejacktransport=(int)JTRANSPORT->value();
  stygmorgan.set("usejacktransport",rmgmo->usejacktransport);
  
  rmgmo->usesysex=(int)DUseSysEx->value();
  stygmorgan.set("UseSysEX",rmgmo->usesysex);
  
  
  if (rmgmo->usesysex)
  {
   stygmorgan.set("ButStart",rmgmo->TextSTART);
   stygmorgan.set("ButAutoF",rmgmo->TextAUTOF);
   rmgmo->ConvierteHexString();
  }
}

void rmgmpref::MiraClientes() {
  FILE *fp;
  char temp[128];
  char temp1[128];
  char *masque;
  char *name;
  
  if ((fp = fopen ("/proc/asound/seq/clients", "r")) != NULL)
    {
      bzero (temp, sizeof (temp));
  
        while (fgets (temp, sizeof temp, fp) != NULL)
             {
               
              if (strstr(temp,"Port") != NULL)
               
             {  
               
               strcpy(temp1,temp);
               strtok(temp1,"\"");
               name=strtok(NULL,"\"");
               masque=strtok(NULL,")");
               
               
               
               if ((masque[3]=='W' ) && (strstr(name,"stygmorgan IN")==0)) BrOut->add(name);
               if ((masque[2]=='R' ) && (strstr(name,"stygmorgan OUT")==0)) BrIn->add(name);
               
              } 
             } 
     }
     
     fclose(fp);
}
