This is a simple shell implementation in C programming language that supports basic commands as well as features such as passing the command line arguments, executing a program, creating processes, waiting for them to complete, retrieving file information and accessing the environment variables.
To run the shell, simply clone this repository to your local machine
git clone https://github.com/your-username/simple-shell.git
Usage
 Once the program is running, you can enter commands in the shell prompt. The program supports the following command:
·        ls: lists the contents of the current directory
·        cd: changes the current working directory
·        mkdir: creates a new directory
·        rm: deletes a file or directory
·        cat: displays the contents of a file
·        echo: displays a message on the screen
·        help: displays a help message
·        exit: exits the shell program
The shell also supports:
Parsing and executing user input commands using the execve system call
Creating child processes to execute user input commands using the fork system call
Waiting for child processes to finish executing before continuing using the wait system call
Retrieving file information (size, access time, modification time)
Accessing environment variables

Contributing:
Contributions to this project are welcome, To contribute, please follow these steps:
Fork the repository
Create a new branch for your feature or bug fix
Make your changes and commit them with a clear commit messages
Push your changes to your forked repository
Submit a pull request to this repository
