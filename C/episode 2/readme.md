#  C typedef-
### The typedef is a keyword that is used to provide existing data types with a new name. The C typedef keyword is used to redefine the name of already existing data types.

### When names of datatypes become difficult to use in programs, typedef is used with user-defined datatypes, which behave similarly to defining an alias for commands.

## Syntax -
### typedef existing_name alias_name;

#### After this declaration, we can use the alias_name as if it were the real existing_name in out C program.
```C
#include<stdio.h>
typedef long long ll;
int main()
{
    ll x=22331313131;
    printf("%lld",x); // 22331313131

}
```
## Following are some common uses of the typedef in C programming:

#### - The typedef keyword gives a meaningful name to the existing data type which helps other users to understand the program more easily.
#### - It can be used with structures to increase code readability and we don’t have to type struct repeatedly.
#### - The typedef keyword can also be used with pointers to declare multiple pointers in a single statement.
#### - It can be used with arrays to declare any number of variables.

## typedef struct
#### typedef can also be used with structures in the C programming language. A new data type can be created and used to define the structure variable.

```C
#include<stdio.h>
#include<string.h>

struct Point
{
   int x ;  
   int y ;  
   char quadrant[10];
};
typedef struct Point pt;
int main()
{
    pt p={1,1};
    strcpy(p.quadrant,"first");
    printf("%d,%d,%s",p.x,p.y,p.quadrant);
}

```

## Using typedef to define a name for pointer type.

```C
#include <stdio.h>
 
typedef int* ptr;
 
// Driver code
int main()
{
    ptr var;
    *var = 20;
 
    printf("Value of var is %d", *var);
    return 0;

```

## typedef with Array

```C


typedef int Arr[4];

int main()
{
	Arr arr = { 10, 20 };
	

	for (int i = 0; i < 2; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}

```

## C typedef vs #define

### The following are the major difference between the typedef and #define in C:

#### - define is capable of defining aliases for values as well, for instance, you can define 1 as ONE, 3.14 as PI, etc. Typedef is limited to giving symbolic names to types only.
#### - Preprocessors interpret #define statements, while the compiler interprets typedef statements.
#### - There should be no semicolon at the end of #define, but a semicolon at the end of typedef.
#### - In contrast with #define, typedef will actually define a new type by copying and pasting the definition values.