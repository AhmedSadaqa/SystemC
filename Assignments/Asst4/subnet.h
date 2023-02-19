#pragma once

#include <systemc.h>

#include "place.h"
#include "transition.h"

// Subnet:
// TODO
SC_MODULE(subnet) {
public:
    transition<1, 1, 1> ACT;
    transition<1, 1> RD;
    transition<1, 1> PRE;
    transition<1, 1> WR;

    placeChannel<1,1> ACTIVE;

    SC_CTOR(subnet) : ACT("ACT"), RD("RD"), PRE("PRE"), WR("WR"), ACTIVE(0) {
        ACT.out.bind(ACTIVE);
        ACT.inhibitors.bind(ACTIVE);

        RD.in.bind(ACTIVE);
        RD.out.bind(ACTIVE);

        PRE.in.bind(ACTIVE);

        WR.in.bind(ACTIVE);
        WR.out.bind(ACTIVE);
    }
};