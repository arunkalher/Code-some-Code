# Map in JavaScript

### Map ais a JavaScript data structure you can use to store a collection of values, similar to Objects and Arrays. It is a specialized data structure that can help you store and manipulate related values.


## The Map Object 
#### The Map object stores data in a key/value pair structure, just like an Object. The main differences between a regular object and a Map are:

#### - A Map can have any type of data as the key value
#### - A Map maintains the order of data added to the object

### How to Create a Map Object
#### To create a Map object, you can call the Map() constructor as follows:
```javascript
const myMap = new Map();
```


### Map Object Methods and Properties


### - set(key, value) – Adds a key/value pair to a Map
### - get(key) – Retrieves a value from a Map (returns undefined if key doesn't exist)
### - has(key) – Checks if a Map has a specific key
### - delete(key) – Removes a specific key from a Map
### - clear() – Removes all items from a Map
### - keys() – Returns all keys in a Map
### - values() – Returns all values in a Map
### - entries() – Returns all keys and values in a Map
### - size – Returns the number of items in Map

#### To insert data into the Map object, you can use the set() method:
```javascript
const myMap = new Map();

myMap.set(1, 'Jack');
myMap.set(2, 'Jill');
myMap.set('animal', 'Elephant'); 
//Map(3) { 1 => 'Jack', 2 => 'Jill', 'animal' => 'Elephant' }
```


### To retrieve a value from the Map object, you need to use the get() method and pass the key as its argument:
```javascript
console.log(myMap.get(1)); // Jack

console.log(myMap.get('animal')); // Elephant
```

#### To see how many key/value pairs a Map has, you can access the size property:
```javascript
myMap.size; // 3
```


#### To see if a certain key exists in a Map object, you can use the has() method. See the example below:
```javascript
myMap.has(1); // true
myMap.has(10); // false
```




### To remove a key/value pair from a Map object, you can use the delete() method and pass the key of the pair you want to remove as follows:
```javascript
myMap.delete(1);

console.log(myMap);
// 0: {2 => "Jill"}
// 1: {"animal" => "Elephant"}
```

### If you want to remove all key/value pairs, you can use the clear() method instead:
```javascript
myMap.clear();

console.log(myMap); // Map(0) {size: 0}
```

## Other Ways to Create a Map Object
### You can also create a Map object from an Array as follows:


```javascript
const myMap = new Map([
  [1, 'Jack'],
  [2, 'Jill'],
  ['animal', 'Elephant'],
]);
// Map(3) { 1 => 'Jack', 2 => 'Jill', 'animal' => 'Elephant' }

```

#### - When creating a Map from an Array, you need to create a two-dimensional array and specify two elements in each array.

#### - The first element will be the key, the second element will be the value. Any extra value in the array will be ignored.

#### - In the example below, the value 'Johnson' from the first array will be ignored by the Map() constructor:
```javascript
const myMap = new Map([
  [1, 'Jack', 'Johnson'], // the value 'Johnson' is ignored
  [2, 'Jill'],
  ['animal', 'Elephant'],
]);

```

### Because you can create a Map object from an array, you can also create one from an object. You need to transform the object into an array first using the Object.entries() method.

### The following example shows how to use an object to create a Map:
```javascript
const person = {
    'name': 'Jack',
    'age': 20,
}
console.log(Object.entries(person))
// [ [ 'name', 'Jack' ], [ 'age', 20 ] ]
const myMap = new Map(Object.entries(person));
console.log(myMap); // Map(2) { 'name' => 'Jack', 'age' => 20 }
```


### Iterate Over Map Object Data
#### To iterate over a Map object data, you can use either the forEach() method or the for .. of loop:
```javascript
const myMap = new Map([
  [1, 'Jack'],
  [2, 'Jill'],
  ['animal', 'Elephant'],
]);

// iterate using the forEach() method
myMap.forEach((value, key) => {
  console.log(`${key}: ${value}`);
});

// or using the for .. of loop

for (const [key, value] of myMap) {
  console.log(`${key}: ${value}`);
}

// 1: Jack
// 2: Jill
// animal: Elephant
```
### When to Use the Map Object
#### - You can think of the Map object as an upgraded version of the regular Object. It can use any type of data as the key value, while an object can only use string values as keys.

#### - Under the hood, the Map object performs better when you need to add and remove keys, so you might consider using it when your data changes frequently.

#### - Also, the Map object has many useful methods for data manipulation, such as has() to see if the Map contains a specific key, keys() to get all keys defined in the Map, values to get all values, and entries() to get all key/value pairs.

#### - But if you only want to create an object without further manipulation, then you don't need to use the Map object.

#### - One example is when you send a network request using the fetch() method. You would create an object and convert it into a JSON string, so using a Map object won't give any benefit.

