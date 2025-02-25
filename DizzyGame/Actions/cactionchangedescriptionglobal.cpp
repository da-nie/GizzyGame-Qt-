//****************************************************************************************************
//������������ ����������
//****************************************************************************************************
#include "cactionchangedescriptionglobal.h"

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
CActionChangeDescriptionGlobal::CActionChangeDescriptionGlobal(const std::string &description,std::shared_ptr<IAction> iAction_Ptr)
{ 
 Description=description;
 iAction_NextPtr=iAction_Ptr;
 Init();
}
//----------------------------------------------------------------------------------------------------
//����������
//----------------------------------------------------------------------------------------------------
CActionChangeDescriptionGlobal::~CActionChangeDescriptionGlobal()
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
void CActionChangeDescriptionGlobal::Execute(std::shared_ptr<IPart> iPart_Ptr,CGameState &cGameState)
{
 size_t size=cGameState.MapNamed.size();
 for(size_t n=0;n<size;n++)
 {
  if (cGameState.MapNamed[n]->Name.compare(iPart_Ptr->Name)==0) cGameState.MapNamed[n]->Description=Description;
 }
 if (iAction_NextPtr.get()!=NULL) iAction_NextPtr->Execute(iPart_Ptr,cGameState);	
}
//----------------------------------------------------------------------------------------------------
//�������������
//----------------------------------------------------------------------------------------------------
void CActionChangeDescriptionGlobal::Init(void)
{
 if (iAction_NextPtr.get()!=NULL) iAction_NextPtr->Init();
}