#pragma once
#include <systemc.h>

// Place Interface:
// TODO

//template <class T>
class placeInterface : public sc_interface {
public:
	virtual void addTokens() = 0;
	virtual void removeTokens() = 0;
	virtual bool testTokens() = 0;
};

// Place Channel:
// TODO
template<unsigned int Win = 1, unsigned int Wout = 1>
class placeChannel : public placeInterface {
private:
	unsigned int tokens; /*specifies the current number of tokens in the place*/
public:

	//Default Constructor
	placeChannel() {
		this->tokens = 0;
	}
	//Constructor
	placeChannel(unsigned int tokens) {
		this->tokens = tokens;
	}
	void addTokens() {
		/*should add n tokens to the member variable tokens.*/
		this->tokens += Win;
	}
	void removeTokens() {
		/*should subtract n tokens from the member variable tokens.*/
		this->tokens -= Wout;
	}
	bool testTokens() {
		/*should return the value of the member variable tokens.*/
		return tokens >= Wout;
	}
};