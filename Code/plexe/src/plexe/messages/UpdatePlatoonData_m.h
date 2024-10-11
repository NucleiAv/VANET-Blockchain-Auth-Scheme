//
// Generated file, do not edit! Created by opp_msgtool 6.0 from plexe/messages/UpdatePlatoonData.msg.
//

#ifndef __UPDATEPLATOONDATA_M_H
#define __UPDATEPLATOONDATA_M_H

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#include <omnetpp.h>

// opp_msgtool version check
#define MSGC_VERSION 0x0600
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of opp_msgtool: 'make clean' should help.
#endif

// dll export symbol
#ifndef PLEXE_API
#  if defined(PLEXE_EXPORT)
#    define PLEXE_API  OPP_DLLEXPORT
#  elif defined(PLEXE_IMPORT)
#    define PLEXE_API  OPP_DLLIMPORT
#  else
#    define PLEXE_API
#  endif
#endif

class UpdatePlatoonData;
#include "UpdatePlatoonFormation_m.h" // import UpdatePlatoonFormation

/**
 * Class generated from <tt>plexe/messages/UpdatePlatoonData.msg:26</tt> by opp_msgtool.
 * <pre>
 * // Message to inform the all vehicles in the Platoon of the updated formation.
 * // Is similar to a PlatoonBeacon.
 * packet UpdatePlatoonData extends UpdatePlatoonFormation
 * {
 *     int newPlatoonId;
 * }
 * </pre>
 */
class PLEXE_API UpdatePlatoonData : public ::UpdatePlatoonFormation
{
  protected:
    int newPlatoonId = 0;

  private:
    void copy(const UpdatePlatoonData& other);

  protected:
    bool operator==(const UpdatePlatoonData&) = delete;

  public:
    UpdatePlatoonData(const char *name=nullptr, short kind=0);
    UpdatePlatoonData(const UpdatePlatoonData& other);
    virtual ~UpdatePlatoonData();
    UpdatePlatoonData& operator=(const UpdatePlatoonData& other);
    virtual UpdatePlatoonData *dup() const override {return new UpdatePlatoonData(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    virtual int getNewPlatoonId() const;
    virtual void setNewPlatoonId(int newPlatoonId);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const UpdatePlatoonData& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, UpdatePlatoonData& obj) {obj.parsimUnpack(b);}


namespace omnetpp {

template<> inline UpdatePlatoonData *fromAnyPtr(any_ptr ptr) { return check_and_cast<UpdatePlatoonData*>(ptr.get<cObject>()); }

}  // namespace omnetpp

#endif // ifndef __UPDATEPLATOONDATA_M_H

