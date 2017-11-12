/* array_extend extension for PHP */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "ext/standard/info.h"
#include "php_array_extend.h"

/* {{{ void array_extend_test1()
 */
PHP_FUNCTION(array_extend_test1)
{
	// ZEND_PARSE_PARAMETERS_NONE();

	php_printf("The extension %s is loaded and working!\r\n", "array_extend");
}
/* }}} */

/* {{{ string array_extend_test2( [ string $var ] )
 */
PHP_FUNCTION(array_extend_test2)
{
	char *var = "World";
	size_t var_len = sizeof("World") - 1;
	zend_string *retval;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STRING(var, var_len)
	ZEND_PARSE_PARAMETERS_END();

	retval = strpprintf(0, "Hello %s", var);

	RETURN_STR(retval);
}
/* }}}*/

PHP_FUNCTION(array_every)
{
	zval *input = NULL;
	zend_array *ht;
	zval *item;
	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache = empty_fcall_info_cache;
	zval fci_args[1];
	zval retval;

	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_ARRAY(input)
		Z_PARAM_FUNC(fci, fci_cache)
	ZEND_PARSE_PARAMETERS_END();

	ht = Z_ARRVAL_P(input);

	ZEND_HASH_FOREACH_VAL(ht, item) {
		ZVAL_COPY(&fci_args[0], item);
		zend_fcall_info_argp(&fci, 1, fci_args);
		zend_fcall_info_call(&fci, &fci_cache, &retval, NULL);
		if (Z_TYPE_INFO(retval) == IS_FALSE)
		{
			RETURN_FALSE;
		}
	} ZEND_HASH_FOREACH_END();

	RETURN_TRUE;
}

PHP_FUNCTION(array_search_uassoc)
{
	zval *input = NULL;
	zend_array *ht;
	zval *item;
	zend_ulong h;
	zend_string *key;
	zend_fcall_info fci;
	zend_fcall_info_cache fci_cache = empty_fcall_info_cache;
	zval fci_retval;
	zval fci_args[1];
	
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_ARRAY(input)
		Z_PARAM_FUNC(fci, fci_cache)
	ZEND_PARSE_PARAMETERS_END();

	ht = Z_ARRVAL_P(input);

	ZEND_HASH_FOREACH_KEY_VAL(ht, h, key, item) {
		ZVAL_COPY(&fci_args[0], item);
		zend_fcall_info_argp(&fci, 1, fci_args);
		zend_fcall_info_call(&fci, &fci_cache, &fci_retval, NULL);
		if (Z_TYPE_INFO(fci_retval) == IS_TRUE)
		{
			if (key)
			{
				RETURN_STR(key);
			}
			else
			{
				RETURN_LONG(h)
			}
		}
	} ZEND_HASH_FOREACH_END();

	RETURN_FALSE;
}

/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(array_extend)
{
#if defined(ZTS) && defined(COMPILE_DL_ARRAY_EXTEND)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(array_extend)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "array_extend support", "enabled");
	php_info_print_table_end();
}
/* }}} */

/* {{{ arginfo
 */
ZEND_BEGIN_ARG_INFO(arginfo_array_extend_test1, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO(arginfo_array_extend_test2, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

// ZEND_BEGIN_ARG_INFO(arginfo_array_every, 0)
// ZEND_END_ARG_INFO()
/* }}} */

/* {{{ array_extend_functions[]
 */
const zend_function_entry array_extend_functions[] = {
	PHP_FE(array_extend_test1,		arginfo_array_extend_test1)
	PHP_FE(array_extend_test2,		arginfo_array_extend_test2)
	PHP_FE(array_every,             NULL)
	PHP_FE(array_search_uassoc,     NULL)
	PHP_FE_END
};
/* }}} */

/* {{{ array_extend_module_entry
 */
zend_module_entry array_extend_module_entry = {
	STANDARD_MODULE_HEADER,
	"array_extend",					/* Extension name */
	array_extend_functions,			/* zend_function_entry */
	NULL,							/* PHP_MINIT - Module initialization */
	NULL,							/* PHP_MSHUTDOWN - Module shutdown */
	PHP_RINIT(array_extend),			/* PHP_RINIT - Request initialization */
	NULL,							/* PHP_RSHUTDOWN - Request shutdown */
	PHP_MINFO(array_extend),			/* PHP_MINFO - Module info */
	PHP_ARRAY_EXTEND_VERSION,		/* Version */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_ARRAY_EXTEND
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(array_extend)
#endif
