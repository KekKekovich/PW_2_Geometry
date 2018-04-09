
#include <Randomize.hh>
#include "PrimaryGen.hh"
#include "Random.h"

PrimaryGen::PrimaryGen() {
    gun = new G4ParticleGun(1);
    G4cout<<"Primary particles generator is created successfully\t\tOK!!!"<<G4endl;
}

PrimaryGen::~PrimaryGen() {

}

void PrimaryGen::GeneratePrimaries(G4Event* anEvent) {
//    RandomSpectre a(0, 1);
//    G4double E = a.RandomVariate(0,5,0.01,1)[0]* MeV;

    gun->SetParticleDefinition(G4Gamma::GammaDefinition());
    gun->SetParticleEnergy(662 * keV);

    double R = 10*cm, px, py, pz;

     do {
        px = (2*G4UniformRand()-1) * cm;
        py = (2*G4UniformRand()-1) * cm;
        pz = (2*G4UniformRand()-1) * cm;
    } while (sqrt(px*px + py*py + pz*pz) > R);

//    gun->SetParticlePosition(G4ThreeVector(px, py, pz));
    gun->SetParticlePosition(G4ThreeVector(0, 0, 0));

    double x = 2*G4UniformRand()-1;
    double y = 2*G4UniformRand()-1;
    double z = 2*G4UniformRand()-1;
    double r = sqrt(x*x + y*y + z*z);
//    gun->SetParticleMomentum(G4ThreeVector(x/r, y/r, z/r));
    gun->SetParticleMomentum(G4ThreeVector(1, 0, 0));


    gun->GeneratePrimaryVertex(anEvent);
}