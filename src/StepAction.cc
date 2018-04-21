
#include <G4Step.hh>
#include <G4UserSteppingAction.hh>
#include "StepAction.hh"
#include "EventAction.hh"

StepAction::StepAction(EventAction *event) {
    eventAction = event;
}

void StepAction::UserSteppingAction(const G4Step *aStep) {
    if (aStep->GetTotalEnergyDeposit() > 0) {
        eventAction->Data(aStep->GetTrack()->GetVolume()->GetName(), aStep->GetTotalEnergyDeposit());
    }
}


