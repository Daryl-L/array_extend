# array_extend

[![Build Status](https://travis-ci.org/Daryl-L/array_extend.svg?branch=master)](https://travis-ci.org/Daryl-L/array_extend)

## Introduction

Some convient functions for array. Some methods in Laravel Collection which not exist in original PHP array functions.

## Required

    php >= 7.0

## Usage

```sh
$ phpize
$ ./configure
$ make && make test && make install
```

## Functions

### array_every

The `array_expect` function may be used to verify that all elements of an array pass a given truth test.

```php
array_every([1, 2, 3, 4], function ($item) {
    return $item < 4;
});

// false
```

### array_search_uassoc

Just like the original function `array_search`, but the second parameters is your own callback to search for the first key of the item that passes your truth test.

```php
array_search_uassoc([1, 2, 3, 4, 5], function ($item) {
    return $item > 3;
})

// 3
```