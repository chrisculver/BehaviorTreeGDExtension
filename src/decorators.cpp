#include "decorators.h"

#include "task.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void AlwaysSuccess::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("update"), &AlwaysSuccess::update);
}

Task::Status AlwaysSuccess::update()
{ 
    (Object::cast_to<Task>(get_child(0)))->call("update");
    return Task::Status::SUCCESS;
}


void AlwaysFailure::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("update"), &AlwaysFailure::update);
}

Task::Status AlwaysFailure::update()
{ 
    (Object::cast_to<Task>(get_child(0)))->call("update");
    return Task::Status::FAILURE;
}