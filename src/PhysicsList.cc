#include "PhysicsList.hh"

#include "G4EmStandardPhysics.hh"
#include "G4EmExtraPhysics.hh"
#include "G4DecayPhysics.hh"
#include "G4HadronElasticPhysics.hh"
#include "G4HadronPhysicsFTFP_BERT.hh"
#include "G4IonPhysics.hh"
#include "G4StoppingPhysics.hh"

#include "G4SystemOfUnits.hh"

PhysicsList::PhysicsList() : G4VModularPhysicsList() {
    // Default cut value
    defaultCutValue = 0.1*mm;
    
    // EM Physics
    RegisterPhysics(new G4EmStandardPhysics());
    
    // Decay Physics
    RegisterPhysics(new G4DecayPhysics());
    
    // Hadron Elastic scattering
    RegisterPhysics(new G4HadronElasticPhysics());
    
    // Hadron Physics
    RegisterPhysics(new G4HadronPhysicsFTFP_BERT());
    
    // Stopping Physics
    RegisterPhysics(new G4StoppingPhysics());
    
    // Ion Physics
    RegisterPhysics(new G4IonPhysics());
}

PhysicsList::~PhysicsList() {}

void PhysicsList::SetCuts() {
    // Set cuts for all particles
    SetCutsWithDefault();
}

void PhysicsList::ConstructParticle() {
    G4VModularPhysicsList::ConstructParticle();
}

void PhysicsList::ConstructProcess() {
    G4VModularPhysicsList::ConstructProcess();
}