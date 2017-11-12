PHP_ARG_ENABLE(array_extend, whether to enable array_extend support,
[  --enable-array_extend          Enable array_extend support], no)

if test "$PHP_ARRAY_EXTEND" != "no"; then
  AC_DEFINE(HAVE_ARRAY_EXTEND, 1, [ Have array_extend support ])
  PHP_NEW_EXTENSION(array_extend, array_extend.c, $ext_shared)
fi
