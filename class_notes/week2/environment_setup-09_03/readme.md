# Lecture Notes

## table of contents
1. Environment Setup
2. Terminal Basics


## Enivironment Setup
### Tools we will be using
* Visual Studio Code (VS Code) is a source code editor that combines developer tooling with a fast edit-build-debug cycle
* Docker is a software platform that allows developers to build, test, and deploy applications in containers. It's an open-source platform that provides a way to separate applications from infrastructure, which can help speed up software delivery. 
* Git is a version control system (VCS) that allows programmers, software engineers, and developers to work together on projects. It's the most popular open-source VCS in the world and is used by millions of people every day.


### Installation links
* [docker install link](https://docs.docker.com/engine/install/)(Make sure to turn on wsl2 for if you're using windows)
* [git install link](https://git-scm.com/downloads)
* [vscode install link](https://code.visualstudio.com/download)
  * To install vscode extensions use the shortcut **ctrl+shit+x**, then search for the following:  
    * Dev Containers
    * C/C++ Themes

Once you have installed all the links above, open vscode and its terminal with shortcut **ctrl+`**, and navigate to where you want to download the github folder on your computer. Once you settle on a location, run the command<br> ```git clone https://github.com/canizalesjaime/Mth4300_algorithms_and_programming.git```

Create a folder and name it **hidden**, inside this folder you can develop code that won't conflict with the class code.

To open the github directory in vscode, first open vscode, then open the directory Mth4300_algorithms_and_programming by going to **File** on top left then press **Open Folder...** and select Mth4300_algorithms_and_programming folder. Everytime you open the folder in vscode you should open a terminal using the shortcut **ctrl+`** then run the command ```git pull```. This will update any changes I have made recently to the directory.


## Terminal Basics
In this class we will be using the terminal as a means for interacting with our computer. To acces the terminal in vscode use the shortcut **ctrl+`**. 
### List of useful commands(Note the terms directory, and folder are the same thing):
* pwd : print the working directory(where your terminal is operating from)
* cd : change directory (changing working directory to another directory) ```cd directory_path```
* mv : move a file to another location ```mv file_to_move location_to_move_file```
* cp : copy a file  ```cp file_to_copy location_to_copy_file```
* mkdir : create a directory ```mkdir new_folder_name```
* ls : show all files in the working directory
* g++ : compile a *.cpp file into a.out
* ./ : shorcut for this directory ```./a.out``` (is saying in this directory execute a.out(analogous to clicking on file)) 
* ../ : refers to the parent directory. ```cd ../```(changes the working directory to the parent directory)
