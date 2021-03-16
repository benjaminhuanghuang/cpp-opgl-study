
## Vector vs Scalar
A vector is a quantity that has a `magnitude` and a `direction`. 
For example: displacement, velocity, acceleration and force.

In a 3D coordinate system, a vector is specified by the coordinates with respect to the coordinate system.

Vector magnitude = sqr(x^2 + y^2 + z^2)

Unit Vector / Normalized vectors
In some cases, we don't care about the magnitude of the vector, we just want to know the
direction of the vector.

In unit vectors, the X, Y, and Z components of the vector are divided by the magnitude to
create a vector of unit length.

![](./_images/unit-vector.png)

## 向量与标量运算
## Dot Product
点乘是通过将对应分量逐个相乘，然后再把所得积相加来计算

两个向量的点乘 = 它们的数乘结果乘以两个向量之间夹角的余弦值

两个单位向量的点乘 = 它们的数乘结果乘以两个向量之间夹角的余弦值

90度的余弦值是0，0度的余弦值是1
使用点乘可以很容易测试两个向量是否正交(Orthogonal)或平行

两个向量的夹角。点乘会在计算光照的时候非常有用。

![](./_images/dot-product.png)


### Cross Product

叉乘只在3D空间中有定义，它需要两个不平行向量作为输入，生成一个正交于两个输入向量的第三个向量

![](./_images/cross-product.png)

![](./_images/cross-product2.png)
