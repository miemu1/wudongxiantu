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
	str += WHT"[���´����]"NOR"["+((me->query("jihuom/s1")>=1)?HIG"����ȡ"NOR:HIR"δ��ȡ"NOR)+"]:jihuo1"ZJSEP;
	str += WHT"[��������]"NOR"["+((me->query("jihuom/s2")>=1)?HIG"����ȡ"NOR:HIR"δ��ȡ"NOR)+"]:jihuo2"ZJSEP;
	str += WHT"[��������]"NOR"["+((me->query("jihuom/s4")>=1)?HIG"����ȡ"NOR:HIR"δ��ȡ"NOR)+"]:jihuo4"ZJSEP;
	str += WHT"[����ʹ��]"NOR"["+((me->query("jihuom/s10")>=1)?HIG"����ȡ"NOR:HIR"δ��ȡ"NOR)+"]:jihuo10"ZJSEP;
    str += WHT"[���²��� A]"NOR"["+((me->query("jihuom/s5")>=1)?HIG"����ȡ"NOR:HIR"δ��ȡ"NOR)+"]:jihuo5"ZJSEP;
    str += WHT"[���²��� B]"NOR"["+((me->query("jihuom/s6")>=1)?HIG"����ȡ"NOR:HIR"δ��ȡ"NOR)+"]:jihuo6"ZJSEP;
    str += WHT"[���²��� C]"NOR"["+((me->query("jihuom/s3")>=1)?HIG"����ȡ"NOR:HIR"δ��ȡ"NOR)+"]:jihuo3"ZJSEP;
    str += WHT"[���²��� D]"NOR"["+((me->query("jihuom/s7")>=1)?HIG"����ȡ"NOR:HIR"δ��ȡ"NOR)+"]:jihuo7"ZJSEP;
    str += WHT"[���¿���]"NOR"["+((me->query("jihuom/s8")>=1)?HIG"����ȡ"NOR:HIR"δ��ȡ"NOR)+"]:jihuo8"ZJSEP;
    str += WHT"[ɾ������ A]"NOR"["+((me->query("jihuom/s999")>=1)?HIG"����ȡ"NOR:HIR"δ��ȡ"NOR)+"]:jihuo999"ZJSEP;
    str += WHT"[ɾ������ B]"NOR"["+((me->query("jihuom/s9")>=1)?HIG"����ȡ"NOR:HIR"δ��ȡ"NOR)+"]:jihuo9"ZJSEP;
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
