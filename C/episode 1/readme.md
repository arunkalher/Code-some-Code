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