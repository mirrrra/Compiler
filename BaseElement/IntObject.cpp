#include "IntObject.h"

bool IntObject::ToBool() const {
    return value_ != 0;
}

int IntObject::ToInt() const {
    return value_;
}