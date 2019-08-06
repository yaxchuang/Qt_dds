

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from meter_relay.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#include <iosfwd>
#include <iomanip>
#include "meter_relay.hpp"
#include "meter_relayImplPlugin.h"

#include <rti/util/ostream_operators.hpp>

namespace two {

    // ---- Meter: 

    Meter::Meter() :
        m_init_value_ (0) ,
        m_id_ (0) ,
        m_voltage_ (0.0f) ,
        m_current_ (0.0f) ,
        m_power_ (0.0f) ,
        m_frequency_ (0.0f) ,
        m_pf_ (0.0f) ,
        m_status_ (0) ,
        m_padding_ (0) {
    }   

    Meter::Meter (
        int32_t init_value_param,
        int32_t id_param,
        float voltage_param,
        float current_param,
        float power_param,
        float frequency_param,
        float pf_param,
        int32_t status_param,
        int32_t padding_param)
        :
            m_init_value_( init_value_param ),
            m_id_( id_param ),
            m_voltage_( voltage_param ),
            m_current_( current_param ),
            m_power_( power_param ),
            m_frequency_( frequency_param ),
            m_pf_( pf_param ),
            m_status_( status_param ),
            m_padding_( padding_param ) {
    }
    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    Meter::Meter(Meter&& other_) OMG_NOEXCEPT  :m_init_value_ (std::move(other_.m_init_value_))
    ,
    m_id_ (std::move(other_.m_id_))
    ,
    m_voltage_ (std::move(other_.m_voltage_))
    ,
    m_current_ (std::move(other_.m_current_))
    ,
    m_power_ (std::move(other_.m_power_))
    ,
    m_frequency_ (std::move(other_.m_frequency_))
    ,
    m_pf_ (std::move(other_.m_pf_))
    ,
    m_status_ (std::move(other_.m_status_))
    ,
    m_padding_ (std::move(other_.m_padding_))
    {
    } 

    Meter& Meter::operator=(Meter&&  other_) OMG_NOEXCEPT {
        Meter tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void Meter::swap(Meter& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_init_value_, other_.m_init_value_);
        swap(m_id_, other_.m_id_);
        swap(m_voltage_, other_.m_voltage_);
        swap(m_current_, other_.m_current_);
        swap(m_power_, other_.m_power_);
        swap(m_frequency_, other_.m_frequency_);
        swap(m_pf_, other_.m_pf_);
        swap(m_status_, other_.m_status_);
        swap(m_padding_, other_.m_padding_);
    }  

    bool Meter::operator == (const Meter& other_) const {
        if (m_init_value_ != other_.m_init_value_) {
            return false;
        }
        if (m_id_ != other_.m_id_) {
            return false;
        }
        if (m_voltage_ != other_.m_voltage_) {
            return false;
        }
        if (m_current_ != other_.m_current_) {
            return false;
        }
        if (m_power_ != other_.m_power_) {
            return false;
        }
        if (m_frequency_ != other_.m_frequency_) {
            return false;
        }
        if (m_pf_ != other_.m_pf_) {
            return false;
        }
        if (m_status_ != other_.m_status_) {
            return false;
        }
        if (m_padding_ != other_.m_padding_) {
            return false;
        }
        return true;
    }
    bool Meter::operator != (const Meter& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    int32_t two::Meter::init_value() const OMG_NOEXCEPT{
        return m_init_value_;
    }

    void two::Meter::init_value(int32_t value) {
        m_init_value_ = value;
    }

    int32_t two::Meter::id() const OMG_NOEXCEPT{
        return m_id_;
    }

    void two::Meter::id(int32_t value) {
        m_id_ = value;
    }

    float two::Meter::voltage() const OMG_NOEXCEPT{
        return m_voltage_;
    }

    void two::Meter::voltage(float value) {
        m_voltage_ = value;
    }

    float two::Meter::current() const OMG_NOEXCEPT{
        return m_current_;
    }

    void two::Meter::current(float value) {
        m_current_ = value;
    }

    float two::Meter::power() const OMG_NOEXCEPT{
        return m_power_;
    }

    void two::Meter::power(float value) {
        m_power_ = value;
    }

    float two::Meter::frequency() const OMG_NOEXCEPT{
        return m_frequency_;
    }

    void two::Meter::frequency(float value) {
        m_frequency_ = value;
    }

    float two::Meter::pf() const OMG_NOEXCEPT{
        return m_pf_;
    }

    void two::Meter::pf(float value) {
        m_pf_ = value;
    }

    int32_t two::Meter::status() const OMG_NOEXCEPT{
        return m_status_;
    }

    void two::Meter::status(int32_t value) {
        m_status_ = value;
    }

    int32_t two::Meter::padding() const OMG_NOEXCEPT{
        return m_padding_;
    }

    void two::Meter::padding(int32_t value) {
        m_padding_ = value;
    }

    std::ostream& operator << (std::ostream& o,const Meter& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "init_value: " << sample.init_value()<<", ";
        o << "id: " << sample.id()<<", ";
        o << "voltage: " << std::setprecision(9) <<sample.voltage()<<", ";
        o << "current: " << std::setprecision(9) <<sample.current()<<", ";
        o << "power: " << std::setprecision(9) <<sample.power()<<", ";
        o << "frequency: " << std::setprecision(9) <<sample.frequency()<<", ";
        o << "pf: " << std::setprecision(9) <<sample.pf()<<", ";
        o << "status: " << sample.status()<<", ";
        o << "padding: " << sample.padding() ;
        o <<"]";
        return o;
    }

    // ---- Relay: 

    Relay::Relay() :
        m_init_value_ (0) ,
        m_id_ (0) ,
        m_status_ (0) ,
        m_padding1_ (0) ,
        m_padding2_ (0) {
    }   

    Relay::Relay (
        int32_t init_value_param,
        int32_t id_param,
        int32_t status_param,
        int32_t padding1_param,
        int32_t padding2_param)
        :
            m_init_value_( init_value_param ),
            m_id_( id_param ),
            m_status_( status_param ),
            m_padding1_( padding1_param ),
            m_padding2_( padding2_param ) {
    }
    #ifdef RTI_CXX11_RVALUE_REFERENCES
    #ifdef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
    Relay::Relay(Relay&& other_) OMG_NOEXCEPT  :m_init_value_ (std::move(other_.m_init_value_))
    ,
    m_id_ (std::move(other_.m_id_))
    ,
    m_status_ (std::move(other_.m_status_))
    ,
    m_padding1_ (std::move(other_.m_padding1_))
    ,
    m_padding2_ (std::move(other_.m_padding2_))
    {
    } 

    Relay& Relay::operator=(Relay&&  other_) OMG_NOEXCEPT {
        Relay tmp(std::move(other_));
        swap(tmp); 
        return *this;
    }
    #endif
    #endif   

    void Relay::swap(Relay& other_)  OMG_NOEXCEPT 
    {
        using std::swap;
        swap(m_init_value_, other_.m_init_value_);
        swap(m_id_, other_.m_id_);
        swap(m_status_, other_.m_status_);
        swap(m_padding1_, other_.m_padding1_);
        swap(m_padding2_, other_.m_padding2_);
    }  

    bool Relay::operator == (const Relay& other_) const {
        if (m_init_value_ != other_.m_init_value_) {
            return false;
        }
        if (m_id_ != other_.m_id_) {
            return false;
        }
        if (m_status_ != other_.m_status_) {
            return false;
        }
        if (m_padding1_ != other_.m_padding1_) {
            return false;
        }
        if (m_padding2_ != other_.m_padding2_) {
            return false;
        }
        return true;
    }
    bool Relay::operator != (const Relay& other_) const {
        return !this->operator ==(other_);
    }

    // --- Getters and Setters: -------------------------------------------------
    int32_t two::Relay::init_value() const OMG_NOEXCEPT{
        return m_init_value_;
    }

    void two::Relay::init_value(int32_t value) {
        m_init_value_ = value;
    }

    int32_t two::Relay::id() const OMG_NOEXCEPT{
        return m_id_;
    }

    void two::Relay::id(int32_t value) {
        m_id_ = value;
    }

    int32_t two::Relay::status() const OMG_NOEXCEPT{
        return m_status_;
    }

    void two::Relay::status(int32_t value) {
        m_status_ = value;
    }

    int32_t two::Relay::padding1() const OMG_NOEXCEPT{
        return m_padding1_;
    }

    void two::Relay::padding1(int32_t value) {
        m_padding1_ = value;
    }

    int32_t two::Relay::padding2() const OMG_NOEXCEPT{
        return m_padding2_;
    }

    void two::Relay::padding2(int32_t value) {
        m_padding2_ = value;
    }

    std::ostream& operator << (std::ostream& o,const Relay& sample)
    {
        rti::util::StreamFlagSaver flag_saver (o);
        o <<"[";
        o << "init_value: " << sample.init_value()<<", ";
        o << "id: " << sample.id()<<", ";
        o << "status: " << sample.status()<<", ";
        o << "padding1: " << sample.padding1()<<", ";
        o << "padding2: " << sample.padding2() ;
        o <<"]";
        return o;
    }

} // namespace two  

// --- Type traits: -------------------------------------------------

namespace rti { 
    namespace topic {

        const dds::core::xtypes::StructType& dynamic_type<two::Meter>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(two_Meter_c_get_typecode())));
        }

        const dds::core::xtypes::StructType& dynamic_type<two::Relay>::get()
        {
            return static_cast<const dds::core::xtypes::StructType&>(
                rti::core::native_conversions::cast_from_native<dds::core::xtypes::DynamicType>(
                    *(two_Relay_c_get_typecode())));
        }

    }
}  

namespace dds { 
    namespace topic {
        void topic_type_support<two::Meter>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name){

            rti::domain::register_type_plugin(
                participant,
                type_name,
                two_Meter_cPlugin_new,
                two_Meter_cPlugin_delete);
        }

        void topic_type_support<two::Meter>::initialize_sample(two::Meter& sample){

            two_Meter_c* native_sample=reinterpret_cast<two_Meter_c*> (&sample);

            struct DDS_TypeDeallocationParams_t deAllocParams = {RTI_FALSE, RTI_FALSE};
            two_Meter_c_finalize_w_params(native_sample,&deAllocParams);

            struct DDS_TypeAllocationParams_t allocParams = {RTI_FALSE, RTI_FALSE, RTI_TRUE}; 
            RTIBool ok=two_Meter_c_initialize_w_params(native_sample,&allocParams);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to initialize_w_params");

        } 

        std::vector<char>& topic_type_support<two::Meter>::to_cdr_buffer(
            std::vector<char>& buffer, const two::Meter& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = two_Meter_cPlugin_serialize_to_cdr_buffer(
                NULL, &length,reinterpret_cast<const two_Meter_c*>(&sample));
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = two_Meter_cPlugin_serialize_to_cdr_buffer(
                &buffer[0], &length, reinterpret_cast<const two_Meter_c*>(&sample));
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;

        }

        void topic_type_support<two::Meter>::from_cdr_buffer(two::Meter& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = two_Meter_cPlugin_deserialize_from_cdr_buffer(
                reinterpret_cast<two_Meter_c*> (&sample), &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to create two::Meter from cdr buffer");
        }

        void topic_type_support<two::Relay>:: register_type(
            dds::domain::DomainParticipant& participant,
            const std::string& type_name){

            rti::domain::register_type_plugin(
                participant,
                type_name,
                two_Relay_cPlugin_new,
                two_Relay_cPlugin_delete);
        }

        void topic_type_support<two::Relay>::initialize_sample(two::Relay& sample){

            two_Relay_c* native_sample=reinterpret_cast<two_Relay_c*> (&sample);

            struct DDS_TypeDeallocationParams_t deAllocParams = {RTI_FALSE, RTI_FALSE};
            two_Relay_c_finalize_w_params(native_sample,&deAllocParams);

            struct DDS_TypeAllocationParams_t allocParams = {RTI_FALSE, RTI_FALSE, RTI_TRUE}; 
            RTIBool ok=two_Relay_c_initialize_w_params(native_sample,&allocParams);
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to initialize_w_params");

        } 

        std::vector<char>& topic_type_support<two::Relay>::to_cdr_buffer(
            std::vector<char>& buffer, const two::Relay& sample)
        {
            // First get the length of the buffer
            unsigned int length = 0;
            RTIBool ok = two_Relay_cPlugin_serialize_to_cdr_buffer(
                NULL, &length,reinterpret_cast<const two_Relay_c*>(&sample));
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to calculate cdr buffer size");

            // Create a vector with that size and copy the cdr buffer into it
            buffer.resize(length);
            ok = two_Relay_cPlugin_serialize_to_cdr_buffer(
                &buffer[0], &length, reinterpret_cast<const two_Relay_c*>(&sample));
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to copy cdr buffer");

            return buffer;

        }

        void topic_type_support<two::Relay>::from_cdr_buffer(two::Relay& sample, 
        const std::vector<char>& buffer)
        {

            RTIBool ok  = two_Relay_cPlugin_deserialize_from_cdr_buffer(
                reinterpret_cast<two_Relay_c*> (&sample), &buffer[0], 
                static_cast<unsigned int>(buffer.size()));
            rti::core::check_return_code(
                ok ? DDS_RETCODE_OK : DDS_RETCODE_ERROR,
                "Failed to create two::Relay from cdr buffer");
        }

    }
}  

