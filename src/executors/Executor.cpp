/*
 * Executor.cpp
 */
#include "Executor.h"

Executor::Executor(std::shared_ptr<Environment> environ) : environ(environ), systems(environ->getSystems()) {

}

Executor::~Executor() {

}
