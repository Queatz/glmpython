#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "../glm/glm.hpp"

/* Type Definitions */
/*$ BASETYPEDEF $*/

typedef struct {
	PyObject_HEAD
	PyObject *obj;
	Py_ssize_t offset;
} glm_${type}Iterator;

typedef struct {
	PyObject_HEAD
} glm_${type};

/*$ $*/
/*$ VECTOR $*/

typedef struct {
	glm_Vector vector;
	glm::${p}vec${n} vec;
} glm_${p}vec${n};

#define glm_${p}vec${n}Data(o) \
	((glm_${p}vec${n} *)o)->vec

PyObject *glm_${p}vec${n}New(glm::${p}vec${n});
/*$ $*/
/*$ MATRIX $*/

typedef struct {
	glm_Matrix matrix;
	glm::${p}mat${n} mat;
} glm_${p}mat${n};

#define glm_${p}mat${n}Data(o) \
	((glm_${p}mat${n} *)o)->mat

PyObject *glm_${p}mat${n}New(glm::${p}mat${n});
/*$ $*/
