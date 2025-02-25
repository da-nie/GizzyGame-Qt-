//****************************************************************************************************
//������������ ����������
//****************************************************************************************************
#include "cactioncopypositionoffset.h"

//****************************************************************************************************
//���������� ����������
//****************************************************************************************************

//****************************************************************************************************
//���������
//****************************************************************************************************

//****************************************************************************************************
//����������������
//****************************************************************************************************

//****************************************************************************************************
//����������� � ����������
//****************************************************************************************************

//----------------------------------------------------------------------------------------------------
//�����������
//----------------------------------------------------------------------------------------------------
CActionCopyPositionOffset::CActionCopyPositionOffset(const std::string &name_one,const std::string &name_two,int32_t offset_x,int32_t offset_y,std::shared_ptr<IAction> iAction_Ptr)
{ 
 Name_One=name_one;
 Name_Two=name_two;
 OffsetX=offset_x;
 OffsetY=offset_y;
 iAction_NextPtr=iAction_Ptr;
 Init();
}
//----------------------------------------------------------------------------------------------------
//����������
//----------------------------------------------------------------------------------------------------
CActionCopyPositionOffset::~CActionCopyPositionOffset()
{
}

//****************************************************************************************************
//�������� �������
//****************************************************************************************************

//----------------------------------------------------------------------------------------------------
//
//----------------------------------------------------------------------------------------------------

//****************************************************************************************************
//�������� �������
//****************************************************************************************************

//----------------------------------------------------------------------------------------------------
//��������� �������� � ���������
//----------------------------------------------------------------------------------------------------
void CActionCopyPositionOffset::Execute(std::shared_ptr<IPart> iPart_Ptr,CGameState &cGameState)
{
 //���� ������ ��������
 std::shared_ptr<IPart> part_one_ptr;
 std::shared_ptr<IPart> part_two_ptr;
 size_t size=cGameState.MapNamed.size();
 for(size_t n=0;n<size;n++)
 {
  if (cGameState.MapNamed[n]->Name.compare(Name_One)==0) part_one_ptr=cGameState.MapNamed[n];
  if (cGameState.MapNamed[n]->Name.compare(Name_Two)==0) part_two_ptr=cGameState.MapNamed[n];
 }
 if (part_one_ptr.get()!=NULL && part_two_ptr.get()!=NULL)//��������� ������ ���������
 {  
  part_one_ptr->BlockPosX=part_two_ptr->BlockPosX+OffsetX;
  part_one_ptr->BlockPosY=part_two_ptr->BlockPosY+OffsetY;
 }
 if (iAction_NextPtr.get()!=NULL) iAction_NextPtr->Execute(iPart_Ptr,cGameState);	
}
//----------------------------------------------------------------------------------------------------
//�������������
//----------------------------------------------------------------------------------------------------
void CActionCopyPositionOffset::Init(void)
{
 if (iAction_NextPtr.get()!=NULL) iAction_NextPtr->Init();
}