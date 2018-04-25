
#include <G4Orb.hh>
#include <G4Colour.hh>
#include "DetGeometry.hh"
#include <G4VisAttributes.hh>
#include <G4Cons.hh>
#include <G4Para.hh>
#include <G4Tubs.hh>
#include <G4IntersectionSolid.hh>
#include <G4SubtractionSolid.hh>
#include <G4UnionSolid.hh>
#include <iostream>

DetGeometry::DetGeometry() {
    world_sizeXYZ   = 3 * m;
    nist            = G4NistManager::Instance();
    world_mat       = nist->FindOrBuildMaterial("G4_AIR");
    solidWorld      = new G4Box("solWorld", 0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);
    logicWorld      = new G4LogicalVolume(solidWorld, world_mat, "logWorld");
    physWorld       = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0);

    G4cout<<"Geometry of detector is build successfully\t\t\t\t\t\tOK!!!"<<G4endl;
}

DetGeometry::~DetGeometry() {}

G4VPhysicalVolume* DetGeometry::Construct(){

//    auto tubs = new G4Tubs("tubs", 0, 0.5*m, 2*m, 0, 360*deg);
//    auto tubs_log = new G4LogicalVolume(tubs, G4NistManager::Instance()->FindOrBuildMaterial("G4_AIR"), "tubs");
//    tubs_log->SetVisAttributes(G4Colour::Green());
//    new G4PVPlacement(0, G4ThreeVector(0, 0, 0), tubs_log, "tubs", logicWorld, false, 0);
//    auto box = new G4Box("box", 2*sqrt(3) / 2 *m, 1*m, 1*m);
//
//    G4UnionSolid* Inter = new G4UnionSolid("inters", box, box, new G4RotationMatrix(60*deg, 0, 0),G4ThreeVector(0, 0, 0));
//    G4UnionSolid* Inter3 = new G4UnionSolid("inters", Inter, box, new G4RotationMatrix(120*deg, 0, 0),G4ThreeVector(0, 0, 0));
//    G4SubtractionSolid* Inter2 = new G4SubtractionSolid("inters", Inter3, tubs);
//
//    G4LogicalVolume* Inter_log = new G4LogicalVolume(Inter2, world_mat,"int_log");
//    Inter_log->SetVisAttributes(G4Colour::Blue());

//    for ( int i = -2; i < 2; i ++) {
//        for (int j = -2; j < 2; j++) {
//            for (int k = -2; k < 2; k++) {
//                new G4PVPlacement(new G4RotationMatrix(0, 0, 0), G4ThreeVector(k * 5 * m, j * 5 * m, i * 5 * m),
//                                  Inter_log, "int_log", logicWorld, false, 0);
//            }
//        }
//    }

//    for ( int i = 0; i < 5; i ++) {
//        new G4PVPlacement(new G4RotationMatrix(15*i*deg, 0, 0), G4ThreeVector(0, 0, i * 2 * m),
//                          Inter_log, "int_log", logicWorld, false, 0);
//    }

    std::ofstream file("../result.txt");

//    G4Element *Na = new G4Element("Na", "Na", 11, 22.990*g/mole);
//    G4Element *I = new G4Element("I", "I", 53, 126.904*g/mole);
//
//    G4Material *NaI = new G4Material("NaI", 3.667*g/cm3, 2, kStateSolid);
//    NaI->AddElement(Na, 1);
//    NaI->AddElement(I, 1);
//
//    G4Element* Al = nist->FindOrBuildElement(13);
//    G4Element* Mg = nist->FindOrBuildElement(12);
//    G4Element* Fe = nist->FindOrBuildElement(26);
//    G4Element* Si = nist->FindOrBuildElement(14);
//
//    G4Material* AMG = new G4Material("AMG", 2.64*g/cm3, 4, kStateSolid);
//    AMG->AddElement(Al, 0.92);
//    AMG->AddElement(Mg, 0.06);
//    AMG->AddElement(Fe, 0.01);
//    AMG->AddElement(Si, 0.01);
    G4Material* CH = nist->FindOrBuildMaterial("G4_CESIUM_IODIDE");

//    auto tubs = new G4Tubs("tubs", 0, 1*m, 2*m, 0, 360*deg);
//    auto tubs_log = new G4LogicalVolume(tubs, NaI, "tubs");
//    tubs_log->SetVisAttributes(G4Colour::Red());
//    new G4PVPlacement(0, G4ThreeVector(0, 0, 0), tubs_log, "tubs", logicWorld, false, 0);
//
//    auto orb = new G4Orb("orb", 1*m);
//    auto orb_log = new G4LogicalVolume(orb, NaI, "orb");
//    orb_log->SetVisAttributes(G4Colour::Green());
//    new G4PVPlacement(0, G4ThreeVector(3*m, 0, 0), orb_log, "orb", logicWorld, false, 0);
    double l = 10*cm;
    auto box = new G4Box("box", l, l, l);
    auto box_log = new G4LogicalVolume(box, CH, "box");
    box_log->SetVisAttributes(G4Colour::Yellow());
    new G4PVPlacement(0, G4ThreeVector(-15*cm - l, 0, 0), box_log, "box", logicWorld, false, 0);

    auto box1 = new G4Box("box1", l, l, l);
    auto box1_log = new G4LogicalVolume(box1, CH, "box1");
    box1_log->SetVisAttributes(G4Colour::Blue());
    new G4PVPlacement(0, G4ThreeVector(30*cm + l, 0, 0), box1_log, "box1", logicWorld, false, 0);
//    file<<NaI<<"\n";
//    file<<AMG;
//    std::cout << NaI << std::endl;
//    std::cout << AMG << std::endl;
//
//    file << "Tubs volume " << tubs->GetCubicVolume() / m3 << std::endl;
//    file << "Orb surface area " << orb->GetSurfaceArea() / m2 << std::endl;
//    file << "Box volume " << box->GetCubicVolume() / m3 << std::endl;
//    file << "Box mass " << box_log->GetMass()/g << std::endl;

    return physWorld;
}