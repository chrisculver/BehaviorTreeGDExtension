#ifndef BLACKBOARD_H
#define BLACKBOARD_H

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/binder_common.hpp>

using namespace godot;

class BlackBoard : public Resource
{
    GDCLASS(BlackBoard,Resource);

protected:
    static void _bind_methods();

public: 
    Dictionary data;

    bool has_data(String name);
    Variant get_data(String name);
    void set_data(String name, Variant value);
};

#endif