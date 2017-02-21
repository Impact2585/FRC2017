#include "EndSignal.h"

EndSignal::EndSignal() : ended(false) {

}

EndSignal::~EndSignal() {

}

bool EndSignal::hasEnded() {
    return ended;
}

void EndSignal::setEnded(bool ended) {
    this->ended = ended;
}
