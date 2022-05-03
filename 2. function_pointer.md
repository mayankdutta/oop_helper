### Question

I am working on a class project and my teacher has given us functions that we must write. Here is an example of one. I am wondering why there is a const at the beginning and the end. What do they do that they are needed on either end?

```cpp
const Foo multiple(int value) const;
```


<hr> 

<details>
  <summary> explanation 1 </summary> 
The first const applies to the return type of the member function.
The second const applies to the invisible this argument that is a pointer to the instance calling the Foo method.
</details>


<details> 
  <summary> explanation 2 </summary> 
First one is the type of the return value `(const Foo)`, the second one means that it doesn't alter the class.
</details>

<details> 
  <summary> explanation 3 </summary> 
In C++ `const return_type function_name(params)` means you have a function that returns a `const return_type`. 
If you have `static return_type function_name(params)` then this marks the function as `static` and you no longer need an instance of the class to call this function. 
If you want to mark a function as `const` meaning that it will not moodify the class contents then you need to place the const after the function as

```cpp
return_type function_name(params) const
                                  ^^^^^
```
  
  <details> 
