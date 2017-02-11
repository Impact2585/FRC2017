#ifndef SRC_COMMANDS_COMMAND_H_
#define SRC_COMMANDS_COMMAND_H_

class Command {
public:
	Command();
	virtual ~Command();
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
