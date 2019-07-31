

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from meter_relayImpl.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef meter_relayImpl_1882284563_h
#define meter_relayImpl_1882284563_h

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif
#else
#include "ndds_standalone_type.h"
#endif

extern const char *two_Meter_cTYPENAME;

typedef struct two_Meter_c {

    DDS_Float   init_value ;
    DDS_Long   id ;
    DDS_Float   voltage ;
    DDS_Float   current ;
    DDS_Float   power ;
    DDS_Float   frequency ;
    DDS_Float   pf ;
    DDS_Long   status ;
    DDS_Long   padding ;

    two_Meter_c() {}

} two_Meter_c ;
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* two_Meter_c_get_typecode(void); /* Type code */

DDS_SEQUENCE(two_Meter_cSeq, two_Meter_c);

NDDSUSERDllExport
RTIBool two_Meter_c_initialize(
    two_Meter_c* self);

NDDSUSERDllExport
RTIBool two_Meter_c_initialize_ex(
    two_Meter_c* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool two_Meter_c_initialize_w_params(
    two_Meter_c* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
void two_Meter_c_finalize(
    two_Meter_c* self);

NDDSUSERDllExport
void two_Meter_c_finalize_ex(
    two_Meter_c* self,RTIBool deletePointers);

NDDSUSERDllExport
void two_Meter_c_finalize_w_params(
    two_Meter_c* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void two_Meter_c_finalize_optional_members(
    two_Meter_c* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool two_Meter_c_copy(
    two_Meter_c* dst,
    const two_Meter_c* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

extern const char *two_Relay_cTYPENAME;

typedef struct two_Relay_c {

    DDS_Float   init_value ;
    DDS_Long   id ;
    DDS_Long   status ;
    DDS_Long   padding1 ;
    DDS_Long   padding2 ;

    two_Relay_c() {}

} two_Relay_c ;
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

NDDSUSERDllExport DDS_TypeCode* two_Relay_c_get_typecode(void); /* Type code */

DDS_SEQUENCE(two_Relay_cSeq, two_Relay_c);

NDDSUSERDllExport
RTIBool two_Relay_c_initialize(
    two_Relay_c* self);

NDDSUSERDllExport
RTIBool two_Relay_c_initialize_ex(
    two_Relay_c* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool two_Relay_c_initialize_w_params(
    two_Relay_c* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
void two_Relay_c_finalize(
    two_Relay_c* self);

NDDSUSERDllExport
void two_Relay_c_finalize_ex(
    two_Relay_c* self,RTIBool deletePointers);

NDDSUSERDllExport
void two_Relay_c_finalize_w_params(
    two_Relay_c* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void two_Relay_c_finalize_optional_members(
    two_Relay_c* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool two_Relay_c_copy(
    two_Relay_c* dst,
    const two_Relay_c* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* meter_relayImpl */

