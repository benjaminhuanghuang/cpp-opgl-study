

##
我们将这两个颜色向量作分量相乘，结果就是最终的颜色向量了：
```
  glm::vec3 lightColor(1.0f, 1.0f, 1.0f);
  glm::vec3 toyColor(1.0f, 0.5f, 0.31f);
  glm::vec3 result = lightColor * toyColor; // = (1.0f, 0.5f, 0.31f);
```