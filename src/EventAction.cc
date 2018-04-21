
#include <G4String.hh>
#include "EventAction.hh"

EventAction::EventAction(RunAction *action) {
    runAction = action;
}

void EventAction::BeginOfEventAction(const G4Event *event) {
    G4UserEventAction::BeginOfEventAction(event);
}

void EventAction::EndOfEventAction(const G4Event *event) {
    G4UserEventAction::EndOfEventAction(event);
}

void EventAction::Data(G4String name, G4double Energy) {

}


