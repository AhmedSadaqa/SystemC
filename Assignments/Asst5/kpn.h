#pragma once
#include <systemc.h>

template <class T>
SC_MODULE(kpn)
{
private:
    
    // Input FIFOS
    sc_fifo<T> a, b, c, d;

    // Output signal
    sc_signal<T> e;
    

    // Processes
    void add(); //This process reads one integer number from  (a) and (c) and writes the sum output (b)
    void split(); //This process copies its input (b) to two FIFOs (a) and (d) and to the output signal (e.
    void delay(); // This process writes its input (d) to its output (c).

public:
    

    SC_CTOR(kpn) : a(10), b(10), c(10), d(10), e(0) 
    {
        //Two FIFOs are initialized with single values : b = 1 and c = 0.
        b.write(1);
        c.write(0);

        

        SC_THREAD(add);
        SC_THREAD(delay);
        SC_THREAD(split);

        
        
    }
    

};