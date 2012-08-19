#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "../glm/glm.hpp"

/* Type Definitions */

typedef struct {
	PyObject_HEAD
	PyObject *obj;
	Py_ssize_t offset;
} glm_VectorIterator;

typedef struct {
	PyObject_HEAD
} glm_Vector;


typedef struct {
	PyObject_HEAD
	PyObject *obj;
	Py_ssize_t offset;
} glm_MatrixIterator;

typedef struct {
	PyObject_HEAD
} glm_Matrix;


typedef struct {
	glm_Vector vector;
	glm::vec2 vec;
} glm_vec2;

#define glm_vec2Data(o) \
	((glm_vec2 *)o)->vec

PyObject *glm_vec2New(glm::vec2);

typedef struct {
	glm_Vector vector;
	glm::vec3 vec;
} glm_vec3;

#define glm_vec3Data(o) \
	((glm_vec3 *)o)->vec

PyObject *glm_vec3New(glm::vec3);

typedef struct {
	glm_Vector vector;
	glm::vec4 vec;
} glm_vec4;

#define glm_vec4Data(o) \
	((glm_vec4 *)o)->vec

PyObject *glm_vec4New(glm::vec4);

typedef struct {
	glm_Vector vector;
	glm::ivec2 vec;
} glm_ivec2;

#define glm_ivec2Data(o) \
	((glm_ivec2 *)o)->vec

PyObject *glm_ivec2New(glm::ivec2);

typedef struct {
	glm_Vector vector;
	glm::ivec3 vec;
} glm_ivec3;

#define glm_ivec3Data(o) \
	((glm_ivec3 *)o)->vec

PyObject *glm_ivec3New(glm::ivec3);

typedef struct {
	glm_Vector vector;
	glm::ivec4 vec;
} glm_ivec4;

#define glm_ivec4Data(o) \
	((glm_ivec4 *)o)->vec

PyObject *glm_ivec4New(glm::ivec4);

typedef struct {
	glm_Matrix matrix;
	glm::mat2 mat;
} glm_mat2;

#define glm_mat2Data(o) \
	((glm_mat2 *)o)->mat

PyObject *glm_mat2New(glm::mat2);

typedef struct {
	glm_Matrix matrix;
	glm::mat3x2 mat;
} glm_mat3x2;

#define glm_mat3x2Data(o) \
	((glm_mat3x2 *)o)->mat

PyObject *glm_mat3x2New(glm::mat3x2);

typedef struct {
	glm_Matrix matrix;
	glm::mat4x2 mat;
} glm_mat4x2;

#define glm_mat4x2Data(o) \
	((glm_mat4x2 *)o)->mat

PyObject *glm_mat4x2New(glm::mat4x2);

typedef struct {
	glm_Matrix matrix;
	glm::mat2x3 mat;
} glm_mat2x3;

#define glm_mat2x3Data(o) \
	((glm_mat2x3 *)o)->mat

PyObject *glm_mat2x3New(glm::mat2x3);

typedef struct {
	glm_Matrix matrix;
	glm::mat3 mat;
} glm_mat3;

#define glm_mat3Data(o) \
	((glm_mat3 *)o)->mat

PyObject *glm_mat3New(glm::mat3);

typedef struct {
	glm_Matrix matrix;
	glm::mat4x3 mat;
} glm_mat4x3;

#define glm_mat4x3Data(o) \
	((glm_mat4x3 *)o)->mat

PyObject *glm_mat4x3New(glm::mat4x3);

typedef struct {
	glm_Matrix matrix;
	glm::mat2x4 mat;
} glm_mat2x4;

#define glm_mat2x4Data(o) \
	((glm_mat2x4 *)o)->mat

PyObject *glm_mat2x4New(glm::mat2x4);

typedef struct {
	glm_Matrix matrix;
	glm::mat3x4 mat;
} glm_mat3x4;

#define glm_mat3x4Data(o) \
	((glm_mat3x4 *)o)->mat

PyObject *glm_mat3x4New(glm::mat3x4);

typedef struct {
	glm_Matrix matrix;
	glm::mat4 mat;
} glm_mat4;

#define glm_mat4Data(o) \
	((glm_mat4 *)o)->mat

PyObject *glm_mat4New(glm::mat4);
