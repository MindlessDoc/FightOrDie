QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Application/game.cpp \
    Application/main.cpp \
    Application/mainwindow.cpp \
    Application/mediator.cpp \
    Avatar/avatar.cpp \
    Cells/CellFactory/QtCellFactory/qtentrancecellfactory.cpp \
    Cells/CellFactory/QtCellFactory/qtexitcellfactory.cpp \
    Cells/CellFactory/QtCellFactory/qtwaycellfactory.cpp \
    Cells/CellFactory/cellfactory.cpp \
    Cells/cell.cpp \
    Cells/entrance.cpp \
    Cells/exit.cpp \
    Cells/graphiccell.cpp \
    Cells/way.cpp \
    ChooseCell/QtRandomChooseCell/qtrandomchoosecell.cpp \
    ChooseCell/choosecell.cpp \
    Controller/QtController/qtcontroller.cpp \
    Entities/Characters/Enemies/EnemyMoveContoller/enemymovecontroller.cpp \
    Entities/Characters/Enemies/EnemyMoveContoller/qtenemymovecontroller.cpp \
    Entities/Characters/Enemies/enemy.cpp \
    Entities/Characters/Enemies/immortal.cpp \
    Entities/Characters/Enemies/trojan.cpp \
    Entities/Characters/Enemies/virus.cpp \
    Entities/Characters/Player/player.cpp \
    Entities/Characters/icharacter.cpp \
    Entities/EntityFactory/entityfactory.cpp \
    Entities/Items/HealthItem/healthitem.cpp \
    Entities/Items/ArmorItem/armoritem.cpp \
    Entities/Items/AttackItem/attackitem.cpp \
    Entities/Items/item.cpp \
    Entities/graphicentity.cpp \
    Entities/ientity.cpp \
    Fields/field.cpp \
    Fields/graphicfield.cpp \
    Loggable/loggable.cpp \
    Loggers/ConsolLogger/consollogger.cpp \
    Loggers/FileLogger/filelogger.cpp \
    Loggers/logger.cpp \
    Rules/EnemySpawnRule/enemyspawnrule.cpp \
    Rules/LoggerRule/loggerrule.cpp \
    Rules/rule.cpp \
    Controller/controller.cpp


HEADERS += \
    Application/TemplateMediator.h \
    Application/game.h \
    Application/mainwindow.h \
    Application/mediator.h \
    Avatar/avatar.h \
    Cells/CellFactory/QtCellFactory/qtentrancecellfactory.h \
    Cells/CellFactory/QtCellFactory/qtexitcellfactory.h \
    Cells/CellFactory/QtCellFactory/qtwaycellfactory.h \
    Cells/CellFactory/cellfactory.h \
    Cells/cell.h \
    Cells/entrance.h \
    Cells/exit.h \
    Cells/graphiccell.h \
    Cells/way.h \
    ChooseCell/QtRandomChooseCell/qtrandomchoosecell.h \
    ChooseCell/choosecell.h \
    Controller/QtController/qtcontroller.h \
    Entities/Characters/Enemies/EnemyMoveContoller/enemymovecontroller.h \
    Entities/Characters/Enemies/EnemyMoveContoller/qtenemymovecontroller.h \
    Entities/Characters/Enemies/enemy.h \
    Entities/Characters/Enemies/immortal.h \
    Entities/Characters/Enemies/trojan.h \
    Entities/Characters/Enemies/virus.h \
    Entities/Characters/Player/player.h \
    Entities/Characters/icharacter.h \
    Entities/EntityFactory/entityfactory.h \
    Entities/Items/HealthItem/healthitem.h \
    Entities/Items/ArmorItem/armoritem.h \
    Entities/Items/AttackItem/attackitem.h \
    Entities/Items/item.h \
    Entities/graphicentity.h \
    Entities/ientity.h \
    Fields/field.h \
    Fields/graphicfield.h \
    Containers/vector.h \
    Loggable/loggable.h \
    Loggers/ConsolLogger/consollogger.h \
    Loggers/FileLogger/filelogger.h \
    Loggers/logger.h \
    Rules/EnemySpawnRule/enemyspawnrule.h \
    Rules/LoggerRule/loggerrule.h \
    Rules/rule.h \
    Controller/controller.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
