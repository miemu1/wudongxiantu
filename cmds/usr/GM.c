// time.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string str;
	if(!arg)
{
	str = ZJOBLONG"��ѡ�������\n";
	str += ZJOBACTS2+ZJMENUF(1,1,9,29);
	str += WHT"[������ʯ]"NOR"["+((me->query("GM/GMma3")>=999999)?HIG"����ȡ"NOR:HIR"������ȡ"NOR)+"]:GMma3"ZJSEP;
    str += WHT"[�������]"NOR"["+((me->query("GM/GMma4")>=999999)?HIG"����ȡ"NOR:HIR"������ȡ"NOR)+"]:GMma4"ZJSEP;
    str += WHT"[���޵�ȯ]"NOR"["+((me->query("GM/GMma5")>=999999)?HIG"����ȡ"NOR:HIR"������ȡ"NOR)+"]:GMma5"ZJSEP;
}
	
	message("vision", str+"\n", me);
	return 1;
}

int help(object me)
{
     write(@HELP
ָ���ʽ: uplv [-s]

���ָ������������Ϊ�����ȼ���

HELP
    );
    return 1;
}
