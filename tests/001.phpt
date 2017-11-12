--TEST--
Check if array_extend is loaded
--SKIPIF--
<?php
if (!extension_loaded('array_extend')) {
	echo 'skip';
}
?>
--FILE--
<?php 
echo 'The extension "array_extend" is available';
?>
--EXPECT--
The extension "array_extend" is available
