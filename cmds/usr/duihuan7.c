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

        return notify_fail(INPUTTXT("请输入你想要用灵石兑换天机点的数量，"ZJBR"比例是1024灵石==1天机点，单次最多兑换一亿天机点","duihuan7 $txt#")+"\n");
              sscanf(arg, "%d %s", count);

      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

  if(me->query("yuanbao") < 1024)
	{
		tell_object(me, HIR"灵石不足！。\n"NOR);
        return 1;
	}

        if (count<1) return notify_fail("gjb？！\n");
        if (count>100000000) return notify_fail("单次最多兑换1亿！\n");



        if (  (count*1024) > me->query("yuanbao")  )
		{
			tell_object(me, sprintf(HIR + "你的灵石不够兑换"+
		chinese_number(count)+ "天机点，你需要"+
		chinese_number(count*1024)+ "灵石才能兑换天机点。\n"NOR));
        return 1;

		}
//			return notify_fail("你的修为不够兑换+chinese_number""！\n");
//              CHANNEL_D->do_channel(this_object(),"rumor",
//               HIY+me->name() + "扫荡了日常七剑副本！"NOR);
//	me->add("combat_exp",exp*count);
//	me->add("yuanbao",888888*count);
//	me->add("weapon_max",3*count);
//	me->add("weapon/lv",3*count);
//	me->add("qijian",-count);
	me->add("yuanbao",-1024*count);
	me->add("tianji1",1*count);
//	me->start_busy(2);

        tell_object(me,HIW"你获得了：\n" +
        count + "天机点\n" +
        NOR);
	


        return 1;
}

int help(object me)
{
        write(@HELP
指令格式：giveall 物品路径

给在线的所有玩家红包。
HELP
        );
        return 1;
}
