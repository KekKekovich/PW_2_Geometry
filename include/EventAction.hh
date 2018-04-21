

#ifndef CPROJECT_EVENTACT_HH
#define CPROJECT_EVENTACT_HH

#include "G4UserEventAction.hh"
#include "G4RunManager.hh"

class EventAction : public G4UserEventAction {
public:
    EventAction();
    ~EventAction();
    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);
private:

};

#endif //CPROJECT_EVENTACT_HH
