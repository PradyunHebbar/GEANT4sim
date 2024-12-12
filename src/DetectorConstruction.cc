#include "DetectorConstruction.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"

DetectorConstruction::DetectorConstruction() {}

DetectorConstruction::~DetectorConstruction() {}

G4VPhysicalVolume* DetectorConstruction::Construct() {
    // Get material from NIST database
    G4NistManager* nist = G4NistManager::Instance();
    G4Material* silicon = nist->FindOrBuildMaterial("G4_Si");

    // World volume
    G4Box* solidWorld = new G4Box("World", 50*cm, 50*cm, 50*cm);
    G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, 
                                                     nist->FindOrBuildMaterial("G4_AIR"),
                                                     "World");
    G4VPhysicalVolume* physWorld = new G4PVPlacement(0,
                                                     G4ThreeVector(),
                                                     logicWorld,
                                                     "World",
                                                     0,
                                                     false,
                                                     0);

    // Detector volume
    G4Box* solidDetector = new G4Box("Detector", 10*cm, 10*cm, 1*cm);
    logicDetector = new G4LogicalVolume(solidDetector, silicon, "Detector");
    physDetector = new G4PVPlacement(0,
                                    G4ThreeVector(0, 0, 0),
                                    logicDetector,
                                    "Detector",
                                    logicWorld,
                                    false,
                                    0);

    return physWorld;
}