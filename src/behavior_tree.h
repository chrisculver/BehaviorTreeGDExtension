#ifndef BEHAVIOR_TREE_H
#define BEHAVIOR_TREE_H

#include "task.h"

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

class BehaviorTree : public Task
{
    GDCLASS(BehaviorTree, Task);

protected:
    static void _bind_methods();

public:
    BehaviorTree();
    ~BehaviorTree();

    void _ready() override;
    // see.cpp for comments on getting rid of this
    //void _physics_process(double delta) override;
};

#endif