#pragma once
#include"Head.h"

class ScoreManager
{
private:
	//�ŏ���10�[���v�Z����p
	static const int FIRST_NUM_MAX = 10;
	//�ő僌�r���[
	static const int MAX_REVIEW = 5;
	//��{�̃X�R�A
	static const int DEFO_SCORE = 800;
private:
	//�����I�ȃX�R�A
	static float totalScore;
	//�����I�ȃ��r���[
	static float totalReview;

	//�ꎞ�ۑ��p�̃��r���[
	float oldReview;
	//���r���[�̌v�Z�p
	std::vector<float> reviewNum;

	//�͂��̃X�R�A
	float SKINHEAD_SCORE_NUM = 5;
	//��{�͂�
	float THINNING_SCORE_NUM = 4;
	//�A�t��
	float AFROHEAD_SCORE_NUM = 3;
private:
	//�ŏ���Num�Z�b�g
	void FirstNumSet();
public:
	//����������
	void Initialize();
	//�X�V����
	void Update(Head *heads, const CheraType cheraType);
	//�X�R�A�̎Q��
	static const float &GetScore() { return totalScore; }
	//���r���[�̎Q��
	static const float &GetReview() { return totalReview; }
};

