//=============================================================================
//
// ���͏��� [input.h]
// Author : 
//
//=============================================================================
#pragma once
#include "main.h"

#include "dinput.h"
#include "mmsystem.h"
#pragma comment (lib, "dinput8.lib")

//*****************************************************************************
// �}�N����`
//*****************************************************************************

// �v���O������������Ƃ��Ɏg��
#define	USE_KEYBOARD				// �錾����ƃL�[�{�[�h�ő���\�ɂȂ�
#define	USE_MOUSE					// �錾����ƃ}�E�X�ő���\�ɂȂ�
#define	USE_PAD						// �錾����ƃp�b�h�ő���\�ɂȂ�


/* game pad��� */
#define BUTTON_UP		0x00000001l	// �����L�[��(.IY<0)
#define BUTTON_DOWN		0x00000002l	// �����L�[��(.IY>0)
#define BUTTON_LEFT		0x00000004l	// �����L�[��(.IX<0)
#define BUTTON_RIGHT	0x00000008l	// �����L�[�E(.IX>0)

//#define BUTTON_A		0x00000010l	// �`�{�^��(.rgbButtons[0]&0x80)
//#define BUTTON_B		0x00000020l	// �a�{�^��(.rgbButtons[1]&0x80)
//#define BUTTON_C		0x00000040l	// �b�{�^��(.rgbButtons[2]&0x80)
//#define BUTTON_X		0x00000080l	// �w�{�^��(.rgbButtons[3]&0x80)
//#define BUTTON_Y		0x00000100l	// �x�{�^��(.rgbButtons[4]&0x80)
//#define BUTTON_Z		0x00000200l	// �y�{�^��(.rgbButtons[5]&0x80)
//#define BUTTON_L		0x00000400l	// �k�{�^��(.rgbButtons[6]&0x80)
//#define BUTTON_R		0x00000800l	// �q�{�^��(.rgbButtons[7]&0x80)
//#define BUTTON_START	0x00001000l	// �r�s�`�q�s�{�^��(.rgbButtons[8]&0x80)
//#define BUTTON_M		0x00002000l	// �l�{�^��(.rgbButtons[9]&0x80)

#define BUTTON_X		0x00000010l	// �w�{�^��(.rgbButtons[0]&0x80)
#define BUTTON_A		0x00000020l	// �`�{�^��(.rgbButtons[1]&0x80)
#define BUTTON_B		0x00000040l	// �a�{�^��(.rgbButtons[2]&0x80)
#define BUTTON_Y		0x00000080l	// �x�{�^��(.rgbButtons[3]&0x80)

#define BUTTON_1X		0x00000010l	// �w�{�^��(.rgbButtons[0]&0x80)
#define BUTTON_2Y		0x00000020l	// �`�{�^��(.rgbButtons[1]&0x80)
#define BUTTON_3A		0x00000040l	// �a�{�^��(.rgbButtons[2]&0x80)
#define BUTTON_4B		0x00000080l	// �x�{�^��(.rgbButtons[3]&0x80)

#define BUTTON_L		0x00000100l	// �k�{�^��(.rgbButtons[4]&0x80)
#define BUTTON_R		0x00000200l	// �q�{�^��(.rgbButtons[5]&0x80)
#define BUTTON_L2		0x00000400l	// �k�{�^��(.rgbButtons[6]&0x80)
#define BUTTON_R2		0x00000800l	// �q�{�^��(.rgbButtons[7]&0x80)
#define BUTTON_SELECT	0x00001000l	// �y�{�^��(.rgbButtons[8]&0x80)
#define BUTTON_START	0x00002000l	// �r�s�`�q�s�{�^��(.rgbButtons[9]&0x80)
#define BUTTON_TEN_UP   0x000 

#define BUTTON_PAD_RETURN (BUTTON_4B)
#define BUTTON_PAD_LEFTSKILL (BUTTON_3A)
#define BUTTON_PAD_RIGHTSKILL (BUTTON_4B)
#define BUTTON_PAD_QUIT (BUTTON_1X)
#define BUTTON_PAD_SHOWUI (BUTTON_2Y)

#define GAMEPADMAX		4			// �����ɐڑ�����W���C�p�b�h�̍ő吔���Z�b�g

enum {	// �{�^���ɑ΂���rgbButtons[?]�z��̔z��ԍ�(DirectInput��ł�XYAB�{�^���ʒu�ɍ��킹��)
	rgbButtons_X,
	rgbButtons_A,
	rgbButtons_B,
	rgbButtons_Y,
	rgbButtons_L,
	rgbButtons_R,
	rgbButtons_L2,
	rgbButtons_R2,
	rgbButtons_SELECT,
	rgbButtons_START,
};

enum
{
	ten_up,
	ten_down,
	ten_left,
	ten_right,
};


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
HRESULT InitInput(HINSTANCE hInst, HWND hWnd);
void UninitInput(void);
void UpdateInput(void);

//---------------------------- keyboard
bool GetKeyboardPress(int nKey);
bool GetKeyboardTrigger(int nKey);
bool GetKeyboardRepeat(int nKey);
bool GetKeyboardRelease(int nKey);

//---------------------------- mouse
BOOL IsMouseLeftPressed(void);      // ���N���b�N�������
BOOL IsMouseLeftTriggered(void);    // ���N���b�N�����u��
BOOL IsMouseRightPressed(void);     // �E�N���b�N�������
BOOL IsMouseRightTriggered(void);   // �E�N���b�N�����u��
BOOL IsMouseCenterPressed(void);    // ���N���b�N�������
BOOL IsMouseCenterTriggered(void);  // ���N���b�N�����u��
long GetMouseX(void);               // �}�E�X��X�����ɓ��������Βl
long GetMouseY(void);               // �}�E�X��Y�����ɓ��������Βl
long GetMouseZ(void);               // �}�E�X�z�C�[�������������Βl

bool IsMouseSlideLeft();
bool IsMouseSlideRight();
void SetCanCheckSlide(bool can);

//---------------------------- game pad
BOOL IsButtonPressed(int padNo,DWORD button);
BOOL IsButtonTriggered(int padNo,DWORD button);
BOOL TenButtonPressed(int padNo,int tenType);
void TestPad();

int GetPadID();

