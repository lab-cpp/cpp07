# C++ Module 07 - C++ Templates

## Overview
This module introduces **Templates** in C++, a powerful feature that allows you to write generic, type-safe code. Instead of copying and pasting the exact same function for `int`, `float`, and `std::string`, you write one "blueprint" (a template), and the compiler automatically generates the correct code for whatever type you use.

## Key Concepts

### 1. Function Templates (ex00, ex01)
A function template defines a family of functions. 
```cpp
template <typename T>
void myPrint(T value) {
    std::cout << value << std::endl;
}
```
**Type Deduction:** When you call `myPrint(42)`, the compiler automatically deduces that `T` is an `int`. When you call `myPrint("Hello")`, the compiler deduces `T` is a `const char*`. The compiler physically generates a different function for each type you use behind the scenes.

### 2. Class Templates (ex02)
A class template defines a family of classes, like `std::vector` or `std::map` from the standard library.
```cpp
template <typename T>
class Box {
    private:
        T _content;
    public:
        Box(T content) : _content(content) {}
};
```
Unlike function templates, **Type Deduction does not work for classes in C++98**. You must explicitly tell the compiler what type to generate when creating the object:
```cpp
Box<int> myIntBox(42);
Box<std::string> myStringBox("Hello");
```

### 3. Why `.hpp` only?
In standard C++ programming, you put declarations in `.hpp` files and implementations in `.cpp` files. 
**With templates, this rule is broken.** 
Because a template is just a "blueprint," the compiler cannot compile it into machine code until it knows what `T` is. When you use `Box<int>` in `main.cpp`, the compiler needs to see the full implementation of the `Box` class *right then and there* to generate the `int` version. If the implementation is hidden inside a `.cpp` file that hasn't been linked yet, you will get "Undefined Reference" linker errors. 
Therefore, **all template implementations must be placed inside header files** (or in a `.tpp` file that is included at the bottom of the `.hpp` file).

### 4. `typename` vs `class`
In template declarations like `template <typename T>` and `template <class T>`, the keywords `typename` and `class` do exactly the same thing. `typename` was introduced later because using `class` was confusing (since `T` could be an `int`, which is obviously not a class). Evaluators prefer seeing `typename T`.
