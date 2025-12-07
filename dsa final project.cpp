#include <iostream> // cin and cout
#include <string>  // for strings
#include <stack>   // to make undo
#include <limits>  // for inputs clearing
#include <iomanip>  // for the formula of cout like lift , rigt and setw
using namespace std;


// colors //
#define RESET   "\033[0m"  // return the normal color
#define CYAN    "\033[36m" //  light blue
#define GREEN   "\033[32m" // green 
#define YELLOW  "\033[33m" //yellow
#define RED     "\033[31m" //red
#define BLUE    "\033[34m" // blue
#define MAGENTA "\033[35m" //purple
#define BOLD    "\033[1m"  // bold


// put the text in the center //
void centerText(const string& text , int width = 60){
	int pad = (width - text.size())/2;
	if (pad < 0 )
	pad = 0;
	cout << string(pad , ' ') << text << "\n";
}

// Task Node 
struct Task{
	int id ;
	std::string name ;
	int points ;
	bool completed ;
	Task* prev ;
	Task* next ;
	
	//counstructor 
	Task(int id, string name, int pts)
{
    this->id = id;
    this->name = name;
    this->points = pts;
    this->completed = false;
    this->prev = NULL;
    this->next = NULL;
}

};
// =========== Task List =========

class TaskList{
	private:
		Task* head ;
		Task* tail ;
		int nextId ;
		
	public:
	// Constructor
	TaskList() : head(NULL), tail(NULL), nextId(1) {} 
	
   
   
   // Adds a new task to the end of the list
   // Returns pointer to the new task
   Task* addTask(const std::string&name , int points){
   	Task* node = new Task(nextId++, name , points);
   	if(head== NULL){
   		head = tail = node;
	   }else{
	   	tail->next = node;
	   	node->prev = tail;
	   	tail = node;
	   }
	   return node;
   }
   
   
   // Search task by ID 
   Task* searchById(int id ){
   	Task* current = head ;
   	while (current){
   		if (current->id == id )
   		    return current;
   		current = current->next;
	   }
	   return NULL;
   }
   
   
   
   
   bool deleteTask(int id){
   	Task* current = head ;
   	
   	while(current){
   		if(current->id == id){
   			
   			
   			if(current == head )
   			head = current->next;
   			
   			if(current== tail )
   			tail = current->prev;
   			
   			 if (current->prev)
                current->prev->next = current->next;

            if (current->next)
                current->next->prev = current->prev;

            delete current;
            return true;
		   }
		   current = current->next;
	   }
	   return false;
   }
   
   
    
  void sortById(){
        for(Task* i = head; i; i = i->next)
            for(Task* j = i->next; j; j = j->next)
                if(i->id > j->id){
                    swap(i->id, j->id);
                    swap(i->name, j->name);
                    swap(i->points, j->points);
                    swap(i->completed, j->completed);
                }
    }
    
    void sortByName(){
        for(Task* i = head; i; i = i->next)
            for(Task* j = i->next; j; j = j->next)
                if(i->name > j->name){
                    swap(i->id, j->id);
                    swap(i->name, j->name);
                    swap(i->points, j->points);
                    swap(i->completed, j->completed);
                }
    }
    
    void sortByPoints(){
        for(Task* i = head; i; i = i->next)
            for(Task* j = i->next; j; j = j->next)
                if(i->points > j->points){
                    swap(i->id, j->id);
                    swap(i->name, j->name);
                    swap(i->points, j->points);
                    swap(i->completed, j->completed);
                }
    }
    
    void sortByStatus(){
        for(Task* i = head; i; i = i->next)
            for(Task* j = i->next; j; j = j->next)
                if(i->completed > j->completed){
                    swap(i->id, j->id);
                    swap(i->name, j->name);
                    swap(i->points, j->points);
                    swap(i->completed, j->completed);
                }
    }  
   
   // Destructor
   ~TaskList(){
	Task* current = head ;
	while(current){
		Task* temp = current->next;
		delete current ;
		current = temp;
	}	
   }
   
   // Returns the first incomplete task in the list
   // If all tasks are complete, returns NULL
   Task* nextIncompleteTask(){
   	Task* current = head;
   	while(current){
   		if(!current->completed)
   		    return current;
   		current = current->next;
	   }
	   return NULL;
	   
   }
   
   // Marks a task as completed
    // Returns false if task is NULL or already completed
   bool taskComplete(Task* task){
   	if(!task || task->completed)
   	    return false;
   	    task->completed = true;
   	    return true;
   }
   
   // Reverts a completed task back to incomplete
    // Returns false if task is NULL or already incomplete
   bool taskInComplete(Task* task){
   	 if (!task || !task->completed) 
		return false;
        task->completed = false;
        return true;
   }
   
   
   void display(){
    if(head == NULL){
        cout << RED << "\n No Tasks Available.\n" << RESET;
        return;
    }
    
    
    cout << "+------+---------------------------+--------+------------------+\n"
         << "|  ID  |          NAME             | POINTS |      STATUS      |\n"
         << "+------+---------------------------+--------+------------------+\n";
    
    Task* current = head;
    while(current != NULL){
        
        cout << "| " << setw(4) << current->id << " | "; // setw sets the width of the next output field in cout
        
        
        string displayName = current->name; //Copies the task name to a temporary variable
        if(displayName.length() > 25)
            displayName = displayName.substr(0, 22) + "...";
        
        cout << setw(25) << left << displayName << " | "
             << setw(6) << right << current->points << " | ";
        
        
        if(current->completed)
            cout << GREEN << setw(16) << left << "Completed" << RESET;
        else
            cout << YELLOW << setw(16) << left << "Pending" << RESET;
        
        cout << " |\n";
        current = current->next;
    }
}
   
};


class scoreManager{
private :
	int total;
	
public:
	// Constructor
	scoreManager(): total(0){}
	
	// Adds points to total score
	void addPoints(int points){
		
		total += points;	
	}
	
	
	// Subtracts points from total score (never below 0)
	void subtractPoints(int points){
		 
		total-= points;
		if(total < 0)
		total = 0 ;
	}
	
	// Returns current total score
	int getScore() const {
	return total ;
	}
	
		
};


// Clears invalid input from the input buffer
void clearInput(){
	cin.clear(); //clears any error flags in the input stream
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // discards characters from the input buffer.
	
}

int main(){
	TaskList tasks;
	scoreManager score ;
	stack<Task*> undoStack;
	
	
	bool a = true;
	
	
	
	while(a){

        cout << MAGENTA << BOLD;
        centerText("========================================");
        centerText("           TODO  MENU           ");
        centerText("========================================");
        cout << RESET;

        cout << CYAN;
        cout << "1. Add a Task\n";
        cout << "2. Complete Next Task\n";
        cout << "3. Undo Last Completed Task\n";
        cout << "4. View Task List\n";
        cout << "5. View Score\n";
        cout << "6. search task by ID\n";
        cout << "7. Delete Task\n";
        cout << "8. sort the tasks\n";
        cout << "9. Exit\n";
        cout << RESET;

        cout << YELLOW << "\nChoose an option: " << RESET;
        
        int choice ;
        if (!(std::cin >> choice)){
        	cout<< "invalid input";
        	clearInput();
        	continue ;
		}
		clearInput();
		
		switch(choice){
			case 1 : {
				string name;
				int points;
				cout<< BLUE << "Enter task name: " << RESET ;
				getline(cin , name);
				if(name.empty()){
					cout<<RED << " task name can not be empty \n" << RESET;
					break;
				}
				cout<<BLUE <<  " enter points for this task" << RESET ;
				if(!(cin>> points)|| points <0 ){
					cout<< RED << "invalid points " << RESET;
					clearInput();
					break;
				}
				clearInput();
				Task* task = tasks.addTask(name , points);
				cout<< GREEN << "Task addaed (Id : " << task->id  << " ) \n" << RESET ;
				break;
			}
			
			case 2 : {
				Task* next = tasks.nextIncompleteTask();
				if(!next){
					cout<< YELLOW <<  " no pending tasks to complete. \n" << RESET ;
					
				}else {
					tasks.taskComplete(next);
					undoStack.push(next);
					score.addPoints(next->points);
					cout<< GREEN <<  "Completed task ID " << next->id << " (" << next->name << "). +" << next->points << " points.\n" << RESET ;
					
				}
				break;
			}
			
			case 3 : {
				if (undoStack.empty()){
					cout<< YELLOW << " nothing to Undo \n"<< RESET;
				}else {
					Task* last = undoStack.top();
					undoStack.pop();
					if(tasks.taskInComplete(last)){
						score.subtractPoints(last->points);
						cout << RED << "undid task ID " << last->id << " ( " << last->name << " ) " << last->points << "points \n" << RESET;
						
					}else{
						cout<< " task is not marked as completed \n" ;
						
					}
				}
				break;
			}
			
			case 4 : {
				tasks.display();
				break;
			}
			
			case 5 : {
				cout<< BOLD << CYAN << " Total Score : " << score.getScore() << "\n" << RESET ;
				
				break;
			}
			
			
			case 6 : {
				int id ;
				cout << CYAN << "Enter task ID to search: " << RESET ;
				cin >> id ;
				
				Task* task = tasks.searchById(id);
				
				if(task){
			         cout << GREEN << " Task Found!\n" << RESET;
                     cout << YELLOW << "ID: " << RESET << task->id << "\n";
                     cout << YELLOW << "Name: " << RESET << task->name << "\n";
                     cout << YELLOW << "Points: " << RESET << task->points << "\n";
                     cout << YELLOW << "Status: " << RESET 
                          << (task->completed ? GREEN "Completed" RESET : RED "Pending" RESET)
                          << "\n";
                 } 
                else {
                 cout << RED << " Task not found.\n" << RESET;
                }
				
				break;
			}
			  
			  
		   case 7: {
		   	int id ;
		   	cout << CYAN << "Enter task ID to delete: " << RESET;
            cin >> id;
            
            Task* task = tasks.searchById(id);
            if (task) {
              cout << YELLOW << "\nDeleting Task...\n" << RESET;
              cout << YELLOW << "ID: " << RESET << task->id << "\n";
              cout << YELLOW << "Name: " << RESET << task->name << "\n";
       		  cout << YELLOW << "Points: " << RESET << task->points << "\n";
       		  cout << YELLOW << "Status: " << RESET 
              << (task->completed ? GREEN "Completed" RESET : RED "Pending" RESET)
              << "\n\n";
			  
			  if (tasks.deleteTask(id))	{
			  	cout<< GREEN << " Task deleted \n" << RESET ;
			  }else {
			  	cout << RED << "Failed to delete Task \n " << RESET ;
			  }
			}
			break;
		   }
		   
		   
		   
		   case 8: {
            cout << "\033[1;36m================ Sort Tasks ================\033[0m\n";
            cout << "\033[1;33m1. Sort by ID\n";
            cout << "2. Sort by Name\n";
            cout << "3. Sort by Points\n";
            cout << "4. Sort by Status (Pending ? Completed)\n\033[0m";
            cout << "\033[1;36m===========================================\033[0m\n";

            int s;
            cout << "\033[1;32mChoose sorting option: \033[0m";
            cin >> s;

            switch (s) {
                case 1: tasks.sortById();     cout << "\033[1;32mSorted by ID!\n\033[0m"; break;
                case 2: tasks.sortByName();   cout << "\033[1;32mSorted by Name!\n\033[0m"; break;
                case 3: tasks.sortByPoints(); cout << "\033[1;32mSorted by Points!\n\033[0m"; break;
                case 4: tasks.sortByStatus(); cout << "\033[1;32mSorted by Status!\n\033[0m"; break;
                default: cout << "\033[1;31mInvalid choice.\n\033[0m";
            }
            break;
        }
        
        
        
		   case 9 : {
				cout<< MAGENTA  <<" Exiting the prgram . \n" << RESET;
				a = false;
				break;
			}  
			
			
			default :
			cout<< RED <<" invalid Choice .Enter a number between 1 and 6.\n " << RESET ;
		}

	}
	
	return 0;
	
}


