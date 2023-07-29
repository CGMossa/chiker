
#' `tools` is a standard r-package for package development.
#' Basically shortcut for terminal: R CMD SHLIB
#'
tools::Rcmd(c("SHLIB", "--clean", "--use-C23", "lib.c"))

#' Load the library
dyn.load("lib")

#' Using it

.Call("silly")

#' I want to create S4 objects in C code.
#' But actually it is necessay for these to be defined here.
#'
#'
setClass(
  "Person",
  slots = list(
    name = "character",
    age = "numeric"
  ),
  prototype = list(
    name = NA_character_,
    age = NA_real_
  )
)
#'
#'
#' Then I'm allowed to call a function that retrieves this definition
#' and fills it out as needed.
#'
person <- .Call("create_s4_object")
person

#' Final: At the end of the script
#'
dyn.unload("lib")
