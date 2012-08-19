# Installing

After cloning glm from <https://github.com/Groovounet/glm> cd to the glm direcory and clone this repository.

To use the header file for the C-API, move the parsed python.hpp into the main glm include dir.  For a global glm install it should look like:

```c++
#include <glm/python.hpp>
```

The source relies on Parseme being installed.  Get it here:
https://github.com/Queatz/Parseme

Do `dir(glm)` to see a list of supported types and function.

# Basic Usage

```python
>>> import glm
>>> a = glm.vec3()
>>> a
glm.vec3(0, 0, 0)
>>> a.brg = .3, 1, .5
>>> a
glm.vec3(1, 0.5, 0.3)
>>> b = glm.vec4(.7, a)
>>> b
glm.vec4(0.7, 1, 0.5, 0.3)
>>> c = b.yz
>>> c
glm.vec2(1, 0.5)
>>> c / glm.vec2(2, .5)
glm.vec2(0.5, 1)
>>> 
```
