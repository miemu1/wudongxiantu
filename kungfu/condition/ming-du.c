#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;
inherit POISON;

string name() { return "ming-du"; }

string chinese_name() { return "�鶾"; }

string update_msg_others()
{
       return HIR "$Nһ���Һ�����Ϣ���������ۡ���һ�����һ�����Ѫ��"NOR"\n";
}

string update_msg_self()
{
	return HIR "��ֻ�е������������ڲ�ֹ���綾���ģ������������鶾�ĸ��ţ�"NOR"\n";
}

