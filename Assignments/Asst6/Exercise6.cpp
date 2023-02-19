#include <iostream>
#include <iomanip>
#include <systemc.h>

#include "memory.h"
#include "processor.h"
#include "bus.h"


//int sc_main(int, char**)
//{
//    processor cpu0("cpu0", "stimuli1.txt", sc_time(1, SC_NS));
//    processor cpu1("cpu1", "stimuli2.txt", sc_time(1, SC_NS));
//    memory<512> memory0("memory0");
//    memory<512> memory1("memory1");
//    bus bus0("bus0");
//
//    // TODO: add your code here
//
//    cpu0.iSocket.bind(bus0.tSocket[0]);
//    cpu1.iSocket.bind(bus0.tSocket[1]);
//
//    bus0.iSocket[0].bind(memory0.tSocket);
//    bus0.iSocket[1].bind(memory1.tSocket);
//
//    std::cout << std::endl << "Name "
//        << std::setfill(' ') << std::setw(10)
//        << "Time" << " "
//        << std::setfill(' ') << std::setw(5)
//        << "CMD" << "   "
//        << std::setfill(' ') << std::setw(8)
//        << "Address"
//        << "   " << std::hex
//        << std::setfill(' ') << std::setw(8)
//        << "Data"
//        << " " << std::endl
//        << "-------------------------------------------"
//        << std::endl;
//
//    sc_start();
//
//    std::cout << std::endl;
//    return 0;
//}