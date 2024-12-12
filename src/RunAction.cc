#include "RunAction.hh"
#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

#include <fstream>

RunAction::RunAction() : G4UserRunAction() {
    outputFileName = "output.txt";
}

RunAction::~RunAction() {}

void RunAction::BeginOfRunAction(const G4Run* run) {
    G4cout << "### Run " << run->GetRunID() << " start." << G4endl;
    
    // Create output file
    std::ofstream outFile;
    outFile.open(outputFileName, std::ios::out);
    outFile << "# Event_ID Position_X(mm) Position_Y(mm) Position_Z(mm) Energy_Deposit(MeV)" << G4endl;
    outFile.close();
}

void RunAction::EndOfRunAction(const G4Run* run) {
    G4int nofEvents = run->GetNumberOfEvent();
    if (nofEvents == 0) return;
    
    // Print run summary
    G4cout << "\n--------------------End of Run---------------------\n"
           << " The run was " << nofEvents << " events " << G4endl;
}