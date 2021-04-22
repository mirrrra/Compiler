#pragma once
#include "BaseElement.h"
#include "../Declarations/Type.h"
#include <memory>

class Object: std::enable_shared_from_this<Object> {
public:
    virtual int ToInt() const;
    virtual bool ToBool() const;

    virtual bool IsMain() const;
    virtual bool IsArray() const;
    virtual bool IsClass() const;
    virtual bool IsFunction() const;

    virtual ~Object() = default;

protected:
};