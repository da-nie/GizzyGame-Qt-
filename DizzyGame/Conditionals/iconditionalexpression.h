#ifndef I_CONDITIONAL_EXPRESSION_H
#define I_CONDITIONAL_EXPRESSION_H

//****************************************************************************************************
//��������� ������� �������� ���������
//****************************************************************************************************

//****************************************************************************************************
//������������ ����������
//****************************************************************************************************
#include <stdint.h>
#include <vector>
#include <memory>
#include "../Game/ipart.h"

//****************************************************************************************************
//����������������
//****************************************************************************************************

//****************************************************************************************************
//���������
//****************************************************************************************************

//****************************************************************************************************
//��������������� ����������
//****************************************************************************************************
class CGameState;

//****************************************************************************************************
//��������� ������� �������� ���������
//****************************************************************************************************
class IConditionalExpression
{
 public:
  //-������������---------------------------------------------------------------------------------------
  //-���������------------------------------------------------------------------------------------------
  //-���������------------------------------------------------------------------------------------------
 private:
  //-����������-----------------------------------------------------------------------------------------
 public:
  //-����������-----------------------------------------------------------------------------------------
  virtual ~IConditionalExpression() {};
 public:
  //-�������� �������-----------------------------------------------------------------------------------
  virtual void Execute(int32_t dizzy_x,int32_t dizzy_y,int32_t dizzy_width,int32_t dizzy_height,int32_t part_width,int32_t part_height,bool use,bool timer,CGameState &cGameState)=0;//��������� ������� � ��������� ��������
  //-�������� ����������� �������-----------------------------------------------------------------------
};

#endif