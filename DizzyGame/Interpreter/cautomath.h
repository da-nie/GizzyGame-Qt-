#ifndef C_AUTOMATH_H
#define C_AUTOMATH_H

//****************************************************************************************************
//����� ������������������ ��������� ��������
//****************************************************************************************************

//****************************************************************************************************
//������������ ����������
//****************************************************************************************************

#include <stdint.h>
#include <string>
#include <vector>
#include <list>

//****************************************************************************************************
//����������������
//****************************************************************************************************

//****************************************************************************************************
//���������
//****************************************************************************************************

//****************************************************************************************************
//��������������� ����������
//****************************************************************************************************

//****************************************************************************************************
//����� ������������������ ��������� ��������
//****************************************************************************************************
class CAutomath
{
 public:
  //-������������---------------------------------------------------------------------------------------
  //-���������------------------------------------------------------------------------------------------
  //������� ��������
  struct SRule
  {
   std::string CurrentState;//������� ���������
   std::string NextState;//��������� ���������
   bool EndingTypeNextState;//�������� �� ��������� ��������� �����������
   
   uint32_t InputFirst;//��������� ��� ��������
   uint32_t InputLast;//�������� ��� ��������
  };  
  //-���������------------------------------------------------------------------------------------------
 private:
  //-����������-----------------------------------------------------------------------------------------
  std::string CurrentState;//������� ��������� ��������
  std::vector<SRule> vector_SRule;//������� �������� ��������
  std::list<uint32_t> InputLine;//������� ������������������, �������� ���������
  bool EndingTypeCurrentState;//�������� �� ������� ��������� �����������
 public:
  //-�����������----------------------------------------------------------------------------------------
  CAutomath(void);
  //-����������-----------------------------------------------------------------------------------------
  ~CAutomath();
 public:
  //-�������� �������-----------------------------------------------------------------------------------
  void Release(void);//�������� ������� � �������� ���������
  void AddRule(const std::string &current_state,const std::string &next_state,uint32_t input_first,uint32_t input_last,bool next_state_ending);//�������� �������
  void Reset(void);//�������� ������� � �������� ���������
  bool Push(uint32_t value);//������ �� ���� �������� �����
  bool IsCurrentStateEndingType(void) const;//�������� ����������� �� ������� ��������� ��������
  bool CompareCurrentState(const std::string &state) const;//�������� ������� ��������� � ��������    
  void GetInputLineToString(std::string &string) const;//�������� ������� ������������������ �������� ��� ������
 private:
  //-�������� �������-----------------------------------------------------------------------------------
};

#endif