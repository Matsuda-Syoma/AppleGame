#pragma once

int playSE = 0;

extern struct RankingData {
	int		no;
	char	name[11];
	long	score;
};

extern struct RankingData		gRanking[RANKING_DATA];