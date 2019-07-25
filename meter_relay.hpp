

/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from meter_relay.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Connext distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Connext manual.
*/

#ifndef meter_relay_1882284457_hpp
#define meter_relay_1882284457_hpp

#include <iosfwd>
#include "meter_relayImpl.h"

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport __declspec(dllexport)
#endif

#include "dds/domain/DomainParticipant.hpp"
#include "dds/topic/TopicTraits.hpp"
#include "dds/core/SafeEnumeration.hpp"
#include "dds/core/String.hpp"
#include "dds/core/array.hpp"
#include "dds/core/vector.hpp"
#include "dds/core/Optional.hpp"
#include "dds/core/xtypes/DynamicType.hpp"
#include "dds/core/xtypes/StructType.hpp"
#include "dds/core/xtypes/UnionType.hpp"
#include "dds/core/xtypes/EnumType.hpp"
#include "dds/core/xtypes/AliasType.hpp"
#include "rti/core/array.hpp"
#include "rti/util/StreamFlagSaver.hpp"
#include "rti/domain/PluginSupport.hpp"
#include "rti/core/LongDouble.hpp"
#include "rti/core/Pointer.hpp"
#include "rti/topic/TopicTraits.hpp"
#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef RTIUSERDllExport
#define RTIUSERDllExport
#endif

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

namespace two {

    class NDDSUSERDllExport Meter {

      public:
        Meter();

        Meter(
            int32_t id_param,
            float voltage_param,
            float current_param,
            float power_param,
            float frequency_param,
            float pf_param,
            const dds::core::string& status_param);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        Meter (Meter&&) = default;
        Meter& operator=(Meter&&) = default;
        Meter& operator=(const Meter&) = default;
        Meter(const Meter&) = default;
        #else
        Meter(Meter&& other_) OMG_NOEXCEPT;  
        Meter& operator=(Meter&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        int32_t id() const OMG_NOEXCEPT;
        void id(int32_t value);

        float voltage() const OMG_NOEXCEPT;
        void voltage(float value);

        float current() const OMG_NOEXCEPT;
        void current(float value);

        float power() const OMG_NOEXCEPT;
        void power(float value);

        float frequency() const OMG_NOEXCEPT;
        void frequency(float value);

        float pf() const OMG_NOEXCEPT;
        void pf(float value);

        dds::core::string& status() OMG_NOEXCEPT; 
        const dds::core::string& status() const OMG_NOEXCEPT;
        void status(const dds::core::string& value);

        bool operator == (const Meter& other_) const;
        bool operator != (const Meter& other_) const;

        void swap(Meter& other_) OMG_NOEXCEPT;

      private:

        int32_t m_id_;
        float m_voltage_;
        float m_current_;
        float m_power_;
        float m_frequency_;
        float m_pf_;
        dds::core::string m_status_;

    };

    inline void swap(Meter& a, Meter& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o,const Meter& sample);

    class NDDSUSERDllExport Relay {

      public:
        Relay();

        Relay(
            int32_t id_param,
            const dds::core::string& status_param);

        #ifdef RTI_CXX11_RVALUE_REFERENCES
        #ifndef RTI_CXX11_NO_IMPLICIT_MOVE_OPERATIONS
        Relay (Relay&&) = default;
        Relay& operator=(Relay&&) = default;
        Relay& operator=(const Relay&) = default;
        Relay(const Relay&) = default;
        #else
        Relay(Relay&& other_) OMG_NOEXCEPT;  
        Relay& operator=(Relay&&  other_) OMG_NOEXCEPT;
        #endif
        #endif 

        int32_t id() const OMG_NOEXCEPT;
        void id(int32_t value);

        dds::core::string& status() OMG_NOEXCEPT; 
        const dds::core::string& status() const OMG_NOEXCEPT;
        void status(const dds::core::string& value);

        bool operator == (const Relay& other_) const;
        bool operator != (const Relay& other_) const;

        void swap(Relay& other_) OMG_NOEXCEPT;

      private:

        int32_t m_id_;
        dds::core::string m_status_;

    };

    inline void swap(Relay& a, Relay& b)  OMG_NOEXCEPT 
    {
        a.swap(b);
    }

    NDDSUSERDllExport std::ostream& operator<<(std::ostream& o,const Relay& sample);

} // namespace two  
namespace dds { 
    namespace topic {

        template<>
        struct topic_type_name<two::Meter> {
            NDDSUSERDllExport static std::string value() {
                return "two::Meter";
            }
        };

        template<>
        struct is_topic_type<two::Meter> : public dds::core::true_type {};

        template<>
        struct topic_type_support<two::Meter> {

            NDDSUSERDllExport static void initialize_sample(two::Meter& sample);

            NDDSUSERDllExport static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const two::Meter& sample);

            NDDSUSERDllExport static void from_cdr_buffer(two::Meter& sample, const std::vector<char>& buffer);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::NON_STL;
        };

        template<>
        struct topic_type_name<two::Relay> {
            NDDSUSERDllExport static std::string value() {
                return "two::Relay";
            }
        };

        template<>
        struct is_topic_type<two::Relay> : public dds::core::true_type {};

        template<>
        struct topic_type_support<two::Relay> {

            NDDSUSERDllExport static void initialize_sample(two::Relay& sample);

            NDDSUSERDllExport static void register_type(
                dds::domain::DomainParticipant& participant,
                const std::string & type_name);

            NDDSUSERDllExport static std::vector<char>& to_cdr_buffer(
                std::vector<char>& buffer, const two::Relay& sample);

            NDDSUSERDllExport static void from_cdr_buffer(two::Relay& sample, const std::vector<char>& buffer);

            static const rti::topic::TypePluginKind::type type_plugin_kind = 
            rti::topic::TypePluginKind::NON_STL;
        };

    }
}

namespace rti { 
    namespace topic {
        template<>
        struct dynamic_type<two::Meter> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template<>
        struct impl_type<two::Meter> {
            typedef two_Meter_c type;
        };

        template<>
        struct dynamic_type<two::Relay> {
            typedef dds::core::xtypes::StructType type;
            NDDSUSERDllExport static const dds::core::xtypes::StructType& get();
        };

        template<>
        struct impl_type<two::Relay> {
            typedef two_Relay_c type;
        };

    }
}

#if (defined(RTI_WIN32) || defined (RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif // meter_relay_1882284457_hpp

