QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Src/Application/game.cpp \
    Src/Application/gameobjects.cpp \
    Src/Application/main.cpp \
    Src/Application/mainwindow.cpp \
    Src/Application/mediator.cpp \
    Src/Avatar/avatar.cpp \
    Src/Cells/CellFactory/QtCellFactory/qtentrancecellfactory.cpp \
    Src/Cells/CellFactory/QtCellFactory/qtexitcellfactory.cpp \
    Src/Cells/CellFactory/QtCellFactory/qtwaycellfactory.cpp \
    Src/Cells/CellFactory/cellfactory.cpp \
    Src/Cells/cell.cpp \
    Src/Cells/entrance.cpp \
    Src/Cells/exit.cpp \
    Src/Cells/graphiccell.cpp \
    Src/Cells/way.cpp \
    Src/ChooseCell/QtRandomChooseCell/qtrandomchoosecell.cpp \
    Src/ChooseCell/choosecell.cpp \
    Src/Controller/QtController/qtcontroller.cpp \
    Src/Entities/Characters/Enemies/EnemyMoveContoller/enemymovecontroller.cpp \
    Src/Entities/Characters/Enemies/EnemyMoveContoller/qtenemymovecontroller.cpp \
    Src/Entities/Characters/Enemies/enemy.cpp \
    Src/Entities/Characters/Enemies/immortal.cpp \
    Src/Entities/Characters/Enemies/trojan.cpp \
    Src/Entities/Characters/Enemies/virus.cpp \
    Src/Entities/Characters/Player/player.cpp \
    Src/Entities/Characters/icharacter.cpp \
    Src/Entities/EntityFactory/entityfactory.cpp \
    Src/Entities/Items/HealthItem/healthitem.cpp \
    Src/Entities/Items/ArmorItem/armoritem.cpp \
    Src/Entities/Items/AttackItem/attackitem.cpp \
    Src/Entities/Items/item.cpp \
    Src/Entities/graphicentity.cpp \
    Src/Entities/ientity.cpp \
    Src/Factory/SerializableCharacters/serializableimmortal.cpp \
    Src/Factory/SerializableCharacters/serializableplayer.cpp \
    Src/Factory/SerializableCharacters/serializabletrojan.cpp \
    Src/Factory/SerializableCharacters/serializablevirus.cpp \
    Src/Factory/SerializableItems/serializablearmor.cpp \
    Src/Factory/SerializableItems/serializableattack.cpp \
    Src/Factory/SerializableItems/serializablehealth.cpp \
    Src/Factory/serializablefactory.cpp \
    Src/Fields/field.cpp \
    Src/Fields/graphicfield.cpp \
    Src/Loggable/loggable.cpp \
    Src/Loggers/ConsolLogger/consollogger.cpp \
    Src/Loggers/FileLogger/filelogger.cpp \
    Src/Loggers/logger.cpp \
    Src/Memento/caretaker.cpp \
    Src/Memento/memento.cpp \
    Src/Memento/originator.cpp \
    Src/Rules/EnemySpawnRule/enemyspawnrule.cpp \
    Src/Rules/LoggerRule/loggerrule.cpp \
    Src/Rules/rule.cpp \
    Src/Controller/controller.cpp \
    Src/Serializable/serializable.cpp


HEADERS += \
    Src/Application/TemplateMediator.h \
    Src/Application/game.h \
    Src/Application/gameobjects.h \
    Src/Application/mainwindow.h \
    Src/Application/mediator.h \
    Src/Avatar/avatar.h \
    Src/Cells/CellFactory/QtCellFactory/qtentrancecellfactory.h \
    Src/Cells/CellFactory/QtCellFactory/qtexitcellfactory.h \
    Src/Cells/CellFactory/QtCellFactory/qtwaycellfactory.h \
    Src/Cells/CellFactory/cellfactory.h \
    Src/Cells/cell.h \
    Src/Cells/entrance.h \
    Src/Cells/exit.h \
    Src/Cells/graphiccell.h \
    Src/Cells/way.h \
    Src/ChooseCell/QtRandomChooseCell/qtrandomchoosecell.h \
    Src/ChooseCell/choosecell.h \
    Src/Controller/QtController/qtcontroller.h \
    Src/Entities/Characters/Enemies/EnemyMoveContoller/enemymovecontroller.h \
    Src/Entities/Characters/Enemies/EnemyMoveContoller/qtenemymovecontroller.h \
    Src/Entities/Characters/Enemies/enemy.h \
    Src/Entities/Characters/Enemies/immortal.h \
    Src/Entities/Characters/Enemies/trojan.h \
    Src/Entities/Characters/Enemies/virus.h \
    Src/Entities/Characters/Player/player.h \
    Src/Entities/Characters/icharacter.h \
    Src/Entities/EntityFactory/entityfactory.h \
    Src/Entities/Items/HealthItem/healthitem.h \
    Src/Entities/Items/ArmorItem/armoritem.h \
    Src/Entities/Items/AttackItem/attackitem.h \
    Src/Entities/Items/item.h \
    Src/Entities/graphicentity.h \
    Src/Entities/ientity.h \
    Src/Factory/SerializableCharacters/serializableimmortal.h \
    Src/Factory/SerializableCharacters/serializableplayer.h \
    Src/Factory/SerializableCharacters/serializabletrojan.h \
    Src/Factory/SerializableCharacters/serializablevirus.h \
    Src/Factory/SerializableItems/serializablearmor.h \
    Src/Factory/SerializableItems/serializableattack.h \
    Src/Factory/SerializableItems/serializablehealth.h \
    Src/Factory/serializablefactory.h \
    Src/Fields/field.h \
    Src/Fields/graphicfield.h \
    Src/Containers/vector.h \
    Src/Loggable/loggable.h \
    Src/Loggers/ConsolLogger/consollogger.h \
    Src/Loggers/FileLogger/filelogger.h \
    Src/Loggers/logger.h \
    Src/Memento/caretaker.h \
    Src/Memento/memento.h \
    Src/Memento/originator.h \
    Src/Rules/EnemySpawnRule/enemyspawnrule.h \
    Src/Rules/LoggerRule/loggerrule.h \
    Src/Rules/rule.h \
    Src/Controller/controller.h \
    Src/Serializable/serializable.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
