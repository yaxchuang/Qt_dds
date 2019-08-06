

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from meter_relayImpl.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef NDDS_STANDALONE_TYPE
#ifndef ndds_c_h
#include "ndds/ndds_c.h"
#endif

#ifndef cdr_type_h
#include "cdr/cdr_type.h"
#endif    

#ifndef osapi_heap_h
#include "osapi/osapi_heap.h" 
#endif
#else
#include "ndds_standalone_type.h"
#endif

#include "meter_relayImpl.h"

/* ========================================================================= */
const char *two_Meter_cTYPENAME = "two::Meter";

DDS_TypeCode* two_Meter_c_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member two_Meter_c_g_tc_members[9]=
    {

        {
            (char *)"init_value",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"id",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"voltage",/* Member name */
            {
                2,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"current",/* Member name */
            {
                3,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"power",/* Member name */
            {
                4,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"frequency",/* Member name */
            {
                5,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"pf",/* Member name */
            {
                6,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"status",/* Member name */
            {
                7,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"padding",/* Member name */
            {
                8,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode two_Meter_c_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"two::Meter", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            9, /* Number of members */
            two_Meter_c_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for two_Meter_c*/

    if (is_initialized) {
        return &two_Meter_c_g_tc;
    }

    two_Meter_c_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    two_Meter_c_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    two_Meter_c_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    two_Meter_c_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    two_Meter_c_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    two_Meter_c_g_tc_members[5]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    two_Meter_c_g_tc_members[6]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_float;

    two_Meter_c_g_tc_members[7]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    two_Meter_c_g_tc_members[8]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    is_initialized = RTI_TRUE;

    return &two_Meter_c_g_tc;
}

RTIBool two_Meter_c_initialize(
    two_Meter_c* sample) {
    return two_Meter_c_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool two_Meter_c_initialize_ex(
    two_Meter_c* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return two_Meter_c_initialize_w_params(
        sample,&allocParams);

}

RTIBool two_Meter_c_initialize_w_params(
    two_Meter_c* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initLong(&sample->init_value)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initLong(&sample->id)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->voltage)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->current)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->power)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->frequency)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initFloat(&sample->pf)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initLong(&sample->status)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initLong(&sample->padding)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

void two_Meter_c_finalize(
    two_Meter_c* sample)
{

    two_Meter_c_finalize_ex(sample,RTI_TRUE);
}

void two_Meter_c_finalize_ex(
    two_Meter_c* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    two_Meter_c_finalize_w_params(
        sample,&deallocParams);
}

void two_Meter_c_finalize_w_params(
    two_Meter_c* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void two_Meter_c_finalize_optional_members(
    two_Meter_c* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool two_Meter_c_copy(
    two_Meter_c* dst,
    const two_Meter_c* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_copyLong (
        &dst->init_value, &src->init_value)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyLong (
        &dst->id, &src->id)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->voltage, &src->voltage)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->current, &src->current)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->power, &src->power)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->frequency, &src->frequency)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyFloat (
        &dst->pf, &src->pf)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyLong (
        &dst->status, &src->status)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyLong (
        &dst->padding, &src->padding)) { 
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'two_Meter_c' sequence class.
*/
#define T two_Meter_c
#define TSeq two_Meter_cSeq

#define T_initialize_w_params two_Meter_c_initialize_w_params

#define T_finalize_w_params   two_Meter_c_finalize_w_params
#define T_copy       two_Meter_c_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

/* ========================================================================= */
const char *two_Relay_cTYPENAME = "two::Relay";

DDS_TypeCode* two_Relay_c_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member two_Relay_c_g_tc_members[5]=
    {

        {
            (char *)"init_value",/* Member name */
            {
                0,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"id",/* Member name */
            {
                1,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"status",/* Member name */
            {
                2,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"padding1",/* Member name */
            {
                3,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }, 
        {
            (char *)"padding2",/* Member name */
            {
                4,/* Representation ID */          
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL/* Ignored */
        }
    };

    static DDS_TypeCode two_Relay_c_g_tc =
    {{
            DDS_TK_STRUCT,/* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"two::Relay", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            5, /* Number of members */
            two_Relay_c_g_tc_members, /* Members */
            DDS_VM_NONE  /* Ignored */         
        }}; /* Type code for two_Relay_c*/

    if (is_initialized) {
        return &two_Relay_c_g_tc;
    }

    two_Relay_c_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    two_Relay_c_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    two_Relay_c_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    two_Relay_c_g_tc_members[3]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    two_Relay_c_g_tc_members[4]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_long;

    is_initialized = RTI_TRUE;

    return &two_Relay_c_g_tc;
}

RTIBool two_Relay_c_initialize(
    two_Relay_c* sample) {
    return two_Relay_c_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool two_Relay_c_initialize_ex(
    two_Relay_c* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return two_Relay_c_initialize_w_params(
        sample,&allocParams);

}

RTIBool two_Relay_c_initialize_w_params(
    two_Relay_c* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initLong(&sample->init_value)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initLong(&sample->id)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initLong(&sample->status)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initLong(&sample->padding1)) {
        return RTI_FALSE;
    }

    if (!RTICdrType_initLong(&sample->padding2)) {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

void two_Relay_c_finalize(
    two_Relay_c* sample)
{

    two_Relay_c_finalize_ex(sample,RTI_TRUE);
}

void two_Relay_c_finalize_ex(
    two_Relay_c* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    two_Relay_c_finalize_w_params(
        sample,&deallocParams);
}

void two_Relay_c_finalize_w_params(
    two_Relay_c* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void two_Relay_c_finalize_optional_members(
    two_Relay_c* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool two_Relay_c_copy(
    two_Relay_c* dst,
    const two_Relay_c* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    if (!RTICdrType_copyLong (
        &dst->init_value, &src->init_value)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyLong (
        &dst->id, &src->id)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyLong (
        &dst->status, &src->status)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyLong (
        &dst->padding1, &src->padding1)) { 
        return RTI_FALSE;
    }
    if (!RTICdrType_copyLong (
        &dst->padding2, &src->padding2)) { 
        return RTI_FALSE;
    }

    return RTI_TRUE;

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'two_Relay_c' sequence class.
*/
#define T two_Relay_c
#define TSeq two_Relay_cSeq

#define T_initialize_w_params two_Relay_c_initialize_w_params

#define T_finalize_w_params   two_Relay_c_finalize_w_params
#define T_copy       two_Relay_c_copy

#ifndef NDDS_STANDALONE_TYPE
#include "dds_c/generic/dds_c_sequence_TSeq.gen"
#else
#include "dds_c_sequence_TSeq.gen"
#endif

#undef T_copy
#undef T_finalize_w_params

#undef T_initialize_w_params

#undef TSeq
#undef T

