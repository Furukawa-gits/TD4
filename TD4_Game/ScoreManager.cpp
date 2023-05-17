#include "ScoreManager.h"
float ScoreManager::totalScore = 0;
float ScoreManager::totalReview = 0;

void ScoreManager::FirstNumSet()
{
	for (int i = 0; i < FIRST_NUM_MAX; i++)
	{
		reviewNum.push_back(5);
	}
	for (int i = 0; i < FIRST_NUM_MAX; i++)
	{
		reviewNum.push_back(4);
	}
}

void ScoreManager::Initialize()
{
	totalReview = 0;
	oldReview = 0;
	totalScore = 0;

	FirstNumSet();

	for (int i = 0; i < reviewNum.size(); i++)
	{
		oldReview += reviewNum[i];
	}

	totalReview = oldReview / reviewNum.size();
}

void ScoreManager::Update(Head *heads, CheraType cheraType)
{
	if (heads->isAllMoveFinish)
	{
		if (cheraType == CheraType::SkinHead)
		{
			//�ň��Ȃ��Ƃ������Ƃ�
			//if()
			reviewNum.push_back(2);
			//�����Ă��邱�Ƃ������Ƃ�
			//if()
			reviewNum.push_back(SKINHEAD_SCORE_NUM);

			oldReview += reviewNum[reviewNum.size() - 1];
		}
		if (cheraType == CheraType::Thinning)
		{
			//�ň��Ȃ��Ƃ������Ƃ�
			//if()
			reviewNum.push_back(2);
			//�����Ă��邱�Ƃ������Ƃ�
			//if()
			reviewNum.push_back(THINNING_SCORE_NUM);

			oldReview += reviewNum[reviewNum.size() - 1];
		}
		if (cheraType == CheraType::Afro)
		{
			//�ň��Ȃ��Ƃ������Ƃ�
			//if()
			reviewNum.push_back(2);
			//�����Ă��邱�Ƃ������Ƃ�
			//if()
			reviewNum.push_back(AFROHEAD_SCORE_NUM);

			oldReview += reviewNum[reviewNum.size() - 1];
		}
		//���r���[�̌v�Z
		totalReview = oldReview / reviewNum.size();

		//�X�R�A�̌v�Z
		totalScore += DEFO_SCORE * (MAX_REVIEW - totalReview);
	}
}
