#pragma once

#include <xaudio2.h>
#include <fstream>
#include <assert.h>
#include <wrl.h>
#include <mfapi.h>
#include <mfidl.h>
#include <mfreadwrite.h>

// mediafoundation
#pragma comment(lib, "Mf.lib")
#pragma comment(lib, "mfplat.lib")
#pragma comment(lib, "Mfreadwrite.lib")
#pragma comment(lib, "mfuuid.lib")

// xaudio
#pragma comment(lib,"xaudio2.lib")

using namespace Microsoft::WRL;

//�����f�[�^�Ǘ��\����
struct ChunkHeader {
	char id[4];   //�`�����NiD
	int32_t size; //�`�����N�T�C�Y
};

//RIFF�w�b�_�`�����N
struct RiffHeader {
	ChunkHeader chunk;
	char type[4];
};

//FMT�`�����N
struct FormatChunk {
	ChunkHeader				chunk; //"fmt "
	WAVEFORMAT				wf;
	PCMWAVEFORMAT			pcmwf;
	WAVEFORMATEX			fmt;   //�g�`�t�H�[�}�b�g
	WAVEFORMATEXTENSIBLE	wften;
};

enum FMT_BYTE {
	FMT_BYTE_16,
	FMT_BYTE_18,
	FMT_BYTE_40,
};

//�����f�[�^
struct SoundData {
	//�g�`�t�H�[�}�b�g�i�傫���ɉ����ăf�[�^�^���قȂ�A�Ȃ�ł���j
	WAVEFORMAT				wf;
	PCMWAVEFORMAT			pcmwf;
	WAVEFORMATEX			wfex;
	WAVEFORMATEXTENSIBLE	wften;

	FMT_BYTE byteMode;

	//�o�b�t�@�擪�A�h���X
	BYTE *pBuffer = nullptr;
	//�o�b�t�@�T�C�Y
	unsigned int bufferSize;
	//�I�[�f�B�I�|�C���^
	IXAudio2SourceVoice *source = nullptr;
	//�o�b�t�@
	XAUDIO2_BUFFER buf{};
	//����
	float volume = 1.0f;
	//�ꎞ��~�t���O
	bool isPause = false;
};


class Audio
{
private:
	// XAudio
	static ComPtr<IXAudio2>        xAudio2;
	static IXAudio2MasteringVoice *masterVoice;
	static float mastervolume;

	static SoundData LoadSound_mp3(const char* filename);

public:

	Audio() {
		//xAudio�G���W���̃C���X�^���X�쐬
		HRESULT result = XAudio2Create(&xAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR);
		//�}�X�^�[�{�C�X�쐬
		result = xAudio2->CreateMasteringVoice(&masterVoice);
		//�{�����[��������(50%)
		mastervolume = 0.5f;
	}

	//������
	static void Init();

	//�T�E���h�f�[�^�̓ǂݍ���
	static SoundData LoadSound_wav(const char* filename);


	//�T�E���h�f�[�^�̃A�����[�h
	static void UnloadSound(SoundData *data);
	

	//���[�v�̐ݒ�(0~254�Ń��[�v�񐔂��w��B255�̏ꍇ�������[�v�B����ȊO�͖���)
	static void SetPlayRoopmode(SoundData &soundData,int roopCount);
	//�Đ�
	static void PlayLoadedSound(SoundData &soundData,bool isSerialPlay = false);
	//�ꎞ��~
	static void PauseLoadedSound(SoundData &soundData);
	//��~
	static void StopLoadedSound(SoundData &soundData);

	//�}�X�^�[���ʕύX
	static void SetMasterVolume(float volume);
	//���f�[�^���ʕύX
	static void SetSoundDataVolume(SoundData& data, float volume);
};

