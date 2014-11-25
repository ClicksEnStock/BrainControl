
#include "Common.h"

bool Extension::OnError()
{
	return ((wcscmp(lastError,_T("[00] No Error")))!=0);
}

bool Extension::IsConnected()
{
	return isConnected;
}


