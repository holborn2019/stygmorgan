// generated by Fast Light User Interface Designer (fluid) version 1.0304

#ifndef stygmdmui_h
#define stygmdmui_h
#include <FL/Fl.H>
#include <FL/x.H>
#include <Fl/Fl_Scroll.H>
#include <Fl/Fl_Box.H>
#include <FL/Fl_Value_Slider.H>
#include <Fl/Fl_Preferences.H>
#include "stygmorgan.h"

class DSlider : public Fl_Value_Slider {
public:
  DSlider(int x,int y, int w, int h, const char *label=0);
  int handle(int event);
};
#include <FL/Fl_Window.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Scroll.H>

class Drummixer {
  RMGMO *rmgmo; 
public:
  Drummixer(RMGMO *rmgmo_);
  static void tick(void* v);
  Fl_Window* make_window();
  Fl_Window *drummixerwin;
private:
  inline void cb_drummixerwin_i(Fl_Window*, void*);
  static void cb_drummixerwin(Fl_Window*, void*);
public:
  Fl_Box *Caso;
private:
  inline void cb_Caso_i(Fl_Box*, void*);
  static void cb_Caso(Fl_Box*, void*);
public:
  Fl_Box *CasoV;
private:
  inline void cb_Apply_i(Fl_Button*, void*);
  static void cb_Apply(Fl_Button*, void*);
  inline void cb_Cancel_i(Fl_Button*, void*);
  static void cb_Cancel(Fl_Button*, void*);
  inline void cb_Ok_i(Fl_Button*, void*);
  static void cb_Ok(Fl_Button*, void*);
  inline void cb_Reset_i(Fl_Button*, void*);
  static void cb_Reset(Fl_Button*, void*);
public:
  Fl_Scroll *Scr;
  void labelwin();
  void GuardaPrefs();
  static void dm_call1(Fl_Value_Slider* o, void* v);
  void dm_call1_i(Fl_Value_Slider* o, void*);
  void ReadPattern();
  void GeneraScroll();
  void MiraLucecitas();
  int BuscaLucecita(int luz);
  void PonLucecitas(int luz);
  void QuitaLucecitas(int luz);
  void PonCambiosPoce();
  void ResetSliders();
};
#endif
