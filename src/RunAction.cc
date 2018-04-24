
#include <G4Run.hh>
#include <G4UserRunAction.hh>
#include "RunAction.hh"
#include "EventAction.hh"

void RunAction::BeginOfRunAction(const G4Run *aRun) {
    G4UserRunAction::BeginOfRunAction(aRun);

}

void RunAction::EndOfRunAction(const G4Run *aRun) {
    G4UserRunAction::EndOfRunAction(aRun);
}

RunAction::RunAction() {

}
