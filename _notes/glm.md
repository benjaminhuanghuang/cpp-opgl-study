# GLM (OpenGL Mathematics)
GLM是一个只有头文件的库，https://glm.g-truc.net/0.9.9/index.html

```
  #include <glm/glm.hpp>
  #include <glm/gtc/matrix_transform.hpp>
  #include <glm/gtc/type_ptr.hpp>
```
GLM库从0.9.9版本起，默认会将矩阵类型初始化为一个零矩阵（所有元素均为0），而不是单位矩阵。



translate
```
  glm::vec4 vec(1.0f, 0.0f, 0.0f, 1.0f);
  // 0.9.9下面这行代码就需要改为:
  // glm::mat4 trans = glm::mat4(1.0f)
  glm::mat4 trans;

  // create tranform matrix
  trans = glm::translate(trans, glm::vec3(1.0f, 1.0f, 0.0f));


  vec = trans * vec;
  std::cout << vec.x << vec.y << vec.z << std::endl;
```