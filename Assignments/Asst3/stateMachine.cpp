#include <iostream>
#include <systemc.h>
#include "stateMachine.h"


void stateMachine::process() {


	//   ######## Simple State Machine for the Regex /GAAG/ ########

	/*switch (current_state)
	{
	case Start:
		if (input.read() == 'G') {
			current_state = G;
		}
		else if (input.read() == 'A' || input.read() == 'C' || input.read() == 'T') {
			current_state = Start;
		}
		break;

	case G:
		if (input.read() == 'A') {
			current_state = GA;
		}
		else if (input.read() == 'G') {
			current_state = G;
		}
		else if (input.read() == 'C' || input.read() == 'T') {
			current_state = Start;
		}
		break;

	case GA:
		if (input.read() == 'A') {
			current_state = GAA;
		}
		else if (input.read() == 'G') {
			current_state = G;
		}
		else if (input.read() == 'C' || input.read() == 'T') {
			current_state = Start;
		}
		break;

	case GAA:
		if (input.read() == 'G') {
			current_state = GAAG;
		}
		else if (input.read() == 'A' || input.read() == 'C' || input.read() == 'T') {
			current_state = Start;
		}
		break;

	case GAAG:
		if (input.read() == 'G') {
			current_state = G;
		}
		else if (input.read() == 'A' || input.read() == 'C' || input.read() == 'T') {
			current_state = Start;
		}
		cout << "Done" << endl;
		break;

	default:
		cout << "Invalid Input!!";
		break;
	}*/


	//######## Simple State Machine for the Regex / GA{2,}+G / ########
	switch (current_state)
	{
	case Start:
		if (input.read() == 'G') {
			current_state = G;
		}
		else if (input.read() == 'A' || input.read() == 'C' || input.read() == 'T') {
			current_state = Start;
		}
		break;
	case G:
		if(input.read() == 'A') {
			current_state = GA;
		}
		else if (input.read() == 'G') {
			current_state = G;
		}
		else if (input.read() == 'C' || input.read() == 'T') {
			current_state = Start;
		}
		break;
	case GA:
		if (input.read() == 'A') {
			current_state = GAA;
		}
		else if (input.read() == 'G') {
			current_state = G;
		}
		else if (input.read() == 'C' || input.read() == 'T') {
			current_state = Start;
		}
		break;
	case GAA:
		if (input.read() == 'A') {
			current_state = GAA;
		}
		else if (input.read() == 'G') {
			current_state = GAAG;
		}
		else if (input.read() == 'C' || input.read() == 'T') {
			current_state = Start;
		}
		break;
	case GAAG:
		if (input.read() == 'G') {
			current_state = GAAG;
		}
		else if (input.read() == 'A' || input.read() == 'C' || input.read() == 'T') {
			current_state = Start;
		}
		cout << "Done" << endl;
		break;
	default:
		cout << "Invalid Input!!";
		break;
	}
	
}