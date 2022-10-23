# GreedySnake

̰������Ŀ������C++�ļ�С��Ŀ

## component�����

### Food

### Map

```c++
��ͼ����ӿ�
void PrintInitMap();
```

### Point

### Snake

## controller���Ʋ�

```c++
static void Start();//��Ϸ�Ŀ�ʼ����ļ���

void Select();//ѡ����Ϸ�Ѷ�

void DrawGame() const;//������Ϸ��ͼ�Ͳ˵�����

int PlayGame();

void UpdateScore(const int &tmp);

void RewriteScore() const;

static int Menu();

void Game();//��Ϸ����ڣ����ؿ�ʼ������������Ϸ

int GameOver() const;//��Ϸ����
```

## startinterface��ʼ�����

```c++
��ʼ���涯��������
void Action();����ӿ�
```

## utils���߲�

```c++
void SetWindowSize(int cols, int lines);//���ô��ڱ��⡢��С

void SetCursorPosition(int x, int y);//���ù��λ��

void SetColor(int colorID);//�����ı���ɫ

void SetBackColor();//�����ı���ɫ�ͱ�����ɫ

void SetCursorNoVisible();//���ù�겻�ɼ�
```

## main.cpp����������

```c++
���ÿ��Ʋ����ӿ�
void Game();
```
