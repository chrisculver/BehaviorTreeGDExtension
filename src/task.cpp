#include "task.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>


using namespace godot;


void Task::_bind_methods()
{
    // Abstract Methods
    //ClassDB::bind_method("update", &Task::update);
    BIND_VIRTUAL_METHOD(&Task, &Task::update);
    ClassDB::bind_method("initialize", &Task::initialize);
    ClassDB::bind_method("terminate", &Task::terminate);



    // Final Methods
    ClassDB::bind_method("tick", &Task::tick);
    ClassDB::bind_method("isRunning", &Task::isRunning);
    ClassDB::bind_method("isSuccess", &Task::isSuccess);
    ClassDB::bind_method("isFailure", &Task::isFailure);
    ClassDB::bind_method("isTerminated", &Task::isTerminated);

    // Properties
    ClassDB::bind_method("set_status", &Task::set_status);
    ClassDB::bind_method(D_METHOD("get_status"), &Task::get_status);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "status"), "set_status", "get_status");
}


Task::Task(){}
Task::~Task(){}


// Virtual Methods
Task::Status Task::update()
{
    UtilityFunctions::print("Default update running in ", get_name());
    return Task::Status::INVALID;
}

void Task::initialize() {}
void Task::terminate(Status s) {}


// Methods
Task::Status Task::tick()
{
    if(status != Task::Status::RUNNING)
    {
        initialize();
    }

    status = update();

    if(status != Task::Status::RUNNING)
    {
        terminate(status);
    }

    return status;
}

bool Task::isSuccess() const
{
    return status==Task::Status::SUCCESS;
}

bool Task::isFailure() const
{
    return status==Task::Status::FAILURE;
}

bool Task::isRunning() const
{
    return status==Task::Status::RUNNING;
}

bool Task::isTerminated() const
{
    return status==Task::Status::FAILURE;
}

void Task::reset()
{
    status = Task::Status::INVALID;
}


//Properties
void Task::set_status(const Task::Status new_status)
{
    status=new_status;
}

Task::Status Task::get_status()
{
    return status;
}