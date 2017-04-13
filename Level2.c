/* Project:		practice1
   File Name:	Level2.c
   Author:		������
   Date:		2017-3-28
   Purpose:		Levelģ��  */

#include <stdio.h>
#include "GameStateList.h"
#include "System.h"
#include "Level2.h"
#include "Input.h"
#include "GamestateManager.h"
#include "AEEngine.h"

   //------------------------------------------------------------------------------
   // Private Consts:
   //------------------------------------------------------------------------------

   //------------------------------------------------------------------------------
   // Private Structures:
   //------------------------------------------------------------------------------

   //------------------------------------------------------------------------------
   // Public Variables:
   //------------------------------------------------------------------------------

   //------------------------------------------------------------------------------
   // Private Variables:
   //------------------------------------------------------------------------------
static AEGfxVertexList*	pMesh1;	// ����1������(mesh)ģ��
static float obj1X, obj1Y;		// ����1��λ��
//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void Load2(void)
{
	// ��ʼ��Ӷ���1
	AEGfxMeshStart();
	AEGfxTriAdd(
		-25.5f, -25.5f, 0xFFFF0000, 0.0f, 0.0f,
		25.5f, 0.0f, 0x00FF0000, 0.0f, 0.0f,
		-25.5f, 25.5f, 0xFFFFFF00, 0.0f, 0.0f);
	pMesh1 = AEGfxMeshEnd();
	AE_ASSERT_MESG(pMesh1, "Failed to create mesh 1!!");

	// ǩ��
	fprintf(fp, "Level2:Load\n");
}

void Ini2(void)
{
	// ����1�ĳ�ʼλ��
	obj1X = 0.0f;
	obj1Y = 0.0f;

	// Ϊ��ʼ��������׼��
	AEGfxSetBackgroundColor(0.0f, 0.0f, 255.0f);   // ����ɫRGB
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	// ǩ��
	fprintf(fp, "Level2:Initialize\n");
}

void Update2(void)
{
	// ״̬�л�
	if (KeyPressed[KeyR])
		Next = GS_Restart;
	if (KeyPressed[KeyESC])
		Next = GS_Quit;
	if (KeyPressed[Key1])
		Next = GS_L1;

	// �����ƶ�
	if (KeyPressed[KeyUp])
		obj1Y += 0.5f;
	else
		if (KeyPressed[KeyDown])
			obj1Y -= 0.5f;
	if (KeyPressed[KeyLeft])
		obj1X -= 0.5f;
	else
		if (KeyPressed[KeyRight])
			obj1X += 0.5f;

	// ��������
	Input_Initialize();

	// ǩ��
	fprintf(fp, "Level2:Update\n");
}

void Draw2(void)
{
	// ������1
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	AEGfxSetPosition(obj1X, obj1Y);
	AEGfxTextureSet(NULL, 0, 0);
	AEGfxSetTransparency(1);
	AEGfxSetBlendColor(0.0f, 0.0f, 0.0, 0.0f);
	AEGfxMeshDraw(pMesh1, AE_GFX_MDM_TRIANGLES);

	// ǩ��
	fprintf(fp, "Level2:Draw\n");
}

void Free2(void)
{
	// ǩ��
	fprintf(fp, "Level2:Free\n");
}

void Unload2(void)
{
	AEGfxMeshFree(pMesh1);		// ע�������Ķ���

								// ǩ��
	fprintf(fp, "Level2:Unload\n");
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------