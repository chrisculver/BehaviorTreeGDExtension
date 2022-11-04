#ifndef COMPOSITES_H
#define COMPOSITES_H

#include "task.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/binder_common.hpp>

using namespace godot;

class Composite : public Task 
{
    GDCLASS(Composite, Task);

protected:
    static void _bind_methods();
    int curChild=0;
    
public:
    void reset() override;

};

class Selector : public Composite 
{
    GDCLASS(Selector, Composite);

protected:
    static void _bind_methods();

public:
    Status update() override;
};


class Sequence : public Composite
{
    GDCLASS(Sequence, Composite);

protected:
    static void _bind_methods();

public:
    Status update() override;
};



#endif