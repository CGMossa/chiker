# `chiker`

Package origins:

```r
usethis::create_project("chiker")
usethis::use_directory("notebooks", ignore = TRUE)
```

Be sure to have the restart button handy for this one.

## `vscode` settings

Editting C files in Rstudio isn't the most comfortable.
For this, I use `vscode` with C/C++ extensions installed.
> Name: C/C++ Extension Pack
Id: ms-vscode.cpptools-extension-pack
Description: Popular extensions for C++ development in Visual Studio Code.
Version: 1.3.0
Publisher: Microsoft
VS Marketplace Link: <https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack>

- In the `c_cpp_properties.json` file I include at the top:

```json
    "env": {
        // EDIT THIS
        "R_HOME": "C:/Users/Kevin/scoop/apps/r/current"
    },
```

where I fill in my personal setting. Note where this is different in the file.

## `vscode` workflow

In `.vscode/tasks.json`, there is a task that uses `R CMD SHLIB` to build the
current file into a library. It also takes all `gcc` errors and puts them
in the problems section. Thus, press <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>B</kbd> after editting.
