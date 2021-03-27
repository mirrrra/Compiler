#pragma once
#include "Type.h"
#include "../driver.h"
#include <string>

class IdType: public Type{
public:
    IdType(Driver* driver, const std::string& id): driver_(driver), id_(id) {}
    virtual void Accept(Visitor* visitor) override;
    Driver* driver_;
    std::string id_;
};