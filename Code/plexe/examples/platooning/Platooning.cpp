/*
 * Platooning.cpp
 *
 *  Created on: Aug 18, 2024
 *      Author: nsen
 */


#include "Platooning.h"

#include <omnetpp.h>

using namespace omnetpp;

int main(int argc, char *argv[]) {
    // Initialize OMNeT++
    cEnvir *env = cSimulation::getActiveEnvir();
    //env->setup(argc, argv);

    cSimulation *sim = new cSimulation("PlatooningSimulation", env);
    std::cout << "Checking network!" << endl;
    // Load the .ned file and instantiate the network
    cModuleType *networkType = cModuleType::get("Platooning");
    if (!networkType) {
        std::cout << "Network not found!" << endl;
        return 1;
    }
    std::cout << "Network Found!" << endl;


    sim->setupNetwork(networkType);

    /// Since sim expects a NetworkType, maybe it makes the
    ///network itself and calls these when we call run? who knows.

    //cModule *network = networkType->create("network", sim);
    //network->buildInside();
    //network->scheduleStart(simTime());

    // Run the simulation
    sim->callInitialize();

    sim->transferToMain();

    // Clean up
    delete sim;
    return 0;
}
