# Tanc

Tanc (pronounced /tæŋk/, like "tank") is a simple, fast ANSI C library for debugging and logging. It is designed to be easy to use and to integrate into your project as a header-only library. It aims to help you crush through barriers when doing your work in the year 1989, or finishing your homework from courses with some idiotic requirements in modern times.

## Features

TODO

## Compatibility

Tanc is developed and tested on Linux with GCC 11.4.0. It should work on any POSIX-compliant system with GCC. Though most of the GNU language extensions are prohibited in ANSI C under `-std=c89 -Wpedantic -Wall -Wextra -Werror`, there are still some extensions that are not prohibited and are listed below:

- [ ] [Statements and Declarations in Expressions](https://gcc.gnu.org/onlinedocs/gcc/Statement-Exprs.html)
- [ ] [Locally Declared Labels](https://gcc.gnu.org/onlinedocs/gcc/Local-Labels.html)
- [ ] [Labels as Values](https://gcc.gnu.org/onlinedocs/gcc/Labels-as-Values.html)
- [ ] [Nested Functions](https://gcc.gnu.org/onlinedocs/gcc/Nested-Functions.html)
- [x] [Nonlocal Gotos](https://gcc.gnu.org/onlinedocs/gcc/Nonlocal-Gotos.html)
- [x] [Constructing Function Calls](https://gcc.gnu.org/onlinedocs/gcc/Constructing-Calls.html)
- [x] [Referring to a Type with `typeof`](https://gcc.gnu.org/onlinedocs/gcc/Typeof.html) (Polyfilled by `__typeof__`)
- [ ] [Conditionals with Omitted Operands](https://gcc.gnu.org/onlinedocs/gcc/Conditionals.html)
- [ ] [Arrays of Length Zero](https://gcc.gnu.org/onlinedocs/gcc/Zero-Length.html)
- [ ] [Structures with No Members](https://gcc.gnu.org/onlinedocs/gcc/Empty-Structures.html)
- [ ] [Arrays of Variable Length](https://gcc.gnu.org/onlinedocs/gcc/Variable-Length.html)
- [ ] [Macros with a Variable Number of Arguments](https://gcc.gnu.org/onlinedocs/gcc/Variadic-Macros.html)
- [ ] [Non-Lvalue Arrays May Have Subscripts](https://gcc.gnu.org/onlinedocs/gcc/Subscripting.html)
- [ ] [Non-Constant Initializers](https://gcc.gnu.org/onlinedocs/gcc/Initializers.html)
- [ ] [Compound Literals](https://gcc.gnu.org/onlinedocs/gcc/Compound-Literals.html)
- [ ] [Designated Initializers](https://gcc.gnu.org/onlinedocs/gcc/Designated-Inits.html)
- [ ] [Case Ranges](https://gcc.gnu.org/onlinedocs/gcc/Case-Ranges.html)
- [ ] [Cast to a Union Type](https://gcc.gnu.org/onlinedocs/gcc/Cast-to-Union.html)
- [x] [Declaring Attributes of Functions](https://gcc.gnu.org/onlinedocs/gcc/Function-Attributes.html)
- [x] [Specifying Attributes of Variables](https://gcc.gnu.org/onlinedocs/gcc/Variable-Attributes.html)
- [x] [Specifying Attributes of Types](https://gcc.gnu.org/onlinedocs/gcc/Type-Attributes.html)
- [x] [Label Attributes](https://gcc.gnu.org/onlinedocs/gcc/Label-Attributes.html)
- [x] [Enumerator Attributes](https://gcc.gnu.org/onlinedocs/gcc/Enumerator-Attributes.html)
- [x] [Statement Attributes](https://gcc.gnu.org/onlinedocs/gcc/Statement-Attributes.html)
- [x] [An Inline Function is As Fast As a Macro](https://gcc.gnu.org/onlinedocs/gcc/Inline.html) (Polyfilled by `__inline__`)
- [x] [Function Names as Strings](https://gcc.gnu.org/onlinedocs/gcc/Function-Names.html) (Polyfilled by `__builtin_FUNCTION`)
- [x] [Getting the Return or Frame Address of a Function](https://gcc.gnu.org/onlinedocs/gcc/Return-Address.html)
- [x] [Support for `offsetof`](https://gcc.gnu.org/onlinedocs/gcc/Offsetof.html)
- [x] [Other Built-in Functions Provided by GCC](https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html)
- [ ] [Unnamed Structure and Union Fields](https://gcc.gnu.org/onlinedocs/gcc/Unnamed-Fields.html)



