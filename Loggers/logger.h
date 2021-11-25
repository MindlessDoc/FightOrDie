#pragma once

class Loggable;

class Logger
{
public: 
    virtual void AddInLogger(Loggable* loggable);
    virtual void Update(Loggable* loggable) = 0;
};

