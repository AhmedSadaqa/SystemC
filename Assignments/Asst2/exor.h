#pragma 
#include <systemc.h>
#include <iostream>
#include "nand.h"



SC_MODULE(exor) {
	sc_in <bool> A;
	sc_in <bool> B;
	sc_out <bool> Z;

	sc_signal <bool> h1, h2, h3;
	nand n1, n2, n3, n4;

	SC_CTOR(exor) : A("A"), B("B"), Z("Z"), h1("h1"), h2("h2"), h3("h3"), n1("nand1"), n2("nand2"), n3("nand3"), n4("nand4") {
		n1.A.bind(A);
		n1.B.bind(B);
		n1.Z.bind(h1);

		n2.A.bind(A);
		n2.B.bind(h1);
		n2.Z.bind(h2);

		n3.A.bind(h1);
		n3.B.bind(B);
		n3.Z.bind(h3);

		n4.A.bind(h2);
		n4.B.bind(h3);
		n4.Z.bind(Z);

	}
};