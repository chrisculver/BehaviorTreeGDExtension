#include "leaf.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>


using namespace godot;


void Leaf::_bind_methods()
{
    ClassDB::bind_method("update", &Leaf::update);
    
    ClassDB::bind_method("set_blackboard", &Leaf::set_blackboard);
    ClassDB::bind_method("get_blackboard", &Leaf::get_blackboard);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "blackboard"), "set_blackboard", "get_blackboard");
}



Task::Status Leaf::update()
{
    UtilityFunctions::print("Using default leaf update");
    return Task::Status::INVALID;
}

void Leaf::set_blackboard(const Ref<BlackBoard> &new_blackboard)
{
    blackboard=new_blackboard;
}

Ref<BlackBoard> Leaf::get_blackboard()
{
    return blackboard;
}