#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "../glm/glm.hpp"
#include <sstream>
#include "../glm/ext.hpp"

#include "python.hpp"

/* * * Header * * */

/* mat2 */

static PyObject *glm_mat2_nb_add(PyObject *, PyObject *);
static PyObject *glm_mat2_nb_subtract(PyObject *, PyObject *);
static PyObject *glm_mat2_nb_multiply(PyObject *, PyObject *);
static PyObject *glm_mat2_nb_true_divide(PyObject *, PyObject *);

static PyObject *glm_mat2_nb_negative(PyObject *);
static PyObject *glm_mat2_nb_positive(PyObject *);

static PyObject *glm_mat2_nb_inplace_add(PyObject *, PyObject *);
static PyObject *glm_mat2_nb_inplace_subtract(PyObject *, PyObject *);
static PyObject *glm_mat2_nb_inplace_multiply(PyObject *, PyObject *);
static PyObject *glm_mat2_nb_inplace_true_divide(PyObject *, PyObject *);

static Py_ssize_t glm_mat2_sq_length(PyObject *);
static PyObject *glm_mat2_sq_item(PyObject *, Py_ssize_t);
static int glm_mat2_sq_ass_item(PyObject *, Py_ssize_t, PyObject *);

static PyObject *glm_mat2_tp_repr(PyObject *);
static int glm_mat2_tp_init(PyObject *, PyObject *, PyObject *);

static int glm_mat2_bf_getbuffer(PyObject *, Py_buffer *, int);

static PyObject *glm_mat2_tp_richcompare(PyObject *, PyObject *, int);
static Py_hash_t glm_mat2_tp_hash(PyObject *);

/* mat3x2 */

static PyObject *glm_mat3x2_nb_add(PyObject *, PyObject *);
static PyObject *glm_mat3x2_nb_subtract(PyObject *, PyObject *);
static PyObject *glm_mat3x2_nb_multiply(PyObject *, PyObject *);
static PyObject *glm_mat3x2_nb_true_divide(PyObject *, PyObject *);

static PyObject *glm_mat3x2_nb_negative(PyObject *);
static PyObject *glm_mat3x2_nb_positive(PyObject *);

static PyObject *glm_mat3x2_nb_inplace_add(PyObject *, PyObject *);
static PyObject *glm_mat3x2_nb_inplace_subtract(PyObject *, PyObject *);
static PyObject *glm_mat3x2_nb_inplace_multiply(PyObject *, PyObject *);
static PyObject *glm_mat3x2_nb_inplace_true_divide(PyObject *, PyObject *);

static Py_ssize_t glm_mat3x2_sq_length(PyObject *);
static PyObject *glm_mat3x2_sq_item(PyObject *, Py_ssize_t);
static int glm_mat3x2_sq_ass_item(PyObject *, Py_ssize_t, PyObject *);

static PyObject *glm_mat3x2_tp_repr(PyObject *);
static int glm_mat3x2_tp_init(PyObject *, PyObject *, PyObject *);

static int glm_mat3x2_bf_getbuffer(PyObject *, Py_buffer *, int);

static PyObject *glm_mat3x2_tp_richcompare(PyObject *, PyObject *, int);
static Py_hash_t glm_mat3x2_tp_hash(PyObject *);

/* mat4x2 */

static PyObject *glm_mat4x2_nb_add(PyObject *, PyObject *);
static PyObject *glm_mat4x2_nb_subtract(PyObject *, PyObject *);
static PyObject *glm_mat4x2_nb_multiply(PyObject *, PyObject *);
static PyObject *glm_mat4x2_nb_true_divide(PyObject *, PyObject *);

static PyObject *glm_mat4x2_nb_negative(PyObject *);
static PyObject *glm_mat4x2_nb_positive(PyObject *);

static PyObject *glm_mat4x2_nb_inplace_add(PyObject *, PyObject *);
static PyObject *glm_mat4x2_nb_inplace_subtract(PyObject *, PyObject *);
static PyObject *glm_mat4x2_nb_inplace_multiply(PyObject *, PyObject *);
static PyObject *glm_mat4x2_nb_inplace_true_divide(PyObject *, PyObject *);

static Py_ssize_t glm_mat4x2_sq_length(PyObject *);
static PyObject *glm_mat4x2_sq_item(PyObject *, Py_ssize_t);
static int glm_mat4x2_sq_ass_item(PyObject *, Py_ssize_t, PyObject *);

static PyObject *glm_mat4x2_tp_repr(PyObject *);
static int glm_mat4x2_tp_init(PyObject *, PyObject *, PyObject *);

static int glm_mat4x2_bf_getbuffer(PyObject *, Py_buffer *, int);

static PyObject *glm_mat4x2_tp_richcompare(PyObject *, PyObject *, int);
static Py_hash_t glm_mat4x2_tp_hash(PyObject *);

/* mat2x3 */

static PyObject *glm_mat2x3_nb_add(PyObject *, PyObject *);
static PyObject *glm_mat2x3_nb_subtract(PyObject *, PyObject *);
static PyObject *glm_mat2x3_nb_multiply(PyObject *, PyObject *);
static PyObject *glm_mat2x3_nb_true_divide(PyObject *, PyObject *);

static PyObject *glm_mat2x3_nb_negative(PyObject *);
static PyObject *glm_mat2x3_nb_positive(PyObject *);

static PyObject *glm_mat2x3_nb_inplace_add(PyObject *, PyObject *);
static PyObject *glm_mat2x3_nb_inplace_subtract(PyObject *, PyObject *);
static PyObject *glm_mat2x3_nb_inplace_multiply(PyObject *, PyObject *);
static PyObject *glm_mat2x3_nb_inplace_true_divide(PyObject *, PyObject *);

static Py_ssize_t glm_mat2x3_sq_length(PyObject *);
static PyObject *glm_mat2x3_sq_item(PyObject *, Py_ssize_t);
static int glm_mat2x3_sq_ass_item(PyObject *, Py_ssize_t, PyObject *);

static PyObject *glm_mat2x3_tp_repr(PyObject *);
static int glm_mat2x3_tp_init(PyObject *, PyObject *, PyObject *);

static int glm_mat2x3_bf_getbuffer(PyObject *, Py_buffer *, int);

static PyObject *glm_mat2x3_tp_richcompare(PyObject *, PyObject *, int);
static Py_hash_t glm_mat2x3_tp_hash(PyObject *);

/* mat3 */

static PyObject *glm_mat3_nb_add(PyObject *, PyObject *);
static PyObject *glm_mat3_nb_subtract(PyObject *, PyObject *);
static PyObject *glm_mat3_nb_multiply(PyObject *, PyObject *);
static PyObject *glm_mat3_nb_true_divide(PyObject *, PyObject *);

static PyObject *glm_mat3_nb_negative(PyObject *);
static PyObject *glm_mat3_nb_positive(PyObject *);

static PyObject *glm_mat3_nb_inplace_add(PyObject *, PyObject *);
static PyObject *glm_mat3_nb_inplace_subtract(PyObject *, PyObject *);
static PyObject *glm_mat3_nb_inplace_multiply(PyObject *, PyObject *);
static PyObject *glm_mat3_nb_inplace_true_divide(PyObject *, PyObject *);

static Py_ssize_t glm_mat3_sq_length(PyObject *);
static PyObject *glm_mat3_sq_item(PyObject *, Py_ssize_t);
static int glm_mat3_sq_ass_item(PyObject *, Py_ssize_t, PyObject *);

static PyObject *glm_mat3_tp_repr(PyObject *);
static int glm_mat3_tp_init(PyObject *, PyObject *, PyObject *);

static int glm_mat3_bf_getbuffer(PyObject *, Py_buffer *, int);

static PyObject *glm_mat3_tp_richcompare(PyObject *, PyObject *, int);
static Py_hash_t glm_mat3_tp_hash(PyObject *);

/* mat4x3 */

static PyObject *glm_mat4x3_nb_add(PyObject *, PyObject *);
static PyObject *glm_mat4x3_nb_subtract(PyObject *, PyObject *);
static PyObject *glm_mat4x3_nb_multiply(PyObject *, PyObject *);
static PyObject *glm_mat4x3_nb_true_divide(PyObject *, PyObject *);

static PyObject *glm_mat4x3_nb_negative(PyObject *);
static PyObject *glm_mat4x3_nb_positive(PyObject *);

static PyObject *glm_mat4x3_nb_inplace_add(PyObject *, PyObject *);
static PyObject *glm_mat4x3_nb_inplace_subtract(PyObject *, PyObject *);
static PyObject *glm_mat4x3_nb_inplace_multiply(PyObject *, PyObject *);
static PyObject *glm_mat4x3_nb_inplace_true_divide(PyObject *, PyObject *);

static Py_ssize_t glm_mat4x3_sq_length(PyObject *);
static PyObject *glm_mat4x3_sq_item(PyObject *, Py_ssize_t);
static int glm_mat4x3_sq_ass_item(PyObject *, Py_ssize_t, PyObject *);

static PyObject *glm_mat4x3_tp_repr(PyObject *);
static int glm_mat4x3_tp_init(PyObject *, PyObject *, PyObject *);

static int glm_mat4x3_bf_getbuffer(PyObject *, Py_buffer *, int);

static PyObject *glm_mat4x3_tp_richcompare(PyObject *, PyObject *, int);
static Py_hash_t glm_mat4x3_tp_hash(PyObject *);

/* mat2x4 */

static PyObject *glm_mat2x4_nb_add(PyObject *, PyObject *);
static PyObject *glm_mat2x4_nb_subtract(PyObject *, PyObject *);
static PyObject *glm_mat2x4_nb_multiply(PyObject *, PyObject *);
static PyObject *glm_mat2x4_nb_true_divide(PyObject *, PyObject *);

static PyObject *glm_mat2x4_nb_negative(PyObject *);
static PyObject *glm_mat2x4_nb_positive(PyObject *);

static PyObject *glm_mat2x4_nb_inplace_add(PyObject *, PyObject *);
static PyObject *glm_mat2x4_nb_inplace_subtract(PyObject *, PyObject *);
static PyObject *glm_mat2x4_nb_inplace_multiply(PyObject *, PyObject *);
static PyObject *glm_mat2x4_nb_inplace_true_divide(PyObject *, PyObject *);

static Py_ssize_t glm_mat2x4_sq_length(PyObject *);
static PyObject *glm_mat2x4_sq_item(PyObject *, Py_ssize_t);
static int glm_mat2x4_sq_ass_item(PyObject *, Py_ssize_t, PyObject *);

static PyObject *glm_mat2x4_tp_repr(PyObject *);
static int glm_mat2x4_tp_init(PyObject *, PyObject *, PyObject *);

static int glm_mat2x4_bf_getbuffer(PyObject *, Py_buffer *, int);

static PyObject *glm_mat2x4_tp_richcompare(PyObject *, PyObject *, int);
static Py_hash_t glm_mat2x4_tp_hash(PyObject *);

/* mat3x4 */

static PyObject *glm_mat3x4_nb_add(PyObject *, PyObject *);
static PyObject *glm_mat3x4_nb_subtract(PyObject *, PyObject *);
static PyObject *glm_mat3x4_nb_multiply(PyObject *, PyObject *);
static PyObject *glm_mat3x4_nb_true_divide(PyObject *, PyObject *);

static PyObject *glm_mat3x4_nb_negative(PyObject *);
static PyObject *glm_mat3x4_nb_positive(PyObject *);

static PyObject *glm_mat3x4_nb_inplace_add(PyObject *, PyObject *);
static PyObject *glm_mat3x4_nb_inplace_subtract(PyObject *, PyObject *);
static PyObject *glm_mat3x4_nb_inplace_multiply(PyObject *, PyObject *);
static PyObject *glm_mat3x4_nb_inplace_true_divide(PyObject *, PyObject *);

static Py_ssize_t glm_mat3x4_sq_length(PyObject *);
static PyObject *glm_mat3x4_sq_item(PyObject *, Py_ssize_t);
static int glm_mat3x4_sq_ass_item(PyObject *, Py_ssize_t, PyObject *);

static PyObject *glm_mat3x4_tp_repr(PyObject *);
static int glm_mat3x4_tp_init(PyObject *, PyObject *, PyObject *);

static int glm_mat3x4_bf_getbuffer(PyObject *, Py_buffer *, int);

static PyObject *glm_mat3x4_tp_richcompare(PyObject *, PyObject *, int);
static Py_hash_t glm_mat3x4_tp_hash(PyObject *);

/* mat4 */

static PyObject *glm_mat4_nb_add(PyObject *, PyObject *);
static PyObject *glm_mat4_nb_subtract(PyObject *, PyObject *);
static PyObject *glm_mat4_nb_multiply(PyObject *, PyObject *);
static PyObject *glm_mat4_nb_true_divide(PyObject *, PyObject *);

static PyObject *glm_mat4_nb_negative(PyObject *);
static PyObject *glm_mat4_nb_positive(PyObject *);

static PyObject *glm_mat4_nb_inplace_add(PyObject *, PyObject *);
static PyObject *glm_mat4_nb_inplace_subtract(PyObject *, PyObject *);
static PyObject *glm_mat4_nb_inplace_multiply(PyObject *, PyObject *);
static PyObject *glm_mat4_nb_inplace_true_divide(PyObject *, PyObject *);

static Py_ssize_t glm_mat4_sq_length(PyObject *);
static PyObject *glm_mat4_sq_item(PyObject *, Py_ssize_t);
static int glm_mat4_sq_ass_item(PyObject *, Py_ssize_t, PyObject *);

static PyObject *glm_mat4_tp_repr(PyObject *);
static int glm_mat4_tp_init(PyObject *, PyObject *, PyObject *);

static int glm_mat4_bf_getbuffer(PyObject *, Py_buffer *, int);

static PyObject *glm_mat4_tp_richcompare(PyObject *, PyObject *, int);
static Py_hash_t glm_mat4_tp_hash(PyObject *);

/* vec2 */


static PyObject *glm_vec2_nb_add(PyObject *, PyObject *);
static PyObject *glm_vec2_nb_inplace_add(PyObject *, PyObject *);
static PyObject *glm_vec2_nb_subtract(PyObject *, PyObject *);
static PyObject *glm_vec2_nb_inplace_subtract(PyObject *, PyObject *);
static PyObject *glm_vec2_nb_multiply(PyObject *, PyObject *);
static PyObject *glm_vec2_nb_inplace_multiply(PyObject *, PyObject *);
static PyObject *glm_vec2_nb_true_divide(PyObject *, PyObject *);
static PyObject *glm_vec2_nb_inplace_true_divide(PyObject *, PyObject *);
static PyObject *glm_vec2_nb_remainder(PyObject *, PyObject *);
static PyObject *glm_vec2_nb_divmod(PyObject *, PyObject *);
static PyObject *glm_vec2_nb_power(PyObject *, PyObject *);
static PyObject *glm_vec2_nb_negative(PyObject *);
static PyObject *glm_vec2_nb_positive(PyObject *);
static PyObject *glm_vec2_nb_absolute(PyObject *);

static PyObject *glm_vec2_nb_floor_divide(PyObject *, PyObject *);
static PyObject *glm_vec2_nb_inplace_floor_divide(PyObject *, PyObject *);

static Py_ssize_t glm_vec2_sq_length(PyObject *);
static PyObject *glm_vec2_sq_item(PyObject *, Py_ssize_t);
static int glm_vec2_sq_ass_item(PyObject *, Py_ssize_t, PyObject *);

static PyObject *glm_vec2_tp_repr(PyObject *);
static PyObject *glm_vec2_tp_getattro(PyObject *, PyObject *);
static int glm_vec2_tp_setattro(PyObject *, PyObject *, PyObject *);
static int glm_vec2_tp_init(PyObject *, PyObject *, PyObject *);

static int glm_vec2_bf_getbuffer(PyObject *, Py_buffer *, int);

static PyObject *glm_vec2_tp_richcompare(PyObject *, PyObject *, int);
static Py_hash_t glm_vec2_tp_hash(PyObject *);

/* vec3 */


static PyObject *glm_vec3_nb_add(PyObject *, PyObject *);
static PyObject *glm_vec3_nb_inplace_add(PyObject *, PyObject *);
static PyObject *glm_vec3_nb_subtract(PyObject *, PyObject *);
static PyObject *glm_vec3_nb_inplace_subtract(PyObject *, PyObject *);
static PyObject *glm_vec3_nb_multiply(PyObject *, PyObject *);
static PyObject *glm_vec3_nb_inplace_multiply(PyObject *, PyObject *);
static PyObject *glm_vec3_nb_true_divide(PyObject *, PyObject *);
static PyObject *glm_vec3_nb_inplace_true_divide(PyObject *, PyObject *);
static PyObject *glm_vec3_nb_remainder(PyObject *, PyObject *);
static PyObject *glm_vec3_nb_divmod(PyObject *, PyObject *);
static PyObject *glm_vec3_nb_power(PyObject *, PyObject *);
static PyObject *glm_vec3_nb_negative(PyObject *);
static PyObject *glm_vec3_nb_positive(PyObject *);
static PyObject *glm_vec3_nb_absolute(PyObject *);

static PyObject *glm_vec3_nb_floor_divide(PyObject *, PyObject *);
static PyObject *glm_vec3_nb_inplace_floor_divide(PyObject *, PyObject *);

static Py_ssize_t glm_vec3_sq_length(PyObject *);
static PyObject *glm_vec3_sq_item(PyObject *, Py_ssize_t);
static int glm_vec3_sq_ass_item(PyObject *, Py_ssize_t, PyObject *);

static PyObject *glm_vec3_tp_repr(PyObject *);
static PyObject *glm_vec3_tp_getattro(PyObject *, PyObject *);
static int glm_vec3_tp_setattro(PyObject *, PyObject *, PyObject *);
static int glm_vec3_tp_init(PyObject *, PyObject *, PyObject *);

static int glm_vec3_bf_getbuffer(PyObject *, Py_buffer *, int);

static PyObject *glm_vec3_tp_richcompare(PyObject *, PyObject *, int);
static Py_hash_t glm_vec3_tp_hash(PyObject *);

/* vec4 */


static PyObject *glm_vec4_nb_add(PyObject *, PyObject *);
static PyObject *glm_vec4_nb_inplace_add(PyObject *, PyObject *);
static PyObject *glm_vec4_nb_subtract(PyObject *, PyObject *);
static PyObject *glm_vec4_nb_inplace_subtract(PyObject *, PyObject *);
static PyObject *glm_vec4_nb_multiply(PyObject *, PyObject *);
static PyObject *glm_vec4_nb_inplace_multiply(PyObject *, PyObject *);
static PyObject *glm_vec4_nb_true_divide(PyObject *, PyObject *);
static PyObject *glm_vec4_nb_inplace_true_divide(PyObject *, PyObject *);
static PyObject *glm_vec4_nb_remainder(PyObject *, PyObject *);
static PyObject *glm_vec4_nb_divmod(PyObject *, PyObject *);
static PyObject *glm_vec4_nb_power(PyObject *, PyObject *);
static PyObject *glm_vec4_nb_negative(PyObject *);
static PyObject *glm_vec4_nb_positive(PyObject *);
static PyObject *glm_vec4_nb_absolute(PyObject *);

static PyObject *glm_vec4_nb_floor_divide(PyObject *, PyObject *);
static PyObject *glm_vec4_nb_inplace_floor_divide(PyObject *, PyObject *);

static Py_ssize_t glm_vec4_sq_length(PyObject *);
static PyObject *glm_vec4_sq_item(PyObject *, Py_ssize_t);
static int glm_vec4_sq_ass_item(PyObject *, Py_ssize_t, PyObject *);

static PyObject *glm_vec4_tp_repr(PyObject *);
static PyObject *glm_vec4_tp_getattro(PyObject *, PyObject *);
static int glm_vec4_tp_setattro(PyObject *, PyObject *, PyObject *);
static int glm_vec4_tp_init(PyObject *, PyObject *, PyObject *);

static int glm_vec4_bf_getbuffer(PyObject *, Py_buffer *, int);

static PyObject *glm_vec4_tp_richcompare(PyObject *, PyObject *, int);
static Py_hash_t glm_vec4_tp_hash(PyObject *);

/* ivec2 */


static PyObject *glm_ivec2_nb_add(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_inplace_add(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_subtract(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_inplace_subtract(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_multiply(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_inplace_multiply(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_true_divide(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_inplace_true_divide(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_lshift(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_inplace_lshift(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_rshift(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_inplace_rshift(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_and(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_inplace_and(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_xor(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_inplace_xor(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_or(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_inplace_or(PyObject *, PyObject *);
static PyObject *glm_ivec2_nb_negative(PyObject *);
static PyObject *glm_ivec2_nb_positive(PyObject *);
static PyObject *glm_ivec2_nb_absolute(PyObject *);

static PyObject *glm_ivec2_nb_invert(PyObject *);


static Py_ssize_t glm_ivec2_sq_length(PyObject *);
static PyObject *glm_ivec2_sq_item(PyObject *, Py_ssize_t);
static int glm_ivec2_sq_ass_item(PyObject *, Py_ssize_t, PyObject *);

static PyObject *glm_ivec2_tp_repr(PyObject *);
static PyObject *glm_ivec2_tp_getattro(PyObject *, PyObject *);
static int glm_ivec2_tp_setattro(PyObject *, PyObject *, PyObject *);
static int glm_ivec2_tp_init(PyObject *, PyObject *, PyObject *);

static int glm_ivec2_bf_getbuffer(PyObject *, Py_buffer *, int);

static PyObject *glm_ivec2_tp_richcompare(PyObject *, PyObject *, int);
static Py_hash_t glm_ivec2_tp_hash(PyObject *);

/* ivec3 */


static PyObject *glm_ivec3_nb_add(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_inplace_add(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_subtract(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_inplace_subtract(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_multiply(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_inplace_multiply(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_true_divide(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_inplace_true_divide(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_lshift(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_inplace_lshift(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_rshift(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_inplace_rshift(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_and(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_inplace_and(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_xor(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_inplace_xor(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_or(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_inplace_or(PyObject *, PyObject *);
static PyObject *glm_ivec3_nb_negative(PyObject *);
static PyObject *glm_ivec3_nb_positive(PyObject *);
static PyObject *glm_ivec3_nb_absolute(PyObject *);

static PyObject *glm_ivec3_nb_invert(PyObject *);


static Py_ssize_t glm_ivec3_sq_length(PyObject *);
static PyObject *glm_ivec3_sq_item(PyObject *, Py_ssize_t);
static int glm_ivec3_sq_ass_item(PyObject *, Py_ssize_t, PyObject *);

static PyObject *glm_ivec3_tp_repr(PyObject *);
static PyObject *glm_ivec3_tp_getattro(PyObject *, PyObject *);
static int glm_ivec3_tp_setattro(PyObject *, PyObject *, PyObject *);
static int glm_ivec3_tp_init(PyObject *, PyObject *, PyObject *);

static int glm_ivec3_bf_getbuffer(PyObject *, Py_buffer *, int);

static PyObject *glm_ivec3_tp_richcompare(PyObject *, PyObject *, int);
static Py_hash_t glm_ivec3_tp_hash(PyObject *);

/* ivec4 */


static PyObject *glm_ivec4_nb_add(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_inplace_add(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_subtract(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_inplace_subtract(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_multiply(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_inplace_multiply(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_true_divide(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_inplace_true_divide(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_lshift(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_inplace_lshift(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_rshift(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_inplace_rshift(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_and(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_inplace_and(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_xor(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_inplace_xor(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_or(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_inplace_or(PyObject *, PyObject *);
static PyObject *glm_ivec4_nb_negative(PyObject *);
static PyObject *glm_ivec4_nb_positive(PyObject *);
static PyObject *glm_ivec4_nb_absolute(PyObject *);

static PyObject *glm_ivec4_nb_invert(PyObject *);


static Py_ssize_t glm_ivec4_sq_length(PyObject *);
static PyObject *glm_ivec4_sq_item(PyObject *, Py_ssize_t);
static int glm_ivec4_sq_ass_item(PyObject *, Py_ssize_t, PyObject *);

static PyObject *glm_ivec4_tp_repr(PyObject *);
static PyObject *glm_ivec4_tp_getattro(PyObject *, PyObject *);
static int glm_ivec4_tp_setattro(PyObject *, PyObject *, PyObject *);
static int glm_ivec4_tp_init(PyObject *, PyObject *, PyObject *);

static int glm_ivec4_bf_getbuffer(PyObject *, Py_buffer *, int);

static PyObject *glm_ivec4_tp_richcompare(PyObject *, PyObject *, int);
static Py_hash_t glm_ivec4_tp_hash(PyObject *);

/* * * Types * * */

static
PyNumberMethods glm_mat2_NumberMethods = {
	(binaryfunc)glm_mat2_nb_add,
	(binaryfunc)glm_mat2_nb_subtract,
	(binaryfunc)glm_mat2_nb_multiply,
	NULL,
	NULL,
	NULL,
	(unaryfunc)glm_mat2_nb_negative,
	(unaryfunc)glm_mat2_nb_positive,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	(binaryfunc)glm_mat2_nb_inplace_add,
	(binaryfunc)glm_mat2_nb_inplace_subtract,
	(binaryfunc)glm_mat2_nb_inplace_multiply,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	NULL,
	(binaryfunc)glm_mat2_nb_true_divide,
	NULL,
	(binaryfunc)glm_mat2_nb_inplace_true_divide,

	NULL,
};

static
PySequenceMethods glm_mat2_SequenceMethods = {
	(lenfunc)glm_mat2_sq_length,
	NULL,
	NULL,
	(ssizeargfunc)glm_mat2_sq_item,
	NULL,
	(ssizeobjargproc)glm_mat2_sq_ass_item,
	NULL,
	NULL,

	NULL,
	NULL,
};

static
PyBufferProcs glm_mat2_BufferMethods = {
	(getbufferproc)glm_mat2_bf_getbuffer,
	NULL,
};

// mat2 Methods

static PyObject *glm_mat2_function_inverse(PyObject *, PyObject *);

PyDoc_STRVAR(glm_mat2_function_inverse__doc__, "Matrix's inverse.");

static
PyMethodDef glm_mat2Methods[] = {
	{"inverse", (PyCFunction) glm_mat2_function_inverse, METH_NOARGS, glm_mat2_function_inverse__doc__},
	{NULL, NULL},
};

PyDoc_STRVAR(glm_mat2Type__doc__, "A 2x2 matrix.");

// mat2 Object

static
PyTypeObject glm_mat2Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.mat2",										/* tp_name */
	sizeof(glm_mat2),								/* tp_basicsize */
	0,														/* tp_itemsize */
	0,														/* tp_dealloc */
	0,														/* tp_print */
	0,														/* tp_getattr */
	0,														/* tp_setattr */
	0,														/* tp_reserved */
	(reprfunc)glm_mat2_tp_repr,						/* tp_repr */
	&glm_mat2_NumberMethods,							/* tp_as_number */
	&glm_mat2_SequenceMethods,						/* tp_as_sequence */
	0,														/* tp_as_mapping */
	(hashfunc)glm_mat2_tp_hash,						/* tp_hash  */
	0,														/* tp_call */
	0,														/* tp_str */
	PyObject_GenericGetAttr,								/* tp_getattro */
	PyObject_GenericSetAttr,								/* tp_setattro */
	&glm_mat2_BufferMethods,							/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	  Py_TPFLAGS_BASETYPE,									/* tp_flags */
	glm_mat2Type__doc__,								/* tp_doc */
	0,														/* tp_traverse */
	0,														/* tp_clear */
	glm_mat2_tp_richcompare,							/* tp_richcompare */
	0,														/* tp_weaklistoffset */
	0,														/* tp_iter */
	0,														/* tp_iternext */
	glm_mat2Methods,									/* tp_methods */
	0,														/* tp_members */
	0,														/* tp_getset */
	0,														/* tp_base */
	0,														/* tp_dict */
	0,														/* tp_descr_get */
	0,														/* tp_descr_set */
	0,														/* tp_dictoffset */
	(initproc)glm_mat2_tp_init,						/* tp_init */
	0,														/* tp_alloc */
	PyType_GenericNew,										/* tp_new */
};
static
PyNumberMethods glm_mat3x2_NumberMethods = {
	(binaryfunc)glm_mat3x2_nb_add,
	(binaryfunc)glm_mat3x2_nb_subtract,
	(binaryfunc)glm_mat3x2_nb_multiply,
	NULL,
	NULL,
	NULL,
	(unaryfunc)glm_mat3x2_nb_negative,
	(unaryfunc)glm_mat3x2_nb_positive,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	(binaryfunc)glm_mat3x2_nb_inplace_add,
	(binaryfunc)glm_mat3x2_nb_inplace_subtract,
	(binaryfunc)glm_mat3x2_nb_inplace_multiply,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	NULL,
	(binaryfunc)glm_mat3x2_nb_true_divide,
	NULL,
	(binaryfunc)glm_mat3x2_nb_inplace_true_divide,

	NULL,
};

static
PySequenceMethods glm_mat3x2_SequenceMethods = {
	(lenfunc)glm_mat3x2_sq_length,
	NULL,
	NULL,
	(ssizeargfunc)glm_mat3x2_sq_item,
	NULL,
	(ssizeobjargproc)glm_mat3x2_sq_ass_item,
	NULL,
	NULL,

	NULL,
	NULL,
};

static
PyBufferProcs glm_mat3x2_BufferMethods = {
	(getbufferproc)glm_mat3x2_bf_getbuffer,
	NULL,
};

// mat3x2 Methods



static
PyMethodDef glm_mat3x2Methods[] = {
	{NULL, NULL},
};

PyDoc_STRVAR(glm_mat3x2Type__doc__, "A 3x2 matrix.");

// mat3x2 Object

static
PyTypeObject glm_mat3x2Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.mat3x2",										/* tp_name */
	sizeof(glm_mat3x2),								/* tp_basicsize */
	0,														/* tp_itemsize */
	0,														/* tp_dealloc */
	0,														/* tp_print */
	0,														/* tp_getattr */
	0,														/* tp_setattr */
	0,														/* tp_reserved */
	(reprfunc)glm_mat3x2_tp_repr,						/* tp_repr */
	&glm_mat3x2_NumberMethods,							/* tp_as_number */
	&glm_mat3x2_SequenceMethods,						/* tp_as_sequence */
	0,														/* tp_as_mapping */
	(hashfunc)glm_mat3x2_tp_hash,						/* tp_hash  */
	0,														/* tp_call */
	0,														/* tp_str */
	PyObject_GenericGetAttr,								/* tp_getattro */
	PyObject_GenericSetAttr,								/* tp_setattro */
	&glm_mat3x2_BufferMethods,							/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	  Py_TPFLAGS_BASETYPE,									/* tp_flags */
	glm_mat3x2Type__doc__,								/* tp_doc */
	0,														/* tp_traverse */
	0,														/* tp_clear */
	glm_mat3x2_tp_richcompare,							/* tp_richcompare */
	0,														/* tp_weaklistoffset */
	0,														/* tp_iter */
	0,														/* tp_iternext */
	glm_mat3x2Methods,									/* tp_methods */
	0,														/* tp_members */
	0,														/* tp_getset */
	0,														/* tp_base */
	0,														/* tp_dict */
	0,														/* tp_descr_get */
	0,														/* tp_descr_set */
	0,														/* tp_dictoffset */
	(initproc)glm_mat3x2_tp_init,						/* tp_init */
	0,														/* tp_alloc */
	PyType_GenericNew,										/* tp_new */
};
static
PyNumberMethods glm_mat4x2_NumberMethods = {
	(binaryfunc)glm_mat4x2_nb_add,
	(binaryfunc)glm_mat4x2_nb_subtract,
	(binaryfunc)glm_mat4x2_nb_multiply,
	NULL,
	NULL,
	NULL,
	(unaryfunc)glm_mat4x2_nb_negative,
	(unaryfunc)glm_mat4x2_nb_positive,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	(binaryfunc)glm_mat4x2_nb_inplace_add,
	(binaryfunc)glm_mat4x2_nb_inplace_subtract,
	(binaryfunc)glm_mat4x2_nb_inplace_multiply,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	NULL,
	(binaryfunc)glm_mat4x2_nb_true_divide,
	NULL,
	(binaryfunc)glm_mat4x2_nb_inplace_true_divide,

	NULL,
};

static
PySequenceMethods glm_mat4x2_SequenceMethods = {
	(lenfunc)glm_mat4x2_sq_length,
	NULL,
	NULL,
	(ssizeargfunc)glm_mat4x2_sq_item,
	NULL,
	(ssizeobjargproc)glm_mat4x2_sq_ass_item,
	NULL,
	NULL,

	NULL,
	NULL,
};

static
PyBufferProcs glm_mat4x2_BufferMethods = {
	(getbufferproc)glm_mat4x2_bf_getbuffer,
	NULL,
};

// mat4x2 Methods



static
PyMethodDef glm_mat4x2Methods[] = {
	{NULL, NULL},
};

PyDoc_STRVAR(glm_mat4x2Type__doc__, "A 4x2 matrix.");

// mat4x2 Object

static
PyTypeObject glm_mat4x2Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.mat4x2",										/* tp_name */
	sizeof(glm_mat4x2),								/* tp_basicsize */
	0,														/* tp_itemsize */
	0,														/* tp_dealloc */
	0,														/* tp_print */
	0,														/* tp_getattr */
	0,														/* tp_setattr */
	0,														/* tp_reserved */
	(reprfunc)glm_mat4x2_tp_repr,						/* tp_repr */
	&glm_mat4x2_NumberMethods,							/* tp_as_number */
	&glm_mat4x2_SequenceMethods,						/* tp_as_sequence */
	0,														/* tp_as_mapping */
	(hashfunc)glm_mat4x2_tp_hash,						/* tp_hash  */
	0,														/* tp_call */
	0,														/* tp_str */
	PyObject_GenericGetAttr,								/* tp_getattro */
	PyObject_GenericSetAttr,								/* tp_setattro */
	&glm_mat4x2_BufferMethods,							/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	  Py_TPFLAGS_BASETYPE,									/* tp_flags */
	glm_mat4x2Type__doc__,								/* tp_doc */
	0,														/* tp_traverse */
	0,														/* tp_clear */
	glm_mat4x2_tp_richcompare,							/* tp_richcompare */
	0,														/* tp_weaklistoffset */
	0,														/* tp_iter */
	0,														/* tp_iternext */
	glm_mat4x2Methods,									/* tp_methods */
	0,														/* tp_members */
	0,														/* tp_getset */
	0,														/* tp_base */
	0,														/* tp_dict */
	0,														/* tp_descr_get */
	0,														/* tp_descr_set */
	0,														/* tp_dictoffset */
	(initproc)glm_mat4x2_tp_init,						/* tp_init */
	0,														/* tp_alloc */
	PyType_GenericNew,										/* tp_new */
};
static
PyNumberMethods glm_mat2x3_NumberMethods = {
	(binaryfunc)glm_mat2x3_nb_add,
	(binaryfunc)glm_mat2x3_nb_subtract,
	(binaryfunc)glm_mat2x3_nb_multiply,
	NULL,
	NULL,
	NULL,
	(unaryfunc)glm_mat2x3_nb_negative,
	(unaryfunc)glm_mat2x3_nb_positive,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	(binaryfunc)glm_mat2x3_nb_inplace_add,
	(binaryfunc)glm_mat2x3_nb_inplace_subtract,
	(binaryfunc)glm_mat2x3_nb_inplace_multiply,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	NULL,
	(binaryfunc)glm_mat2x3_nb_true_divide,
	NULL,
	(binaryfunc)glm_mat2x3_nb_inplace_true_divide,

	NULL,
};

static
PySequenceMethods glm_mat2x3_SequenceMethods = {
	(lenfunc)glm_mat2x3_sq_length,
	NULL,
	NULL,
	(ssizeargfunc)glm_mat2x3_sq_item,
	NULL,
	(ssizeobjargproc)glm_mat2x3_sq_ass_item,
	NULL,
	NULL,

	NULL,
	NULL,
};

static
PyBufferProcs glm_mat2x3_BufferMethods = {
	(getbufferproc)glm_mat2x3_bf_getbuffer,
	NULL,
};

// mat2x3 Methods



static
PyMethodDef glm_mat2x3Methods[] = {
	{NULL, NULL},
};

PyDoc_STRVAR(glm_mat2x3Type__doc__, "A 2x3 matrix.");

// mat2x3 Object

static
PyTypeObject glm_mat2x3Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.mat2x3",										/* tp_name */
	sizeof(glm_mat2x3),								/* tp_basicsize */
	0,														/* tp_itemsize */
	0,														/* tp_dealloc */
	0,														/* tp_print */
	0,														/* tp_getattr */
	0,														/* tp_setattr */
	0,														/* tp_reserved */
	(reprfunc)glm_mat2x3_tp_repr,						/* tp_repr */
	&glm_mat2x3_NumberMethods,							/* tp_as_number */
	&glm_mat2x3_SequenceMethods,						/* tp_as_sequence */
	0,														/* tp_as_mapping */
	(hashfunc)glm_mat2x3_tp_hash,						/* tp_hash  */
	0,														/* tp_call */
	0,														/* tp_str */
	PyObject_GenericGetAttr,								/* tp_getattro */
	PyObject_GenericSetAttr,								/* tp_setattro */
	&glm_mat2x3_BufferMethods,							/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	  Py_TPFLAGS_BASETYPE,									/* tp_flags */
	glm_mat2x3Type__doc__,								/* tp_doc */
	0,														/* tp_traverse */
	0,														/* tp_clear */
	glm_mat2x3_tp_richcompare,							/* tp_richcompare */
	0,														/* tp_weaklistoffset */
	0,														/* tp_iter */
	0,														/* tp_iternext */
	glm_mat2x3Methods,									/* tp_methods */
	0,														/* tp_members */
	0,														/* tp_getset */
	0,														/* tp_base */
	0,														/* tp_dict */
	0,														/* tp_descr_get */
	0,														/* tp_descr_set */
	0,														/* tp_dictoffset */
	(initproc)glm_mat2x3_tp_init,						/* tp_init */
	0,														/* tp_alloc */
	PyType_GenericNew,										/* tp_new */
};
static
PyNumberMethods glm_mat3_NumberMethods = {
	(binaryfunc)glm_mat3_nb_add,
	(binaryfunc)glm_mat3_nb_subtract,
	(binaryfunc)glm_mat3_nb_multiply,
	NULL,
	NULL,
	NULL,
	(unaryfunc)glm_mat3_nb_negative,
	(unaryfunc)glm_mat3_nb_positive,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	(binaryfunc)glm_mat3_nb_inplace_add,
	(binaryfunc)glm_mat3_nb_inplace_subtract,
	(binaryfunc)glm_mat3_nb_inplace_multiply,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	NULL,
	(binaryfunc)glm_mat3_nb_true_divide,
	NULL,
	(binaryfunc)glm_mat3_nb_inplace_true_divide,

	NULL,
};

static
PySequenceMethods glm_mat3_SequenceMethods = {
	(lenfunc)glm_mat3_sq_length,
	NULL,
	NULL,
	(ssizeargfunc)glm_mat3_sq_item,
	NULL,
	(ssizeobjargproc)glm_mat3_sq_ass_item,
	NULL,
	NULL,

	NULL,
	NULL,
};

static
PyBufferProcs glm_mat3_BufferMethods = {
	(getbufferproc)glm_mat3_bf_getbuffer,
	NULL,
};

// mat3 Methods

static PyObject *glm_mat3_function_inverse(PyObject *, PyObject *);

PyDoc_STRVAR(glm_mat3_function_inverse__doc__, "Matrix's inverse.");

static
PyMethodDef glm_mat3Methods[] = {
	{"inverse", (PyCFunction) glm_mat3_function_inverse, METH_NOARGS, glm_mat3_function_inverse__doc__},
	{NULL, NULL},
};

PyDoc_STRVAR(glm_mat3Type__doc__, "A 3x3 matrix.");

// mat3 Object

static
PyTypeObject glm_mat3Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.mat3",										/* tp_name */
	sizeof(glm_mat3),								/* tp_basicsize */
	0,														/* tp_itemsize */
	0,														/* tp_dealloc */
	0,														/* tp_print */
	0,														/* tp_getattr */
	0,														/* tp_setattr */
	0,														/* tp_reserved */
	(reprfunc)glm_mat3_tp_repr,						/* tp_repr */
	&glm_mat3_NumberMethods,							/* tp_as_number */
	&glm_mat3_SequenceMethods,						/* tp_as_sequence */
	0,														/* tp_as_mapping */
	(hashfunc)glm_mat3_tp_hash,						/* tp_hash  */
	0,														/* tp_call */
	0,														/* tp_str */
	PyObject_GenericGetAttr,								/* tp_getattro */
	PyObject_GenericSetAttr,								/* tp_setattro */
	&glm_mat3_BufferMethods,							/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	  Py_TPFLAGS_BASETYPE,									/* tp_flags */
	glm_mat3Type__doc__,								/* tp_doc */
	0,														/* tp_traverse */
	0,														/* tp_clear */
	glm_mat3_tp_richcompare,							/* tp_richcompare */
	0,														/* tp_weaklistoffset */
	0,														/* tp_iter */
	0,														/* tp_iternext */
	glm_mat3Methods,									/* tp_methods */
	0,														/* tp_members */
	0,														/* tp_getset */
	0,														/* tp_base */
	0,														/* tp_dict */
	0,														/* tp_descr_get */
	0,														/* tp_descr_set */
	0,														/* tp_dictoffset */
	(initproc)glm_mat3_tp_init,						/* tp_init */
	0,														/* tp_alloc */
	PyType_GenericNew,										/* tp_new */
};
static
PyNumberMethods glm_mat4x3_NumberMethods = {
	(binaryfunc)glm_mat4x3_nb_add,
	(binaryfunc)glm_mat4x3_nb_subtract,
	(binaryfunc)glm_mat4x3_nb_multiply,
	NULL,
	NULL,
	NULL,
	(unaryfunc)glm_mat4x3_nb_negative,
	(unaryfunc)glm_mat4x3_nb_positive,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	(binaryfunc)glm_mat4x3_nb_inplace_add,
	(binaryfunc)glm_mat4x3_nb_inplace_subtract,
	(binaryfunc)glm_mat4x3_nb_inplace_multiply,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	NULL,
	(binaryfunc)glm_mat4x3_nb_true_divide,
	NULL,
	(binaryfunc)glm_mat4x3_nb_inplace_true_divide,

	NULL,
};

static
PySequenceMethods glm_mat4x3_SequenceMethods = {
	(lenfunc)glm_mat4x3_sq_length,
	NULL,
	NULL,
	(ssizeargfunc)glm_mat4x3_sq_item,
	NULL,
	(ssizeobjargproc)glm_mat4x3_sq_ass_item,
	NULL,
	NULL,

	NULL,
	NULL,
};

static
PyBufferProcs glm_mat4x3_BufferMethods = {
	(getbufferproc)glm_mat4x3_bf_getbuffer,
	NULL,
};

// mat4x3 Methods



static
PyMethodDef glm_mat4x3Methods[] = {
	{NULL, NULL},
};

PyDoc_STRVAR(glm_mat4x3Type__doc__, "A 4x3 matrix.");

// mat4x3 Object

static
PyTypeObject glm_mat4x3Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.mat4x3",										/* tp_name */
	sizeof(glm_mat4x3),								/* tp_basicsize */
	0,														/* tp_itemsize */
	0,														/* tp_dealloc */
	0,														/* tp_print */
	0,														/* tp_getattr */
	0,														/* tp_setattr */
	0,														/* tp_reserved */
	(reprfunc)glm_mat4x3_tp_repr,						/* tp_repr */
	&glm_mat4x3_NumberMethods,							/* tp_as_number */
	&glm_mat4x3_SequenceMethods,						/* tp_as_sequence */
	0,														/* tp_as_mapping */
	(hashfunc)glm_mat4x3_tp_hash,						/* tp_hash  */
	0,														/* tp_call */
	0,														/* tp_str */
	PyObject_GenericGetAttr,								/* tp_getattro */
	PyObject_GenericSetAttr,								/* tp_setattro */
	&glm_mat4x3_BufferMethods,							/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	  Py_TPFLAGS_BASETYPE,									/* tp_flags */
	glm_mat4x3Type__doc__,								/* tp_doc */
	0,														/* tp_traverse */
	0,														/* tp_clear */
	glm_mat4x3_tp_richcompare,							/* tp_richcompare */
	0,														/* tp_weaklistoffset */
	0,														/* tp_iter */
	0,														/* tp_iternext */
	glm_mat4x3Methods,									/* tp_methods */
	0,														/* tp_members */
	0,														/* tp_getset */
	0,														/* tp_base */
	0,														/* tp_dict */
	0,														/* tp_descr_get */
	0,														/* tp_descr_set */
	0,														/* tp_dictoffset */
	(initproc)glm_mat4x3_tp_init,						/* tp_init */
	0,														/* tp_alloc */
	PyType_GenericNew,										/* tp_new */
};
static
PyNumberMethods glm_mat2x4_NumberMethods = {
	(binaryfunc)glm_mat2x4_nb_add,
	(binaryfunc)glm_mat2x4_nb_subtract,
	(binaryfunc)glm_mat2x4_nb_multiply,
	NULL,
	NULL,
	NULL,
	(unaryfunc)glm_mat2x4_nb_negative,
	(unaryfunc)glm_mat2x4_nb_positive,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	(binaryfunc)glm_mat2x4_nb_inplace_add,
	(binaryfunc)glm_mat2x4_nb_inplace_subtract,
	(binaryfunc)glm_mat2x4_nb_inplace_multiply,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	NULL,
	(binaryfunc)glm_mat2x4_nb_true_divide,
	NULL,
	(binaryfunc)glm_mat2x4_nb_inplace_true_divide,

	NULL,
};

static
PySequenceMethods glm_mat2x4_SequenceMethods = {
	(lenfunc)glm_mat2x4_sq_length,
	NULL,
	NULL,
	(ssizeargfunc)glm_mat2x4_sq_item,
	NULL,
	(ssizeobjargproc)glm_mat2x4_sq_ass_item,
	NULL,
	NULL,

	NULL,
	NULL,
};

static
PyBufferProcs glm_mat2x4_BufferMethods = {
	(getbufferproc)glm_mat2x4_bf_getbuffer,
	NULL,
};

// mat2x4 Methods



static
PyMethodDef glm_mat2x4Methods[] = {
	{NULL, NULL},
};

PyDoc_STRVAR(glm_mat2x4Type__doc__, "A 2x4 matrix.");

// mat2x4 Object

static
PyTypeObject glm_mat2x4Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.mat2x4",										/* tp_name */
	sizeof(glm_mat2x4),								/* tp_basicsize */
	0,														/* tp_itemsize */
	0,														/* tp_dealloc */
	0,														/* tp_print */
	0,														/* tp_getattr */
	0,														/* tp_setattr */
	0,														/* tp_reserved */
	(reprfunc)glm_mat2x4_tp_repr,						/* tp_repr */
	&glm_mat2x4_NumberMethods,							/* tp_as_number */
	&glm_mat2x4_SequenceMethods,						/* tp_as_sequence */
	0,														/* tp_as_mapping */
	(hashfunc)glm_mat2x4_tp_hash,						/* tp_hash  */
	0,														/* tp_call */
	0,														/* tp_str */
	PyObject_GenericGetAttr,								/* tp_getattro */
	PyObject_GenericSetAttr,								/* tp_setattro */
	&glm_mat2x4_BufferMethods,							/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	  Py_TPFLAGS_BASETYPE,									/* tp_flags */
	glm_mat2x4Type__doc__,								/* tp_doc */
	0,														/* tp_traverse */
	0,														/* tp_clear */
	glm_mat2x4_tp_richcompare,							/* tp_richcompare */
	0,														/* tp_weaklistoffset */
	0,														/* tp_iter */
	0,														/* tp_iternext */
	glm_mat2x4Methods,									/* tp_methods */
	0,														/* tp_members */
	0,														/* tp_getset */
	0,														/* tp_base */
	0,														/* tp_dict */
	0,														/* tp_descr_get */
	0,														/* tp_descr_set */
	0,														/* tp_dictoffset */
	(initproc)glm_mat2x4_tp_init,						/* tp_init */
	0,														/* tp_alloc */
	PyType_GenericNew,										/* tp_new */
};
static
PyNumberMethods glm_mat3x4_NumberMethods = {
	(binaryfunc)glm_mat3x4_nb_add,
	(binaryfunc)glm_mat3x4_nb_subtract,
	(binaryfunc)glm_mat3x4_nb_multiply,
	NULL,
	NULL,
	NULL,
	(unaryfunc)glm_mat3x4_nb_negative,
	(unaryfunc)glm_mat3x4_nb_positive,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	(binaryfunc)glm_mat3x4_nb_inplace_add,
	(binaryfunc)glm_mat3x4_nb_inplace_subtract,
	(binaryfunc)glm_mat3x4_nb_inplace_multiply,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	NULL,
	(binaryfunc)glm_mat3x4_nb_true_divide,
	NULL,
	(binaryfunc)glm_mat3x4_nb_inplace_true_divide,

	NULL,
};

static
PySequenceMethods glm_mat3x4_SequenceMethods = {
	(lenfunc)glm_mat3x4_sq_length,
	NULL,
	NULL,
	(ssizeargfunc)glm_mat3x4_sq_item,
	NULL,
	(ssizeobjargproc)glm_mat3x4_sq_ass_item,
	NULL,
	NULL,

	NULL,
	NULL,
};

static
PyBufferProcs glm_mat3x4_BufferMethods = {
	(getbufferproc)glm_mat3x4_bf_getbuffer,
	NULL,
};

// mat3x4 Methods



static
PyMethodDef glm_mat3x4Methods[] = {
	{NULL, NULL},
};

PyDoc_STRVAR(glm_mat3x4Type__doc__, "A 3x4 matrix.");

// mat3x4 Object

static
PyTypeObject glm_mat3x4Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.mat3x4",										/* tp_name */
	sizeof(glm_mat3x4),								/* tp_basicsize */
	0,														/* tp_itemsize */
	0,														/* tp_dealloc */
	0,														/* tp_print */
	0,														/* tp_getattr */
	0,														/* tp_setattr */
	0,														/* tp_reserved */
	(reprfunc)glm_mat3x4_tp_repr,						/* tp_repr */
	&glm_mat3x4_NumberMethods,							/* tp_as_number */
	&glm_mat3x4_SequenceMethods,						/* tp_as_sequence */
	0,														/* tp_as_mapping */
	(hashfunc)glm_mat3x4_tp_hash,						/* tp_hash  */
	0,														/* tp_call */
	0,														/* tp_str */
	PyObject_GenericGetAttr,								/* tp_getattro */
	PyObject_GenericSetAttr,								/* tp_setattro */
	&glm_mat3x4_BufferMethods,							/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	  Py_TPFLAGS_BASETYPE,									/* tp_flags */
	glm_mat3x4Type__doc__,								/* tp_doc */
	0,														/* tp_traverse */
	0,														/* tp_clear */
	glm_mat3x4_tp_richcompare,							/* tp_richcompare */
	0,														/* tp_weaklistoffset */
	0,														/* tp_iter */
	0,														/* tp_iternext */
	glm_mat3x4Methods,									/* tp_methods */
	0,														/* tp_members */
	0,														/* tp_getset */
	0,														/* tp_base */
	0,														/* tp_dict */
	0,														/* tp_descr_get */
	0,														/* tp_descr_set */
	0,														/* tp_dictoffset */
	(initproc)glm_mat3x4_tp_init,						/* tp_init */
	0,														/* tp_alloc */
	PyType_GenericNew,										/* tp_new */
};
static
PyNumberMethods glm_mat4_NumberMethods = {
	(binaryfunc)glm_mat4_nb_add,
	(binaryfunc)glm_mat4_nb_subtract,
	(binaryfunc)glm_mat4_nb_multiply,
	NULL,
	NULL,
	NULL,
	(unaryfunc)glm_mat4_nb_negative,
	(unaryfunc)glm_mat4_nb_positive,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	(binaryfunc)glm_mat4_nb_inplace_add,
	(binaryfunc)glm_mat4_nb_inplace_subtract,
	(binaryfunc)glm_mat4_nb_inplace_multiply,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	NULL,
	(binaryfunc)glm_mat4_nb_true_divide,
	NULL,
	(binaryfunc)glm_mat4_nb_inplace_true_divide,

	NULL,
};

static
PySequenceMethods glm_mat4_SequenceMethods = {
	(lenfunc)glm_mat4_sq_length,
	NULL,
	NULL,
	(ssizeargfunc)glm_mat4_sq_item,
	NULL,
	(ssizeobjargproc)glm_mat4_sq_ass_item,
	NULL,
	NULL,

	NULL,
	NULL,
};

static
PyBufferProcs glm_mat4_BufferMethods = {
	(getbufferproc)glm_mat4_bf_getbuffer,
	NULL,
};

// mat4 Methods

static PyObject *glm_mat4_function_translate(PyObject *, PyObject *);
static PyObject *glm_mat4_function_rotate(PyObject *, PyObject *);
static PyObject *glm_mat4_function_scale(PyObject *, PyObject *);
static PyObject *glm_mat4_function_inverse(PyObject *, PyObject *);

PyDoc_STRVAR(glm_mat4_function_translate__doc__, "Translates a 4x4 matrix.");
PyDoc_STRVAR(glm_mat4_function_rotate__doc__, "Rotates a 4x4 matrix.");
PyDoc_STRVAR(glm_mat4_function_scale__doc__, "Scales a 4x4 matrix.");
PyDoc_STRVAR(glm_mat4_function_inverse__doc__, "Matrix's inverse.");

static
PyMethodDef glm_mat4Methods[] = {
	{"translate", (PyCFunction) glm_mat4_function_translate, METH_VARARGS, glm_mat4_function_translate__doc__},
	{"rotate", (PyCFunction) glm_mat4_function_rotate, METH_VARARGS, glm_mat4_function_rotate__doc__},
	{"scale", (PyCFunction) glm_mat4_function_scale, METH_VARARGS, glm_mat4_function_scale__doc__},
	{"inverse", (PyCFunction) glm_mat4_function_inverse, METH_NOARGS, glm_mat4_function_inverse__doc__},
	{NULL, NULL},
};

PyDoc_STRVAR(glm_mat4Type__doc__, "A 4x4 matrix.");

// mat4 Object

static
PyTypeObject glm_mat4Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.mat4",										/* tp_name */
	sizeof(glm_mat4),								/* tp_basicsize */
	0,														/* tp_itemsize */
	0,														/* tp_dealloc */
	0,														/* tp_print */
	0,														/* tp_getattr */
	0,														/* tp_setattr */
	0,														/* tp_reserved */
	(reprfunc)glm_mat4_tp_repr,						/* tp_repr */
	&glm_mat4_NumberMethods,							/* tp_as_number */
	&glm_mat4_SequenceMethods,						/* tp_as_sequence */
	0,														/* tp_as_mapping */
	(hashfunc)glm_mat4_tp_hash,						/* tp_hash  */
	0,														/* tp_call */
	0,														/* tp_str */
	PyObject_GenericGetAttr,								/* tp_getattro */
	PyObject_GenericSetAttr,								/* tp_setattro */
	&glm_mat4_BufferMethods,							/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	  Py_TPFLAGS_BASETYPE,									/* tp_flags */
	glm_mat4Type__doc__,								/* tp_doc */
	0,														/* tp_traverse */
	0,														/* tp_clear */
	glm_mat4_tp_richcompare,							/* tp_richcompare */
	0,														/* tp_weaklistoffset */
	0,														/* tp_iter */
	0,														/* tp_iternext */
	glm_mat4Methods,									/* tp_methods */
	0,														/* tp_members */
	0,														/* tp_getset */
	0,														/* tp_base */
	0,														/* tp_dict */
	0,														/* tp_descr_get */
	0,														/* tp_descr_set */
	0,														/* tp_dictoffset */
	(initproc)glm_mat4_tp_init,						/* tp_init */
	0,														/* tp_alloc */
	PyType_GenericNew,										/* tp_new */
};

static
PyNumberMethods glm_vec2_NumberMethods = {
	(binaryfunc)glm_vec2_nb_add,
	(binaryfunc)glm_vec2_nb_subtract,
	(binaryfunc)glm_vec2_nb_multiply,
	(binaryfunc)glm_vec2_nb_remainder,
	(binaryfunc)glm_vec2_nb_divmod,
	(ternaryfunc)glm_vec2_nb_power,
	(unaryfunc)glm_vec2_nb_negative,
	(unaryfunc)glm_vec2_nb_positive,
	(unaryfunc)glm_vec2_nb_absolute,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	(binaryfunc)glm_vec2_nb_inplace_add,
	(binaryfunc)glm_vec2_nb_inplace_subtract,
	(binaryfunc)glm_vec2_nb_inplace_multiply,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	(binaryfunc)glm_vec2_nb_floor_divide,
	(binaryfunc)glm_vec2_nb_true_divide,
	(binaryfunc)glm_vec2_nb_inplace_floor_divide,
	(binaryfunc)glm_vec2_nb_inplace_true_divide,

	NULL,
};

static
PySequenceMethods glm_vec2_SequenceMethods = {
	(lenfunc)glm_vec2_sq_length,
	NULL,
	NULL,
	(ssizeargfunc)glm_vec2_sq_item,
	NULL,
	(ssizeobjargproc)glm_vec2_sq_ass_item,
	NULL,
	NULL,

	NULL,
	NULL,
};

static
PyBufferProcs glm_vec2_BufferMethods = {
	(getbufferproc)glm_vec2_bf_getbuffer,
	NULL,
};

// vec2 Methods

static
PyObject * glm_vec2_function_abs(PyObject *self) {
	PyErr_SetString(PyExc_NotImplementedError, "Function not ported.");
	return NULL;
}

PyDoc_STRVAR(glm_vec2_function_abs__doc__, "Absolute value.");

static
PyMethodDef glm_vec2Methods[] = {
	{"abs", (PyCFunction) glm_vec2_function_abs, METH_NOARGS, glm_vec2_function_abs__doc__},
	{NULL, NULL},
};

PyDoc_STRVAR(glm_vec2Type__doc__, "A 2D vector.");

// vec2 Object

static
PyTypeObject glm_vec2Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.vec2",										/* tp_name */
	sizeof(glm_vec2),								/* tp_basicsize */
	0,														/* tp_itemsize */
	0,														/* tp_dealloc */
	0,														/* tp_print */
	0,														/* tp_getattr */
	0,														/* tp_setattr */
	0,														/* tp_reserved */
	(reprfunc)glm_vec2_tp_repr,						/* tp_repr */
	&glm_vec2_NumberMethods,							/* tp_as_number */
	&glm_vec2_SequenceMethods,						/* tp_as_sequence */
	0,														/* tp_as_mapping */
	(hashfunc)glm_vec2_tp_hash,						/* tp_hash  */
	0,														/* tp_call */
	0,														/* tp_str */
	(getattrofunc)glm_vec2_tp_getattro,				/* tp_getattro */
	(setattrofunc)glm_vec2_tp_setattro,				/* tp_setattro */
	&glm_vec2_BufferMethods,							/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	  Py_TPFLAGS_BASETYPE,									/* tp_flags */
	glm_vec2Type__doc__,								/* tp_doc */
	0,														/* tp_traverse */
	0,														/* tp_clear */
	glm_vec2_tp_richcompare,							/* tp_richcompare */
	0,														/* tp_weaklistoffset */
	0,														/* tp_iter */
	0,														/* tp_iternext */
	glm_vec2Methods,									/* tp_methods */
	0,														/* tp_members */
	0,														/* tp_getset */
	0,														/* tp_base */
	0,														/* tp_dict */
	0,														/* tp_descr_get */
	0,														/* tp_descr_set */
	0,														/* tp_dictoffset */
	(initproc)glm_vec2_tp_init,						/* tp_init */
	0,														/* tp_alloc */
	PyType_GenericNew,										/* tp_new */
};
static
PyNumberMethods glm_vec3_NumberMethods = {
	(binaryfunc)glm_vec3_nb_add,
	(binaryfunc)glm_vec3_nb_subtract,
	(binaryfunc)glm_vec3_nb_multiply,
	(binaryfunc)glm_vec3_nb_remainder,
	(binaryfunc)glm_vec3_nb_divmod,
	(ternaryfunc)glm_vec3_nb_power,
	(unaryfunc)glm_vec3_nb_negative,
	(unaryfunc)glm_vec3_nb_positive,
	(unaryfunc)glm_vec3_nb_absolute,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	(binaryfunc)glm_vec3_nb_inplace_add,
	(binaryfunc)glm_vec3_nb_inplace_subtract,
	(binaryfunc)glm_vec3_nb_inplace_multiply,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	(binaryfunc)glm_vec3_nb_floor_divide,
	(binaryfunc)glm_vec3_nb_true_divide,
	(binaryfunc)glm_vec3_nb_inplace_floor_divide,
	(binaryfunc)glm_vec3_nb_inplace_true_divide,

	NULL,
};

static
PySequenceMethods glm_vec3_SequenceMethods = {
	(lenfunc)glm_vec3_sq_length,
	NULL,
	NULL,
	(ssizeargfunc)glm_vec3_sq_item,
	NULL,
	(ssizeobjargproc)glm_vec3_sq_ass_item,
	NULL,
	NULL,

	NULL,
	NULL,
};

static
PyBufferProcs glm_vec3_BufferMethods = {
	(getbufferproc)glm_vec3_bf_getbuffer,
	NULL,
};

// vec3 Methods

static
PyObject * glm_vec3_function_abs(PyObject *self) {
	PyErr_SetString(PyExc_NotImplementedError, "Function not ported.");
	return NULL;
}

PyDoc_STRVAR(glm_vec3_function_abs__doc__, "Absolute value.");

static
PyMethodDef glm_vec3Methods[] = {
	{"abs", (PyCFunction) glm_vec3_function_abs, METH_NOARGS, glm_vec3_function_abs__doc__},
	{NULL, NULL},
};

PyDoc_STRVAR(glm_vec3Type__doc__, "A 3D vector.");

// vec3 Object

static
PyTypeObject glm_vec3Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.vec3",										/* tp_name */
	sizeof(glm_vec3),								/* tp_basicsize */
	0,														/* tp_itemsize */
	0,														/* tp_dealloc */
	0,														/* tp_print */
	0,														/* tp_getattr */
	0,														/* tp_setattr */
	0,														/* tp_reserved */
	(reprfunc)glm_vec3_tp_repr,						/* tp_repr */
	&glm_vec3_NumberMethods,							/* tp_as_number */
	&glm_vec3_SequenceMethods,						/* tp_as_sequence */
	0,														/* tp_as_mapping */
	(hashfunc)glm_vec3_tp_hash,						/* tp_hash  */
	0,														/* tp_call */
	0,														/* tp_str */
	(getattrofunc)glm_vec3_tp_getattro,				/* tp_getattro */
	(setattrofunc)glm_vec3_tp_setattro,				/* tp_setattro */
	&glm_vec3_BufferMethods,							/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	  Py_TPFLAGS_BASETYPE,									/* tp_flags */
	glm_vec3Type__doc__,								/* tp_doc */
	0,														/* tp_traverse */
	0,														/* tp_clear */
	glm_vec3_tp_richcompare,							/* tp_richcompare */
	0,														/* tp_weaklistoffset */
	0,														/* tp_iter */
	0,														/* tp_iternext */
	glm_vec3Methods,									/* tp_methods */
	0,														/* tp_members */
	0,														/* tp_getset */
	0,														/* tp_base */
	0,														/* tp_dict */
	0,														/* tp_descr_get */
	0,														/* tp_descr_set */
	0,														/* tp_dictoffset */
	(initproc)glm_vec3_tp_init,						/* tp_init */
	0,														/* tp_alloc */
	PyType_GenericNew,										/* tp_new */
};
static
PyNumberMethods glm_vec4_NumberMethods = {
	(binaryfunc)glm_vec4_nb_add,
	(binaryfunc)glm_vec4_nb_subtract,
	(binaryfunc)glm_vec4_nb_multiply,
	(binaryfunc)glm_vec4_nb_remainder,
	(binaryfunc)glm_vec4_nb_divmod,
	(ternaryfunc)glm_vec4_nb_power,
	(unaryfunc)glm_vec4_nb_negative,
	(unaryfunc)glm_vec4_nb_positive,
	(unaryfunc)glm_vec4_nb_absolute,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,

	(binaryfunc)glm_vec4_nb_inplace_add,
	(binaryfunc)glm_vec4_nb_inplace_subtract,
	(binaryfunc)glm_vec4_nb_inplace_multiply,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	(binaryfunc)glm_vec4_nb_floor_divide,
	(binaryfunc)glm_vec4_nb_true_divide,
	(binaryfunc)glm_vec4_nb_inplace_floor_divide,
	(binaryfunc)glm_vec4_nb_inplace_true_divide,

	NULL,
};

static
PySequenceMethods glm_vec4_SequenceMethods = {
	(lenfunc)glm_vec4_sq_length,
	NULL,
	NULL,
	(ssizeargfunc)glm_vec4_sq_item,
	NULL,
	(ssizeobjargproc)glm_vec4_sq_ass_item,
	NULL,
	NULL,

	NULL,
	NULL,
};

static
PyBufferProcs glm_vec4_BufferMethods = {
	(getbufferproc)glm_vec4_bf_getbuffer,
	NULL,
};

// vec4 Methods

static
PyObject * glm_vec4_function_abs(PyObject *self) {
	PyErr_SetString(PyExc_NotImplementedError, "Function not ported.");
	return NULL;
}

PyDoc_STRVAR(glm_vec4_function_abs__doc__, "Absolute value.");

static
PyMethodDef glm_vec4Methods[] = {
	{"abs", (PyCFunction) glm_vec4_function_abs, METH_NOARGS, glm_vec4_function_abs__doc__},
	{NULL, NULL},
};

PyDoc_STRVAR(glm_vec4Type__doc__, "A 4D vector.");

// vec4 Object

static
PyTypeObject glm_vec4Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.vec4",										/* tp_name */
	sizeof(glm_vec4),								/* tp_basicsize */
	0,														/* tp_itemsize */
	0,														/* tp_dealloc */
	0,														/* tp_print */
	0,														/* tp_getattr */
	0,														/* tp_setattr */
	0,														/* tp_reserved */
	(reprfunc)glm_vec4_tp_repr,						/* tp_repr */
	&glm_vec4_NumberMethods,							/* tp_as_number */
	&glm_vec4_SequenceMethods,						/* tp_as_sequence */
	0,														/* tp_as_mapping */
	(hashfunc)glm_vec4_tp_hash,						/* tp_hash  */
	0,														/* tp_call */
	0,														/* tp_str */
	(getattrofunc)glm_vec4_tp_getattro,				/* tp_getattro */
	(setattrofunc)glm_vec4_tp_setattro,				/* tp_setattro */
	&glm_vec4_BufferMethods,							/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	  Py_TPFLAGS_BASETYPE,									/* tp_flags */
	glm_vec4Type__doc__,								/* tp_doc */
	0,														/* tp_traverse */
	0,														/* tp_clear */
	glm_vec4_tp_richcompare,							/* tp_richcompare */
	0,														/* tp_weaklistoffset */
	0,														/* tp_iter */
	0,														/* tp_iternext */
	glm_vec4Methods,									/* tp_methods */
	0,														/* tp_members */
	0,														/* tp_getset */
	0,														/* tp_base */
	0,														/* tp_dict */
	0,														/* tp_descr_get */
	0,														/* tp_descr_set */
	0,														/* tp_dictoffset */
	(initproc)glm_vec4_tp_init,						/* tp_init */
	0,														/* tp_alloc */
	PyType_GenericNew,										/* tp_new */
};
static
PyNumberMethods glm_ivec2_NumberMethods = {
	(binaryfunc)glm_ivec2_nb_add,
	(binaryfunc)glm_ivec2_nb_subtract,
	(binaryfunc)glm_ivec2_nb_multiply,
	NULL,
	NULL,
	NULL,
	(unaryfunc)glm_ivec2_nb_negative,
	(unaryfunc)glm_ivec2_nb_positive,
	(unaryfunc)glm_ivec2_nb_absolute,
	NULL,
	(unaryfunc)glm_ivec2_nb_invert,
	(binaryfunc)glm_ivec2_nb_lshift,
	(binaryfunc)glm_ivec2_nb_rshift,
	(binaryfunc)glm_ivec2_nb_and,
	(binaryfunc)glm_ivec2_nb_xor,
	(binaryfunc)glm_ivec2_nb_or,
	NULL,
	NULL,
	NULL,

	(binaryfunc)glm_ivec2_nb_inplace_add,
	(binaryfunc)glm_ivec2_nb_inplace_subtract,
	(binaryfunc)glm_ivec2_nb_inplace_multiply,
	NULL,
	NULL,
	(binaryfunc)glm_ivec2_nb_inplace_lshift,
	(binaryfunc)glm_ivec2_nb_inplace_rshift,
	(binaryfunc)glm_ivec2_nb_inplace_and,
	(binaryfunc)glm_ivec2_nb_inplace_xor,
	(binaryfunc)glm_ivec2_nb_inplace_or,
	(binaryfunc)glm_ivec2_nb_true_divide,
	(binaryfunc)glm_ivec2_nb_true_divide,
	(binaryfunc)glm_ivec2_nb_inplace_true_divide,
	(binaryfunc)glm_ivec2_nb_inplace_true_divide,

	NULL,
};

static
PySequenceMethods glm_ivec2_SequenceMethods = {
	(lenfunc)glm_ivec2_sq_length,
	NULL,
	NULL,
	(ssizeargfunc)glm_ivec2_sq_item,
	NULL,
	(ssizeobjargproc)glm_ivec2_sq_ass_item,
	NULL,
	NULL,

	NULL,
	NULL,
};

static
PyBufferProcs glm_ivec2_BufferMethods = {
	(getbufferproc)glm_ivec2_bf_getbuffer,
	NULL,
};

// ivec2 Methods

static
PyObject * glm_ivec2_function_abs(PyObject *self) {
	PyErr_SetString(PyExc_NotImplementedError, "Function not ported.");
	return NULL;
}

PyDoc_STRVAR(glm_ivec2_function_abs__doc__, "Absolute value.");

static
PyMethodDef glm_ivec2Methods[] = {
	{"abs", (PyCFunction) glm_ivec2_function_abs, METH_NOARGS, glm_ivec2_function_abs__doc__},
	{NULL, NULL},
};

PyDoc_STRVAR(glm_ivec2Type__doc__, "A 2D integer vector.");

// ivec2 Object

static
PyTypeObject glm_ivec2Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.ivec2",										/* tp_name */
	sizeof(glm_ivec2),								/* tp_basicsize */
	0,														/* tp_itemsize */
	0,														/* tp_dealloc */
	0,														/* tp_print */
	0,														/* tp_getattr */
	0,														/* tp_setattr */
	0,														/* tp_reserved */
	(reprfunc)glm_ivec2_tp_repr,						/* tp_repr */
	&glm_ivec2_NumberMethods,							/* tp_as_number */
	&glm_ivec2_SequenceMethods,						/* tp_as_sequence */
	0,														/* tp_as_mapping */
	(hashfunc)glm_ivec2_tp_hash,						/* tp_hash  */
	0,														/* tp_call */
	0,														/* tp_str */
	(getattrofunc)glm_ivec2_tp_getattro,				/* tp_getattro */
	(setattrofunc)glm_ivec2_tp_setattro,				/* tp_setattro */
	&glm_ivec2_BufferMethods,							/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	  Py_TPFLAGS_BASETYPE,									/* tp_flags */
	glm_ivec2Type__doc__,								/* tp_doc */
	0,														/* tp_traverse */
	0,														/* tp_clear */
	glm_ivec2_tp_richcompare,							/* tp_richcompare */
	0,														/* tp_weaklistoffset */
	0,														/* tp_iter */
	0,														/* tp_iternext */
	glm_ivec2Methods,									/* tp_methods */
	0,														/* tp_members */
	0,														/* tp_getset */
	0,														/* tp_base */
	0,														/* tp_dict */
	0,														/* tp_descr_get */
	0,														/* tp_descr_set */
	0,														/* tp_dictoffset */
	(initproc)glm_ivec2_tp_init,						/* tp_init */
	0,														/* tp_alloc */
	PyType_GenericNew,										/* tp_new */
};
static
PyNumberMethods glm_ivec3_NumberMethods = {
	(binaryfunc)glm_ivec3_nb_add,
	(binaryfunc)glm_ivec3_nb_subtract,
	(binaryfunc)glm_ivec3_nb_multiply,
	NULL,
	NULL,
	NULL,
	(unaryfunc)glm_ivec3_nb_negative,
	(unaryfunc)glm_ivec3_nb_positive,
	(unaryfunc)glm_ivec3_nb_absolute,
	NULL,
	(unaryfunc)glm_ivec3_nb_invert,
	(binaryfunc)glm_ivec3_nb_lshift,
	(binaryfunc)glm_ivec3_nb_rshift,
	(binaryfunc)glm_ivec3_nb_and,
	(binaryfunc)glm_ivec3_nb_xor,
	(binaryfunc)glm_ivec3_nb_or,
	NULL,
	NULL,
	NULL,

	(binaryfunc)glm_ivec3_nb_inplace_add,
	(binaryfunc)glm_ivec3_nb_inplace_subtract,
	(binaryfunc)glm_ivec3_nb_inplace_multiply,
	NULL,
	NULL,
	(binaryfunc)glm_ivec3_nb_inplace_lshift,
	(binaryfunc)glm_ivec3_nb_inplace_rshift,
	(binaryfunc)glm_ivec3_nb_inplace_and,
	(binaryfunc)glm_ivec3_nb_inplace_xor,
	(binaryfunc)glm_ivec3_nb_inplace_or,
	(binaryfunc)glm_ivec3_nb_true_divide,
	(binaryfunc)glm_ivec3_nb_true_divide,
	(binaryfunc)glm_ivec3_nb_inplace_true_divide,
	(binaryfunc)glm_ivec3_nb_inplace_true_divide,

	NULL,
};

static
PySequenceMethods glm_ivec3_SequenceMethods = {
	(lenfunc)glm_ivec3_sq_length,
	NULL,
	NULL,
	(ssizeargfunc)glm_ivec3_sq_item,
	NULL,
	(ssizeobjargproc)glm_ivec3_sq_ass_item,
	NULL,
	NULL,

	NULL,
	NULL,
};

static
PyBufferProcs glm_ivec3_BufferMethods = {
	(getbufferproc)glm_ivec3_bf_getbuffer,
	NULL,
};

// ivec3 Methods

static
PyObject * glm_ivec3_function_abs(PyObject *self) {
	PyErr_SetString(PyExc_NotImplementedError, "Function not ported.");
	return NULL;
}

PyDoc_STRVAR(glm_ivec3_function_abs__doc__, "Absolute value.");

static
PyMethodDef glm_ivec3Methods[] = {
	{"abs", (PyCFunction) glm_ivec3_function_abs, METH_NOARGS, glm_ivec3_function_abs__doc__},
	{NULL, NULL},
};

PyDoc_STRVAR(glm_ivec3Type__doc__, "A 3D integer vector.");

// ivec3 Object

static
PyTypeObject glm_ivec3Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.ivec3",										/* tp_name */
	sizeof(glm_ivec3),								/* tp_basicsize */
	0,														/* tp_itemsize */
	0,														/* tp_dealloc */
	0,														/* tp_print */
	0,														/* tp_getattr */
	0,														/* tp_setattr */
	0,														/* tp_reserved */
	(reprfunc)glm_ivec3_tp_repr,						/* tp_repr */
	&glm_ivec3_NumberMethods,							/* tp_as_number */
	&glm_ivec3_SequenceMethods,						/* tp_as_sequence */
	0,														/* tp_as_mapping */
	(hashfunc)glm_ivec3_tp_hash,						/* tp_hash  */
	0,														/* tp_call */
	0,														/* tp_str */
	(getattrofunc)glm_ivec3_tp_getattro,				/* tp_getattro */
	(setattrofunc)glm_ivec3_tp_setattro,				/* tp_setattro */
	&glm_ivec3_BufferMethods,							/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	  Py_TPFLAGS_BASETYPE,									/* tp_flags */
	glm_ivec3Type__doc__,								/* tp_doc */
	0,														/* tp_traverse */
	0,														/* tp_clear */
	glm_ivec3_tp_richcompare,							/* tp_richcompare */
	0,														/* tp_weaklistoffset */
	0,														/* tp_iter */
	0,														/* tp_iternext */
	glm_ivec3Methods,									/* tp_methods */
	0,														/* tp_members */
	0,														/* tp_getset */
	0,														/* tp_base */
	0,														/* tp_dict */
	0,														/* tp_descr_get */
	0,														/* tp_descr_set */
	0,														/* tp_dictoffset */
	(initproc)glm_ivec3_tp_init,						/* tp_init */
	0,														/* tp_alloc */
	PyType_GenericNew,										/* tp_new */
};
static
PyNumberMethods glm_ivec4_NumberMethods = {
	(binaryfunc)glm_ivec4_nb_add,
	(binaryfunc)glm_ivec4_nb_subtract,
	(binaryfunc)glm_ivec4_nb_multiply,
	NULL,
	NULL,
	NULL,
	(unaryfunc)glm_ivec4_nb_negative,
	(unaryfunc)glm_ivec4_nb_positive,
	(unaryfunc)glm_ivec4_nb_absolute,
	NULL,
	(unaryfunc)glm_ivec4_nb_invert,
	(binaryfunc)glm_ivec4_nb_lshift,
	(binaryfunc)glm_ivec4_nb_rshift,
	(binaryfunc)glm_ivec4_nb_and,
	(binaryfunc)glm_ivec4_nb_xor,
	(binaryfunc)glm_ivec4_nb_or,
	NULL,
	NULL,
	NULL,

	(binaryfunc)glm_ivec4_nb_inplace_add,
	(binaryfunc)glm_ivec4_nb_inplace_subtract,
	(binaryfunc)glm_ivec4_nb_inplace_multiply,
	NULL,
	NULL,
	(binaryfunc)glm_ivec4_nb_inplace_lshift,
	(binaryfunc)glm_ivec4_nb_inplace_rshift,
	(binaryfunc)glm_ivec4_nb_inplace_and,
	(binaryfunc)glm_ivec4_nb_inplace_xor,
	(binaryfunc)glm_ivec4_nb_inplace_or,
	(binaryfunc)glm_ivec4_nb_true_divide,
	(binaryfunc)glm_ivec4_nb_true_divide,
	(binaryfunc)glm_ivec4_nb_inplace_true_divide,
	(binaryfunc)glm_ivec4_nb_inplace_true_divide,

	NULL,
};

static
PySequenceMethods glm_ivec4_SequenceMethods = {
	(lenfunc)glm_ivec4_sq_length,
	NULL,
	NULL,
	(ssizeargfunc)glm_ivec4_sq_item,
	NULL,
	(ssizeobjargproc)glm_ivec4_sq_ass_item,
	NULL,
	NULL,

	NULL,
	NULL,
};

static
PyBufferProcs glm_ivec4_BufferMethods = {
	(getbufferproc)glm_ivec4_bf_getbuffer,
	NULL,
};

// ivec4 Methods

static
PyObject * glm_ivec4_function_abs(PyObject *self) {
	PyErr_SetString(PyExc_NotImplementedError, "Function not ported.");
	return NULL;
}

PyDoc_STRVAR(glm_ivec4_function_abs__doc__, "Absolute value.");

static
PyMethodDef glm_ivec4Methods[] = {
	{"abs", (PyCFunction) glm_ivec4_function_abs, METH_NOARGS, glm_ivec4_function_abs__doc__},
	{NULL, NULL},
};

PyDoc_STRVAR(glm_ivec4Type__doc__, "A 4D integer vector.");

// ivec4 Object

static
PyTypeObject glm_ivec4Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.ivec4",										/* tp_name */
	sizeof(glm_ivec4),								/* tp_basicsize */
	0,														/* tp_itemsize */
	0,														/* tp_dealloc */
	0,														/* tp_print */
	0,														/* tp_getattr */
	0,														/* tp_setattr */
	0,														/* tp_reserved */
	(reprfunc)glm_ivec4_tp_repr,						/* tp_repr */
	&glm_ivec4_NumberMethods,							/* tp_as_number */
	&glm_ivec4_SequenceMethods,						/* tp_as_sequence */
	0,														/* tp_as_mapping */
	(hashfunc)glm_ivec4_tp_hash,						/* tp_hash  */
	0,														/* tp_call */
	0,														/* tp_str */
	(getattrofunc)glm_ivec4_tp_getattro,				/* tp_getattro */
	(setattrofunc)glm_ivec4_tp_setattro,				/* tp_setattro */
	&glm_ivec4_BufferMethods,							/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	  Py_TPFLAGS_BASETYPE,									/* tp_flags */
	glm_ivec4Type__doc__,								/* tp_doc */
	0,														/* tp_traverse */
	0,														/* tp_clear */
	glm_ivec4_tp_richcompare,							/* tp_richcompare */
	0,														/* tp_weaklistoffset */
	0,														/* tp_iter */
	0,														/* tp_iternext */
	glm_ivec4Methods,									/* tp_methods */
	0,														/* tp_members */
	0,														/* tp_getset */
	0,														/* tp_base */
	0,														/* tp_dict */
	0,														/* tp_descr_get */
	0,														/* tp_descr_set */
	0,														/* tp_dictoffset */
	(initproc)glm_ivec4_tp_init,						/* tp_init */
	0,														/* tp_alloc */
	PyType_GenericNew,										/* tp_new */
};

/* * * Vector Iterator * * */

static
PyObject * glm_VectorIterator_tp_iternext(PyObject *self) {
	PyObject *result;
	glm_VectorIterator *iter = (glm_VectorIterator *)self;
	
	if(iter->obj == NULL) {
		PyErr_SetString(PyExc_TypeError, "Vector is invalid.");
		return NULL;
	}
	
	Py_ssize_t len = PyObject_Size(iter->obj);
	
	if(len < 0) {
		std::string s = "'";
		s += Py_TYPE(iter->obj)->tp_name;
		s += "' is not an iterable vector.";
		PyErr_SetString(PyExc_TypeError, s.c_str());
		return NULL;
	}
	
	if(iter->offset > len - 1)
		return NULL;
	
	result = PySequence_GetItem(iter->obj, iter->offset);
	
	if(result == NULL)
		return NULL;
	
	iter->offset += 1;
	
	return result;
}

static
PyObject * glm_VectorIterator_tp_iter(PyObject *self) {
	PyObject *result;
	PyObject *args = Py_BuildValue("(O)", ((glm_VectorIterator *)self)->obj);
	
	if(args == NULL)
		return NULL;
	
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
	Py_DECREF(args);
	return result;
}

static
int glm_VectorIterator_tp_init(PyObject *self, PyObject *args, PyObject *kwargs) {
	glm_VectorIterator *real;
	PyObject *obj;
	
	real = (glm_VectorIterator *)self;
	real->offset = 0;
	
	if(!PyArg_ParseTuple(args, "O:VectorIterator", &obj)) {
		real->obj = NULL;
		return -1;
	}
	
	if(obj == NULL) {
		real->obj = NULL;
	}
	else {
		Py_INCREF(obj);
		real->obj = obj;
	}
	
	return 0;
}

static int
glm_VectorIterator_tp_traverse(glm_VectorIterator *self, visitproc visit, void *arg)
{
    Py_VISIT(self->obj);
    return 0;
}

static int
glm_VectorIterator_tp_clear(glm_VectorIterator *self)
{
    Py_CLEAR(self->obj);
    return 0;
}

static void
glm_VectorIterator_tp_dealloc(glm_VectorIterator* self)
{
    glm_VectorIterator_tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

PyDoc_STRVAR(glm_VectorIterator__doc__, "A Vector iterator.");

static
PyTypeObject glm_VectorIteratorType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.VectorIterator",								/* tp_name */
	sizeof(glm_VectorIterator),						/* tp_basicsize */
	0,													/* tp_itemsize */
	(destructor)glm_VectorIterator_tp_dealloc,			/* tp_dealloc */
	0,													/* tp_print */
	0,													/* tp_getattr */
	0,													/* tp_setattr */
	0,													/* tp_reserved */
	0,													/* tp_repr */
	0,													/* tp_as_number */
	0,													/* tp_as_sequence */
	0,													/* tp_as_mapping */
	0,													/* tp_hash  */
	0,													/* tp_call */
	0,													/* tp_str */
	PyObject_GenericGetAttr,							/* tp_getattro */
	PyObject_GenericSetAttr,							/* tp_setattro */
	0,													/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC,			/* tp_flags */
	glm_VectorIterator__doc__,							/* tp_doc */
	(traverseproc)glm_VectorIterator_tp_traverse,		/* tp_traverse */
	(inquiry)glm_VectorIterator_tp_clear,				/* tp_clear */
	0,													/* tp_richcompare */
	0,													/* tp_weaklistoffset */
	(getiterfunc)glm_VectorIterator_tp_iter,			/* tp_iter */
	(iternextfunc)glm_VectorIterator_tp_iternext,		/* tp_iternext */
	0,													/* tp_methods */
	0,													/* tp_members */
	0,													/* tp_getset */
	0,													/* tp_base */
	0,													/* tp_dict */
	0,													/* tp_descr_get */
	0,													/* tp_descr_set */
	0,													/* tp_dictoffset */
	(initproc)glm_VectorIterator_tp_init,				/* tp_init */
	0,													/* tp_alloc */
	PyType_GenericNew,									/* tp_new */
};

/* * * Matrix Iterator * * */

static
PyObject * glm_MatrixIterator_tp_iternext(PyObject *self) {
	PyObject *result;
	glm_MatrixIterator *iter = (glm_MatrixIterator *)self;
	
	if(iter->obj == NULL) {
		PyErr_SetString(PyExc_TypeError, "Matrix is invalid.");
		return NULL;
	}
	
	Py_ssize_t len = PyObject_Size(iter->obj);
	
	if(len < 0) {
		std::string s = "'";
		s += Py_TYPE(iter->obj)->tp_name;
		s += "' is not an iterable matrix.";
		PyErr_SetString(PyExc_TypeError, s.c_str());
		return NULL;
	}
	
	if(iter->offset > len - 1)
		return NULL;
	
	result = PySequence_GetItem(iter->obj, iter->offset);
	
	if(result == NULL)
		return NULL;
	
	iter->offset += 1;
	
	return result;
}

static
PyObject * glm_MatrixIterator_tp_iter(PyObject *self) {
	PyObject *result;
	PyObject *args = Py_BuildValue("(O)", ((glm_MatrixIterator *)self)->obj);
	
	if(args == NULL)
		return NULL;
	
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
	Py_DECREF(args);
	return result;
}

static
int glm_MatrixIterator_tp_init(PyObject *self, PyObject *args, PyObject *kwargs) {
	glm_MatrixIterator *real;
	PyObject *obj;
	
	real = (glm_MatrixIterator *)self;
	real->offset = 0;
	
	if(!PyArg_ParseTuple(args, "O:MatrixIterator", &obj)) {
		real->obj = NULL;
		return -1;
	}
	
	if(obj == NULL) {
		real->obj = NULL;
	}
	else {
		Py_INCREF(obj);
		real->obj = obj;
	}
	
	return 0;
}

static int
glm_MatrixIterator_tp_traverse(glm_MatrixIterator *self, visitproc visit, void *arg)
{
    Py_VISIT(self->obj);
    return 0;
}

static int
glm_MatrixIterator_tp_clear(glm_MatrixIterator *self)
{
    Py_CLEAR(self->obj);
    return 0;
}

static void
glm_MatrixIterator_tp_dealloc(glm_MatrixIterator* self)
{
    glm_MatrixIterator_tp_clear(self);
    Py_TYPE(self)->tp_free((PyObject*)self);
}

PyDoc_STRVAR(glm_MatrixIterator__doc__, "A Matrix iterator.");

static
PyTypeObject glm_MatrixIteratorType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.MatrixIterator",								/* tp_name */
	sizeof(glm_MatrixIterator),						/* tp_basicsize */
	0,													/* tp_itemsize */
	(destructor)glm_MatrixIterator_tp_dealloc,			/* tp_dealloc */
	0,													/* tp_print */
	0,													/* tp_getattr */
	0,													/* tp_setattr */
	0,													/* tp_reserved */
	0,													/* tp_repr */
	0,													/* tp_as_number */
	0,													/* tp_as_sequence */
	0,													/* tp_as_mapping */
	0,													/* tp_hash  */
	0,													/* tp_call */
	0,													/* tp_str */
	PyObject_GenericGetAttr,							/* tp_getattro */
	PyObject_GenericSetAttr,							/* tp_setattro */
	0,													/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC,			/* tp_flags */
	glm_MatrixIterator__doc__,							/* tp_doc */
	(traverseproc)glm_MatrixIterator_tp_traverse,		/* tp_traverse */
	(inquiry)glm_MatrixIterator_tp_clear,				/* tp_clear */
	0,													/* tp_richcompare */
	0,													/* tp_weaklistoffset */
	(getiterfunc)glm_MatrixIterator_tp_iter,			/* tp_iter */
	(iternextfunc)glm_MatrixIterator_tp_iternext,		/* tp_iternext */
	0,													/* tp_methods */
	0,													/* tp_members */
	0,													/* tp_getset */
	0,													/* tp_base */
	0,													/* tp_dict */
	0,													/* tp_descr_get */
	0,													/* tp_descr_set */
	0,													/* tp_dictoffset */
	(initproc)glm_MatrixIterator_tp_init,				/* tp_init */
	0,													/* tp_alloc */
	PyType_GenericNew,									/* tp_new */
};

/* * * mat2 * * */

/* mat2: Numbers */

static
PyObject *glm_mat2_nb_add(PyObject *self, PyObject *other) {
	PyObject *result;
	
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2 *)result)->mat = ((glm_mat2 *)self)->mat + (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat2 *)result)->mat = (float)PyFloat_AsDouble(self) + ((glm_mat2 *)other)->mat;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2 *)result)->mat = ((glm_mat2 *)self)->mat + ((glm_mat2 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat2_nb_subtract(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2 *)result)->mat = ((glm_mat2 *)self)->mat - (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat2 *)result)->mat = (float)PyFloat_AsDouble(self) - ((glm_mat2 *)other)->mat;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2 *)result)->mat = ((glm_mat2 *)self)->mat - ((glm_mat2 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat2_nb_multiply(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2 *)result)->mat = ((glm_mat2 *)self)->mat * (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat2 *)result)->mat = (float)PyFloat_AsDouble(self) * ((glm_mat2 *)other)->mat;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2 *)result)->mat = ((glm_mat2 *)self)->mat * ((glm_mat2 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat2_nb_negative(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_mat2 *)result)->mat = -((glm_mat2 *)self)->mat;
	return result;
}

static
PyObject *glm_mat2_nb_positive(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	return result;
}

static
PyObject *glm_mat2_nb_inplace_add(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat2 *)self)->mat += (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2Type))
		((glm_mat2 *)self)->mat += ((glm_mat2 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat2_nb_inplace_subtract(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat2 *)self)->mat -= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2Type))
		((glm_mat2 *)self)->mat -= ((glm_mat2 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat2_nb_inplace_multiply(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat2 *)self)->mat *= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2Type))
		((glm_mat2 *)self)->mat *= ((glm_mat2 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat2_nb_true_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2 *)result)->mat = ((glm_mat2 *)self)->mat / (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat2 *)result)->mat = (float)PyFloat_AsDouble(self) / ((glm_mat2 *)other)->mat;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2 *)result)->mat = ((glm_mat2 *)self)->mat / ((glm_mat2 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat2_nb_inplace_true_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat2 *)self)->mat /= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2Type))
		((glm_mat2 *)self)->mat /= ((glm_mat2 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

/* mat2: Sequence */

static
Py_ssize_t glm_mat2_sq_length(PyObject *self) {
	return 4;
}

static
PyObject *glm_mat2_sq_item(PyObject *self, Py_ssize_t item) {
	PyObject *result;
	if(item >= 4) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return NULL;
	}
	
	result = PyFloat_FromDouble((double)((glm_mat2 *)self)->mat[item/2][item%2]);
	return result;
}

static
int glm_mat2_sq_ass_item(PyObject *self, Py_ssize_t item, PyObject *value) {
	if(item >= 4) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return -1;
	}
	
	if(!PyNumber_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return -1;
	}
	
	((glm_mat2 *)self)->mat[item/2][item%2] = (float)PyFloat_AsDouble(value);
	
	return 0;
}

/* Definition */

static
PyObject * glm_mat2_tp_repr(PyObject *self) {
	glm::mat2 *v = &((glm_mat2 *)self)->mat;
	std::stringstream s;
	s.precision(std::numeric_limits<float>::digits10);
	s << Py_TYPE(self)->tp_name << "("
	 << (*v)[0][0]
	<< ", " << (*v)[0][1]
	<< ", " << (*v)[1][0]
	<< ", " << (*v)[1][1]
	<< ")";
	PyObject *result = PyUnicode_FromString(s.str().c_str());
	return result;
}

static
int glm_mat2_tp_init(PyObject *self, PyObject *args, PyObject *kwargs) {
	if(1 != PyObject_IsInstance(self, (PyObject *)&glm_mat2Type)) {
		PyErr_SetString(PyExc_TypeError, "Can only init mat2.");
		return -1;
	}
	
	glm_mat2 *real = (glm_mat2 *)self;
	
	Py_ssize_t argsize = PyTuple_GET_SIZE(args);
	
	if(argsize == 0) {
		real->mat = glm::mat2();
		return 0;
	}
	
	if(argsize == 1) {
		PyObject *tmp;
		tmp = PyTuple_GET_ITEM(args, 0);
		
		if(PyNumber_Check(tmp)) {
			real->mat = glm::mat2((float)PyFloat_AsDouble(tmp));
			return 0;
		}
		
		if(PyBytes_CheckExact(tmp)) {
			memcpy(&real->mat, PyBytes_AsString(tmp), sizeof(float) * 4);
			
			return 0;
		}
	}
	
	real->mat = glm::mat2();
	
	PyObject *tmp;
	Py_ssize_t i;
	Py_ssize_t at = 0;

	for(i = 0; i < argsize; i++) {
		tmp = PyTuple_GET_ITEM(args, i);

		if(PyBytes_CheckExact(tmp)) {
			size_t len = PyBytes_Size(tmp) / sizeof(float);
			
			if(at + len > 3)
				len = 4 - at;
			
			memcpy(glm::value_ptr(real->mat) + at, PyBytes_AsString(tmp), len * sizeof(float));
			
			at += len;
		}
		else if(PyIter_Check(tmp) || Py_TYPE(tmp)->tp_iter) {
			PyObject *tmpi = PyObject_GetIter(tmp);
			PyObject *item;
	
			while(1) {
				item = PyIter_Next(tmpi);
				if(item == NULL)
					break;
		
				real->mat[at/2][at%2] = (float)PyFloat_AsDouble(item);
		
				Py_DECREF(item);
				at += 1;
			}
	
			Py_DECREF(tmpi);
		}
		else if(PyNumber_Check(tmp)) {
			real->mat[at/2][at%2] = (float)PyFloat_AsDouble(tmp);

			at += 1;
		}
		else {
			PyErr_Format(PyExc_TypeError, "Initialization only accepts numbers, sequences, and bytes as arguments, not '%s' at argument %i.", Py_TYPE(tmp)->tp_name, (int)at);
			return -1;
		}
		
		if(at > 4) {
			PyErr_SetString(PyExc_TypeError, "Too much data.");
			return -1;
		}
	}
	
	return 0;
}

int glm_mat2_bf_getbuffer(PyObject *self, Py_buffer *view, int flags) {
	PyBuffer_FillInfo(view, self, glm::value_ptr(((glm_mat2 *)self)->mat), sizeof(float) * 4, 1, PyBUF_SIMPLE);
	return 0;
}

PyObject *glm_mat2_tp_richcompare(PyObject *self, PyObject *other, int op) {
	switch(op) {
		case Py_EQ:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat2Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_EQ))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat2Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat2 *)self)->mat == ((glm_mat2 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		case Py_NE:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat2Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_NE))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat2Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat2 *)self)->mat != ((glm_mat2 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		default:
			PyErr_SetString(PyExc_TypeError, "Comparison not valid.");
			return NULL;
	}
}

Py_hash_t glm_mat2_tp_hash(PyObject *self) {
	Py_hash_t x;

	x = _Py_HashDouble((double)((glm_mat2 *)self)->mat[0][0]);
	x ^= _Py_HashDouble((double)((glm_mat2 *)self)->mat[0][1]) << 7;
	x ^= _Py_HashDouble((double)((glm_mat2 *)self)->mat[1][0]) << 15;
	x ^= _Py_HashDouble((double)((glm_mat2 *)self)->mat[1][1]) << 23;
	
	if(x == -1)
		x = -2;
	
	return x;
}

/* * * mat3x2 * * */

/* mat3x2: Numbers */

static
PyObject *glm_mat3x2_nb_add(PyObject *self, PyObject *other) {
	PyObject *result;
	
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3x2 *)result)->mat = ((glm_mat3x2 *)self)->mat + (float)PyFloat_AsDouble(other);
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3x2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3x2 *)result)->mat = ((glm_mat3x2 *)self)->mat + ((glm_mat3x2 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat3x2_nb_subtract(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3x2 *)result)->mat = ((glm_mat3x2 *)self)->mat - (float)PyFloat_AsDouble(other);
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3x2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3x2 *)result)->mat = ((glm_mat3x2 *)self)->mat - ((glm_mat3x2 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat3x2_nb_multiply(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3x2 *)result)->mat = ((glm_mat3x2 *)self)->mat * (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3x2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat3x2 *)result)->mat = (float)PyFloat_AsDouble(self) * ((glm_mat3x2 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat3x2_nb_negative(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_mat3x2 *)result)->mat = -((glm_mat3x2 *)self)->mat;
	return result;
}

static
PyObject *glm_mat3x2_nb_positive(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	return result;
}

static
PyObject *glm_mat3x2_nb_inplace_add(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat3x2 *)self)->mat += (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3x2Type))
		((glm_mat3x2 *)self)->mat += ((glm_mat3x2 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat3x2_nb_inplace_subtract(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat3x2 *)self)->mat -= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3x2Type))
		((glm_mat3x2 *)self)->mat -= ((glm_mat3x2 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat3x2_nb_inplace_multiply(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat3x2 *)self)->mat *= (float)PyFloat_AsDouble(other);
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat3x2_nb_true_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3x2 *)result)->mat = ((glm_mat3x2 *)self)->mat / (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3x2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat3x2 *)result)->mat = (float)PyFloat_AsDouble(self) / ((glm_mat3x2 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat3x2_nb_inplace_true_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat3x2 *)self)->mat /= (float)PyFloat_AsDouble(other);
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

/* mat3x2: Sequence */

static
Py_ssize_t glm_mat3x2_sq_length(PyObject *self) {
	return 6;
}

static
PyObject *glm_mat3x2_sq_item(PyObject *self, Py_ssize_t item) {
	PyObject *result;
	if(item >= 6) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return NULL;
	}
	
	result = PyFloat_FromDouble((double)((glm_mat3x2 *)self)->mat[item/3][item%3]);
	return result;
}

static
int glm_mat3x2_sq_ass_item(PyObject *self, Py_ssize_t item, PyObject *value) {
	if(item >= 6) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return -1;
	}
	
	if(!PyNumber_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return -1;
	}
	
	((glm_mat3x2 *)self)->mat[item/3][item%3] = (float)PyFloat_AsDouble(value);
	
	return 0;
}

/* Definition */

static
PyObject * glm_mat3x2_tp_repr(PyObject *self) {
	glm::mat3x2 *v = &((glm_mat3x2 *)self)->mat;
	std::stringstream s;
	s.precision(std::numeric_limits<float>::digits10);
	s << Py_TYPE(self)->tp_name << "("
	 << (*v)[0][0]
	<< ", " << (*v)[0][1]
	<< ", " << (*v)[0][2]
	<< ", " << (*v)[1][0]
	<< ", " << (*v)[1][1]
	<< ", " << (*v)[1][2]
	<< ")";
	PyObject *result = PyUnicode_FromString(s.str().c_str());
	return result;
}

static
int glm_mat3x2_tp_init(PyObject *self, PyObject *args, PyObject *kwargs) {
	if(1 != PyObject_IsInstance(self, (PyObject *)&glm_mat3x2Type)) {
		PyErr_SetString(PyExc_TypeError, "Can only init mat3x2.");
		return -1;
	}
	
	glm_mat3x2 *real = (glm_mat3x2 *)self;
	
	Py_ssize_t argsize = PyTuple_GET_SIZE(args);
	
	if(argsize == 0) {
		real->mat = glm::mat3x2();
		return 0;
	}
	
	if(argsize == 1) {
		PyObject *tmp;
		tmp = PyTuple_GET_ITEM(args, 0);
		
		if(PyNumber_Check(tmp)) {
			real->mat = glm::mat3x2((float)PyFloat_AsDouble(tmp));
			return 0;
		}
		
		if(PyBytes_CheckExact(tmp)) {
			memcpy(&real->mat, PyBytes_AsString(tmp), sizeof(float) * 6);
			
			return 0;
		}
	}
	
	real->mat = glm::mat3x2();
	
	PyObject *tmp;
	Py_ssize_t i;
	Py_ssize_t at = 0;

	for(i = 0; i < argsize; i++) {
		tmp = PyTuple_GET_ITEM(args, i);

		if(PyBytes_CheckExact(tmp)) {
			size_t len = PyBytes_Size(tmp) / sizeof(float);
			
			if(at + len > 5)
				len = 6 - at;
			
			memcpy(glm::value_ptr(real->mat) + at, PyBytes_AsString(tmp), len * sizeof(float));
			
			at += len;
		}
		else if(PyIter_Check(tmp) || Py_TYPE(tmp)->tp_iter) {
			PyObject *tmpi = PyObject_GetIter(tmp);
			PyObject *item;
	
			while(1) {
				item = PyIter_Next(tmpi);
				if(item == NULL)
					break;
		
				real->mat[at/3][at%3] = (float)PyFloat_AsDouble(item);
		
				Py_DECREF(item);
				at += 1;
			}
	
			Py_DECREF(tmpi);
		}
		else if(PyNumber_Check(tmp)) {
			real->mat[at/3][at%3] = (float)PyFloat_AsDouble(tmp);

			at += 1;
		}
		else {
			PyErr_Format(PyExc_TypeError, "Initialization only accepts numbers, sequences, and bytes as arguments, not '%s' at argument %i.", Py_TYPE(tmp)->tp_name, (int)at);
			return -1;
		}
		
		if(at > 6) {
			PyErr_SetString(PyExc_TypeError, "Too much data.");
			return -1;
		}
	}
	
	return 0;
}

int glm_mat3x2_bf_getbuffer(PyObject *self, Py_buffer *view, int flags) {
	PyBuffer_FillInfo(view, self, glm::value_ptr(((glm_mat3x2 *)self)->mat), sizeof(float) * 6, 1, PyBUF_SIMPLE);
	return 0;
}

PyObject *glm_mat3x2_tp_richcompare(PyObject *self, PyObject *other, int op) {
	switch(op) {
		case Py_EQ:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat3x2Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_EQ))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat3x2Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat3x2 *)self)->mat == ((glm_mat3x2 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		case Py_NE:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat3x2Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_NE))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat3x2Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat3x2 *)self)->mat != ((glm_mat3x2 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		default:
			PyErr_SetString(PyExc_TypeError, "Comparison not valid.");
			return NULL;
	}
}

Py_hash_t glm_mat3x2_tp_hash(PyObject *self) {
	Py_hash_t x;

	x = _Py_HashDouble((double)((glm_mat3x2 *)self)->mat[0][0]);
	x ^= _Py_HashDouble((double)((glm_mat3x2 *)self)->mat[0][1]) << 5;
	x ^= _Py_HashDouble((double)((glm_mat3x2 *)self)->mat[0][2]) << 10;
	x ^= _Py_HashDouble((double)((glm_mat3x2 *)self)->mat[1][0]) << 15;
	x ^= _Py_HashDouble((double)((glm_mat3x2 *)self)->mat[1][1]) << 20;
	x ^= _Py_HashDouble((double)((glm_mat3x2 *)self)->mat[1][2]) << 25;
	
	if(x == -1)
		x = -2;
	
	return x;
}

/* * * mat4x2 * * */

/* mat4x2: Numbers */

static
PyObject *glm_mat4x2_nb_add(PyObject *self, PyObject *other) {
	PyObject *result;
	
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4x2 *)result)->mat = ((glm_mat4x2 *)self)->mat + (float)PyFloat_AsDouble(other);
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4x2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4x2 *)result)->mat = ((glm_mat4x2 *)self)->mat + ((glm_mat4x2 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat4x2_nb_subtract(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4x2 *)result)->mat = ((glm_mat4x2 *)self)->mat - (float)PyFloat_AsDouble(other);
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4x2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4x2 *)result)->mat = ((glm_mat4x2 *)self)->mat - ((glm_mat4x2 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat4x2_nb_multiply(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4x2 *)result)->mat = ((glm_mat4x2 *)self)->mat * (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4x2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat4x2 *)result)->mat = (float)PyFloat_AsDouble(self) * ((glm_mat4x2 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat4x2_nb_negative(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_mat4x2 *)result)->mat = -((glm_mat4x2 *)self)->mat;
	return result;
}

static
PyObject *glm_mat4x2_nb_positive(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	return result;
}

static
PyObject *glm_mat4x2_nb_inplace_add(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat4x2 *)self)->mat += (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4x2Type))
		((glm_mat4x2 *)self)->mat += ((glm_mat4x2 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat4x2_nb_inplace_subtract(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat4x2 *)self)->mat -= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4x2Type))
		((glm_mat4x2 *)self)->mat -= ((glm_mat4x2 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat4x2_nb_inplace_multiply(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat4x2 *)self)->mat *= (float)PyFloat_AsDouble(other);
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat4x2_nb_true_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4x2 *)result)->mat = ((glm_mat4x2 *)self)->mat / (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4x2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat4x2 *)result)->mat = (float)PyFloat_AsDouble(self) / ((glm_mat4x2 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat4x2_nb_inplace_true_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat4x2 *)self)->mat /= (float)PyFloat_AsDouble(other);
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

/* mat4x2: Sequence */

static
Py_ssize_t glm_mat4x2_sq_length(PyObject *self) {
	return 8;
}

static
PyObject *glm_mat4x2_sq_item(PyObject *self, Py_ssize_t item) {
	PyObject *result;
	if(item >= 8) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return NULL;
	}
	
	result = PyFloat_FromDouble((double)((glm_mat4x2 *)self)->mat[item/4][item%4]);
	return result;
}

static
int glm_mat4x2_sq_ass_item(PyObject *self, Py_ssize_t item, PyObject *value) {
	if(item >= 8) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return -1;
	}
	
	if(!PyNumber_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return -1;
	}
	
	((glm_mat4x2 *)self)->mat[item/4][item%4] = (float)PyFloat_AsDouble(value);
	
	return 0;
}

/* Definition */

static
PyObject * glm_mat4x2_tp_repr(PyObject *self) {
	glm::mat4x2 *v = &((glm_mat4x2 *)self)->mat;
	std::stringstream s;
	s.precision(std::numeric_limits<float>::digits10);
	s << Py_TYPE(self)->tp_name << "("
	 << (*v)[0][0]
	<< ", " << (*v)[0][1]
	<< ", " << (*v)[0][2]
	<< ", " << (*v)[0][3]
	<< ", " << (*v)[1][0]
	<< ", " << (*v)[1][1]
	<< ", " << (*v)[1][2]
	<< ", " << (*v)[1][3]
	<< ")";
	PyObject *result = PyUnicode_FromString(s.str().c_str());
	return result;
}

static
int glm_mat4x2_tp_init(PyObject *self, PyObject *args, PyObject *kwargs) {
	if(1 != PyObject_IsInstance(self, (PyObject *)&glm_mat4x2Type)) {
		PyErr_SetString(PyExc_TypeError, "Can only init mat4x2.");
		return -1;
	}
	
	glm_mat4x2 *real = (glm_mat4x2 *)self;
	
	Py_ssize_t argsize = PyTuple_GET_SIZE(args);
	
	if(argsize == 0) {
		real->mat = glm::mat4x2();
		return 0;
	}
	
	if(argsize == 1) {
		PyObject *tmp;
		tmp = PyTuple_GET_ITEM(args, 0);
		
		if(PyNumber_Check(tmp)) {
			real->mat = glm::mat4x2((float)PyFloat_AsDouble(tmp));
			return 0;
		}
		
		if(PyBytes_CheckExact(tmp)) {
			memcpy(&real->mat, PyBytes_AsString(tmp), sizeof(float) * 8);
			
			return 0;
		}
	}
	
	real->mat = glm::mat4x2();
	
	PyObject *tmp;
	Py_ssize_t i;
	Py_ssize_t at = 0;

	for(i = 0; i < argsize; i++) {
		tmp = PyTuple_GET_ITEM(args, i);

		if(PyBytes_CheckExact(tmp)) {
			size_t len = PyBytes_Size(tmp) / sizeof(float);
			
			if(at + len > 7)
				len = 8 - at;
			
			memcpy(glm::value_ptr(real->mat) + at, PyBytes_AsString(tmp), len * sizeof(float));
			
			at += len;
		}
		else if(PyIter_Check(tmp) || Py_TYPE(tmp)->tp_iter) {
			PyObject *tmpi = PyObject_GetIter(tmp);
			PyObject *item;
	
			while(1) {
				item = PyIter_Next(tmpi);
				if(item == NULL)
					break;
		
				real->mat[at/4][at%4] = (float)PyFloat_AsDouble(item);
		
				Py_DECREF(item);
				at += 1;
			}
	
			Py_DECREF(tmpi);
		}
		else if(PyNumber_Check(tmp)) {
			real->mat[at/4][at%4] = (float)PyFloat_AsDouble(tmp);

			at += 1;
		}
		else {
			PyErr_Format(PyExc_TypeError, "Initialization only accepts numbers, sequences, and bytes as arguments, not '%s' at argument %i.", Py_TYPE(tmp)->tp_name, (int)at);
			return -1;
		}
		
		if(at > 8) {
			PyErr_SetString(PyExc_TypeError, "Too much data.");
			return -1;
		}
	}
	
	return 0;
}

int glm_mat4x2_bf_getbuffer(PyObject *self, Py_buffer *view, int flags) {
	PyBuffer_FillInfo(view, self, glm::value_ptr(((glm_mat4x2 *)self)->mat), sizeof(float) * 8, 1, PyBUF_SIMPLE);
	return 0;
}

PyObject *glm_mat4x2_tp_richcompare(PyObject *self, PyObject *other, int op) {
	switch(op) {
		case Py_EQ:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat4x2Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_EQ))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat4x2Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat4x2 *)self)->mat == ((glm_mat4x2 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		case Py_NE:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat4x2Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_NE))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat4x2Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat4x2 *)self)->mat != ((glm_mat4x2 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		default:
			PyErr_SetString(PyExc_TypeError, "Comparison not valid.");
			return NULL;
	}
}

Py_hash_t glm_mat4x2_tp_hash(PyObject *self) {
	Py_hash_t x;

	x = _Py_HashDouble((double)((glm_mat4x2 *)self)->mat[0][0]);
	x ^= _Py_HashDouble((double)((glm_mat4x2 *)self)->mat[0][1]) << 3;
	x ^= _Py_HashDouble((double)((glm_mat4x2 *)self)->mat[0][2]) << 7;
	x ^= _Py_HashDouble((double)((glm_mat4x2 *)self)->mat[0][3]) << 11;
	x ^= _Py_HashDouble((double)((glm_mat4x2 *)self)->mat[1][0]) << 15;
	x ^= _Py_HashDouble((double)((glm_mat4x2 *)self)->mat[1][1]) << 19;
	x ^= _Py_HashDouble((double)((glm_mat4x2 *)self)->mat[1][2]) << 23;
	x ^= _Py_HashDouble((double)((glm_mat4x2 *)self)->mat[1][3]) << 27;
	
	if(x == -1)
		x = -2;
	
	return x;
}

/* * * mat2x3 * * */

/* mat2x3: Numbers */

static
PyObject *glm_mat2x3_nb_add(PyObject *self, PyObject *other) {
	PyObject *result;
	
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2x3 *)result)->mat = ((glm_mat2x3 *)self)->mat + (float)PyFloat_AsDouble(other);
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2x3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2x3 *)result)->mat = ((glm_mat2x3 *)self)->mat + ((glm_mat2x3 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat2x3_nb_subtract(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2x3 *)result)->mat = ((glm_mat2x3 *)self)->mat - (float)PyFloat_AsDouble(other);
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2x3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2x3 *)result)->mat = ((glm_mat2x3 *)self)->mat - ((glm_mat2x3 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat2x3_nb_multiply(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2x3 *)result)->mat = ((glm_mat2x3 *)self)->mat * (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2x3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat2x3 *)result)->mat = (float)PyFloat_AsDouble(self) * ((glm_mat2x3 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat2x3_nb_negative(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_mat2x3 *)result)->mat = -((glm_mat2x3 *)self)->mat;
	return result;
}

static
PyObject *glm_mat2x3_nb_positive(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	return result;
}

static
PyObject *glm_mat2x3_nb_inplace_add(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat2x3 *)self)->mat += (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2x3Type))
		((glm_mat2x3 *)self)->mat += ((glm_mat2x3 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat2x3_nb_inplace_subtract(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat2x3 *)self)->mat -= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2x3Type))
		((glm_mat2x3 *)self)->mat -= ((glm_mat2x3 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat2x3_nb_inplace_multiply(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat2x3 *)self)->mat *= (float)PyFloat_AsDouble(other);
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat2x3_nb_true_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2x3 *)result)->mat = ((glm_mat2x3 *)self)->mat / (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2x3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat2x3 *)result)->mat = (float)PyFloat_AsDouble(self) / ((glm_mat2x3 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat2x3_nb_inplace_true_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat2x3 *)self)->mat /= (float)PyFloat_AsDouble(other);
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

/* mat2x3: Sequence */

static
Py_ssize_t glm_mat2x3_sq_length(PyObject *self) {
	return 6;
}

static
PyObject *glm_mat2x3_sq_item(PyObject *self, Py_ssize_t item) {
	PyObject *result;
	if(item >= 6) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return NULL;
	}
	
	result = PyFloat_FromDouble((double)((glm_mat2x3 *)self)->mat[item/2][item%2]);
	return result;
}

static
int glm_mat2x3_sq_ass_item(PyObject *self, Py_ssize_t item, PyObject *value) {
	if(item >= 6) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return -1;
	}
	
	if(!PyNumber_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return -1;
	}
	
	((glm_mat2x3 *)self)->mat[item/2][item%2] = (float)PyFloat_AsDouble(value);
	
	return 0;
}

/* Definition */

static
PyObject * glm_mat2x3_tp_repr(PyObject *self) {
	glm::mat2x3 *v = &((glm_mat2x3 *)self)->mat;
	std::stringstream s;
	s.precision(std::numeric_limits<float>::digits10);
	s << Py_TYPE(self)->tp_name << "("
	 << (*v)[0][0]
	<< ", " << (*v)[0][1]
	<< ", " << (*v)[1][0]
	<< ", " << (*v)[1][1]
	<< ", " << (*v)[2][0]
	<< ", " << (*v)[2][1]
	<< ")";
	PyObject *result = PyUnicode_FromString(s.str().c_str());
	return result;
}

static
int glm_mat2x3_tp_init(PyObject *self, PyObject *args, PyObject *kwargs) {
	if(1 != PyObject_IsInstance(self, (PyObject *)&glm_mat2x3Type)) {
		PyErr_SetString(PyExc_TypeError, "Can only init mat2x3.");
		return -1;
	}
	
	glm_mat2x3 *real = (glm_mat2x3 *)self;
	
	Py_ssize_t argsize = PyTuple_GET_SIZE(args);
	
	if(argsize == 0) {
		real->mat = glm::mat2x3();
		return 0;
	}
	
	if(argsize == 1) {
		PyObject *tmp;
		tmp = PyTuple_GET_ITEM(args, 0);
		
		if(PyNumber_Check(tmp)) {
			real->mat = glm::mat2x3((float)PyFloat_AsDouble(tmp));
			return 0;
		}
		
		if(PyBytes_CheckExact(tmp)) {
			memcpy(&real->mat, PyBytes_AsString(tmp), sizeof(float) * 6);
			
			return 0;
		}
	}
	
	real->mat = glm::mat2x3();
	
	PyObject *tmp;
	Py_ssize_t i;
	Py_ssize_t at = 0;

	for(i = 0; i < argsize; i++) {
		tmp = PyTuple_GET_ITEM(args, i);

		if(PyBytes_CheckExact(tmp)) {
			size_t len = PyBytes_Size(tmp) / sizeof(float);
			
			if(at + len > 5)
				len = 6 - at;
			
			memcpy(glm::value_ptr(real->mat) + at, PyBytes_AsString(tmp), len * sizeof(float));
			
			at += len;
		}
		else if(PyIter_Check(tmp) || Py_TYPE(tmp)->tp_iter) {
			PyObject *tmpi = PyObject_GetIter(tmp);
			PyObject *item;
	
			while(1) {
				item = PyIter_Next(tmpi);
				if(item == NULL)
					break;
		
				real->mat[at/2][at%2] = (float)PyFloat_AsDouble(item);
		
				Py_DECREF(item);
				at += 1;
			}
	
			Py_DECREF(tmpi);
		}
		else if(PyNumber_Check(tmp)) {
			real->mat[at/2][at%2] = (float)PyFloat_AsDouble(tmp);

			at += 1;
		}
		else {
			PyErr_Format(PyExc_TypeError, "Initialization only accepts numbers, sequences, and bytes as arguments, not '%s' at argument %i.", Py_TYPE(tmp)->tp_name, (int)at);
			return -1;
		}
		
		if(at > 6) {
			PyErr_SetString(PyExc_TypeError, "Too much data.");
			return -1;
		}
	}
	
	return 0;
}

int glm_mat2x3_bf_getbuffer(PyObject *self, Py_buffer *view, int flags) {
	PyBuffer_FillInfo(view, self, glm::value_ptr(((glm_mat2x3 *)self)->mat), sizeof(float) * 6, 1, PyBUF_SIMPLE);
	return 0;
}

PyObject *glm_mat2x3_tp_richcompare(PyObject *self, PyObject *other, int op) {
	switch(op) {
		case Py_EQ:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat2x3Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_EQ))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat2x3Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat2x3 *)self)->mat == ((glm_mat2x3 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		case Py_NE:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat2x3Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_NE))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat2x3Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat2x3 *)self)->mat != ((glm_mat2x3 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		default:
			PyErr_SetString(PyExc_TypeError, "Comparison not valid.");
			return NULL;
	}
}

Py_hash_t glm_mat2x3_tp_hash(PyObject *self) {
	Py_hash_t x;

	x = _Py_HashDouble((double)((glm_mat2x3 *)self)->mat[0][0]);
	x ^= _Py_HashDouble((double)((glm_mat2x3 *)self)->mat[0][1]) << 5;
	x ^= _Py_HashDouble((double)((glm_mat2x3 *)self)->mat[1][0]) << 10;
	x ^= _Py_HashDouble((double)((glm_mat2x3 *)self)->mat[1][1]) << 15;
	x ^= _Py_HashDouble((double)((glm_mat2x3 *)self)->mat[2][0]) << 20;
	x ^= _Py_HashDouble((double)((glm_mat2x3 *)self)->mat[2][1]) << 25;
	
	if(x == -1)
		x = -2;
	
	return x;
}

/* * * mat3 * * */

/* mat3: Numbers */

static
PyObject *glm_mat3_nb_add(PyObject *self, PyObject *other) {
	PyObject *result;
	
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3 *)result)->mat = ((glm_mat3 *)self)->mat + (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat3 *)result)->mat = (float)PyFloat_AsDouble(self) + ((glm_mat3 *)other)->mat;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3 *)result)->mat = ((glm_mat3 *)self)->mat + ((glm_mat3 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat3_nb_subtract(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3 *)result)->mat = ((glm_mat3 *)self)->mat - (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat3 *)result)->mat = (float)PyFloat_AsDouble(self) - ((glm_mat3 *)other)->mat;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3 *)result)->mat = ((glm_mat3 *)self)->mat - ((glm_mat3 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat3_nb_multiply(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3 *)result)->mat = ((glm_mat3 *)self)->mat * (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat3 *)result)->mat = (float)PyFloat_AsDouble(self) * ((glm_mat3 *)other)->mat;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3 *)result)->mat = ((glm_mat3 *)self)->mat * ((glm_mat3 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat3_nb_negative(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_mat3 *)result)->mat = -((glm_mat3 *)self)->mat;
	return result;
}

static
PyObject *glm_mat3_nb_positive(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	return result;
}

static
PyObject *glm_mat3_nb_inplace_add(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat3 *)self)->mat += (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3Type))
		((glm_mat3 *)self)->mat += ((glm_mat3 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat3_nb_inplace_subtract(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat3 *)self)->mat -= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3Type))
		((glm_mat3 *)self)->mat -= ((glm_mat3 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat3_nb_inplace_multiply(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat3 *)self)->mat *= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3Type))
		((glm_mat3 *)self)->mat *= ((glm_mat3 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat3_nb_true_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3 *)result)->mat = ((glm_mat3 *)self)->mat / (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat3 *)result)->mat = (float)PyFloat_AsDouble(self) / ((glm_mat3 *)other)->mat;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3 *)result)->mat = ((glm_mat3 *)self)->mat / ((glm_mat3 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat3_nb_inplace_true_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat3 *)self)->mat /= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3Type))
		((glm_mat3 *)self)->mat /= ((glm_mat3 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

/* mat3: Sequence */

static
Py_ssize_t glm_mat3_sq_length(PyObject *self) {
	return 9;
}

static
PyObject *glm_mat3_sq_item(PyObject *self, Py_ssize_t item) {
	PyObject *result;
	if(item >= 9) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return NULL;
	}
	
	result = PyFloat_FromDouble((double)((glm_mat3 *)self)->mat[item/3][item%3]);
	return result;
}

static
int glm_mat3_sq_ass_item(PyObject *self, Py_ssize_t item, PyObject *value) {
	if(item >= 9) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return -1;
	}
	
	if(!PyNumber_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return -1;
	}
	
	((glm_mat3 *)self)->mat[item/3][item%3] = (float)PyFloat_AsDouble(value);
	
	return 0;
}

/* Definition */

static
PyObject * glm_mat3_tp_repr(PyObject *self) {
	glm::mat3 *v = &((glm_mat3 *)self)->mat;
	std::stringstream s;
	s.precision(std::numeric_limits<float>::digits10);
	s << Py_TYPE(self)->tp_name << "("
	 << (*v)[0][0]
	<< ", " << (*v)[0][1]
	<< ", " << (*v)[0][2]
	<< ", " << (*v)[1][0]
	<< ", " << (*v)[1][1]
	<< ", " << (*v)[1][2]
	<< ", " << (*v)[2][0]
	<< ", " << (*v)[2][1]
	<< ", " << (*v)[2][2]
	<< ")";
	PyObject *result = PyUnicode_FromString(s.str().c_str());
	return result;
}

static
int glm_mat3_tp_init(PyObject *self, PyObject *args, PyObject *kwargs) {
	if(1 != PyObject_IsInstance(self, (PyObject *)&glm_mat3Type)) {
		PyErr_SetString(PyExc_TypeError, "Can only init mat3.");
		return -1;
	}
	
	glm_mat3 *real = (glm_mat3 *)self;
	
	Py_ssize_t argsize = PyTuple_GET_SIZE(args);
	
	if(argsize == 0) {
		real->mat = glm::mat3();
		return 0;
	}
	
	if(argsize == 1) {
		PyObject *tmp;
		tmp = PyTuple_GET_ITEM(args, 0);
		
		if(PyNumber_Check(tmp)) {
			real->mat = glm::mat3((float)PyFloat_AsDouble(tmp));
			return 0;
		}
		
		if(PyBytes_CheckExact(tmp)) {
			memcpy(&real->mat, PyBytes_AsString(tmp), sizeof(float) * 9);
			
			return 0;
		}
	}
	
	real->mat = glm::mat3();
	
	PyObject *tmp;
	Py_ssize_t i;
	Py_ssize_t at = 0;

	for(i = 0; i < argsize; i++) {
		tmp = PyTuple_GET_ITEM(args, i);

		if(PyBytes_CheckExact(tmp)) {
			size_t len = PyBytes_Size(tmp) / sizeof(float);
			
			if(at + len > 8)
				len = 9 - at;
			
			memcpy(glm::value_ptr(real->mat) + at, PyBytes_AsString(tmp), len * sizeof(float));
			
			at += len;
		}
		else if(PyIter_Check(tmp) || Py_TYPE(tmp)->tp_iter) {
			PyObject *tmpi = PyObject_GetIter(tmp);
			PyObject *item;
	
			while(1) {
				item = PyIter_Next(tmpi);
				if(item == NULL)
					break;
		
				real->mat[at/3][at%3] = (float)PyFloat_AsDouble(item);
		
				Py_DECREF(item);
				at += 1;
			}
	
			Py_DECREF(tmpi);
		}
		else if(PyNumber_Check(tmp)) {
			real->mat[at/3][at%3] = (float)PyFloat_AsDouble(tmp);

			at += 1;
		}
		else {
			PyErr_Format(PyExc_TypeError, "Initialization only accepts numbers, sequences, and bytes as arguments, not '%s' at argument %i.", Py_TYPE(tmp)->tp_name, (int)at);
			return -1;
		}
		
		if(at > 9) {
			PyErr_SetString(PyExc_TypeError, "Too much data.");
			return -1;
		}
	}
	
	return 0;
}

int glm_mat3_bf_getbuffer(PyObject *self, Py_buffer *view, int flags) {
	PyBuffer_FillInfo(view, self, glm::value_ptr(((glm_mat3 *)self)->mat), sizeof(float) * 9, 1, PyBUF_SIMPLE);
	return 0;
}

PyObject *glm_mat3_tp_richcompare(PyObject *self, PyObject *other, int op) {
	switch(op) {
		case Py_EQ:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat3Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_EQ))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat3Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat3 *)self)->mat == ((glm_mat3 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		case Py_NE:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat3Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_NE))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat3Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat3 *)self)->mat != ((glm_mat3 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		default:
			PyErr_SetString(PyExc_TypeError, "Comparison not valid.");
			return NULL;
	}
}

Py_hash_t glm_mat3_tp_hash(PyObject *self) {
	Py_hash_t x;

	x = _Py_HashDouble((double)((glm_mat3 *)self)->mat[0][0]);
	x ^= _Py_HashDouble((double)((glm_mat3 *)self)->mat[0][1]) << 3;
	x ^= _Py_HashDouble((double)((glm_mat3 *)self)->mat[0][2]) << 6;
	x ^= _Py_HashDouble((double)((glm_mat3 *)self)->mat[1][0]) << 10;
	x ^= _Py_HashDouble((double)((glm_mat3 *)self)->mat[1][1]) << 13;
	x ^= _Py_HashDouble((double)((glm_mat3 *)self)->mat[1][2]) << 17;
	x ^= _Py_HashDouble((double)((glm_mat3 *)self)->mat[2][0]) << 20;
	x ^= _Py_HashDouble((double)((glm_mat3 *)self)->mat[2][1]) << 24;
	x ^= _Py_HashDouble((double)((glm_mat3 *)self)->mat[2][2]) << 27;
	
	if(x == -1)
		x = -2;
	
	return x;
}

/* * * mat4x3 * * */

/* mat4x3: Numbers */

static
PyObject *glm_mat4x3_nb_add(PyObject *self, PyObject *other) {
	PyObject *result;
	
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4x3 *)result)->mat = ((glm_mat4x3 *)self)->mat + (float)PyFloat_AsDouble(other);
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4x3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4x3 *)result)->mat = ((glm_mat4x3 *)self)->mat + ((glm_mat4x3 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat4x3_nb_subtract(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4x3 *)result)->mat = ((glm_mat4x3 *)self)->mat - (float)PyFloat_AsDouble(other);
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4x3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4x3 *)result)->mat = ((glm_mat4x3 *)self)->mat - ((glm_mat4x3 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat4x3_nb_multiply(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4x3 *)result)->mat = ((glm_mat4x3 *)self)->mat * (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4x3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat4x3 *)result)->mat = (float)PyFloat_AsDouble(self) * ((glm_mat4x3 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat4x3_nb_negative(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_mat4x3 *)result)->mat = -((glm_mat4x3 *)self)->mat;
	return result;
}

static
PyObject *glm_mat4x3_nb_positive(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	return result;
}

static
PyObject *glm_mat4x3_nb_inplace_add(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat4x3 *)self)->mat += (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4x3Type))
		((glm_mat4x3 *)self)->mat += ((glm_mat4x3 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat4x3_nb_inplace_subtract(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat4x3 *)self)->mat -= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4x3Type))
		((glm_mat4x3 *)self)->mat -= ((glm_mat4x3 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat4x3_nb_inplace_multiply(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat4x3 *)self)->mat *= (float)PyFloat_AsDouble(other);
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat4x3_nb_true_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4x3 *)result)->mat = ((glm_mat4x3 *)self)->mat / (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4x3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat4x3 *)result)->mat = (float)PyFloat_AsDouble(self) / ((glm_mat4x3 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat4x3_nb_inplace_true_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat4x3 *)self)->mat /= (float)PyFloat_AsDouble(other);
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

/* mat4x3: Sequence */

static
Py_ssize_t glm_mat4x3_sq_length(PyObject *self) {
	return 12;
}

static
PyObject *glm_mat4x3_sq_item(PyObject *self, Py_ssize_t item) {
	PyObject *result;
	if(item >= 12) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return NULL;
	}
	
	result = PyFloat_FromDouble((double)((glm_mat4x3 *)self)->mat[item/4][item%4]);
	return result;
}

static
int glm_mat4x3_sq_ass_item(PyObject *self, Py_ssize_t item, PyObject *value) {
	if(item >= 12) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return -1;
	}
	
	if(!PyNumber_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return -1;
	}
	
	((glm_mat4x3 *)self)->mat[item/4][item%4] = (float)PyFloat_AsDouble(value);
	
	return 0;
}

/* Definition */

static
PyObject * glm_mat4x3_tp_repr(PyObject *self) {
	glm::mat4x3 *v = &((glm_mat4x3 *)self)->mat;
	std::stringstream s;
	s.precision(std::numeric_limits<float>::digits10);
	s << Py_TYPE(self)->tp_name << "("
	 << (*v)[0][0]
	<< ", " << (*v)[0][1]
	<< ", " << (*v)[0][2]
	<< ", " << (*v)[0][3]
	<< ", " << (*v)[1][0]
	<< ", " << (*v)[1][1]
	<< ", " << (*v)[1][2]
	<< ", " << (*v)[1][3]
	<< ", " << (*v)[2][0]
	<< ", " << (*v)[2][1]
	<< ", " << (*v)[2][2]
	<< ", " << (*v)[2][3]
	<< ")";
	PyObject *result = PyUnicode_FromString(s.str().c_str());
	return result;
}

static
int glm_mat4x3_tp_init(PyObject *self, PyObject *args, PyObject *kwargs) {
	if(1 != PyObject_IsInstance(self, (PyObject *)&glm_mat4x3Type)) {
		PyErr_SetString(PyExc_TypeError, "Can only init mat4x3.");
		return -1;
	}
	
	glm_mat4x3 *real = (glm_mat4x3 *)self;
	
	Py_ssize_t argsize = PyTuple_GET_SIZE(args);
	
	if(argsize == 0) {
		real->mat = glm::mat4x3();
		return 0;
	}
	
	if(argsize == 1) {
		PyObject *tmp;
		tmp = PyTuple_GET_ITEM(args, 0);
		
		if(PyNumber_Check(tmp)) {
			real->mat = glm::mat4x3((float)PyFloat_AsDouble(tmp));
			return 0;
		}
		
		if(PyBytes_CheckExact(tmp)) {
			memcpy(&real->mat, PyBytes_AsString(tmp), sizeof(float) * 12);
			
			return 0;
		}
	}
	
	real->mat = glm::mat4x3();
	
	PyObject *tmp;
	Py_ssize_t i;
	Py_ssize_t at = 0;

	for(i = 0; i < argsize; i++) {
		tmp = PyTuple_GET_ITEM(args, i);

		if(PyBytes_CheckExact(tmp)) {
			size_t len = PyBytes_Size(tmp) / sizeof(float);
			
			if(at + len > 11)
				len = 12 - at;
			
			memcpy(glm::value_ptr(real->mat) + at, PyBytes_AsString(tmp), len * sizeof(float));
			
			at += len;
		}
		else if(PyIter_Check(tmp) || Py_TYPE(tmp)->tp_iter) {
			PyObject *tmpi = PyObject_GetIter(tmp);
			PyObject *item;
	
			while(1) {
				item = PyIter_Next(tmpi);
				if(item == NULL)
					break;
		
				real->mat[at/4][at%4] = (float)PyFloat_AsDouble(item);
		
				Py_DECREF(item);
				at += 1;
			}
	
			Py_DECREF(tmpi);
		}
		else if(PyNumber_Check(tmp)) {
			real->mat[at/4][at%4] = (float)PyFloat_AsDouble(tmp);

			at += 1;
		}
		else {
			PyErr_Format(PyExc_TypeError, "Initialization only accepts numbers, sequences, and bytes as arguments, not '%s' at argument %i.", Py_TYPE(tmp)->tp_name, (int)at);
			return -1;
		}
		
		if(at > 12) {
			PyErr_SetString(PyExc_TypeError, "Too much data.");
			return -1;
		}
	}
	
	return 0;
}

int glm_mat4x3_bf_getbuffer(PyObject *self, Py_buffer *view, int flags) {
	PyBuffer_FillInfo(view, self, glm::value_ptr(((glm_mat4x3 *)self)->mat), sizeof(float) * 12, 1, PyBUF_SIMPLE);
	return 0;
}

PyObject *glm_mat4x3_tp_richcompare(PyObject *self, PyObject *other, int op) {
	switch(op) {
		case Py_EQ:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat4x3Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_EQ))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat4x3Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat4x3 *)self)->mat == ((glm_mat4x3 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		case Py_NE:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat4x3Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_NE))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat4x3Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat4x3 *)self)->mat != ((glm_mat4x3 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		default:
			PyErr_SetString(PyExc_TypeError, "Comparison not valid.");
			return NULL;
	}
}

Py_hash_t glm_mat4x3_tp_hash(PyObject *self) {
	Py_hash_t x;

	x = _Py_HashDouble((double)((glm_mat4x3 *)self)->mat[0][0]);
	x ^= _Py_HashDouble((double)((glm_mat4x3 *)self)->mat[0][1]) << 2;
	x ^= _Py_HashDouble((double)((glm_mat4x3 *)self)->mat[0][2]) << 5;
	x ^= _Py_HashDouble((double)((glm_mat4x3 *)self)->mat[0][3]) << 7;
	x ^= _Py_HashDouble((double)((glm_mat4x3 *)self)->mat[1][0]) << 10;
	x ^= _Py_HashDouble((double)((glm_mat4x3 *)self)->mat[1][1]) << 12;
	x ^= _Py_HashDouble((double)((glm_mat4x3 *)self)->mat[1][2]) << 15;
	x ^= _Py_HashDouble((double)((glm_mat4x3 *)self)->mat[1][3]) << 18;
	x ^= _Py_HashDouble((double)((glm_mat4x3 *)self)->mat[2][0]) << 20;
	x ^= _Py_HashDouble((double)((glm_mat4x3 *)self)->mat[2][1]) << 23;
	x ^= _Py_HashDouble((double)((glm_mat4x3 *)self)->mat[2][2]) << 25;
	x ^= _Py_HashDouble((double)((glm_mat4x3 *)self)->mat[2][3]) << 28;
	
	if(x == -1)
		x = -2;
	
	return x;
}

/* * * mat2x4 * * */

/* mat2x4: Numbers */

static
PyObject *glm_mat2x4_nb_add(PyObject *self, PyObject *other) {
	PyObject *result;
	
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2x4 *)result)->mat = ((glm_mat2x4 *)self)->mat + (float)PyFloat_AsDouble(other);
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2x4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2x4 *)result)->mat = ((glm_mat2x4 *)self)->mat + ((glm_mat2x4 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat2x4_nb_subtract(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2x4 *)result)->mat = ((glm_mat2x4 *)self)->mat - (float)PyFloat_AsDouble(other);
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2x4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2x4 *)result)->mat = ((glm_mat2x4 *)self)->mat - ((glm_mat2x4 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat2x4_nb_multiply(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2x4 *)result)->mat = ((glm_mat2x4 *)self)->mat * (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2x4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat2x4 *)result)->mat = (float)PyFloat_AsDouble(self) * ((glm_mat2x4 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat2x4_nb_negative(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_mat2x4 *)result)->mat = -((glm_mat2x4 *)self)->mat;
	return result;
}

static
PyObject *glm_mat2x4_nb_positive(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	return result;
}

static
PyObject *glm_mat2x4_nb_inplace_add(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat2x4 *)self)->mat += (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2x4Type))
		((glm_mat2x4 *)self)->mat += ((glm_mat2x4 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat2x4_nb_inplace_subtract(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat2x4 *)self)->mat -= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2x4Type))
		((glm_mat2x4 *)self)->mat -= ((glm_mat2x4 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat2x4_nb_inplace_multiply(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat2x4 *)self)->mat *= (float)PyFloat_AsDouble(other);
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat2x4_nb_true_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat2x4 *)result)->mat = ((glm_mat2x4 *)self)->mat / (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat2x4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat2x4 *)result)->mat = (float)PyFloat_AsDouble(self) / ((glm_mat2x4 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat2x4_nb_inplace_true_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat2x4 *)self)->mat /= (float)PyFloat_AsDouble(other);
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

/* mat2x4: Sequence */

static
Py_ssize_t glm_mat2x4_sq_length(PyObject *self) {
	return 8;
}

static
PyObject *glm_mat2x4_sq_item(PyObject *self, Py_ssize_t item) {
	PyObject *result;
	if(item >= 8) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return NULL;
	}
	
	result = PyFloat_FromDouble((double)((glm_mat2x4 *)self)->mat[item/2][item%2]);
	return result;
}

static
int glm_mat2x4_sq_ass_item(PyObject *self, Py_ssize_t item, PyObject *value) {
	if(item >= 8) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return -1;
	}
	
	if(!PyNumber_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return -1;
	}
	
	((glm_mat2x4 *)self)->mat[item/2][item%2] = (float)PyFloat_AsDouble(value);
	
	return 0;
}

/* Definition */

static
PyObject * glm_mat2x4_tp_repr(PyObject *self) {
	glm::mat2x4 *v = &((glm_mat2x4 *)self)->mat;
	std::stringstream s;
	s.precision(std::numeric_limits<float>::digits10);
	s << Py_TYPE(self)->tp_name << "("
	 << (*v)[0][0]
	<< ", " << (*v)[0][1]
	<< ", " << (*v)[1][0]
	<< ", " << (*v)[1][1]
	<< ", " << (*v)[2][0]
	<< ", " << (*v)[2][1]
	<< ", " << (*v)[3][0]
	<< ", " << (*v)[3][1]
	<< ")";
	PyObject *result = PyUnicode_FromString(s.str().c_str());
	return result;
}

static
int glm_mat2x4_tp_init(PyObject *self, PyObject *args, PyObject *kwargs) {
	if(1 != PyObject_IsInstance(self, (PyObject *)&glm_mat2x4Type)) {
		PyErr_SetString(PyExc_TypeError, "Can only init mat2x4.");
		return -1;
	}
	
	glm_mat2x4 *real = (glm_mat2x4 *)self;
	
	Py_ssize_t argsize = PyTuple_GET_SIZE(args);
	
	if(argsize == 0) {
		real->mat = glm::mat2x4();
		return 0;
	}
	
	if(argsize == 1) {
		PyObject *tmp;
		tmp = PyTuple_GET_ITEM(args, 0);
		
		if(PyNumber_Check(tmp)) {
			real->mat = glm::mat2x4((float)PyFloat_AsDouble(tmp));
			return 0;
		}
		
		if(PyBytes_CheckExact(tmp)) {
			memcpy(&real->mat, PyBytes_AsString(tmp), sizeof(float) * 8);
			
			return 0;
		}
	}
	
	real->mat = glm::mat2x4();
	
	PyObject *tmp;
	Py_ssize_t i;
	Py_ssize_t at = 0;

	for(i = 0; i < argsize; i++) {
		tmp = PyTuple_GET_ITEM(args, i);

		if(PyBytes_CheckExact(tmp)) {
			size_t len = PyBytes_Size(tmp) / sizeof(float);
			
			if(at + len > 7)
				len = 8 - at;
			
			memcpy(glm::value_ptr(real->mat) + at, PyBytes_AsString(tmp), len * sizeof(float));
			
			at += len;
		}
		else if(PyIter_Check(tmp) || Py_TYPE(tmp)->tp_iter) {
			PyObject *tmpi = PyObject_GetIter(tmp);
			PyObject *item;
	
			while(1) {
				item = PyIter_Next(tmpi);
				if(item == NULL)
					break;
		
				real->mat[at/2][at%2] = (float)PyFloat_AsDouble(item);
		
				Py_DECREF(item);
				at += 1;
			}
	
			Py_DECREF(tmpi);
		}
		else if(PyNumber_Check(tmp)) {
			real->mat[at/2][at%2] = (float)PyFloat_AsDouble(tmp);

			at += 1;
		}
		else {
			PyErr_Format(PyExc_TypeError, "Initialization only accepts numbers, sequences, and bytes as arguments, not '%s' at argument %i.", Py_TYPE(tmp)->tp_name, (int)at);
			return -1;
		}
		
		if(at > 8) {
			PyErr_SetString(PyExc_TypeError, "Too much data.");
			return -1;
		}
	}
	
	return 0;
}

int glm_mat2x4_bf_getbuffer(PyObject *self, Py_buffer *view, int flags) {
	PyBuffer_FillInfo(view, self, glm::value_ptr(((glm_mat2x4 *)self)->mat), sizeof(float) * 8, 1, PyBUF_SIMPLE);
	return 0;
}

PyObject *glm_mat2x4_tp_richcompare(PyObject *self, PyObject *other, int op) {
	switch(op) {
		case Py_EQ:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat2x4Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_EQ))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat2x4Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat2x4 *)self)->mat == ((glm_mat2x4 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		case Py_NE:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat2x4Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_NE))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat2x4Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat2x4 *)self)->mat != ((glm_mat2x4 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		default:
			PyErr_SetString(PyExc_TypeError, "Comparison not valid.");
			return NULL;
	}
}

Py_hash_t glm_mat2x4_tp_hash(PyObject *self) {
	Py_hash_t x;

	x = _Py_HashDouble((double)((glm_mat2x4 *)self)->mat[0][0]);
	x ^= _Py_HashDouble((double)((glm_mat2x4 *)self)->mat[0][1]) << 3;
	x ^= _Py_HashDouble((double)((glm_mat2x4 *)self)->mat[1][0]) << 7;
	x ^= _Py_HashDouble((double)((glm_mat2x4 *)self)->mat[1][1]) << 11;
	x ^= _Py_HashDouble((double)((glm_mat2x4 *)self)->mat[2][0]) << 15;
	x ^= _Py_HashDouble((double)((glm_mat2x4 *)self)->mat[2][1]) << 19;
	x ^= _Py_HashDouble((double)((glm_mat2x4 *)self)->mat[3][0]) << 23;
	x ^= _Py_HashDouble((double)((glm_mat2x4 *)self)->mat[3][1]) << 27;
	
	if(x == -1)
		x = -2;
	
	return x;
}

/* * * mat3x4 * * */

/* mat3x4: Numbers */

static
PyObject *glm_mat3x4_nb_add(PyObject *self, PyObject *other) {
	PyObject *result;
	
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3x4 *)result)->mat = ((glm_mat3x4 *)self)->mat + (float)PyFloat_AsDouble(other);
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3x4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3x4 *)result)->mat = ((glm_mat3x4 *)self)->mat + ((glm_mat3x4 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat3x4_nb_subtract(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3x4 *)result)->mat = ((glm_mat3x4 *)self)->mat - (float)PyFloat_AsDouble(other);
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3x4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3x4 *)result)->mat = ((glm_mat3x4 *)self)->mat - ((glm_mat3x4 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat3x4_nb_multiply(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3x4 *)result)->mat = ((glm_mat3x4 *)self)->mat * (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3x4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat3x4 *)result)->mat = (float)PyFloat_AsDouble(self) * ((glm_mat3x4 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat3x4_nb_negative(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_mat3x4 *)result)->mat = -((glm_mat3x4 *)self)->mat;
	return result;
}

static
PyObject *glm_mat3x4_nb_positive(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	return result;
}

static
PyObject *glm_mat3x4_nb_inplace_add(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat3x4 *)self)->mat += (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3x4Type))
		((glm_mat3x4 *)self)->mat += ((glm_mat3x4 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat3x4_nb_inplace_subtract(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat3x4 *)self)->mat -= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3x4Type))
		((glm_mat3x4 *)self)->mat -= ((glm_mat3x4 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat3x4_nb_inplace_multiply(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat3x4 *)self)->mat *= (float)PyFloat_AsDouble(other);
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat3x4_nb_true_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat3x4 *)result)->mat = ((glm_mat3x4 *)self)->mat / (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat3x4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat3x4 *)result)->mat = (float)PyFloat_AsDouble(self) / ((glm_mat3x4 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat3x4_nb_inplace_true_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat3x4 *)self)->mat /= (float)PyFloat_AsDouble(other);
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

/* mat3x4: Sequence */

static
Py_ssize_t glm_mat3x4_sq_length(PyObject *self) {
	return 12;
}

static
PyObject *glm_mat3x4_sq_item(PyObject *self, Py_ssize_t item) {
	PyObject *result;
	if(item >= 12) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return NULL;
	}
	
	result = PyFloat_FromDouble((double)((glm_mat3x4 *)self)->mat[item/3][item%3]);
	return result;
}

static
int glm_mat3x4_sq_ass_item(PyObject *self, Py_ssize_t item, PyObject *value) {
	if(item >= 12) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return -1;
	}
	
	if(!PyNumber_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return -1;
	}
	
	((glm_mat3x4 *)self)->mat[item/3][item%3] = (float)PyFloat_AsDouble(value);
	
	return 0;
}

/* Definition */

static
PyObject * glm_mat3x4_tp_repr(PyObject *self) {
	glm::mat3x4 *v = &((glm_mat3x4 *)self)->mat;
	std::stringstream s;
	s.precision(std::numeric_limits<float>::digits10);
	s << Py_TYPE(self)->tp_name << "("
	 << (*v)[0][0]
	<< ", " << (*v)[0][1]
	<< ", " << (*v)[0][2]
	<< ", " << (*v)[1][0]
	<< ", " << (*v)[1][1]
	<< ", " << (*v)[1][2]
	<< ", " << (*v)[2][0]
	<< ", " << (*v)[2][1]
	<< ", " << (*v)[2][2]
	<< ", " << (*v)[3][0]
	<< ", " << (*v)[3][1]
	<< ", " << (*v)[3][2]
	<< ")";
	PyObject *result = PyUnicode_FromString(s.str().c_str());
	return result;
}

static
int glm_mat3x4_tp_init(PyObject *self, PyObject *args, PyObject *kwargs) {
	if(1 != PyObject_IsInstance(self, (PyObject *)&glm_mat3x4Type)) {
		PyErr_SetString(PyExc_TypeError, "Can only init mat3x4.");
		return -1;
	}
	
	glm_mat3x4 *real = (glm_mat3x4 *)self;
	
	Py_ssize_t argsize = PyTuple_GET_SIZE(args);
	
	if(argsize == 0) {
		real->mat = glm::mat3x4();
		return 0;
	}
	
	if(argsize == 1) {
		PyObject *tmp;
		tmp = PyTuple_GET_ITEM(args, 0);
		
		if(PyNumber_Check(tmp)) {
			real->mat = glm::mat3x4((float)PyFloat_AsDouble(tmp));
			return 0;
		}
		
		if(PyBytes_CheckExact(tmp)) {
			memcpy(&real->mat, PyBytes_AsString(tmp), sizeof(float) * 12);
			
			return 0;
		}
	}
	
	real->mat = glm::mat3x4();
	
	PyObject *tmp;
	Py_ssize_t i;
	Py_ssize_t at = 0;

	for(i = 0; i < argsize; i++) {
		tmp = PyTuple_GET_ITEM(args, i);

		if(PyBytes_CheckExact(tmp)) {
			size_t len = PyBytes_Size(tmp) / sizeof(float);
			
			if(at + len > 11)
				len = 12 - at;
			
			memcpy(glm::value_ptr(real->mat) + at, PyBytes_AsString(tmp), len * sizeof(float));
			
			at += len;
		}
		else if(PyIter_Check(tmp) || Py_TYPE(tmp)->tp_iter) {
			PyObject *tmpi = PyObject_GetIter(tmp);
			PyObject *item;
	
			while(1) {
				item = PyIter_Next(tmpi);
				if(item == NULL)
					break;
		
				real->mat[at/3][at%3] = (float)PyFloat_AsDouble(item);
		
				Py_DECREF(item);
				at += 1;
			}
	
			Py_DECREF(tmpi);
		}
		else if(PyNumber_Check(tmp)) {
			real->mat[at/3][at%3] = (float)PyFloat_AsDouble(tmp);

			at += 1;
		}
		else {
			PyErr_Format(PyExc_TypeError, "Initialization only accepts numbers, sequences, and bytes as arguments, not '%s' at argument %i.", Py_TYPE(tmp)->tp_name, (int)at);
			return -1;
		}
		
		if(at > 12) {
			PyErr_SetString(PyExc_TypeError, "Too much data.");
			return -1;
		}
	}
	
	return 0;
}

int glm_mat3x4_bf_getbuffer(PyObject *self, Py_buffer *view, int flags) {
	PyBuffer_FillInfo(view, self, glm::value_ptr(((glm_mat3x4 *)self)->mat), sizeof(float) * 12, 1, PyBUF_SIMPLE);
	return 0;
}

PyObject *glm_mat3x4_tp_richcompare(PyObject *self, PyObject *other, int op) {
	switch(op) {
		case Py_EQ:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat3x4Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_EQ))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat3x4Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat3x4 *)self)->mat == ((glm_mat3x4 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		case Py_NE:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat3x4Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_NE))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat3x4Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat3x4 *)self)->mat != ((glm_mat3x4 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		default:
			PyErr_SetString(PyExc_TypeError, "Comparison not valid.");
			return NULL;
	}
}

Py_hash_t glm_mat3x4_tp_hash(PyObject *self) {
	Py_hash_t x;

	x = _Py_HashDouble((double)((glm_mat3x4 *)self)->mat[0][0]);
	x ^= _Py_HashDouble((double)((glm_mat3x4 *)self)->mat[0][1]) << 2;
	x ^= _Py_HashDouble((double)((glm_mat3x4 *)self)->mat[0][2]) << 5;
	x ^= _Py_HashDouble((double)((glm_mat3x4 *)self)->mat[1][0]) << 7;
	x ^= _Py_HashDouble((double)((glm_mat3x4 *)self)->mat[1][1]) << 10;
	x ^= _Py_HashDouble((double)((glm_mat3x4 *)self)->mat[1][2]) << 12;
	x ^= _Py_HashDouble((double)((glm_mat3x4 *)self)->mat[2][0]) << 15;
	x ^= _Py_HashDouble((double)((glm_mat3x4 *)self)->mat[2][1]) << 18;
	x ^= _Py_HashDouble((double)((glm_mat3x4 *)self)->mat[2][2]) << 20;
	x ^= _Py_HashDouble((double)((glm_mat3x4 *)self)->mat[3][0]) << 23;
	x ^= _Py_HashDouble((double)((glm_mat3x4 *)self)->mat[3][1]) << 25;
	x ^= _Py_HashDouble((double)((glm_mat3x4 *)self)->mat[3][2]) << 28;
	
	if(x == -1)
		x = -2;
	
	return x;
}

/* * * mat4 * * */

/* mat4: Numbers */

static
PyObject *glm_mat4_nb_add(PyObject *self, PyObject *other) {
	PyObject *result;
	
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4 *)result)->mat = ((glm_mat4 *)self)->mat + (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat4 *)result)->mat = (float)PyFloat_AsDouble(self) + ((glm_mat4 *)other)->mat;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4 *)result)->mat = ((glm_mat4 *)self)->mat + ((glm_mat4 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat4_nb_subtract(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4 *)result)->mat = ((glm_mat4 *)self)->mat - (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat4 *)result)->mat = (float)PyFloat_AsDouble(self) - ((glm_mat4 *)other)->mat;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4 *)result)->mat = ((glm_mat4 *)self)->mat - ((glm_mat4 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat4_nb_multiply(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4 *)result)->mat = ((glm_mat4 *)self)->mat * (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat4 *)result)->mat = (float)PyFloat_AsDouble(self) * ((glm_mat4 *)other)->mat;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4 *)result)->mat = ((glm_mat4 *)self)->mat * ((glm_mat4 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat4_nb_negative(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_mat4 *)result)->mat = -((glm_mat4 *)self)->mat;
	return result;
}

static
PyObject *glm_mat4_nb_positive(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	return result;
}

static
PyObject *glm_mat4_nb_inplace_add(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat4 *)self)->mat += (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4Type))
		((glm_mat4 *)self)->mat += ((glm_mat4 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat4_nb_inplace_subtract(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat4 *)self)->mat -= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4Type))
		((glm_mat4 *)self)->mat -= ((glm_mat4 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat4_nb_inplace_multiply(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat4 *)self)->mat *= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4Type))
		((glm_mat4 *)self)->mat *= ((glm_mat4 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_mat4_nb_true_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4 *)result)->mat = ((glm_mat4 *)self)->mat / (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_mat4 *)result)->mat = (float)PyFloat_AsDouble(self) / ((glm_mat4 *)other)->mat;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_mat4 *)result)->mat = ((glm_mat4 *)self)->mat / ((glm_mat4 *)other)->mat;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_mat4_nb_inplace_true_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_mat4 *)self)->mat /= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_mat4Type))
		((glm_mat4 *)self)->mat /= ((glm_mat4 *)other)->mat;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

/* mat4: Sequence */

static
Py_ssize_t glm_mat4_sq_length(PyObject *self) {
	return 16;
}

static
PyObject *glm_mat4_sq_item(PyObject *self, Py_ssize_t item) {
	PyObject *result;
	if(item >= 16) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return NULL;
	}
	
	result = PyFloat_FromDouble((double)((glm_mat4 *)self)->mat[item/4][item%4]);
	return result;
}

static
int glm_mat4_sq_ass_item(PyObject *self, Py_ssize_t item, PyObject *value) {
	if(item >= 16) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return -1;
	}
	
	if(!PyNumber_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return -1;
	}
	
	((glm_mat4 *)self)->mat[item/4][item%4] = (float)PyFloat_AsDouble(value);
	
	return 0;
}

/* Definition */

static
PyObject * glm_mat4_tp_repr(PyObject *self) {
	glm::mat4 *v = &((glm_mat4 *)self)->mat;
	std::stringstream s;
	s.precision(std::numeric_limits<float>::digits10);
	s << Py_TYPE(self)->tp_name << "("
	 << (*v)[0][0]
	<< ", " << (*v)[0][1]
	<< ", " << (*v)[0][2]
	<< ", " << (*v)[0][3]
	<< ", " << (*v)[1][0]
	<< ", " << (*v)[1][1]
	<< ", " << (*v)[1][2]
	<< ", " << (*v)[1][3]
	<< ", " << (*v)[2][0]
	<< ", " << (*v)[2][1]
	<< ", " << (*v)[2][2]
	<< ", " << (*v)[2][3]
	<< ", " << (*v)[3][0]
	<< ", " << (*v)[3][1]
	<< ", " << (*v)[3][2]
	<< ", " << (*v)[3][3]
	<< ")";
	PyObject *result = PyUnicode_FromString(s.str().c_str());
	return result;
}

static
int glm_mat4_tp_init(PyObject *self, PyObject *args, PyObject *kwargs) {
	if(1 != PyObject_IsInstance(self, (PyObject *)&glm_mat4Type)) {
		PyErr_SetString(PyExc_TypeError, "Can only init mat4.");
		return -1;
	}
	
	glm_mat4 *real = (glm_mat4 *)self;
	
	Py_ssize_t argsize = PyTuple_GET_SIZE(args);
	
	if(argsize == 0) {
		real->mat = glm::mat4();
		return 0;
	}
	
	if(argsize == 1) {
		PyObject *tmp;
		tmp = PyTuple_GET_ITEM(args, 0);
		
		if(PyNumber_Check(tmp)) {
			real->mat = glm::mat4((float)PyFloat_AsDouble(tmp));
			return 0;
		}
		
		if(PyBytes_CheckExact(tmp)) {
			memcpy(&real->mat, PyBytes_AsString(tmp), sizeof(float) * 16);
			
			return 0;
		}
	}
	
	real->mat = glm::mat4();
	
	PyObject *tmp;
	Py_ssize_t i;
	Py_ssize_t at = 0;

	for(i = 0; i < argsize; i++) {
		tmp = PyTuple_GET_ITEM(args, i);

		if(PyBytes_CheckExact(tmp)) {
			size_t len = PyBytes_Size(tmp) / sizeof(float);
			
			if(at + len > 15)
				len = 16 - at;
			
			memcpy(glm::value_ptr(real->mat) + at, PyBytes_AsString(tmp), len * sizeof(float));
			
			at += len;
		}
		else if(PyIter_Check(tmp) || Py_TYPE(tmp)->tp_iter) {
			PyObject *tmpi = PyObject_GetIter(tmp);
			PyObject *item;
	
			while(1) {
				item = PyIter_Next(tmpi);
				if(item == NULL)
					break;
		
				real->mat[at/4][at%4] = (float)PyFloat_AsDouble(item);
		
				Py_DECREF(item);
				at += 1;
			}
	
			Py_DECREF(tmpi);
		}
		else if(PyNumber_Check(tmp)) {
			real->mat[at/4][at%4] = (float)PyFloat_AsDouble(tmp);

			at += 1;
		}
		else {
			PyErr_Format(PyExc_TypeError, "Initialization only accepts numbers, sequences, and bytes as arguments, not '%s' at argument %i.", Py_TYPE(tmp)->tp_name, (int)at);
			return -1;
		}
		
		if(at > 16) {
			PyErr_SetString(PyExc_TypeError, "Too much data.");
			return -1;
		}
	}
	
	return 0;
}

int glm_mat4_bf_getbuffer(PyObject *self, Py_buffer *view, int flags) {
	PyBuffer_FillInfo(view, self, glm::value_ptr(((glm_mat4 *)self)->mat), sizeof(float) * 16, 1, PyBUF_SIMPLE);
	return 0;
}

PyObject *glm_mat4_tp_richcompare(PyObject *self, PyObject *other, int op) {
	switch(op) {
		case Py_EQ:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat4Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_EQ))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat4Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat4 *)self)->mat == ((glm_mat4 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		case Py_NE:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat4Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_NE))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_mat4Type)) {
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_mat4 *)self)->mat != ((glm_mat4 *)other)->mat) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		default:
			PyErr_SetString(PyExc_TypeError, "Comparison not valid.");
			return NULL;
	}
}

Py_hash_t glm_mat4_tp_hash(PyObject *self) {
	Py_hash_t x;

	x = _Py_HashDouble((double)((glm_mat4 *)self)->mat[0][0]);
	x ^= _Py_HashDouble((double)((glm_mat4 *)self)->mat[0][1]) << 1;
	x ^= _Py_HashDouble((double)((glm_mat4 *)self)->mat[0][2]) << 3;
	x ^= _Py_HashDouble((double)((glm_mat4 *)self)->mat[0][3]) << 5;
	x ^= _Py_HashDouble((double)((glm_mat4 *)self)->mat[1][0]) << 7;
	x ^= _Py_HashDouble((double)((glm_mat4 *)self)->mat[1][1]) << 9;
	x ^= _Py_HashDouble((double)((glm_mat4 *)self)->mat[1][2]) << 11;
	x ^= _Py_HashDouble((double)((glm_mat4 *)self)->mat[1][3]) << 13;
	x ^= _Py_HashDouble((double)((glm_mat4 *)self)->mat[2][0]) << 15;
	x ^= _Py_HashDouble((double)((glm_mat4 *)self)->mat[2][1]) << 17;
	x ^= _Py_HashDouble((double)((glm_mat4 *)self)->mat[2][2]) << 19;
	x ^= _Py_HashDouble((double)((glm_mat4 *)self)->mat[2][3]) << 21;
	x ^= _Py_HashDouble((double)((glm_mat4 *)self)->mat[3][0]) << 23;
	x ^= _Py_HashDouble((double)((glm_mat4 *)self)->mat[3][1]) << 25;
	x ^= _Py_HashDouble((double)((glm_mat4 *)self)->mat[3][2]) << 27;
	x ^= _Py_HashDouble((double)((glm_mat4 *)self)->mat[3][3]) << 29;
	
	if(x == -1)
		x = -2;
	
	return x;
}

/* * * vec2 * * */

/* vec2: Numbers */

static
PyObject *glm_vec2_nb_add(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec2 *)result)->vec = ((glm_vec2 *)self)->vec + (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_vec2 *)result)->vec = (float)PyFloat_AsDouble(self) + ((glm_vec2 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec2 *)result)->vec = ((glm_vec2 *)self)->vec + ((glm_vec2 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec2 *)result)->vec = ((glm_vec2 *)self)->vec + ((glm_vec2 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec2_nb_inplace_add(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_vec2 *)self)->vec += (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type))
		((glm_vec2 *)self)->vec += ((glm_vec2 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec2 *)self)->vec += ((glm_vec2 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_vec2_nb_subtract(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec2 *)result)->vec = ((glm_vec2 *)self)->vec - (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_vec2 *)result)->vec = (float)PyFloat_AsDouble(self) - ((glm_vec2 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec2 *)result)->vec = ((glm_vec2 *)self)->vec - ((glm_vec2 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec2 *)result)->vec = ((glm_vec2 *)self)->vec - ((glm_vec2 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec2_nb_inplace_subtract(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_vec2 *)self)->vec -= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type))
		((glm_vec2 *)self)->vec -= ((glm_vec2 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec2 *)self)->vec -= ((glm_vec2 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_vec2_nb_multiply(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec2 *)result)->vec = ((glm_vec2 *)self)->vec * (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_vec2 *)result)->vec = (float)PyFloat_AsDouble(self) * ((glm_vec2 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec2 *)result)->vec = ((glm_vec2 *)self)->vec * ((glm_vec2 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec2 *)result)->vec = ((glm_vec2 *)self)->vec * ((glm_vec2 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec2_nb_inplace_multiply(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_vec2 *)self)->vec *= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type))
		((glm_vec2 *)self)->vec *= ((glm_vec2 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec2 *)self)->vec *= ((glm_vec2 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_vec2_nb_true_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec2 *)result)->vec = ((glm_vec2 *)self)->vec / (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_vec2 *)result)->vec = (float)PyFloat_AsDouble(self) / ((glm_vec2 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec2 *)result)->vec = ((glm_vec2 *)self)->vec / ((glm_vec2 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec2 *)result)->vec = ((glm_vec2 *)self)->vec / ((glm_vec2 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec2_nb_inplace_true_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_vec2 *)self)->vec /= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type))
		((glm_vec2 *)self)->vec /= ((glm_vec2 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec2 *)self)->vec /= ((glm_vec2 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}


static
PyObject *glm_vec2_nb_remainder(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec2 *)result)->vec = glm::mod(((glm_vec2 *)self)->vec, (float)PyFloat_AsDouble(other));
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec2 *)result)->vec = glm::mod(((glm_vec2 *)self)->vec, ((glm_vec2 *)other)->vec);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec2_nb_divmod(PyObject *self, PyObject *other) {
	if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type)) {
		PyObject *whole = PyNumber_FloorDivide(self, other);
	
		if(whole == NULL)
			return NULL;
		
		PyObject *args = Py_BuildValue("(O)", self);
		PyObject *tmp = Py_TYPE(other)->tp_new(Py_TYPE(other), args, NULL);
		Py_DECREF(args);
		PyObject *remain = PyNumber_Remainder(tmp, other);
		Py_DECREF(tmp);
		
		if(remain == NULL) {
			Py_DECREF(whole);
			return NULL;
		}
		
		PyObject *result = Py_BuildValue("(OO)", whole, remain);
		
		Py_DECREF(whole);
		Py_DECREF(remain);
		
		return result;
	}
	else if(!PyNumber_Check(other) && 1 != PyObject_IsInstance(other, (PyObject *)&glm_vec2Type)) {
		PyErr_SetString(PyExc_TypeError, "Other must be a number or of the same type.");
		return NULL;
	}
	
	PyObject *whole = PyNumber_FloorDivide(self, other);
	
	if(whole == NULL)
		return NULL;
	
	PyObject *remain = PyNumber_Remainder(self, other);
	
	if(remain == NULL) {
		Py_DECREF(whole);
		return NULL;
	}
	
	PyObject *result = Py_BuildValue("(OO)", whole, remain);
	
	Py_DECREF(whole);
	Py_DECREF(remain);
	
	return result;
}

static
PyObject *glm_vec2_nb_power(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);;
		
		((glm_vec2 *)result)->vec = glm::pow(((glm_vec2 *)self)->vec, glm::vec2((float)PyFloat_AsDouble(other)));
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec2 *)result)->vec = glm::pow(((glm_vec2 *)self)->vec, ((glm_vec2 *)other)->vec);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec2_nb_negative(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_vec2 *)result)->vec = -((glm_vec2 *)self)->vec;
	return result;
}

static
PyObject *glm_vec2_nb_positive(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	return result;
}

static
PyObject *glm_vec2_nb_absolute(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_vec2 *)result)->vec = glm::abs(((glm_vec2 *)self)->vec);
	return result;
}


static
PyObject *glm_vec2_nb_floor_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec2 *)result)->vec = glm::floor(((glm_vec2 *)self)->vec / (float)PyFloat_AsDouble(other));
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_vec2 *)result)->vec = glm::floor((float)PyFloat_AsDouble(self) / ((glm_vec2 *)other)->vec);
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec2 *)result)->vec = glm::floor(((glm_vec2 *)self)->vec / ((glm_vec2 *)other)->vec);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec2_nb_inplace_floor_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_vec2 *)self)->vec /= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec2Type))
		((glm_vec2 *)self)->vec /= ((glm_vec2 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	((glm_vec2 *)self)->vec = glm::floor(((glm_vec2 *)self)->vec);
	
	Py_INCREF(self);
	return self;
}

/* vec2: Sequence */

static
Py_ssize_t glm_vec2_sq_length(PyObject *self) {
	return 2;
}

static
PyObject *glm_vec2_sq_item(PyObject *self, Py_ssize_t item) {
	PyObject *result;
	if(item >= 2) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return NULL;
	}
	
	result = PyFloat_FromDouble((double)((glm_vec2 *)self)->vec[item]);
	return result;
}

static
int glm_vec2_sq_ass_item(PyObject *self, Py_ssize_t item, PyObject *value) {
	if(item >= 2) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return -1;
	}
	
	if(!PyNumber_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return -1;
	}
	
	((glm_vec2 *)self)->vec[item] = (float)PyFloat_AsDouble(value);
	
	return 0;
}

/* Definition */

static
PyObject * glm_vec2_tp_repr(PyObject *self) {
	glm::vec2 *v = &((glm_vec2 *)self)->vec;
	std::stringstream s;
	s.precision(std::numeric_limits<float>::digits10);
	s << Py_TYPE(self)->tp_name << "("
	 << (*v)[0]
	<< ", " << (*v)[1]
	<< ")";
	PyObject *result = PyUnicode_FromString(s.str().c_str());
	return result;
}

static
int glm_vec2_tp_init(PyObject *self, PyObject *args, PyObject *kwargs) {
	if(1 != PyObject_IsInstance(self, (PyObject *)&glm_vec2Type)) {
		PyErr_SetString(PyExc_TypeError, "Can only init vec2.");
		return -1;
	}
	
	glm_vec2 *real = (glm_vec2 *)self;
	
	Py_ssize_t argsize = PyTuple_GET_SIZE(args);
	
	if(argsize == 0) {
		real->vec = glm::vec2();
		return 0;
	}
	
	if(argsize == 1) {
		PyObject *tmp;
		tmp = PyTuple_GET_ITEM(args, 0);
		
		if(PyNumber_Check(tmp)) {
			real->vec = glm::vec2((float)PyFloat_AsDouble(tmp));
			return 0;
		}
		
		if(PyBytes_CheckExact(tmp)) {
			memcpy(&real->vec, PyBytes_AsString(tmp), sizeof(float) * 2);
			
			return 0;
		}
	}
	
	real->vec = glm::vec2();
	
	PyObject *tmp;
	Py_ssize_t i;
	Py_ssize_t at = 0;

	for(i = 0; i < argsize; i++) {
		tmp = PyTuple_GET_ITEM(args, i);
		
		if(PyBytes_CheckExact(tmp)) {
			size_t len = PyBytes_Size(tmp) / sizeof(float);
			
			if(at + len > 1)
				len = 2 - at;
			
			memcpy(glm::value_ptr(real->vec) + at, PyBytes_AsString(tmp), len * sizeof(float));
			
			at += len;
		}
		else if(PyIter_Check(tmp) || Py_TYPE(tmp)->tp_iter) {
			PyObject *tmpi = PyObject_GetIter(tmp);
			PyObject *item;
	
			while(1) {
				item = PyIter_Next(tmpi);
				if(item == NULL)
					break;
		
				real->vec[at] = (float)PyFloat_AsDouble(item);
		
				Py_DECREF(item);
				
				at += 1;
			}
	
			Py_DECREF(tmpi);
		}
		else if(PyNumber_Check(tmp)) {
			real->vec[at] = (float)PyFloat_AsDouble(tmp);

			at += 1;
		}
		else {
			PyErr_Format(PyExc_TypeError, "Initialization only accepts numbers, sequences, and bytes as arguments, not '%s' at argument %i.", Py_TYPE(tmp)->tp_name, (int)at);
			return -1;
		}
		
		if(at > 2) {
			PyErr_SetString(PyExc_TypeError, "Too much data.");
			return -1;
		}
	}
	
	return 0;
}

static
PyObject * glm_vec2_tp_getattro(PyObject *self, PyObject *attr_name) {
	PyObject *tmp;
	tmp = PyObject_GenericGetAttr(self, attr_name);
	
	if(tmp != NULL)
		return tmp;
	else
		PyErr_Clear();
	
	if(!PyUnicode_Check(attr_name)) {
		PyErr_SetString(PyExc_TypeError, "Attributes use strings.");
		return NULL;
	}
	
	Py_ssize_t swizzles = PyObject_Size(attr_name);
	
	if(swizzles < 1) {
		PyErr_SetString(PyExc_TypeError, "Attributes are strings with a commendable length.");
		return NULL;
	}
	
	PyObject * result;
	PyObject * args;
	Py_ssize_t c;
	
	args = PyTuple_New(swizzles);
	
	if(args == NULL) {
		PyErr_SetString(PyExc_ValueError, "Could not create a simple tuple...hmmm...");
		return NULL;
	}
	
	for(c = 0; c < swizzles; c++) {
		tmp = PySequence_ITEM(attr_name, c);
		if(
			PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
			PyTuple_SET_ITEM(args, c, PyFloat_FromDouble((double)((glm_vec2 *)self)->vec[0]));
		else if(
			PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
			PyTuple_SET_ITEM(args, c, PyFloat_FromDouble((double)((glm_vec2 *)self)->vec[1]));
		else {
			Py_DECREF(tmp);
			Py_DECREF(args);
			PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
			return NULL;
		}
		
		Py_DECREF(tmp);
	}
	
	if(swizzles == 1) {
		result = PyTuple_GET_ITEM(args, 0);
		Py_INCREF(result);
	}
	else if(swizzles == 2)
		result = PyObject_CallObject((PyObject *)&glm_vec2Type, args);
	else if(swizzles == 3)
		result = PyObject_CallObject((PyObject *)&glm_vec3Type, args);
	else if(swizzles == 4)
		result = PyObject_CallObject((PyObject *)&glm_vec4Type, args);
	else
		return args;
	
	Py_DECREF(args);
	
	if(result == NULL)
		PyErr_SetString(PyExc_ValueError, "Could not create vector.");
	
	return result;
}

static
int glm_vec2_tp_setattro(PyObject *self, PyObject *attr_name, PyObject *value) {
	if(!PyUnicode_Check(attr_name)) {
		PyErr_SetString(PyExc_TypeError, "Attributes use strings.");
		return -1;
	}
	
	Py_ssize_t swizzles = PyObject_Size(attr_name);
	
	Py_ssize_t c;
	PyObject *tmp;
	
	if(PyNumber_Check(value)) {
		for(c = 0; c < swizzles; c++) {
			tmp = PySequence_ITEM(attr_name, c);
			if(
				PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
				((glm_vec2 *)self)->vec[0] = (float)PyFloat_AsDouble(value);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
				((glm_vec2 *)self)->vec[1] = (float)PyFloat_AsDouble(value);
			else {
				Py_DECREF(tmp);
				PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
				return -1;
			}
		
			Py_DECREF(tmp);
		}
	}
	else if(PyIter_Check(value) || Py_TYPE(value)->tp_iter) {
		PyObject *iter = PyObject_GetIter(value);
		PyObject *iteritem;
		
		if(iter == NULL)
			return -1;
		
		for(c = 0; c < swizzles; c++) {
			tmp = PySequence_ITEM(attr_name, c);
			iteritem = PyIter_Next(iter);
			
			if(iteritem == NULL) {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				PyErr_SetString(PyExc_AttributeError, "Too few values.");
				return -1;
			}
			else if(!PyNumber_Check(iteritem)) {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				Py_DECREF(iteritem);
				PyErr_SetString(PyExc_AttributeError, "Values must all be numbers.");
				return -1;
			}
			if(
				PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
				((glm_vec2 *)self)->vec[0] = (float)PyFloat_AsDouble(iteritem);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
				((glm_vec2 *)self)->vec[1] = (float)PyFloat_AsDouble(iteritem);
			else {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				Py_DECREF(iteritem);
				PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
				return -1;
			}
			
			Py_DECREF(iteritem);
			Py_DECREF(tmp);
		}
		
		Py_DECREF(iter);
	}
	else {
		PyErr_SetString(PyExc_AttributeError, "Value must be a number or iterable.");
		return -1;
	}
	
	return 0;
}

int glm_vec2_bf_getbuffer(PyObject *self, Py_buffer *view, int flags) {
	PyBuffer_FillInfo(view, self, glm::value_ptr(((glm_vec2 *)self)->vec), sizeof(float) * 2, 1, PyBUF_SIMPLE);
	return 0;
}

PyObject *glm_vec2_tp_richcompare(PyObject *self, PyObject *other, int op) {
	switch(op) {
		case Py_EQ:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_vec2Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_EQ))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_vec2 *)self)->vec == ((glm_vec2 *)other)->vec) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		case Py_NE:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_vec2Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_NE))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_vec2 *)self)->vec != ((glm_vec2 *)other)->vec) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		default:
			PyErr_SetString(PyExc_TypeError, "Comparison not valid.");
			return NULL;
	}
}

Py_hash_t glm_vec2_tp_hash(PyObject *self) {
	Py_hash_t x;

	x = _Py_HashDouble((double)((glm_vec2 *)self)->vec[0]);
	x ^= _Py_HashDouble((double)((glm_vec2 *)self)->vec[1]) << 15;
	
	if(x == -1)
		x = -2;
	
	return x;
}
/* * * vec3 * * */

/* vec3: Numbers */

static
PyObject *glm_vec3_nb_add(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec3 *)result)->vec = ((glm_vec3 *)self)->vec + (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_vec3 *)result)->vec = (float)PyFloat_AsDouble(self) + ((glm_vec3 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec3 *)result)->vec = ((glm_vec3 *)self)->vec + ((glm_vec3 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec3 *)result)->vec = ((glm_vec3 *)self)->vec + ((glm_vec3 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec3_nb_inplace_add(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_vec3 *)self)->vec += (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type))
		((glm_vec3 *)self)->vec += ((glm_vec3 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec3 *)self)->vec += ((glm_vec3 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_vec3_nb_subtract(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec3 *)result)->vec = ((glm_vec3 *)self)->vec - (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_vec3 *)result)->vec = (float)PyFloat_AsDouble(self) - ((glm_vec3 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec3 *)result)->vec = ((glm_vec3 *)self)->vec - ((glm_vec3 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec3 *)result)->vec = ((glm_vec3 *)self)->vec - ((glm_vec3 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec3_nb_inplace_subtract(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_vec3 *)self)->vec -= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type))
		((glm_vec3 *)self)->vec -= ((glm_vec3 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec3 *)self)->vec -= ((glm_vec3 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_vec3_nb_multiply(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec3 *)result)->vec = ((glm_vec3 *)self)->vec * (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_vec3 *)result)->vec = (float)PyFloat_AsDouble(self) * ((glm_vec3 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec3 *)result)->vec = ((glm_vec3 *)self)->vec * ((glm_vec3 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec3 *)result)->vec = ((glm_vec3 *)self)->vec * ((glm_vec3 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec3_nb_inplace_multiply(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_vec3 *)self)->vec *= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type))
		((glm_vec3 *)self)->vec *= ((glm_vec3 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec3 *)self)->vec *= ((glm_vec3 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_vec3_nb_true_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec3 *)result)->vec = ((glm_vec3 *)self)->vec / (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_vec3 *)result)->vec = (float)PyFloat_AsDouble(self) / ((glm_vec3 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec3 *)result)->vec = ((glm_vec3 *)self)->vec / ((glm_vec3 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec3 *)result)->vec = ((glm_vec3 *)self)->vec / ((glm_vec3 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec3_nb_inplace_true_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_vec3 *)self)->vec /= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type))
		((glm_vec3 *)self)->vec /= ((glm_vec3 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec3 *)self)->vec /= ((glm_vec3 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}


static
PyObject *glm_vec3_nb_remainder(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec3 *)result)->vec = glm::mod(((glm_vec3 *)self)->vec, (float)PyFloat_AsDouble(other));
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec3 *)result)->vec = glm::mod(((glm_vec3 *)self)->vec, ((glm_vec3 *)other)->vec);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec3_nb_divmod(PyObject *self, PyObject *other) {
	if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type)) {
		PyObject *whole = PyNumber_FloorDivide(self, other);
	
		if(whole == NULL)
			return NULL;
		
		PyObject *args = Py_BuildValue("(O)", self);
		PyObject *tmp = Py_TYPE(other)->tp_new(Py_TYPE(other), args, NULL);
		Py_DECREF(args);
		PyObject *remain = PyNumber_Remainder(tmp, other);
		Py_DECREF(tmp);
		
		if(remain == NULL) {
			Py_DECREF(whole);
			return NULL;
		}
		
		PyObject *result = Py_BuildValue("(OO)", whole, remain);
		
		Py_DECREF(whole);
		Py_DECREF(remain);
		
		return result;
	}
	else if(!PyNumber_Check(other) && 1 != PyObject_IsInstance(other, (PyObject *)&glm_vec3Type)) {
		PyErr_SetString(PyExc_TypeError, "Other must be a number or of the same type.");
		return NULL;
	}
	
	PyObject *whole = PyNumber_FloorDivide(self, other);
	
	if(whole == NULL)
		return NULL;
	
	PyObject *remain = PyNumber_Remainder(self, other);
	
	if(remain == NULL) {
		Py_DECREF(whole);
		return NULL;
	}
	
	PyObject *result = Py_BuildValue("(OO)", whole, remain);
	
	Py_DECREF(whole);
	Py_DECREF(remain);
	
	return result;
}

static
PyObject *glm_vec3_nb_power(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);;
		
		((glm_vec3 *)result)->vec = glm::pow(((glm_vec3 *)self)->vec, glm::vec3((float)PyFloat_AsDouble(other)));
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec3 *)result)->vec = glm::pow(((glm_vec3 *)self)->vec, ((glm_vec3 *)other)->vec);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec3_nb_negative(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_vec3 *)result)->vec = -((glm_vec3 *)self)->vec;
	return result;
}

static
PyObject *glm_vec3_nb_positive(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	return result;
}

static
PyObject *glm_vec3_nb_absolute(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_vec3 *)result)->vec = glm::abs(((glm_vec3 *)self)->vec);
	return result;
}


static
PyObject *glm_vec3_nb_floor_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec3 *)result)->vec = glm::floor(((glm_vec3 *)self)->vec / (float)PyFloat_AsDouble(other));
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_vec3 *)result)->vec = glm::floor((float)PyFloat_AsDouble(self) / ((glm_vec3 *)other)->vec);
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec3 *)result)->vec = glm::floor(((glm_vec3 *)self)->vec / ((glm_vec3 *)other)->vec);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec3_nb_inplace_floor_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_vec3 *)self)->vec /= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec3Type))
		((glm_vec3 *)self)->vec /= ((glm_vec3 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	((glm_vec3 *)self)->vec = glm::floor(((glm_vec3 *)self)->vec);
	
	Py_INCREF(self);
	return self;
}

/* vec3: Sequence */

static
Py_ssize_t glm_vec3_sq_length(PyObject *self) {
	return 3;
}

static
PyObject *glm_vec3_sq_item(PyObject *self, Py_ssize_t item) {
	PyObject *result;
	if(item >= 3) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return NULL;
	}
	
	result = PyFloat_FromDouble((double)((glm_vec3 *)self)->vec[item]);
	return result;
}

static
int glm_vec3_sq_ass_item(PyObject *self, Py_ssize_t item, PyObject *value) {
	if(item >= 3) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return -1;
	}
	
	if(!PyNumber_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return -1;
	}
	
	((glm_vec3 *)self)->vec[item] = (float)PyFloat_AsDouble(value);
	
	return 0;
}

/* Definition */

static
PyObject * glm_vec3_tp_repr(PyObject *self) {
	glm::vec3 *v = &((glm_vec3 *)self)->vec;
	std::stringstream s;
	s.precision(std::numeric_limits<float>::digits10);
	s << Py_TYPE(self)->tp_name << "("
	 << (*v)[0]
	<< ", " << (*v)[1]
	<< ", " << (*v)[2]
	<< ")";
	PyObject *result = PyUnicode_FromString(s.str().c_str());
	return result;
}

static
int glm_vec3_tp_init(PyObject *self, PyObject *args, PyObject *kwargs) {
	if(1 != PyObject_IsInstance(self, (PyObject *)&glm_vec3Type)) {
		PyErr_SetString(PyExc_TypeError, "Can only init vec3.");
		return -1;
	}
	
	glm_vec3 *real = (glm_vec3 *)self;
	
	Py_ssize_t argsize = PyTuple_GET_SIZE(args);
	
	if(argsize == 0) {
		real->vec = glm::vec3();
		return 0;
	}
	
	if(argsize == 1) {
		PyObject *tmp;
		tmp = PyTuple_GET_ITEM(args, 0);
		
		if(PyNumber_Check(tmp)) {
			real->vec = glm::vec3((float)PyFloat_AsDouble(tmp));
			return 0;
		}
		
		if(PyBytes_CheckExact(tmp)) {
			memcpy(&real->vec, PyBytes_AsString(tmp), sizeof(float) * 3);
			
			return 0;
		}
	}
	
	real->vec = glm::vec3();
	
	PyObject *tmp;
	Py_ssize_t i;
	Py_ssize_t at = 0;

	for(i = 0; i < argsize; i++) {
		tmp = PyTuple_GET_ITEM(args, i);
		
		if(PyBytes_CheckExact(tmp)) {
			size_t len = PyBytes_Size(tmp) / sizeof(float);
			
			if(at + len > 2)
				len = 3 - at;
			
			memcpy(glm::value_ptr(real->vec) + at, PyBytes_AsString(tmp), len * sizeof(float));
			
			at += len;
		}
		else if(PyIter_Check(tmp) || Py_TYPE(tmp)->tp_iter) {
			PyObject *tmpi = PyObject_GetIter(tmp);
			PyObject *item;
	
			while(1) {
				item = PyIter_Next(tmpi);
				if(item == NULL)
					break;
		
				real->vec[at] = (float)PyFloat_AsDouble(item);
		
				Py_DECREF(item);
				
				at += 1;
			}
	
			Py_DECREF(tmpi);
		}
		else if(PyNumber_Check(tmp)) {
			real->vec[at] = (float)PyFloat_AsDouble(tmp);

			at += 1;
		}
		else {
			PyErr_Format(PyExc_TypeError, "Initialization only accepts numbers, sequences, and bytes as arguments, not '%s' at argument %i.", Py_TYPE(tmp)->tp_name, (int)at);
			return -1;
		}
		
		if(at > 3) {
			PyErr_SetString(PyExc_TypeError, "Too much data.");
			return -1;
		}
	}
	
	return 0;
}

static
PyObject * glm_vec3_tp_getattro(PyObject *self, PyObject *attr_name) {
	PyObject *tmp;
	tmp = PyObject_GenericGetAttr(self, attr_name);
	
	if(tmp != NULL)
		return tmp;
	else
		PyErr_Clear();
	
	if(!PyUnicode_Check(attr_name)) {
		PyErr_SetString(PyExc_TypeError, "Attributes use strings.");
		return NULL;
	}
	
	Py_ssize_t swizzles = PyObject_Size(attr_name);
	
	if(swizzles < 1) {
		PyErr_SetString(PyExc_TypeError, "Attributes are strings with a commendable length.");
		return NULL;
	}
	
	PyObject * result;
	PyObject * args;
	Py_ssize_t c;
	
	args = PyTuple_New(swizzles);
	
	if(args == NULL) {
		PyErr_SetString(PyExc_ValueError, "Could not create a simple tuple...hmmm...");
		return NULL;
	}
	
	for(c = 0; c < swizzles; c++) {
		tmp = PySequence_ITEM(attr_name, c);
		if(
			PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
			PyTuple_SET_ITEM(args, c, PyFloat_FromDouble((double)((glm_vec3 *)self)->vec[0]));
		else if(
			PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
			PyTuple_SET_ITEM(args, c, PyFloat_FromDouble((double)((glm_vec3 *)self)->vec[1]));
		else if(
			PyUnicode_CompareWithASCIIString(tmp, "z") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "p") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "b") == 0 )
			PyTuple_SET_ITEM(args, c, PyFloat_FromDouble((double)((glm_vec3 *)self)->vec[2]));
		else {
			Py_DECREF(tmp);
			Py_DECREF(args);
			PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
			return NULL;
		}
		
		Py_DECREF(tmp);
	}
	
	if(swizzles == 1) {
		result = PyTuple_GET_ITEM(args, 0);
		Py_INCREF(result);
	}
	else if(swizzles == 2)
		result = PyObject_CallObject((PyObject *)&glm_vec2Type, args);
	else if(swizzles == 3)
		result = PyObject_CallObject((PyObject *)&glm_vec3Type, args);
	else if(swizzles == 4)
		result = PyObject_CallObject((PyObject *)&glm_vec4Type, args);
	else
		return args;
	
	Py_DECREF(args);
	
	if(result == NULL)
		PyErr_SetString(PyExc_ValueError, "Could not create vector.");
	
	return result;
}

static
int glm_vec3_tp_setattro(PyObject *self, PyObject *attr_name, PyObject *value) {
	if(!PyUnicode_Check(attr_name)) {
		PyErr_SetString(PyExc_TypeError, "Attributes use strings.");
		return -1;
	}
	
	Py_ssize_t swizzles = PyObject_Size(attr_name);
	
	Py_ssize_t c;
	PyObject *tmp;
	
	if(PyNumber_Check(value)) {
		for(c = 0; c < swizzles; c++) {
			tmp = PySequence_ITEM(attr_name, c);
			if(
				PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
				((glm_vec3 *)self)->vec[0] = (float)PyFloat_AsDouble(value);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
				((glm_vec3 *)self)->vec[1] = (float)PyFloat_AsDouble(value);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "z") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "p") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "b") == 0 )
				((glm_vec3 *)self)->vec[2] = (float)PyFloat_AsDouble(value);
			else {
				Py_DECREF(tmp);
				PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
				return -1;
			}
		
			Py_DECREF(tmp);
		}
	}
	else if(PyIter_Check(value) || Py_TYPE(value)->tp_iter) {
		PyObject *iter = PyObject_GetIter(value);
		PyObject *iteritem;
		
		if(iter == NULL)
			return -1;
		
		for(c = 0; c < swizzles; c++) {
			tmp = PySequence_ITEM(attr_name, c);
			iteritem = PyIter_Next(iter);
			
			if(iteritem == NULL) {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				PyErr_SetString(PyExc_AttributeError, "Too few values.");
				return -1;
			}
			else if(!PyNumber_Check(iteritem)) {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				Py_DECREF(iteritem);
				PyErr_SetString(PyExc_AttributeError, "Values must all be numbers.");
				return -1;
			}
			if(
				PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
				((glm_vec3 *)self)->vec[0] = (float)PyFloat_AsDouble(iteritem);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
				((glm_vec3 *)self)->vec[1] = (float)PyFloat_AsDouble(iteritem);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "z") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "p") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "b") == 0 )
				((glm_vec3 *)self)->vec[2] = (float)PyFloat_AsDouble(iteritem);
			else {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				Py_DECREF(iteritem);
				PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
				return -1;
			}
			
			Py_DECREF(iteritem);
			Py_DECREF(tmp);
		}
		
		Py_DECREF(iter);
	}
	else {
		PyErr_SetString(PyExc_AttributeError, "Value must be a number or iterable.");
		return -1;
	}
	
	return 0;
}

int glm_vec3_bf_getbuffer(PyObject *self, Py_buffer *view, int flags) {
	PyBuffer_FillInfo(view, self, glm::value_ptr(((glm_vec3 *)self)->vec), sizeof(float) * 3, 1, PyBUF_SIMPLE);
	return 0;
}

PyObject *glm_vec3_tp_richcompare(PyObject *self, PyObject *other, int op) {
	switch(op) {
		case Py_EQ:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_vec3Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_EQ))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_vec3 *)self)->vec == ((glm_vec3 *)other)->vec) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		case Py_NE:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_vec3Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_NE))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_vec3 *)self)->vec != ((glm_vec3 *)other)->vec) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		default:
			PyErr_SetString(PyExc_TypeError, "Comparison not valid.");
			return NULL;
	}
}

Py_hash_t glm_vec3_tp_hash(PyObject *self) {
	Py_hash_t x;

	x = _Py_HashDouble((double)((glm_vec3 *)self)->vec[0]);
	x ^= _Py_HashDouble((double)((glm_vec3 *)self)->vec[1]) << 10;
	x ^= _Py_HashDouble((double)((glm_vec3 *)self)->vec[2]) << 20;
	
	if(x == -1)
		x = -2;
	
	return x;
}
/* * * vec4 * * */

/* vec4: Numbers */

static
PyObject *glm_vec4_nb_add(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec4 *)result)->vec = ((glm_vec4 *)self)->vec + (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_vec4 *)result)->vec = (float)PyFloat_AsDouble(self) + ((glm_vec4 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec4 *)result)->vec = ((glm_vec4 *)self)->vec + ((glm_vec4 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec4 *)result)->vec = ((glm_vec4 *)self)->vec + ((glm_vec4 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec4_nb_inplace_add(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_vec4 *)self)->vec += (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type))
		((glm_vec4 *)self)->vec += ((glm_vec4 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec4 *)self)->vec += ((glm_vec4 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_vec4_nb_subtract(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec4 *)result)->vec = ((glm_vec4 *)self)->vec - (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_vec4 *)result)->vec = (float)PyFloat_AsDouble(self) - ((glm_vec4 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec4 *)result)->vec = ((glm_vec4 *)self)->vec - ((glm_vec4 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec4 *)result)->vec = ((glm_vec4 *)self)->vec - ((glm_vec4 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec4_nb_inplace_subtract(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_vec4 *)self)->vec -= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type))
		((glm_vec4 *)self)->vec -= ((glm_vec4 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec4 *)self)->vec -= ((glm_vec4 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_vec4_nb_multiply(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec4 *)result)->vec = ((glm_vec4 *)self)->vec * (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_vec4 *)result)->vec = (float)PyFloat_AsDouble(self) * ((glm_vec4 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec4 *)result)->vec = ((glm_vec4 *)self)->vec * ((glm_vec4 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec4 *)result)->vec = ((glm_vec4 *)self)->vec * ((glm_vec4 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec4_nb_inplace_multiply(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_vec4 *)self)->vec *= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type))
		((glm_vec4 *)self)->vec *= ((glm_vec4 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec4 *)self)->vec *= ((glm_vec4 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_vec4_nb_true_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec4 *)result)->vec = ((glm_vec4 *)self)->vec / (float)PyFloat_AsDouble(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_vec4 *)result)->vec = (float)PyFloat_AsDouble(self) / ((glm_vec4 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec4 *)result)->vec = ((glm_vec4 *)self)->vec / ((glm_vec4 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec4 *)result)->vec = ((glm_vec4 *)self)->vec / ((glm_vec4 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec4_nb_inplace_true_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_vec4 *)self)->vec /= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type))
		((glm_vec4 *)self)->vec /= ((glm_vec4 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_vec4 *)self)->vec /= ((glm_vec4 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}


static
PyObject *glm_vec4_nb_remainder(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec4 *)result)->vec = glm::mod(((glm_vec4 *)self)->vec, (float)PyFloat_AsDouble(other));
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec4 *)result)->vec = glm::mod(((glm_vec4 *)self)->vec, ((glm_vec4 *)other)->vec);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec4_nb_divmod(PyObject *self, PyObject *other) {
	if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type)) {
		PyObject *whole = PyNumber_FloorDivide(self, other);
	
		if(whole == NULL)
			return NULL;
		
		PyObject *args = Py_BuildValue("(O)", self);
		PyObject *tmp = Py_TYPE(other)->tp_new(Py_TYPE(other), args, NULL);
		Py_DECREF(args);
		PyObject *remain = PyNumber_Remainder(tmp, other);
		Py_DECREF(tmp);
		
		if(remain == NULL) {
			Py_DECREF(whole);
			return NULL;
		}
		
		PyObject *result = Py_BuildValue("(OO)", whole, remain);
		
		Py_DECREF(whole);
		Py_DECREF(remain);
		
		return result;
	}
	else if(!PyNumber_Check(other) && 1 != PyObject_IsInstance(other, (PyObject *)&glm_vec4Type)) {
		PyErr_SetString(PyExc_TypeError, "Other must be a number or of the same type.");
		return NULL;
	}
	
	PyObject *whole = PyNumber_FloorDivide(self, other);
	
	if(whole == NULL)
		return NULL;
	
	PyObject *remain = PyNumber_Remainder(self, other);
	
	if(remain == NULL) {
		Py_DECREF(whole);
		return NULL;
	}
	
	PyObject *result = Py_BuildValue("(OO)", whole, remain);
	
	Py_DECREF(whole);
	Py_DECREF(remain);
	
	return result;
}

static
PyObject *glm_vec4_nb_power(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);;
		
		((glm_vec4 *)result)->vec = glm::pow(((glm_vec4 *)self)->vec, glm::vec4((float)PyFloat_AsDouble(other)));
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec4 *)result)->vec = glm::pow(((glm_vec4 *)self)->vec, ((glm_vec4 *)other)->vec);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec4_nb_negative(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_vec4 *)result)->vec = -((glm_vec4 *)self)->vec;
	return result;
}

static
PyObject *glm_vec4_nb_positive(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	return result;
}

static
PyObject *glm_vec4_nb_absolute(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_vec4 *)result)->vec = glm::abs(((glm_vec4 *)self)->vec);
	return result;
}


static
PyObject *glm_vec4_nb_floor_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec4 *)result)->vec = glm::floor(((glm_vec4 *)self)->vec / (float)PyFloat_AsDouble(other));
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_vec4 *)result)->vec = glm::floor((float)PyFloat_AsDouble(self) / ((glm_vec4 *)other)->vec);
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_vec4 *)result)->vec = glm::floor(((glm_vec4 *)self)->vec / ((glm_vec4 *)other)->vec);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_vec4_nb_inplace_floor_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_vec4 *)self)->vec /= (float)PyFloat_AsDouble(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_vec4Type))
		((glm_vec4 *)self)->vec /= ((glm_vec4 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	((glm_vec4 *)self)->vec = glm::floor(((glm_vec4 *)self)->vec);
	
	Py_INCREF(self);
	return self;
}

/* vec4: Sequence */

static
Py_ssize_t glm_vec4_sq_length(PyObject *self) {
	return 4;
}

static
PyObject *glm_vec4_sq_item(PyObject *self, Py_ssize_t item) {
	PyObject *result;
	if(item >= 4) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return NULL;
	}
	
	result = PyFloat_FromDouble((double)((glm_vec4 *)self)->vec[item]);
	return result;
}

static
int glm_vec4_sq_ass_item(PyObject *self, Py_ssize_t item, PyObject *value) {
	if(item >= 4) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return -1;
	}
	
	if(!PyNumber_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return -1;
	}
	
	((glm_vec4 *)self)->vec[item] = (float)PyFloat_AsDouble(value);
	
	return 0;
}

/* Definition */

static
PyObject * glm_vec4_tp_repr(PyObject *self) {
	glm::vec4 *v = &((glm_vec4 *)self)->vec;
	std::stringstream s;
	s.precision(std::numeric_limits<float>::digits10);
	s << Py_TYPE(self)->tp_name << "("
	 << (*v)[0]
	<< ", " << (*v)[1]
	<< ", " << (*v)[2]
	<< ", " << (*v)[3]
	<< ")";
	PyObject *result = PyUnicode_FromString(s.str().c_str());
	return result;
}

static
int glm_vec4_tp_init(PyObject *self, PyObject *args, PyObject *kwargs) {
	if(1 != PyObject_IsInstance(self, (PyObject *)&glm_vec4Type)) {
		PyErr_SetString(PyExc_TypeError, "Can only init vec4.");
		return -1;
	}
	
	glm_vec4 *real = (glm_vec4 *)self;
	
	Py_ssize_t argsize = PyTuple_GET_SIZE(args);
	
	if(argsize == 0) {
		real->vec = glm::vec4();
		return 0;
	}
	
	if(argsize == 1) {
		PyObject *tmp;
		tmp = PyTuple_GET_ITEM(args, 0);
		
		if(PyNumber_Check(tmp)) {
			real->vec = glm::vec4((float)PyFloat_AsDouble(tmp));
			return 0;
		}
		
		if(PyBytes_CheckExact(tmp)) {
			memcpy(&real->vec, PyBytes_AsString(tmp), sizeof(float) * 4);
			
			return 0;
		}
	}
	
	real->vec = glm::vec4();
	
	PyObject *tmp;
	Py_ssize_t i;
	Py_ssize_t at = 0;

	for(i = 0; i < argsize; i++) {
		tmp = PyTuple_GET_ITEM(args, i);
		
		if(PyBytes_CheckExact(tmp)) {
			size_t len = PyBytes_Size(tmp) / sizeof(float);
			
			if(at + len > 3)
				len = 4 - at;
			
			memcpy(glm::value_ptr(real->vec) + at, PyBytes_AsString(tmp), len * sizeof(float));
			
			at += len;
		}
		else if(PyIter_Check(tmp) || Py_TYPE(tmp)->tp_iter) {
			PyObject *tmpi = PyObject_GetIter(tmp);
			PyObject *item;
	
			while(1) {
				item = PyIter_Next(tmpi);
				if(item == NULL)
					break;
		
				real->vec[at] = (float)PyFloat_AsDouble(item);
		
				Py_DECREF(item);
				
				at += 1;
			}
	
			Py_DECREF(tmpi);
		}
		else if(PyNumber_Check(tmp)) {
			real->vec[at] = (float)PyFloat_AsDouble(tmp);

			at += 1;
		}
		else {
			PyErr_Format(PyExc_TypeError, "Initialization only accepts numbers, sequences, and bytes as arguments, not '%s' at argument %i.", Py_TYPE(tmp)->tp_name, (int)at);
			return -1;
		}
		
		if(at > 4) {
			PyErr_SetString(PyExc_TypeError, "Too much data.");
			return -1;
		}
	}
	
	return 0;
}

static
PyObject * glm_vec4_tp_getattro(PyObject *self, PyObject *attr_name) {
	PyObject *tmp;
	tmp = PyObject_GenericGetAttr(self, attr_name);
	
	if(tmp != NULL)
		return tmp;
	else
		PyErr_Clear();
	
	if(!PyUnicode_Check(attr_name)) {
		PyErr_SetString(PyExc_TypeError, "Attributes use strings.");
		return NULL;
	}
	
	Py_ssize_t swizzles = PyObject_Size(attr_name);
	
	if(swizzles < 1) {
		PyErr_SetString(PyExc_TypeError, "Attributes are strings with a commendable length.");
		return NULL;
	}
	
	PyObject * result;
	PyObject * args;
	Py_ssize_t c;
	
	args = PyTuple_New(swizzles);
	
	if(args == NULL) {
		PyErr_SetString(PyExc_ValueError, "Could not create a simple tuple...hmmm...");
		return NULL;
	}
	
	for(c = 0; c < swizzles; c++) {
		tmp = PySequence_ITEM(attr_name, c);
		if(
			PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
			PyTuple_SET_ITEM(args, c, PyFloat_FromDouble((double)((glm_vec4 *)self)->vec[0]));
		else if(
			PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
			PyTuple_SET_ITEM(args, c, PyFloat_FromDouble((double)((glm_vec4 *)self)->vec[1]));
		else if(
			PyUnicode_CompareWithASCIIString(tmp, "z") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "p") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "b") == 0 )
			PyTuple_SET_ITEM(args, c, PyFloat_FromDouble((double)((glm_vec4 *)self)->vec[2]));
		else if(
			PyUnicode_CompareWithASCIIString(tmp, "w") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "q") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "a") == 0 )
			PyTuple_SET_ITEM(args, c, PyFloat_FromDouble((double)((glm_vec4 *)self)->vec[3]));
		else {
			Py_DECREF(tmp);
			Py_DECREF(args);
			PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
			return NULL;
		}
		
		Py_DECREF(tmp);
	}
	
	if(swizzles == 1) {
		result = PyTuple_GET_ITEM(args, 0);
		Py_INCREF(result);
	}
	else if(swizzles == 2)
		result = PyObject_CallObject((PyObject *)&glm_vec2Type, args);
	else if(swizzles == 3)
		result = PyObject_CallObject((PyObject *)&glm_vec3Type, args);
	else if(swizzles == 4)
		result = PyObject_CallObject((PyObject *)&glm_vec4Type, args);
	else
		return args;
	
	Py_DECREF(args);
	
	if(result == NULL)
		PyErr_SetString(PyExc_ValueError, "Could not create vector.");
	
	return result;
}

static
int glm_vec4_tp_setattro(PyObject *self, PyObject *attr_name, PyObject *value) {
	if(!PyUnicode_Check(attr_name)) {
		PyErr_SetString(PyExc_TypeError, "Attributes use strings.");
		return -1;
	}
	
	Py_ssize_t swizzles = PyObject_Size(attr_name);
	
	Py_ssize_t c;
	PyObject *tmp;
	
	if(PyNumber_Check(value)) {
		for(c = 0; c < swizzles; c++) {
			tmp = PySequence_ITEM(attr_name, c);
			if(
				PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
				((glm_vec4 *)self)->vec[0] = (float)PyFloat_AsDouble(value);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
				((glm_vec4 *)self)->vec[1] = (float)PyFloat_AsDouble(value);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "z") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "p") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "b") == 0 )
				((glm_vec4 *)self)->vec[2] = (float)PyFloat_AsDouble(value);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "w") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "q") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "a") == 0 )
				((glm_vec4 *)self)->vec[3] = (float)PyFloat_AsDouble(value);
			else {
				Py_DECREF(tmp);
				PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
				return -1;
			}
		
			Py_DECREF(tmp);
		}
	}
	else if(PyIter_Check(value) || Py_TYPE(value)->tp_iter) {
		PyObject *iter = PyObject_GetIter(value);
		PyObject *iteritem;
		
		if(iter == NULL)
			return -1;
		
		for(c = 0; c < swizzles; c++) {
			tmp = PySequence_ITEM(attr_name, c);
			iteritem = PyIter_Next(iter);
			
			if(iteritem == NULL) {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				PyErr_SetString(PyExc_AttributeError, "Too few values.");
				return -1;
			}
			else if(!PyNumber_Check(iteritem)) {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				Py_DECREF(iteritem);
				PyErr_SetString(PyExc_AttributeError, "Values must all be numbers.");
				return -1;
			}
			if(
				PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
				((glm_vec4 *)self)->vec[0] = (float)PyFloat_AsDouble(iteritem);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
				((glm_vec4 *)self)->vec[1] = (float)PyFloat_AsDouble(iteritem);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "z") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "p") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "b") == 0 )
				((glm_vec4 *)self)->vec[2] = (float)PyFloat_AsDouble(iteritem);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "w") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "q") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "a") == 0 )
				((glm_vec4 *)self)->vec[3] = (float)PyFloat_AsDouble(iteritem);
			else {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				Py_DECREF(iteritem);
				PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
				return -1;
			}
			
			Py_DECREF(iteritem);
			Py_DECREF(tmp);
		}
		
		Py_DECREF(iter);
	}
	else {
		PyErr_SetString(PyExc_AttributeError, "Value must be a number or iterable.");
		return -1;
	}
	
	return 0;
}

int glm_vec4_bf_getbuffer(PyObject *self, Py_buffer *view, int flags) {
	PyBuffer_FillInfo(view, self, glm::value_ptr(((glm_vec4 *)self)->vec), sizeof(float) * 4, 1, PyBUF_SIMPLE);
	return 0;
}

PyObject *glm_vec4_tp_richcompare(PyObject *self, PyObject *other, int op) {
	switch(op) {
		case Py_EQ:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_vec4Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_EQ))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_vec4 *)self)->vec == ((glm_vec4 *)other)->vec) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		case Py_NE:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_vec4Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_NE))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_vec4 *)self)->vec != ((glm_vec4 *)other)->vec) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		default:
			PyErr_SetString(PyExc_TypeError, "Comparison not valid.");
			return NULL;
	}
}

Py_hash_t glm_vec4_tp_hash(PyObject *self) {
	Py_hash_t x;

	x = _Py_HashDouble((double)((glm_vec4 *)self)->vec[0]);
	x ^= _Py_HashDouble((double)((glm_vec4 *)self)->vec[1]) << 7;
	x ^= _Py_HashDouble((double)((glm_vec4 *)self)->vec[2]) << 15;
	x ^= _Py_HashDouble((double)((glm_vec4 *)self)->vec[3]) << 23;
	
	if(x == -1)
		x = -2;
	
	return x;
}
/* * * ivec2 * * */

/* ivec2: Numbers */

static
PyObject *glm_ivec2_nb_add(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec + (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec2 *)result)->vec = (int)PyLong_AsLong(self) + ((glm_ivec2 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec + ((glm_ivec2 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec + ((glm_ivec2 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec2_nb_inplace_add(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec2 *)self)->vec += (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type))
		((glm_ivec2 *)self)->vec += ((glm_ivec2 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec2 *)self)->vec += ((glm_ivec2 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec2_nb_subtract(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec - (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec2 *)result)->vec = (int)PyLong_AsLong(self) - ((glm_ivec2 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec - ((glm_ivec2 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec - ((glm_ivec2 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec2_nb_inplace_subtract(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec2 *)self)->vec -= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type))
		((glm_ivec2 *)self)->vec -= ((glm_ivec2 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec2 *)self)->vec -= ((glm_ivec2 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec2_nb_multiply(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec * (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec2 *)result)->vec = (int)PyLong_AsLong(self) * ((glm_ivec2 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec * ((glm_ivec2 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec * ((glm_ivec2 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec2_nb_inplace_multiply(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec2 *)self)->vec *= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type))
		((glm_ivec2 *)self)->vec *= ((glm_ivec2 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec2 *)self)->vec *= ((glm_ivec2 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec2_nb_true_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec / (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec2 *)result)->vec = (int)PyLong_AsLong(self) / ((glm_ivec2 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec / ((glm_ivec2 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec / ((glm_ivec2 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec2_nb_inplace_true_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec2 *)self)->vec /= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type))
		((glm_ivec2 *)self)->vec /= ((glm_ivec2 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec2 *)self)->vec /= ((glm_ivec2 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec2_nb_lshift(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec << (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec2 *)result)->vec = (int)PyLong_AsLong(self) << ((glm_ivec2 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec << ((glm_ivec2 *)other)->vec;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec2_nb_inplace_lshift(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec2 *)self)->vec <<= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type))
		((glm_ivec2 *)self)->vec <<= ((glm_ivec2 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec2_nb_rshift(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec >> (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec2 *)result)->vec = (int)PyLong_AsLong(self) >> ((glm_ivec2 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec >> ((glm_ivec2 *)other)->vec;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec2_nb_inplace_rshift(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec2 *)self)->vec >>= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type))
		((glm_ivec2 *)self)->vec >>= ((glm_ivec2 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec2_nb_and(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec & (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec2 *)result)->vec = (int)PyLong_AsLong(self) & ((glm_ivec2 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec & ((glm_ivec2 *)other)->vec;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec2_nb_inplace_and(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec2 *)self)->vec &= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type))
		((glm_ivec2 *)self)->vec &= ((glm_ivec2 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec2_nb_xor(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec ^ (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec2 *)result)->vec = (int)PyLong_AsLong(self) ^ ((glm_ivec2 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec ^ ((glm_ivec2 *)other)->vec;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec2_nb_inplace_xor(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec2 *)self)->vec ^= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type))
		((glm_ivec2 *)self)->vec ^= ((glm_ivec2 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec2_nb_or(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec | (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec2 *)result)->vec = (int)PyLong_AsLong(self) | ((glm_ivec2 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec2 *)result)->vec = ((glm_ivec2 *)self)->vec | ((glm_ivec2 *)other)->vec;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec2_nb_inplace_or(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec2 *)self)->vec |= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type))
		((glm_ivec2 *)self)->vec |= ((glm_ivec2 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}



static
PyObject *glm_ivec2_nb_negative(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_ivec2 *)result)->vec = -((glm_ivec2 *)self)->vec;
	return result;
}

static
PyObject *glm_ivec2_nb_positive(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	return result;
}

static
PyObject *glm_ivec2_nb_absolute(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_ivec2 *)result)->vec = glm::abs(((glm_ivec2 *)self)->vec);
	return result;
}

static
PyObject *glm_ivec2_nb_invert(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_ivec2 *)result)->vec = ~((glm_ivec2 *)self)->vec;
	return result;
}



/* ivec2: Sequence */

static
Py_ssize_t glm_ivec2_sq_length(PyObject *self) {
	return 2;
}

static
PyObject *glm_ivec2_sq_item(PyObject *self, Py_ssize_t item) {
	PyObject *result;
	if(item >= 2) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return NULL;
	}
	
	result = PyLong_FromLong((long)((glm_ivec2 *)self)->vec[item]);
	return result;
}

static
int glm_ivec2_sq_ass_item(PyObject *self, Py_ssize_t item, PyObject *value) {
	if(item >= 2) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return -1;
	}
	
	if(!PyNumber_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return -1;
	}
	
	((glm_ivec2 *)self)->vec[item] = (int)PyLong_AsLong(value);
	
	return 0;
}

/* Definition */

static
PyObject * glm_ivec2_tp_repr(PyObject *self) {
	glm::ivec2 *v = &((glm_ivec2 *)self)->vec;
	std::stringstream s;
	s << Py_TYPE(self)->tp_name << "("
	 << (*v)[0]
	<< ", " << (*v)[1]
	<< ")";
	PyObject *result = PyUnicode_FromString(s.str().c_str());
	return result;
}

static
int glm_ivec2_tp_init(PyObject *self, PyObject *args, PyObject *kwargs) {
	if(1 != PyObject_IsInstance(self, (PyObject *)&glm_ivec2Type)) {
		PyErr_SetString(PyExc_TypeError, "Can only init ivec2.");
		return -1;
	}
	
	glm_ivec2 *real = (glm_ivec2 *)self;
	
	Py_ssize_t argsize = PyTuple_GET_SIZE(args);
	
	if(argsize == 0) {
		real->vec = glm::ivec2();
		return 0;
	}
	
	if(argsize == 1) {
		PyObject *tmp;
		tmp = PyTuple_GET_ITEM(args, 0);
		
		if(PyNumber_Check(tmp)) {
			real->vec = glm::ivec2((int)PyLong_AsLong(tmp));
			return 0;
		}
		
		if(PyBytes_CheckExact(tmp)) {
			memcpy(&real->vec, PyBytes_AsString(tmp), sizeof(int) * 2);
			
			return 0;
		}
	}
	
	real->vec = glm::ivec2();
	
	PyObject *tmp;
	Py_ssize_t i;
	Py_ssize_t at = 0;

	for(i = 0; i < argsize; i++) {
		tmp = PyTuple_GET_ITEM(args, i);
		
		if(PyBytes_CheckExact(tmp)) {
			size_t len = PyBytes_Size(tmp) / sizeof(int);
			
			if(at + len > 1)
				len = 2 - at;
			
			memcpy(glm::value_ptr(real->vec) + at, PyBytes_AsString(tmp), len * sizeof(int));
			
			at += len;
		}
		else if(PyIter_Check(tmp) || Py_TYPE(tmp)->tp_iter) {
			PyObject *tmpi = PyObject_GetIter(tmp);
			PyObject *item;
	
			while(1) {
				item = PyIter_Next(tmpi);
				if(item == NULL)
					break;
		
				real->vec[at] = (int)PyLong_AsLong(item);
		
				Py_DECREF(item);
				
				at += 1;
			}
	
			Py_DECREF(tmpi);
		}
		else if(PyNumber_Check(tmp)) {
			real->vec[at] = (int)PyLong_AsLong(tmp);

			at += 1;
		}
		else {
			PyErr_Format(PyExc_TypeError, "Initialization only accepts numbers, sequences, and bytes as arguments, not '%s' at argument %i.", Py_TYPE(tmp)->tp_name, (int)at);
			return -1;
		}
		
		if(at > 2) {
			PyErr_SetString(PyExc_TypeError, "Too much data.");
			return -1;
		}
	}
	
	return 0;
}

static
PyObject * glm_ivec2_tp_getattro(PyObject *self, PyObject *attr_name) {
	PyObject *tmp;
	tmp = PyObject_GenericGetAttr(self, attr_name);
	
	if(tmp != NULL)
		return tmp;
	else
		PyErr_Clear();
	
	if(!PyUnicode_Check(attr_name)) {
		PyErr_SetString(PyExc_TypeError, "Attributes use strings.");
		return NULL;
	}
	
	Py_ssize_t swizzles = PyObject_Size(attr_name);
	
	if(swizzles < 1) {
		PyErr_SetString(PyExc_TypeError, "Attributes are strings with a commendable length.");
		return NULL;
	}
	
	PyObject * result;
	PyObject * args;
	Py_ssize_t c;
	
	args = PyTuple_New(swizzles);
	
	if(args == NULL) {
		PyErr_SetString(PyExc_ValueError, "Could not create a simple tuple...hmmm...");
		return NULL;
	}
	
	for(c = 0; c < swizzles; c++) {
		tmp = PySequence_ITEM(attr_name, c);
		if(
			PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
			PyTuple_SET_ITEM(args, c, PyLong_FromLong((long)((glm_ivec2 *)self)->vec[0]));
		else if(
			PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
			PyTuple_SET_ITEM(args, c, PyLong_FromLong((long)((glm_ivec2 *)self)->vec[1]));
		else {
			Py_DECREF(tmp);
			Py_DECREF(args);
			PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
			return NULL;
		}
		
		Py_DECREF(tmp);
	}
	
	if(swizzles == 1) {
		result = PyTuple_GET_ITEM(args, 0);
		Py_INCREF(result);
	}
	else if(swizzles == 2)
		result = PyObject_CallObject((PyObject *)&glm_ivec2Type, args);
	else if(swizzles == 3)
		result = PyObject_CallObject((PyObject *)&glm_ivec3Type, args);
	else if(swizzles == 4)
		result = PyObject_CallObject((PyObject *)&glm_ivec4Type, args);
	else
		return args;
	
	Py_DECREF(args);
	
	if(result == NULL)
		PyErr_SetString(PyExc_ValueError, "Could not create vector.");
	
	return result;
}

static
int glm_ivec2_tp_setattro(PyObject *self, PyObject *attr_name, PyObject *value) {
	if(!PyUnicode_Check(attr_name)) {
		PyErr_SetString(PyExc_TypeError, "Attributes use strings.");
		return -1;
	}
	
	Py_ssize_t swizzles = PyObject_Size(attr_name);
	
	Py_ssize_t c;
	PyObject *tmp;
	
	if(PyNumber_Check(value)) {
		for(c = 0; c < swizzles; c++) {
			tmp = PySequence_ITEM(attr_name, c);
			if(
				PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
				((glm_ivec2 *)self)->vec[0] = (int)PyLong_AsLong(value);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
				((glm_ivec2 *)self)->vec[1] = (int)PyLong_AsLong(value);
			else {
				Py_DECREF(tmp);
				PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
				return -1;
			}
		
			Py_DECREF(tmp);
		}
	}
	else if(PyIter_Check(value) || Py_TYPE(value)->tp_iter) {
		PyObject *iter = PyObject_GetIter(value);
		PyObject *iteritem;
		
		if(iter == NULL)
			return -1;
		
		for(c = 0; c < swizzles; c++) {
			tmp = PySequence_ITEM(attr_name, c);
			iteritem = PyIter_Next(iter);
			
			if(iteritem == NULL) {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				PyErr_SetString(PyExc_AttributeError, "Too few values.");
				return -1;
			}
			else if(!PyNumber_Check(iteritem)) {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				Py_DECREF(iteritem);
				PyErr_SetString(PyExc_AttributeError, "Values must all be numbers.");
				return -1;
			}
			if(
				PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
				((glm_ivec2 *)self)->vec[0] = (int)PyLong_AsLong(iteritem);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
				((glm_ivec2 *)self)->vec[1] = (int)PyLong_AsLong(iteritem);
			else {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				Py_DECREF(iteritem);
				PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
				return -1;
			}
			
			Py_DECREF(iteritem);
			Py_DECREF(tmp);
		}
		
		Py_DECREF(iter);
	}
	else {
		PyErr_SetString(PyExc_AttributeError, "Value must be a number or iterable.");
		return -1;
	}
	
	return 0;
}

int glm_ivec2_bf_getbuffer(PyObject *self, Py_buffer *view, int flags) {
	PyBuffer_FillInfo(view, self, glm::value_ptr(((glm_ivec2 *)self)->vec), sizeof(int) * 2, 1, PyBUF_SIMPLE);
	return 0;
}

PyObject *glm_ivec2_tp_richcompare(PyObject *self, PyObject *other, int op) {
	switch(op) {
		case Py_EQ:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_EQ))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_ivec2 *)self)->vec == ((glm_ivec2 *)other)->vec) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		case Py_NE:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_ivec2Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_NE))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_ivec2 *)self)->vec != ((glm_ivec2 *)other)->vec) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		default:
			PyErr_SetString(PyExc_TypeError, "Comparison not valid.");
			return NULL;
	}
}

Py_hash_t glm_ivec2_tp_hash(PyObject *self) {
	Py_hash_t x;

	x = (Py_hash_t) ((glm_ivec2 *)self)->vec[0];
	x ^= (Py_hash_t) ((glm_ivec2 *)self)->vec[1] << 15;
	
	if(x == -1)
		x = -2;
	
	return x;
}
/* * * ivec3 * * */

/* ivec3: Numbers */

static
PyObject *glm_ivec3_nb_add(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec + (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec3 *)result)->vec = (int)PyLong_AsLong(self) + ((glm_ivec3 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec + ((glm_ivec3 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec + ((glm_ivec3 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec3_nb_inplace_add(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec3 *)self)->vec += (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type))
		((glm_ivec3 *)self)->vec += ((glm_ivec3 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec3 *)self)->vec += ((glm_ivec3 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec3_nb_subtract(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec - (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec3 *)result)->vec = (int)PyLong_AsLong(self) - ((glm_ivec3 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec - ((glm_ivec3 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec - ((glm_ivec3 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec3_nb_inplace_subtract(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec3 *)self)->vec -= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type))
		((glm_ivec3 *)self)->vec -= ((glm_ivec3 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec3 *)self)->vec -= ((glm_ivec3 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec3_nb_multiply(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec * (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec3 *)result)->vec = (int)PyLong_AsLong(self) * ((glm_ivec3 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec * ((glm_ivec3 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec * ((glm_ivec3 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec3_nb_inplace_multiply(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec3 *)self)->vec *= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type))
		((glm_ivec3 *)self)->vec *= ((glm_ivec3 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec3 *)self)->vec *= ((glm_ivec3 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec3_nb_true_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec / (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec3 *)result)->vec = (int)PyLong_AsLong(self) / ((glm_ivec3 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec / ((glm_ivec3 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec / ((glm_ivec3 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec3_nb_inplace_true_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec3 *)self)->vec /= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type))
		((glm_ivec3 *)self)->vec /= ((glm_ivec3 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec3 *)self)->vec /= ((glm_ivec3 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec3_nb_lshift(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec << (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec3 *)result)->vec = (int)PyLong_AsLong(self) << ((glm_ivec3 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec << ((glm_ivec3 *)other)->vec;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec3_nb_inplace_lshift(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec3 *)self)->vec <<= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type))
		((glm_ivec3 *)self)->vec <<= ((glm_ivec3 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec3_nb_rshift(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec >> (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec3 *)result)->vec = (int)PyLong_AsLong(self) >> ((glm_ivec3 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec >> ((glm_ivec3 *)other)->vec;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec3_nb_inplace_rshift(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec3 *)self)->vec >>= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type))
		((glm_ivec3 *)self)->vec >>= ((glm_ivec3 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec3_nb_and(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec & (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec3 *)result)->vec = (int)PyLong_AsLong(self) & ((glm_ivec3 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec & ((glm_ivec3 *)other)->vec;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec3_nb_inplace_and(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec3 *)self)->vec &= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type))
		((glm_ivec3 *)self)->vec &= ((glm_ivec3 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec3_nb_xor(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec ^ (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec3 *)result)->vec = (int)PyLong_AsLong(self) ^ ((glm_ivec3 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec ^ ((glm_ivec3 *)other)->vec;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec3_nb_inplace_xor(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec3 *)self)->vec ^= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type))
		((glm_ivec3 *)self)->vec ^= ((glm_ivec3 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec3_nb_or(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec | (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec3 *)result)->vec = (int)PyLong_AsLong(self) | ((glm_ivec3 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec3 *)result)->vec = ((glm_ivec3 *)self)->vec | ((glm_ivec3 *)other)->vec;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec3_nb_inplace_or(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec3 *)self)->vec |= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type))
		((glm_ivec3 *)self)->vec |= ((glm_ivec3 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}



static
PyObject *glm_ivec3_nb_negative(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_ivec3 *)result)->vec = -((glm_ivec3 *)self)->vec;
	return result;
}

static
PyObject *glm_ivec3_nb_positive(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	return result;
}

static
PyObject *glm_ivec3_nb_absolute(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_ivec3 *)result)->vec = glm::abs(((glm_ivec3 *)self)->vec);
	return result;
}

static
PyObject *glm_ivec3_nb_invert(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_ivec3 *)result)->vec = ~((glm_ivec3 *)self)->vec;
	return result;
}



/* ivec3: Sequence */

static
Py_ssize_t glm_ivec3_sq_length(PyObject *self) {
	return 3;
}

static
PyObject *glm_ivec3_sq_item(PyObject *self, Py_ssize_t item) {
	PyObject *result;
	if(item >= 3) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return NULL;
	}
	
	result = PyLong_FromLong((long)((glm_ivec3 *)self)->vec[item]);
	return result;
}

static
int glm_ivec3_sq_ass_item(PyObject *self, Py_ssize_t item, PyObject *value) {
	if(item >= 3) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return -1;
	}
	
	if(!PyNumber_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return -1;
	}
	
	((glm_ivec3 *)self)->vec[item] = (int)PyLong_AsLong(value);
	
	return 0;
}

/* Definition */

static
PyObject * glm_ivec3_tp_repr(PyObject *self) {
	glm::ivec3 *v = &((glm_ivec3 *)self)->vec;
	std::stringstream s;
	s << Py_TYPE(self)->tp_name << "("
	 << (*v)[0]
	<< ", " << (*v)[1]
	<< ", " << (*v)[2]
	<< ")";
	PyObject *result = PyUnicode_FromString(s.str().c_str());
	return result;
}

static
int glm_ivec3_tp_init(PyObject *self, PyObject *args, PyObject *kwargs) {
	if(1 != PyObject_IsInstance(self, (PyObject *)&glm_ivec3Type)) {
		PyErr_SetString(PyExc_TypeError, "Can only init ivec3.");
		return -1;
	}
	
	glm_ivec3 *real = (glm_ivec3 *)self;
	
	Py_ssize_t argsize = PyTuple_GET_SIZE(args);
	
	if(argsize == 0) {
		real->vec = glm::ivec3();
		return 0;
	}
	
	if(argsize == 1) {
		PyObject *tmp;
		tmp = PyTuple_GET_ITEM(args, 0);
		
		if(PyNumber_Check(tmp)) {
			real->vec = glm::ivec3((int)PyLong_AsLong(tmp));
			return 0;
		}
		
		if(PyBytes_CheckExact(tmp)) {
			memcpy(&real->vec, PyBytes_AsString(tmp), sizeof(int) * 3);
			
			return 0;
		}
	}
	
	real->vec = glm::ivec3();
	
	PyObject *tmp;
	Py_ssize_t i;
	Py_ssize_t at = 0;

	for(i = 0; i < argsize; i++) {
		tmp = PyTuple_GET_ITEM(args, i);
		
		if(PyBytes_CheckExact(tmp)) {
			size_t len = PyBytes_Size(tmp) / sizeof(int);
			
			if(at + len > 2)
				len = 3 - at;
			
			memcpy(glm::value_ptr(real->vec) + at, PyBytes_AsString(tmp), len * sizeof(int));
			
			at += len;
		}
		else if(PyIter_Check(tmp) || Py_TYPE(tmp)->tp_iter) {
			PyObject *tmpi = PyObject_GetIter(tmp);
			PyObject *item;
	
			while(1) {
				item = PyIter_Next(tmpi);
				if(item == NULL)
					break;
		
				real->vec[at] = (int)PyLong_AsLong(item);
		
				Py_DECREF(item);
				
				at += 1;
			}
	
			Py_DECREF(tmpi);
		}
		else if(PyNumber_Check(tmp)) {
			real->vec[at] = (int)PyLong_AsLong(tmp);

			at += 1;
		}
		else {
			PyErr_Format(PyExc_TypeError, "Initialization only accepts numbers, sequences, and bytes as arguments, not '%s' at argument %i.", Py_TYPE(tmp)->tp_name, (int)at);
			return -1;
		}
		
		if(at > 3) {
			PyErr_SetString(PyExc_TypeError, "Too much data.");
			return -1;
		}
	}
	
	return 0;
}

static
PyObject * glm_ivec3_tp_getattro(PyObject *self, PyObject *attr_name) {
	PyObject *tmp;
	tmp = PyObject_GenericGetAttr(self, attr_name);
	
	if(tmp != NULL)
		return tmp;
	else
		PyErr_Clear();
	
	if(!PyUnicode_Check(attr_name)) {
		PyErr_SetString(PyExc_TypeError, "Attributes use strings.");
		return NULL;
	}
	
	Py_ssize_t swizzles = PyObject_Size(attr_name);
	
	if(swizzles < 1) {
		PyErr_SetString(PyExc_TypeError, "Attributes are strings with a commendable length.");
		return NULL;
	}
	
	PyObject * result;
	PyObject * args;
	Py_ssize_t c;
	
	args = PyTuple_New(swizzles);
	
	if(args == NULL) {
		PyErr_SetString(PyExc_ValueError, "Could not create a simple tuple...hmmm...");
		return NULL;
	}
	
	for(c = 0; c < swizzles; c++) {
		tmp = PySequence_ITEM(attr_name, c);
		if(
			PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
			PyTuple_SET_ITEM(args, c, PyLong_FromLong((long)((glm_ivec3 *)self)->vec[0]));
		else if(
			PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
			PyTuple_SET_ITEM(args, c, PyLong_FromLong((long)((glm_ivec3 *)self)->vec[1]));
		else if(
			PyUnicode_CompareWithASCIIString(tmp, "z") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "p") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "b") == 0 )
			PyTuple_SET_ITEM(args, c, PyLong_FromLong((long)((glm_ivec3 *)self)->vec[2]));
		else {
			Py_DECREF(tmp);
			Py_DECREF(args);
			PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
			return NULL;
		}
		
		Py_DECREF(tmp);
	}
	
	if(swizzles == 1) {
		result = PyTuple_GET_ITEM(args, 0);
		Py_INCREF(result);
	}
	else if(swizzles == 2)
		result = PyObject_CallObject((PyObject *)&glm_ivec2Type, args);
	else if(swizzles == 3)
		result = PyObject_CallObject((PyObject *)&glm_ivec3Type, args);
	else if(swizzles == 4)
		result = PyObject_CallObject((PyObject *)&glm_ivec4Type, args);
	else
		return args;
	
	Py_DECREF(args);
	
	if(result == NULL)
		PyErr_SetString(PyExc_ValueError, "Could not create vector.");
	
	return result;
}

static
int glm_ivec3_tp_setattro(PyObject *self, PyObject *attr_name, PyObject *value) {
	if(!PyUnicode_Check(attr_name)) {
		PyErr_SetString(PyExc_TypeError, "Attributes use strings.");
		return -1;
	}
	
	Py_ssize_t swizzles = PyObject_Size(attr_name);
	
	Py_ssize_t c;
	PyObject *tmp;
	
	if(PyNumber_Check(value)) {
		for(c = 0; c < swizzles; c++) {
			tmp = PySequence_ITEM(attr_name, c);
			if(
				PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
				((glm_ivec3 *)self)->vec[0] = (int)PyLong_AsLong(value);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
				((glm_ivec3 *)self)->vec[1] = (int)PyLong_AsLong(value);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "z") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "p") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "b") == 0 )
				((glm_ivec3 *)self)->vec[2] = (int)PyLong_AsLong(value);
			else {
				Py_DECREF(tmp);
				PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
				return -1;
			}
		
			Py_DECREF(tmp);
		}
	}
	else if(PyIter_Check(value) || Py_TYPE(value)->tp_iter) {
		PyObject *iter = PyObject_GetIter(value);
		PyObject *iteritem;
		
		if(iter == NULL)
			return -1;
		
		for(c = 0; c < swizzles; c++) {
			tmp = PySequence_ITEM(attr_name, c);
			iteritem = PyIter_Next(iter);
			
			if(iteritem == NULL) {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				PyErr_SetString(PyExc_AttributeError, "Too few values.");
				return -1;
			}
			else if(!PyNumber_Check(iteritem)) {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				Py_DECREF(iteritem);
				PyErr_SetString(PyExc_AttributeError, "Values must all be numbers.");
				return -1;
			}
			if(
				PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
				((glm_ivec3 *)self)->vec[0] = (int)PyLong_AsLong(iteritem);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
				((glm_ivec3 *)self)->vec[1] = (int)PyLong_AsLong(iteritem);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "z") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "p") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "b") == 0 )
				((glm_ivec3 *)self)->vec[2] = (int)PyLong_AsLong(iteritem);
			else {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				Py_DECREF(iteritem);
				PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
				return -1;
			}
			
			Py_DECREF(iteritem);
			Py_DECREF(tmp);
		}
		
		Py_DECREF(iter);
	}
	else {
		PyErr_SetString(PyExc_AttributeError, "Value must be a number or iterable.");
		return -1;
	}
	
	return 0;
}

int glm_ivec3_bf_getbuffer(PyObject *self, Py_buffer *view, int flags) {
	PyBuffer_FillInfo(view, self, glm::value_ptr(((glm_ivec3 *)self)->vec), sizeof(int) * 3, 1, PyBUF_SIMPLE);
	return 0;
}

PyObject *glm_ivec3_tp_richcompare(PyObject *self, PyObject *other, int op) {
	switch(op) {
		case Py_EQ:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_EQ))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_ivec3 *)self)->vec == ((glm_ivec3 *)other)->vec) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		case Py_NE:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_ivec3Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_NE))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_ivec3 *)self)->vec != ((glm_ivec3 *)other)->vec) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		default:
			PyErr_SetString(PyExc_TypeError, "Comparison not valid.");
			return NULL;
	}
}

Py_hash_t glm_ivec3_tp_hash(PyObject *self) {
	Py_hash_t x;

	x = (Py_hash_t) ((glm_ivec3 *)self)->vec[0];
	x ^= (Py_hash_t) ((glm_ivec3 *)self)->vec[1] << 10;
	x ^= (Py_hash_t) ((glm_ivec3 *)self)->vec[2] << 20;
	
	if(x == -1)
		x = -2;
	
	return x;
}
/* * * ivec4 * * */

/* ivec4: Numbers */

static
PyObject *glm_ivec4_nb_add(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec + (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec4 *)result)->vec = (int)PyLong_AsLong(self) + ((glm_ivec4 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec + ((glm_ivec4 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec + ((glm_ivec4 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec4_nb_inplace_add(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec4 *)self)->vec += (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type))
		((glm_ivec4 *)self)->vec += ((glm_ivec4 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec4 *)self)->vec += ((glm_ivec4 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec4_nb_subtract(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec - (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec4 *)result)->vec = (int)PyLong_AsLong(self) - ((glm_ivec4 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec - ((glm_ivec4 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec - ((glm_ivec4 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec4_nb_inplace_subtract(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec4 *)self)->vec -= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type))
		((glm_ivec4 *)self)->vec -= ((glm_ivec4 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec4 *)self)->vec -= ((glm_ivec4 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec4_nb_multiply(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec * (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec4 *)result)->vec = (int)PyLong_AsLong(self) * ((glm_ivec4 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec * ((glm_ivec4 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec * ((glm_ivec4 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec4_nb_inplace_multiply(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec4 *)self)->vec *= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type))
		((glm_ivec4 *)self)->vec *= ((glm_ivec4 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec4 *)self)->vec *= ((glm_ivec4 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec4_nb_true_divide(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec / (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec4 *)result)->vec = (int)PyLong_AsLong(self) / ((glm_ivec4 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec / ((glm_ivec4 *)other)->vec;
	}
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec / ((glm_ivec4 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec4_nb_inplace_true_divide(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec4 *)self)->vec /= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type))
		((glm_ivec4 *)self)->vec /= ((glm_ivec4 *)other)->vec;
	else if(PyIter_Check(other) || Py_TYPE(other)->tp_iter) {
		PyObject *convert;
		PyObject *args = Py_BuildValue("(O)", other);
		convert = PyObject_CallObject((PyObject *)Py_TYPE(self), args);
		Py_DECREF(args);
		
		((glm_ivec4 *)self)->vec /= ((glm_ivec4 *)convert)->vec;
		
		Py_DECREF(convert);
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number, the same type, or an iterable.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec4_nb_lshift(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec << (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec4 *)result)->vec = (int)PyLong_AsLong(self) << ((glm_ivec4 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec << ((glm_ivec4 *)other)->vec;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec4_nb_inplace_lshift(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec4 *)self)->vec <<= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type))
		((glm_ivec4 *)self)->vec <<= ((glm_ivec4 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec4_nb_rshift(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec >> (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec4 *)result)->vec = (int)PyLong_AsLong(self) >> ((glm_ivec4 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec >> ((glm_ivec4 *)other)->vec;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec4_nb_inplace_rshift(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec4 *)self)->vec >>= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type))
		((glm_ivec4 *)self)->vec >>= ((glm_ivec4 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec4_nb_and(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec & (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec4 *)result)->vec = (int)PyLong_AsLong(self) & ((glm_ivec4 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec & ((glm_ivec4 *)other)->vec;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec4_nb_inplace_and(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec4 *)self)->vec &= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type))
		((glm_ivec4 *)self)->vec &= ((glm_ivec4 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec4_nb_xor(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec ^ (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec4 *)result)->vec = (int)PyLong_AsLong(self) ^ ((glm_ivec4 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec ^ ((glm_ivec4 *)other)->vec;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec4_nb_inplace_xor(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec4 *)self)->vec ^= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type))
		((glm_ivec4 *)self)->vec ^= ((glm_ivec4 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}

static
PyObject *glm_ivec4_nb_or(PyObject *self, PyObject *other) {
	PyObject *result;
	if(PyNumber_Check(other)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec | (int)PyLong_AsLong(other);
	}
	else if(PyNumber_Check(self) && 1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(other), NULL);
		((glm_ivec4 *)result)->vec = (int)PyLong_AsLong(self) | ((glm_ivec4 *)other)->vec;
	}
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
		result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
		((glm_ivec4 *)result)->vec = ((glm_ivec4 *)self)->vec | ((glm_ivec4 *)other)->vec;
	}
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	return result;
}

static
PyObject *glm_ivec4_nb_inplace_or(PyObject *self, PyObject *other) {
	if(PyNumber_Check(other))
		((glm_ivec4 *)self)->vec |= (int)PyLong_AsLong(other);
	else if(1 == PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type))
		((glm_ivec4 *)self)->vec |= ((glm_ivec4 *)other)->vec;
	else {
		PyErr_SetString(PyExc_TypeError, "Must be a number or of the same type.");
		return NULL;
	}
	
	Py_INCREF(self);
	return self;
}



static
PyObject *glm_ivec4_nb_negative(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_ivec4 *)result)->vec = -((glm_ivec4 *)self)->vec;
	return result;
}

static
PyObject *glm_ivec4_nb_positive(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	return result;
}

static
PyObject *glm_ivec4_nb_absolute(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_ivec4 *)result)->vec = glm::abs(((glm_ivec4 *)self)->vec);
	return result;
}

static
PyObject *glm_ivec4_nb_invert(PyObject *self) {
	PyObject *result;
	result = PyObject_CallObject((PyObject *)Py_TYPE(self), NULL);
	((glm_ivec4 *)result)->vec = ~((glm_ivec4 *)self)->vec;
	return result;
}



/* ivec4: Sequence */

static
Py_ssize_t glm_ivec4_sq_length(PyObject *self) {
	return 4;
}

static
PyObject *glm_ivec4_sq_item(PyObject *self, Py_ssize_t item) {
	PyObject *result;
	if(item >= 4) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return NULL;
	}
	
	result = PyLong_FromLong((long)((glm_ivec4 *)self)->vec[item]);
	return result;
}

static
int glm_ivec4_sq_ass_item(PyObject *self, Py_ssize_t item, PyObject *value) {
	if(item >= 4) {
		PyErr_SetString(PyExc_IndexError, "Out of range.");
		return -1;
	}
	
	if(!PyNumber_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "Must be a number.");
		return -1;
	}
	
	((glm_ivec4 *)self)->vec[item] = (int)PyLong_AsLong(value);
	
	return 0;
}

/* Definition */

static
PyObject * glm_ivec4_tp_repr(PyObject *self) {
	glm::ivec4 *v = &((glm_ivec4 *)self)->vec;
	std::stringstream s;
	s << Py_TYPE(self)->tp_name << "("
	 << (*v)[0]
	<< ", " << (*v)[1]
	<< ", " << (*v)[2]
	<< ", " << (*v)[3]
	<< ")";
	PyObject *result = PyUnicode_FromString(s.str().c_str());
	return result;
}

static
int glm_ivec4_tp_init(PyObject *self, PyObject *args, PyObject *kwargs) {
	if(1 != PyObject_IsInstance(self, (PyObject *)&glm_ivec4Type)) {
		PyErr_SetString(PyExc_TypeError, "Can only init ivec4.");
		return -1;
	}
	
	glm_ivec4 *real = (glm_ivec4 *)self;
	
	Py_ssize_t argsize = PyTuple_GET_SIZE(args);
	
	if(argsize == 0) {
		real->vec = glm::ivec4();
		return 0;
	}
	
	if(argsize == 1) {
		PyObject *tmp;
		tmp = PyTuple_GET_ITEM(args, 0);
		
		if(PyNumber_Check(tmp)) {
			real->vec = glm::ivec4((int)PyLong_AsLong(tmp));
			return 0;
		}
		
		if(PyBytes_CheckExact(tmp)) {
			memcpy(&real->vec, PyBytes_AsString(tmp), sizeof(int) * 4);
			
			return 0;
		}
	}
	
	real->vec = glm::ivec4();
	
	PyObject *tmp;
	Py_ssize_t i;
	Py_ssize_t at = 0;

	for(i = 0; i < argsize; i++) {
		tmp = PyTuple_GET_ITEM(args, i);
		
		if(PyBytes_CheckExact(tmp)) {
			size_t len = PyBytes_Size(tmp) / sizeof(int);
			
			if(at + len > 3)
				len = 4 - at;
			
			memcpy(glm::value_ptr(real->vec) + at, PyBytes_AsString(tmp), len * sizeof(int));
			
			at += len;
		}
		else if(PyIter_Check(tmp) || Py_TYPE(tmp)->tp_iter) {
			PyObject *tmpi = PyObject_GetIter(tmp);
			PyObject *item;
	
			while(1) {
				item = PyIter_Next(tmpi);
				if(item == NULL)
					break;
		
				real->vec[at] = (int)PyLong_AsLong(item);
		
				Py_DECREF(item);
				
				at += 1;
			}
	
			Py_DECREF(tmpi);
		}
		else if(PyNumber_Check(tmp)) {
			real->vec[at] = (int)PyLong_AsLong(tmp);

			at += 1;
		}
		else {
			PyErr_Format(PyExc_TypeError, "Initialization only accepts numbers, sequences, and bytes as arguments, not '%s' at argument %i.", Py_TYPE(tmp)->tp_name, (int)at);
			return -1;
		}
		
		if(at > 4) {
			PyErr_SetString(PyExc_TypeError, "Too much data.");
			return -1;
		}
	}
	
	return 0;
}

static
PyObject * glm_ivec4_tp_getattro(PyObject *self, PyObject *attr_name) {
	PyObject *tmp;
	tmp = PyObject_GenericGetAttr(self, attr_name);
	
	if(tmp != NULL)
		return tmp;
	else
		PyErr_Clear();
	
	if(!PyUnicode_Check(attr_name)) {
		PyErr_SetString(PyExc_TypeError, "Attributes use strings.");
		return NULL;
	}
	
	Py_ssize_t swizzles = PyObject_Size(attr_name);
	
	if(swizzles < 1) {
		PyErr_SetString(PyExc_TypeError, "Attributes are strings with a commendable length.");
		return NULL;
	}
	
	PyObject * result;
	PyObject * args;
	Py_ssize_t c;
	
	args = PyTuple_New(swizzles);
	
	if(args == NULL) {
		PyErr_SetString(PyExc_ValueError, "Could not create a simple tuple...hmmm...");
		return NULL;
	}
	
	for(c = 0; c < swizzles; c++) {
		tmp = PySequence_ITEM(attr_name, c);
		if(
			PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
			PyTuple_SET_ITEM(args, c, PyLong_FromLong((long)((glm_ivec4 *)self)->vec[0]));
		else if(
			PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
			PyTuple_SET_ITEM(args, c, PyLong_FromLong((long)((glm_ivec4 *)self)->vec[1]));
		else if(
			PyUnicode_CompareWithASCIIString(tmp, "z") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "p") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "b") == 0 )
			PyTuple_SET_ITEM(args, c, PyLong_FromLong((long)((glm_ivec4 *)self)->vec[2]));
		else if(
			PyUnicode_CompareWithASCIIString(tmp, "w") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "q") == 0 ||
			PyUnicode_CompareWithASCIIString(tmp, "a") == 0 )
			PyTuple_SET_ITEM(args, c, PyLong_FromLong((long)((glm_ivec4 *)self)->vec[3]));
		else {
			Py_DECREF(tmp);
			Py_DECREF(args);
			PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
			return NULL;
		}
		
		Py_DECREF(tmp);
	}
	
	if(swizzles == 1) {
		result = PyTuple_GET_ITEM(args, 0);
		Py_INCREF(result);
	}
	else if(swizzles == 2)
		result = PyObject_CallObject((PyObject *)&glm_ivec2Type, args);
	else if(swizzles == 3)
		result = PyObject_CallObject((PyObject *)&glm_ivec3Type, args);
	else if(swizzles == 4)
		result = PyObject_CallObject((PyObject *)&glm_ivec4Type, args);
	else
		return args;
	
	Py_DECREF(args);
	
	if(result == NULL)
		PyErr_SetString(PyExc_ValueError, "Could not create vector.");
	
	return result;
}

static
int glm_ivec4_tp_setattro(PyObject *self, PyObject *attr_name, PyObject *value) {
	if(!PyUnicode_Check(attr_name)) {
		PyErr_SetString(PyExc_TypeError, "Attributes use strings.");
		return -1;
	}
	
	Py_ssize_t swizzles = PyObject_Size(attr_name);
	
	Py_ssize_t c;
	PyObject *tmp;
	
	if(PyNumber_Check(value)) {
		for(c = 0; c < swizzles; c++) {
			tmp = PySequence_ITEM(attr_name, c);
			if(
				PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
				((glm_ivec4 *)self)->vec[0] = (int)PyLong_AsLong(value);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
				((glm_ivec4 *)self)->vec[1] = (int)PyLong_AsLong(value);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "z") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "p") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "b") == 0 )
				((glm_ivec4 *)self)->vec[2] = (int)PyLong_AsLong(value);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "w") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "q") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "a") == 0 )
				((glm_ivec4 *)self)->vec[3] = (int)PyLong_AsLong(value);
			else {
				Py_DECREF(tmp);
				PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
				return -1;
			}
		
			Py_DECREF(tmp);
		}
	}
	else if(PyIter_Check(value) || Py_TYPE(value)->tp_iter) {
		PyObject *iter = PyObject_GetIter(value);
		PyObject *iteritem;
		
		if(iter == NULL)
			return -1;
		
		for(c = 0; c < swizzles; c++) {
			tmp = PySequence_ITEM(attr_name, c);
			iteritem = PyIter_Next(iter);
			
			if(iteritem == NULL) {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				PyErr_SetString(PyExc_AttributeError, "Too few values.");
				return -1;
			}
			else if(!PyNumber_Check(iteritem)) {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				Py_DECREF(iteritem);
				PyErr_SetString(PyExc_AttributeError, "Values must all be numbers.");
				return -1;
			}
			if(
				PyUnicode_CompareWithASCIIString(tmp, "x") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "s") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "r") == 0 )
				((glm_ivec4 *)self)->vec[0] = (int)PyLong_AsLong(iteritem);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "y") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "t") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "g") == 0 )
				((glm_ivec4 *)self)->vec[1] = (int)PyLong_AsLong(iteritem);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "z") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "p") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "b") == 0 )
				((glm_ivec4 *)self)->vec[2] = (int)PyLong_AsLong(iteritem);
			else if(
				PyUnicode_CompareWithASCIIString(tmp, "w") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "q") == 0 ||
				PyUnicode_CompareWithASCIIString(tmp, "a") == 0 )
				((glm_ivec4 *)self)->vec[3] = (int)PyLong_AsLong(iteritem);
			else {
				Py_DECREF(tmp);
				Py_DECREF(iter);
				Py_DECREF(iteritem);
				PyErr_SetString(PyExc_AttributeError, "Swizzle out of range.");
				return -1;
			}
			
			Py_DECREF(iteritem);
			Py_DECREF(tmp);
		}
		
		Py_DECREF(iter);
	}
	else {
		PyErr_SetString(PyExc_AttributeError, "Value must be a number or iterable.");
		return -1;
	}
	
	return 0;
}

int glm_ivec4_bf_getbuffer(PyObject *self, Py_buffer *view, int flags) {
	PyBuffer_FillInfo(view, self, glm::value_ptr(((glm_ivec4 *)self)->vec), sizeof(int) * 4, 1, PyBUF_SIMPLE);
	return 0;
}

PyObject *glm_ivec4_tp_richcompare(PyObject *self, PyObject *other, int op) {
	switch(op) {
		case Py_EQ:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_EQ))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_ivec4 *)self)->vec == ((glm_ivec4 *)other)->vec) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		case Py_NE:
			if(1 != PyObject_IsInstance(other, (PyObject *)&glm_ivec4Type)) {
				if((PyIter_Check(other) || Py_TYPE(other)->tp_iter) && PyObject_Size(self) == PyObject_Size(other)) {
					PyObject *iter = PyObject_GetIter(self);
					PyObject *itero = PyObject_GetIter(other);
					PyObject *iteritem;
					PyObject *iteritemo;
					
					if(iter != NULL && itero != NULL) {
						while(true) {
							iteritem = PyIter_Next(iter);
							iteritemo = PyIter_Next(itero);
						
							if(iteritem == NULL && iteritemo == NULL) {
								Py_INCREF(Py_True);
								return Py_True;
							}
						
							if(iteritem == NULL || iteritemo == NULL || 1 != PyObject_RichCompareBool(iteritem, iteritemo, Py_NE))
								break;
							
							Py_DECREF(iteritem);
							Py_DECREF(iteritemo);
						}
					}
					
					Py_XDECREF(iter);
					Py_XDECREF(itero);
				}
				
				Py_INCREF(Py_False);
				return Py_False;
			}
			
			if(((glm_ivec4 *)self)->vec != ((glm_ivec4 *)other)->vec) {
				Py_INCREF(Py_True);
				return Py_True;
			}
			
			Py_INCREF(Py_False);
			return Py_False;
		default:
			PyErr_SetString(PyExc_TypeError, "Comparison not valid.");
			return NULL;
	}
}

Py_hash_t glm_ivec4_tp_hash(PyObject *self) {
	Py_hash_t x;

	x = (Py_hash_t) ((glm_ivec4 *)self)->vec[0];
	x ^= (Py_hash_t) ((glm_ivec4 *)self)->vec[1] << 7;
	x ^= (Py_hash_t) ((glm_ivec4 *)self)->vec[2] << 15;
	x ^= (Py_hash_t) ((glm_ivec4 *)self)->vec[3] << 23;
	
	if(x == -1)
		x = -2;
	
	return x;
}

/* * * New * * */

PyObject *glm_mat2New(glm::mat2 m) {
	glm_mat2 *result = PyObject_New(glm_mat2, &glm_mat2Type);
	result->mat = m;
	return (PyObject *)result;
}
PyObject *glm_mat3x2New(glm::mat3x2 m) {
	glm_mat3x2 *result = PyObject_New(glm_mat3x2, &glm_mat3x2Type);
	result->mat = m;
	return (PyObject *)result;
}
PyObject *glm_mat4x2New(glm::mat4x2 m) {
	glm_mat4x2 *result = PyObject_New(glm_mat4x2, &glm_mat4x2Type);
	result->mat = m;
	return (PyObject *)result;
}
PyObject *glm_mat2x3New(glm::mat2x3 m) {
	glm_mat2x3 *result = PyObject_New(glm_mat2x3, &glm_mat2x3Type);
	result->mat = m;
	return (PyObject *)result;
}
PyObject *glm_mat3New(glm::mat3 m) {
	glm_mat3 *result = PyObject_New(glm_mat3, &glm_mat3Type);
	result->mat = m;
	return (PyObject *)result;
}
PyObject *glm_mat4x3New(glm::mat4x3 m) {
	glm_mat4x3 *result = PyObject_New(glm_mat4x3, &glm_mat4x3Type);
	result->mat = m;
	return (PyObject *)result;
}
PyObject *glm_mat2x4New(glm::mat2x4 m) {
	glm_mat2x4 *result = PyObject_New(glm_mat2x4, &glm_mat2x4Type);
	result->mat = m;
	return (PyObject *)result;
}
PyObject *glm_mat3x4New(glm::mat3x4 m) {
	glm_mat3x4 *result = PyObject_New(glm_mat3x4, &glm_mat3x4Type);
	result->mat = m;
	return (PyObject *)result;
}
PyObject *glm_mat4New(glm::mat4 m) {
	glm_mat4 *result = PyObject_New(glm_mat4, &glm_mat4Type);
	result->mat = m;
	return (PyObject *)result;
}
PyObject *glm_vec2New(glm::vec2 v) {
	glm_vec2 *result = PyObject_New(glm_vec2, &glm_vec2Type);
	result->vec = v;
	return (PyObject *)result;
}
PyObject *glm_vec3New(glm::vec3 v) {
	glm_vec3 *result = PyObject_New(glm_vec3, &glm_vec3Type);
	result->vec = v;
	return (PyObject *)result;
}
PyObject *glm_vec4New(glm::vec4 v) {
	glm_vec4 *result = PyObject_New(glm_vec4, &glm_vec4Type);
	result->vec = v;
	return (PyObject *)result;
}
PyObject *glm_ivec2New(glm::ivec2 v) {
	glm_ivec2 *result = PyObject_New(glm_ivec2, &glm_ivec2Type);
	result->vec = v;
	return (PyObject *)result;
}
PyObject *glm_ivec3New(glm::ivec3 v) {
	glm_ivec3 *result = PyObject_New(glm_ivec3, &glm_ivec3Type);
	result->vec = v;
	return (PyObject *)result;
}
PyObject *glm_ivec4New(glm::ivec4 v) {
	glm_ivec4 *result = PyObject_New(glm_ivec4, &glm_ivec4Type);
	result->vec = v;
	return (PyObject *)result;
}

/* * * Vector * * */

static
PyObject *glm_Vector_tp_iter(PyObject *self) {
	PyObject *result;
	PyObject *args;
	args = Py_BuildValue("(O)", self);
	
	if(args == NULL) {
		PyErr_SetString(PyExc_SystemError, "Invalid self.");
		return (PyObject *) NULL;
	}
	
	result = PyObject_CallObject((PyObject *)&glm_VectorIteratorType, args);
	
	Py_DECREF(args);
	return result;
}

/* Vector Definition */

PyDoc_STRVAR(glm_VectorType__doc__, "This is a basic vector type that you can isinstance against.  It is also used for global function checking, and in theory you could make your own vector types which define custom calls for global functions.");

static
PyTypeObject glm_VectorType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.Vector",										/* tp_name */
	sizeof(glm_Vector),								/* tp_basicsize */
	0,													/* tp_itemsize */
	0,													/* tp_dealloc */
	0,													/* tp_print */
	0,													/* tp_getattr */
	0,													/* tp_setattr */
	0,													/* tp_reserved */
	0,													/* tp_repr */
	0,													/* tp_as_number */
	0,													/* tp_as_sequence */
	0,													/* tp_as_mapping */
	0,													/* tp_hash  */
	0,													/* tp_call */
	0,													/* tp_str */
	PyObject_GenericGetAttr,							/* tp_getattro */
	PyObject_GenericSetAttr,							/* tp_setattro */
	0,													/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	  Py_TPFLAGS_BASETYPE,								/* tp_flags */
	glm_VectorType__doc__,								/* tp_doc */
	0,													/* tp_traverse */
	0,													/* tp_clear */
	0,													/* tp_richcompare */
	0,													/* tp_weaklistoffset */
	(getiterfunc)glm_Vector_tp_iter,					/* tp_iter */
	0,													/* tp_iternext */
	0,													/* tp_methods */
	0,													/* tp_members */
	0,													/* tp_getset */
	0,													/* tp_base */
	0,													/* tp_dict */
	0,													/* tp_descr_get */
	0,													/* tp_descr_set */
	0,													/* tp_dictoffset */
	0,													/* tp_init */
	0,													/* tp_alloc */
	PyType_GenericNew,									/* tp_new */
};
/* * * Matrix * * */

static
PyObject *glm_Matrix_tp_iter(PyObject *self) {
	PyObject *result;
	PyObject *args;
	args = Py_BuildValue("(O)", self);
	
	if(args == NULL) {
		PyErr_SetString(PyExc_SystemError, "Invalid self.");
		return (PyObject *) NULL;
	}
	
	result = PyObject_CallObject((PyObject *)&glm_MatrixIteratorType, args);
	
	Py_DECREF(args);
	return result;
}

/* Matrix Definition */

PyDoc_STRVAR(glm_MatrixType__doc__, "A matrix.");

static
PyTypeObject glm_MatrixType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm.Matrix",										/* tp_name */
	sizeof(glm_Matrix),								/* tp_basicsize */
	0,													/* tp_itemsize */
	0,													/* tp_dealloc */
	0,													/* tp_print */
	0,													/* tp_getattr */
	0,													/* tp_setattr */
	0,													/* tp_reserved */
	0,													/* tp_repr */
	0,													/* tp_as_number */
	0,													/* tp_as_sequence */
	0,													/* tp_as_mapping */
	0,													/* tp_hash  */
	0,													/* tp_call */
	0,													/* tp_str */
	PyObject_GenericGetAttr,							/* tp_getattro */
	PyObject_GenericSetAttr,							/* tp_setattro */
	0,													/* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	  Py_TPFLAGS_BASETYPE,								/* tp_flags */
	glm_MatrixType__doc__,								/* tp_doc */
	0,													/* tp_traverse */
	0,													/* tp_clear */
	0,													/* tp_richcompare */
	0,													/* tp_weaklistoffset */
	(getiterfunc)glm_Matrix_tp_iter,					/* tp_iter */
	0,													/* tp_iternext */
	0,													/* tp_methods */
	0,													/* tp_members */
	0,													/* tp_getset */
	0,													/* tp_base */
	0,													/* tp_dict */
	0,													/* tp_descr_get */
	0,													/* tp_descr_set */
	0,													/* tp_dictoffset */
	0,													/* tp_init */
	0,													/* tp_alloc */
	PyType_GenericNew,									/* tp_new */
};

/* * * Matrix Functions * * */

static
PyObject *glm_mat2_function_inverse(PyObject *self, PyObject *args) {
	
	glm::mat2 computed;
	PyObject *result;
	computed = glm::inverse(glm_mat2Data(self)
	);
	
	result = glm_mat2New(computed);
	
	return result;
}
static
PyObject *glm_mat3_function_inverse(PyObject *self, PyObject *args) {
	
	glm::mat3 computed;
	PyObject *result;
	computed = glm::inverse(glm_mat3Data(self)
	);
	
	result = glm_mat3New(computed);
	
	return result;
}
static
PyObject *glm_mat4_function_translate(PyObject *self, PyObject *args) {
	PyObject * argument0;
	
	if(!PyArg_ParseTuple(args, "O:translate"
	, &argument0
	))
		return NULL;
	
	if(1 != PyObject_IsInstance(argument0, (PyObject *)&glm_vec3Type)) {
		std::stringstream ss;
		ss << "Argument 1 must be of type 'glm.vec3' not '" << Py_TYPE(argument0)->tp_name << "'.";
		std::string s = ss.str();
		PyErr_SetString(PyExc_TypeError, s.c_str());
		return NULL;
	}
	
	glm::mat4 computed;
	PyObject *result;
	computed = glm::translate(glm_mat4Data(self)
	, glm_vec3Data(argument0)
	);
	
	result = glm_mat4New(computed);
	
	return result;
}
static
PyObject *glm_mat4_function_rotate(PyObject *self, PyObject *args) {
	float argument0;
	PyObject * argument1;
	
	if(!PyArg_ParseTuple(args, "fO:rotate"
	, &argument0
	, &argument1
	))
		return NULL;
	
	if(1 != PyObject_IsInstance(argument1, (PyObject *)&glm_vec3Type)) {
		std::stringstream ss;
		ss << "Argument 2 must be of type 'glm.vec3' not '" << Py_TYPE(argument1)->tp_name << "'.";
		std::string s = ss.str();
		PyErr_SetString(PyExc_TypeError, s.c_str());
		return NULL;
	}
	
	glm::mat4 computed;
	PyObject *result;
	computed = glm::rotate(glm_mat4Data(self)
	, argument0
	, glm_vec3Data(argument1)
	);
	
	result = glm_mat4New(computed);
	
	return result;
}
static
PyObject *glm_mat4_function_scale(PyObject *self, PyObject *args) {
	PyObject * argument0;
	
	if(!PyArg_ParseTuple(args, "O:scale"
	, &argument0
	))
		return NULL;
	
	if(1 != PyObject_IsInstance(argument0, (PyObject *)&glm_vec3Type)) {
		std::stringstream ss;
		ss << "Argument 1 must be of type 'glm.vec3' not '" << Py_TYPE(argument0)->tp_name << "'.";
		std::string s = ss.str();
		PyErr_SetString(PyExc_TypeError, s.c_str());
		return NULL;
	}
	
	glm::mat4 computed;
	PyObject *result;
	computed = glm::scale(glm_mat4Data(self)
	, glm_vec3Data(argument0)
	);
	
	result = glm_mat4New(computed);
	
	return result;
}
static
PyObject *glm_mat4_function_inverse(PyObject *self, PyObject *args) {
	
	glm::mat4 computed;
	PyObject *result;
	computed = glm::inverse(glm_mat4Data(self)
	);
	
	result = glm_mat4New(computed);
	
	return result;
}

/* * * Functions * * */

PyObject *glm_function_translate(PyObject *) {
	
	PyErr_SetString(PyExc_TypeError, "GLM functions only accept GLM types...or numbers.");
	return NULL;
}
PyObject *glm_function_rotate(PyObject *) {
	
	PyErr_SetString(PyExc_TypeError, "GLM functions only accept GLM types...or numbers.");
	return NULL;
}
PyObject *glm_function_scale(PyObject *) {
	
	PyErr_SetString(PyExc_TypeError, "GLM functions only accept GLM types...or numbers.");
	return NULL;
}
PyObject *glm_function_inverse(PyObject *) {
	
	PyErr_SetString(PyExc_TypeError, "GLM functions only accept GLM types...or numbers.");
	return NULL;
}

PyObject *glm_function_abs(PyObject *) {
	
	PyErr_SetString(PyExc_TypeError, "GLM functions only accept GLM types...or numbers.");
	return NULL;
}

PyObject *glm_function_ortho(PyObject *module, PyObject *args) {
	float a0;
	float a1;
	float a2;
	float a3;
	float a4;
	float a5;
	
	if(!PyArg_ParseTuple(args, "ffff|ff:ortho",
	&a0, 
	&a1, 
	&a2, 
	&a3, 
	&a4, 
	&a5
	))
		return NULL;
	
	PyObject *result = PyObject_CallObject((PyObject *)&glm_mat4Type, NULL);
	
	((glm_mat4 *)result)->mat = 
	glm::ortho<float>(
	a0, 
	a1, 
	a2, 
	a3, 
	a4, 
	a5
);
	
	return result;
}

PyObject *glm_function_frustum(PyObject *module, PyObject *args) {
	float a0;
	float a1;
	float a2;
	float a3;
	float a4;
	float a5;
	
	if(!PyArg_ParseTuple(args, "ffffff|:frustum",
	&a0, 
	&a1, 
	&a2, 
	&a3, 
	&a4, 
	&a5
	))
		return NULL;
	
	PyObject *result = PyObject_CallObject((PyObject *)&glm_mat4Type, NULL);
	
	((glm_mat4 *)result)->mat = 
	glm::frustum<float>(
	a0, 
	a1, 
	a2, 
	a3, 
	a4, 
	a5
);
	
	return result;
}

PyObject *glm_function_perspective(PyObject *module, PyObject *args) {
	float a0;
	float a1;
	float a2;
	float a3;
	
	if(!PyArg_ParseTuple(args, "ffff|:perspective",
	&a0, 
	&a1, 
	&a2, 
	&a3
	))
		return NULL;
	
	PyObject *result = PyObject_CallObject((PyObject *)&glm_mat4Type, NULL);
	
	((glm_mat4 *)result)->mat = 
	glm::perspective<float>(
	a0, 
	a1, 
	a2, 
	a3
);
	
	return result;
}

PyObject *glm_function_perspectiveFov(PyObject *module, PyObject *args) {
	float a0;
	float a1;
	float a2;
	float a3;
	float a4;
	
	if(!PyArg_ParseTuple(args, "fffff|:perspectiveFov",
	&a0, 
	&a1, 
	&a2, 
	&a3, 
	&a4
	))
		return NULL;
	
	PyObject *result = PyObject_CallObject((PyObject *)&glm_mat4Type, NULL);
	
	((glm_mat4 *)result)->mat = 
	glm::perspectiveFov<float>(
	a0, 
	a1, 
	a2, 
	a3, 
	a4
);
	
	return result;
}


/* * * GLM Module * * */

PyDoc_STRVAR(glm_function_abs__doc__, "Absolute value.");

PyDoc_STRVAR(glm_function_translate__doc__, "Translates a 4x4 matrix.");
PyDoc_STRVAR(glm_function_rotate__doc__, "Rotates a 4x4 matrix.");
PyDoc_STRVAR(glm_function_scale__doc__, "Scales a 4x4 matrix.");
PyDoc_STRVAR(glm_function_inverse__doc__, "Matrix's inverse.");

PyDoc_STRVAR(glm_function_ortho__doc__, "Creates an orthographic matrix.");
PyDoc_STRVAR(glm_function_frustum__doc__, "Creates a frustum matrix.");
PyDoc_STRVAR(glm_function_perspective__doc__, "Creates a perspective matrix.");
PyDoc_STRVAR(glm_function_perspectiveFov__doc__, "Creates a perspective matrix with a defined FOV.");

static
PyMethodDef glmmodule_methods[] = {
	{"abs", (PyCFunction) glm_function_abs, METH_O, glm_function_abs__doc__},
	{"translate", (PyCFunction) glm_function_translate, METH_VARARGS, glm_function_translate__doc__},
	{"rotate", (PyCFunction) glm_function_rotate, METH_VARARGS, glm_function_rotate__doc__},
	{"scale", (PyCFunction) glm_function_scale, METH_VARARGS, glm_function_scale__doc__},
	{"inverse", (PyCFunction) glm_function_inverse, METH_VARARGS, glm_function_inverse__doc__},
	{"ortho", (PyCFunction) glm_function_ortho, METH_VARARGS, glm_function_ortho__doc__},
	{"frustum", (PyCFunction) glm_function_frustum, METH_VARARGS, glm_function_frustum__doc__},
	{"perspective", (PyCFunction) glm_function_perspective, METH_VARARGS, glm_function_perspective__doc__},
	{"perspectiveFov", (PyCFunction) glm_function_perspectiveFov, METH_VARARGS, glm_function_perspectiveFov__doc__},
	{NULL, NULL},
};

PyDoc_STRVAR(glmmodule__doc__, "GLSL Mathematics.");

static
PyModuleDef glmmodule = {
	PyModuleDef_HEAD_INIT,
	"glm",
	glmmodule__doc__,
	-1,
	glmmodule_methods,
};

extern "C"
PyMODINIT_FUNC
PyInit_glm()
{
	/* Ready Bases */
	PyType_Ready(&glm_VectorIteratorType);
	PyType_Ready(&glm_VectorType);
	PyType_Ready(&glm_MatrixIteratorType);
	PyType_Ready(&glm_MatrixType);
	
	/* Ready Matrices */
	glm_mat2Type.tp_base = &glm_MatrixType;
	PyType_Ready(&glm_mat2Type);
	glm_mat3x2Type.tp_base = &glm_MatrixType;
	PyType_Ready(&glm_mat3x2Type);
	glm_mat4x2Type.tp_base = &glm_MatrixType;
	PyType_Ready(&glm_mat4x2Type);
	glm_mat2x3Type.tp_base = &glm_MatrixType;
	PyType_Ready(&glm_mat2x3Type);
	glm_mat3Type.tp_base = &glm_MatrixType;
	PyType_Ready(&glm_mat3Type);
	glm_mat4x3Type.tp_base = &glm_MatrixType;
	PyType_Ready(&glm_mat4x3Type);
	glm_mat2x4Type.tp_base = &glm_MatrixType;
	PyType_Ready(&glm_mat2x4Type);
	glm_mat3x4Type.tp_base = &glm_MatrixType;
	PyType_Ready(&glm_mat3x4Type);
	glm_mat4Type.tp_base = &glm_MatrixType;
	PyType_Ready(&glm_mat4Type);
	
	/* Ready Vectors */
	glm_vec2Type.tp_base = &glm_VectorType;
	PyType_Ready(&glm_vec2Type);
	glm_vec3Type.tp_base = &glm_VectorType;
	PyType_Ready(&glm_vec3Type);
	glm_vec4Type.tp_base = &glm_VectorType;
	PyType_Ready(&glm_vec4Type);
	glm_ivec2Type.tp_base = &glm_VectorType;
	PyType_Ready(&glm_ivec2Type);
	glm_ivec3Type.tp_base = &glm_VectorType;
	PyType_Ready(&glm_ivec3Type);
	glm_ivec4Type.tp_base = &glm_VectorType;
	PyType_Ready(&glm_ivec4Type);
	
	PyObject* m;

	m = PyModule_Create(&glmmodule);
	
	if(m == NULL)
		return NULL;
	
	/* Add types to module */
	Py_INCREF(&glm_VectorIteratorType);
	Py_INCREF(&glm_VectorType);
	Py_INCREF(&glm_MatrixIteratorType);
	Py_INCREF(&glm_MatrixType);
	Py_INCREF(&glm_mat2Type);
	Py_INCREF(&glm_mat3x2Type);
	Py_INCREF(&glm_mat4x2Type);
	Py_INCREF(&glm_mat2x3Type);
	Py_INCREF(&glm_mat3Type);
	Py_INCREF(&glm_mat4x3Type);
	Py_INCREF(&glm_mat2x4Type);
	Py_INCREF(&glm_mat3x4Type);
	Py_INCREF(&glm_mat4Type);
	Py_INCREF(&glm_vec2Type);
	Py_INCREF(&glm_vec3Type);
	Py_INCREF(&glm_vec4Type);
	Py_INCREF(&glm_ivec2Type);
	Py_INCREF(&glm_ivec3Type);
	Py_INCREF(&glm_ivec4Type);
	PyModule_AddObject(m, "VectorIterator", (PyObject *) &glm_VectorIteratorType);
	PyModule_AddObject(m, "Vector", (PyObject *) &glm_VectorType);
	PyModule_AddObject(m, "MatrixIterator", (PyObject *) &glm_MatrixIteratorType);
	PyModule_AddObject(m, "Matrix", (PyObject *) &glm_MatrixType);
	PyModule_AddObject(m, "mat2", (PyObject *) &glm_mat2Type);
	PyModule_AddObject(m, "mat3x2", (PyObject *) &glm_mat3x2Type);
	PyModule_AddObject(m, "mat4x2", (PyObject *) &glm_mat4x2Type);
	PyModule_AddObject(m, "mat2x3", (PyObject *) &glm_mat2x3Type);
	PyModule_AddObject(m, "mat3", (PyObject *) &glm_mat3Type);
	PyModule_AddObject(m, "mat4x3", (PyObject *) &glm_mat4x3Type);
	PyModule_AddObject(m, "mat2x4", (PyObject *) &glm_mat2x4Type);
	PyModule_AddObject(m, "mat3x4", (PyObject *) &glm_mat3x4Type);
	PyModule_AddObject(m, "mat4", (PyObject *) &glm_mat4Type);
	PyModule_AddObject(m, "vec2", (PyObject *) &glm_vec2Type);
	PyModule_AddObject(m, "vec3", (PyObject *) &glm_vec3Type);
	PyModule_AddObject(m, "vec4", (PyObject *) &glm_vec4Type);
	PyModule_AddObject(m, "ivec2", (PyObject *) &glm_ivec2Type);
	PyModule_AddObject(m, "ivec3", (PyObject *) &glm_ivec3Type);
	PyModule_AddObject(m, "ivec4", (PyObject *) &glm_ivec4Type);
	
	return m;
}
