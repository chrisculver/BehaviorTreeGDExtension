#include "behavior_tree.h"


#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void BehaviorTree::_bind_methods()
{

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