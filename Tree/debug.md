Debugging a C++ program is a crucial step in identifying and resolving issues in your code. C++ provides various tools and techniques to help with debugging. Here, I will walk you through common debugging techniques, tools, and best practices for debugging C++ code.

### Techniques and Tools for Debugging C++ Code

#### 1. **Using Print Statements**
One of the simplest and most widely used debugging techniques is inserting print statements (e.g., `std::cout`) to print out the values of variables, function calls, or the flow of execution at different points in your code.

**Example:**
```cpp
#include <iostream>

int factorial(int n) {
    std::cout << "Factorial of " << n << " is called\n"; // Debugging print
    if (n <= 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

int main() {
    int num = 5;
    std::cout << "Factorial of " << num << " is: " << factorial(num) << std::endl;
    return 0;
}
```

**Output:**
```
Factorial of 5 is called
Factorial of 4 is called
Factorial of 3 is called
Factorial of 2 is called
Factorial of 1 is called
Factorial of 1 is: 120
```

#### 2. **Using a Debugger (GDB)**
A debugger is a powerful tool that allows you to inspect your program's state, step through code, and identify where things go wrong.

##### **Using GDB (GNU Debugger)**
1. **Compile with Debugging Information**:
   - Use the `-g` flag to compile the code with debugging information. This allows the debugger to work with source code symbols.
   ```bash
   g++ -g -o myprogram myprogram.cpp
   ```

2. **Start the Debugger**:
   - Run GDB by passing the compiled program as an argument.
   ```bash
   gdb ./myprogram
   ```

3. **Set Breakpoints**:
   - Set breakpoints at specific lines or functions to pause execution and inspect the state of the program.
   ```bash
   (gdb) break main   # Set a breakpoint at the start of the main function
   (gdb) break 10     # Set a breakpoint at line 10
   ```

4. **Run the Program**:
   - Start the program inside the debugger.
   ```bash
   (gdb) run
   ```

5. **Inspect Variables**:
   - After the program hits a breakpoint, inspect variables using the `print` command.
   ```bash
   (gdb) print variable_name
   ```

6. **Step Through the Code**:
   - You can step through the code one line at a time with the following commands:
     - `next`: Go to the next line of code (but step over function calls).
     - `step`: Step into functions and break at the first line inside the function.
     - `continue`: Continue running the program until the next breakpoint.

7. **Quit Debugger**:
   - To exit GDB, type `quit` or `q`.
   ```bash
   (gdb) quit
   ```

#### 3. **Using IDE Debuggers (Visual Studio, CLion, etc.)**
Modern IDEs (like **Visual Studio**, **CLion**, and **Eclipse**) come with integrated debuggers that make the process of debugging even easier. These IDEs allow you to set breakpoints, inspect variables, step through code, and even view the call stack in a graphical interface.

For example, in **Visual Studio**:
1. **Set a Breakpoint**: Click on the margin next to a line of code to set a breakpoint.
2. **Start Debugging**: Press `F5` or click on the "Start Debugging" button.
3. **Inspect Variables**: Hover over variables to see their current values or use the "Watch" window to track specific variables.
4. **Step Through the Code**: Use `F10` to step over lines, `F11` to step into functions, or `Shift + F11` to step out of a function.

#### 4. **Static Code Analyzers**
Static analysis tools examine your code without running it, detecting potential issues such as syntax errors, memory leaks, and undefined behaviors.

Popular C++ static analyzers include:
- **Clang Static Analyzer**: Can be used with the Clang compiler to identify bugs.
- **Cppcheck**: A popular open-source static code analysis tool for C++.
- **SonarQube**: A platform for continuous inspection of code quality.

Example of using **Cppcheck**:
```bash
cppcheck myprogram.cpp
```

#### 5. **Valgrind (For Memory Debugging)**
Memory-related issues such as memory leaks, invalid memory access, and uninitialized memory can cause hard-to-track bugs in C++ programs. **Valgrind** is a tool that helps detect such issues.

1. **Install Valgrind** (on Linux):
   ```bash
   sudo apt-get install valgrind
   ```

2. **Run your program with Valgrind**:
   ```bash
   valgrind ./myprogram
   ```

   It will provide output showing memory errors such as leaks, invalid access, or incorrect memory allocations.

#### 6. **Common Debugging Strategies**
- **Isolate the Issue**: Try to narrow down where the problem is occurring by removing parts of the code or commenting out certain blocks.
- **Check Boundary Conditions**: Ensure that loop bounds, array sizes, and pointer dereferencing are correct. Off-by-one errors are common.
- **Use Assertions**: Use `assert()` to ensure that assumptions in your code hold true.
   ```cpp
   #include <cassert>

   int divide(int a, int b) {
       assert(b != 0);  // Ensure b is not zero
       return a / b;
   }
   ```

- **Review Compiler Warnings**: Often, compilers will provide helpful warnings about possible issues in your code, such as unused variables, type mismatches, or potential memory issues.
   ```bash
   g++ -Wall -o myprogram myprogram.cpp  # Enable all warnings
   ```

### Example Debugging Workflow:
Consider the following buggy program with a potential infinite loop:

```cpp
#include <iostream>
using namespace std;

void buggyLoop(int n) {
    int i = 0;
    while (i < n) {
        cout << "i = " << i << endl;
        // Bug: i is never incremented, causing an infinite loop
    }
}

int main() {
    buggyLoop(5);
    return 0;
}
```

**Steps to debug:**
1. **Print Statements**: We can add a `cout` statement inside the loop to verify if the loop is running infinitely.
   ```cpp
   cout << "Before loop: i = " << i << endl;
   ```

2. **Using GDB**: Compile with `-g`, run with `gdb`, set a breakpoint at `buggyLoop`, and check the value of `i` each time the loop runs.

3. **Fix the Bug**: After inspecting the code, we see that the issue is that the loop control variable `i` is never updated. The fix is to add `i++` inside the loop.

```cpp
#include <iostream>
using namespace std;

void buggyLoop(int n) {
    int i = 0;
    while (i < n) {
        cout << "i = " << i << endl;
        i++;  // Fix: increment i to avoid infinite loop
    }
}

int main() {
    buggyLoop(5);
    return 0;
}
```

### Conclusion:
To debug C++ code effectively, you can use several methods, ranging from simple print statements to advanced tools like GDB, static code analyzers, and memory debuggers like Valgrind. Using modern IDEs also greatly simplifies the process by offering visual debuggers with step-through capabilities.

The process typically involves isolating the problem, inspecting variable values, stepping through the code, and correcting issues.