extends BehaviorTree

func _ready():
	blackboard.set_data("answer", 42)

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _physics_process(delta):
	var root_status = get_child(0).tick()

	if root_status == Task.SUCCESS:
		get_child(0).reset()

