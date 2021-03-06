/* Project:		practice1
   File Name:	Level2.c
   Author:		张仕钊
   Date:		2017-3-28
   Purpose:		Level模块  */

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
static AEGfxVertexList*	pMesh1;	// 对象1的网格(mesh)模型
static float obj1X, obj1Y;		// 对象1的位置
//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void Load2(void)
{
	// 开始添加对象1
	AEGfxMeshStart();
	AEGfxTriAdd(
		-25.5f, -25.5f, 0xFFFF0000, 0.0f, 0.0f,
		25.5f, 0.0f, 0x00FF0000, 0.0f, 0.0f,
		-25.5f, 25.5f, 0xFFFFFF00, 0.0f, 0.0f);
	pMesh1 = AEGfxMeshEnd();
	AE_ASSERT_MESG(pMesh1, "Failed to create mesh 1!!");

	// 签到
	fprintf(fp, "Level2:Load\n");
}

void Ini2(void)
{
	// 对象1的初始位置
	obj1X = 0.0f;
	obj1Y = 0.0f;

	// 为开始画对象做准备
	AEGfxSetBackgroundColor(0.0f, 0.0f, 255.0f);   // 背景色RGB
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	// 签到
	fprintf(fp, "Level2:Initialize\n");
}

void Update2(void)
{
	// 状态切换
	if (KeyPressed[KeyR])
		Next = GS_Restart;
	if (KeyPressed[KeyESC])
		Next = GS_Quit;
	if (KeyPressed[Key1])
		Next = GS_L1;

	// 对象移动
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

	// 输入重置
	Input_Initialize();

	// 签到
	fprintf(fp, "Level2:Update\n");
}

void Draw2(void)
{
	// 画对象1
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	AEGfxSetPosition(obj1X, obj1Y);
	AEGfxTextureSet(NULL, 0, 0);
	AEGfxSetTransparency(1);
	AEGfxSetBlendColor(0.0f, 0.0f, 0.0, 0.0f);
	AEGfxMeshDraw(pMesh1, AE_GFX_MDM_TRIANGLES);

	// 签到
	fprintf(fp, "Level2:Draw\n");
}

void Free2(void)
{
	// 签到
	fprintf(fp, "Level2:Free\n");
}

void Unload2(void)
{
	AEGfxMeshFree(pMesh1);		// 注销创建的对象

								// 签到
	fprintf(fp, "Level2:Unload\n");
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------