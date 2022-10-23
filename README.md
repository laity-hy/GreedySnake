# GreedySnake

贪吃蛇项目，基于C++的简单小项目

## component组件层

### Food

### Map

```c++
地图对外接口
void PrintInitMap();
```

### Point

### Snake

## controller控制层

### Controller

## startinterface开始界面层

```c++
开始界面动画的设置
void Action();对外接口
```

## utils工具层

```c++
void SetWindowSize(int cols, int lines);//设置窗口标题、大小

void SetCursorPosition(int x, int y);//设置光标位置

void SetColor(int colorID);//设置文本颜色

void SetBackColor();//设置文本颜色和背景颜色

void SetCursorNoVisible();//设置光标不可见
```

## main.cpp主程序的入口

```c++
调用控制层对外接口
void Game();
```
