//
// Generated file, do not edit! Created by opp_msgtool 6.0 from plexe/messages/PlatooningBeacon.msg.
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
#include "PlatooningBeacon_m.h"

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

Register_Class(PlatooningBeacon)

PlatooningBeacon::PlatooningBeacon(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

PlatooningBeacon::PlatooningBeacon(const PlatooningBeacon& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

PlatooningBeacon::~PlatooningBeacon()
{
}

PlatooningBeacon& PlatooningBeacon::operator=(const PlatooningBeacon& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void PlatooningBeacon::copy(const PlatooningBeacon& other)
{
    this->vehicleId = other.vehicleId;
    this->controllerAcceleration = other.controllerAcceleration;
    this->acceleration = other.acceleration;
    this->speed = other.speed;
    this->positionX = other.positionX;
    this->positionY = other.positionY;
    this->time = other.time;
    this->sequenceNumber = other.sequenceNumber;
    this->length = other.length;
    this->speedX = other.speedX;
    this->speedY = other.speedY;
    this->angle = other.angle;
}

void PlatooningBeacon::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->vehicleId);
    doParsimPacking(b,this->controllerAcceleration);
    doParsimPacking(b,this->acceleration);
    doParsimPacking(b,this->speed);
    doParsimPacking(b,this->positionX);
    doParsimPacking(b,this->positionY);
    doParsimPacking(b,this->time);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->length);
    doParsimPacking(b,this->speedX);
    doParsimPacking(b,this->speedY);
    doParsimPacking(b,this->angle);
}

void PlatooningBeacon::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->vehicleId);
    doParsimUnpacking(b,this->controllerAcceleration);
    doParsimUnpacking(b,this->acceleration);
    doParsimUnpacking(b,this->speed);
    doParsimUnpacking(b,this->positionX);
    doParsimUnpacking(b,this->positionY);
    doParsimUnpacking(b,this->time);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->length);
    doParsimUnpacking(b,this->speedX);
    doParsimUnpacking(b,this->speedY);
    doParsimUnpacking(b,this->angle);
}

int PlatooningBeacon::getVehicleId() const
{
    return this->vehicleId;
}

void PlatooningBeacon::setVehicleId(int vehicleId)
{
    this->vehicleId = vehicleId;
}

double PlatooningBeacon::getControllerAcceleration() const
{
    return this->controllerAcceleration;
}

void PlatooningBeacon::setControllerAcceleration(double controllerAcceleration)
{
    this->controllerAcceleration = controllerAcceleration;
}

double PlatooningBeacon::getAcceleration() const
{
    return this->acceleration;
}

void PlatooningBeacon::setAcceleration(double acceleration)
{
    this->acceleration = acceleration;
}

double PlatooningBeacon::getSpeed() const
{
    return this->speed;
}

void PlatooningBeacon::setSpeed(double speed)
{
    this->speed = speed;
}

double PlatooningBeacon::getPositionX() const
{
    return this->positionX;
}

void PlatooningBeacon::setPositionX(double positionX)
{
    this->positionX = positionX;
}

double PlatooningBeacon::getPositionY() const
{
    return this->positionY;
}

void PlatooningBeacon::setPositionY(double positionY)
{
    this->positionY = positionY;
}

double PlatooningBeacon::getTime() const
{
    return this->time;
}

void PlatooningBeacon::setTime(double time)
{
    this->time = time;
}

int PlatooningBeacon::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void PlatooningBeacon::setSequenceNumber(int sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

double PlatooningBeacon::getLength() const
{
    return this->length;
}

void PlatooningBeacon::setLength(double length)
{
    this->length = length;
}

double PlatooningBeacon::getSpeedX() const
{
    return this->speedX;
}

void PlatooningBeacon::setSpeedX(double speedX)
{
    this->speedX = speedX;
}

double PlatooningBeacon::getSpeedY() const
{
    return this->speedY;
}

void PlatooningBeacon::setSpeedY(double speedY)
{
    this->speedY = speedY;
}

double PlatooningBeacon::getAngle() const
{
    return this->angle;
}

void PlatooningBeacon::setAngle(double angle)
{
    this->angle = angle;
}

class PlatooningBeaconDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_vehicleId,
        FIELD_controllerAcceleration,
        FIELD_acceleration,
        FIELD_speed,
        FIELD_positionX,
        FIELD_positionY,
        FIELD_time,
        FIELD_sequenceNumber,
        FIELD_length,
        FIELD_speedX,
        FIELD_speedY,
        FIELD_angle,
    };
  public:
    PlatooningBeaconDescriptor();
    virtual ~PlatooningBeaconDescriptor();

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

Register_ClassDescriptor(PlatooningBeaconDescriptor)

PlatooningBeaconDescriptor::PlatooningBeaconDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(PlatooningBeacon)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

PlatooningBeaconDescriptor::~PlatooningBeaconDescriptor()
{
    delete[] propertyNames;
}

bool PlatooningBeaconDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<PlatooningBeacon *>(obj)!=nullptr;
}

const char **PlatooningBeaconDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *PlatooningBeaconDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int PlatooningBeaconDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 12+base->getFieldCount() : 12;
}

unsigned int PlatooningBeaconDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_vehicleId
        FD_ISEDITABLE,    // FIELD_controllerAcceleration
        FD_ISEDITABLE,    // FIELD_acceleration
        FD_ISEDITABLE,    // FIELD_speed
        FD_ISEDITABLE,    // FIELD_positionX
        FD_ISEDITABLE,    // FIELD_positionY
        FD_ISEDITABLE,    // FIELD_time
        FD_ISEDITABLE,    // FIELD_sequenceNumber
        FD_ISEDITABLE,    // FIELD_length
        FD_ISEDITABLE,    // FIELD_speedX
        FD_ISEDITABLE,    // FIELD_speedY
        FD_ISEDITABLE,    // FIELD_angle
    };
    return (field >= 0 && field < 12) ? fieldTypeFlags[field] : 0;
}

const char *PlatooningBeaconDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "vehicleId",
        "controllerAcceleration",
        "acceleration",
        "speed",
        "positionX",
        "positionY",
        "time",
        "sequenceNumber",
        "length",
        "speedX",
        "speedY",
        "angle",
    };
    return (field >= 0 && field < 12) ? fieldNames[field] : nullptr;
}

int PlatooningBeaconDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "vehicleId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "controllerAcceleration") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "acceleration") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "speed") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "positionX") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "positionY") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "time") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "sequenceNumber") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "length") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "speedX") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "speedY") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "angle") == 0) return baseIndex + 11;
    return base ? base->findField(fieldName) : -1;
}

const char *PlatooningBeaconDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_vehicleId
        "double",    // FIELD_controllerAcceleration
        "double",    // FIELD_acceleration
        "double",    // FIELD_speed
        "double",    // FIELD_positionX
        "double",    // FIELD_positionY
        "double",    // FIELD_time
        "int",    // FIELD_sequenceNumber
        "double",    // FIELD_length
        "double",    // FIELD_speedX
        "double",    // FIELD_speedY
        "double",    // FIELD_angle
    };
    return (field >= 0 && field < 12) ? fieldTypeStrings[field] : nullptr;
}

const char **PlatooningBeaconDescriptor::getFieldPropertyNames(int field) const
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

const char *PlatooningBeaconDescriptor::getFieldProperty(int field, const char *propertyName) const
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

int PlatooningBeaconDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    PlatooningBeacon *pp = omnetpp::fromAnyPtr<PlatooningBeacon>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void PlatooningBeaconDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    PlatooningBeacon *pp = omnetpp::fromAnyPtr<PlatooningBeacon>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'PlatooningBeacon'", field);
    }
}

const char *PlatooningBeaconDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    PlatooningBeacon *pp = omnetpp::fromAnyPtr<PlatooningBeacon>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string PlatooningBeaconDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    PlatooningBeacon *pp = omnetpp::fromAnyPtr<PlatooningBeacon>(object); (void)pp;
    switch (field) {
        case FIELD_vehicleId: return long2string(pp->getVehicleId());
        case FIELD_controllerAcceleration: return double2string(pp->getControllerAcceleration());
        case FIELD_acceleration: return double2string(pp->getAcceleration());
        case FIELD_speed: return double2string(pp->getSpeed());
        case FIELD_positionX: return double2string(pp->getPositionX());
        case FIELD_positionY: return double2string(pp->getPositionY());
        case FIELD_time: return double2string(pp->getTime());
        case FIELD_sequenceNumber: return long2string(pp->getSequenceNumber());
        case FIELD_length: return double2string(pp->getLength());
        case FIELD_speedX: return double2string(pp->getSpeedX());
        case FIELD_speedY: return double2string(pp->getSpeedY());
        case FIELD_angle: return double2string(pp->getAngle());
        default: return "";
    }
}

void PlatooningBeaconDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PlatooningBeacon *pp = omnetpp::fromAnyPtr<PlatooningBeacon>(object); (void)pp;
    switch (field) {
        case FIELD_vehicleId: pp->setVehicleId(string2long(value)); break;
        case FIELD_controllerAcceleration: pp->setControllerAcceleration(string2double(value)); break;
        case FIELD_acceleration: pp->setAcceleration(string2double(value)); break;
        case FIELD_speed: pp->setSpeed(string2double(value)); break;
        case FIELD_positionX: pp->setPositionX(string2double(value)); break;
        case FIELD_positionY: pp->setPositionY(string2double(value)); break;
        case FIELD_time: pp->setTime(string2double(value)); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(string2long(value)); break;
        case FIELD_length: pp->setLength(string2double(value)); break;
        case FIELD_speedX: pp->setSpeedX(string2double(value)); break;
        case FIELD_speedY: pp->setSpeedY(string2double(value)); break;
        case FIELD_angle: pp->setAngle(string2double(value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PlatooningBeacon'", field);
    }
}

omnetpp::cValue PlatooningBeaconDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    PlatooningBeacon *pp = omnetpp::fromAnyPtr<PlatooningBeacon>(object); (void)pp;
    switch (field) {
        case FIELD_vehicleId: return pp->getVehicleId();
        case FIELD_controllerAcceleration: return pp->getControllerAcceleration();
        case FIELD_acceleration: return pp->getAcceleration();
        case FIELD_speed: return pp->getSpeed();
        case FIELD_positionX: return pp->getPositionX();
        case FIELD_positionY: return pp->getPositionY();
        case FIELD_time: return pp->getTime();
        case FIELD_sequenceNumber: return pp->getSequenceNumber();
        case FIELD_length: return pp->getLength();
        case FIELD_speedX: return pp->getSpeedX();
        case FIELD_speedY: return pp->getSpeedY();
        case FIELD_angle: return pp->getAngle();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'PlatooningBeacon' as cValue -- field index out of range?", field);
    }
}

void PlatooningBeaconDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    PlatooningBeacon *pp = omnetpp::fromAnyPtr<PlatooningBeacon>(object); (void)pp;
    switch (field) {
        case FIELD_vehicleId: pp->setVehicleId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_controllerAcceleration: pp->setControllerAcceleration(value.doubleValue()); break;
        case FIELD_acceleration: pp->setAcceleration(value.doubleValue()); break;
        case FIELD_speed: pp->setSpeed(value.doubleValue()); break;
        case FIELD_positionX: pp->setPositionX(value.doubleValue()); break;
        case FIELD_positionY: pp->setPositionY(value.doubleValue()); break;
        case FIELD_time: pp->setTime(value.doubleValue()); break;
        case FIELD_sequenceNumber: pp->setSequenceNumber(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_length: pp->setLength(value.doubleValue()); break;
        case FIELD_speedX: pp->setSpeedX(value.doubleValue()); break;
        case FIELD_speedY: pp->setSpeedY(value.doubleValue()); break;
        case FIELD_angle: pp->setAngle(value.doubleValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PlatooningBeacon'", field);
    }
}

const char *PlatooningBeaconDescriptor::getFieldStructName(int field) const
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

omnetpp::any_ptr PlatooningBeaconDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    PlatooningBeacon *pp = omnetpp::fromAnyPtr<PlatooningBeacon>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void PlatooningBeaconDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    PlatooningBeacon *pp = omnetpp::fromAnyPtr<PlatooningBeacon>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'PlatooningBeacon'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

