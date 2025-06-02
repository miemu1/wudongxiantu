// shop.c
#define SKILLS_D "adm/daemons/skillsd"
inherit F_CLEAN_UP;
mapping basic_id = ([
	"force":"�����ڹ�",
	"dodge":"�����Ṧ",
	"unarmed":"����ȭ��",
	"cuff":"����ȭ��",
	"strike":"�����Ʒ�",
	"finger":"����ָ��",
	"hand":"�����ַ�",
	"claw":"����צ��",
	"sword":"��������",
	"blade":"��������",
	"staff":"�����ɷ�",
	"hammer":"��������",
	"club":"��������",
	"whip":"�����޷�",
	"dagger":"�����̱�",
	"throwing":"��������",
	"parry":"�����м�",
	"spear":"����ǹ��",
]);

int main(object me, string arg)
{
        if (! wizardp(me) && time() - me->query_temp("last_combat") < 10)  
                return notify_fail("ϵͳ�������̾���������� ....\n");   
   if (!arg)
  {
   string type,*types = keys(basic_id);
   string msg= ZJOBLONG+HIR "��"HIY "������ѧϵͳ" HIR "��"NOR+ZJBR;
	msg+="�����ѡ��鿴��������\n";
	msg+=ZJOBACTS2+ZJMENUF(3,3,9,30); 
	foreach (type in types)
	msg += basic_id[type]+":combat "+type+ZJSEP;
	msg += "ȫ������:combat all\n";
	 return notify_fail(msg+"\n");
	}
        me->set_temp("last_combat", time());        
          if (arg=="all")
          {
            SKILLS_D->show_skills_power_point(me);    
            return 1;
            }
        SKILLS_D->show_skills_power_point(me, arg);      
        return 1;
}

int help (object me)
{
        write(@HELP
�鿴�书���ֲ���ֵ
    combat attack             �鿴����������
    combat dodge              �鿴����������
    combat parry              �鿴�м�������
    combat damage             �鿴�˺�������
    combat force              �鿴�ڹ�������
    combat difficult          �鿴�Ѷȵ�����
    combat ultimate           �鿴�ռ����书
    combat expert             �鿴�������书
    combat advance            �鿴�߼����书
    combat normal             �鿴��ͨ���书
    combat public             �鿴�������书
    combat family             �鿴���ɵ��书
    combat private            �鿴�Դ����书
    combat <��������>         �鿴�������书
    combat <��������>         �鿴���书����
    combat <��������>         �鿴�ɼ����书

HELP);
        return 1;
}
