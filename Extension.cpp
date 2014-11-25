
#include "Common.h"


///
/// EXTENSION CONSTRUCTOR/DESTRUCTOR
///

Extension::Extension(LPRDATA _rdPtr, LPEDATA edPtr, fpcob cobPtr)
    : rdPtr(_rdPtr), rhPtr(_rdPtr->rHo.hoAdRunHeader), Runtime(_rdPtr)
{
    /*
        Link all your action/condition/expression functions to their IDs to match the
        IDs in the JSON here
    */

	LinkAction(0, StartRecording);
	LinkAction(1, StopRecording);
	/*LinkAction(2, LogStream);
	LinkAction(3, LogData);*/

    LinkCondition(0, OnError);
	LinkCondition(1, IsConnected);

	LinkExpression(0, LastError);
	LinkExpression(1, Attention);
	LinkExpression(2, Meditation);
	LinkExpression(3, Delta);
	LinkExpression(4, Theta);
	LinkExpression(5, Alpha1);
	LinkExpression(6, Alpha2);
	LinkExpression(7, Beta1);
	LinkExpression(8, Beta2);
	LinkExpression(9, Gamma1);
	LinkExpression(10,Gamma2);
	LinkExpression(11,PoorSignal);
	LinkExpression(12,DllVersion);


    /*
        This is where you'd do anything you'd do in CreateRunObject in the original SDK

        It's the only place you'll get access to edPtr at runtime, so you should transfer
        anything from edPtr to the extension class here.
    
    */
	dllVersion=0;
	connectionId=0;
	errCode=0;
	_snprintf_s(comPortName, _countof(comPortName),_countof(comPortName),"\\\\.\\COM");
	_snwprintf_s(lastError, _countof(lastError),ERRORSIZE,ErrorS[noError]);
	_snwprintf_s(errorTemp, _countof(errorTemp),ERRORSIZE,ErrorS[noError]);
	isConnected = false;
	baudRate = BaudRateValues[edPtr->baudRateId];

	dllVersion = TG_GetDriverVersion();
	connectionId = TG_GetNewConnectionId();
}

Extension::~Extension()
{
    /*
        This is where you'd do anything you'd do in DestroyRunObject in the original SDK.
        (except calling destructors and other such atrocities, because that's automatic in Edif)
    */
	TG_FreeConnection( connectionId );

}


short Extension::Handle()
{
    /*
       If your extension will draw to the MMF window you should first 
       check if anything about its display has changed :

           if (rdPtr->roc.rcChanged)
              return REFLAG_DISPLAY;
           else
              return 0;

       You will also need to make sure you change this flag yourself 
       to 1 whenever you want to redraw your object
     
       If your extension won't draw to the window, but it still needs 
       to do something every MMF loop use :

            return 0;

       If you don't need to do something every loop, use :

            return REFLAG_ONESHOT;

       This doesn't mean this function can never run again. If you want MMF
       to handle your object again (causing this code to run) use this function:

            Runtime.Rehandle();

       At the end of the loop this code will run

    */

	// Will not be called next loop	
	return REFLAG_ONESHOT;
}


short Extension::Display()
{
    /*
       If you return REFLAG_DISPLAY in Handle() this routine will run.
    */

    // Ok
    return 0;
}

short Extension::Pause()
{

    // Ok
    return 0;
}

short Extension::Continue()
{

    // Ok
    return 0;
}

bool Extension::Save(HANDLE File)
{
	bool OK = false;

    #ifndef VITALIZE

	    // Save the object's data here

	    OK = true;

    #endif

	return OK;
}

bool Extension::Load(HANDLE File)
{
	bool OK = false;

    #ifndef VITALIZE

	    // Load the object's data here

	    OK = true;

    #endif

	return OK;
}


// These are called if there's no function linked to an ID

void Extension::Action(int ID, LPRDATA rdPtr, long param1, long param2)
{

}

long Extension::Condition(int ID, LPRDATA rdPtr, long param1, long param2)
{

    return false;
}

long Extension::Expression(int ID, LPRDATA rdPtr, long param)
{

    return 0;
}

