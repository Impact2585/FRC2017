#ifndef SRC_TASKS_PARALLELTASK_H_
#define SRC_TASKS_PARALLELTASK_H_

#include "Task.h"
#include <memory>
#include <vector>
#include <initializer_list>

class ParallelTask : public Task{
public:
	ParallelTask(std::initializer_list<Task*> commands);
	virtual ~ParallelTask();
	virtual void onStart();
	virtual void execute();
	virtual void onEnd();
protected:
	virtual bool checkIfFinished();
private:
	//boost::ptr_vector<Task> commands;
	std::vector<std::unique_ptr<Task>> commands;
	
};

#endif

