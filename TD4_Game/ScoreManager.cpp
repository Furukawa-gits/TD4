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
	elpsedTime = 0;
	scorePrintFlag = false;
	scorePos = { 0,0 };

	//���݂̎��Ԃ��Z�b�g
	beginTime = time(NULL);

	FirstNumSet();

	for (int i = 0; i < reviewNum.size(); i++)
	{
		oldReview += reviewNum[i];
	}

	totalReview = oldReview / reviewNum.size();

	spriteScore.CreateAndSetDivisionUVOffsets(10, 10, 1, 64, 64, TexManager::LoadTexture("Resources/Score.png"));
}

void ScoreManager::Update(Head *heads, CheraType cheraType, ItemType itemType)
{
	if (heads->isAllMoveFinish)
	{
		//�o�ߎ��Ԃ��v��
		endTime = time(NULL);
		elpsedTime = difftime(endTime, beginTime);

		//���Ԃɂ���ă��r���[�𑝌�
		if (elpsedTime >= 5)
		{
			reduceReview = 5;
		}
		else if (elpsedTime >= 4)
		{
			reduceReview = 4;
		}
		else if (elpsedTime >= 3)
		{
			reduceReview = 3;
		}
		else if (elpsedTime >= 2)
		{
			reduceReview = 2;
		}
		else if (elpsedTime >= 1)
		{
			reduceReview = 1;
		}
		else
		{
			//�����I���o�����Ƃ��������r���[�����炷
			reduceReview = -1;
		}

		if (cheraType == CheraType::SkinHead)
		{
			//�ň��Ȃ��Ƃ������Ƃ�
			if (itemType == ItemType::Hand)
			{
				//��b���r���[
				skinheadReview = DEFO_HAGEHEAD_REVIEW - BAD_ACTION;
				//�o�ߎ��ԕ����܂߂�
				skinheadReview += reduceReview;
				if (skinheadReview > 5)
				{
					skinheadReview = 5;
				}
				reviewNum.push_back(skinheadReview);
			}
			//�����Ă��邱�Ƃ������Ƃ�
			if (itemType == ItemType::Clippers || itemType == ItemType::Scissors)
			{
				//��b���r���[
				skinheadReview = DEFO_HAGEHEAD_REVIEW + GOOD_ACTION;
				//�o�ߎ��ԕ����܂߂�
				skinheadReview += reduceReview;
				if (skinheadReview > 5)
				{
					skinheadReview = 5;
				}
				reviewNum.push_back(skinheadReview);
			}

			oldReview += reviewNum[reviewNum.size() - 1];
		}
		if (cheraType == CheraType::Thinning)
		{
			//�ň��Ȃ��Ƃ������Ƃ�
			if (itemType == ItemType::Scissors)
			{
				//��b���r���[
				thinningReview = DEFO_LIGHTHEAD_REVIEW - BAD_ACTION;
				//�o�ߎ��ԕ����܂߂�
				thinningReview += reduceReview;
				if (thinningReview > 5)
				{
					thinningReview = 5;
				}
				reviewNum.push_back(thinningReview);
			}
			//�����Ă��邱�Ƃ������Ƃ�
			if (itemType == ItemType::Hand || itemType == ItemType::Clippers)
			{
				//��b���r���[
				thinningReview = DEFO_LIGHTHEAD_REVIEW + GOOD_ACTION;
				//�o�ߎ��ԕ����܂߂�
				thinningReview += reduceReview;
				if (thinningReview > 5)
				{
					thinningReview = 5;
				}
				reviewNum.push_back(thinningReview);
			}

			oldReview += reviewNum[reviewNum.size() - 1];
		}
		if (cheraType == CheraType::Afro)
		{
			//�ň��Ȃ��Ƃ������Ƃ�
			if (itemType == ItemType::Clippers)
			{
				//��b���r���[
				afroheadReview = DEFO_AFROHEAD_REVIEW - BAD_ACTION;
				//�o�ߎ��ԕ����܂߂�
				afroheadReview += reduceReview;
				if (afroheadReview > 5)
				{
					afroheadReview = 5;
				}
				reviewNum.push_back(afroheadReview);
			}
			//�����Ă��邱�Ƃ������Ƃ�
			if (itemType == ItemType::Hand || itemType == ItemType::Scissors)
			{
				//��b���r���[
				afroheadReview = DEFO_AFROHEAD_REVIEW + GOOD_ACTION;
				//�o�ߎ��ԕ����܂߂�
				afroheadReview += reduceReview;
				if (afroheadReview > 5)
				{
					afroheadReview = 5;
				}
				reviewNum.push_back(afroheadReview);
			}

			oldReview += reviewNum[reviewNum.size() - 1];
		}
		//���̐l�̌v�����n�߂�
		beginTime = time(NULL);


		//���r���[�̌v�Z
		totalReview = oldReview / reviewNum.size();

		//�X�R�A�̌v�Z
		scoreNum.push_back(DEFO_SCORE * (MAX_REVIEW - totalReview));
		scorePrintFlag = true;
		totalScore += scoreNum[scoreNum.size() - 1];
	}
	if (scorePrintFlag == true)
	{
		scorePos.y--;

	}
}

void ScoreManager::Draw()
{
	float drawScore = 128;
	
	spriteScore.uvOffsetHandle = (int)drawScore / 100;
	spriteScore.DrawExtendSprite(1280.f - 192.f, 720.f - 64.f, 1280.0f - 128.f, 720.f);
	spriteScore.uvOffsetHandle = ((int)drawScore / 10) % 10;
	spriteScore.DrawExtendSprite(1280.f - 128.f, 720.f - 64.f, 1280.0f - 64.f, 720.f);
	spriteScore.uvOffsetHandle = (int)drawScore % 10;
	spriteScore.DrawExtendSprite(1280.f - 64.f, 720.f - 64.f, 1280.0f - 0.f, 720.f);
	spriteScore.Draw();
	//spriteReview.Draw();
}
