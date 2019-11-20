// generated by Fast Light User Interface Designer (fluid) version 1.0304

#ifndef stygmorganui_h
#define stygmorganui_h
#include <FL/Fl.H>
#include <FL/x.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_File_Chooser.H>
#include <FL/Fl_Dial.H>
#include "stygmorgan.h"

class MiSlider : public Fl_Slider {
public:
  MiSlider(int x,int y, int w, int h, const char *label=0);
  int handle(int event);
};

class MiDial : public Fl_Dial {
public:
  MiDial(int x,int y, int w, int h, const char *label=0);
  int handle(int event);
};
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Counter.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Dial.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Slider.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Output.H>

class stygmorgan {
  RMGMO *rmgmo; 
public:
  Fl_Double_Window* make_window();
  Fl_Double_Window *rmgmorganwin;
private:
  inline void cb_rmgmorganwin_i(Fl_Double_Window*, void*);
  static void cb_rmgmorganwin(Fl_Double_Window*, void*);
public:
  Fl_Group *Mix0;
  MiDial *Pan0;
private:
  inline void cb_Pan0_i(MiDial*, void*);
  static void cb_Pan0(MiDial*, void*);
public:
  MiDial *Reverb0;
private:
  inline void cb_Reverb0_i(MiDial*, void*);
  static void cb_Reverb0(MiDial*, void*);
public:
  MiDial *Chorus0;
private:
  inline void cb_Chorus0_i(MiDial*, void*);
  static void cb_Chorus0(MiDial*, void*);
public:
  MiSlider *Vol0;
private:
  inline void cb_Vol0_i(MiSlider*, void*);
  static void cb_Vol0(MiSlider*, void*);
public:
  Fl_Button *On0;
private:
  inline void cb_On0_i(Fl_Button*, void*);
  static void cb_On0(Fl_Button*, void*);
public:
  Fl_Button *Solo0;
private:
  inline void cb_Solo0_i(Fl_Button*, void*);
  static void cb_Solo0(Fl_Button*, void*);
public:
  Fl_Button *More0;
private:
  inline void cb_More0_i(Fl_Button*, void*);
  static void cb_More0(Fl_Button*, void*);
public:
  Fl_Box *DP0;
  Fl_Counter *P0;
private:
  inline void cb_P0_i(Fl_Counter*, void*);
  static void cb_P0(Fl_Counter*, void*);
public:
  Fl_Group *Mix1;
  MiDial *Pan1;
private:
  inline void cb_Pan1_i(MiDial*, void*);
  static void cb_Pan1(MiDial*, void*);
public:
  MiDial *Reverb1;
private:
  inline void cb_Reverb1_i(MiDial*, void*);
  static void cb_Reverb1(MiDial*, void*);
public:
  MiDial *Chorus1;
private:
  inline void cb_Chorus1_i(MiDial*, void*);
  static void cb_Chorus1(MiDial*, void*);
public:
  MiSlider *Vol1;
private:
  inline void cb_Vol1_i(MiSlider*, void*);
  static void cb_Vol1(MiSlider*, void*);
public:
  Fl_Button *On1;
private:
  inline void cb_On1_i(Fl_Button*, void*);
  static void cb_On1(Fl_Button*, void*);
public:
  Fl_Button *Solo1;
private:
  inline void cb_Solo1_i(Fl_Button*, void*);
  static void cb_Solo1(Fl_Button*, void*);
public:
  Fl_Button *More1;
private:
  inline void cb_More1_i(Fl_Button*, void*);
  static void cb_More1(Fl_Button*, void*);
public:
  Fl_Box *DP1;
  Fl_Counter *P1;
private:
  inline void cb_P1_i(Fl_Counter*, void*);
  static void cb_P1(Fl_Counter*, void*);
public:
  Fl_Group *Mix2;
  MiDial *Pan2;
private:
  inline void cb_Pan2_i(MiDial*, void*);
  static void cb_Pan2(MiDial*, void*);
public:
  MiDial *Reverb2;
private:
  inline void cb_Reverb2_i(MiDial*, void*);
  static void cb_Reverb2(MiDial*, void*);
public:
  MiDial *Chorus2;
private:
  inline void cb_Chorus2_i(MiDial*, void*);
  static void cb_Chorus2(MiDial*, void*);
public:
  MiSlider *Vol2;
private:
  inline void cb_Vol2_i(MiSlider*, void*);
  static void cb_Vol2(MiSlider*, void*);
public:
  Fl_Button *On2;
private:
  inline void cb_On2_i(Fl_Button*, void*);
  static void cb_On2(Fl_Button*, void*);
public:
  Fl_Button *Solo2;
private:
  inline void cb_Solo2_i(Fl_Button*, void*);
  static void cb_Solo2(Fl_Button*, void*);
public:
  Fl_Button *More2;
private:
  inline void cb_More2_i(Fl_Button*, void*);
  static void cb_More2(Fl_Button*, void*);
public:
  Fl_Box *DP2;
  Fl_Counter *P2;
private:
  inline void cb_P2_i(Fl_Counter*, void*);
  static void cb_P2(Fl_Counter*, void*);
public:
  Fl_Group *Mix3;
  MiDial *Pan3;
private:
  inline void cb_Pan3_i(MiDial*, void*);
  static void cb_Pan3(MiDial*, void*);
public:
  MiDial *Reverb3;
private:
  inline void cb_Reverb3_i(MiDial*, void*);
  static void cb_Reverb3(MiDial*, void*);
public:
  MiDial *Chorus3;
private:
  inline void cb_Chorus3_i(MiDial*, void*);
  static void cb_Chorus3(MiDial*, void*);
public:
  MiSlider *Vol3;
private:
  inline void cb_Vol3_i(MiSlider*, void*);
  static void cb_Vol3(MiSlider*, void*);
public:
  Fl_Button *On3;
private:
  inline void cb_On3_i(Fl_Button*, void*);
  static void cb_On3(Fl_Button*, void*);
public:
  Fl_Button *Solo3;
private:
  inline void cb_Solo3_i(Fl_Button*, void*);
  static void cb_Solo3(Fl_Button*, void*);
public:
  Fl_Button *More3;
private:
  inline void cb_More3_i(Fl_Button*, void*);
  static void cb_More3(Fl_Button*, void*);
public:
  Fl_Box *DP3;
  Fl_Counter *P3;
private:
  inline void cb_P3_i(Fl_Counter*, void*);
  static void cb_P3(Fl_Counter*, void*);
public:
  Fl_Group *Mix4;
  MiDial *Pan4;
private:
  inline void cb_Pan4_i(MiDial*, void*);
  static void cb_Pan4(MiDial*, void*);
public:
  MiDial *Reverb4;
private:
  inline void cb_Reverb4_i(MiDial*, void*);
  static void cb_Reverb4(MiDial*, void*);
public:
  MiDial *Chorus4;
private:
  inline void cb_Chorus4_i(MiDial*, void*);
  static void cb_Chorus4(MiDial*, void*);
public:
  MiSlider *Vol4;
private:
  inline void cb_Vol4_i(MiSlider*, void*);
  static void cb_Vol4(MiSlider*, void*);
public:
  Fl_Button *On4;
private:
  inline void cb_On4_i(Fl_Button*, void*);
  static void cb_On4(Fl_Button*, void*);
public:
  Fl_Button *Solo4;
private:
  inline void cb_Solo4_i(Fl_Button*, void*);
  static void cb_Solo4(Fl_Button*, void*);
public:
  Fl_Button *More4;
private:
  inline void cb_More4_i(Fl_Button*, void*);
  static void cb_More4(Fl_Button*, void*);
public:
  Fl_Box *DP4;
  Fl_Counter *P4;
private:
  inline void cb_P4_i(Fl_Counter*, void*);
  static void cb_P4(Fl_Counter*, void*);
public:
  Fl_Group *Mix9;
  MiDial *Pan9;
private:
  inline void cb_Pan9_i(MiDial*, void*);
  static void cb_Pan9(MiDial*, void*);
public:
  MiDial *Reverb9;
private:
  inline void cb_Reverb9_i(MiDial*, void*);
  static void cb_Reverb9(MiDial*, void*);
public:
  MiDial *Chorus9;
private:
  inline void cb_Chorus9_i(MiDial*, void*);
  static void cb_Chorus9(MiDial*, void*);
public:
  MiSlider *Vol9;
private:
  inline void cb_Vol9_i(MiSlider*, void*);
  static void cb_Vol9(MiSlider*, void*);
public:
  Fl_Button *On9;
private:
  inline void cb_On9_i(Fl_Button*, void*);
  static void cb_On9(Fl_Button*, void*);
public:
  Fl_Button *Solo9;
private:
  inline void cb_Solo9_i(Fl_Button*, void*);
  static void cb_Solo9(Fl_Button*, void*);
public:
  Fl_Button *More9;
private:
  inline void cb_More9_i(Fl_Button*, void*);
  static void cb_More9(Fl_Button*, void*);
public:
  Fl_Box *DP9;
  Fl_Group *VumCanal9;
  Fl_Counter *P9;
private:
  inline void cb_P9_i(Fl_Counter*, void*);
  static void cb_P9(Fl_Counter*, void*);
public:
  Fl_Group *Mix10;
  MiDial *Pan10;
private:
  inline void cb_Pan10_i(MiDial*, void*);
  static void cb_Pan10(MiDial*, void*);
public:
  MiDial *Reverb10;
private:
  inline void cb_Reverb10_i(MiDial*, void*);
  static void cb_Reverb10(MiDial*, void*);
public:
  MiDial *Chorus10;
private:
  inline void cb_Chorus10_i(MiDial*, void*);
  static void cb_Chorus10(MiDial*, void*);
public:
  MiSlider *Vol10;
private:
  inline void cb_Vol10_i(MiSlider*, void*);
  static void cb_Vol10(MiSlider*, void*);
public:
  Fl_Button *On10;
private:
  inline void cb_On10_i(Fl_Button*, void*);
  static void cb_On10(Fl_Button*, void*);
public:
  Fl_Button *Solo10;
private:
  inline void cb_Solo10_i(Fl_Button*, void*);
  static void cb_Solo10(Fl_Button*, void*);
public:
  Fl_Button *More10;
private:
  inline void cb_More10_i(Fl_Button*, void*);
  static void cb_More10(Fl_Button*, void*);
public:
  Fl_Box *DP10;
  Fl_Group *VumCanal10;
  Fl_Counter *P10;
private:
  inline void cb_P10_i(Fl_Counter*, void*);
  static void cb_P10(Fl_Counter*, void*);
public:
  Fl_Group *Mix11;
  MiDial *Pan11;
private:
  inline void cb_Pan11_i(MiDial*, void*);
  static void cb_Pan11(MiDial*, void*);
public:
  MiDial *Reverb11;
private:
  inline void cb_Reverb11_i(MiDial*, void*);
  static void cb_Reverb11(MiDial*, void*);
public:
  MiDial *Chorus11;
private:
  inline void cb_Chorus11_i(MiDial*, void*);
  static void cb_Chorus11(MiDial*, void*);
public:
  MiSlider *Vol11;
private:
  inline void cb_Vol11_i(MiSlider*, void*);
  static void cb_Vol11(MiSlider*, void*);
public:
  Fl_Button *On11;
private:
  inline void cb_On11_i(Fl_Button*, void*);
  static void cb_On11(Fl_Button*, void*);
public:
  Fl_Button *Solo11;
private:
  inline void cb_Solo11_i(Fl_Button*, void*);
  static void cb_Solo11(Fl_Button*, void*);
public:
  Fl_Button *More11;
private:
  inline void cb_More11_i(Fl_Button*, void*);
  static void cb_More11(Fl_Button*, void*);
public:
  Fl_Box *DP11;
  Fl_Group *VumCanal11;
  Fl_Counter *P11;
private:
  inline void cb_P11_i(Fl_Counter*, void*);
  static void cb_P11(Fl_Counter*, void*);
public:
  Fl_Group *Mix12;
  MiDial *Pan12;
private:
  inline void cb_Pan12_i(MiDial*, void*);
  static void cb_Pan12(MiDial*, void*);
public:
  MiDial *Reverb12;
private:
  inline void cb_Reverb12_i(MiDial*, void*);
  static void cb_Reverb12(MiDial*, void*);
public:
  MiDial *Chorus12;
private:
  inline void cb_Chorus12_i(MiDial*, void*);
  static void cb_Chorus12(MiDial*, void*);
public:
  MiSlider *Vol12;
private:
  inline void cb_Vol12_i(MiSlider*, void*);
  static void cb_Vol12(MiSlider*, void*);
public:
  Fl_Button *On12;
private:
  inline void cb_On12_i(Fl_Button*, void*);
  static void cb_On12(Fl_Button*, void*);
public:
  Fl_Button *Solo12;
private:
  inline void cb_Solo12_i(Fl_Button*, void*);
  static void cb_Solo12(Fl_Button*, void*);
public:
  Fl_Button *More12;
private:
  inline void cb_More12_i(Fl_Button*, void*);
  static void cb_More12(Fl_Button*, void*);
public:
  Fl_Box *DP12;
  Fl_Group *VumCanal12;
  Fl_Counter *P12;
private:
  inline void cb_P12_i(Fl_Counter*, void*);
  static void cb_P12(Fl_Counter*, void*);
public:
  Fl_Group *Mix13;
  MiDial *Pan13;
private:
  inline void cb_Pan13_i(MiDial*, void*);
  static void cb_Pan13(MiDial*, void*);
public:
  MiDial *Reverb13;
private:
  inline void cb_Reverb13_i(MiDial*, void*);
  static void cb_Reverb13(MiDial*, void*);
public:
  MiDial *Chorus13;
private:
  inline void cb_Chorus13_i(MiDial*, void*);
  static void cb_Chorus13(MiDial*, void*);
public:
  MiSlider *Vol13;
private:
  inline void cb_Vol13_i(MiSlider*, void*);
  static void cb_Vol13(MiSlider*, void*);
public:
  Fl_Button *On13;
private:
  inline void cb_On13_i(Fl_Button*, void*);
  static void cb_On13(Fl_Button*, void*);
public:
  Fl_Button *Solo13;
private:
  inline void cb_Solo13_i(Fl_Button*, void*);
  static void cb_Solo13(Fl_Button*, void*);
public:
  Fl_Button *More13;
private:
  inline void cb_More13_i(Fl_Button*, void*);
  static void cb_More13(Fl_Button*, void*);
public:
  Fl_Box *DP13;
  Fl_Group *VumCanal13;
  Fl_Counter *P13;
private:
  inline void cb_P13_i(Fl_Counter*, void*);
  static void cb_P13(Fl_Counter*, void*);
public:
  Fl_Group *Mix14;
  MiDial *Pan14;
private:
  inline void cb_Pan14_i(MiDial*, void*);
  static void cb_Pan14(MiDial*, void*);
public:
  MiDial *Reverb14;
private:
  inline void cb_Reverb14_i(MiDial*, void*);
  static void cb_Reverb14(MiDial*, void*);
public:
  MiDial *Chorus14;
private:
  inline void cb_Chorus14_i(MiDial*, void*);
  static void cb_Chorus14(MiDial*, void*);
public:
  MiSlider *Vol14;
private:
  inline void cb_Vol14_i(MiSlider*, void*);
  static void cb_Vol14(MiSlider*, void*);
public:
  Fl_Button *On14;
private:
  inline void cb_On14_i(Fl_Button*, void*);
  static void cb_On14(Fl_Button*, void*);
public:
  Fl_Button *Solo14;
private:
  inline void cb_Solo14_i(Fl_Button*, void*);
  static void cb_Solo14(Fl_Button*, void*);
public:
  Fl_Button *More14;
private:
  inline void cb_More14_i(Fl_Button*, void*);
  static void cb_More14(Fl_Button*, void*);
public:
  Fl_Box *DP14;
  Fl_Group *VumCanal14;
  Fl_Counter *P14;
private:
  inline void cb_P14_i(Fl_Counter*, void*);
  static void cb_P14(Fl_Counter*, void*);
public:
  Fl_Group *Mix15;
  MiDial *Pan15;
private:
  inline void cb_Pan15_i(MiDial*, void*);
  static void cb_Pan15(MiDial*, void*);
public:
  MiDial *Reverb15;
private:
  inline void cb_Reverb15_i(MiDial*, void*);
  static void cb_Reverb15(MiDial*, void*);
public:
  MiDial *Chorus15;
private:
  inline void cb_Chorus15_i(MiDial*, void*);
  static void cb_Chorus15(MiDial*, void*);
public:
  MiSlider *Vol15;
private:
  inline void cb_Vol15_i(MiSlider*, void*);
  static void cb_Vol15(MiSlider*, void*);
public:
  Fl_Button *On15;
private:
  inline void cb_On15_i(Fl_Button*, void*);
  static void cb_On15(Fl_Button*, void*);
public:
  Fl_Button *Solo15;
private:
  inline void cb_Solo15_i(Fl_Button*, void*);
  static void cb_Solo15(Fl_Button*, void*);
public:
  Fl_Button *More15;
private:
  inline void cb_More15_i(Fl_Button*, void*);
  static void cb_More15(Fl_Button*, void*);
public:
  Fl_Box *DP15;
  Fl_Group *VumCanal15;
  Fl_Counter *P15;
private:
  inline void cb_P15_i(Fl_Counter*, void*);
  static void cb_P15(Fl_Counter*, void*);
public:
  Fl_Menu_Bar *Menu;
  static unsigned char menu_Menu_i18n_done;
  static Fl_Menu_Item menu_Menu[];
  static Fl_Menu_Item *File;
  static Fl_Menu_Item *NewSound;
private:
  inline void cb_NewSound_i(Fl_Menu_*, void*);
  static void cb_NewSound(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *LoadSounds;
private:
  inline void cb_LoadSounds_i(Fl_Menu_*, void*);
  static void cb_LoadSounds(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *SaveSounds;
private:
  inline void cb_SaveSounds_i(Fl_Menu_*, void*);
  static void cb_SaveSounds(Fl_Menu_*, void*);
  inline void cb_Delete_i(Fl_Menu_*, void*);
  static void cb_Delete(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *LoadStyles;
private:
  inline void cb_LoadStyles_i(Fl_Menu_*, void*);
  static void cb_LoadStyles(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *SaveStyles;
private:
  inline void cb_SaveStyles_i(Fl_Menu_*, void*);
  static void cb_SaveStyles(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *DelStyle;
private:
  inline void cb_DelStyle_i(Fl_Menu_*, void*);
  static void cb_DelStyle(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *ImportSty;
private:
  inline void cb_ImportSty_i(Fl_Menu_*, void*);
  static void cb_ImportSty(Fl_Menu_*, void*);
  inline void cb_Load_i(Fl_Menu_*, void*);
  static void cb_Load(Fl_Menu_*, void*);
  inline void cb_Save_i(Fl_Menu_*, void*);
  static void cb_Save(Fl_Menu_*, void*);
  inline void cb_New_i(Fl_Menu_*, void*);
  static void cb_New(Fl_Menu_*, void*);
  inline void cb_Read_i(Fl_Menu_*, void*);
  static void cb_Read(Fl_Menu_*, void*);
  inline void cb_Save1_i(Fl_Menu_*, void*);
  static void cb_Save1(Fl_Menu_*, void*);
  inline void cb_Delete1_i(Fl_Menu_*, void*);
  static void cb_Delete1(Fl_Menu_*, void*);
  inline void cb_Load1_i(Fl_Menu_*, void*);
  static void cb_Load1(Fl_Menu_*, void*);
  inline void cb_Load2_i(Fl_Menu_*, void*);
  static void cb_Load2(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *Exit;
private:
  inline void cb_Exit_i(Fl_Menu_*, void*);
  static void cb_Exit(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *sEdit;
  static Fl_Menu_Item *EPattern;
private:
  inline void cb_EPattern_i(Fl_Menu_*, void*);
  static void cb_EPattern(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *MixerE;
private:
  inline void cb_MixerE_i(Fl_Menu_*, void*);
  static void cb_MixerE(Fl_Menu_*, void*);
  inline void cb_Drum_i(Fl_Menu_*, void*);
  static void cb_Drum(Fl_Menu_*, void*);
  inline void cb_Pattern_i(Fl_Menu_*, void*);
  static void cb_Pattern(Fl_Menu_*, void*);
  inline void cb_Style_i(Fl_Menu_*, void*);
  static void cb_Style(Fl_Menu_*, void*);
  inline void cb_Preferences_i(Fl_Menu_*, void*);
  static void cb_Preferences(Fl_Menu_*, void*);
public:
  static Fl_Menu_Item *ElSeq;
private:
  inline void cb_ElSeq_i(Fl_Menu_*, void*);
  static void cb_ElSeq(Fl_Menu_*, void*);
  inline void cb_Help_i(Fl_Menu_*, void*);
  static void cb_Help(Fl_Menu_*, void*);
  inline void cb_About_i(Fl_Menu_*, void*);
  static void cb_About(Fl_Menu_*, void*);
public:
  Fl_Group *ElBueno;
  Fl_Dial *RTempo;
private:
  inline void cb_RTempo_i(Fl_Dial*, void*);
  static void cb_RTempo(Fl_Dial*, void*);
public:
  Fl_Counter *CTempo;
private:
  inline void cb_CTempo_i(Fl_Counter*, void*);
  static void cb_CTempo(Fl_Counter*, void*);
public:
  Fl_Browser *ListaStyles;
private:
  inline void cb_ListaStyles_i(Fl_Browser*, void*);
  static void cb_ListaStyles(Fl_Browser*, void*);
public:
  Fl_Browser *ListaSounds;
private:
  inline void cb_ListaSounds_i(Fl_Browser*, void*);
  static void cb_ListaSounds(Fl_Browser*, void*);
public:
  Fl_Button *STST;
private:
  inline void cb_STST_i(Fl_Button*, void*);
  static void cb_STST(Fl_Button*, void*);
public:
  Fl_Box *DCompas;
private:
  inline void cb_DCompas_i(Fl_Box*, void*);
  static void cb_DCompas(Fl_Box*, void*);
public:
  Fl_Group *marker;
  Fl_Box *N1;
  Fl_Box *N2;
  Fl_Box *N3;
  Fl_Box *N4;
  Fl_Button *Sso;
private:
  inline void cb_Sso_i(Fl_Button*, void*);
  static void cb_Sso(Fl_Button*, void*);
public:
  Fl_Button *Sst;
private:
  inline void cb_Sst_i(Fl_Button*, void*);
  static void cb_Sst(Fl_Button*, void*);
public:
  Fl_Slider *DMidi;
  Fl_Box *Dsel;
  MiSlider *VolKeyb;
private:
  inline void cb_VolKeyb_i(MiSlider*, void*);
  static void cb_VolKeyb(MiSlider*, void*);
public:
  Fl_Counter *CTranspose;
private:
  inline void cb_CTranspose_i(Fl_Counter*, void*);
  static void cb_CTranspose(Fl_Counter*, void*);
public:
  Fl_Counter *CSplit;
private:
  inline void cb_CSplit_i(Fl_Counter*, void*);
  static void cb_CSplit(Fl_Counter*, void*);
public:
  MiSlider *VolAcc;
private:
  inline void cb_VolAcc_i(MiSlider*, void*);
  static void cb_VolAcc(MiSlider*, void*);
public:
  Fl_Box *DSplit;
  Fl_Choice *SelectType;
private:
  inline void cb_SelectType_i(Fl_Choice*, void*);
  static void cb_SelectType(Fl_Choice*, void*);
public:
  Fl_Button *FGBM;
private:
  inline void cb_FGBM_i(Fl_Button*, void*);
  static void cb_FGBM(Fl_Button*, void*);
public:
  Fl_Button *FG;
private:
  inline void cb_FG_i(Fl_Button*, void*);
  static void cb_FG(Fl_Button*, void*);
public:
  Fl_Button *STSync;
private:
  inline void cb_STSync_i(Fl_Button*, void*);
  static void cb_STSync(Fl_Button*, void*);
public:
  Fl_Output *DMidiInDevice;
  Fl_Output *DMidiOutDevice;
  Fl_Browser *BroReg;
private:
  inline void cb_BroReg_i(Fl_Browser*, void*);
  static void cb_BroReg(Fl_Browser*, void*);
public:
  Fl_Button *CopyMixer;
private:
  inline void cb_CopyMixer_i(Fl_Button*, void*);
  static void cb_CopyMixer(Fl_Button*, void*);
public:
  Fl_Button *DrumMixer;
private:
  inline void cb_DrumMixer_i(Fl_Button*, void*);
  static void cb_DrumMixer(Fl_Button*, void*);
public:
  Fl_Button *EditPattern;
private:
  inline void cb_EditPattern_i(Fl_Button*, void*);
  static void cb_EditPattern(Fl_Button*, void*);
public:
  Fl_Group *VariGroup;
  Fl_Counter *Varicounter;
private:
  inline void cb_Varicounter_i(Fl_Counter*, void*);
  static void cb_Varicounter(Fl_Counter*, void*);
public:
  Fl_Box *DInfoControl;
private:
  inline void cb_DInfoControl_i(Fl_Box*, void*);
  static void cb_DInfoControl(Fl_Box*, void*);
public:
  Fl_Group *Botones;
  Fl_Button *bMainA;
private:
  inline void cb_bMainA_i(Fl_Button*, void*);
  static void cb_bMainA(Fl_Button*, void*);
public:
  Fl_Button *bMainB;
private:
  inline void cb_bMainB_i(Fl_Button*, void*);
  static void cb_bMainB(Fl_Button*, void*);
public:
  Fl_Button *bMainC;
private:
  inline void cb_bMainC_i(Fl_Button*, void*);
  static void cb_bMainC(Fl_Button*, void*);
public:
  Fl_Button *bMainD;
private:
  inline void cb_bMainD_i(Fl_Button*, void*);
  static void cb_bMainD(Fl_Button*, void*);
public:
  Fl_Button *bEndingA;
private:
  inline void cb_bEndingA_i(Fl_Button*, void*);
  static void cb_bEndingA(Fl_Button*, void*);
public:
  Fl_Button *bEndingB;
private:
  inline void cb_bEndingB_i(Fl_Button*, void*);
  static void cb_bEndingB(Fl_Button*, void*);
public:
  Fl_Button *bEndingC;
private:
  inline void cb_bEndingC_i(Fl_Button*, void*);
  static void cb_bEndingC(Fl_Button*, void*);
public:
  Fl_Button *bIntroA;
private:
  inline void cb_bIntroA_i(Fl_Button*, void*);
  static void cb_bIntroA(Fl_Button*, void*);
public:
  Fl_Button *bIntroB;
private:
  inline void cb_bIntroB_i(Fl_Button*, void*);
  static void cb_bIntroB(Fl_Button*, void*);
public:
  Fl_Button *bIntroC;
private:
  inline void cb_bIntroC_i(Fl_Button*, void*);
  static void cb_bIntroC(Fl_Button*, void*);
public:
  Fl_Button *bFillAA;
private:
  inline void cb_bFillAA_i(Fl_Button*, void*);
  static void cb_bFillAA(Fl_Button*, void*);
public:
  Fl_Button *bFillAB;
private:
  inline void cb_bFillAB_i(Fl_Button*, void*);
  static void cb_bFillAB(Fl_Button*, void*);
public:
  Fl_Button *bFillBA;
private:
  inline void cb_bFillBA_i(Fl_Button*, void*);
  static void cb_bFillBA(Fl_Button*, void*);
public:
  Fl_Button *bFillBB;
private:
  inline void cb_bFillBB_i(Fl_Button*, void*);
  static void cb_bFillBB(Fl_Button*, void*);
public:
  Fl_Button *bFillCC;
private:
  inline void cb_bFillCC_i(Fl_Button*, void*);
  static void cb_bFillCC(Fl_Button*, void*);
public:
  Fl_Button *bFillDD;
private:
  inline void cb_bFillDD_i(Fl_Button*, void*);
  static void cb_bFillDD(Fl_Button*, void*);
public:
  Fl_Button *AutoFill;
private:
  inline void cb_AutoFill_i(Fl_Button*, void*);
  static void cb_AutoFill(Fl_Button*, void*);
public:
  Fl_Box *VName;
  Fl_Box *VChord;
  Fl_Box *VSound;
  Fl_Box *VStyle;
  stygmorgan(int argc, char **argv,RMGMO *rmgmo_);
  static void tick(void* v);
  Fl_Double_Window* MoreParams(int i);
  Fl_Double_Window *More;
private:
  inline void cb_More_i(Fl_Double_Window*, void*);
  static void cb_More(Fl_Double_Window*, void*);
public:
  Fl_Counter *Octave;
private:
  inline void cb_Octave_i(Fl_Counter*, void*);
  static void cb_Octave(Fl_Counter*, void*);
public:
  Fl_Counter *Transpose;
private:
  inline void cb_Transpose_i(Fl_Counter*, void*);
  static void cb_Transpose(Fl_Counter*, void*);
public:
  Fl_Counter *bMSB;
private:
  inline void cb_bMSB_i(Fl_Counter*, void*);
  static void cb_bMSB(Fl_Counter*, void*);
public:
  Fl_Counter *bLSB;
private:
  inline void cb_bLSB_i(Fl_Counter*, void*);
  static void cb_bLSB(Fl_Counter*, void*);
  inline void cb_Ok_i(Fl_Button*, void*);
  static void cb_Ok(Fl_Button*, void*);
public:
  Fl_Box *LMore;
  void ponmix();
  void PonSolo(int mcanal);
  void ActuaOnOff();
  void QuitaSolo();
  void ActuaSolo();
  void Actua_More();
  void pontempo();
  void Leer_Styles(int num);
  void EnAp();
  void ActuaBoton();
  void CVari(int boton,int vari);
  void buscala();
  void Leer_Sounds();
  void ponmixsound();
  void ActuaOnOffP();
  void apaga();
  void PCVari(int boton,int vari);
  void ActuaDsel();
  void ActuVolp();
  void ActuVols();
  Fl_Double_Window* CreaCMixer();
  Fl_Double_Window *CMixer;
private:
  inline void cb_CMixer_i(Fl_Double_Window*, void*);
  static void cb_CMixer(Fl_Double_Window*, void*);
  inline void cb_Ok1_i(Fl_Button*, void*);
  static void cb_Ok1(Fl_Button*, void*);
public:
  Fl_Button *CCCancel;
private:
  inline void cb_CCCancel_i(Fl_Button*, void*);
  static void cb_CCCancel(Fl_Button*, void*);
  inline void cb_Select_i(Fl_Button*, void*);
  static void cb_Select(Fl_Button*, void*);
public:
  void SetSound(int num);
  void coord();
  void SaveStylesFunction();
  void GuardaPref();
  void Leer_Registrations();
  void SetRegistration(int num);
  void ActuaVarios();
  void PonLaReg();
  void semabplay();
  void sema();
  void MoreSolo();
  void ActuaMidDevices();
  void labelwin(int i);
  void AcutaLeds(int ifun);
  void FunciLeds(int ifun);
  void ActuaBanco(int can);
  void put_icon(Fl_Window* window);
  void poninfo(int track, int control, int value);
  void ActuaDP();
  void AjustaValores(int value);
  Fl_Double_Window* My_message(const char *text);
  Fl_Double_Window *Message_Win;
private:
  inline void cb_Message_Win_i(Fl_Double_Window*, void*);
  static void cb_Message_Win(Fl_Double_Window*, void*);
  inline void cb_Close_i(Fl_Button*, void*);
  static void cb_Close(Fl_Button*, void*);
public:
  Fl_Box *Caja_Message;
};
#endif
