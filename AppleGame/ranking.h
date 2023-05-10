#ifndef RANKING_H
#define RANKING_H
#define RANKING_DATA 5

//\‘¢‘Ì
struct RankingData{
	int		no;
	char	name[11];
	long	score;
};

//•Ï”éŒ¾
extern struct RankingData		gRanking[RANKING_DATA];

#endif