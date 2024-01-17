//
// Generated file, do not edit! Created by opp_msgtool 6.0 from src/dtnsim.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "dtnsim_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

class CgrRouteDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
    };
  public:
    CgrRouteDescriptor();
    virtual ~CgrRouteDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(CgrRouteDescriptor)

CgrRouteDescriptor::CgrRouteDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(CgrRoute)), "")
{
    propertyNames = nullptr;
}

CgrRouteDescriptor::~CgrRouteDescriptor()
{
    delete[] propertyNames;
}

bool CgrRouteDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CgrRoute *>(obj)!=nullptr;
}

const char **CgrRouteDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *CgrRouteDescriptor::getProperty(const char *propertyName) const
{
    if (!strcmp(propertyName, "existingClass")) return "";
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int CgrRouteDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 0+base->getFieldCount() : 0;
}

unsigned int CgrRouteDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    return 0;
}

const char *CgrRouteDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

int CgrRouteDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->findField(fieldName) : -1;
}

const char *CgrRouteDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

const char **CgrRouteDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *CgrRouteDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int CgrRouteDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    CgrRoute *pp = omnetpp::fromAnyPtr<CgrRoute>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void CgrRouteDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    CgrRoute *pp = omnetpp::fromAnyPtr<CgrRoute>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'CgrRoute'", field);
    }
}

const char *CgrRouteDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    CgrRoute *pp = omnetpp::fromAnyPtr<CgrRoute>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CgrRouteDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    CgrRoute *pp = omnetpp::fromAnyPtr<CgrRoute>(object); (void)pp;
    switch (field) {
        default: return "";
    }
}

void CgrRouteDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CgrRoute *pp = omnetpp::fromAnyPtr<CgrRoute>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CgrRoute'", field);
    }
}

omnetpp::cValue CgrRouteDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    CgrRoute *pp = omnetpp::fromAnyPtr<CgrRoute>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'CgrRoute' as cValue -- field index out of range?", field);
    }
}

void CgrRouteDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CgrRoute *pp = omnetpp::fromAnyPtr<CgrRoute>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CgrRoute'", field);
    }
}

const char *CgrRouteDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

omnetpp::any_ptr CgrRouteDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    CgrRoute *pp = omnetpp::fromAnyPtr<CgrRoute>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void CgrRouteDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    CgrRoute *pp = omnetpp::fromAnyPtr<CgrRoute>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CgrRoute'", field);
    }
}

class intListDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
    };
  public:
    intListDescriptor();
    virtual ~intListDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(intListDescriptor)

intListDescriptor::intListDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(intList)), "")
{
    propertyNames = nullptr;
}

intListDescriptor::~intListDescriptor()
{
    delete[] propertyNames;
}

bool intListDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<intList *>(obj)!=nullptr;
}

const char **intListDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = { "existingClass",  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *intListDescriptor::getProperty(const char *propertyName) const
{
    if (!strcmp(propertyName, "existingClass")) return "";
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int intListDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 0+base->getFieldCount() : 0;
}

unsigned int intListDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    return 0;
}

const char *intListDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

int intListDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->findField(fieldName) : -1;
}

const char *intListDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

const char **intListDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *intListDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int intListDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    intList *pp = omnetpp::fromAnyPtr<intList>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void intListDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    intList *pp = omnetpp::fromAnyPtr<intList>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'intList'", field);
    }
}

const char *intListDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    intList *pp = omnetpp::fromAnyPtr<intList>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string intListDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    intList *pp = omnetpp::fromAnyPtr<intList>(object); (void)pp;
    switch (field) {
        default: return "";
    }
}

void intListDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    intList *pp = omnetpp::fromAnyPtr<intList>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'intList'", field);
    }
}

omnetpp::cValue intListDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    intList *pp = omnetpp::fromAnyPtr<intList>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'intList' as cValue -- field index out of range?", field);
    }
}

void intListDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    intList *pp = omnetpp::fromAnyPtr<intList>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'intList'", field);
    }
}

const char *intListDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    return nullptr;
}

omnetpp::any_ptr intListDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    intList *pp = omnetpp::fromAnyPtr<intList>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void intListDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    intList *pp = omnetpp::fromAnyPtr<intList>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'intList'", field);
    }
}

Register_Class(BundlePkt)

BundlePkt::BundlePkt(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

BundlePkt::BundlePkt(const BundlePkt& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

BundlePkt::~BundlePkt()
{
}

BundlePkt& BundlePkt::operator=(const BundlePkt& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void BundlePkt::copy(const BundlePkt& other)
{
    this->bundleId = other.bundleId;
    this->sourceEid = other.sourceEid;
    this->destinationEid = other.destinationEid;
    this->critical = other.critical;
    this->creationTimestamp = other.creationTimestamp;
    this->ttl = other.ttl;
    this->returnToSender = other.returnToSender;
    this->custodyTransferRequested = other.custodyTransferRequested;
    this->cgrRoute = other.cgrRoute;
    this->bundleIsCustodyReport = other.bundleIsCustodyReport;
    this->custodyAccepted = other.custodyAccepted;
    this->custodyBundleId = other.custodyBundleId;
    this->custodianEid = other.custodianEid;
    this->senderEid = other.senderEid;
    this->nextHopEid = other.nextHopEid;
    this->hopCount = other.hopCount;
    this->visitedNodes = other.visitedNodes;
    this->xmitCopiesCount = other.xmitCopiesCount;
    this->dlvConfidence = other.dlvConfidence;
    this->bundlesCopies = other.bundlesCopies;
    this->qos = other.qos;
}

void BundlePkt::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->bundleId);
    doParsimPacking(b,this->sourceEid);
    doParsimPacking(b,this->destinationEid);
    doParsimPacking(b,this->critical);
    doParsimPacking(b,this->creationTimestamp);
    doParsimPacking(b,this->ttl);
    doParsimPacking(b,this->returnToSender);
    doParsimPacking(b,this->custodyTransferRequested);
    doParsimPacking(b,this->cgrRoute);
    doParsimPacking(b,this->bundleIsCustodyReport);
    doParsimPacking(b,this->custodyAccepted);
    doParsimPacking(b,this->custodyBundleId);
    doParsimPacking(b,this->custodianEid);
    doParsimPacking(b,this->senderEid);
    doParsimPacking(b,this->nextHopEid);
    doParsimPacking(b,this->hopCount);
    doParsimPacking(b,this->visitedNodes);
    doParsimPacking(b,this->xmitCopiesCount);
    doParsimPacking(b,this->dlvConfidence);
    doParsimPacking(b,this->bundlesCopies);
    doParsimPacking(b,this->qos);
}

void BundlePkt::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->bundleId);
    doParsimUnpacking(b,this->sourceEid);
    doParsimUnpacking(b,this->destinationEid);
    doParsimUnpacking(b,this->critical);
    doParsimUnpacking(b,this->creationTimestamp);
    doParsimUnpacking(b,this->ttl);
    doParsimUnpacking(b,this->returnToSender);
    doParsimUnpacking(b,this->custodyTransferRequested);
    doParsimUnpacking(b,this->cgrRoute);
    doParsimUnpacking(b,this->bundleIsCustodyReport);
    doParsimUnpacking(b,this->custodyAccepted);
    doParsimUnpacking(b,this->custodyBundleId);
    doParsimUnpacking(b,this->custodianEid);
    doParsimUnpacking(b,this->senderEid);
    doParsimUnpacking(b,this->nextHopEid);
    doParsimUnpacking(b,this->hopCount);
    doParsimUnpacking(b,this->visitedNodes);
    doParsimUnpacking(b,this->xmitCopiesCount);
    doParsimUnpacking(b,this->dlvConfidence);
    doParsimUnpacking(b,this->bundlesCopies);
    doParsimUnpacking(b,this->qos);
}

long BundlePkt::getBundleId() const
{
    return this->bundleId;
}

void BundlePkt::setBundleId(long bundleId)
{
    this->bundleId = bundleId;
}

int BundlePkt::getSourceEid() const
{
    return this->sourceEid;
}

void BundlePkt::setSourceEid(int sourceEid)
{
    this->sourceEid = sourceEid;
}

int BundlePkt::getDestinationEid() const
{
    return this->destinationEid;
}

void BundlePkt::setDestinationEid(int destinationEid)
{
    this->destinationEid = destinationEid;
}

bool BundlePkt::getCritical() const
{
    return this->critical;
}

void BundlePkt::setCritical(bool critical)
{
    this->critical = critical;
}

omnetpp::simtime_t BundlePkt::getCreationTimestamp() const
{
    return this->creationTimestamp;
}

void BundlePkt::setCreationTimestamp(omnetpp::simtime_t creationTimestamp)
{
    this->creationTimestamp = creationTimestamp;
}

omnetpp::simtime_t BundlePkt::getTtl() const
{
    return this->ttl;
}

void BundlePkt::setTtl(omnetpp::simtime_t ttl)
{
    this->ttl = ttl;
}

bool BundlePkt::getReturnToSender() const
{
    return this->returnToSender;
}

void BundlePkt::setReturnToSender(bool returnToSender)
{
    this->returnToSender = returnToSender;
}

bool BundlePkt::getCustodyTransferRequested() const
{
    return this->custodyTransferRequested;
}

void BundlePkt::setCustodyTransferRequested(bool custodyTransferRequested)
{
    this->custodyTransferRequested = custodyTransferRequested;
}

const CgrRoute& BundlePkt::getCgrRoute() const
{
    return this->cgrRoute;
}

void BundlePkt::setCgrRoute(const CgrRoute& cgrRoute)
{
    this->cgrRoute = cgrRoute;
}

bool BundlePkt::getBundleIsCustodyReport() const
{
    return this->bundleIsCustodyReport;
}

void BundlePkt::setBundleIsCustodyReport(bool bundleIsCustodyReport)
{
    this->bundleIsCustodyReport = bundleIsCustodyReport;
}

bool BundlePkt::getCustodyAccepted() const
{
    return this->custodyAccepted;
}

void BundlePkt::setCustodyAccepted(bool custodyAccepted)
{
    this->custodyAccepted = custodyAccepted;
}

long BundlePkt::getCustodyBundleId() const
{
    return this->custodyBundleId;
}

void BundlePkt::setCustodyBundleId(long custodyBundleId)
{
    this->custodyBundleId = custodyBundleId;
}

int BundlePkt::getCustodianEid() const
{
    return this->custodianEid;
}

void BundlePkt::setCustodianEid(int custodianEid)
{
    this->custodianEid = custodianEid;
}

int BundlePkt::getSenderEid() const
{
    return this->senderEid;
}

void BundlePkt::setSenderEid(int senderEid)
{
    this->senderEid = senderEid;
}

int BundlePkt::getNextHopEid() const
{
    return this->nextHopEid;
}

void BundlePkt::setNextHopEid(int nextHopEid)
{
    this->nextHopEid = nextHopEid;
}

int BundlePkt::getHopCount() const
{
    return this->hopCount;
}

void BundlePkt::setHopCount(int hopCount)
{
    this->hopCount = hopCount;
}

const intList& BundlePkt::getVisitedNodes() const
{
    return this->visitedNodes;
}

void BundlePkt::setVisitedNodes(const intList& visitedNodes)
{
    this->visitedNodes = visitedNodes;
}

int BundlePkt::getXmitCopiesCount() const
{
    return this->xmitCopiesCount;
}

void BundlePkt::setXmitCopiesCount(int xmitCopiesCount)
{
    this->xmitCopiesCount = xmitCopiesCount;
}

double BundlePkt::getDlvConfidence() const
{
    return this->dlvConfidence;
}

void BundlePkt::setDlvConfidence(double dlvConfidence)
{
    this->dlvConfidence = dlvConfidence;
}

int BundlePkt::getBundlesCopies() const
{
    return this->bundlesCopies;
}

void BundlePkt::setBundlesCopies(int bundlesCopies)
{
    this->bundlesCopies = bundlesCopies;
}

int BundlePkt::getQos() const
{
    return this->qos;
}

void BundlePkt::setQos(int qos)
{
    this->qos = qos;
}

class BundlePktDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_bundleId,
        FIELD_sourceEid,
        FIELD_destinationEid,
        FIELD_critical,
        FIELD_creationTimestamp,
        FIELD_ttl,
        FIELD_returnToSender,
        FIELD_custodyTransferRequested,
        FIELD_cgrRoute,
        FIELD_bundleIsCustodyReport,
        FIELD_custodyAccepted,
        FIELD_custodyBundleId,
        FIELD_custodianEid,
        FIELD_senderEid,
        FIELD_nextHopEid,
        FIELD_hopCount,
        FIELD_visitedNodes,
        FIELD_xmitCopiesCount,
        FIELD_dlvConfidence,
        FIELD_bundlesCopies,
        FIELD_qos,
    };
  public:
    BundlePktDescriptor();
    virtual ~BundlePktDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(BundlePktDescriptor)

BundlePktDescriptor::BundlePktDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(BundlePkt)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

BundlePktDescriptor::~BundlePktDescriptor()
{
    delete[] propertyNames;
}

bool BundlePktDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<BundlePkt *>(obj)!=nullptr;
}

const char **BundlePktDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *BundlePktDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int BundlePktDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 21+base->getFieldCount() : 21;
}

unsigned int BundlePktDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_bundleId
        FD_ISEDITABLE,    // FIELD_sourceEid
        FD_ISEDITABLE,    // FIELD_destinationEid
        FD_ISEDITABLE,    // FIELD_critical
        FD_ISEDITABLE,    // FIELD_creationTimestamp
        FD_ISEDITABLE,    // FIELD_ttl
        FD_ISEDITABLE,    // FIELD_returnToSender
        FD_ISEDITABLE,    // FIELD_custodyTransferRequested
        FD_ISCOMPOUND,    // FIELD_cgrRoute
        FD_ISEDITABLE,    // FIELD_bundleIsCustodyReport
        FD_ISEDITABLE,    // FIELD_custodyAccepted
        FD_ISEDITABLE,    // FIELD_custodyBundleId
        FD_ISEDITABLE,    // FIELD_custodianEid
        FD_ISEDITABLE,    // FIELD_senderEid
        FD_ISEDITABLE,    // FIELD_nextHopEid
        FD_ISEDITABLE,    // FIELD_hopCount
        FD_ISCOMPOUND,    // FIELD_visitedNodes
        FD_ISEDITABLE,    // FIELD_xmitCopiesCount
        FD_ISEDITABLE,    // FIELD_dlvConfidence
        FD_ISEDITABLE,    // FIELD_bundlesCopies
        FD_ISEDITABLE,    // FIELD_qos
    };
    return (field >= 0 && field < 21) ? fieldTypeFlags[field] : 0;
}

const char *BundlePktDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bundleId",
        "sourceEid",
        "destinationEid",
        "critical",
        "creationTimestamp",
        "ttl",
        "returnToSender",
        "custodyTransferRequested",
        "cgrRoute",
        "bundleIsCustodyReport",
        "custodyAccepted",
        "custodyBundleId",
        "custodianEid",
        "senderEid",
        "nextHopEid",
        "hopCount",
        "visitedNodes",
        "xmitCopiesCount",
        "dlvConfidence",
        "bundlesCopies",
        "qos",
    };
    return (field >= 0 && field < 21) ? fieldNames[field] : nullptr;
}

int BundlePktDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "bundleId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "sourceEid") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "destinationEid") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "critical") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "creationTimestamp") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "ttl") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "returnToSender") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "custodyTransferRequested") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "cgrRoute") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "bundleIsCustodyReport") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "custodyAccepted") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "custodyBundleId") == 0) return baseIndex + 11;
    if (strcmp(fieldName, "custodianEid") == 0) return baseIndex + 12;
    if (strcmp(fieldName, "senderEid") == 0) return baseIndex + 13;
    if (strcmp(fieldName, "nextHopEid") == 0) return baseIndex + 14;
    if (strcmp(fieldName, "hopCount") == 0) return baseIndex + 15;
    if (strcmp(fieldName, "visitedNodes") == 0) return baseIndex + 16;
    if (strcmp(fieldName, "xmitCopiesCount") == 0) return baseIndex + 17;
    if (strcmp(fieldName, "dlvConfidence") == 0) return baseIndex + 18;
    if (strcmp(fieldName, "bundlesCopies") == 0) return baseIndex + 19;
    if (strcmp(fieldName, "qos") == 0) return baseIndex + 20;
    return base ? base->findField(fieldName) : -1;
}

const char *BundlePktDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "long",    // FIELD_bundleId
        "int",    // FIELD_sourceEid
        "int",    // FIELD_destinationEid
        "bool",    // FIELD_critical
        "omnetpp::simtime_t",    // FIELD_creationTimestamp
        "omnetpp::simtime_t",    // FIELD_ttl
        "bool",    // FIELD_returnToSender
        "bool",    // FIELD_custodyTransferRequested
        "CgrRoute",    // FIELD_cgrRoute
        "bool",    // FIELD_bundleIsCustodyReport
        "bool",    // FIELD_custodyAccepted
        "long",    // FIELD_custodyBundleId
        "int",    // FIELD_custodianEid
        "int",    // FIELD_senderEid
        "int",    // FIELD_nextHopEid
        "int",    // FIELD_hopCount
        "intList",    // FIELD_visitedNodes
        "int",    // FIELD_xmitCopiesCount
        "double",    // FIELD_dlvConfidence
        "int",    // FIELD_bundlesCopies
        "int",    // FIELD_qos
    };
    return (field >= 0 && field < 21) ? fieldTypeStrings[field] : nullptr;
}

const char **BundlePktDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *BundlePktDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int BundlePktDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    BundlePkt *pp = omnetpp::fromAnyPtr<BundlePkt>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void BundlePktDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    BundlePkt *pp = omnetpp::fromAnyPtr<BundlePkt>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'BundlePkt'", field);
    }
}

const char *BundlePktDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    BundlePkt *pp = omnetpp::fromAnyPtr<BundlePkt>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string BundlePktDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    BundlePkt *pp = omnetpp::fromAnyPtr<BundlePkt>(object); (void)pp;
    switch (field) {
        case FIELD_bundleId: return long2string(pp->getBundleId());
        case FIELD_sourceEid: return long2string(pp->getSourceEid());
        case FIELD_destinationEid: return long2string(pp->getDestinationEid());
        case FIELD_critical: return bool2string(pp->getCritical());
        case FIELD_creationTimestamp: return simtime2string(pp->getCreationTimestamp());
        case FIELD_ttl: return simtime2string(pp->getTtl());
        case FIELD_returnToSender: return bool2string(pp->getReturnToSender());
        case FIELD_custodyTransferRequested: return bool2string(pp->getCustodyTransferRequested());
        case FIELD_cgrRoute: return "";
        case FIELD_bundleIsCustodyReport: return bool2string(pp->getBundleIsCustodyReport());
        case FIELD_custodyAccepted: return bool2string(pp->getCustodyAccepted());
        case FIELD_custodyBundleId: return long2string(pp->getCustodyBundleId());
        case FIELD_custodianEid: return long2string(pp->getCustodianEid());
        case FIELD_senderEid: return long2string(pp->getSenderEid());
        case FIELD_nextHopEid: return long2string(pp->getNextHopEid());
        case FIELD_hopCount: return long2string(pp->getHopCount());
        case FIELD_visitedNodes: return "";
        case FIELD_xmitCopiesCount: return long2string(pp->getXmitCopiesCount());
        case FIELD_dlvConfidence: return double2string(pp->getDlvConfidence());
        case FIELD_bundlesCopies: return long2string(pp->getBundlesCopies());
        case FIELD_qos: return long2string(pp->getQos());
        default: return "";
    }
}

void BundlePktDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    BundlePkt *pp = omnetpp::fromAnyPtr<BundlePkt>(object); (void)pp;
    switch (field) {
        case FIELD_bundleId: pp->setBundleId(string2long(value)); break;
        case FIELD_sourceEid: pp->setSourceEid(string2long(value)); break;
        case FIELD_destinationEid: pp->setDestinationEid(string2long(value)); break;
        case FIELD_critical: pp->setCritical(string2bool(value)); break;
        case FIELD_creationTimestamp: pp->setCreationTimestamp(string2simtime(value)); break;
        case FIELD_ttl: pp->setTtl(string2simtime(value)); break;
        case FIELD_returnToSender: pp->setReturnToSender(string2bool(value)); break;
        case FIELD_custodyTransferRequested: pp->setCustodyTransferRequested(string2bool(value)); break;
        case FIELD_bundleIsCustodyReport: pp->setBundleIsCustodyReport(string2bool(value)); break;
        case FIELD_custodyAccepted: pp->setCustodyAccepted(string2bool(value)); break;
        case FIELD_custodyBundleId: pp->setCustodyBundleId(string2long(value)); break;
        case FIELD_custodianEid: pp->setCustodianEid(string2long(value)); break;
        case FIELD_senderEid: pp->setSenderEid(string2long(value)); break;
        case FIELD_nextHopEid: pp->setNextHopEid(string2long(value)); break;
        case FIELD_hopCount: pp->setHopCount(string2long(value)); break;
        case FIELD_xmitCopiesCount: pp->setXmitCopiesCount(string2long(value)); break;
        case FIELD_dlvConfidence: pp->setDlvConfidence(string2double(value)); break;
        case FIELD_bundlesCopies: pp->setBundlesCopies(string2long(value)); break;
        case FIELD_qos: pp->setQos(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BundlePkt'", field);
    }
}

omnetpp::cValue BundlePktDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    BundlePkt *pp = omnetpp::fromAnyPtr<BundlePkt>(object); (void)pp;
    switch (field) {
        case FIELD_bundleId: return (omnetpp::intval_t)(pp->getBundleId());
        case FIELD_sourceEid: return pp->getSourceEid();
        case FIELD_destinationEid: return pp->getDestinationEid();
        case FIELD_critical: return pp->getCritical();
        case FIELD_creationTimestamp: return pp->getCreationTimestamp().dbl();
        case FIELD_ttl: return pp->getTtl().dbl();
        case FIELD_returnToSender: return pp->getReturnToSender();
        case FIELD_custodyTransferRequested: return pp->getCustodyTransferRequested();
        case FIELD_cgrRoute: return omnetpp::toAnyPtr(&pp->getCgrRoute()); break;
        case FIELD_bundleIsCustodyReport: return pp->getBundleIsCustodyReport();
        case FIELD_custodyAccepted: return pp->getCustodyAccepted();
        case FIELD_custodyBundleId: return (omnetpp::intval_t)(pp->getCustodyBundleId());
        case FIELD_custodianEid: return pp->getCustodianEid();
        case FIELD_senderEid: return pp->getSenderEid();
        case FIELD_nextHopEid: return pp->getNextHopEid();
        case FIELD_hopCount: return pp->getHopCount();
        case FIELD_visitedNodes: return omnetpp::toAnyPtr(&pp->getVisitedNodes()); break;
        case FIELD_xmitCopiesCount: return pp->getXmitCopiesCount();
        case FIELD_dlvConfidence: return pp->getDlvConfidence();
        case FIELD_bundlesCopies: return pp->getBundlesCopies();
        case FIELD_qos: return pp->getQos();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'BundlePkt' as cValue -- field index out of range?", field);
    }
}

void BundlePktDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    BundlePkt *pp = omnetpp::fromAnyPtr<BundlePkt>(object); (void)pp;
    switch (field) {
        case FIELD_bundleId: pp->setBundleId(omnetpp::checked_int_cast<long>(value.intValue())); break;
        case FIELD_sourceEid: pp->setSourceEid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_destinationEid: pp->setDestinationEid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_critical: pp->setCritical(value.boolValue()); break;
        case FIELD_creationTimestamp: pp->setCreationTimestamp(value.doubleValue()); break;
        case FIELD_ttl: pp->setTtl(value.doubleValue()); break;
        case FIELD_returnToSender: pp->setReturnToSender(value.boolValue()); break;
        case FIELD_custodyTransferRequested: pp->setCustodyTransferRequested(value.boolValue()); break;
        case FIELD_bundleIsCustodyReport: pp->setBundleIsCustodyReport(value.boolValue()); break;
        case FIELD_custodyAccepted: pp->setCustodyAccepted(value.boolValue()); break;
        case FIELD_custodyBundleId: pp->setCustodyBundleId(omnetpp::checked_int_cast<long>(value.intValue())); break;
        case FIELD_custodianEid: pp->setCustodianEid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_senderEid: pp->setSenderEid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_nextHopEid: pp->setNextHopEid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_hopCount: pp->setHopCount(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_xmitCopiesCount: pp->setXmitCopiesCount(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_dlvConfidence: pp->setDlvConfidence(value.doubleValue()); break;
        case FIELD_bundlesCopies: pp->setBundlesCopies(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_qos: pp->setQos(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BundlePkt'", field);
    }
}

const char *BundlePktDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        case FIELD_cgrRoute: return omnetpp::opp_typename(typeid(CgrRoute));
        case FIELD_visitedNodes: return omnetpp::opp_typename(typeid(intList));
        default: return nullptr;
    };
}

omnetpp::any_ptr BundlePktDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    BundlePkt *pp = omnetpp::fromAnyPtr<BundlePkt>(object); (void)pp;
    switch (field) {
        case FIELD_cgrRoute: return omnetpp::toAnyPtr(&pp->getCgrRoute()); break;
        case FIELD_visitedNodes: return omnetpp::toAnyPtr(&pp->getVisitedNodes()); break;
        default: return omnetpp::any_ptr(nullptr);
    }
}

void BundlePktDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    BundlePkt *pp = omnetpp::fromAnyPtr<BundlePkt>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'BundlePkt'", field);
    }
}

Register_Class(TrafficGeneratorMsg)

TrafficGeneratorMsg::TrafficGeneratorMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

TrafficGeneratorMsg::TrafficGeneratorMsg(const TrafficGeneratorMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

TrafficGeneratorMsg::~TrafficGeneratorMsg()
{
}

TrafficGeneratorMsg& TrafficGeneratorMsg::operator=(const TrafficGeneratorMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void TrafficGeneratorMsg::copy(const TrafficGeneratorMsg& other)
{
    this->bundlesNumber = other.bundlesNumber;
    this->destinationEid = other.destinationEid;
    this->size = other.size;
    this->ttl = other.ttl;
    this->interval = other.interval;
}

void TrafficGeneratorMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->bundlesNumber);
    doParsimPacking(b,this->destinationEid);
    doParsimPacking(b,this->size);
    doParsimPacking(b,this->ttl);
    doParsimPacking(b,this->interval);
}

void TrafficGeneratorMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->bundlesNumber);
    doParsimUnpacking(b,this->destinationEid);
    doParsimUnpacking(b,this->size);
    doParsimUnpacking(b,this->ttl);
    doParsimUnpacking(b,this->interval);
}

int TrafficGeneratorMsg::getBundlesNumber() const
{
    return this->bundlesNumber;
}

void TrafficGeneratorMsg::setBundlesNumber(int bundlesNumber)
{
    this->bundlesNumber = bundlesNumber;
}

int TrafficGeneratorMsg::getDestinationEid() const
{
    return this->destinationEid;
}

void TrafficGeneratorMsg::setDestinationEid(int destinationEid)
{
    this->destinationEid = destinationEid;
}

int TrafficGeneratorMsg::getSize() const
{
    return this->size;
}

void TrafficGeneratorMsg::setSize(int size)
{
    this->size = size;
}

double TrafficGeneratorMsg::getTtl() const
{
    return this->ttl;
}

void TrafficGeneratorMsg::setTtl(double ttl)
{
    this->ttl = ttl;
}

double TrafficGeneratorMsg::getInterval() const
{
    return this->interval;
}

void TrafficGeneratorMsg::setInterval(double interval)
{
    this->interval = interval;
}

class TrafficGeneratorMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_bundlesNumber,
        FIELD_destinationEid,
        FIELD_size,
        FIELD_ttl,
        FIELD_interval,
    };
  public:
    TrafficGeneratorMsgDescriptor();
    virtual ~TrafficGeneratorMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(TrafficGeneratorMsgDescriptor)

TrafficGeneratorMsgDescriptor::TrafficGeneratorMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(TrafficGeneratorMsg)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

TrafficGeneratorMsgDescriptor::~TrafficGeneratorMsgDescriptor()
{
    delete[] propertyNames;
}

bool TrafficGeneratorMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<TrafficGeneratorMsg *>(obj)!=nullptr;
}

const char **TrafficGeneratorMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *TrafficGeneratorMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int TrafficGeneratorMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 5+base->getFieldCount() : 5;
}

unsigned int TrafficGeneratorMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_bundlesNumber
        FD_ISEDITABLE,    // FIELD_destinationEid
        FD_ISEDITABLE,    // FIELD_size
        FD_ISEDITABLE,    // FIELD_ttl
        FD_ISEDITABLE,    // FIELD_interval
    };
    return (field >= 0 && field < 5) ? fieldTypeFlags[field] : 0;
}

const char *TrafficGeneratorMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bundlesNumber",
        "destinationEid",
        "size",
        "ttl",
        "interval",
    };
    return (field >= 0 && field < 5) ? fieldNames[field] : nullptr;
}

int TrafficGeneratorMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "bundlesNumber") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "destinationEid") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "size") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "ttl") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "interval") == 0) return baseIndex + 4;
    return base ? base->findField(fieldName) : -1;
}

const char *TrafficGeneratorMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_bundlesNumber
        "int",    // FIELD_destinationEid
        "int",    // FIELD_size
        "double",    // FIELD_ttl
        "double",    // FIELD_interval
    };
    return (field >= 0 && field < 5) ? fieldTypeStrings[field] : nullptr;
}

const char **TrafficGeneratorMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *TrafficGeneratorMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int TrafficGeneratorMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    TrafficGeneratorMsg *pp = omnetpp::fromAnyPtr<TrafficGeneratorMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void TrafficGeneratorMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    TrafficGeneratorMsg *pp = omnetpp::fromAnyPtr<TrafficGeneratorMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'TrafficGeneratorMsg'", field);
    }
}

const char *TrafficGeneratorMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    TrafficGeneratorMsg *pp = omnetpp::fromAnyPtr<TrafficGeneratorMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string TrafficGeneratorMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    TrafficGeneratorMsg *pp = omnetpp::fromAnyPtr<TrafficGeneratorMsg>(object); (void)pp;
    switch (field) {
        case FIELD_bundlesNumber: return long2string(pp->getBundlesNumber());
        case FIELD_destinationEid: return long2string(pp->getDestinationEid());
        case FIELD_size: return long2string(pp->getSize());
        case FIELD_ttl: return double2string(pp->getTtl());
        case FIELD_interval: return double2string(pp->getInterval());
        default: return "";
    }
}

void TrafficGeneratorMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TrafficGeneratorMsg *pp = omnetpp::fromAnyPtr<TrafficGeneratorMsg>(object); (void)pp;
    switch (field) {
        case FIELD_bundlesNumber: pp->setBundlesNumber(string2long(value)); break;
        case FIELD_destinationEid: pp->setDestinationEid(string2long(value)); break;
        case FIELD_size: pp->setSize(string2long(value)); break;
        case FIELD_ttl: pp->setTtl(string2double(value)); break;
        case FIELD_interval: pp->setInterval(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TrafficGeneratorMsg'", field);
    }
}

omnetpp::cValue TrafficGeneratorMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    TrafficGeneratorMsg *pp = omnetpp::fromAnyPtr<TrafficGeneratorMsg>(object); (void)pp;
    switch (field) {
        case FIELD_bundlesNumber: return pp->getBundlesNumber();
        case FIELD_destinationEid: return pp->getDestinationEid();
        case FIELD_size: return pp->getSize();
        case FIELD_ttl: return pp->getTtl();
        case FIELD_interval: return pp->getInterval();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'TrafficGeneratorMsg' as cValue -- field index out of range?", field);
    }
}

void TrafficGeneratorMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    TrafficGeneratorMsg *pp = omnetpp::fromAnyPtr<TrafficGeneratorMsg>(object); (void)pp;
    switch (field) {
        case FIELD_bundlesNumber: pp->setBundlesNumber(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_destinationEid: pp->setDestinationEid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_size: pp->setSize(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_ttl: pp->setTtl(value.doubleValue()); break;
        case FIELD_interval: pp->setInterval(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TrafficGeneratorMsg'", field);
    }
}

const char *TrafficGeneratorMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr TrafficGeneratorMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    TrafficGeneratorMsg *pp = omnetpp::fromAnyPtr<TrafficGeneratorMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void TrafficGeneratorMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    TrafficGeneratorMsg *pp = omnetpp::fromAnyPtr<TrafficGeneratorMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'TrafficGeneratorMsg'", field);
    }
}

Register_Class(ContactMsg)

ContactMsg::ContactMsg(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

ContactMsg::ContactMsg(const ContactMsg& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

ContactMsg::~ContactMsg()
{
}

ContactMsg& ContactMsg::operator=(const ContactMsg& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void ContactMsg::copy(const ContactMsg& other)
{
    this->id = other.id;
    this->dataRate = other.dataRate;
    this->start = other.start;
    this->end = other.end;
    this->duration = other.duration;
    this->sourceEid = other.sourceEid;
    this->destinationEid = other.destinationEid;
}

void ContactMsg::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->id);
    doParsimPacking(b,this->dataRate);
    doParsimPacking(b,this->start);
    doParsimPacking(b,this->end);
    doParsimPacking(b,this->duration);
    doParsimPacking(b,this->sourceEid);
    doParsimPacking(b,this->destinationEid);
}

void ContactMsg::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->id);
    doParsimUnpacking(b,this->dataRate);
    doParsimUnpacking(b,this->start);
    doParsimUnpacking(b,this->end);
    doParsimUnpacking(b,this->duration);
    doParsimUnpacking(b,this->sourceEid);
    doParsimUnpacking(b,this->destinationEid);
}

int ContactMsg::getId() const
{
    return this->id;
}

void ContactMsg::setId(int id)
{
    this->id = id;
}

double ContactMsg::getDataRate() const
{
    return this->dataRate;
}

void ContactMsg::setDataRate(double dataRate)
{
    this->dataRate = dataRate;
}

omnetpp::simtime_t ContactMsg::getStart() const
{
    return this->start;
}

void ContactMsg::setStart(omnetpp::simtime_t start)
{
    this->start = start;
}

omnetpp::simtime_t ContactMsg::getEnd() const
{
    return this->end;
}

void ContactMsg::setEnd(omnetpp::simtime_t end)
{
    this->end = end;
}

omnetpp::simtime_t ContactMsg::getDuration() const
{
    return this->duration;
}

void ContactMsg::setDuration(omnetpp::simtime_t duration)
{
    this->duration = duration;
}

int ContactMsg::getSourceEid() const
{
    return this->sourceEid;
}

void ContactMsg::setSourceEid(int sourceEid)
{
    this->sourceEid = sourceEid;
}

int ContactMsg::getDestinationEid() const
{
    return this->destinationEid;
}

void ContactMsg::setDestinationEid(int destinationEid)
{
    this->destinationEid = destinationEid;
}

class ContactMsgDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_id,
        FIELD_dataRate,
        FIELD_start,
        FIELD_end,
        FIELD_duration,
        FIELD_sourceEid,
        FIELD_destinationEid,
    };
  public:
    ContactMsgDescriptor();
    virtual ~ContactMsgDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(ContactMsgDescriptor)

ContactMsgDescriptor::ContactMsgDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(ContactMsg)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

ContactMsgDescriptor::~ContactMsgDescriptor()
{
    delete[] propertyNames;
}

bool ContactMsgDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ContactMsg *>(obj)!=nullptr;
}

const char **ContactMsgDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *ContactMsgDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int ContactMsgDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 7+base->getFieldCount() : 7;
}

unsigned int ContactMsgDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_id
        FD_ISEDITABLE,    // FIELD_dataRate
        FD_ISEDITABLE,    // FIELD_start
        FD_ISEDITABLE,    // FIELD_end
        FD_ISEDITABLE,    // FIELD_duration
        FD_ISEDITABLE,    // FIELD_sourceEid
        FD_ISEDITABLE,    // FIELD_destinationEid
    };
    return (field >= 0 && field < 7) ? fieldTypeFlags[field] : 0;
}

const char *ContactMsgDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "id",
        "dataRate",
        "start",
        "end",
        "duration",
        "sourceEid",
        "destinationEid",
    };
    return (field >= 0 && field < 7) ? fieldNames[field] : nullptr;
}

int ContactMsgDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "id") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "dataRate") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "start") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "end") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "duration") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "sourceEid") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "destinationEid") == 0) return baseIndex + 6;
    return base ? base->findField(fieldName) : -1;
}

const char *ContactMsgDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_id
        "double",    // FIELD_dataRate
        "omnetpp::simtime_t",    // FIELD_start
        "omnetpp::simtime_t",    // FIELD_end
        "omnetpp::simtime_t",    // FIELD_duration
        "int",    // FIELD_sourceEid
        "int",    // FIELD_destinationEid
    };
    return (field >= 0 && field < 7) ? fieldTypeStrings[field] : nullptr;
}

const char **ContactMsgDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ContactMsgDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ContactMsgDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    ContactMsg *pp = omnetpp::fromAnyPtr<ContactMsg>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ContactMsgDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    ContactMsg *pp = omnetpp::fromAnyPtr<ContactMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ContactMsg'", field);
    }
}

const char *ContactMsgDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    ContactMsg *pp = omnetpp::fromAnyPtr<ContactMsg>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ContactMsgDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    ContactMsg *pp = omnetpp::fromAnyPtr<ContactMsg>(object); (void)pp;
    switch (field) {
        case FIELD_id: return long2string(pp->getId());
        case FIELD_dataRate: return double2string(pp->getDataRate());
        case FIELD_start: return simtime2string(pp->getStart());
        case FIELD_end: return simtime2string(pp->getEnd());
        case FIELD_duration: return simtime2string(pp->getDuration());
        case FIELD_sourceEid: return long2string(pp->getSourceEid());
        case FIELD_destinationEid: return long2string(pp->getDestinationEid());
        default: return "";
    }
}

void ContactMsgDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ContactMsg *pp = omnetpp::fromAnyPtr<ContactMsg>(object); (void)pp;
    switch (field) {
        case FIELD_id: pp->setId(string2long(value)); break;
        case FIELD_dataRate: pp->setDataRate(string2double(value)); break;
        case FIELD_start: pp->setStart(string2simtime(value)); break;
        case FIELD_end: pp->setEnd(string2simtime(value)); break;
        case FIELD_duration: pp->setDuration(string2simtime(value)); break;
        case FIELD_sourceEid: pp->setSourceEid(string2long(value)); break;
        case FIELD_destinationEid: pp->setDestinationEid(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ContactMsg'", field);
    }
}

omnetpp::cValue ContactMsgDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    ContactMsg *pp = omnetpp::fromAnyPtr<ContactMsg>(object); (void)pp;
    switch (field) {
        case FIELD_id: return pp->getId();
        case FIELD_dataRate: return pp->getDataRate();
        case FIELD_start: return pp->getStart().dbl();
        case FIELD_end: return pp->getEnd().dbl();
        case FIELD_duration: return pp->getDuration().dbl();
        case FIELD_sourceEid: return pp->getSourceEid();
        case FIELD_destinationEid: return pp->getDestinationEid();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'ContactMsg' as cValue -- field index out of range?", field);
    }
}

void ContactMsgDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ContactMsg *pp = omnetpp::fromAnyPtr<ContactMsg>(object); (void)pp;
    switch (field) {
        case FIELD_id: pp->setId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_dataRate: pp->setDataRate(value.doubleValue()); break;
        case FIELD_start: pp->setStart(value.doubleValue()); break;
        case FIELD_end: pp->setEnd(value.doubleValue()); break;
        case FIELD_duration: pp->setDuration(value.doubleValue()); break;
        case FIELD_sourceEid: pp->setSourceEid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_destinationEid: pp->setDestinationEid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ContactMsg'", field);
    }
}

const char *ContactMsgDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr ContactMsgDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    ContactMsg *pp = omnetpp::fromAnyPtr<ContactMsg>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void ContactMsgDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    ContactMsg *pp = omnetpp::fromAnyPtr<ContactMsg>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ContactMsg'", field);
    }
}

Register_Class(ForwardingMsgEnd)

ForwardingMsgEnd::ForwardingMsgEnd(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

ForwardingMsgEnd::ForwardingMsgEnd(const ForwardingMsgEnd& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

ForwardingMsgEnd::~ForwardingMsgEnd()
{
}

ForwardingMsgEnd& ForwardingMsgEnd::operator=(const ForwardingMsgEnd& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void ForwardingMsgEnd::copy(const ForwardingMsgEnd& other)
{
    this->neighborEid = other.neighborEid;
    this->contactId = other.contactId;
    this->bundleId = other.bundleId;
    this->sentToDestination = other.sentToDestination;
}

void ForwardingMsgEnd::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->neighborEid);
    doParsimPacking(b,this->contactId);
    doParsimPacking(b,this->bundleId);
    doParsimPacking(b,this->sentToDestination);
}

void ForwardingMsgEnd::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->neighborEid);
    doParsimUnpacking(b,this->contactId);
    doParsimUnpacking(b,this->bundleId);
    doParsimUnpacking(b,this->sentToDestination);
}

int ForwardingMsgEnd::getNeighborEid() const
{
    return this->neighborEid;
}

void ForwardingMsgEnd::setNeighborEid(int neighborEid)
{
    this->neighborEid = neighborEid;
}

int ForwardingMsgEnd::getContactId() const
{
    return this->contactId;
}

void ForwardingMsgEnd::setContactId(int contactId)
{
    this->contactId = contactId;
}

long ForwardingMsgEnd::getBundleId() const
{
    return this->bundleId;
}

void ForwardingMsgEnd::setBundleId(long bundleId)
{
    this->bundleId = bundleId;
}

bool ForwardingMsgEnd::getSentToDestination() const
{
    return this->sentToDestination;
}

void ForwardingMsgEnd::setSentToDestination(bool sentToDestination)
{
    this->sentToDestination = sentToDestination;
}

class ForwardingMsgEndDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_neighborEid,
        FIELD_contactId,
        FIELD_bundleId,
        FIELD_sentToDestination,
    };
  public:
    ForwardingMsgEndDescriptor();
    virtual ~ForwardingMsgEndDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(ForwardingMsgEndDescriptor)

ForwardingMsgEndDescriptor::ForwardingMsgEndDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(ForwardingMsgEnd)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

ForwardingMsgEndDescriptor::~ForwardingMsgEndDescriptor()
{
    delete[] propertyNames;
}

bool ForwardingMsgEndDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ForwardingMsgEnd *>(obj)!=nullptr;
}

const char **ForwardingMsgEndDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *ForwardingMsgEndDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int ForwardingMsgEndDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 4+base->getFieldCount() : 4;
}

unsigned int ForwardingMsgEndDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_neighborEid
        FD_ISEDITABLE,    // FIELD_contactId
        FD_ISEDITABLE,    // FIELD_bundleId
        FD_ISEDITABLE,    // FIELD_sentToDestination
    };
    return (field >= 0 && field < 4) ? fieldTypeFlags[field] : 0;
}

const char *ForwardingMsgEndDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "neighborEid",
        "contactId",
        "bundleId",
        "sentToDestination",
    };
    return (field >= 0 && field < 4) ? fieldNames[field] : nullptr;
}

int ForwardingMsgEndDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "neighborEid") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "contactId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "bundleId") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "sentToDestination") == 0) return baseIndex + 3;
    return base ? base->findField(fieldName) : -1;
}

const char *ForwardingMsgEndDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_neighborEid
        "int",    // FIELD_contactId
        "long",    // FIELD_bundleId
        "bool",    // FIELD_sentToDestination
    };
    return (field >= 0 && field < 4) ? fieldTypeStrings[field] : nullptr;
}

const char **ForwardingMsgEndDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ForwardingMsgEndDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ForwardingMsgEndDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    ForwardingMsgEnd *pp = omnetpp::fromAnyPtr<ForwardingMsgEnd>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ForwardingMsgEndDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    ForwardingMsgEnd *pp = omnetpp::fromAnyPtr<ForwardingMsgEnd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ForwardingMsgEnd'", field);
    }
}

const char *ForwardingMsgEndDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    ForwardingMsgEnd *pp = omnetpp::fromAnyPtr<ForwardingMsgEnd>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ForwardingMsgEndDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    ForwardingMsgEnd *pp = omnetpp::fromAnyPtr<ForwardingMsgEnd>(object); (void)pp;
    switch (field) {
        case FIELD_neighborEid: return long2string(pp->getNeighborEid());
        case FIELD_contactId: return long2string(pp->getContactId());
        case FIELD_bundleId: return long2string(pp->getBundleId());
        case FIELD_sentToDestination: return bool2string(pp->getSentToDestination());
        default: return "";
    }
}

void ForwardingMsgEndDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ForwardingMsgEnd *pp = omnetpp::fromAnyPtr<ForwardingMsgEnd>(object); (void)pp;
    switch (field) {
        case FIELD_neighborEid: pp->setNeighborEid(string2long(value)); break;
        case FIELD_contactId: pp->setContactId(string2long(value)); break;
        case FIELD_bundleId: pp->setBundleId(string2long(value)); break;
        case FIELD_sentToDestination: pp->setSentToDestination(string2bool(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ForwardingMsgEnd'", field);
    }
}

omnetpp::cValue ForwardingMsgEndDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    ForwardingMsgEnd *pp = omnetpp::fromAnyPtr<ForwardingMsgEnd>(object); (void)pp;
    switch (field) {
        case FIELD_neighborEid: return pp->getNeighborEid();
        case FIELD_contactId: return pp->getContactId();
        case FIELD_bundleId: return (omnetpp::intval_t)(pp->getBundleId());
        case FIELD_sentToDestination: return pp->getSentToDestination();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'ForwardingMsgEnd' as cValue -- field index out of range?", field);
    }
}

void ForwardingMsgEndDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ForwardingMsgEnd *pp = omnetpp::fromAnyPtr<ForwardingMsgEnd>(object); (void)pp;
    switch (field) {
        case FIELD_neighborEid: pp->setNeighborEid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_contactId: pp->setContactId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_bundleId: pp->setBundleId(omnetpp::checked_int_cast<long>(value.intValue())); break;
        case FIELD_sentToDestination: pp->setSentToDestination(value.boolValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ForwardingMsgEnd'", field);
    }
}

const char *ForwardingMsgEndDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr ForwardingMsgEndDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    ForwardingMsgEnd *pp = omnetpp::fromAnyPtr<ForwardingMsgEnd>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void ForwardingMsgEndDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    ForwardingMsgEnd *pp = omnetpp::fromAnyPtr<ForwardingMsgEnd>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ForwardingMsgEnd'", field);
    }
}

Register_Class(ForwardingMsgStart)

ForwardingMsgStart::ForwardingMsgStart(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

ForwardingMsgStart::ForwardingMsgStart(const ForwardingMsgStart& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

ForwardingMsgStart::~ForwardingMsgStart()
{
}

ForwardingMsgStart& ForwardingMsgStart::operator=(const ForwardingMsgStart& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void ForwardingMsgStart::copy(const ForwardingMsgStart& other)
{
    this->neighborEid = other.neighborEid;
    this->contactId = other.contactId;
}

void ForwardingMsgStart::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->neighborEid);
    doParsimPacking(b,this->contactId);
}

void ForwardingMsgStart::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->neighborEid);
    doParsimUnpacking(b,this->contactId);
}

int ForwardingMsgStart::getNeighborEid() const
{
    return this->neighborEid;
}

void ForwardingMsgStart::setNeighborEid(int neighborEid)
{
    this->neighborEid = neighborEid;
}

int ForwardingMsgStart::getContactId() const
{
    return this->contactId;
}

void ForwardingMsgStart::setContactId(int contactId)
{
    this->contactId = contactId;
}

class ForwardingMsgStartDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_neighborEid,
        FIELD_contactId,
    };
  public:
    ForwardingMsgStartDescriptor();
    virtual ~ForwardingMsgStartDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(ForwardingMsgStartDescriptor)

ForwardingMsgStartDescriptor::ForwardingMsgStartDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(ForwardingMsgStart)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

ForwardingMsgStartDescriptor::~ForwardingMsgStartDescriptor()
{
    delete[] propertyNames;
}

bool ForwardingMsgStartDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ForwardingMsgStart *>(obj)!=nullptr;
}

const char **ForwardingMsgStartDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *ForwardingMsgStartDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int ForwardingMsgStartDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 2+base->getFieldCount() : 2;
}

unsigned int ForwardingMsgStartDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_neighborEid
        FD_ISEDITABLE,    // FIELD_contactId
    };
    return (field >= 0 && field < 2) ? fieldTypeFlags[field] : 0;
}

const char *ForwardingMsgStartDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "neighborEid",
        "contactId",
    };
    return (field >= 0 && field < 2) ? fieldNames[field] : nullptr;
}

int ForwardingMsgStartDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "neighborEid") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "contactId") == 0) return baseIndex + 1;
    return base ? base->findField(fieldName) : -1;
}

const char *ForwardingMsgStartDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_neighborEid
        "int",    // FIELD_contactId
    };
    return (field >= 0 && field < 2) ? fieldTypeStrings[field] : nullptr;
}

const char **ForwardingMsgStartDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ForwardingMsgStartDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ForwardingMsgStartDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    ForwardingMsgStart *pp = omnetpp::fromAnyPtr<ForwardingMsgStart>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ForwardingMsgStartDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    ForwardingMsgStart *pp = omnetpp::fromAnyPtr<ForwardingMsgStart>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ForwardingMsgStart'", field);
    }
}

const char *ForwardingMsgStartDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    ForwardingMsgStart *pp = omnetpp::fromAnyPtr<ForwardingMsgStart>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ForwardingMsgStartDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    ForwardingMsgStart *pp = omnetpp::fromAnyPtr<ForwardingMsgStart>(object); (void)pp;
    switch (field) {
        case FIELD_neighborEid: return long2string(pp->getNeighborEid());
        case FIELD_contactId: return long2string(pp->getContactId());
        default: return "";
    }
}

void ForwardingMsgStartDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ForwardingMsgStart *pp = omnetpp::fromAnyPtr<ForwardingMsgStart>(object); (void)pp;
    switch (field) {
        case FIELD_neighborEid: pp->setNeighborEid(string2long(value)); break;
        case FIELD_contactId: pp->setContactId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ForwardingMsgStart'", field);
    }
}

omnetpp::cValue ForwardingMsgStartDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    ForwardingMsgStart *pp = omnetpp::fromAnyPtr<ForwardingMsgStart>(object); (void)pp;
    switch (field) {
        case FIELD_neighborEid: return pp->getNeighborEid();
        case FIELD_contactId: return pp->getContactId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'ForwardingMsgStart' as cValue -- field index out of range?", field);
    }
}

void ForwardingMsgStartDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ForwardingMsgStart *pp = omnetpp::fromAnyPtr<ForwardingMsgStart>(object); (void)pp;
    switch (field) {
        case FIELD_neighborEid: pp->setNeighborEid(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_contactId: pp->setContactId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ForwardingMsgStart'", field);
    }
}

const char *ForwardingMsgStartDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr ForwardingMsgStartDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    ForwardingMsgStart *pp = omnetpp::fromAnyPtr<ForwardingMsgStart>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void ForwardingMsgStartDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    ForwardingMsgStart *pp = omnetpp::fromAnyPtr<ForwardingMsgStart>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ForwardingMsgStart'", field);
    }
}

Register_Class(CustodyTimout)

CustodyTimout::CustodyTimout(const char *name, short kind) : ::omnetpp::cMessage(name, kind)
{
}

CustodyTimout::CustodyTimout(const CustodyTimout& other) : ::omnetpp::cMessage(other)
{
    copy(other);
}

CustodyTimout::~CustodyTimout()
{
}

CustodyTimout& CustodyTimout::operator=(const CustodyTimout& other)
{
    if (this == &other) return *this;
    ::omnetpp::cMessage::operator=(other);
    copy(other);
    return *this;
}

void CustodyTimout::copy(const CustodyTimout& other)
{
    this->bundleId = other.bundleId;
}

void CustodyTimout::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cMessage::parsimPack(b);
    doParsimPacking(b,this->bundleId);
}

void CustodyTimout::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->bundleId);
}

int CustodyTimout::getBundleId() const
{
    return this->bundleId;
}

void CustodyTimout::setBundleId(int bundleId)
{
    this->bundleId = bundleId;
}

class CustodyTimoutDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_bundleId,
    };
  public:
    CustodyTimoutDescriptor();
    virtual ~CustodyTimoutDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(CustodyTimoutDescriptor)

CustodyTimoutDescriptor::CustodyTimoutDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(CustodyTimout)), "omnetpp::cMessage")
{
    propertyNames = nullptr;
}

CustodyTimoutDescriptor::~CustodyTimoutDescriptor()
{
    delete[] propertyNames;
}

bool CustodyTimoutDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<CustodyTimout *>(obj)!=nullptr;
}

const char **CustodyTimoutDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *CustodyTimoutDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int CustodyTimoutDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int CustodyTimoutDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_bundleId
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *CustodyTimoutDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "bundleId",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int CustodyTimoutDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "bundleId") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *CustodyTimoutDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_bundleId
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **CustodyTimoutDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *CustodyTimoutDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int CustodyTimoutDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    CustodyTimout *pp = omnetpp::fromAnyPtr<CustodyTimout>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void CustodyTimoutDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    CustodyTimout *pp = omnetpp::fromAnyPtr<CustodyTimout>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'CustodyTimout'", field);
    }
}

const char *CustodyTimoutDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    CustodyTimout *pp = omnetpp::fromAnyPtr<CustodyTimout>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string CustodyTimoutDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    CustodyTimout *pp = omnetpp::fromAnyPtr<CustodyTimout>(object); (void)pp;
    switch (field) {
        case FIELD_bundleId: return long2string(pp->getBundleId());
        default: return "";
    }
}

void CustodyTimoutDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CustodyTimout *pp = omnetpp::fromAnyPtr<CustodyTimout>(object); (void)pp;
    switch (field) {
        case FIELD_bundleId: pp->setBundleId(string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CustodyTimout'", field);
    }
}

omnetpp::cValue CustodyTimoutDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    CustodyTimout *pp = omnetpp::fromAnyPtr<CustodyTimout>(object); (void)pp;
    switch (field) {
        case FIELD_bundleId: return pp->getBundleId();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'CustodyTimout' as cValue -- field index out of range?", field);
    }
}

void CustodyTimoutDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    CustodyTimout *pp = omnetpp::fromAnyPtr<CustodyTimout>(object); (void)pp;
    switch (field) {
        case FIELD_bundleId: pp->setBundleId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CustodyTimout'", field);
    }
}

const char *CustodyTimoutDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr CustodyTimoutDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    CustodyTimout *pp = omnetpp::fromAnyPtr<CustodyTimout>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void CustodyTimoutDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    CustodyTimout *pp = omnetpp::fromAnyPtr<CustodyTimout>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'CustodyTimout'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

