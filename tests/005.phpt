--TEST--
array_search_uassoc() Basic TEST
--SKIPIF--
<?php
if (!extension_loaded('array_extend')) {
    echo 'skip';
}
?>
--FILE--
<?php
$a = [2, 4, 6, 8];
var_dump(array_search_uassoc($a, function ($item) {
    if (6 == $item) {
        return true;
    }
}));
?>
--EXPECT--
int(2)