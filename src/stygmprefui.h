// generated by Fast Light User Interface Designer (fluid) version 1.0304

#ifndef stygmprefui_h
#define stygmprefui_h
#include <FL/Fl.H>
#include "stygmorgan.h"
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_File_Input.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Input.H>

class rmgmpref {
public:
  rmgmpref(RMGMO *rmgmo_);
private:
  RMGMO *rmgmo; 
public:
  Fl_Double_Window* make_window();
  Fl_Double_Window *rmgmprefwin;
private:
  inline void cb_rmgmprefwin_i(Fl_Double_Window*, void*);
  static void cb_rmgmprefwin(Fl_Double_Window*, void*);
  inline void cb_Cancel_i(Fl_Button*, void*);
  static void cb_Cancel(Fl_Button*, void*);
  inline void cb_Ok_i(Fl_Button*, void*);
  static void cb_Ok(Fl_Button*, void*);
public:
  Fl_Check_Button *ASF;
private:
  inline void cb_ASF_i(Fl_Check_Button*, void*);
  static void cb_ASF(Fl_Check_Button*, void*);
public:
  Fl_Group *ASFGroup;
  Fl_File_Input *SFPath;
private:
  inline void cb_Browse_i(Fl_Button*, void*);
  static void cb_Browse(Fl_Button*, void*);
public:
  Fl_Check_Button *AConnect;
private:
  inline void cb_AConnect_i(Fl_Check_Button*, void*);
  static void cb_AConnect(Fl_Check_Button*, void*);
public:
  Fl_Group *MBros;
  Fl_Browser *BrIn;
  Fl_Browser *BrOut;
  Fl_File_Input *TempFilesDir;
private:
  inline void cb_Browse1_i(Fl_Button*, void*);
  static void cb_Browse1(Fl_Button*, void*);
public:
  Fl_Check_Button *DRespect;
  Fl_Check_Button *DUseSysEx;
private:
  inline void cb_DUseSysEx_i(Fl_Check_Button*, void*);
  static void cb_DUseSysEx(Fl_Check_Button*, void*);
public:
  Fl_Input *DTextStart;
private:
  inline void cb_DTextStart_i(Fl_Input*, void*);
  static void cb_DTextStart(Fl_Input*, void*);
public:
  Fl_Input *DTextAutoF;
private:
  inline void cb_DTextAutoF_i(Fl_Input*, void*);
  static void cb_DTextAutoF(Fl_Input*, void*);
public:
  Fl_Check_Button *BANKLSB0;
  Fl_Check_Button *BANKTRUCO;
  Fl_Check_Button *JTRANSPORT;
  void GuardaPrefs();
  void MiraClientes();
};
#endif
