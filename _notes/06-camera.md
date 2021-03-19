
Camera/View Space是以摄像机的视角作为场景原点时场景中所有的顶点坐标
View Matrix 把所有的世界坐标变换为相对于摄像机位置与方向的观察坐标。要定义一个摄像机，我们需要它在世界空间中的位置、观察的方向、一个指向它右测的向量以及一个指向它上方的向量。


缺省下实际上创建了一个三个单位轴相互垂直的、以摄像机的位置为原点的坐标系。


## Camera position
摄像机位置简单来说就是世界空间中一个指向摄像机位置的向量
```
  glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
```


## 摄像机方向
```
  glm::vec3 cameraTarget = glm::vec3(0.0f, 0.0f, 0.0f);

  glm::vec3 cameraDirection = glm::normalize(cameraPos - cameraTarget);
```
方向向量(Direction Vector)并不是最好的名字，因为它实际上指向从它到目标向量的相反方向

## 右向量(Right Vector)摄像机空间的x轴的正方向

为获取右向量我们需要先使用一个小技巧：先定义一个上向量(Up Vector)。接下来把上向量和第二步得到的方向向量进行叉乘。两个向量叉乘的结果会同时垂直于两向量，因此我们会得到指向x轴正方向的那个向量（如果我们交换两个向量叉乘的顺序就会得到相反的指向x轴负方向的向量）：
```
glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f); 
glm::vec3 cameraRight = glm::normalize(glm::cross(up, cameraDirection));
```

## 欧拉角(Euler Angles)
被定义为偏航角(Yaw)，俯仰角(Pitch)，和滚转角(Roll)从而允许我们通过这三个值构造任何3D方向。