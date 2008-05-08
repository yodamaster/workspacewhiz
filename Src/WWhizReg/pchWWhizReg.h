///////////////////////////////////////////////////////////////////////////////
// $Workfile: pchWWhizReg.h $
// $Archive: /WWhizReg/pchWWhizReg.h $
// $Date:: 11/13/00 7:19p  $ $Revision:: 19   $ $Author: Jjensen $
//
// This source file is Copyright 1997-2000 by Joshua C. Jensen.
//
// Unauthorized use of this source file, by modification, copying, or
// distribution is strictly prohibited unless prior consent has
// been given by Joshua C. Jensen.
///////////////////////////////////////////////////////////////////////////////
#pragma once

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#ifndef WINVER
#define WINVER 0x0400
#endif

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

// turns off ATL's hiding of some common and often safely ignored warning messages
#define _ATL_ALL_WARNINGS

#pragma warning( disable : 4244 )
#pragma warning( disable : 4311 )
#pragma warning( disable : 4312 )
#include <afxcmn.h>
#include <afxtempl.h>
#include <atlbase.h>
#include <afxmt.h>
#include <mmsystem.h>
#include "WCollection.h"

using namespace ATL;

#ifdef WWHIZ_VC6

// Developer Studio Object Model
#include <ObjModel\appauto.h>

#endif WWHIZ_VC6

#ifdef WWHIZ_VSNET

#pragma warning( disable : 4278 )
#pragma warning( disable : 4146 )
	//The following #import imports MSO based on it's LIBID
	#import "libid:2DF8D04C-5BFA-101B-BDE5-00AA0044DE52" version("2.2") lcid("0") raw_interfaces_only named_guids

	//The following #import imports DTE based on it's LIBID
	#import "libid:80cc9f66-e7d8-4ddd-85b6-d9e6cd0e93e2" version("7.0") lcid("0") raw_interfaces_only named_guids
#pragma warning( default : 4146 )
#pragma warning( default : 4278 )

#endif WWHIZ_VSNET

// determine number of elements in an array (not bytes)
#ifndef _countof
#define _countof(array) (sizeof(array)/sizeof(array[0]))
#endif _countof

#include <io.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "ObjModelHelper.h"
#include "WWhizInterface3.h"
#include "WWhizReg.h"
#include "resource.h"

extern WWhizInterface* g_wwhizInterface;
extern HINSTANCE g_instance;

//#define USE_EXPIRATION

__forceinline bool HasExpiredHelper()
{
#ifdef USE_EXPIRATION
	CTime timeStart(2003, 05, 22, 00, 00, 00);
	CTime currentTime = CTime::GetCurrentTime();
	CTimeSpan time30Days(30, 0, 0, 0);

	if (timeStart + time30Days < currentTime)
		return true;
	return false;
#else
	return false;
#endif USE_EXPIRATION
}

__forceinline bool HasExpired()
{
#ifdef USE_EXPIRATION
	if (HasExpiredHelper())
	{
		AfxMessageBox("Workspace Whiz 3.0 Build 1014 has expired.  Please go to "
			"http://www.workspacewhiz.com/ to download the latest version.\n");

		return true;
	}

	return false;
#else
	return false;
#endif
}

#define WM_DOREG		(WM_APP + 1)
#define WM_FILLREG		(WM_APP + 2)

