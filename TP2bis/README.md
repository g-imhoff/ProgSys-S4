
# TitleModifier
This project was created by Guillaume IMHOFF, the goal of this project was to train and get better at system programming in C 

## Install/Compile

You can directly download the file in the release section or by downloading the code and compile on your device : 

```bash
    git clone git@github.com:purpl5/TitleModifier.git
    cd TitleModifier
    cd build 
    make 
    ./TitleModifier
```


## How it works 
```bash
    computer@computer : ~/TitleModifier/build$ ./TitleModifier 
    Enter the name of the folder that you want to scan: ./
    Enter the string to delete from the title: StrToDelete
    the function was successful
```

In this case, the program will check if every folder or file title in ./ contains StrToDelete and if it contains StrToDelete, will rename the folder or file without StrToDelete. 