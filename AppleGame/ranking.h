#ifndef RANKING_H
#define RANKING_H
#define RANKING_DATA 5

//構造体
struct RankingData{
	int		no;
	char	name[11];
	long	score;
};

//変数宣言
extern struct RankingData		gRanking[RANKING_DATA];

#endif