#include "composites.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;


void Selector::_bind_methods()
{
    ClassDB::bind_method("update", &Selector::update);
}


Task::Status Selector::update() 
{
    while(curChild<get_child_count())
    {
        auto status = (Object::cast_to<Task>(get_child(curChild)))->tick();
        if(status!=Task::Status::FAILURE)
        {
            return status;
        }
        curChild++;
    }

    return Task::Status::FAILURE;
}



void Sequence::_bind_methods()
{
    ClassDB::bind_method("update", &Sequence::update);
}

Task::Status Sequence::update()
{
    UtilityFunctions::print("Sequence pdate from ", get_name());
    while(curChild<get_child_count())
    {
        auto status = (Object::cast_to<Task>(get_child(curChild)))->tick();

        if(status!=Status::SUCCESS)
        {
            return status;
        }

        curChild++;
    }

    return Task::Status::SUCCESS;
}