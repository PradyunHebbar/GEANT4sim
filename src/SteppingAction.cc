#include "SteppingAction.hh"
#include "G4Step.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"

#include <fstream>

SteppingAction::SteppingAction() : G4UserSteppingAction() {}

SteppingAction::~SteppingAction() {}

void SteppingAction::UserSteppingAction(const G4Step* step) {
    // Get volume of the current step
    G4VPhysicalVolume* volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
    
    // Check if we're in the detector
    if (volume->GetName() != "Detector") return;
    
    // Get energy deposit
    G4double edep = step->GetTotalEnergyDeposit();
    if (edep == 0.) return;
    
    // Get position
    G4ThreeVector pos = step->GetPreStepPoint()->GetPosition();
    
    // Get event ID
    G4int eventID = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();
    
    // Write to file
    std::ofstream outFile;
    outFile.open("output.txt", std::ios::app);
    outFile << eventID << " "
            << pos.x()/mm << " "
            << pos.y()/mm << " "
            << pos.z()/mm << " "
            << edep/MeV << G4endl;
    outFile.close();
}