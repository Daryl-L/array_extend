--TEST--
array_every() Basic TEST
--SKIPIF--
<?php
if (!extension_loaded('array_extend')) {
    echo 'skip';

}
?>
--FILE--
<?php
var_dump(array_every([1, 2, 3], function ($item) {
    if (3 == $item) {
        return false;
    }
}));

$x = '';
var_dump(array_every([1, 2, 3, 4], function ($item) use (&$x) {
    if (3 < $item) {
        return false;
    }
    $x .= $item;
}));
echo $x;
?>
--EXPECT--
bool(false)
bool(false)
123