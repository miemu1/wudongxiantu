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

        return notify_fail(INPUTTXT("请输入你想要用点券兑换灵石的数量，"ZJBR"比例是25点券==1灵石，单次最多兑换一亿灵石","duihuan2 $txt#")+"\n");
              sscanf(arg, "%d %s", count);

      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

  if(me->query("jifeng") < 25)
	{
		tell_object(me, HIR"点券不足。\n"NOR);
        return 1;
	}

        if (count<1) return notify_fail("gjb？！\n");
        if (count>100000000) return notify_fail("单次最多兑换1亿！\n");



        if (  (count*25) > me->query("jifeng")  )
		{
			tell_object(me, sprintf(HIR + "你的点券不够兑换"+
		chinese_number(count)+ "枚灵石，你需要"+
		chinese_number(count*25)+ "点券才能兑换灵石。\n"NOR));
        return 1;

		}
//			return notify_fail("你的修为不够兑换+chinese_number""！\n");
//              CHANNEL_D->do_channel(this_object(),"rumor",
//               HIY+me->name() + "扫荡了日常七剑副本！"NOR);
//	me->add("combat_exp",exp*count);
//	me->add("jifeng",888888*count);
//	me->add("weapon_max",3*count);
//	me->add("weapon/lv",3*count);
//	me->add("qijian",-count);
	me->add("jifeng",-25*count);
	me->add("yuanbao",count);
//	me->start_busy(2);

        tell_object(me,HIW"你获得了：\n" +
        count + "枚灵石\n" +
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
