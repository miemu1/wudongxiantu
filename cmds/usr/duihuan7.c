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
        int count,mengxin,tianji1;
        	me = this_player();
        	tianji1 = 15000000+me->query("zhuanshii")*1000000+me->query("guizhen")*1000000;

        if (! arg) 

        return notify_fail(INPUTTXT("����������Ҫ����ʯ�һ�������������"ZJBR"������1024��ʯ==1����㣬�������һ�һ�������","duihuan7 $txt#")+"\n");
              sscanf(arg, "%d %s", count);

      if (me->is_busy())
                return notify_fail("����æ���ء�\n");

  if(me->query("yuanbao") < 1024)
	{
		tell_object(me, HIR"��ʯ���㣡��\n"NOR);
        return 1;
	}

        if (count<1) return notify_fail("gjb����\n");
        if (count>100000000) return notify_fail("�������һ�1�ڣ�\n");



        if (  (count*1024) > me->query("yuanbao")  )
		{
			tell_object(me, sprintf(HIR + "�����ʯ�����һ�"+
		chinese_number(count)+ "����㣬����Ҫ"+
		chinese_number(count*1024)+ "��ʯ���ܶһ�����㡣\n"NOR));
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
	me->add("yuanbao",-1024*count);
	me->add("tianji1",1*count);
//	me->start_busy(2);

        tell_object(me,HIW"�����ˣ�\n" +
        count + "�����\n" +
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
