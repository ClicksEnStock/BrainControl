
#include "Common.h"

void Extension::StartRecording(int portNum)
{
	char number[3];
	_snprintf_s(comPortName, _countof(comPortName),_countof(comPortName),"\\\\.\\COM");
	_snprintf_s(number, _countof(number),_countof(number),"%d",portNum);
	strncat (comPortName, number, 3);
	errCode = TG_Connect( connectionId,comPortName,baudRate,TG_STREAM_PACKETS );
	//errCode = TG_Connect( connectionId,comPortName,TG_BAUD_57600,TG_STREAM_PACKETS );
	if(errCode==-1)
	{
		_snwprintf_s(lastError, _countof(lastError),_countof(lastError),ErrorS[wrongConnectionId]);
	}
	else if(errCode==-2)
	{
		_snwprintf_s(lastError, _countof(lastError),_countof(lastError),ErrorS[invalidCOMPort]);
	}
	else if(errCode==-3)
	{
		_snwprintf_s(lastError, _countof(lastError),_countof(lastError),ErrorS[invalidBaudRate]);
	}
	else if(errCode==-4)
	{
		_snwprintf_s(lastError, _countof(lastError),_countof(lastError),ErrorS[invalidDataFormat]);
	}
	else if(errCode==0)
	{
		errCode = TG_EnableAutoRead(connectionId,1);
		if(errCode==-1)
		{
			_snwprintf_s(lastError, _countof(lastError),_countof(lastError),ErrorS[wrongConnectionId]);
		}
		else if(errCode==-2)
		{
			_snwprintf_s(lastError, _countof(lastError),_countof(lastError),ErrorS[autoReadingError]);
		}
		else if(errCode==0)
		{
			isConnected=true;
		}
	}
}

void Extension::StopRecording()
{
	TG_Disconnect( connectionId);
}

//void Extension::LogStream(char* fileName)
//{
//	errCode = TG_SetStreamLog( connectionId, fileName );
//	if(errCode==-1)
//	{
//		_snwprintf_s(lastError, _countof(lastError),_countof(lastError),ErrorS[wrongConnectionId]);
//	}
//	else if(errCode==-2)
//	{
//		_snwprintf_s(lastError, _countof(lastError),_countof(lastError),ErrorS[wrongStreamLogPath]);
//	}
//}
//
//void Extension::LogData(char* fileName)
//{
//	errCode = TG_SetDataLog( connectionId, fileName );
//	if(errCode==-1)
//	{
//		_snwprintf_s(lastError, _countof(lastError),_countof(lastError),ErrorS[wrongConnectionId]);
//	}
//	else if(errCode==-2)
//	{
//		_snwprintf_s(lastError, _countof(lastError),_countof(lastError),ErrorS[streamLogPathNotSpecified]);
//	}
//}
