//
// Created by cullycross on 11/26/15.
// Follow me (@tonyshkurenko)
//

#include "RuntimeException.h"

RuntimeException::RuntimeException(char *message) {
    message_ = message;
}

const char *RuntimeException::what() const noexcept {
    return message_;
}
