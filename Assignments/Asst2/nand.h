#pragma once

#include <systemc.h>
#include <iostream>

SC_MODULE(nand) {
    sc_in<bool> A, B;
    sc_out<bool> Z;

    void do_nand() {
        Z.write(!(A.read() && B.read()));
    }

    SC_CTOR(nand) : A("A"), B("B"), Z("Z") {
        SC_METHOD(do_nand);
        sensitive << A << B;
    }
};
