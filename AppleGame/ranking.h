#ifndef RANKING_H
#define RANKING_H
#define RANKING_DATA 5

//�\����
struct RankingData{
	int		no;
	char	name[11];
	long	score;
};

//�ϐ��錾
extern struct RankingData		gRanking[RANKING_DATA];

#endif