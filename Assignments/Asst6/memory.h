#pragma once

#include <iostream>
#include <tlm.h>
#include <systemc.h>


// TODO: add your code here
template <unsigned int N = 1024>
class memory :sc_module, tlm::tlm_fw_transport_if<> {
private:
	unsigned char mem[N];
public:
	tlm::tlm_target_socket<> tSocket;

	memory(sc_module_name) {
		tSocket.bind(*this);
	}
	SC_HAS_PROCESS(memory);

	void b_transport(tlm::tlm_generic_payload& trans, sc_time& delay) {
		{
			if (trans.get_address() >= 1024)
			{
				trans.set_response_status(tlm::TLM_ADDRESS_ERROR_RESPONSE);
				SC_REPORT_FATAL(this->name(), "Address greater than or equal to 1024 is accessed!!");
			}

			if (trans.get_data_length() != 1)
			{
				trans.set_response_status(tlm::TLM_BURST_ERROR_RESPONSE);
				return;
			}

			if (trans.get_command() == tlm::TLM_WRITE_COMMAND)
			{
				memcpy(&mem[trans.get_address()], // destination
					trans.get_data_ptr(),      // source
					trans.get_data_length());  // size
			}
			else // (trans.get_command() == tlm::TLM_READ_COMMAND)
			{
				memcpy(trans.get_data_ptr(),      // destination
					&mem[trans.get_address()], // source
					trans.get_data_length());  // size
			}

			delay = delay + sc_time(20, SC_NS);

		}

	}

	//stubs
	virtual tlm::tlm_sync_enum nb_transport_fw(tlm::tlm_generic_payload& trans, tlm::tlm_phase& phase,
		sc_time& delay)
	{
		SC_REPORT_FATAL(this->name(), "nb_transport_fw is not implemented");
		return tlm::TLM_ACCEPTED;
	}

	//stubs
	bool get_direct_mem_ptr(tlm::tlm_generic_payload& trans,tlm::tlm_dmi& dmi_data)
	{
		SC_REPORT_FATAL(this->name(), "get_direct_mem_ptr is not implemented");
		return false;
	}

	//stubs
	unsigned int transport_dbg(tlm::tlm_generic_payload& trans)
	{
		SC_REPORT_FATAL(this->name(), "transport_dbg is not implemented");
		return 0;
	}
};



