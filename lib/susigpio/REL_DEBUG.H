//======================================================================
//           ADVANTECH - Trusted ePlatform Services                              
//======================================================================
//
// DEBUG.H - Header File for Function Index Codes in SUSIEC2 Advanced Debugging
// 
// Copyright (c) Advantech Co., Ltd. All Rights Reserved
//======================================================================
// Revision History :
// --------------------------------------------
// Oct. 2010 - first featuring in SusiEC v2.0	
// --------------------------------------------
// Author : Wilson Wang
//======================================================================
#include "define.h"
#ifndef _REL_DEBUG_H_
#define _REL_DEBUG_H_
#define EAPI_UINT32_C ULONG
/*
 *
 *
 *  S T A T U S   C O D E S
 *
 *
 */
/* Description
 *   The EAPI library is not yet or unsuccessfully initialized. 
 *   EApiLibInitialize needs to be called prior to the first access of any 
 *   other EAPI function.
 * Actions
 *   Call EApiLibInitialize..
 */
// (0xFFFFFF00~0xFFFFFFFF)
#define EAPI_STATUS_NOT_INITIALIZED			EAPI_UINT32_C(0xFFFFFFFF)
#define EAPI_STATUS_INITIALIZED				EAPI_UINT32_C(0xFFFFFFFE)
#define EAPI_STATUS_ALLOC_ERROR				EAPI_UINT32_C(0xFFFFFFFD)
#define EAPI_STATUS_DRIVER_TIMEOUT			EAPI_UINT32_C(0xFFFFFFFC)
// (0xFFFFFE00~0xFFFFFEFF)
#define EAPI_STATUS_INVALID_PARAMETER		EAPI_UINT32_C(0xFFFFFEFF)
#define EAPI_STATUS_INVALID_BLOCK_ALIGNMENT	EAPI_UINT32_C(0xFFFFFEFE)
#define EAPI_STATUS_INVALID_BLOCK_LENGTH    EAPI_UINT32_C(0xFFFFFEFD)
#define EAPI_STATUS_INVALID_DIRECTION       EAPI_UINT32_C(0xFFFFFEFC)
#define EAPI_STATUS_INVALID_BITMASK         EAPI_UINT32_C(0xFFFFFEFB)
#define EAPI_STATUS_RUNNING                 EAPI_UINT32_C(0xFFFFFEFA)
// (0xFFFFFC00~0xFFFFFCFF)
#define EAPI_STATUS_UNSUPPORTED				EAPI_UINT32_C(0xFFFFFCFF)
// (0xFFFFFB00~0xFFFFFBFF)
#define EAPI_STATUS_NOT_FOUND				EAPI_UINT32_C(0xFFFFFBFF)
#define EAPI_STATUS_TIMEOUT					EAPI_UINT32_C(0xFFFFFBFE)
#define EAPI_STATUS_BUSY_COLLISION			EAPI_UINT32_C(0xFFFFFBFD)
// (0xFFFFFA00~0xFFFFFAFF)
#define EAPI_STATUS_READ_ERROR				EAPI_UINT32_C(0xFFFFFAFF)
#define EAPI_STATUS_WRITE_ERROR				EAPI_UINT32_C(0xFFFFFAFE)
// (0xFFFFF900~0xFFFFF9FF)
#define EAPI_STATUS_MORE_DATA				EAPI_UINT32_C(0xFFFFF9FF)
// (0xFFFFF000~0xFFFFF0FF)
#define EAPI_STATUS_ERROR					EAPI_UINT32_C(0xFFFFF0FF)
// (0)											
#define EAPI_STATUS_SUCCESS					EAPI_UINT32_C(0)

// (0xFFFFF100~0xFFFFF1FF)
#define EAPI_STATUS_SW_TIMEOUT				EAPI_UINT32_C(0xFFFFF1FF)
#define EAPI_STATUS_HW_TIMEOUT				EAPI_UINT32_C(0xFFFFF1FE)


#endif // _SUSI_DEBUG_H_
