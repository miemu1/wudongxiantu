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
        int count,mengxin,exp;
        	me = this_player();
        	exp = 15000000+me->query("zhuanshii")*1000000+me->query("guizhen")*1000000;

        if (! arg) 

        return notify_fail(INPUTTXT("����������Ҫ��Ǳ�ܶһ���Ϊ��������"ZJBR"������10250Ǳ��==1��Ϊֵ���������һ�1����Ϊ","duihuan $txt#")+"\n");
              sscanf(arg, "%d %s", count);

      if (me->is_busy())
                return notify_fail("����æ���ء�\n");

  if(me->query("potential") < 10250)
	{
		tell_object(me, HIR"Ǳ�ܲ��㡣\n"NOR);
        return 1;
	}

        if (count<1) return notify_fail("gjb����\n");
        if (count>10000) return notify_fail("�������һ�1��\n");



        if (  (count*10250) > me->query("potential")  )
		{
			tell_object(me, sprintf(HIR + "���Ǳ�ܲ����һ�"+
		chinese_number(count)+ "����Ϊֵ������Ҫ"+
		chinese_number(count*10250)+ "Ǳ�ܲ��ܶһ���Ϊֵ��\n"NOR));
        return 1;

		}
//			return notify_fail("�����Ϊ�����һ�+chinese_number""��\n");
//              CHANNEL_D->do_channel(this_object(),"rumor",
//               HIY+me->name() + "ɨ�����ճ��߽�������"NOR);
//	me->add("combat_exp",exp*count);
//	me->add("potential",888888*count);
//	me->add("weapon_max",3*count);
//	me->add("weapon/lv",3*count);
//	me->add("qijian",-count);
	me->add("potential",-10250*count);
	me->add("combat_exp",count);
//	me->start_busy(2);

        tell_object(me,HIW"�����ˣ�\n" +
        count + "����Ϊֵ\n" +
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
