#include "register_types.h"

#include "task.h"
#include "behavior_tree.h"
#include "blackboard.h"
#include "leaf.h"
#include "composites.h"
#include "decorators.h"

#include <godot/gdnative_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/godot.hpp>

using namespace godot;

void initialize_bt_types(ModuleInitializationLevel p_level)
{
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
	{
		// Base BT Node
        ClassDB::register_class<Task>();
		
		// BT & BB & Leaf
		ClassDB::register_class<BehaviorTree>();
		ClassDB::register_class<BlackBoard>();
		ClassDB::register_class<Leaf>();

		// Composites
		ClassDB::register_class<Composite>();
		ClassDB::register_class<Selector>();
		ClassDB::register_class<Sequence>();

		// Decorators
		ClassDB::register_class<Decorator>();
		ClassDB::register_class<AlwaysSuccess>();
		ClassDB::register_class<AlwaysFailure>();


	}
}

void uninitialize_bt_types(ModuleInitializationLevel p_level) {
	if (p_level == MODULE_INITIALIZATION_LEVEL_SCENE)
	{

	}
}



extern "C"
{
	// Initialization.
	GDNativeBool GDN_EXPORT behavior_tree_init(const GDNativeInterface *p_interface, const GDNativeExtensionClassLibraryPtr p_library, GDNativeInitialization *r_initialization)
	{
		GDExtensionBinding::InitObject init_obj(p_interface, p_library, r_initialization);

		init_obj.register_initializer(initialize_bt_types);
		init_obj.register_terminator(uninitialize_bt_types);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}
