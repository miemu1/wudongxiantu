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
        int count,mengxin,jifeng;
        	me = this_player();
        	jifeng = 15000000+me->query("zhuanshii")*1000000+me->query("guizhen")*1000000;

        if (! arg) 

        return notify_fail(INPUTTXT("请输入你想要用钻石兑换点券的数量，"ZJBR"比例是1钻石==5张点券，单次最多兑换一亿张点券","duihuan4 $txt#")+"\n");
              sscanf(arg, "%d %s", count);

      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

  if(me->query("dajif") < 1)
	{
		tell_object(me, HIR"钻石不足。\n"NOR);
        return 1;
	}

        if (count<1) return notify_fail("gjb？！\n");
        if (count>100000000) return notify_fail("单次最多兑换1亿！\n");



        if (  (count*1) > me->query("dajif")  )
		{
			tell_object(me, sprintf(HIR + "你的钻石不够兑换"+
		chinese_number(count)+ "张点券，你需要"+
		chinese_number(count*1)+ "钻石才能兑换点券。\n"NOR));
        return 1;

		}
//			return notify_fail("你的修为不够兑换+chinese_number""！\n");
//              CHANNEL_D->do_channel(this_object(),"rumor",
//               HIY+me->name() + "扫荡了日常七剑副本！"NOR);
//	me->add("combat_exp",exp*count);
//	me->add("dajif",888888*count);
//	me->add("weapon_max",3*count);
//	me->add("weapon/lv",3*count);
//	me->add("qijian",-count);
	me->add("dajif",-1*count);
	me->add("jifeng",5*count);
//	me->start_busy(2);

        tell_object(me,HIW"你获得了：\n" +
        count + "张点券\n" +
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
