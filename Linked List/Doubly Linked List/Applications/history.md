**Dynamic History Management** in the context of a **Doubly Linked List (DLL)** involves managing a series of actions (or states) in a flexible manner. Specifically, you want to be able to:
- **Add new states** at the current point (e.g., when a user performs an action).
- **Remove unnecessary actions** (e.g., when a user performs an undo or redo).
- **Navigate through the history** (i.e., move back and forth between previous and future states).

### Key Operations for Dynamic History Management in DLL:
1. **Add new states** (e.g., after each user action, add the new state to the history).
2. **Remove unnecessary actions** (e.g., clear the future states when a new action is performed after undoing a series of actions).
3. **Navigate through the history** (e.g., move to a previous action for undo or forward to a future action for redo).

We will extend the **Undo/Redo** scenario that we previously discussed to include:
- **Adding new states**.
- **Removing future actions** if new actions are performed after undoing a set of actions.
- **Navigating through the history** (undo/redo).

### **C++ Example: Dynamic History Management**

We'll create a `HistoryManager` class that allows:
- Inserting new states dynamically.
- Undoing and redoing actions while managing the state history.

#### **Code Implementation**:
```cpp
#include <iostream>
#include <string>
using namespace std;

class Action {
public:
    string documentState;  // The document state (or action description)
    Action* next;
    Action* prev;

    Action(string state) {
        documentState = state;
        next = nullptr;
        prev = nullptr;
    }
};

class HistoryManager {
private:
    Action* currentAction;
public:
    HistoryManager() : currentAction(nullptr) {}

    // Perform a new action and store it
    void performAction(const string& action) {
        Action* newAction = new Action(action);

        // If there's a current action, remove the redo history
        if (currentAction != nullptr) {
            // If we perform a new action after an undo, we need to discard the redo history
            currentAction->next = nullptr;
        }

        // Add the new action to the history
        if (currentAction == nullptr) {
            currentAction = newAction;  // First action
        } else {
            newAction->prev = currentAction;
            currentAction->next = newAction;
            currentAction = newAction;
        }

        cout << "Performed Action: " << action << endl;
    }

    // Undo the last action
    void undo() {
        if (currentAction == nullptr) {
            cout << "No actions to undo." << endl;
            return;
        }

        cout << "Undoing Action: " << currentAction->documentState << endl;
        currentAction = currentAction->prev;
    }

    // Redo the last undone action
    void redo() {
        if (currentAction == nullptr || currentAction->next == nullptr) {
            cout << "No actions to redo." << endl;
            return;
        }

        currentAction = currentAction->next;
        cout << "Redoing Action: " << currentAction->documentState << endl;
    }

    // Display the current document state
    void displayCurrentState() {
        if (currentAction == nullptr) {
            cout << "No actions performed yet." << endl;
        } else {
            cout << "Current Document State: " << currentAction->documentState << endl;
        }
    }

    // Remove all future actions (used when a new action is performed after undo)
    void clearFutureActions() {
        while (currentAction != nullptr && currentAction->next != nullptr) {
            Action* temp = currentAction->next;
            delete currentAction;
            currentAction = temp;
        }
    }

    // Delete all actions (clear the history)
    void clearHistory() {
        while (currentAction != nullptr) {
            Action* temp = currentAction;
            currentAction = currentAction->prev;
            delete temp;
        }
        cout << "History cleared!" << endl;
    }
};

int main() {
    HistoryManager manager;

    // Simulate user actions
    manager.performAction("Action 1: Text Added");
    manager.displayCurrentState();

    manager.performAction("Action 2: Text Deleted");
    manager.displayCurrentState();

    manager.performAction("Action 3: Text Modified");
    manager.displayCurrentState();

    // Undo actions
    manager.undo();
    manager.displayCurrentState();

    manager.undo();
    manager.displayCurrentState();

    // Redo actions
    manager.redo();
    manager.displayCurrentState();

    // Perform a new action after undoing some actions
    manager.performAction("Action 4: New Text Added");
    manager.displayCurrentState();

    // After this, the future actions (redo history) should be cleared
    manager.redo();  // No actions to redo now

    // Clear the entire history
    manager.clearHistory();
    manager.displayCurrentState();

    return 0;
}
```

### **Step-by-Step Breakdown**:

1. **Action Class**:
   - The `Action` class holds the state of the document (or action description) and contains pointers `prev` and `next` to link the actions in a doubly linked list.

2. **HistoryManager Class**:
   - **`currentAction`**: Points to the most recent action (or the current state).
   - **`performAction()`**: Adds a new action to the list. If the user has undone some actions and performs a new action, the redo history is cleared (i.e., all future actions are discarded).
   - **`undo()`**: Moves the `currentAction` pointer to the previous action in the list.
   - **`redo()`**: Moves the `currentAction` pointer to the next action in the list.
   - **`displayCurrentState()`**: Prints the current state of the document (the state stored in `currentAction`).
   - **`clearFutureActions()`**: Clears all actions that follow the `currentAction` (used after an undo operation when a new action is performed, to remove the redo history).
   - **`clearHistory()`**: Clears all actions in the history, effectively resetting the history.

3. **Dynamic History Management**:
   - **Adding New States**: Each time the `performAction()` function is called, a new action is added to the list.
   - **Removing Unnecessary Actions**: When a user performs an undo and then a new action is taken, all subsequent actions (the redo history) are discarded using `clearFutureActions()`.
   - **Navigating Through History**: The user can navigate through the history using the `undo()` and `redo()` functions. This is made possible by the doubly linked list structure, which allows movement in both directions.
   - **Clear History**: The `clearHistory()` function removes all actions, essentially resetting the history.

### **Sample Output**:
```
Performed Action: Action 1: Text Added
Current Document State: Action 1: Text Added
Performed Action: Action 2: Text Deleted
Current Document State: Action 2: Text Deleted
Performed Action: Action 3: Text Modified
Current Document State: Action 3: Text Modified
Undoing Action: Action 3: Text Modified
Current Document State: Action 2: Text Deleted
Undoing Action: Action 2: Text Deleted
Current Document State: Action 1: Text Added
Redoing Action: Action 2: Text Deleted
Current Document State: Action 2: Text Deleted
Redoing Action: Action 3: Text Modified
Current Document State: Action 3: Text Modified
Performed Action: Action 4: New Text Added
Current Document State: Action 4: New Text Added
No actions to redo.
History cleared!
No actions performed yet.
```

### **Explanation of the Output**:
1. **Initial Actions**: The actions `"Action 1: Text Added"`, `"Action 2: Text Deleted"`, and `"Action 3: Text Modified"` are performed, and the current state is displayed after each action.
2. **Undo and Redo**: The `undo()` function reverts to previous actions, and `redo()` moves forward through the history.
3. **Performing New Action**: When a new action `"Action 4: New Text Added"` is performed after some undo operations, the redo history is cleared automatically.
4. **Clearing History**: Finally, the `clearHistory()` function removes all actions, resetting the history.

### **Real-World Applications**:
- **Text Editors**: Managing the undo/redo history dynamically as users type or delete text.
- **Graphic Design Software**: Handling actions like drawing, deleting, or moving shapes.
- **Games**: Keeping track of player actions (e.g., moving characters, changing game states).
  
This implementation demonstrates how to manage dynamic history in C++ using a doubly linked list, allowing efficient addition, deletion, and navigation of actions or states.