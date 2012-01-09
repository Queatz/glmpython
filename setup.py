#!/usr/bin/env python3

import parseme

TEST = None

glmParse = parseme.Project()

# In the VECTOR section,
# p is a prefix to the name
# n is the number of components in the vector
# type is the common type of the vector
# Make sure to include all three of a type because swizzling relies on them
VECTOR = parseme.Section('VECTOR')
VECTOR.add(parseme.Round(p = '', n = 2, type = 'float'))
VECTOR.add(parseme.Round(p = '', n = 3, type = 'float'))
VECTOR.add(parseme.Round(p = '', n = 4, type = 'float'))
VECTOR.add(parseme.Round(p = 'i', n = 2, type = 'int'))
VECTOR.add(parseme.Round(p = 'i', n = 3, type = 'int'))
VECTOR.add(parseme.Round(p = 'i', n = 4, type = 'int'))
glmParse.add(VECTOR)

# In the MATRIX section,
# p is a prefix to the name
# cols and rows is the size of the vector
# type is the common type of the vector
# n is 'colsxrows'
MATRIX = parseme.Section('MATRIX')
MATRIX.add(parseme.Round(p = '', rows = 2, cols = 2, n = '2', type = 'float'))
MATRIX.add(parseme.Round(p = '', rows = 2, cols = 3, n = '2x3', type = 'float'))
MATRIX.add(parseme.Round(p = '', rows = 3, cols = 2, n = '3x2', type = 'float'))
MATRIX.add(parseme.Round(p = '', rows = 3, cols = 3, n = '3', type = 'float'))
MATRIX.add(parseme.Round(p = '', rows = 2, cols = 4, n = '2x4', type = 'float'))
MATRIX.add(parseme.Round(p = '', rows = 4, cols = 2, n = '4x2', type = 'float'))
MATRIX.add(parseme.Round(p = '', rows = 4, cols = 3, n = '3x4', type = 'float'))
MATRIX.add(parseme.Round(p = '', rows = 3, cols = 4, n = '4x3', type = 'float'))
MATRIX.add(parseme.Round(p = '', rows = 4, cols = 4, n = '4', type = 'float'))
glmParse.add(MATRIX)

# In the MATRIX_FUNCTION section,
# func is the name of the function
# func_doc is the doc string
# args is the type of arguments
# argsT is the build string
# availableTo is which types support it
# path is the glm namespace path

# Matrix Transform

MATRIX_FUNCTION = parseme.Section('MATRIX_FUNCTION')
MATRIX_FUNCTION.add(parseme.Round(
	func = 'translate',
	func_doc = 'Translates a 4x4 matrix.',
	args = ('vec3',),
	argsT = 'O',
	availableTo = ('4',),
	path = '::gtc::matrix_transform'
))
MATRIX_FUNCTION.add(parseme.Round(
	func = 'rotate',
	func_doc = 'Rotates a 4x4 matrix.',
	args = (float, 'vec3',),
	argsT = 'fO',
	availableTo = ('4',),
	path = '::gtc::matrix_transform'
))
MATRIX_FUNCTION.add(parseme.Round(
	func = 'scale',
	func_doc = 'Scales a 4x4 matrix.',
	args = ('vec3',),
	argsT = 'O',
	availableTo = ('4',),
	path = '::gtc::matrix_transform'
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
# path is the path to the function, i.e. ::gtc::matrix_transform
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
		path = '::gtc::matrix_transform'
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
		path = '::gtc::matrix_transform'
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
		path = '::gtc::matrix_transform'
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
		path = '::gtc::matrix_transform'
	)
)

glmParse.add(NUMBER_FUNCTION)

BASETYPEDEF = parseme.Section('BASETYPEDEF')
BASETYPEDEF.add(parseme.Round(type = 'Vector', doc = 'This is a basic vector type that you can isinstance against.  It is also used for global function checking, and in theory you could make your own vector types which define custom calls for global functions.'))
BASETYPEDEF.add(parseme.Round(type = 'Matrix', doc = 'A matrix.'))
glmParse.add(BASETYPEDEF)

if glmParse.parse(*(['test.parseme.cpp'] if TEST else ['glm_python.parseme.hpp', 'glm_python.parseme.cpp'])) > 0:
	raise SystemExit

if TEST is not None:
	raise SystemExit

import shutil, os
from distutils.core import setup, Extension

glm = Extension('glm', sources = ['glm_python.cpp'])

setup(name='glm',
      version='0.9.3',
      description='glm',
      author='JacobF | G-Truc Creation',
      author_email='queatz@gmail.com | glm@g-truc.net',
      url='http://glm.g-truc.net/',
      ext_modules=[glm]
)

shutil.copyfile('build/lib.linux-x86_64-3.2/glm.cpython-32mu.so', 'glm.so')
#os.remove('glm_python.cpp')
