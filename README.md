# `chiker`

This repository is to showcase extending R with some C code that uses R's C-facilities.

In order to know what you can do, and what is possible, you need to consult
the C-facilities; these are found in `R_HOME/include`.

Generally, don't include `Rdefines.h`, add defines `STRICT_R_HEADERS`, `R_NO_REMAP`, `R_NO_REMAP_RMATH`.

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

where I fill in my personal setting. This is then used in several places,
for isntance

```json
"includePath": [
                "${workspaceFolder}/**",
                "${env:R_HOME}/include",
            ],
```
this helps intellisense, linter and everything link up nicely.

Also, note `R_NO_REMAP` in the defines section of `c_cpp_properties.json`.
This makes sure that R-functions in C are prefixed with `Rf_`.

## `vscode` workflow

It is required that `R` is available in `PATH`.

In `.vscode/tasks.json`, there is a task that uses `R CMD SHLIB` to build the
current file into a library. It also takes all `gcc` errors and puts them
in the problems section. Thus, press <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>B</kbd> after editting.
