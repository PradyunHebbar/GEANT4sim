# GEANT4 Simple Detector Simulation

This repository contains a basic GEANT4 simulation of particles (electron/pion/muon) passing through a simple block detector. The simulation tracks the energy deposition and trajectory of particles through a rectangular block of material.

## Prerequisites

- GEANT4 (version 11.0 or later)
- C++ compiler with C++17 support
- CMake (3.16 or later)

## Project Structure

```
.
├── CMakeLists.txt
├── README.md
├── include/
│   ├── DetectorConstruction.hh
│   ├── PhysicsList.hh
│   ├── PrimaryGeneratorAction.hh
│   ├── RunAction.hh
│   └── SteppingAction.hh
├── src/
│   ├── DetectorConstruction.cc
│   ├── PhysicsList.cc
│   ├── PrimaryGeneratorAction.cc
│   ├── RunAction.cc
│   ├── SteppingAction.cc
│   └── main.cc
└── macros/
    └── run.mac
```

## Build Instructions

1. Create a build directory:
```bash
mkdir build
cd build
```

2. Configure with CMake:
```bash
cmake ..
```

3. Build:
```bash
make
```

## Running the Simulation

1. From the build directory, run:
```bash
./SimpleDetector run.mac
```

2. The simulation will generate output files with energy deposition data in the format:
```
Event_ID Position_X Position_Y Position_Z Energy_Deposit
```

## Configuration

- Particle type and energy can be modified in `run.mac`
- Detector geometry can be modified in `DetectorConstruction.cc`
- Physics processes can be modified in `PhysicsList.cc`

## Features

- Tracks single particles through a block of material
- Records energy deposition per step
- Configurable particle type (electron/pion/muon)
- Configurable particle energy
- Simple rectangular detector geometry
- Basic electromagnetic physics processes

## Output

The simulation outputs:
1. Energy deposition data in text format
2. Basic run statistics
3. Particle trajectory information

## Author

Pradyun Hebbar
pradyun.hebbar@gmail.com