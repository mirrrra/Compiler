#pragma once
#include "Type.h"
#include "../driver.h"
#include <string>

class IdType: public Type{
public:
    IdType(const std::string& id): id_(id) {}
    virtual void Accept(Visitor* visitor) override;

    std::string id_;
};