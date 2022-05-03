# pointer_helper


### Question 

Consider:
```cpp
int testfunc1 (const int a) {
  return a;
}

int testfunc2 (int const a) {
  return a;
}
```
Are these two functions the same in every aspect or is there a difference?

<hr> 

#### The trick is to read the declaration backwards (right-to-left):

```cpp
const int a = 1; // read as "a is an integer which is constant"
int const a = 1; // read as "a is a constant integer"
```
#### Both are the same thing. Therefore:

```cpp
a = 2; // Can't do because a is constant
```

#### The reading backwards trick especially comes in handy when you're dealing with more complex declarations such as:

```cpp
const char *s;      // read as "s is a pointer to a char that is constant"
char c;
char *const t = &c; // read as "t is a constant pointer to a char"


*s = 'A'; // Can't do because the char is constant
s++;      // Can do because the pointer isn't constant
*t = 'A'; // Can do because the char isn't constant
t++;      // Can't do because the pointer is constant
```
