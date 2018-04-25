

#ifndef PW_2_GEOMETRY_EVENTACT_HH
#define PW_2_GEOMETRY_EVENTACT_HH

#include "G4UserEventAction.hh"
#include "G4RunManager.hh"
#include "RunAction.hh"

class EventAction : public G4UserEventAction {
private:
    RunAction *runAction;
    std::map<G4String, G4double> *result;
public:
   EventAction(RunAction *runAction);

    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);
    void Data(G4String name, G4double Energy);
private:

};

#endif //PW_2_GEOMETRY_EVENTACT_HH
