#include "blackboard.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void BlackBoard::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("has_data"), &BlackBoard::has_data);
    ClassDB::bind_method(D_METHOD("set_data"), &BlackBoard::set_data);
    ClassDB::bind_method(D_METHOD("get_data"), &BlackBoard::get_data);
}


bool BlackBoard::has_data(String name)
{
    return data.has(name);
}


Variant BlackBoard::get_data(String name)
{
    return data[name];
}


void BlackBoard::set_data(String name, Variant value)
{
    data[name]=value;
}