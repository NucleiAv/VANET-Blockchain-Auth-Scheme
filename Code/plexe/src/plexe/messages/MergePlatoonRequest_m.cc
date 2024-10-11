//
// Generated file, do not edit! Created by opp_msgtool 6.0 from plexe/messages/MergePlatoonRequest.msg.
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
#include "MergePlatoonRequest_m.h"

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

Register_Class(MergePlatoonRequest)

MergePlatoonRequest::MergePlatoonRequest(const char *name, short kind) : ::JoinPlatoonRequest(name, kind)
{
}

MergePlatoonRequest::MergePlatoonRequest(const MergePlatoonRequest& other) : ::JoinPlatoonRequest(other)
{
    copy(other);
}

MergePlatoonRequest::~MergePlatoonRequest()
{
    delete [] this->members;
}

MergePlatoonRequest& MergePlatoonRequest::operator=(const MergePlatoonRequest& other)
{
    if (this == &other) return *this;
    ::JoinPlatoonRequest::operator=(other);
    copy(other);
    return *this;
}

void MergePlatoonRequest::copy(const MergePlatoonRequest& other)
{
    delete [] this->members;
    this->members = (other.members_arraysize==0) ? nullptr : new int[other.members_arraysize];
    members_arraysize = other.members_arraysize;
    for (size_t i = 0; i < members_arraysize; i++) {
        this->members[i] = other.members[i];
    }
}

void MergePlatoonRequest::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::JoinPlatoonRequest::parsimPack(b);
    b->pack(members_arraysize);
    doParsimArrayPacking(b,this->members,members_arraysize);
}

void MergePlatoonRequest::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::JoinPlatoonRequest::parsimUnpack(b);
    delete [] this->members;
    b->unpack(members_arraysize);
    if (members_arraysize == 0) {
        this->members = nullptr;
    } else {
        this->members = new int[members_arraysize];
        doParsimArrayUnpacking(b,this->members,members_arraysize);
    }
}

size_t MergePlatoonRequest::getMembersArraySize() const
{
    return members_arraysize;
}

int MergePlatoonRequest::getMembers(size_t k) const
{
    if (k >= members_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)members_arraysize, (unsigned long)k);
    return this->members[k];
}

void MergePlatoonRequest::setMembersArraySize(size_t newSize)
{
    int *members2 = (newSize==0) ? nullptr : new int[newSize];
    size_t minSize = members_arraysize < newSize ? members_arraysize : newSize;
    for (size_t i = 0; i < minSize; i++)
        members2[i] = this->members[i];
    for (size_t i = minSize; i < newSize; i++)
        members2[i] = 0;
    delete [] this->members;
    this->members = members2;
    members_arraysize = newSize;
}

void MergePlatoonRequest::setMembers(size_t k, int members)
{
    if (k >= members_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)members_arraysize, (unsigned long)k);
    this->members[k] = members;
}

void MergePlatoonRequest::insertMembers(size_t k, int members)
{
    if (k > members_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)members_arraysize, (unsigned long)k);
    size_t newSize = members_arraysize + 1;
    int *members2 = new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        members2[i] = this->members[i];
    members2[k] = members;
    for (i = k + 1; i < newSize; i++)
        members2[i] = this->members[i-1];
    delete [] this->members;
    this->members = members2;
    members_arraysize = newSize;
}

void MergePlatoonRequest::appendMembers(int members)
{
    insertMembers(members_arraysize, members);
}

void MergePlatoonRequest::eraseMembers(size_t k)
{
    if (k >= members_arraysize) throw omnetpp::cRuntimeError("Array of size %lu indexed by %lu", (unsigned long)members_arraysize, (unsigned long)k);
    size_t newSize = members_arraysize - 1;
    int *members2 = (newSize == 0) ? nullptr : new int[newSize];
    size_t i;
    for (i = 0; i < k; i++)
        members2[i] = this->members[i];
    for (i = k; i < newSize; i++)
        members2[i] = this->members[i+1];
    delete [] this->members;
    this->members = members2;
    members_arraysize = newSize;
}

class MergePlatoonRequestDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_members,
    };
  public:
    MergePlatoonRequestDescriptor();
    virtual ~MergePlatoonRequestDescriptor();

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

Register_ClassDescriptor(MergePlatoonRequestDescriptor)

MergePlatoonRequestDescriptor::MergePlatoonRequestDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(MergePlatoonRequest)), "JoinPlatoonRequest")
{
    propertyNames = nullptr;
}

MergePlatoonRequestDescriptor::~MergePlatoonRequestDescriptor()
{
    delete[] propertyNames;
}

bool MergePlatoonRequestDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<MergePlatoonRequest *>(obj)!=nullptr;
}

const char **MergePlatoonRequestDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *MergePlatoonRequestDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int MergePlatoonRequestDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 1+base->getFieldCount() : 1;
}

unsigned int MergePlatoonRequestDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISARRAY | FD_ISEDITABLE | FD_ISRESIZABLE,    // FIELD_members
    };
    return (field >= 0 && field < 1) ? fieldTypeFlags[field] : 0;
}

const char *MergePlatoonRequestDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "members",
    };
    return (field >= 0 && field < 1) ? fieldNames[field] : nullptr;
}

int MergePlatoonRequestDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "members") == 0) return baseIndex + 0;
    return base ? base->findField(fieldName) : -1;
}

const char *MergePlatoonRequestDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_members
    };
    return (field >= 0 && field < 1) ? fieldTypeStrings[field] : nullptr;
}

const char **MergePlatoonRequestDescriptor::getFieldPropertyNames(int field) const
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

const char *MergePlatoonRequestDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int MergePlatoonRequestDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    MergePlatoonRequest *pp = omnetpp::fromAnyPtr<MergePlatoonRequest>(object); (void)pp;
    switch (field) {
        case FIELD_members: return pp->getMembersArraySize();
        default: return 0;
    }
}

void MergePlatoonRequestDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    MergePlatoonRequest *pp = omnetpp::fromAnyPtr<MergePlatoonRequest>(object); (void)pp;
    switch (field) {
        case FIELD_members: pp->setMembersArraySize(size); break;
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'MergePlatoonRequest'", field);
    }
}

const char *MergePlatoonRequestDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    MergePlatoonRequest *pp = omnetpp::fromAnyPtr<MergePlatoonRequest>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string MergePlatoonRequestDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    MergePlatoonRequest *pp = omnetpp::fromAnyPtr<MergePlatoonRequest>(object); (void)pp;
    switch (field) {
        case FIELD_members: return long2string(pp->getMembers(i));
        default: return "";
    }
}

void MergePlatoonRequestDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MergePlatoonRequest *pp = omnetpp::fromAnyPtr<MergePlatoonRequest>(object); (void)pp;
    switch (field) {
        case FIELD_members: pp->setMembers(i,string2long(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MergePlatoonRequest'", field);
    }
}

omnetpp::cValue MergePlatoonRequestDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    MergePlatoonRequest *pp = omnetpp::fromAnyPtr<MergePlatoonRequest>(object); (void)pp;
    switch (field) {
        case FIELD_members: return pp->getMembers(i);
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'MergePlatoonRequest' as cValue -- field index out of range?", field);
    }
}

void MergePlatoonRequestDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    MergePlatoonRequest *pp = omnetpp::fromAnyPtr<MergePlatoonRequest>(object); (void)pp;
    switch (field) {
        case FIELD_members: pp->setMembers(i,omnetpp::checked_int_cast<int>(value.intValue())); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MergePlatoonRequest'", field);
    }
}

const char *MergePlatoonRequestDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr MergePlatoonRequestDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    MergePlatoonRequest *pp = omnetpp::fromAnyPtr<MergePlatoonRequest>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void MergePlatoonRequestDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    MergePlatoonRequest *pp = omnetpp::fromAnyPtr<MergePlatoonRequest>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'MergePlatoonRequest'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

