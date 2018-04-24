
#include <G4String.hh>
#include <G4Event.hh>
#include <G4UserEventAction.hh>
#include <EventAction.hh>
#include <RunAction.hh>

EventAction::EventAction(RunAction* run) {
    runAction = run;
    result = new std::map<G4String, G4double>;
}

void EventAction::BeginOfEventAction(const G4Event *event) {

}

void EventAction::EndOfEventAction(const G4Event *event) {
    for(auto it: *result) {
        std::cout << it.first << " | " << it.second << "\n";
    }
    if(result->size()>=0) {

        result->clear();
    }
}

void EventAction::Data(G4String name, G4double Energy) {
    if(result->find(name) == result->end()) {
        result->emplace(name, Energy);
    }
    result->find(name)->second += Energy;
}

EventAction::~EventAction() {
}


