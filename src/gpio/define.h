#ifndef _DEFINE_H_
#define _DEFINE_H_

///////////////////////////////////////////////////////////////////////////////
// EAPI ID
// Board information
#define EAPI_ID_BOARD_MANUFACTURER_STR			0x00000000 // Board Manufacturer Name String
#define EAPI_ID_BOARD_NAME_STR					0x00000001 // Board Name String
#define EAPI_ID_BOARD_REVISION_STR				0x00000002 // Board Name String
#define EAPI_ID_BOARD_SERIAL_STR				0x00000003 // Board Serial Number String
#define EAPI_ID_BOARD_BIOS_REVISION_STR			0x00000004 // Board Bios Revision String
#define EAPI_ID_BOARD_HW_REVISION_STR			0x00000005 // Board Hardware Revision String
#define EAPI_ID_BOARD_PLATFORM_TYPE_STR			0x00000006 // Platform ID(ETX, COM Express,etc...)

//
#define EAPI_ID_GET_EAPI_SPEC_VERSION			0x00000000 /* EAPI Specification 
                                                            * Revision I.E. The 
                                                            * EAPI Spec Version 
                                                            * Bits 31-24, Revision 
                                                            * 23-16, 15-0 always 0
                                                            * Used to implement 
                                                            * this interface
                                                            */
#define EAPI_ID_BOARD_BOOT_COUNTER_VAL			0x00000001 // Units = Boots
#define EAPI_ID_BOARD_RUNNING_TIME_METER_VAL	0x00000002 // Units = Minutes
#define EAPI_ID_BOARD_PNPID_VAL					0x00000003 /* Encoded PNP ID 
                                                            * Format 
                                                            * (Compressed ASCII)
                                                            */
#define EAPI_ID_BOARD_PLATFORM_REV_VAL			0x00000004 /* Platform Revision 
                                                            * I.E. The PICMG Spec 
                                                            * Version Bits 31-24,
                                                            * Revision 23-16, 
                                                            * 15-0 always 0
                                                            */
#define EAPI_ID_BOARD_DRIVER_VERSION_VAL		0x00010000 // Vendor Specific(Optional)
#define EAPI_ID_BOARD_LIB_VERSION_VAL			0x00010001 // Vendor Specific(Optional)
#define EAPI_ID_BOARD_FIRMWARE_VERSION_VAL		0x00010002

// Temperature
#define EAPI_ID_HWMON_CPU_TEMP					0x00020000 // 1 centigrade
#define EAPI_ID_HWMON_CHIPSET_TEMP				0x00020001 // 1 centigrade
#define EAPI_ID_HWMON_SYSTEM_TEMP				0x00020002 // 1 centigrade

#define EAPI_ID_HWMON_CPU_TEMP1					0x00020010 // 1 centigrade
#define EAPI_ID_HWMON_CHIPSET_TEMP1				0x00020011 // 1 centigrade
#define EAPI_ID_HWMON_SYSTEM_TEMP1				0x00020012 // 1 centigrade

#define EAPI_ID_HWMON_CPU_TEMP2					0x00020020 // 1 centigrade
#define EAPI_ID_HWMON_CHIPSET_TEMP2				0x00020021 // 1 centigrade
#define EAPI_ID_HWMON_SYSTEM_TEMP2				0x00020022 // 1 centigrade

#define EAPI_ID_HWMON_CPU_TEMP3					0x00020030 // 1 centigrade
#define EAPI_ID_HWMON_CHIPSET_TEMP3				0x00020031 // 1 centigrade
#define EAPI_ID_HWMON_SYSTEM_TEMP3				0x00020032 // 1 centigrade

// VOLTAGE
#define EAPI_ID_HWMON_VOLTAGE_VCORE				0x00021004 // Volt.11
#define EAPI_ID_HWMON_VOLTAGE_2V5				0x00021008 // Volt.6
#define EAPI_ID_HWMON_VOLTAGE_3V3				0x0002100C // Volt.9
#define EAPI_ID_HWMON_VOLTAGE_VBAT				0x00021010 // Volt.3
#define EAPI_ID_HWMON_VOLTAGE_5V				0x00021014 // Volt.7
#define EAPI_ID_HWMON_VOLTAGE_5VSB				0x00021018 // Volt.8
#define EAPI_ID_HWMON_VOLTAGE_12V				0x0002101C // Volt.13

// Fan
#define EAPI_ID_HWMON_FAN_CPU					0x00022000 // RPM
#define EAPI_ID_HWMON_FAN_SYSTEM				0x00022001 // RPM
#define EAPI_ID_HWMON_FAN_THIRD					0x00022002 // RPM

// Backlight
#define EAPI_ID_BACKLIGHT_1			0x00000000
#define EAPI_ID_BACKLIGHT_2			0x00000001
#define EAPI_ID_BACKLIGHT_3			0x00000002
#define EAPI_ID_BACKLIGHT_BY_PCH	0x0000000F

#define EAPI_BACKLIGHT_SET_ON			0x00000000
#define EAPI_BACKLIGHT_SET_OFF			0xFFFFFFFF
#define EAPI_BACKLIGHT_SET_DIMEST		0
#define EAPI_BACKLIGHT_SET_BRIGHTEST	100
#define EAPI_BACKLIGHT_SET_FREQUENCYEST	1000000
#define EAPI_BACKLIGHT_SET_LEVELEST		9		

// GPIO ID
#define EAPI_GPIO_ID0	0x00000000
#define EAPI_GPIO_ID1	0x00000001
#define EAPI_GPIO_ID2	0x00000002
#define EAPI_GPIO_ID3	0x00000003
#define EAPI_GPIO_ID4	0x00000004
#define EAPI_GPIO_ID5	0x00000005
#define EAPI_GPIO_ID6	0x00000006
#define EAPI_GPIO_ID7	0x00000007

#define EAPI_ID_GPIO_BANK00	0x00010000
#define EAPI_ID_GPIO_BANK01	0x00010001
#define EAPI_ID_GPIO_BANK02	0x00010002

#define EAPI_GPIO_BITMASK_SELECT   1
#define EAPI_GPIO_BITMASK_NOSELECT 0

#define EAPI_GPIO_LOW     0
#define EAPI_GPIO_HIGH    1

#define EAPI_GPIO_INPUT   1
#define EAPI_GPIO_OUTPUT  0

// I2C Bus
#define EAPI_ID_I2C_EXTERNAL	0x00000000	
#define EAPI_ID_I2C_LVDS_1		0x00000001
#define EAPI_ID_I2C_LVDS_2		0x00000002

#define EAPI_I2C_STD_CMD          (0<<30)
#define EAPI_I2C_EXT_CMD          (2<<30)
#define EAPI_I2C_NO_CMD           (1<<30)    
#define EAPI_I2C_CMD_TYPE_MASK    (3<<30)

// Storage
#define EAPI_ID_STORAGE_STD 0x00000000 // Standard Storage Area >=32Bytes for read/write access

// Thermal Protection
#define EAPI_ID_THERMAL_PROTECTION_0	0x00000000
#define EAPI_ID_THERMAL_PROTECTION_1	0x00000001
#define EAPI_ID_THERMAL_PROTECTION_2	0x00000002
#define EAPI_ID_THERMAL_PROTECTION_3	0x00000003

// EAPI ID
///////////////////////////////////////////////////////////////////////////////

#endif