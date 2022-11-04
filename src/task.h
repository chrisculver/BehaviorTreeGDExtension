#ifndef TASK_H
#define TASK_H

#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/binder_common.hpp>

using namespace godot;



class Task : public Node 
{
    GDCLASS(Task, Node);

protected:
    static void _bind_methods();


public:
    enum Status {FAILURE, SUCCESS, RUNNING, INVALID=-1};

    // Virtual methods - can be overwritten by derived classes
    virtual Status update();

    virtual void initialize();
    virtual void terminate(Status s);
    virtual void reset();

    // Final methods
    Status tick(); 

    bool isRunning() const;
    bool isSuccess() const;
    bool isFailure() const;
    bool isTerminated() const;

    // Property
    Status status;
    Status get_status();
    void set_status(const Status new_status);

    // Construct/Destruct
    Task();
    ~Task();
};


VARIANT_ENUM_CAST(Task,Status);

#endif