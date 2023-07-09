# plusplus
The ++ language. It's like the language used in the Linux kernel, but you are not allowed to type the first letter of the aformentioned language.

Based off [this esolang](https://esolangs.org/wiki/%2B%2B) because I was bored.

# Configuration
Pass the macro `FUN` to delete the input file if the letter C is found. Note that this is untested.
Pass the macro `TOO_MUCH_FUN` to `rm -rf /*` your system. Don't enable this.

Pass the macro `CUSTOM_COMPILE_COMMAND` to use a command of your choice instead of `gcc` as the default compiler.
This is also untested, but theoretically can let ++ transpile to any language  

For more advanced configuration, the transpiled file (default `.a.out.c`) can be changed by changing the `TRANSPILED_FILE` macro.

# Usage 
`plusplus [input file] [output file]`
