// literate.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_learn(object me)
{
	return 1;
}


void skill_improved(object me)
{
    int s;
    s = me->query_skill("lifeskill", 1);

    if (s%30==0){
	tell_object(me, HIW "�����������ڷܹ������ۺ����ʵõ��˶��������"+HIY"��������ά��"+NOR+"����ˡ�\n");
    }

}
