#pragma once

#include <systemc.h>

SC_MODULE(stim)
{
public:
    sc_out<bool> A, B;
    sc_in<bool> clk;

    SC_CTOR(stim)
    {
        SC_THREAD(StimGen);
        sensitive << clk.pos();
    }

private:
    void StimGen()
    {
        wait(SC_ZERO_TIME);
        A.write(false);
        B.write(false);
        wait();
        A.write(false);
        B.write(true);
        wait();
        A.write(true);
        B.write(false);
        wait();
        A.write(true);
        B.write(true);
        wait();
        A.write(false);
        B.write(false);
        wait();
        sc_stop();
    }
};
