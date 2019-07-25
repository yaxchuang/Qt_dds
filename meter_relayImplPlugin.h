

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from meter_relayImpl.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef meter_relayImplPlugin_1882284457_h
#define meter_relayImplPlugin_1882284457_h

#include "meter_relayImpl.h"

struct RTICdrStream;

#ifndef pres_typePlugin_h
#include "pres/pres_typePlugin.h"
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#define two_Meter_cPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define two_Meter_cPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define two_Meter_cPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define two_Meter_cPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define two_Meter_cPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern two_Meter_c*
two_Meter_cPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern two_Meter_c*
two_Meter_cPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern two_Meter_c*
two_Meter_cPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
two_Meter_cPluginSupport_copy_data(
    two_Meter_c *out,
    const two_Meter_c *in);

NDDSUSERDllExport extern void 
two_Meter_cPluginSupport_destroy_data_w_params(
    two_Meter_c *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
two_Meter_cPluginSupport_destroy_data_ex(
    two_Meter_c *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
two_Meter_cPluginSupport_destroy_data(
    two_Meter_c *sample);

NDDSUSERDllExport extern void 
two_Meter_cPluginSupport_print_data(
    const two_Meter_c *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
two_Meter_cPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
two_Meter_cPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
two_Meter_cPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
two_Meter_cPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
two_Meter_cPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    two_Meter_c *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
two_Meter_cPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    two_Meter_c *out,
    const two_Meter_c *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
two_Meter_cPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const two_Meter_c *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
two_Meter_cPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    two_Meter_c *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
two_Meter_cPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const two_Meter_c *sample); 

NDDSUSERDllExport extern RTIBool 
two_Meter_cPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    two_Meter_c **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
two_Meter_cPlugin_deserialize_from_cdr_buffer(
    two_Meter_c *sample,
    const char * buffer,
    unsigned int length);    
NDDSUSERDllExport extern DDS_ReturnCode_t
two_Meter_cPlugin_data_to_string(
    const two_Meter_c *sample,
    char *str,
    DDS_UnsignedLong *str_size, 
    const struct DDS_PrintFormatProperty *property);    

NDDSUSERDllExport extern RTIBool
two_Meter_cPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
two_Meter_cPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
two_Meter_cPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
two_Meter_cPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
two_Meter_cPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const two_Meter_c * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
two_Meter_cPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
two_Meter_cPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
two_Meter_cPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
two_Meter_cPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const two_Meter_c *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
two_Meter_cPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    two_Meter_c * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
two_Meter_cPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    two_Meter_c ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
two_Meter_cPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    two_Meter_c *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
two_Meter_cPlugin_new(void);

NDDSUSERDllExport extern void
two_Meter_cPlugin_delete(struct PRESTypePlugin *);

#define two_Relay_cPlugin_get_sample PRESTypePluginDefaultEndpointData_getSample 
#define two_Relay_cPlugin_get_buffer PRESTypePluginDefaultEndpointData_getBuffer 
#define two_Relay_cPlugin_return_buffer PRESTypePluginDefaultEndpointData_returnBuffer 

#define two_Relay_cPlugin_create_sample PRESTypePluginDefaultEndpointData_createSample 
#define two_Relay_cPlugin_destroy_sample PRESTypePluginDefaultEndpointData_deleteSample 

/* --------------------------------------------------------------------------------------
Support functions:
* -------------------------------------------------------------------------------------- */

NDDSUSERDllExport extern two_Relay_c*
two_Relay_cPluginSupport_create_data_w_params(
    const struct DDS_TypeAllocationParams_t * alloc_params);

NDDSUSERDllExport extern two_Relay_c*
two_Relay_cPluginSupport_create_data_ex(RTIBool allocate_pointers);

NDDSUSERDllExport extern two_Relay_c*
two_Relay_cPluginSupport_create_data(void);

NDDSUSERDllExport extern RTIBool 
two_Relay_cPluginSupport_copy_data(
    two_Relay_c *out,
    const two_Relay_c *in);

NDDSUSERDllExport extern void 
two_Relay_cPluginSupport_destroy_data_w_params(
    two_Relay_c *sample,
    const struct DDS_TypeDeallocationParams_t * dealloc_params);

NDDSUSERDllExport extern void 
two_Relay_cPluginSupport_destroy_data_ex(
    two_Relay_c *sample,RTIBool deallocate_pointers);

NDDSUSERDllExport extern void 
two_Relay_cPluginSupport_destroy_data(
    two_Relay_c *sample);

NDDSUSERDllExport extern void 
two_Relay_cPluginSupport_print_data(
    const two_Relay_c *sample,
    const char *desc,
    unsigned int indent);

/* ----------------------------------------------------------------------------
Callback functions:
* ---------------------------------------------------------------------------- */

NDDSUSERDllExport extern PRESTypePluginParticipantData 
two_Relay_cPlugin_on_participant_attached(
    void *registration_data, 
    const struct PRESTypePluginParticipantInfo *participant_info,
    RTIBool top_level_registration, 
    void *container_plugin_context,
    RTICdrTypeCode *typeCode);

NDDSUSERDllExport extern void 
two_Relay_cPlugin_on_participant_detached(
    PRESTypePluginParticipantData participant_data);

NDDSUSERDllExport extern PRESTypePluginEndpointData 
two_Relay_cPlugin_on_endpoint_attached(
    PRESTypePluginParticipantData participant_data,
    const struct PRESTypePluginEndpointInfo *endpoint_info,
    RTIBool top_level_registration, 
    void *container_plugin_context);

NDDSUSERDllExport extern void 
two_Relay_cPlugin_on_endpoint_detached(
    PRESTypePluginEndpointData endpoint_data);

NDDSUSERDllExport extern void    
two_Relay_cPlugin_return_sample(
    PRESTypePluginEndpointData endpoint_data,
    two_Relay_c *sample,
    void *handle);    

NDDSUSERDllExport extern RTIBool 
two_Relay_cPlugin_copy_sample(
    PRESTypePluginEndpointData endpoint_data,
    two_Relay_c *out,
    const two_Relay_c *in);

/* ----------------------------------------------------------------------------
(De)Serialize functions:
* ------------------------------------------------------------------------- */

NDDSUSERDllExport extern RTIBool 
two_Relay_cPlugin_serialize(
    PRESTypePluginEndpointData endpoint_data,
    const two_Relay_c *sample,
    struct RTICdrStream *stream, 
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
two_Relay_cPlugin_deserialize_sample(
    PRESTypePluginEndpointData endpoint_data,
    two_Relay_c *sample, 
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
two_Relay_cPlugin_serialize_to_cdr_buffer(
    char * buffer,
    unsigned int * length,
    const two_Relay_c *sample); 

NDDSUSERDllExport extern RTIBool 
two_Relay_cPlugin_deserialize(
    PRESTypePluginEndpointData endpoint_data,
    two_Relay_c **sample, 
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
two_Relay_cPlugin_deserialize_from_cdr_buffer(
    two_Relay_c *sample,
    const char * buffer,
    unsigned int length);    
NDDSUSERDllExport extern DDS_ReturnCode_t
two_Relay_cPlugin_data_to_string(
    const two_Relay_c *sample,
    char *str,
    DDS_UnsignedLong *str_size, 
    const struct DDS_PrintFormatProperty *property);    

NDDSUSERDllExport extern RTIBool
two_Relay_cPlugin_skip(
    PRESTypePluginEndpointData endpoint_data,
    struct RTICdrStream *stream, 
    RTIBool skip_encapsulation,  
    RTIBool skip_sample, 
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern unsigned int 
two_Relay_cPlugin_get_serialized_sample_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);    

NDDSUSERDllExport extern unsigned int 
two_Relay_cPlugin_get_serialized_sample_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
two_Relay_cPlugin_get_serialized_sample_min_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int
two_Relay_cPlugin_get_serialized_sample_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment,
    const two_Relay_c * sample);

/* --------------------------------------------------------------------------------------
Key Management functions:
* -------------------------------------------------------------------------------------- */
NDDSUSERDllExport extern PRESTypePluginKeyKind 
two_Relay_cPlugin_get_key_kind(void);

NDDSUSERDllExport extern unsigned int 
two_Relay_cPlugin_get_serialized_key_max_size_ex(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool * overflow,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern unsigned int 
two_Relay_cPlugin_get_serialized_key_max_size(
    PRESTypePluginEndpointData endpoint_data,
    RTIBool include_encapsulation,
    RTIEncapsulationId encapsulation_id,
    unsigned int current_alignment);

NDDSUSERDllExport extern RTIBool 
two_Relay_cPlugin_serialize_key(
    PRESTypePluginEndpointData endpoint_data,
    const two_Relay_c *sample,
    struct RTICdrStream *stream,
    RTIBool serialize_encapsulation,
    RTIEncapsulationId encapsulation_id,
    RTIBool serialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
two_Relay_cPlugin_deserialize_key_sample(
    PRESTypePluginEndpointData endpoint_data,
    two_Relay_c * sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool 
two_Relay_cPlugin_deserialize_key(
    PRESTypePluginEndpointData endpoint_data,
    two_Relay_c ** sample,
    RTIBool * drop_sample,
    struct RTICdrStream *stream,
    RTIBool deserialize_encapsulation,
    RTIBool deserialize_key,
    void *endpoint_plugin_qos);

NDDSUSERDllExport extern RTIBool
two_Relay_cPlugin_serialized_sample_to_key(
    PRESTypePluginEndpointData endpoint_data,
    two_Relay_c *sample,
    struct RTICdrStream *stream, 
    RTIBool deserialize_encapsulation,  
    RTIBool deserialize_key, 
    void *endpoint_plugin_qos);

/* Plugin Functions */
NDDSUSERDllExport extern struct PRESTypePlugin*
two_Relay_cPlugin_new(void);

NDDSUSERDllExport extern void
two_Relay_cPlugin_delete(struct PRESTypePlugin *);

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* meter_relayImplPlugin_1882284457_h */
