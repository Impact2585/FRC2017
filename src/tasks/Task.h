#ifndef SRC_TASKS_TASK_H_
#define SRC_TASKS_TASK_H_

class Task {
public:
	Task();
	virtual ~Task();
	virtual void onStart() = 0;
	void run();
	virtual void execute() = 0;
	virtual void onEnd() = 0;
	bool isDone();

protected:
	virtual bool checkIfFinished() = 0;

private:
	bool done;
};

#endif
