#ifndef _PRINTING_H_
#define _PRINTING_H_
#include "variants.h"
#include "stdbool.h"
#include "ff.h"
#include "includes.h"

typedef struct
{
  FIL     file;

  u32     time; // Printed time in sec
  u32     size; // Gcode file total size
  u32     cur; // Gcode has printed file size
  u8      progress;
  bool    printing; // 1 means printing, 0 means idle
  bool    pause; // 1 means paused
  bool    m0_pause; // pause triggered through M0/M1 gcode
  bool    runout; // 1: runout in printing, 0: idle
}PRINTING;

typedef struct
{
  bool    isRelativeCoor;
  bool    isRelativeExtrude;
  COORDINATE  coordinate; 
}PrinterState;

void exitPrinting(void);
void endPrinting(void);
void completePrinting(void);
void abortPrinting(void);

void setM0Pause(bool m0_pause);
bool setPrintPause(bool is_pause,bool is_m0pause, bool M600);

bool isPrinting(void);
bool isPause(void);
bool isM0_Pause(void);
void setPrintingTime(u32 RTtime);

void setPrintSize(u32 size);
void setPrintCur(u32 cur);
u32 getPrintSize(void);
u32 getPrintCur(void);
bool getPrintRunout(void);
void setPrintRunout(bool runout);

u8   getPrintProgress(void);
u32  getPrintTime(void);

void printSetUpdateWaiting(bool isWaiting);

void getGcodeFromFile(void);

void menuBeforePrinting(void);
void menuPrinting(void);
void menuStopPrinting(void);
void menuShutDown(void);

void printingDrawPage(void);
void reDrawProgress(int icon_pos);
void reValueNozzle(int icon_pos);
void reValueBed(int icon_pos);
void reDrawTime(int icon_pos);
void reDrawLayer(int icon_pos);

void loopCheckPrinting(void);

void saveCurrentState();
PrinterState printerStateBeforePause;

//COORDINATE coordinateTmp;
//bool isCoorRelative;
//bool isExtrudeRelative;

#endif
