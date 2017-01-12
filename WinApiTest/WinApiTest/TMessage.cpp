#include "stdafx.h"
#include "TMessage.h"


TMessage::TMessage()
{
}


TMessage::~TMessage()
{
}

void TMessage::Do()
{
}

void TMessage::test1()
{
}

void TMessage::sendToTRACEWIN()
{
  static HWND trace_hwnd = 0;
  static int tracewin_sought = FALSE;

  // Establish connection to TRACEWIN:
  //if (!tracewin_sought) {
  //  trace_hwnd = FindWindow(0, "TRACEWIN");
  //  CiderClear();
  //  tracewin_sought = TRUE;
  //}


}


//#define MAKEWORD(a, b)      ((WORD)(((BYTE)(((DWORD_PTR)(a)) & 0xff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & 0xff))) << 8))
//#define MAKELONG(a, b)      ((LONG)(((WORD)(((DWORD_PTR)(a)) & 0xffff)) | ((DWORD)((WORD)(((DWORD_PTR)(b)) & 0xffff))) << 16))
//#define LOWORD(l)           ((WORD)(((DWORD_PTR)(l)) & 0xffff))
//#define HIWORD(l)           ((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff))
//#define LOBYTE(w)           ((BYTE)(((DWORD_PTR)(w)) & 0xff))
//#define HIBYTE(w)           ((BYTE)((((DWORD_PTR)(w)) >> 8) & 0xff))


void CiderClear()
{
//#define ID_COPYDATA_CLEARMSG MAKELONG(MAKEWORD('c','l'),MAKEWORD('e','r'))
//	HWND trace_hwnd=0;
//	COPYDATASTRUCT txt_info;
//
//	// Establish connection to TRACEWIN:
//	if ((trace_hwnd=FindWindow(0, "TRACEWIN"))==0)
//		return;
//
//	txt_info.dwData=ID_COPYDATA_CLEARMSG;
//	txt_info.lpData=0;
//	txt_info.cbData=0;
//
//	// Send message to TRACEWIN:
//	SendMessage(trace_hwnd, WM_COPYDATA, 0, (LPARAM)&txt_info);
}

void CiderPrintf(char *form, ...)
{
#ifdef _WINNT32
  va_list arg_ptr;
  char txt[CIDER_PRINTF_BUFFER_SIZE];

  // Following sends debug output to TRACEWIN.EXE (eee TRACEWIN project in MSDN for info):
#define ID_COPYDATA_TRACEMSG MAKELONG(MAKEWORD('t','w'),MAKEWORD('i','n'))
  COPYDATASTRUCT txt_info;
  static FILE *fp = 0;
  static HWND trace_hwnd = 0;
  static int tracewin_sought = FALSE;

#ifdef FILE_LOGGING
  if (!fp)
    fp = fopen("cider.log", "wb");
#endif

  // Establish connection to TRACEWIN:
  if (!tracewin_sought) {
    trace_hwnd = FindWindow(0, "TRACEWIN");
    CiderClear();
    tracewin_sought = TRUE;
  }
  if ((trace_hwnd == 0) && (fp == 0))
    return;

  CiderPrintfLock();

  // Format the text:
  va_start(arg_ptr, form);
#ifdef INCLUDE_CAESAR	   							// Prefix "C32S:"
  sprintf(txt, "C32S: ");
  vsprintf(&txt[strlen(txt)], form, arg_ptr);
#else
  vsprintf(txt, form, arg_ptr);
#endif
  va_end(arg_ptr);

  // Deal with file logging:
  if (fp)
    fprintf(fp, txt);

  // Deal with tracewin logging:
  if (trace_hwnd) {

    // Build data for TRACEWIN.EXE:
    txt_info.dwData = ID_COPYDATA_TRACEMSG;
    txt_info.lpData = txt;
    txt_info.cbData = (DWORD)StringLength(txt);

    // Send message to TRACEWIN:
    SendMessage(trace_hwnd, WM_COPYDATA, 0, (LPARAM)&txt_info);
  }
  CiderPrintfUnlock();
#endif
}
