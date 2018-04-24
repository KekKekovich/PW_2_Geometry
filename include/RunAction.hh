//
// Created by student on 21.04.18.
//

#ifndef PW_2_GEOMETRY_RUNACTION_HH
#define PW_2_GEOMETRY_RUNACTION_HH

#include <G4UserRunAction.hh>
#include <map>

class RunAction : public G4UserRunAction {
private:
    std::map<G4double, G4int> *map;
public:
    RunAction();
    void BeginOfRunAction(const G4Run *aRun) override;

    void EndOfRunAction(const G4Run *aRun) override;
};
#endif //PW_2_GEOMETRY_RUNACTION_HH
