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

```c++
static void Start();//游戏的开始界面的加载

void Select();//选择游戏难度

void DrawGame() const;//绘制游戏地图和菜单界面

int PlayGame();

void UpdateScore(const int &tmp);

void RewriteScore() const;

static int Menu();

void Game();//游戏的入口，加载开始动画，加载游戏

int GameOver() const;//游戏结束
```

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
