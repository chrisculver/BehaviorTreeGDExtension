extends Leaf
class_name Task2

func update():
	print("Task 2 custom update")
	print(blackboard.get_data("answer"))
	return Task.SUCCESS
