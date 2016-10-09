#ifndef _REL_EC_API_H_
#define _REL_EC_API_H_

#define EC_API __declspec(dllexport)
#define EAPI_CALLTYPE WINAPI

typedef struct _SUSIAUTOFANCONFIG{
  unsigned long dwZone;
  unsigned long dwOpMode;
  unsigned long dwLowStopTemp;
  unsigned long dwLowTemp;
  unsigned long dwHighTemp; 
  unsigned long dwLowPWM; //Percentage
  unsigned long dwHighPWM;
  unsigned long dwLowRPM;
  unsigned long dwHighRPM;
} SUSIAUTOFANCONFIG, *PSUSIAUTOFANCONFIG;

typedef struct _SUSIFANCONFIG{
  unsigned long dwSize;
  unsigned long dwMode;
  unsigned long dwPWM;
  // optional parameters for auto fan mode
  SUSIAUTOFANCONFIG safConfig;
} SUSIFANCONFIG, *PSUSIFANCONFIG;

typedef struct _THERMALPROTECTNO
{
  unsigned long dw_source;
  unsigned long dw_event_type;
  unsigned long dw_send_event_temperature;
  unsigned long dw_clear_event_temperature;
} THERMALPROTECTNO, *PTHERMALPROTECTNO;

typedef struct _SUSITHERMALCONFIG{
  THERMALPROTECTNO protect_number[4];
} SUSITHERMALCONFIG, *PSUSITHERMALCONFIG;

#ifdef __cplusplus
extern "C" {
#endif
///////////////////////////////////////////////////////////////////////////////
// The Begin of EApi

///////////////////////////////////////////////////////////////////////////////
// Initial
///////////////////////////////////////////////////////////////////////////////
EC_API ULONG EAPI_CALLTYPE EApiLibInitialize(void);
EC_API ULONG EAPI_CALLTYPE EApiLibUnInitialize(void);

///////////////////////////////////////////////////////////////////////////////
// Core
///////////////////////////////////////////////////////////////////////////////
EC_API ULONG EAPI_CALLTYPE EApiBoardGetStringA(
										ULONG Id,
										char *pBuffer,
                                        ULONG *pBufLen
										);
EC_API ULONG EAPI_CALLTYPE EApiBoardGetValue(
									  ULONG Id,
									  ULONG *pValue
									  );
	// Not standard EAPI, and No use by now
    EC_API ULONG EAPI_CALLTYPE EC_ReadIO(ULONG addr,
										 PULONG value);
	// Not standard EAPI, and No use by now
    EC_API ULONG EAPI_CALLTYPE EC_WriteIO(ULONG addr,
										  ULONG value);

///////////////////////////////////////////////////////////////////////////////
// GPIO
///////////////////////////////////////////////////////////////////////////////
EC_API ULONG EAPI_CALLTYPE EApiGPIOGetDirectionCaps(
											  ULONG Id,		/* GPIO Id */
											  ULONG *pInputs,/* Supported GPIO Input
															* Bit Mask 
															*/
											  ULONG *pOutputs/* Supported GPIO Output
															* Bit Mask 
															*/
											);
EC_API ULONG EAPI_CALLTYPE EApiGPIOGetDirection(
										  ULONG Id,			/* GPIO Id */
										  ULONG Bitmask,	/* Bit mask of Affected
															* Bits 
															*/
										  ULONG *pDirection	/* Current Direction */
										);
EC_API ULONG EAPI_CALLTYPE EApiGPIOSetDirection(
										  ULONG Id,			/* GPIO Id */
										  ULONG Bitmask,	/* Bit mask of Affected 
															* Bits 
															*/
										  ULONG Direction	/* Direction */
										);
EC_API ULONG EAPI_CALLTYPE EApiGPIOGetLevel(
									  ULONG Id,				/* GPIO Id */
									  ULONG Bitmask,		/* Bit mask of Affected
															* Bits 
															*/
									  ULONG *pLevel			/* Current Level */
									);
EC_API ULONG EAPI_CALLTYPE EApiGPIOSetLevel(
									  ULONG Id,				/* GPIO Id */
									  ULONG Bitmask,		/* Bit mask of Affected 
															* Bits 
															*/
									  ULONG Level			/* Level */  
									);
	//-------------------------------------------------------------------------
	// Not standard EAPI, and No use by now
    EC_API ULONG EAPI_CALLTYPE EApiGPIOGetCount(ULONG *pIOcount);
	//-------------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////////////
// HW Monitor
///////////////////////////////////////////////////////////////////////////////
	//-----------------------------------------------------------------
	// Not standard EAPI, and No use by now
    EC_API ULONG EAPI_CALLTYPE EApiHWMGetFanCount(
                                            		ULONG *p_fan_count
												 );
	// Not standard EAPI, and No use by now
    EC_API ULONG EAPI_CALLTYPE EApiHWMGetCaps(
											  ULONG Id,		/* GPIO Id */
											  ULONG *pCapability/* Supported GPIO Output
																* Bit Mask 
																*/
											 );
	//------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////////////
// I2C
///////////////////////////////////////////////////////////////////////////////

EC_API ULONG EAPI_CALLTYPE EApiI2CGetBusCap(
									 ULONG Id,			 	/* I2C Bus Id */
									 ULONG *pMaxBlkLen		/* Max Block Length 
															* Supported on this
															* interface 
															*/
									);
EC_API ULONG EAPI_CALLTYPE EApiI2CWriteReadRaw(
										ULONG Id,       	/* I2C Bus Id */
										ULONG Addr,     	/* Encoded 7Bit I2C
															* Device Address 
															*/
										void *pWBuffer,		/* Write Data pBuffer */
										ULONG  WriteBCnt,	/* Number of Bytes to 
															* write plus 1
															*/
										void     *pRBuffer,	/* Read Data pBuffer */
										ULONG  RBufLen,		/* Data pBuffer Length */
										ULONG  ReadBCnt		/* Number of Bytes to 
															* Read plus 1
															*/
										);
EC_API ULONG EAPI_CALLTYPE EApiI2CReadTransfer(
										ULONG Id,			/* I2C Bus Id */
										ULONG Addr,			/* Encoded 7/10Bit I2C
															* Device Address
															*/
										ULONG Cmd,			/* I2C Command/Offset */
										void *pBuffer,		/* Transfer Data pBuffer */
										ULONG BufLen,		/* Data pBuffer Length */
										ULONG ByteCnt		/* Byte Count to read */
									   );
EC_API ULONG EAPI_CALLTYPE EApiI2CWriteTransfer(
										ULONG  Id,			/* I2C Bus Id */
										ULONG  Addr,		/* Encoded 7/10Bit I2C 
															* Device Address 
															*/
										ULONG  Cmd,			/* I2C Command/Offset */
										void *pBuffer,		/* Transfer Data pBuffer */
										ULONG  ByteCnt		/* Byte Count to write */
										);
EC_API ULONG EAPI_CALLTYPE EApiI2CProbeDevice(
										ULONG  Id,			/* I2C Bus Id */
										ULONG  Addr			/* Encoded 7/10Bit 
															* I2C Device Address 
															*/
									  );
//-----------------------------------------------------------------------------
// Not standard EAPI
EC_API ULONG EAPI_CALLTYPE SusiI2CRead(unsigned long bAddr,
									   unsigned char *pBytes,
									   unsigned long dwLen);
// Not standard EAPI
EC_API ULONG EAPI_CALLTYPE SusiI2CWrite(unsigned long bAddr,
										unsigned char *pBytes,
										unsigned long dwLen);
// Not standard EAPI
EC_API ULONG EAPI_CALLTYPE EApiSetI2CMode(ULONG dwModeFlag);

// Not standard EAPI
EC_API ULONG EAPI_CALLTYPE EApiGetI2CSMBFrequency(
										ULONG  Id,			/* I2C Bus Id */
										PULONG pFreq		/* Transfer Data pBuffer */
										);
// Not standard EAPI
EC_API ULONG EAPI_CALLTYPE EApiSetI2CSMBFrequency(
										ULONG  Id,			/* I2C Bus Id */
										ULONG  Freq		/* Transfer Data pBuffer */
										);
//-----------------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////////////
// iManager SMBus, The API only provided by Advantech
///////////////////////////////////////////////////////////////////////////////
//---------------------------------- Read -------------------------------------
EC_API ULONG EAPI_CALLTYPE SusiECSMBusReadByte(UCHAR bAddr,
											   UCHAR bReg,
											   UCHAR *pDataByte);

EC_API ULONG EAPI_CALLTYPE SusiECSMBusReadWord(UCHAR bAddr,
											   UCHAR bReg,
											   USHORT *pDataWord);
	//------------------------------------------------------------------------
	// No use by Now
    EC_API ULONG EAPI_CALLTYPE SusiECSMBusReadByteMulti(UCHAR SlaveAddress,
														UCHAR RegisterOffset,
														UCHAR *Result,
														UCHAR ByteCount);
	//------------------------------------------------------------------------

//---------------------------------- Write ------------------------------------
EC_API ULONG EAPI_CALLTYPE SusiECSMBusWriteByte(UCHAR bAddr,
												UCHAR bReg,
												UCHAR bData);

EC_API ULONG EAPI_CALLTYPE SusiECSMBusWriteWord(UCHAR bAddr,
												UCHAR bReg,
												USHORT wData);
	//------------------------------------------------------------------------	
	// No use by Now
    EC_API ULONG EAPI_CALLTYPE SusiECSMBusWriteByteMulti(UCHAR SlaveAddress,
														 UCHAR RegisterOffset,
														 UCHAR *Result,
														 UCHAR ByteCount);
	//------------------------------------------------------------------------
//------------------------------ Send/Receive ---------------------------------
EC_API ULONG EAPI_CALLTYPE SusiECSMBusReceiveByte(UCHAR bAddr,
												  UCHAR *pDataByte);
EC_API ULONG EAPI_CALLTYPE SusiECSMBusSendByte(UCHAR bAddr,
											   UCHAR bData);
//---------------------------------- Quick ------------------------------------
EC_API ULONG EAPI_CALLTYPE SusiECSMBusWriteQuick(UCHAR bAddr);
EC_API ULONG EAPI_CALLTYPE SusiECSMBusReadQuick(UCHAR bAddr);
//---------------------------------- Probe ------------------------------------
EC_API ULONG EAPI_CALLTYPE SusiECSMBusScanDevice(UCHAR bAddr_7);
//---------------------------------- Block ------------------------------------
EC_API ULONG EAPI_CALLTYPE SusiECSMBusWriteBlock(UCHAR bAddr,
												 UCHAR bReg,
												 UCHAR *Result,
												 UCHAR ByteCount);
EC_API ULONG EAPI_CALLTYPE SusiECSMBusReadBlock(UCHAR bAddr,
												UCHAR bReg,
												UCHAR *Result,
												UCHAR *ByteCount);


///////////////////////////////////////////////////////////////////////////////
// South Bridge SMBus, The API only provided by Advantech
///////////////////////////////////////////////////////////////////////////////
EC_API ULONG EAPI_CALLTYPE SusiSMBusReset(void);

// Read Byte -----------------------------------------------------------------
EC_API ULONG EAPI_CALLTYPE SusiSMBusReadByte(BYTE SlaveAddress,
											 BYTE RegisterOffset,
											 BYTE *Result);
	//------------------------------------------------------------------------	
	// No use by Now
    EC_API ULONG EAPI_CALLTYPE AdvLibSMBusReadByte(BYTE SlaveAddress,
												   BYTE RegisterOffset,
												   BYTE *Result);
	// No use by Now
    EC_API ULONG EAPI_CALLTYPE SusiSMBusReadByteMulti(BYTE SlaveAddress,
													  BYTE RegisterOffset,
													  BYTE *Result,
													  BYTE ByteCount);
	// No use by Now
    EC_API ULONG EAPI_CALLTYPE AdvLibSMBusReadByteMulti(BYTE SlaveAddress,
														BYTE RegisterOffset,
														BYTE *Result,
														BYTE ByteCount);
	//------------------------------------------------------------------------

// Read Word ------------------------------------------------------------------
EC_API ULONG EAPI_CALLTYPE SusiSMBusReadWord(BYTE SlaveAddress,
											 BYTE RegisterOffset,
											 WORD *Result);
	//------------------------------------------------------------------------
	// No use by Now
    EC_API ULONG EAPI_CALLTYPE AdvLibSMBusReadWord(BYTE SlaveAddress,
												   BYTE RegisterOffset,
												   WORD *Result);
	//------------------------------------------------------------------------

// Write Byte -----------------------------------------------------------------
EC_API ULONG EAPI_CALLTYPE SusiSMBusWriteByte(BYTE SlaveAddress,
											  BYTE RegisterOffset,
											  BYTE Result);
	//------------------------------------------------------------------------
	// No use by Now
    EC_API ULONG EAPI_CALLTYPE AdvLibSMBusWriteByte(BYTE SlaveAddress,
													BYTE RegisterOffset,
													BYTE Result);
	// No use by Now
    EC_API ULONG EAPI_CALLTYPE SusiSMBusWriteByteMulti(BYTE SlaveAddress,
													   BYTE RegisterOffset,
													   BYTE *Result,
													   BYTE ByteCount);
	// No use by Now
    EC_API ULONG EAPI_CALLTYPE AdvLibSMBusWriteByteMulti(BYTE SlaveAddress,
														 BYTE RegisterOffset,
														 BYTE *Result,
														 BYTE ByteCount);
	//------------------------------------------------------------------------

// Write Word -----------------------------------------------------------------
EC_API ULONG EAPI_CALLTYPE SusiSMBusWriteWord(BYTE SlaveAddress,
											  BYTE RegisterOffset,
											  WORD Result);
	//------------------------------------------------------------------------	
	// No use by Now
    EC_API ULONG EAPI_CALLTYPE AdvLibSMBusWriteWord(BYTE SlaveAddress,
													BYTE RegisterOffset,
													WORD Result);
	//------------------------------------------------------------------------

// Send/Receive Byte ----------------------------------------------------------
EC_API ULONG EAPI_CALLTYPE SusiSMBusReceiveByte(BYTE SlaveAddress,
												BYTE *Result);


EC_API ULONG EAPI_CALLTYPE SusiSMBusSendByte(BYTE SlaveAddress,
											 BYTE Result);

// Quick Read/Write -----------------------------------------------------------
EC_API ULONG EAPI_CALLTYPE SusiSMBusWriteQuick(BYTE SlaveAddress);

EC_API ULONG EAPI_CALLTYPE SusiSMBusReadQuick(BYTE SlaveAddress);

// Scan Device ----------------------------------------------------------------
EC_API ULONG EAPI_CALLTYPE SusiSMBusScanDevice(BYTE SlaveAddress_7);

// Read/Write Block -----------------------------------------------------------
EC_API ULONG EAPI_CALLTYPE SusiSMBusWriteBlock(BYTE SlaveAddress,
											   BYTE RegisterOffset,
											   BYTE *Result,
											   BYTE ByteCount);

EC_API ULONG EAPI_CALLTYPE SusiSMBusReadBlock(BYTE SlaveAddress,
											  BYTE RegisterOffset,
											  BYTE *Result,
											  BYTE *ByteCount);

///////////////////////////////////////////////////////////////////////////////
// SmartBattery, The API only provided by Advantech
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// SmartFan, The API only provided by Advantech
///////////////////////////////////////////////////////////////////////////////
EC_API ULONG EAPI_CALLTYPE EApiSusiFanGetConfigStruct(unsigned long dwUnit, SUSIFANCONFIG *pConfig);
EC_API ULONG EAPI_CALLTYPE EApiSusiFanSetConfigStruct(unsigned long dwUnit, SUSIFANCONFIG *pConfig);
											 

///////////////////////////////////////////////////////////////////////////////
// Storage
///////////////////////////////////////////////////////////////////////////////

EC_API ULONG EAPI_CALLTYPE EApiStorageCap(
								   ULONG Id,				/* Storage Area Id */
								   ULONG *pStorageSize, 	/* Total */
								   ULONG *pBlockLength		/* Write Block Length
															* & Alignment 
															*/
								  );
EC_API ULONG EAPI_CALLTYPE EApiStorageAreaRead(
										ULONG Id,			/* Storage Area Id */
										ULONG Offset,		/* Byte Offset */
										void *pBuffer, 		/* Pointer to Data pBuffer */
										ULONG BufLen,  		/* Data pBuffer Size in 
															* bytes 
															*/
										ULONG ByteCnt		/* Number of bytes to read */
									   );
EC_API ULONG EAPI_CALLTYPE EApiStorageAreaWrite(
										 ULONG Id,      	/* Storage Area Id */
										 ULONG Offset,  	/* Byte Offset */
										 void *pBuffer, 	/* Pointer to Data pBuffer */
										 ULONG ByteCnt		/* Number of bytes to write */
										);
//-----------------------------------------------------------------------------
// Not standard EAPI
EC_API ULONG EAPI_CALLTYPE SusiStorageAreaIsLocked(ULONG Id,
												   ULONG dwFlags);
// Not standard EAPI
EC_API ULONG EAPI_CALLTYPE SusiStorageAreaLock(ULONG Id,
											   ULONG dwFlags,
											   char *pBytes,
											   ULONG dwLen);
// Not standard EAPI
EC_API ULONG EAPI_CALLTYPE SusiStorageAreaUnlock(ULONG Id,
												 ULONG dwFlags,
												 char *pBytes,
												 ULONG dwLen);
//-----------------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////////////
// Thermal Zone, The API only provided by Advantech
///////////////////////////////////////////////////////////////////////////////
EC_API ULONG EAPI_CALLTYPE SusiEC_ThermalProtectionGetConfigStruct(ULONG Id, SUSITHERMALCONFIG *pConfig);
EC_API ULONG EAPI_CALLTYPE SusiEC_ThermalProtectionSetConfigStruct(ULONG Id, SUSITHERMALCONFIG *pConfig);

///////////////////////////////////////////////////////////////////////////////
// VGA
///////////////////////////////////////////////////////////////////////////////

EC_API ULONG EAPI_CALLTYPE EApiVgaGetBacklightEnable(
											  ULONG Id,
											  ULONG *pEnable
											 );
EC_API ULONG EAPI_CALLTYPE EApiVgaSetBacklightEnable(
											  ULONG Id,
											  ULONG Enable
											 );
EC_API ULONG EAPI_CALLTYPE EApiVgaGetBacklightBrightness(
												  ULONG Id,
												  ULONG *pBright
												 );
EC_API ULONG EAPI_CALLTYPE EApiVgaSetBacklightBrightness(
												  ULONG Id,
												  ULONG Bright
												 );
//-----------------------------------------------------------------------------
// Not standard EAPI
EC_API ULONG EAPI_CALLTYPE EApiVgaSetFrequency(
											  ULONG Id,
											  ULONG dwSetting
											 );
// Not standard EAPI
EC_API ULONG EAPI_CALLTYPE EApiVgaSetPolarity(
											  ULONG Id,
											  ULONG dwSetting
											 );
// Not standard EAPI
EC_API ULONG EAPI_CALLTYPE EApiVgaGetBacklightLevel(
												  ULONG Id,
												  ULONG *pLevel
												 );
// Not standard EAPI
EC_API ULONG EAPI_CALLTYPE EApiVgaSetBacklightLevel(
												  ULONG Id,
												  ULONG Level
												 );
//-----------------------------------------------------------------------------

///////////////////////////////////////////////////////////////////////////////
// WatchDog
///////////////////////////////////////////////////////////////////////////////
EC_API ULONG EAPI_CALLTYPE EApiWDogGetCap(
									ULONG *pMaxDelay,		/* Maximum Supported 
															* Delay in milliseconds
															*/
									ULONG *pMaxEventTimeout,/* Maximum Supported 
															* Event Timeout in 
															* milliseconds
															* 0 == Unsupported
															*/
									ULONG *pMaxResetTimeout	/* Maximum Supported 
															* Reset Timeout in 
															* milliseconds
															*/
								  );

EC_API ULONG EAPI_CALLTYPE EApiWDogStart(
									ULONG Delay,			/* Delay in milliseconds */
									ULONG EventTimeout,		/* Event Timeout in 
															* milliseconds 
															*/
									ULONG ResetTimeout		/* Reset Timeout in 
															* milliseconds 
															*/
								 );

EC_API ULONG EAPI_CALLTYPE EApiWDogTrigger(void);
EC_API ULONG EAPI_CALLTYPE EApiWDogStop(void);

//-----------------------------------------------------------------------------
// Not standard EAPI
EC_API ULONG EAPI_CALLTYPE EApiWDogGetConfig(PULONG Delay,
											 PULONG EventTimeout,
											 PULONG ResetTimeout,
											 PULONG EventType);
// Not standard EAPI
EC_API ULONG EAPI_CALLTYPE EApiWDogSetEventType(ULONG EventType);
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Interrupt CallBack
//-----------------------------------------------------------------------------
// Not standard EAPI

// The End of EApi
///////////////////////////////////////////////////////////////////////////////


#ifdef __cplusplus
}
#endif

#endif

