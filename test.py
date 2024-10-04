#! /usr/bin/env python3

import vector2py

vec1 = vector2py.Vector3D(1, 2, 3)
print(f"Vector vec1:")
vec1.print()

print(f"Vector(vec1) length: {vec1.length()}")

vec1.normalization()

print(f"Vector(vec1) after normalization:")

vec1.print()

vec2 = vector2py.Vector3D(1, 2, 3)
vec3 = vector2py.Vector3D(2, 5, 6)

print(f"Vector vec2:")
vec2.print()
print(f"Vector vec3:")
vec3.print()

print(f"Vector addition vec2 + vec3:")
vec4 = vector2py.addition(vec2, vec3)
print(f"Vector vec4:")
vec4.print()

print(f"Vector substraction vec4 - vec3:")
vec5 = vector2py.substraction(vec4, vec3)
print(f"Vector vec5:")
vec5.print()

print(f"Scalar product of vectors vec4 and vec3: {vector2py.scalarProd(vec4, vec3)}")



