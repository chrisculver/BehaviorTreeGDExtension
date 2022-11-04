extends BehaviorTree



# Called every frame. 'delta' is the elapsed time since the previous frame.
func _physics_process(delta):
	get_child(0).tick()
