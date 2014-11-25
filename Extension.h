
class Extension
{
public:

    LPRDATA rdPtr;
    LPRH    rhPtr;

    Edif::Runtime Runtime;

    static const int MinimumBuild = 251;
    static const int Version = 1;

    static const int OEFLAGS = 0;
    static const int OEPREFS = 0;
    
    static const int WindowProcPriority = 100;

    Extension(LPRDATA rdPtr, LPEDATA edPtr, fpcob cobPtr);
    ~Extension();


    /*  Add any data you want to store in your extension to this class
        (eg. what you'd normally store in rdPtr)

        Unlike rdPtr, you can store real C++ objects with constructors
        and destructors, without having to call them manually or store
        a pointer.
    */

		char  comPortName[20];
		int   dllVersion;
		int   connectionId;
		int   errCode;
		TCHAR  lastError[ERRORSIZE];
		TCHAR  errorTemp[ERRORSIZE];
		bool  isConnected;
		int	  baudRate;
		
    /*  Add your actions, conditions and expressions as real class member
        functions here. The arguments (and return type for expressions) must
        match EXACTLY what you defined in the JSON.

        Remember to link the actions, conditions and expressions to their
        numeric IDs in the class constructor (Extension.cpp)
    */

    /// Actions

		void StartRecording(int portNum);
		void StopRecording();
		void LogStream(char* fileName);
		void LogData(char* fileName);
       
    /// Conditions

        bool OnError();
		bool IsConnected();

    /// Expressions
        
		int   DllVersion();
        float Attention();
		float Meditation();
		float Delta();
		float Theta();
		float Alpha1();
		float Alpha2();
		float Beta1();
		float Beta2();
		float Gamma1();
		float Gamma2();
		float PoorSignal();
        TCHAR* LastError();



    /* These are called if there's no function linked to an ID */

    void Action(int ID, LPRDATA rdPtr, long param1, long param2);
    long Condition(int ID, LPRDATA rdPtr, long param1, long param2);
    long Expression(int ID, LPRDATA rdPtr, long param);




    /*  These replace the functions like HandleRunObject that used to be
        implemented in Runtime.cpp. They work exactly the same, but they're
        inside the extension class.
    */

    short Handle();
    short Display();

    short Pause();
    short Continue();

    bool Save(HANDLE File);
    bool Load(HANDLE File);

};