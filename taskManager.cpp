#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
	string description;
	bool isCompleated;
	Task(const string& desc) :
		description(desc), isCompleated(false){}
};
class TaskManager {
private:
	vector<Task> tasks;
public:
	void addTask(const string& descriptoion) {
		tasks.emplace_back(descriptoion);
		cout << "Task added " << descriptoion << endl;
	}

	void compleateTask(int index) {
		if (index >= 0 && index < tasks.size())
		{
			tasks[index].isCompleated = true;
			cout << "Task compleated: " << tasks[index].description << endl;
		}
	}

	void removeTasks(int index) {
		if (index >= 0 && index < tasks.size()) {
			cout << "Task removed: " << tasks[index].description << endl;
			tasks.erase(tasks.begin() + index);
		}
		else {
			cerr << "Invalid task index. " << endl;
		}
	}

	void listTasks() const {
		cout << "Tasks list: " << endl;
		for (size_t i = 0; i < tasks.size(); i++)
		{
			cout << i + 1 << ". " << tasks[i].description << (tasks[i].isCompleated? "[Compleated]" : "[Not compleated]") << endl;
		}
	}
};

int main()
{
	TaskManager taskManager;
	int choise;
	string description;
	int taskIndex;

	do {
		cout << "\nTask Manager\n";
		cout << "1. Add task.\n";
		cout << "2. Complete Task\n";
		cout << "3. Remove Task\n";
		cout << "4. List Tasks\n";
		cout << "5. Exit\n";
		cout << "Enter Choice: ";
		cin >> choise;

		switch (choise) {
		case 1:
			cout << "Enter task description: ";
			cin.ignore();
			getline(cin, description);

			taskManager.addTask(description);
			break;
		case 2:
			cout << "Enter task number to compleate: ";
			cin >> taskIndex;
			taskManager.compleateTask(taskIndex - 1);
			break;
		case 3:
			cout << "Enter task number to remove: ";
			cin >> taskIndex;
			taskManager.removeTasks(taskIndex - 1);
			break;
		case 4:
			taskManager.listTasks();
			break;
		case 5:
			cout << "Exiting..." << endl;
			break;
		default:
			cerr << "Invalid choise. Please try again!!!" << endl;
			break;
		}
	} while (choise != 5);

	return 0;
}
