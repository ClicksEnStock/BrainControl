#pragma once

// #define TGFEXT       // TGF2, MMF2, MMF2 Dev
   #define MMFEXT       // MMF2, MMF2 Dev
// #define PROEXT       // MMF2 Dev only

#include    "Edif.h"
#include	"Resource.h"

#include	<thinkgear.h>

// edPtr : Used at edittime and saved in the MFA/CCN/EXE files

const int ERRORSIZE = 256;

enum ErrorN
{
	noError,
	wrongConnectionId,
	invalidCOMPort,
	invalidBaudRate,
	invalidDataFormat,
	autoReadingError
};

static TCHAR* ErrorS[50] = {
	_T("[00] No Error"),
	_T("[01] Connection Id is invalid."),
	_T("[02] Invalid COM Port."),
	_T("[03] Invalid Baud Rate."),
	_T("[04] Invalid Data Format."),
	_T("[05] Cannot start recording.")
};

static int BaudRateValues[6] = {TG_BAUD_1200,TG_BAUD_2400,TG_BAUD_4800,TG_BAUD_9600,TG_BAUD_57600,TG_BAUD_115200};

struct EDITDATA
{
	// Header - required
	extHeader		eHeader;

	// Object's data
	int baudRateId;

};

#include "Extension.h"
