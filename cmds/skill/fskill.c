/*
���ܷ����ݼ�����ʾָ��
���͵�һ���汾 
Ц��(����)����
2018.7.5
7.7�ڶ��ε�������ӵȼ���ʾ����ɫ��ʾ,��������
2019.3.24
�����ε����������ֱ��
*/

#include <skill.h>
#include <ansi.h>
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
string *basic_id = ({
	"force",//�����ڹ�
	"dodge",//�����Ṧ
	"unarmed",//����ȭ��
	"cuff",//����ȭ��
	"strike",//�����Ʒ�
	"finger",//����ָ��
	"hand",//�����ַ�
	"claw",//����צ��
	"sword",//��������
	"blade",//��������
	"staff",//�����ɷ�
	"hammer",//��������
	"club",//��������
	"whip",//�����޷�
	"dagger",//�����̱�
	"throwing",//��������
	"parry",//�����м�
	"spear",//����ǹ��
	"spells",//����ǹ��
	"knowledge",//֪ʶ�༼��
	"basic",//���������书�ۺ�
	"fufa",//��������
});
string *basic_name = ({
HIM "�ڹ�"NOR,//�����ڹ�
HIM	"�Ṧ"NOR,//�����Ṧ
HIM	"ȭ��"NOR,//����ȭ��
HIM	"ȭ��"NOR,//����ȭ��
HIM	"�Ʒ�"NOR,//�����Ʒ�
HIM	"ָ��"NOR,//����ָ��
HIM	"�ַ�"NOR,//�����ַ�
HIM	"צ��"NOR,//����צ��
HIM	"����"NOR,//��������
HIM	"����"NOR,//��������
HIM	"�ȷ�"NOR,//�����ɷ�
HIM	"����"NOR,//��������
HIM	"����"NOR,//��������
HIM	"�޷�"NOR,//�����޷�
HIM	"�̱�"NOR,//�����̱�
HIM	"����"NOR,//��������
HIM	"�м�"NOR,//�����м�
HIM "ǹ��"NOR,//����ǹ��
HIM "����"NOR,//��������
HIM "����"NOR,//��������
YEL"֪ʶ�༼��"NOR,//֪ʶ�༼��
	"ȫ������",//�����书�Լ�����
	});
int main(object me,string arg)
{
string sks;
int i,j,is,js;
string *playersk,playerskill,sa,str;
playersk = keys(me->query_skills());//������ҵ�ȫ������
		str=ZJOBACTS2+ZJMENUF(2,2,10,32);
if (!arg)//��û�в�������������ʱ������ѡ�����
{
for (i=0;i <sizeof(basic_name);i++)
{
        if (me->query_skill(basic_id[i],1))
      {
sa =  HIM+basic_name[i]+NOR;
if (me->query_skill_mapped(basic_id[i]))
sa +=HIC"��"+to_chinese(me->query_skill_mapped(basic_id[i]))+NOR;
else
sa +=HIR"��(������)"NOR;
str += sa+":fskill "+ basic_id[i]+ZJSEP;//ָ������������ѭ��������ʶ���ѡ��������
      }
}	
str =ZJOBLONG+HIC"����书��������\n"+str;
}
   else//�������룬���ܷ��࿪ʼ
      {
      		for (i = 0; i < sizeof(basic_name); i++)//ѡ���������
   		{
		if (arg==basic_id[i])
		{
		for (is = 0; is < sizeof(playersk); is++)//ѡ���������������͵������书
		{
		playerskill = playersk[is];
			sa = to_chinese(playersk[is]);
		sa+=HIC"��"+me->query_skill(playersk[is],1)+"����"NOR;			
if (SKILL_D(playersk[is])->valid_enable(basic_id[i]))	//ʶ������
str += sa+":jifa "+ arg +" " +playerskill +ZJSEP; 
		}
		break;				
		}		
		}
		str += HIY"����ȫ��"NOR":fskill"ZJSEP+"\n";
	str =ZJOBLONG"����ѡ�񼤷�����\n"+str;
		}
	write(str+"\n");
	return 1;
}