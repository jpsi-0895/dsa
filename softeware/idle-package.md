Creating software to identify non-functional (idle) or unused software on an Ubuntu system can be a useful task for managing resources and optimizing system performance. The idea behind this software is to track applications and services that have not been used for a certain period and identify those that are consuming unnecessary resources.

The key aspects for such a software tool include:
- **Identifying installed software** (e.g., from package management).
- **Tracking software usage** (through logs, system statistics, or user interaction).
- **Determining idle or non-functional software** based on usage patterns.

Here's an outline of how such a software might be implemented in **Python** with access to Linux utilities and APIs. This software will:
1. List installed packages.
2. Identify software based on last access time.
3. Provide options to remove or disable idle software.

### **Step-by-Step Approach**

1. **Identify Installed Software**:
    - Use `dpkg` to list installed software.
    - Use `apt` or `snap` commands for package management.
   
2. **Monitor Software Usage**:
    - Use tools like `ps`, `top`, or `lsof` to identify running processes.
    - Use logs or timestamps to track the last accessed time.

3. **Define Threshold for Inactivity**:
    - Set a threshold to determine if software is idle (e.g., not accessed in 30 days).

4. **Provide Options**:
    - Show a list of idle software.
    - Give options to remove or disable it.

Here is a Python script that performs the basic task of identifying potentially unused software on Ubuntu.

### **Python Script: Identify Idle Software in Ubuntu**

```python
import os
import subprocess
from datetime import datetime, timedelta


def get_installed_packages():
    """Get a list of installed packages using dpkg."""
    packages = subprocess.check_output(["dpkg", "--get-selections"], text=True).splitlines()
    installed_packages = [pkg.split()[0] for pkg in packages if "install" in pkg]
    return installed_packages


def get_last_access_time(file_path):
    """Get the last access time of a file in seconds since epoch."""
    try:
        return os.path.getatime(file_path)
    except FileNotFoundError:
        return 0


def get_idle_time_of_package(package_name):
    """Estimate idle time by checking the last access time of executable files."""
    package_path = f"/usr/bin/{package_name}"
    
    # Check if the package is installed and executable
    if os.path.exists(package_path):
        last_access_time = get_last_access_time(package_path)
        return last_access_time
    else:
        return 0


def check_idle_packages(threshold_days=30):
    """Check installed packages and identify idle ones based on the threshold."""
    installed_packages = get_installed_packages()
    idle_packages = []

    threshold_time = datetime.now() - timedelta(days=threshold_days)
    threshold_timestamp = threshold_time.timestamp()

    for package in installed_packages:
        last_access_time = get_idle_time_of_package(package)

        if last_access_time == 0:  # Skip non-executable packages
            continue

        if last_access_time < threshold_timestamp:
            last_access_date = datetime.fromtimestamp(last_access_time).strftime('%Y-%m-%d')
            idle_packages.append((package, last_access_date))

    return idle_packages


def display_idle_packages(idle_packages):
    """Display a list of idle packages with their last access date."""
    if not idle_packages:
        print("No idle packages found.")
    else:
        print(f"{'Package Name':<30} {'Last Access Date'}")
        print("=" * 50)
        for package, last_access_date in idle_packages:
            print(f"{package:<30} {last_access_date}")


def main():
    """Main function to check for idle software."""
    print("Checking for idle software...")
    idle_packages = check_idle_packages(threshold_days=30)  # You can adjust threshold days here
    display_idle_packages(idle_packages)


if __name__ == "__main__":
    main()
```

### **Explanation of the Code**

1. **get_installed_packages**: 
   - This function uses `dpkg --get-selections` to get a list of installed packages on the system.
   - It filters out the packages that are marked for installation (and excludes ones marked for removal or purge).

2. **get_last_access_time**:
   - This function checks the last access time of a file (the executable of a package).
   - We use `os.path.getatime(file_path)` to get the last access time of the file.

3. **get_idle_time_of_package**:
   - Given the package name, this function checks if the executable of the package (located in `/usr/bin/`) has been accessed recently.
   - If it hasn’t been accessed recently, the package is considered idle.

4. **check_idle_packages**:
   - This function uses the threshold value to determine which packages are idle. It checks the last access time against a threshold (default is 30 days).
   
5. **display_idle_packages**:
   - Displays the idle packages and their last access date.

6. **main**:
   - The entry point for the program, which triggers the check and displays the results.

### **How to Run the Software**

1. **Save the script**:
    - Save the above code to a file, for example, `idle_software.py`.

2. **Install dependencies**:
    - The script uses standard Python libraries, so no additional dependencies are required.

3. **Make the script executable**:
    ```bash
    chmod +x idle_software.py
    ```

4. **Run the script**:
    ```bash
    python3 idle_software.py
    ```

### **Expected Output**

If there are any idle packages (not accessed in the last 30 days), the script will output a list of them along with their last access date. For example:

```bash
Checking for idle software...
Package Name                  Last Access Date
==================================================
package1                      2022-08-01
package2                      2022-07-15
```

### **Next Steps and Improvements**

1. **Automated Removal/Disabling**:
    - You could extend the script to allow the user to disable or uninstall the idle software by running `sudo apt remove <package_name>` or `sudo systemctl stop <service_name>` for services.
   
2. **Track Service Usage**:
    - You could add functionality to track the usage of system services with `systemd` and identify services that haven’t been accessed for a long time.

3. **Include Snap and Flatpak**:
    - If you're using Snap or Flatpak, include commands to list software installed via these systems as well (`snap list` for Snap packages and `flatpak list` for Flatpak).

4. **Improve Accuracy**:
    - Check the logs (e.g., `~/.bash_history`, application logs) for user interaction to identify if a package has been used recently.

5. **GUI**:
    - Build a simple GUI (with `Tkinter` or `PyQt`) to allow users to view and interact with idle software packages more easily.

### **Conclusion**

This software identifies idle or non-functional software in Ubuntu by checking the last access time of installed package executables. You can enhance this script further by adding removal or disabling features and integrating additional tracking mechanisms.