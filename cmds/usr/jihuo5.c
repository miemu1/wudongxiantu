// giveall.c
inherit F_DBASE;
inherit F_CLEAN_UP;
#include <ansi.h>
#define REDBAO "/u/aliyun/obj/bao"
void create()
{
seteuid(getuid());
}
int main(object me, string arg)
{
	    object obj,ob;
        int count,mengxin;
        string a;
		me = this_player();
        if (! arg) 

        return notify_fail(INPUTTXT(ZJSIZE(24)HIR"请输入礼包码：更新补偿A"NOR,"jihuo5 $txt#")+"\n");
	switch (arg) {
	  case "更新补偿A" :
		me->add_temp("sword",1);
		write("哦豁！\n");
		message("vision","礼包码正确！"+me->name()+"！\n",me);
		
		break;
	  default :
		return notify_fail("礼包码错误，请前往官方QQ群获取输入正确的礼包码\n");

	}		
              sscanf(arg, "%s ", a);



  if(me->query("jihuom/s5")>0)
	{
		tell_object(me, HIR"每个礼包码只能使用一次！\n"NOR);
        return 1;
	}


              CHANNEL_D->do_channel(this_object(),"rumor",
                HIY+me->name() + "领取了更新补偿A！"NOR);
//	me->add("combat_exp",100000);
//	me->add("jifeng",15000);
//    me->add("yuanbao",5000);
	me->add("max_neili", 3000);
	me->add("max_jingli", 1500);
	me->add("max_jing", 1500);
	me->add("max_qi", 3000);

	me->set("jihuom/s5",1);

	
	write("礼包码正确，你获得了以下奖励!\n");
        tell_object(me,HIW"你获得了：\n" +
        3000 + "最大内力\n" +
        1500 + "最大精神\n" +
        3000 + "最大气血\n" +
        1500 + "最大精力\n" +
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
