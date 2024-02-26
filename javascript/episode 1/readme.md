
# JavaScript - Episode 1 
# Array.prototype.map()
#### 5 min read

### The map() method of Array creates a new array populated with the results of calling a provided function on every element in the calling array.

## Syntax -
### map(callbackFun)
### map(callbackFun, _this)
### callbackFun(ele,ind,arr) - A function to execute for each element in the array. Its return value is added as a single element in the new array. The function is called with the following arguments (optional) :
#### ele- The current element being processed in the array.
#### ind - The index of the current element being processed in the array.
#### arr - The array on which map() was called upon.
## Return Value - 
A new array with each element being the result of the callback function.
## Examples -
```javascript
arr=[1,2,3,4]
arr.map((ele)=>ele**2)
// [ 1, 4, 9, 16 ]
```
```javascript
arr=[1,2,3,4]
arr.map((ele)=>{ele**2})
//[ undefined, undefined, undefined, undefined ]
```
```javascript
arr=[1,2,3,4]
arr.map((ele)=>{return ele**2})
//[ 1, 4, 9, 16 ]
```
```javascript
const dummyArr= [
    { id: 1, name: "Rahul"},
    { id: 2, name: "Manan"},
    { id: 3, name: "Ajay"},
  ];
  
dummyArr.map(({ id, name}) => ({ [id] : name }));

// [ { '1': 'Rahul' }, { '2': 'Manan' }, { '3': 'Ajay' } ]
```
```javascript
const numbers = [1, 2, 3, 4];
numbers.map((num, index) => {
  if (index >= 3) {
    return num;
  }
});
// [ undefined, undefined, undefined, 4 ]
```


### If you don't use the return value of map(), use forEach() instead.

```javascript
const products = [
  { name: "watch" },
  { name: "phone" },
];

products.map((product) => {
  product.price = 100;
});

// [ undefined, undefined ]
```
```javascript
const products = [
  { name: "watch" },
  { name: "phone" },
];

products.map((product) => {
    const {name}=product
    return {name,price:100}
  
});

// [ { name: 'watch', price: 100 }, { name: 'phone', price: 100 } ]
```
```javascript
const products = [
  { name: "watch" },
  { name: "phone" },
];

products.map((product) => {
   
    return {...product,price:100}
  
});

// [ { name: 'watch', price: 100 }, { name: 'phone', price: 100 } ]
```
```javascript
const products = [
  { name: "watch" },
  { name: "phone" },
];

products.forEach((product) => {
  product.price = 100;
});
// undefined 

console.log(products)
// [ { name: 'watch', price: 100 }, { name: 'phone', price: 100 } ]
```


## Note- There is no way to access the array being built from the callback function.


```javascript
const dummyArr=[1,2,3,4,5]
dummyArr.map((ele,ind,arr)=>arr[2]+ele)

// [ 4, 5, 6, 7, 8 ]
```

```javascript
const dummyArr=[1,,3,,5]
dummyArr.map((x, index) => {
    return 2;
  })

// [ 2, <1 empty item>, 2, <1 empty item>, 2 ]
```

```javascript
const dummyArr=[1,,3,,5]
dummyArr.map((x, index) => {
    return 2;
  })

// [ 2, <1 empty item>, 2, <1 empty item>, 2 ]
```

```javascript
const arrayLike = {
    length: 3,
    0: 2,
    1: 3,
    6: 5, // ignored by map() since length is 3
  };
console.log(Array.prototype.map.call(arrayLike, (x) => x ** 2));

// [ 4, 9, <1 empty item> ]
```









