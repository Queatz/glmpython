#!/usr/bin/env python3

import parseme

glmParse = parseme.Project()

# In the VECTOR section,
# p is a prefix to the name
# n is the number of components in the vector
# type is the common type of the vector
# Make sure to include all three of a type because swizzling relies on them
VECTOR = parseme.Section('VECTOR')
for t in (('', 'float'), ('i', 'int')):
	for n in range(2, 5):
		VECTOR.add(parseme.Round(p = t[0], n = n, type = t[1]))
glmParse.add(VECTOR)

VECTOR_MATH = parseme.Section('VECTOR_MATH')
VECTOR_MATH.add(parseme.Round(s = '+', f = 'add', only = None))
VECTOR_MATH.add(parseme.Round(s = '-', f = 'subtract', only = None))
VECTOR_MATH.add(parseme.Round(s = '*', f = 'multiply', only = None))
VECTOR_MATH.add(parseme.Round(s = '/', f = 'true_divide', only = None))
VECTOR_MATH.add(parseme.Round(s = '<<', f = 'lshift', only = 'int'))
VECTOR_MATH.add(parseme.Round(s = '>>', f = 'rshift', only = 'int'))
VECTOR_MATH.add(parseme.Round(s = '&', f = 'and', only = 'int'))
VECTOR_MATH.add(parseme.Round(s = '^', f = 'xor', only = 'int'))
VECTOR_MATH.add(parseme.Round(s = '|', f = 'or', only = 'int'))

glmParse.add(VECTOR_MATH)

# In the MATRIX section,
# p is a prefix to the name
# cols and rows is the size of the vector
# type is the common type of the vector
# n is is the name, such as 3x4
MATRIX = parseme.Section('MATRIX')
for cols in range(2, 5):
	for rows in range(2, 5):
		MATRIX.add(parseme.Round(p = '', rows = rows, cols = cols,
			n = (str(rows) if rows == cols else str(rows) + 'x' + str(cols)), type = 'float'))
glmParse.add(MATRIX)

# In the MATRIX_FUNCTION section,
# func is the name of the function
# func_doc is the doc string
# args is the type of arguments
# availableTo is which types support it
# path is the glm namespace path

# Matrix Transform

MATRIX_FUNCTION = parseme.Section('MATRIX_FUNCTION')
MATRIX_FUNCTION.add(parseme.Round(
	func = 'translate',
	func_doc = 'Translates a 4x4 matrix.',
	args = ('vec3',),
	availableTo = ('4',),
	path = ''
))
MATRIX_FUNCTION.add(parseme.Round(
	func = 'rotate',
	func_doc = 'Rotates a 4x4 matrix.',
	args = (float, 'vec3',),
	availableTo = ('4',),
	path = ''
))
MATRIX_FUNCTION.add(parseme.Round(
	func = 'scale',
	func_doc = 'Scales a 4x4 matrix.',
	args = ('vec3',),
	availableTo = ('4',),
	path = ''
))

# Core

MATRIX_FUNCTION.add(parseme.Round(
	func = 'inverse',
	func_doc = 'Matrix\'s inverse.',
	args = (),
	argsT = '',
	availableTo = ('2','3','4',),
	path = ''
))

glmParse.add(MATRIX_FUNCTION)

# In the VECTOR_FUNCTION section,
# func is the name of the function
# func_doc is the doc string
VECTOR_FUNCTION = parseme.Section('VECTOR_FUNCTION')
VECTOR_FUNCTION.add(parseme.Round(func = 'abs', func_doc = 'Absolute value.'))
glmParse.add(VECTOR_FUNCTION)

# In the NUMBER_FUNCTION section,
# func is the name of the function
# func_doc is the doc string
# argc is the number of arguments
# argoc is the number of optional arguments
# returns is the return type
# type is the argument type
# p is the short name of the in type, used to build value
# base the base type of the return
# path is the path to the function, i.e. 
NUMBER_FUNCTION = parseme.Section('NUMBER_FUNCTION')

NUMBER_FUNCTION.add(
	parseme.Round(
		func = 'ortho',
		func_doc = 'Creates an orthographic matrix.',
		argc = 4,
		argoc = 2,
		returns = 'mat4',
		type = 'float',
		p = 'f',
		base = 'mat',
		path = ''
	)
)

NUMBER_FUNCTION.add(
	parseme.Round(
		func = 'frustum',
		func_doc = 'Creates a frustum matrix.',
		argc = 6,
		argoc = 0,
		returns = 'mat4',
		type = 'float',
		p = 'f',
		base = 'mat',
		path = ''
	)
)

NUMBER_FUNCTION.add(
	parseme.Round(
		func = 'perspective',
		func_doc = 'Creates a perspective matrix.',
		argc = 4,
		argoc = 0,
		returns = 'mat4',
		type = 'float',
		p = 'f',
		base = 'mat',
		path = ''
	)
)

NUMBER_FUNCTION.add(
	parseme.Round(
		func = 'perspectiveFov',
		func_doc = 'Creates a perspective matrix with a defined FOV.',
		argc = 5,
		argoc = 0,
		returns = 'mat4',
		type = 'float',
		p = 'f',
		base = 'mat',
		path = ''
	)
)

glmParse.add(NUMBER_FUNCTION)

BASETYPEDEF = parseme.Section('BASETYPEDEF')
BASETYPEDEF.add(parseme.Round(type = 'Vector', doc = 'This is a basic vector type that you can isinstance against.  It is also used for global function checking, and in theory you could make your own vector types which define custom calls for global functions.'))
BASETYPEDEF.add(parseme.Round(type = 'Matrix', doc = 'A matrix.'))
glmParse.add(BASETYPEDEF)

if glmParse.parse('python.parseme.hpp', 'python.parseme.cpp') > 0:
	raise SystemExit

import shutil, os
from distutils.core import setup, Extension

glm = Extension('glm', sources = ['python.cpp'])

setup(name='glm',
      version='0.9.3',
      description='glm',
      author='JacobF | G-Truc Creation',
      author_email='queatz@gmail.com | glm@g-truc.net',
      url='http://glm.g-truc.net/',
      ext_modules=[glm]
)
