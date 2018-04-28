
#include <G4String.hh>
#include <G4Event.hh>
#include <G4UserEventAction.hh>
#include <EventAction.hh>
#include <RunAction.hh>
#include "fstream"

EventAction::EventAction(RunAction* run) {
    runAction = run;
    result = new std::map<G4String, G4double>;
}

void EventAction::BeginOfEventAction(const G4Event *event) {

}

void EventAction::EndOfEventAction(const G4Event *event) {
    std::ofstream file("../result.txt", std::ios_base::app);
    file.clear();

    for(auto it: *result) {
        file << it.first << " | " << it.second << "\n";
    }
    file.close();

    for(auto it: *result) {
        if((it.second > 0.1) && (it.first == "box")) {
            runAction->AddEvent(it.first, it.second);
        } else {


        }

    }

    for(auto it: *result) {
        if((it.second > 0.2) && (it.first == "box1")) {
            runAction->AddEvent(it.first, it.second);
        } else {


        }

    }

    for(auto it: *result) {
        if((it.second > 0.5) && (it.first == "box2")) {
            runAction->AddEvent(it.first, it.second);
        } else {


        }

    }
    for(auto it: *result) {
        if((it.second > 1) && (it.first == "box3")) {
            runAction->AddEvent(it.first, it.second);
        } else {


        }

    }

    if(result->size()>=0) {

        result->clear();
    }
}

void EventAction::Data(G4String name, G4double Energy) {
    if( result->find(name) == result->end()) {
        result->emplace(name, Energy);
    }
    result->find(name)->second += Energy;
}


