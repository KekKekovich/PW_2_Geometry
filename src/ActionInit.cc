
#include "ActionInit.hh"
#include "EventAction.hh"
#include "StepAction.hh"
#include "RunAction.hh"

ActionInit::ActionInit()
{ }

ActionInit::~ActionInit()
{ }

void ActionInit::Build() const {
    SetUserAction(new PrimaryGen());
}