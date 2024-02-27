#  Structure in C-
### The structure in C is a user-defined data type that can be used to group items of possibly different types into a single type. The struct keyword is used to define the structure in the C programming language. The items in the structure are called its member and they can be of any valid data type.
```C
struc [struc_name]{
    //data_type d1;
    //data_type d2;
}
[struct_variable(optional)];
```
```C
#include<stdio.h>
#include<string.h>
struct Student{
    int roll;
    char name[20];
}Shyam;
struct Student Mohan;
// global variables- Shyam,Mohan
```
```C
int main()
{   
    struct Student Rahul;
    Rahul.roll=10;
    Rahul.name[0]='R';
    Rahul.name[1]='\0';
    printf("%d",Rahul.roll); // 10
    printf("%s",Rahul.name); // R
}
```
```C
int main()
{   
    struct Student Rahul;
    Rahul.roll=10;
    strcpy(Rahul.name,"Rahul");
    printf("%d",Rahul.roll); // 10
    printf("%s",Rahul.name); // Rahul
}
```
```C
int main()
{
Mohan.roll=1;
printf("%d",Mohan.roll); // 1
}

```


```C
struct Point
{
   int x = 0;  // COMPILER ERROR:  cannot initialize members here
   int y = 0;  // COMPILER ERROR:  cannot initialize members here
};
```

### Initialization using Assignment Operator

```C
int main()
{
Rahul.roll=10;
}
```

### Initialization using Initializer List

```C
#include<stdio.h>
#include<string.h>
struct Point
{
   int x ;  
   int y ;  
};

int main()
{   
    struct Point p1={1,2};
    printf("%d,%d",p1.x,p1.y);    //1,1

}

```

```C
int main()
{   
    struct Point p1;
    p1={1,2}; //error
    printf("%d,%d",p1.x,p1.y);   

}
```
### Initialization using Designated Initializer List
```C
int main()
{   
    struct Point p1={.y=2,.x=1};
    printf("%d,%d",p1.x,p1.y);    //1,2

}
```
```C
struct Point
{
   int x ;  
   int y ;
   char quadrant[10];  
};
int main()
{   
    struct Point p1={.y=2,.x=1};
    strcpy(p1.quadrant,"first");
    printf("%d,%d",p1.x,p1.y);    //1,2

}

```

## Nested Structures

#### C language allows us to insert one structure into another as a member. This process is called nesting and such structures are called nested structures. There are two ways in which we can nest one structure into another:


### 1. Embedded Structure Nesting
#### In this method, the structure being nested is also declared inside the parent structure.

```C
struct parent {
    int member1;
    struct member_str member2 {
        int member_str1;
        char member_str2;
        ...
    }
    ...
}
```

### 2. Separate Structure Nesting
#### In this method, two structures are declared separately and then the member structure is nested inside the parent structure
```C
struct member_str {
    int member_str1;
    char member_str2;
    ...
}

struct parent {
    int member1;
    struct member_str member2;
    ...
}
```

#### One thing to note here is that the declaration of the structure should always be present before its definition as a structure member. For example, the declaration below is invalid as the struct s is not defined when it is declared inside the parent structure.

```C
struct parent {
    struct s a;
};

struct s {
    int var;
};
```


```C
// C Program to illustrate structure nesting along with 
// forward declaration 
#include <stdio.h> 

// child structure declaration 
struct child { 
	int x; 
	char c; 
}; 

// parent structure declaration 
struct parent { 
	int a; 
	struct child b; 
}; 

// driver code 
int main() 
{ 
	struct parent var1 = { 25, 195, 'A' }; 

	// accessing and printing nested members 
	printf("var1.a = %d\n", var1.a); 
	printf("var1.b.x = %d\n", var1.b.x); 
	printf("var1.b.c = %c", var1.b.c); 

	return 0; 
}

```

### Structure Pointer
```C
// C program to illustrate the structure pointer 
#include <stdio.h> 

// structure declaration 
struct Point { 
	int x, y; 
}; 

int main() 
{ 
	struct Point str = { 1, 2 }; 

	// p2 is a pointer to structure p1 
	struct Point* ptr = &str; 

	// Accessing structure members using structure pointer 
	printf("%d %d", ptr->x, ptr->y); 

	return 0; 
}

```

### Self-Referential Structures
#### The self-referential structures in C are those structures that contain references to the same type as themselves i.e. they contain a member of the type pointer pointing to the same structure type.

```C
struct structure_name {
    data_type member1;
    data_type member2;
    struct structure_name* str;
}
```

```C
// C program to illustrate the self referential structures 
#include <stdio.h> 

// structure template 
typedef struct str { 
	int mem1; 
	int mem2; 
	struct str* next; 
}str; 

// driver code 
int main() 
{ 
	str var1 = { 1, 2, NULL }; 
	str var2 = { 10, 20, NULL }; 

	// assigning the address of var2 to var1.next 
	var1.next = &var2; 

	// pointer to var1 
	str *ptr1 = &var1; 

	// accessing var2 members using var1 
	printf("var2.mem1: %d\nvar2.mem2: %d", ptr1->next->mem1, 
		ptr1->next->mem2); 

	return 0; 
}


```

### C Structure Padding and Packing
#### Technically, the size of the structure in C should be the sum of the sizes of its members. But it may not be true for most cases. The reason for this is Structure Padding.

#### Structure padding is the concept of adding multiple empty bytes in the structure to naturally align the data members in the memory. It is done to minimize the CPU read cycles to retrieve different data members in the structure.

#### There are some situations where we need to pack the structure tightly by removing the empty bytes. In such cases, we use Structure Packing. C language provides two ways for structure packing:

#### Using #pragma pack(1)
#### Using __attribute((packed))__

#### [More Info here](https://github.com/arunkalher/Code-some-Code/tree/main/C/episode%204)