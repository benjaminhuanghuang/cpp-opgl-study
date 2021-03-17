```
public void update() {
  temp += 0.02;
  position.setX((float) Math.sin(temp));
  rotation.set((float) Math.sin(temp) * 360, (float) Math.sin(temp) * 360, (float) Math.sin(temp) * 360);
  scale.set((float) Math.sin(temp), (float) Math.sin(temp), (float) Math.sin(temp));
}
```