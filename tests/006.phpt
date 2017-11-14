--TEST--
array_reject() Basic TEST
--SKIPIF--
<?php
if (!extension_loaded('array_extend')) {
    echo 'skip';
}
?>
--FILE--
<?php
$a = [1, 2, 3, 4, 5, 6];
$b = array_reject($a, function ($value) {
    return $value < 3;
});
foreach ($b as $key => $value) {
    echo $key . $value;
}
?>
--EXPECT--
23344556