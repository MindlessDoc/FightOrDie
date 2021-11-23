#pragma once

class IEntity
{
public:
    virtual ~IEntity() = default;


    virtual int Type() = 0;
};
