
## 顶点着色器是
sets a vertex's coordinate position in 3D space origin location : (0,0,0)
内置变量gl_Position用来设置顶点在3D空间的坐标位置，并发送至下一个管线阶段。
GLSL数据类型vec4用来存储4元组，适合用来存储坐标，4元组的前3个值分别表示X、Y、Z，第4个值在这里设为1.0
```
#version 410
void main(void)
{
  gl_Position = vec4(0.0, 0.0, 0.0, 1.0);
}
```

## 光栅着色器
在本例中所指定的输出颜色值(0,0,1)是蓝色（第4个值1.0是不透明度）。

注意这里的“out”标签表明color变量是输出变量。

在顶点着色器中并不是必须给gl_Position指定“out”标签，因为gl_Position是预定义的输出变量。
```
#version 410
out vec4 color;
void main(void)
{
  color = vec4(0.0, 0.0, 1.0, 1.0);
}
```


## 片段着色器
gl_FragCoord访问输入片段的坐标

渲染的点的像素颜色将会以坐标变化——X坐标小于200时是红色，否则就是蓝色
```
  #version 430
  out vec4 color;
  void main(void)
  { if (gl_FragCoord.x < 200) color = vec4(1.0, 0.0, 0.0, 1.0); else color = vec4(0.0, 0.0, 1.0, 1.0);
  }
```