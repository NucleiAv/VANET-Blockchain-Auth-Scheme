//
// Generated file, do not edit! Created by opp_msgtool 6.0 from plexe/messages/MoveToPosition.msg.
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
#include "MoveToPosition_m.h"

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

Register_Class(MoveToPosition)

MoveToPosition::MoveToPosition(const char *name, short kind) : ::ManeuverMessage(name, kind)
{
}

MoveToPosition::MoveToPosition(const MoveToPosition& other) : ::ManeuverMessage(other)
{
    copy(other);
}

MoveToPosition::~MoveToPosition()
{
    delete [] this->newPlatoonFormation;
}

MoveToPosition& MoveToPosition::operator=(const MoveToPosition& other)
{
    if (this == &other) return *this;
    ::ManeuverMessage::operator=(other);
    copy(other);
    return *this;
}

void MoveToPosition::copy(const MoveToPosition& other)
{
    this->platoonSpeed = other.platoonSpeed;
    this->platoonLane = other.platoonLane;
    delete [] this->newPlatoonFormation;
    this->newPlatoonFormation = (other.newPlatoonFormation_arraysize==0) ? nullptr : new int[other.newPlatoonFormation_arraysize];
    newPlatoonFormation_arraysize = other.newPlatoonFormation_arraysize;
    for (size_t i = 0; i < newPlatoonFormation_arraysize; i++) {
        this->newPlatoonFormation[i] = other.newPlatoonFormation[i];
    }
}

void MoveToPosition::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::ManeuverMessage::parsimPack(b);
    doParsimPacking(b,this->platoonSpeed);
    doParsimPacking(b,this->platoonLane);
    b->pack(newPlatoonFormation_arraysize);
    doParsimArrayPacking(b,this->newPlatoonFormation,newPlatoonFormation_arraysize);
}

void MoveToPosition::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::ManeuverMessage::parsimUnpack(b);
    doParsimUnpacking(b,this->platoonSpeed);
    doParsimUnpacking(b,this->platoonLane);
    delete [] this->newPlatoonFormation;
    b->unpack(newPlatoonFormation_arraysize);
    if (newPlatoonFormation_arraysize == 0) {
        this->newPlatoonFormation = nullptr;
    } else {
        this->newPlatoonFormation = new int[newPlatoonFormation_arraysize];
        doParsimArrayUnpacking(b,this->newPlatoonFormation,newPlatoonFormation_arraysize);
    }
}

double MoveToPosition::getPlatoonSpeed() const
{
    return this->platoonSpeed;
}

void MoveToPosition::setPlatoonSpeed(double platoonSpeed)
{
    this->platoonSpeed = platoonSpeed;
}

int MoveToPosition::getPlatoonLane() const
{
    return this->platoonLane;
}

void MoveToPosition::setPlatoonLane(int platoonLane)
{
    this->platoonLane = platoonLane;
}

size_t MoveToPosition::getNewPlatoonFormationArraySize() const
{
    return newPlatoonFormation_arraysize;
}

int MoveToPosition::getNewPlatoonFormation(size_t k) const
{
    if (k >= newPlatoonFormation_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)newPlatoonFormation_arraysize, (unsigned long)k);
    return this->newPlatoonFormation[k];
}

void MoveToPosition::setNewPlatoonFormationArraySize(size_t newSize)
{
    int *newPlatoonFormation2 = (newSize==0) ? nullptr : new int[newSize];
    size_t minSize = newPlatoonFormation_arraysize < newSize ? newPlatoonFormation_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        newPlatoonFormation2[i] = this->newPlatoonFormation[i];
    for (size_t i = minSize; i < newSize; i++)
        newPlatoonFormation2[i] = 0;
    delete [] this->newPlatoonFormation;
    this->newPlatoonFormation = newPlatoonFormation2;
    newPlatoonFormation_arraysize = newSize;
}

void MoveToPosition::setNewPlatoonFormation(size_t k, int newPlatoonFormation)
{
    if (k >= newPlatoonFormation_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)newPlatoonFormation_arraysize, (unsigned long)k);
    this->newPlatoonFormation[k] = newPlatoonFormation;
}

void MoveToPosition::insertNewPlatoonFormation(size_t k, int newPlatoonFormation)
{
    if (k > newPlatoonFormation_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)newPlatoonFormation_arraysize, (unsigned long)k);
    size_t newSize = newPlatoonFormation_arraysize + 1;
    int *newPlatoonFormation2 = new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        newPlatoonFormation2[i] = this->newPlatoonFormation[i];
    newPlatoonFormation2[k] = newPlatoonFormation;
    for (i = k + 1; i < newSize; i++)
        newPlatoonFormation2[i] = this->newPlatoonFormation[i-1];
    delete [] this->newPlatoonFormation;
    this->newPlatoonFormation = newPlatoonFormation2;
    newPlatoonFormation_arraysize = newSize;
}

void MoveToPosition::appendNewPlatoonFormation(int newPlatoonFormation)
{
    insertNewPlatoonFormation(newPlatoonFormation_arraysize, newPlatoonFormation);
}

void MoveToPosition::eraseNewPlatoonFormation(size_t k)
{
    if (k >= newPlatoonFormation_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)newPlatoonFormation_arraysize, (unsigned long)k);
    size_t newSize = newPlatoonFormation_arraysize - 1;
    int *newPlatoonFormation2 = (newSize == 0) ? nullptr : new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        newPlatoonFormation2[i] = this->newPlatoonFormation[i];
    for (i = k; i < newSize; i++)
        newPlatoonFormation2[i] = this->newPlatoonFormation[i+1];
    delete [] this->newPlatoonFormation;
    this->newPlatoonFormation = newPlatoonFormation2;
    newPlatoonFormation_arraysize = newSize;
}

class MoveToPositionDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_platoonSpeed,
        FIELD_platoonLane,
        FIELD_newPlatoonFormation,
    };
  public:
    MoveToPositionDescriptor();
    virtual ~MoveToPositionDescriptor();

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

Register_ClassDescriptor(MoveToPositionDescriptor)

MoveToPositionDescriptor::MoveToPositionDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MoveToPosition)), "ManeuverMessage")
{
    propertyNames = nullptr;
}

MoveToPositionDescriptor::~MoveToPositionDescriptor()
{
    delete[] propertyNames;
}

bool MoveToPositionDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MoveToPosition *>(obj)!=nullptr;
}

const char **MoveToPositionDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MoveToPositionDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MoveToPositionDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 3+base->getFieldCount() : 3;
}

unsigned int MoveToPositionDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_platoonSpeed
        FD_ISEDITABLE,    // FIELD_platoonLane
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_newPlatoonFormation
    };
    return (field >= 0 && field < 3) ? fieldTypeFlags[field] : 0;
}

const char *MoveToPositionDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "platoonSpeed",
        "platoonLane",
        "newPlatoonFormation",
    };
    return (field >= 0 && field < 3) ? fieldNames[field] : nullptr;
}

int MoveToPositionDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "platoonSpeed") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "platoonLane") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "newPlatoonFormation") == 0) return baseIndex + 2;
    return base ? base->findField(fieldName) : -1;
}

const char *MoveToPositionDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "double",    // FIELD_platoonSpeed
        "int",    // FIELD_platoonLane
        "int",    // FIELD_newPlatoonFormation
    };
    return (field >= 0 && field < 3) ? fieldTypeStrings[field] : nullptr;
}

const char **MoveToPositionDescriptor::getFieldPropertyNames(int field) const
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

const char *MoveToPositionDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int MoveToPositionDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MoveToPosition *pp = omnetpp::fromAnyPtr<MoveToPosition>(object); (void)pp;
    switch (field) {
        case FIELD_newPlatoonFormation: return pp->getNewPlatoonFormationArraySize();
        default: return 0;
    }
}

void MoveToPositionDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MoveToPosition *pp = omnetpp::fromAnyPtr<MoveToPosition>(object); (void)pp;
    switch (field) {
        case FIELD_newPlatoonFormation: pp->setNewPlatoonFormationArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MoveToPosition'", field);
    }
}

const char *MoveToPositionDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MoveToPosition *pp = omnetpp::fromAnyPtr<MoveToPosition>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MoveToPositionDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MoveToPosition *pp = omnetpp::fromAnyPtr<MoveToPosition>(object); (void)pp;
    switch (field) {
        case FIELD_platoonSpeed: return double2string(pp->getPlatoonSpeed());
        case FIELD_platoonLane: return long2string(pp->getPlatoonLane());
        case FIELD_newPlatoonFormation: return long2string(pp->getNewPlatoonFormation(i));
        default: return "";
    }
}

void MoveToPositionDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MoveToPosition *pp = omnetpp::fromAnyPtr<MoveToPosition>(object); (void)pp;
    switch (field) {
        case FIELD_platoonSpeed: pp->setPlatoonSpeed(string2double(value)); break;
        case FIELD_platoonLane: pp->setPlatoonLane(string2long(value)); break;
        case FIELD_newPlatoonFormation: pp->setNewPlatoonFormation(i,string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MoveToPosition'", field);
    }
}

omnetpp::cValue MoveToPositionDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MoveToPosition *pp = omnetpp::fromAnyPtr<MoveToPosition>(object); (void)pp;
    switch (field) {
        case FIELD_platoonSpeed: return pp->getPlatoonSpeed();
        case FIELD_platoonLane: return pp->getPlatoonLane();
        case FIELD_newPlatoonFormation: return pp->getNewPlatoonFormation(i);
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MoveToPosition' as cValue -- field index out of range?", field);
    }
}

void MoveToPositionDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MoveToPosition *pp = omnetpp::fromAnyPtr<MoveToPosition>(object); (void)pp;
    switch (field) {
        case FIELD_platoonSpeed: pp->setPlatoonSpeed(value.doubleValue()); break;
        case FIELD_platoonLane: pp->setPlatoonLane(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_newPlatoonFormation: pp->setNewPlatoonFormation(i,omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MoveToPosition'", field);
    }
}

const char *MoveToPositionDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr MoveToPositionDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MoveToPosition *pp = omnetpp::fromAnyPtr<MoveToPosition>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MoveToPositionDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MoveToPosition *pp = omnetpp::fromAnyPtr<MoveToPosition>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MoveToPosition'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

