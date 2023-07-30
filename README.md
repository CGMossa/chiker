# `chiker`

This repository is to showcase extending R with some C code that uses R's C-facilities.

It is required that `R` is available in `PATH`.

In order to know what you can do, and what is possible, you need to consult
the C-facilities; these are found in `%R_HOME%/include`.

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

Also, this project uses a custom vscode extension called `RCMDconfig` to
retrieve system settings for the currently installed R version.

This allows configuring to leverage R's miticulous cross-platform settings, e.g.

```json
"includePath": [
                "${workspaceFolder}/**",
                "${config:R.CMD.config.R_HOME}/include",
            ],
```

enables intellisense, linter and everything link up with R's C-headers.

Also, note `R_NO_REMAP` in the defines section of `c_cpp_properties.json`.
This makes sure that R-functions in C are prefixed with `Rf_`.

## `vscode` workflow

In `.vscode/tasks.json`, there is a task that uses `R CMD SHLIB` to build the
current file into a library. It also takes all `gcc` errors and puts them
in the problems section. Thus,
press <kbd>Ctrl</kbd>+<kbd>Shift</kbd>+<kbd>B</kbd> after editting.

To explore R's C-headers, there is a task `Open R headers (workspace)`.
