#include "behavior_tree.h"


#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void BehaviorTree::_bind_methods()
{
    ClassDB::bind_method("set_blackboard", &BehaviorTree::set_blackboard);
    ClassDB::bind_method("get_blackboard", &BehaviorTree::get_blackboard);
    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "blackboard"), "set_blackboard", "get_blackboard");
}

BehaviorTree::BehaviorTree(){}
BehaviorTree::~BehaviorTree(){}

void BehaviorTree::_ready()
{
    if(get_child_count()>1)
    {
        UtilityFunctions::print("Behavior tree has more then one child!");
    }
    else if(get_child_count()==0)
    {
        UtilityFunctions::print("Behavior tree doesn't have a child!");
    }
}

/*
// this makes my node run in the editor...
// for now will just launch tree from gd script
void BehaviorTree::_physics_process(double _delta)
{
    //UtilityFunctions::print("num children = ", get_child(0)->get_child_count());
    //Node *n = Object::cast_to<Node>(get_child(0));
    //UtilityFunctions::print("num children = ", n->get_child_count());
    //(Object::cast_to<Node3D>(get_child(0)))->get_position();

    //UtilityFunctions::print("child is ",(Object::cast_to<Task>(get_child(0)))); 
    (Object::cast_to<Task>(get_child(0)))->tick();
}
*/

void BehaviorTree::set_blackboard(const Ref<BlackBoard> &new_blackboard)
{
    // TODO should probably set the BB of all children.
    blackboard=new_blackboard;
}

Ref<BlackBoard> BehaviorTree::get_blackboard()
{
    return blackboard;
}