// giveall.c
inherit F_DBASE;
inherit F_CLEAN_UP;
#include <ansi.h>
void create()
{
seteuid(getuid());
}
int main(object me, int arg)
{
	    object obj;
		object yao;
        int count,mengxin,balance;
        	me = this_player();
        	balance = 15000000+me->query("zhuanshii")*1000000+me->query("guizhen")*1000000;

        if (! arg) 

        return notify_fail(INPUTTXT("����������Ҫ����ʯ�һ��ƽ��������"ZJBR"������5��ʯ==4���ƽ𣬵������һ�һ�ڻƽ�","duihuan8 $txt#")+"\n");
              sscanf(arg, "%d %s", count);

      if (me->is_busy())
                return notify_fail("����æ���ء�\n");

  if(me->query("yuanbao") < 5)
	{
		tell_object(me, HIR"��ʯ���㣡��\n"NOR);
        return 1;
	}

        if (count<1) return notify_fail("gjb����\n");
        if (count>100000000) return notify_fail("�������һ�1�ڣ�\n");



        if (  (count*5) > me->query("yuanbao")  )
		{
			tell_object(me, sprintf(HIR + "�����ʯ�����һ�"+
		chinese_number(count)+ "���ƽ�����Ҫ"+
		chinese_number(count*5)+ "��ʯ���ܶһ��ƽ�\n"NOR));
        return 1;

		}
//			return notify_fail("�����Ϊ�����һ�+chinese_number""��\n");
//              CHANNEL_D->do_channel(this_object(),"rumor",
//               HIY+me->name() + "ɨ�����ճ��߽�������"NOR);
//	me->add("combat_exp",exp*count);
//	me->add("yuanbao",888888*count);
//	me->add("weapon_max",3*count);
//	me->add("weapon/lv",3*count);
//	me->add("qijian",-count);
	me->add("yuanbao",-5*count);
	me->add("balance",40000*count);
//	me->start_busy(2);

        tell_object(me,HIW"�����ˣ�\n" +
        count + "x4���ƽ�\n" +
        NOR);
	


        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��giveall ��Ʒ·��

�����ߵ�������Һ����
HELP
        );
        return 1;
}
