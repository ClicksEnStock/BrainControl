
#include "Common.h"

//#define TG_DATA_BATTERY             0
//#define TG_DATA_POOR_SIGNAL         1
//#define TG_DATA_ATTENTION           2
//#define TG_DATA_MEDITATION          3
//#define TG_DATA_RAW                 4
//#define TG_DATA_DELTA               5
//#define TG_DATA_THETA               6
//#define TG_DATA_ALPHA1              7
//#define TG_DATA_ALPHA2              8
//#define TG_DATA_BETA1               9
//#define TG_DATA_BETA2              10
//#define TG_DATA_GAMMA1             11
//#define TG_DATA_GAMMA2             12
//#define TG_DATA_BLINK_STRENGTH     37

int   Extension::DllVersion()
{
	return dllVersion;
}

float Extension::Attention()
{
	return TG_GetValue(connectionId,TG_DATA_ATTENTION);
}

float Extension::Meditation()
{
	return TG_GetValue(connectionId,TG_DATA_MEDITATION);
}

float Extension::Delta()
{
	return TG_GetValue(connectionId,TG_DATA_DELTA);
}

float Extension::Theta()
{
	return TG_GetValue(connectionId,TG_DATA_THETA);
}

float Extension::Alpha1()
{
	return TG_GetValue(connectionId,TG_DATA_ALPHA1);
}

float Extension::Alpha2()
{
	return TG_GetValue(connectionId,TG_DATA_ALPHA2);
}

float Extension::Beta1()
{
	return TG_GetValue(connectionId,TG_DATA_BETA1);
}

float Extension::Beta2()
{
	return TG_GetValue(connectionId,TG_DATA_BETA2);
}

float Extension::Gamma1()
{
	return TG_GetValue(connectionId,TG_DATA_GAMMA1);
}

float Extension::Gamma2()
{
	return TG_GetValue(connectionId,TG_DATA_GAMMA2);
}

float Extension::PoorSignal()
{
	return TG_GetValue(connectionId,TG_DATA_POOR_SIGNAL);
}

TCHAR* Extension::LastError()
{
    _tcscpy (errorTemp,lastError);
	_snwprintf_s(lastError, _countof(lastError),ERRORSIZE,ErrorS[noError]);
	return  errorTemp;
}