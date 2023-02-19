#pragma once


#include <systemc.h>

#include "place.h"

// Transition:
// TODO
template<unsigned int N = 1, unsigned int M = 1, unsigned int L = 0>
SC_MODULE(transition) {
public:
	SC_CTOR(transition) {}

	/*sc_port<placeInterface<unsigned int>> in;
	sc_port<placeInterface<unsigned int>> out;*/

	sc_port<placeInterface, N, SC_ALL_BOUND> in;
	sc_port<placeInterface, M, SC_ALL_BOUND> out;
	sc_port<placeInterface, L, SC_ZERO_OR_MORE_BOUND> inhibitors;

	/*void fire() {
		if (in->testTokens() > 0) {
			cout << this->name() << ": Fired" << endl;
		}
		else {
			cout << this->name() << ": NOT Fired" << endl;
		}
		in->removeTokens(1);
		out->addTokens(1);
	}*/

	/*void fire() {
		for (unsigned int i = 0; i < N; i++)
		{
			if (in[i]->testTokens()) {
				cout << this->name() << ": Fired" << endl;
				in[i]->removeTokens();
				out[i]->addTokens();
			}
			else {
				cout << this->name() << ": NOT Fired" << endl;
			}
			
		}
	}*/

	void fire() {
		bool NoInhibitors = true;

		for (unsigned int i = 0; i < L; i++)
		{
			if (inhibitors[i]->testTokens()) {
				NoInhibitors = false;
			}
		}
		for (unsigned int i = 0; i < N; i++)
		{
			if (in[i]->testTokens() && NoInhibitors) {
				cout << this->name() << ": Fired" << endl;
				in[i]->removeTokens();
				out[i]->addTokens();
			}
			else {
				cout << this->name() << ": NOT Fired" << endl;
			}

		}
	}
};