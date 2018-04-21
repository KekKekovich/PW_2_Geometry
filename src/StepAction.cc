
#include <G4Step.hh>
#include <G4UserSteppingAction.hh>
#include "StepAction.hh"

void StepAction::UserSteppingAction(const G4Step *step) {
    G4UserSteppingAction::UserSteppingAction(step);
}
