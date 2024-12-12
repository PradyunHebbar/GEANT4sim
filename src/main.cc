#include "G4RunManager.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "FTFP_BERT.hh"

#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "SteppingAction.hh"

int main(int argc, char** argv) {
    // Construct the run manager
    auto runManager = new G4RunManager;

    // Set mandatory initialization classes
    runManager->SetUserInitialization(new DetectorConstruction());
    runManager->SetUserInitialization(new FTFP_BERT());
    runManager->SetUserAction(new PrimaryGeneratorAction());
    
    // Set user action classes
    runManager->SetUserAction(new RunAction());
    runManager->SetUserAction(new SteppingAction());

    // Initialize G4 kernel
    runManager->Initialize();

    // Get the pointer to the UI manager
    G4UImanager* UImanager = G4UImanager::GetUIpointer();

    if (argc == 1) {  // Interactive mode
        G4UIExecutive* ui = new G4UIExecutive(argc, argv);
        G4VisExecutive* visManager = new G4VisExecutive;
        visManager->Initialize();
        UImanager->ApplyCommand("/control/execute vis.mac");
        ui->SessionStart();
        delete ui;
        delete visManager;
    }
    else {  // Batch mode
        G4String command = "/control/execute ";
        G4String fileName = argv[1];
        UImanager->ApplyCommand(command + fileName);
    }

    delete runManager;
    return 0;
}