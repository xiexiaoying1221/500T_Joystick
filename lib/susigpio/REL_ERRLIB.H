//======================================================================
//           ADVANTECH - Trusted ePlatform Services                              
//======================================================================
//
// ERRLIB.H - Header File for Driver Error Codes in SUSI Advanced Debugging
// 
// Copyright (c) Advantech Co., Ltd. All Rights Reserved
//======================================================================
// Revision History :
// --------------------------------------------
// July 2007 - first featuring in Susi v1.2	
// --------------------------------------------
// Author : Josh Chang, ESSD Presention
//======================================================================

#ifndef _SUSI_ERRLIB_H_
#define _SUSI_ERRLIB_H_
	
//----------------------------------------------------------------------
// Library Error Codes : 0 ~ 9999
//
// # 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192 are  
// reserved for driver open errors

typedef enum
{	
	//-----------------------------------------------------------
    // DrvOpen Errors*A                   
    //-----------------------------------------------------------
    ERRLIB_CORE_OPEN_FAIL					= 1,
    ERRLIB_WDT_OPEN_FAIL					= 2,
    ERRLIB_GPIO_OPEN_FAIL					= 4,
	ERRLIB_SMB_OPEN_FAIL					= 8,
	ERRLIB_VC_OPEN_FAIL						= 16,
	ERRLIB_HWM_OPEN_FAIL					= 32,
	//-----------------------------------------------------------
    // Dll :     0000 ~ 0499 (exclude 1, 2, 4, 8, 16, 32, 64, 128, 256)                    
    //-----------------------------------------------------------
	ERRLIB_SUCCESS							= 0, 
	ERRLIB_RESERVED1						= 1, 
    ERRLIB_RESERVED2						= 2,
    ERRLIB_LOGIC							= 3,
	ERRLIB_RESERVED4						= 4,
	ERRLIB_SUSIDLL_NOT_INIT					= 5, 
    ERRLIB_PLATFORM_UNSUPPORT				= 6, 
	ERRLIB_API_UNSUPPORT					= 7,  
	ERRLIB_RESERVED8						= 8,
	ERRLIB_API_CURRENT_UNSUPPORT			= 9,
	ERRLIB_LIB_INIT_FAIL					= 10,	// *B
  	ERRLIB_DRIVER_CONTROL_FAIL				= 11,	// *B
  	ERRLIB_INVALID_PARAMETER				= 12,   // *B  
	ERRLIB_INVALID_ID						= 13,
    ERRLIB_CREATEMUTEX_FAIL					= 14, 
	ERRLIB_OUTBUF_RETURN_SIZE_INCORRECT		= 15, 
	ERRLIB_RESERVED16						= 16,
	ERRLIB_ARRAY_LENGTH_INSUFFICIENT		= 17,
	ERRLIB_RESERVED32						= 32,	                    
  	ERRLIB_BRIGHT_CONTROL_FAIL				= 50,	// *B 
  	ERRLIB_BRIGHT_OUT_OF_RANGE				= 51,	// *B
	ERRLIB_RESERVED64						= 64,
	ERRLIB_RESERVED128						= 128,
	ERRLIB_RESERVED256						= 256,
	//-----------------------------------------------------------
    // CORE :     0500 ~ 0999 (exclude 512)                        
    //----------------------------------------------------------- 
  	ERRLIB_CORE_BIOS_STRING_NOT_FOUND		= 500,
	ERRLIB_RESERVED512						= 512,
	ERRLIB_CORE_CAN_NOT_WRITE_PWR_SCHEME	= 520,
	ERRLIB_CORE_GET_PWR_SCHEME_FAILED		= 521,
	ERRLIB_CORE_SET_PWR_SCHEME_FAILED		= 522,
	ERRLIB_CORE_DETECT_PWR_PROFILE_FAILED	= 523,
	ERRLIB_CORE_DELETE_PWR_PROFILE_FAILED	= 524,
	ERRLIB_CORE_CREATE_PWR_PROFILE_FAILED	= 525,
	ERRLIB_CORE_PWR_PROFILE_INVALID			= 526,
	ERRLIB_CORE_WRITE_PWR_SCHEME_FAILED		= 527,
	ERRLIB_CORE_READ_PWR_SCHEME_FAILED		= 528,
  	//-----------------------------------------------------------
  	// WDT :      1000 ~ 1199 (exclude 1024) 
  	//-----------------------------------------------------------
	ERRLIB_RESERVED1024						= 1024,
  	//-----------------------------------------------------------
  	// GPIO :     1200 ~ 1399 
  	//----------------------------------------------------------- 
	ERRLIB_GPIO_DEVICE_INIT_FAIL			= 1200,
	ERRLIB_GPIO_DEVICE_SETDIR_FAIL			= 1201,
	ERRLIB_GPIO_DEVICE_GETDIR_FAIL			= 1202,
	ERRLIB_GPIO_DEVICE_SETIO_FAIL			= 1203,
	ERRLIB_GPIO_DEVICE_GETIO_FAIL			= 1204,
	ERRLIB_GPIO_DEVICE_FUNC_INIT_FAIL		= 1205,
  	//-----------------------------------------------------------
  	// SMBus :    1400 ~ 1599 
  	//-----------------------------------------------------------
    ERRLIB_SMB_MAX_BLOCK_SIZE_MUST_WITHIN_32= 1400,
  	//-----------------------------------------------------------
  	// IIC :      1600 ~ 1799  
  	//-----------------------------------------------------------
	ERRLIB_IIC_GETCPUFREQ_FAIL				= 1600,
  	//-----------------------------------------------------------
  	// VC :       1800 ~ 1999
  	//-----------------------------------------------------------
  	//-----------------------------------------------------------
  	// HWM :      2000 ~ 2199 (exclude 2048)
  	//-----------------------------------------------------------
	ERRLIB_HWM_CHECKCPUTYPE_FAIL			= 2000, 
	ERRLIB_HWM_FUNCTION_UNSUPPORT,
	ERRLIB_HWM_FUNCTION_CURRENT_UNSUPPORT,
	ERRLIB_HWM_FANDIVISOR_INVALID,
	ERRLIB_RESERVED2048						= 2048,
	//-----------------------------------------------------------
  	// Reserved : 2200 ~ 9999 (exclude 4096, 8192)
  	//-----------------------------------------------------------
	ERRLIB_RESERVED4096						= 4096,
	ERRLIB_RESERVED8192						= 8192

} ESUSI_LIB_ERRCODE; 

//[Note]
// *A - Only could be occurred in SusiDllInit, the error results from
//      driver open error will be in the combination of those flags
//      ie. Error Code = ESusiDllInit + ORed of DrvOpen Errors
// *B - Error codes for backward compatible with earlier versions
//      of SUSI 
//      

#endif //_SUSI_ERRLIB_H_
