#include "composites.h"

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void Composite::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("reset"), &Composite::reset);
}

void Composite::reset()
{
    curChild=0;
    Task::reset();
}





void Selector::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("update"), &Selector::update);
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
    ClassDB::bind_method(D_METHOD("update"), &Sequence::update);
}

Task::Status Sequence::update()
{
    UtilityFunctions::print("Sequence update from node=", get_name());
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
