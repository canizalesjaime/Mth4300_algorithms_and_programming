# Steps for Docker:
1. If image is not built , build it by running:
```
cd .devcontainer
docker build -t test_repo .
```      
2. Run from directory to mount: 
   ```
    docker run --name test_repo_container -it --rm -v ${PWD}/:/workspace -w /workspace test_repo
   ``` 
3. If container doesn't open and terminal says "container started", in another terminal run: ``` docker ps -a``` to get container id then: ``` docker exec -it \<containerID\> ```

# Docker commands to remember:
1. docker ps -a (Shows container ids)
2. docker commit \<containerID\> \<repository\>:\<tag\> (to save changes on container to image)
3. docker rm \<containerID\> (delete container)
4. docker exec -it \<containerID\> bash (open another terminal in a current container)
5. docker tag NAME:tag myaccount/name:tag then docker push myaccount/name:tag


# Dev containers
1. Install dev containers extension in vscode.
2. Change line 12 in file './.devcontainer/devcontainer.json' to the local repo you would like to open. 
3. Reopen container at top prompt.

