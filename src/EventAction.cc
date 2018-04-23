
#include <G4String.hh>
#include <G4Event.hh>
#include <G4UserEventAction.hh>
#include <EventAction.hh>
#include <RunAction.hh>

EventAction::EventAction(RunAction* run) : runAction(run) {}

void EventAction::BeginOfEventAction(const G4Event *event) {
    G4UserEventAction::BeginOfEventAction(event);
}

void EventAction::EndOfEventAction(const G4Event *event) {
    G4UserEventAction::EndOfEventAction(event);
}

void EventAction::Data(G4String name, G4double Energy) {

}


