#pragma once
#include<time.h>
#include<Sprite.h>

#include"Head.h"

class ScoreManager
{
private:
	//�ŏ���10�[���v�Z����p
	static const int FIRST_NUM_MAX = 10;
	//�ő僌�r���[
	static const int MAX_REVIEW = 5;
	//�͂��̊�{���r���[
	static const int DEFO_HAGEHEAD_REVIEW = 3;
	//��{�͂��̊�{���r���[
	static const int DEFO_LIGHTHEAD_REVIEW = 3;
	//�A�t���̊�{���r���[
	static const int DEFO_AFROHEAD_REVIEW = 3;
	//�����I���i�Q�[���I�ɂ͈����I���j(��{���r���[�ɑ����l)
	static const int GOOD_ACTION = 1;
	//�����I��(�Q�[���I�ɂ͗ǂ��I��)�i��{���r���[��������l�j
	static const int BAD_ACTION = 2;
	//��{�̃X�R�A
	static const int DEFO_SCORE = 800;
private:
	//�X�v���C�g
	Sprite spriteScore;
	Sprite spriteReview;

	//�����I�ȃX�R�A
	static float totalScore;
	//�����I�ȃ��r���[
	static float totalReview;

	//�ꎞ�ۑ��p�̃X�R�A
	std::vector<float> scoreNum;

	//�ꎞ�ۑ��p�̃��r���[
	float oldReview;
	//����������ׂ̃��r���[
	float reduceReview;
	//���r���[�̌v�Z�p
	std::vector<float> reviewNum;

	//���Ԍv��
	time_t beginTime;
	time_t endTime;
	double elpsedTime;

	//�͂��̃X�R�A
	float skinheadReview;
	//��{�͂��̃X�R�A
	float thinningReview;
	//�A�t���̃X�R�A
	float afroheadReview;

	//�X�R�A���������\���̂��߂̃t���O
	bool scorePrintFlag;
	//�X�R�A�̈ʒu
	XMFLOAT2 scorePos;
private:
	//�ŏ���Num�Z�b�g
	void FirstNumSet();
public:
	//����������
	void Initialize();
	//�X�V����
	void Update(Head *heads, const CheraType cheraType, const ItemType itemType);
	//�`��
	void Draw();
	//�X�R�A�̎Q��
	static const float &GetScore() { return totalScore; }
	//���r���[�̎Q��
	static const float &GetReview() { return totalReview; }
};

