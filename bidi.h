// File: Bidi.h
//
/*	For use with Bidi Reference Implementation
	For more information see the associated file bidi.cpp

	Credits:
	-------
	Written by: Asmus Freytag
	Command line interface by: Rick McGowan
	Verification (v24): Doug Felt

	Disclaimer and legal rights:
	---------------------------
	Copyright (C) 1999-2009, ASMUS, Inc. All Rights Reserved.
	Distributed under the Terms of Use in http://www.unicode.org/copyright.html.

	THIS SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
	OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF THIRD PARTY RIGHTS.
	IN NO EVENT SHALL THE COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE
	BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES,
	OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
	WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
	ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THE SOFTWARE.

	 The files bidi.rc, and resource.h are distributed together with this file and are included 
	 in the above definition of software.
*/
// Copyright (C) 1999-2009, ASMUS, Inc.     All Rights Reserved

#if WINDOWS_UI
	// disable some warnings generated by windows.h
	#pragma warning (disable : 4514 4201)
#endif

#if WINDOWS_UI > 1
   #include "main.h"		// private header, includes Windows.h
   #include "window.h"		// center
   #define DEMO 1			// force demo mode
   #ifdef DEBUG_ENABLED
	   #define DEBUGGING 1	// conditionally enable debug support 
	   #define ASSERT_ENABLED 1
   #else 
	   #define ASSERT_ENABLED 0
   #endif					// for private build
#elif WINDOWS_UI
	#define ASSERT(x)		// suppress ASSERTs for standalone
	#define ASSERT_ENABLED 0
	#include "windows.h"	// standard include file for windows
	#include "windowsx.h"	// extended include file for windows
	#include "resource.h"	// resource defines
 #else
	// commandline version, define printf based ASSERT
	#pragma message("commandline version")
	#include <stdio.h>
	#define ASSERT(x) if (!(x)) fprintf(stdout, "assert failed: %s\n", #x); else ;
	#define ASSERT_ENABLED 1
#endif

// duplicate some windows.h defines for commandline
#ifndef TEXT
#define TCHAR  char
#define LPTSTR char *
#endif

#if WINDOWS_UI==1
LRESULT CALLBACK BidiWndProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam);
#endif

#ifdef _MAIN_H_
BOOL CALLBACK BidiDlgProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam);
#endif

// For convenience of external callers, the following constitute the interface to the actual algorithm. 
// For usage notes and paramter descriptions see the file bidi.cpp
void BidiLines(int baselevel, TCHAR * pszLine, int * pclsLine,
			   int * plevelLine, int cchPara, int fMirror, bool * pbrk = 0);
int BidiParagraph(int &baselevel,  int * types, int * levels, int cch);

