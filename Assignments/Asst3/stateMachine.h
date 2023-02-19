#pragma once
#include <systemc.h>



SC_MODULE(stateMachine) {
private:
	enum base { Start, G, GA, GAA, GAAG };
	void process();
public:
	sc_in<char> input;
	sc_in<bool> clk;
	base current_state = base::Start;
	//stateMachine(const sc_module_name & name);
	SC_CTOR(stateMachine) : input("input"), clk("clk") {
		SC_METHOD(process);
		sensitive << clk.pos();
		dont_initialize();
	}
};


