
#include <Randomize.hh>
#include <G4Neutron.hh>
#include "PrimaryGen.hh"

PrimaryGen::PrimaryGen() {
    gun = new G4ParticleGun(1);
    G4cout<<"Primary particles generator is created successfully\t\tOK!!!"<<G4endl;
}

PrimaryGen::~PrimaryGen() {

}

void PrimaryGen::GeneratePrimaries(G4Event* anEvent) {
    gun->SetParticleDefinition(G4Neutron::NeutronDefinition());
    gun->SetParticleEnergy(150* keV);

//    double R = 10*cm, px, py, pz;
//
//     do {
//        px = (2*G4UniformRand()-1) * cm;
//        py = (2*G4UniformRand()-1) * cm;
//        pz = (2*G4UniformRand()-1) * cm;
//    } while (sqrt(px*px + py*py + pz*pz) > R);
//
//    gun->SetParticlePosition(G4ThreeVector(px,-3*m + py, pz));

    gun->SetParticlePosition(G4ThreeVector(0,0,0));

    double x = 2*G4UniformRand()-1;
    double y = 2*G4UniformRand()-1;
    double z = 2*G4UniformRand()-1;
    double r = sqrt(x*x + y*y + z*z);

    gun->SetParticleMomentumDirection(G4ThreeVector(x/r, y/r, z/r));
   // gun->SetParticleMomentumDirection(G4ThreeVector(1, 0, 0));


    gun->GeneratePrimaryVertex(anEvent);
}