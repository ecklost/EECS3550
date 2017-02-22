#include "stdafx.h"
#include "operators.h"
#include "arithmetic.h"
#include "logical.h"
#include "relational.h"
#include <string>

operators::operators() {

}

void operators::useOp(std::string op) {
	// arithmetic
	if (op.compare("+")) {
		// +
	}
	else if (op.compare("-")) {
		// -
	}
	else if (op.compare("*")) {
		// *
	}
	else if (op.compare("/")) {
		// /
	}
	else if (op.compare("div")) {
		// mod
	}

	// logical
	else if (op.compare("&")) {
		// &
	}
	else if (op.compare("|")) {
		// |
	}
	else if (op.compare("!")) {
		// !
	}

	// relational
	else if (op.compare("<>")) {
		// <>
	}
	else if (op.compare("<=")) {
		// <=
	}
	else if (op.compare(">=")) {
		// >=
	}
	else if (op.compare("<")) {
		// <
	}
	else if (op.compare(">")) {
		// >
	}
	else if (op.compare("==")) {
		// ==
	}
	else {
		std::cout << "Invalid operator";
		exit(1);
	}
}

operators::~operators() {

}
