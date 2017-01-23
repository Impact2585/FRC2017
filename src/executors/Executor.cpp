/*
 * Executor.cpp
 *
 *  Created on: Jan 22, 2017
 *      Author: joshua
 */
#include "Executor.h"

Executor::Executor(std::shared_ptr<Environment> environ) : environ(environ), systems(environ->getSystems()) {

}

Executor::~Executor() {

}
