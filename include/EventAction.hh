

#ifndef CPROJECT_EVENTACT_HH
#define CPROJECT_EVENTACT_HH

#include "G4UserEventAction.hh"
#include "G4RunManager.hh"
#include "RunAction.hh"

class EventAction : public G4UserEventAction {
private:
    RunAction *runAction;
public:
   EventAction(RunAction *action);
    ~EventAction();

    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);
    void Data(G4String name, G4double Energy);
private:

};

#endif //CPROJECT_EVENTACT_HH
