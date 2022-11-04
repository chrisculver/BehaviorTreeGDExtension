#ifndef COMPOSITES_H
#define COMPOSITES_H

#include "task.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/binder_common.hpp>

using namespace godot;

class Selector : public Task 
{
    GDCLASS(Selector, Task);

protected:
    static void _bind_methods();

public:
    Status update() override;
    void reset() override;

private:
    int curChild=0;
};


class Sequence : public Task
{
    GDCLASS(Sequence, Task);

protected:
    static void _bind_methods();

public:
    Status update() override;
    // TODO: Should make Composites class which defines reset
    void reset() override;

private:
    int curChild=0;
};



#endif