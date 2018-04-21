//
// Created by student on 21.04.18.
//

#ifndef PW_2_GEOMETRY_STEPACTION_HH
#define PW_2_GEOMETRY_STEPACTION_HH

#include <G4UserSteppingAction.hh>
#include <EventAction.hh>

class StepAction: public G4UserSteppingAction {
private:
    EventAction* eventAction;

public:
    StepAction(EventAction* event);
    void UserSteppingAction(const G4Step *step) override;
};

#endif //PW_2_GEOMETRY_STEPACTION_HH
