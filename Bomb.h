#include "Libraries.h"
#include "Animation.h"
#include "Rectangle.h"
#include "Objects.h"
#include "Tile.h"
#include "Link.h"
#include <iostream>
class Bomb
	: public Objects
	, public Sprite

{
public:
	Bomb();
	~Bomb();
	bool TouchesBomb();
	void Update();
	void SetBox(int x, int y) { box.x = x, box.y = y; }
	void Clear();
	void Show();
	void Move();
	static const int BOMB_WIDTH = 5;
	static const int BOMB_HEIGTH = 5;
	Rectangle rec1;
	Rectangle rec2;
	Rectangle rec3;
	Bomb* Bombe;
	Bomb* Smog;
	
	int bombX, bombY;
	bool Visible;

private:
	
	int width, heigth;
	float SmogX, SmogY;
	float currentTime;
	int framerate;
	bool isPlaying;
	bool islooping;
	SDL_Rect box;
	const int domage = 3;
	bool isCollect;


	const int SMOG_NB_FRAME() { return 2; }
	const point<int> SMOG_NB_POSITION(){ return{ 80, 32 }; }
	const point <int> FRAME_SIZE(){ return{ 16, 16 }; }





};


