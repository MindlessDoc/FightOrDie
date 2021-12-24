#include "game.h"
#include "Src/Loggers/ConsolLogger/consollogger.h"
#include "Src/Loggers/FileLogger/filelogger.h"
#include "TemplateMediator.h"
#include "Src/Fields/field.h"

#include "Src/Rules/LoggerRule/loggerrule.h"

#include "Src/Rules/EnemySpawnRule/enemyspawnrule.h"
#include "Src/ChooseCell/QtRandomChooseCell/qtrandomchoosecell.h"

#include "Src/Entities/Characters/Enemies/virus.h"
#include "Src/Entities/Characters/Enemies/trojan.h"
#include "Src/Entities/Characters/Enemies/immortal.h"

#include "Src/Controller/QtController/qtcontroller.h"
#include "Src/Memento/caretaker.h"

#include "Src/Factory/DeserializableField/deserializablefield.h"

#include "Src/Factory/DeserializableCell/deserializableentrance.h"
#include "Src/Factory/DeserializableCell/deserializableexit.h"
#include "Src/Factory/DeserializableCell/deserializableway.h"

#include "Src/Factory/DeserializableCharacters/deserializableimmortal.h"
#include "Src/Factory/DeserializableCharacters/deserializableplayer.h"
#include "Src/Factory/DeserializableCharacters/deserializabletrojan.h"
#include "Src/Factory/DeserializableCharacters/deserializablevirus.h"

#include "Src/Factory/DeserializableItems/deserializablearmor.h"
#include "Src/Factory/DeserializableItems/deserializableattack.h"
#include "Src/Factory/DeserializableItems/deserializablehealth.h"

Game::Game(int heightOfCell, int widthOfCell, int heightInCells, int widthInCells)
{

    _mediator = new TemplateMediator<LoggerRule<false, true>,
            EnemySpawnRule<QtRandomChooseCell, Virus, 2, Trojan, 1, Immortal, 1,
            LoggerRule<true, true>>>();

    _field = new Field(heightInCells, widthInCells);


    _player = new Player(100, 100, 100, _mediator);


    _field->InitField(_player, _mediator);
    _mediator->DoSpawnEnemy(_field);

    _graphicField = new GraphicField(_field, heightOfCell, widthOfCell);

    _mainWindow = new MainWindow(heightOfCell, widthOfCell, heightInCells, widthInCells, _graphicField, _player, _mediator);

    _controller = new QtController(_mediator);

    _mediator->InitMediator(_graphicField, _player, _mainWindow, _controller);
    _mediator->InitCaretaker(new Caretaker(this, "C:/QtProjects/OOP/FightOrDie"));

    _mediator->notifyCaretakerSave();
    std::map<std::string, DeserializableFactory*> creator =
                                                 {{typeid (ArmorItem).name(), new DeserializableArmor()},
                                                 {typeid (AttackItem).name(), new DeserializableAttack()},
                                                 {typeid (HealthItem).name(), new DeserializableHealth()},

                                                 {typeid (Field).name(), new DeserializableField()},

                                                 {typeid (Entrance).name(), new DeserializableEntrance()},
                                                 {typeid (Exit).name(), new DeserializableExit()},
                                                 {typeid (Way).name(), new DeserializableWay()},

                                                 {typeid (Player).name(), new DeserializablePlayer()},
                                                 {typeid (Immortal).name(), new DeserializableImmortal()},
                                                 {typeid (Trojan).name(), new DeserializableTrojan()},
                                                 {typeid (Virus).name(), new DeserializableVirus()}};
    SetCreator(&creator);
    _mediator->notifyCaretakerDownload();

    //_gameObjects = new GameObjects(_field, _player);
}

Game::~Game()
{
    delete _mainWindow;
    //delete _player; //DANGLING POINTER - FIX!!!
    delete _graphicField;
    delete _controller;
}

void Game::Start()
{
    _mainWindow->show();
}

void Game::Save(std::ofstream& out)
{
    _field->Serialize(out);
}


void Game::Download(Memento *memento)
{
    _gameObjects = memento->GetGameObjects();
    delete _field;
    _field = _gameObjects->GetField();
    delete _player;
    _player = _field->GetPlayer();
    _field->InitMediator(_mediator);
    int height = _graphicField->GetHeightOfCell();
    int width = _graphicField->GetWidthOfCell();
    delete _graphicField;
    _graphicField = new GraphicField(_field, height, width);
    delete _mainWindow;
    _mainWindow = new MainWindow(height, width, _field->GetHeightInCells(), _field->GetWidthInCells(), _graphicField, _player, _mediator);
    _mediator->InitMediator(_graphicField, _player, _mainWindow, _controller);
    Start();
}

Mediator* Game::GetMediator() { return _mediator; }
