//======================================================================
//           ADVANTECH - Trusted ePlatform Services                              
//======================================================================
//
// ERRDRV.H - Header File for Driver Error Codes in SUSI Advanced Debugging
// 
// Copyright (c) Advantech Co., Ltd. All Rights Reserved
//======================================================================
// Revision History :
// --------------------------------------------
// July 2007 - first featuring in Susi v1.2	
// --------------------------------------------
// Author : Josh Chang, ESSD Presention
//======================================================================

#ifndef _SUSI_ERRDRV_H_
#define _SUSI_ERRDRV_H_

//----------------------------------------------------------------------
// Driver Error Codes : 10000 ~ 19999
//
typedef enum
{
	ERRDRV_SUCCESS = 0,
    //--------------------------------------------------
    // All*A     10000 ~ 10499 
    //--------------------------------------------------
    ERRDRV_CTRLCODE = 10000,                              
    ERRDRV_LOGIC,                                   
    ERRDRV_INBUF_INSUFFICIENT,                      
    ERRDRV_OUTBUF_INSUFFICIENT,   
    ERRDRV_STOPTIMER_FAILED,
    ERRDRV_STARTTIMER_FAILED,
	ERRDRV_CREATEREG_FAILED,
	ERRDRV_OPENREG_FAILED,
	ERRDRV_SETREGVALUE_FAILED,
	ERRDRV_GETREGVALUE_FAILED,
	ERRDRV_FLUSHREG_FAILED,
	ERRDRV_MEMMAP_FAILED,
	//--------------------------------------------------
    // CORE      10500 ~ 10999 
    //--------------------------------------------------
    //--------------------------------------------------
  	// WDT :     11000 ~ 11199 
  	//--------------------------------------------------
  	//--------------------------------------------------
  	// GPIO :    11200 ~ 11399
  	//--------------------------------------------------
  	ERRDRV_GPIO_PIN_DIR_CHANGED = 11200, 
    ERRDRV_GPIO_PIN_INCONFIGURABLE, 
    ERRDRV_GPIO_PIN_OUTPUT_UNREADABLE, 
    ERRDRV_GPIO_PIN_INPUT_UNWRITTABLE, 
    ERRDRV_GPIO_INITIAL_FAILED, 
    ERRDRV_GPIO_GETINPUT_FAILED, 
    ERRDRV_GPIO_SETOUTPUT_FAILED, 
    ERRDRV_GPIO_GETSTATUS_IO_FAILED, 
    ERRDRV_GPIO_SETSTATUS_OUT_FAILED,  
    ERRDRV_GPIO_SETDIR_FAILED,
    ERRDRV_GPIO_GETDIR_FAILED,
    //--------------------------------------------------
  	// SMBus :   11400 ~ 11599  
  	//--------------------------------------------------
    ERRDRV_SMB_RESETDEV_FAILED = 11400,
	ERRDRV_SMB_TIMEOUT,
	ERRDRV_SMB_BUSTRANSACTION_FAILED,
	ERRDRV_SMB_BUSCOLLISION,
	ERRDRV_SMB_CLIENTDEV_NORESPONSE,
	ERRDRV_SMB_REQUESTMASTERMODE_FAILED,
    ERRDRV_SMB_NOT_MASTERMODE,
	ERRDRV_SMB_BUS_ERROR,
	ERRDRV_SMB_BUS_STALLED,
	ERRDRV_SMB_NEGACK_DETECTED,
	ERRDRV_SMB_TRANSMITMODE_ACTIVE,
	ERRDRV_SMB_TRANSMITMODE_INACTIVE,
	ERRDRV_SMB_STATE_UNKNOWN,
	ERRDRV_SMB_STATE_INVALID_BLOCK_LENGTH,
	ERRDRV_SMB_STATE_MORE_DATA,
  	//--------------------------------------------------
  	// IIC :     11600 ~ 11799  
  	//--------------------------------------------------
    ERRDRV_IIC_RESETDEV_FAILED = 11600,
	ERRDRV_IIC_TIMEOUT,
	ERRDRV_IIC_BUSTRANSACTION_FAILED,
	ERRDRV_IIC_BUSCOLLISION,
	ERRDRV_IIC_CLIENTDEV_NORESPONSE,
	ERRDRV_IIC_REQUESTMASTERMODE_FAILED,
    ERRDRV_IIC_NOT_MASTERMODE,
	ERRDRV_IIC_BUS_ERROR,
	ERRDRV_IIC_BUS_STALLED,
	ERRDRV_IIC_NEGACK_DETECTED,
	ERRDRV_IIC_TRANSMITMODE_ACTIVE,
	ERRDRV_IIC_TRANSMITMODE_INACTIVE,
	ERRDRV_IIC_STATE_UNKNOWN,
  	//--------------------------------------------------
  	// VC :      11800 ~ 11999
  	//--------------------------------------------------
	ERRDRV_VC_FINDVGA_FAILED = 11800,
    ERRDRV_VC_FINDBRIGHTDEV_FAILED,
    ERRDRV_VC_VGA_UNSUPPORTED,
	ERRDRV_VC_BRIGHTDEV_UNSUPPORTED,
  	//--------------------------------------------------
  	// HWM :     12000 ~ 12199 
  	//--------------------------------------------------

} ESUSI_DRV_ERRCODE;

//[Note]
// *A - Common driver-wide errors


#endif //_SUSI_ERRDRV_H_
