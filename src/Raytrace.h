/* All needed structs and functions for interacting with 3D objects in a 
 *     raytracer.
 * CS430
 * Chance Nelson
 */

#ifndef H_RAYTRACERMATH
#define H_RAYTRACERMATH

#include <stdlib.h>
#include <math.h>

// Struct for holding color RGB values
typedef struct {
    double r, g, b;
} Color;

// Struct for holding two XYZ values for a ray
typedef struct {
    double x0, y0, z0;
    double x1, y1, z1;
} Ray;

// Struct for holding a vector
typedef struct {
    double x, y, z;
} Vector;

// Struct for holding all needed data for 3D objects
typedef struct {
    // ID number of the entity.
    // 0: camera
    // 1: sphere
    // 2: plane
    int id;
    double x, y, z;  // Position of entity in 3D space

    // Special attributes for each type of entity. Unioned to save space
    union {
        Vector normal;          // For planes
        double radius;          // For spheres
        double dimensions[2];   // For cameras
    } attributes;

    Color color;  // Color of the object
} Entity;

double dot_product(Vector a, Vector b);                                              // Vector dot product
Vector vector_sub(Vector a, Vector b);                                               // Vector subtraction
double* check_intersect(Ray v, Entity entity);                                       // Check ray intersect
Color shoot(Ray v, Entity *entities, Color backgrounf, int entitiesLen, int phong);  // Shoot ray into scene of entities

#endif
