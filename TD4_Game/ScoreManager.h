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
	static const int DEFO_HAGEHEAD_REVIEW = 2;
	//��{�͂��̊�{���r���[
	static const int DEFO_LIGHTHEAD_REVIEW = 2;
	//�A�t���̊�{���r���[
	static const int DEFO_AFROHEAD_REVIEW = 2;
	//�����I��(�Q�[���I�ɂ͈����I��) (��{���r���[�ɑ����l)
	static const int GOOD_ACTION = 1;
	//�����I��(�Q�[���I�ɂ͗ǂ��I��) (��{���r���[�ɑ����l)
	static const int BAD_ACTION = -2;
	//��{�̃X�R�A
	static const int DEFO_SCORE = 200;
	//�������r���[�̈ʒu
	const XMFLOAT2 TOTALREVIEW_POS = { 32,64 };
	//�J�������̈ʒu
	const XMFLOAT2 HANDLE_POS = { 32,0 };
	//�̗͂̍�����W
	const XMFLOAT2 LIFE_POS = { 0,0 };
	//�̗͂̃T�C�Y
	const float LIFE_SIZE_Y = 32;
private:
	//�X�v���C�g
	Sprite spriteScore;
	Sprite spriteReview;
	Sprite spriteLife;

	//�����I�ȃX�R�A
	static float totalScore;
	//�����I�ȃ��r���[
	static float totalReview;
	//���΂�����
	static int handleNum;

	//�ꎞ�ۑ��p�̃X�R�A
	float scoreNum;

	//�ꎞ�ۑ��p�̃��r���[
	float oldReview;
	//�P�l�̃��r���[
	float oneReview;
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
	//�X�R�A�̃A���t�@�l
	float scoreA;
	//���r���[�̈ʒu
	XMFLOAT2 reviewPos;
	//���r���[���������\���̂��߂̃t���O
	bool reviewPrintFlag;
	//���r���[�̃A���t�@�l
	float reviewA;

	//�ސE��
	int life;
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
	//�J�������̎Q��
	static const int &GetHandle() { return handleNum; }

	//player����ސE�����擾����
	void SetLife(const int &life) { this->life = life; }
};

