#pragma once

struct APPLE gApple[APPLE_MAX];
struct APPLE gApple00 = { true,0,0,0,10,110,110,0,1 };
float gAppleSpeed[4] = { 1.0f,2.0f,3.5f,0.5f };
int gAppleScore[4] = { 100,200,500,-750 };
int AppleTime;		//��񂲂̐����^�C�~���O
int rnd;
int OldAppleSpawn;
int NewAppleSpawn;

