#ifndef DECORATOR_H
#define DECORATOR_H

#include "task.h"

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/binder_common.hpp>

using namespace godot;

class Decorator : public Task 
{
    GDCLASS(Decorator, Task);
};


class AlwaysSuccess : public Decorator 
{
    GDCLASS(AlwaysSuccess, Decorator);

protected:
    static void _bind_methods();

public:
    Task::Status update() override;
};

class AlwaysFailure : public Decorator 
{
    GDCLASS(AlwaysFailure, Decorator);

protected:
    static void _bind_methods();

public:
    Task::Status update() override;
};


#endif