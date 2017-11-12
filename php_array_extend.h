/* array_extend extension for PHP */

#ifndef PHP_ARRAY_EXTEND_H
# define PHP_ARRAY_EXTEND_H

PHP_FUNCTION(array_every);

extern zend_module_entry array_extend_module_entry;
# define phpext_array_extend_ptr &array_extend_module_entry

# define PHP_ARRAY_EXTEND_VERSION "0.1.0"

# if defined(ZTS) && defined(COMPILE_DL_ARRAY_EXTEND)
ZEND_TSRMLS_CACHE_EXTERN()
# endif

#endif	/* PHP_ARRAY_EXTEND_H */
