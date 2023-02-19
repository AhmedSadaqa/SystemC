#include "kpn.h"

// ADD THINGS HERE

template<class T> void kpn<T>::add() {
	while (true) {
		b.write(a.read() + c.read());
	}
}
template void kpn<unsigned int>::add();


template<class T> void kpn<T>::split() {
	for (unsigned int i = 0; i < 10; i++)
	{
		T val = b.read();
		d.write(val);
		a.write(val);
		e.write(val);

		cout << "The output is " << e.read() << endl;
	}
	sc_stop();
}
template void kpn<unsigned int>::split();



template<class T> void kpn<T>::delay() {
	while (true) {
		c.write(d.read());
	}
}
template void kpn<unsigned int>::delay();


