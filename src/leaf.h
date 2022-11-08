#ifndef LEAF_H
#define LEAF_H

#include "task.h"
#include "blackboard.h"

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/binder_common.hpp>

using namespace godot;

// TODO: Probably the blackboard of a leaf should match the blackboard
// of the whole behavior tree, so allowing the set here is dangerous, at
// least making it public

class Leaf : public Task 
{
    GDCLASS(Leaf, Task);

protected:
    static void _bind_methods();

public:
    virtual Status update();

    Ref<BlackBoard> blackboard;
    Ref<BlackBoard> get_blackboard();
    void set_blackboard(const Ref<BlackBoard> &new_blackboard);
};

#endif