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
        int count,mengxin,yuanbao;
        	me = this_player();
        	yuanbao = 15000000+me->query("zhuanshii")*1000000+me->query("guizhen")*1000000;

        if (! arg) 

        return notify_fail(INPUTTXT("����������Ҫ�õ�ȯ�һ���ʯ��������"ZJBR"������25��ȯ==1��ʯ���������һ�һ����ʯ","duihuan2 $txt#")+"\n");
              sscanf(arg, "%d %s", count);

      if (me->is_busy())
                return notify_fail("����æ���ء�\n");

  if(me->query("jifeng") < 25)
	{
		tell_object(me, HIR"��ȯ���㡣\n"NOR);
        return 1;
	}

        if (count<1) return notify_fail("gjb����\n");
        if (count>100000000) return notify_fail("�������һ�1�ڣ�\n");



        if (  (count*25) > me->query("jifeng")  )
		{
			tell_object(me, sprintf(HIR + "��ĵ�ȯ�����һ�"+
		chinese_number(count)+ "ö��ʯ������Ҫ"+
		chinese_number(count*25)+ "��ȯ���ܶһ���ʯ��\n"NOR));
        return 1;

		}
//			return notify_fail("�����Ϊ�����һ�+chinese_number""��\n");
//              CHANNEL_D->do_channel(this_object(),"rumor",
//               HIY+me->name() + "ɨ�����ճ��߽�������"NOR);
//	me->add("combat_exp",exp*count);
//	me->add("jifeng",888888*count);
//	me->add("weapon_max",3*count);
//	me->add("weapon/lv",3*count);
//	me->add("qijian",-count);
	me->add("jifeng",-25*count);
	me->add("yuanbao",count);
//	me->start_busy(2);

        tell_object(me,HIW"�����ˣ�\n" +
        count + "ö��ʯ\n" +
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
