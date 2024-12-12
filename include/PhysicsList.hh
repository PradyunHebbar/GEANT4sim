#ifndef PhysicsList_h
#define PhysicsList_h

#include "G4VModularPhysicsList.hh"
#include "globals.hh"

class PhysicsList : public G4VModularPhysicsList {
public:
    PhysicsList();
    virtual ~PhysicsList();

    virtual void SetCuts();
protected:
    // Construct particle and physics processes
    virtual void ConstructParticle();
    virtual void ConstructProcess();
};

#endif