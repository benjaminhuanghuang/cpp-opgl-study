
## A x B

只有当左侧矩阵的列数与右侧矩阵的行数相等，两个矩阵才能相乘。
矩阵相乘不遵守交换律(Commutative) A⋅B≠B⋅A


## Identity matrix E
单位矩阵的身份和自然数”1”一样基础而重要，A x E = A

```
  glm::mat4 myIdentityMatrix = glm::mat4(1.0);
```
单位矩阵只是缩放矩阵的一个特例，其(X, Y, Z) = (1, 1, 1)。

单位矩阵同时也是旋转矩阵的一个特例，其(X, Y, Z)=(0, 0, 0)）。


## Matrix transpose
![](./_images/matrix-transpose.png)


## 缩放(Scaling)
对一个向量进行缩放(Scaling)就是对向量的长度进行缩放，而保持它的方向不变


## 位移 (Translation)

是在原始向量的基础上加上另一个向量从而获得一个在不同位置的新向量的过程

对于位移来说它们是第四列最上面的3个值
![](./_images/translation-matrix.png)


## 齐次坐标(Homogeneous Coordinates)
如果一个向量的齐次坐标是0，这个坐标就是方向向量(Direction Vector)，因为w坐标是0，这个向量就不能位移


## 旋转(Rotation)
![](./_images/rotation-matrix.png)



## 矩阵的组合
根据矩阵之间的乘法，可以把多个变换组合到一个矩阵中

假设有一个顶点(x, y, z)，将其缩放2倍，然后位移(1, 2, 3)个单位。需要一个位移和缩放矩阵来完成这些变换：

![](./_images/trans-scale.png)

当矩阵相乘时，在最右边的矩阵是第一个与向量相乘的，所以应该从右向左读这个乘法。

在组合矩阵时，先进行缩放操作，然后是旋转，最后才是位移，否则它们会（消极地）互相影响。比如，如果先位移再缩放，位移的向量也会同样被缩放

```
  TransformedVector = TranslationMatrix * RotationMatrix * ScaleMatrix * OriginalVector;
```
注意！！！这行代码首先执行缩放，接着旋转，最后才是平移

假设有个船的模型（为简化，略去旋转）：

错误做法：

- 按(10, 0, 0)平移船体。船体中心目前距离原点10个单位。
- 将船体放大2倍。以原点为参照，每个坐标都变成原来的2倍，就出问题了。最后您得到的是一艘放大的船，但其中心位于2*10=20。It's wrong

正确做法：
- 将船体放大2倍，得到一艘中心位于原点的大船。
- 平移船体。船大小不变，移动距离也正确。


用C++，GLM表示：
```
glm::mat4 myModelMatrix = myTranslationMatrix * myRotationMatrix * myScaleMatrix;
glm::vec4 myTransformedVector = myModelMatrix * myOriginalVector;
```

用GLSL表示：
```
mat4 transform = mat2 * mat1;
vec4 out_vec = transform * in_vec;
```



## Projection / Orthogonal Matrix
- [Projection Matrices in OpenGL](https://www.youtube.com/watch?v=xZs6K7VLM7A&ab_channel=TheCherno)
- [OpenGL中投影矩阵(Projection Matrix)详解]

![](./_images/orthographic-matrix.png)



## Normalized Device Coodination(NDC)
the x, y and z values vary from -1.0 to 1.0


## Normal (法线/法向量)
In geometry, a normal is an object such as a line, ray, or vector that is `perpendicular` to a given object.



## 齐次坐标（Homogeneous coordinates）
齐次坐标使得我们可以用同一个公式对点和方向作运算。

若w==1，则向量(x, y, z, 1)为空间中的点。
若w==0，则向量(x, y, z, 0)为方向。


##变换矩阵（Transformation matrices）
矩阵 x 顶点（记住顺序！！矩阵左乘顶点，顶点用列向量表示）= 变换后的顶点

![](MatrixXVect.gif)

用C++，GLM表示：
```
glm::mat4 myMatrix;
glm::vec4 myVector;
// fill myMatrix and myVector somehow
glm::vec4 transformedVector = myMatrix * myVector; // Again, in this order ! this is important.
```

用GLSL表示：
```
mat4 myMatrix;
vec4 myVector;
// fill myMatrix and myVector somehow
vec4 transformedVector = myMatrix * myVector; // Yeah, it's pretty much the same than GLM
```
## 平移矩阵（Translation matrices）
![](translationMatrix.png)

用C++，GLM表示：
```
#include <glm/gtx/transform.hpp> // after <glm/glm.hpp>

glm::mat4 myMatrix = glm::translate(glm::mat4(), glm::vec3(10.0f, 0.0f, 0.0f));
glm::vec4 myVector(10.0f, 10.0f, 10.0f, 0.0f);
glm::vec4 transformedVector = myMatrix * myVector; // guess the result
```
用GLSL表示
实际中我们几乎不用GLSL计算变换矩阵。大多数情况下在C++代码中用glm::translate()算出矩阵，然后把它传给GLSL。在GLSL中只做一次乘法：
```
vec4 transformedVector = myMatrix * myVector;
```

## 缩放矩阵（Scaling matrices）
![](scalingMatrix.png)

## 旋转矩阵（Rotation matrices）
```
#include <glm/gtc/matrix_transform.hpp> and #include <glm/gtx/transform.hpp>

glm::vec3 myRotationAxis( ??, ??, ??);
glm::rotate( angle_in_degrees, myRotationAxis );
```


## 累积变换


## 投影矩阵（projectionMatrix）
```
// Generates a really hard-to-read matrix, but a normal, standard 4x4 matrix nonetheless
glm::mat4 projectionMatrix = glm::perspective(
    glm::radians(FoV), // The vertical Field of View, in radians: the amount of "zoom". Think "camera lens". Usually between 90&deg; (extra wide) and 30&deg; (quite zoomed in)
    4.0f / 3.0f,       // Aspect Ratio. Depends on the size of your window. Notice that 4/3 == 800/600 == 1280/960, sounds familiar ?
    0.1f,              // Near clipping plane. Keep as big as possible, or you'll get precision issues.
    100.0f             // Far clipping plane. Keep as little as possible.
);
```