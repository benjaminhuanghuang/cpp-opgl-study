
http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/

usemtl and mtllib describe the look of the model. We won’t use this in this tutorial.

- v is a vertex
- vt is the texture coordinate of one vertex
- vn is the normal of one vertex
- f is a face

for f 8/11/7 7/12/7 6/10/7 

8/11/7 describes the first vertex of the triangle
7/12/7 describes the second vertex of the triangle
6/10/7 describes the third vertex of the triangle (duh)

For the first vertex, 8 says which vertex to use. 
So in this case, v(8) -1.000000 1.000000 -1.000000 (index start to 1, not to 0 like in C++)

11 says which texture coordinate to use. So in this case, 0.748355 0.998230

7 says which normal to use. So in this case, 0.000000 1.000000 -0.000000