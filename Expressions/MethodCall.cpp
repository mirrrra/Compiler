#include "MethodCall.h"

void MethodCall::Accept(Visitor* visitor) {
    visitor->Visit(this);
}