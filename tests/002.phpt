--TEST--
array_extend_test1() Basic test
--SKIPIF--
<?php
if (!extension_loaded('array_extend')) {
	echo 'skip';
}
?>
--FILE--
<?php 
$ret = array_extend_test1();

var_dump($ret);
?>
--EXPECT--
The extension array_extend is loaded and working!
NULL
