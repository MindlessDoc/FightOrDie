#pragma once

#include "Src/Rules/rule.h"
#include "Src/Loggers/logger.h"

class Mediator;
class Field;

template<class ChooseCellClass, class EnemyFirst, int countFirst,
         class EnemySecond, int countSecond,
         class EnemyThird, int countThird, class LogRule>
class EnemySpawnRule : public Rule
{
public:
    EnemySpawnRule() = default;

    virtual void Spawn(Field* field, Mediator* mediator)
    {
        for(int i = 0; i < countFirst; i++)
            _logRule.AddInLogger(new EnemyFirst(field, _chooseCellClass.GetCell(field), mediator));
        for(int i = 0; i < countSecond; i++)
            _logRule.AddInLogger(new EnemySecond(field, _chooseCellClass.GetCell(field), mediator));
        for(int i = 0; i < countThird; i++)
            _logRule.AddInLogger(new EnemyThird(field, _chooseCellClass.GetCell(field), mediator));
    }
private:
    ChooseCellClass _chooseCellClass;
    LogRule _logRule;
};
