# Steps for Docker on Terminal:
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

# Useful Docker Commands:
1. docker ps -a (Shows container ids)
2. docker commit \<containerID\> \<repository\>:\<tag\> (to save changes on container to image)
3. docker rm \<containerID\> (delete container)
4. docker exec -it \<containerID\> bash (open another terminal in a current container)
5. docker tag NAME:tag myaccount/name:tag then docker push myaccount/name:tag


# Steps for Docker with Dev Containers(easier alternative to the above):
1. Install dev containers extension in vscode.
2. Make sure that vscode is opened with Mth4300_algorithms_and_programming folder(go to **File** on top left then press **Open Folder...**)
3. ctrl + shift + p to open command palette
4. Find and click on **Dev Containers: Rebuild and Reopen in Container**
5. If you would like to use docker for another folder, copy the .devcontainer folder into that folder; then repeat steps 1 to 4. 

