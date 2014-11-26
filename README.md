# BrainControl

EDIF Brain Control Extension (ClickteamFusion 2.5) 


Brain Control reads brain signal through Neurosky headset.


## Properties

**Baud rate**

Combobox to choose the baud rate for the Neurosky connection.


## Actions


**Start Recording**

Connect device (specified COM Port) and start reading brain signal continuously. Last sample values are stored.

This action takes 1 argument: 
Com Port Number: number of the COM port where the headset is connected. 

------------

**Stop Recording** 

Stop reading brain signal. The device is also disconnected.

This action takes no argument.

## Conditions


**On Error**

Returns true if an error occured

------------

**Is Connected**

Returns true if the Neurosky headset is connected.

## Expressions

**Last Error**

Returns the last error encountered. Once read the error is erased and can not be retrieved anymore.
Note that if several errors happened before this string is read, only the last error is provided.

------------

**Attention**

Returns the NeuroSky "eSense" attention value.

------------

**Mediation**

Returns the NeuroSky "eSense" meditation value.

------------

**Delta**

Returns the delta (1-3Hz) power value, often associated with sleep.

------------

**Theta**

Returns the theta (4-7Hz) power value, associated with a relaxed, meditative state.

------------

**Alpha1**

Returns the low alpha (8-9Hz) power value, higher when eyes are closed or you're relaxed

------------

**Alpha2**

Returns the high alpha (10-12Hz) power value.

------------

**Beta1**

Returns the low beta (13-17Hz) power value, higher when you're alert and focused.

------------

**Beta2**

Returns the high beta (18-30Hz) power value.

------------

**Gamma1**

Returns the low gamma (31-40Hz) power value, associated with multi-sensory processing.

------------

**Gamma2**

Returns the high gamma (41-50Hz) power value.

------------

**Poor Signal**

Returns the latest signal quality reading. 200 is high, 0 is no signal.


## Error Codes

Error Codes provided by Last Error expression

[00] No Error.
Default status. 

[01] Connection Id is invalid.

A unique connection is used when requested by the driver. 

[02] Invalid COM Port.

COM Port is invalid, check in your Neurosky software that it is valid.

[03] Invalid Baud Rate.

Baud Rate is invalid. Since the baud rate is defined through in the properties of the object, this error should never happen.

Try another baudrate.
 
[04] Invalid Data Format.

Data Format is invalid. Since the data Format is handled internally, this error should never happen.

Check that your headset can handle Stream Packets
 
[05] Cannot start recording.

This error happens if the device connected but it cannot automatically read values.

Try to reset the device and try again.
