//
// Created by student on 21.04.18.
//

#ifndef PW_2_GEOMETRY_RUNACTION_HH
#define PW_2_GEOMETRY_RUNACTION_HH

#include <G4UserRunAction.hh>
#include <map>
#include <fstream>

class RunAction : public G4UserRunAction {
private:
    std::map<G4double, G4int> *res;
    G4double N1, N2;

public:
    RunAction();
    ~RunAction();

    void BeginOfRunAction(const G4Run *aRun) override;

    void EndOfRunAction(const G4Run *aRun) override;

    void AddEvent(G4String name, G4double energy);
};
#endif //PW_2_GEOMETRY_RUNACTION_HH
